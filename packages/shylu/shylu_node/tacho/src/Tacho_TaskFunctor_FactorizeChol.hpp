#ifndef __TACHO_TASKFUNCTOR_FACTORIZE_CHOL_HPP__
#define __TACHO_TASKFUNCTOR_FACTORIZE_CHOL_HPP__

/// \file Tacho_TaskFunctor_FactorizeChol.hpp
/// \author Kyungjoo Kim (kyukim@sandia.gov)

#include "Tacho_Util.hpp"

#include "Tacho_CholSupernodes.hpp"
#include "Tacho_CholSupernodes_Serial.hpp"

namespace Tacho {

    template<typename MatValueType, typename SchedulerType>
    struct TaskFunctor_FactorizeChol {
    public:
      typedef SchedulerType scheduler_type;
      typedef typename scheduler_type::execution_space exec_space;
      typedef typename scheduler_type::member_type member_type;

      typedef Kokkos::MemoryPool<exec_space> memory_pool_type;

      typedef int value_type; // functor return type
      typedef Kokkos::BasicFuture<int,scheduler_type> future_type;

      typedef MatValueType mat_value_type; // matrix value type

      typedef SupernodeInfo<mat_value_type,scheduler_type> supernode_info_type;
      typedef typename supernode_info_type::supernode_type supernode_type;

      typedef Kokkos::pair<ordinal_type,ordinal_type> range_type;

    private:
      memory_pool_type _bufpool;

      supernode_info_type _info;
      ordinal_type _sid;

      // supernode_type _s;

      ordinal_type _state;

    public:
      KOKKOS_INLINE_FUNCTION
      TaskFunctor_FactorizeChol() = delete;

      KOKKOS_INLINE_FUNCTION
      TaskFunctor_FactorizeChol(const memory_pool_type &bufpool,
                                const supernode_info_type &info,
                                const ordinal_type sid)
        : _bufpool(bufpool),
          _info(info),
          _sid(sid),
          //_s(info.supernodes(sid)),
          _state(0) {}

      KOKKOS_INLINE_FUNCTION
      ordinal_type factorize_internal(member_type &member, const ordinal_type n, const bool final) {

        // ABR workssize and team private map size
        const size_t team_size = member.team_size();
        const size_t bufsize = (n*n + _info.max_schur_size*team_size)*sizeof(mat_value_type);
        
        mat_value_type * buf = NULL;
        Kokkos::single(Kokkos::PerTeam(member), [&](mat_value_type *&val) {
            val = bufsize > 0 ? (mat_value_type *)_bufpool.allocate(bufsize) : NULL;
          }, buf);

        if (buf == NULL && bufsize) 
          return -1; // allocation fails
        
        CholSupernodes<Algo::Workflow::Serial>
          ::factorize_recursive_serial(member, _info, _sid, final, buf, bufsize);
        
        Kokkos::single(Kokkos::PerTeam(member), [&]() {
            if (bufsize > 0)
              _bufpool.deallocate(buf, bufsize);
          });

        return 0;
      }

      KOKKOS_INLINE_FUNCTION
      void operator()(member_type &member, value_type &r_val) {
        auto& sched = member.scheduler(); 
        const auto &_s = _info.supernodes(_sid);
        constexpr ordinal_type done = 2;
        TACHO_TEST_FOR_ABORT(_state == done, "dead lock");

        Kokkos::single(Kokkos::PerTeam(member), [&]() {
            if (_s.nchildren == 0 && _state == 0) _state = 1;
          });
        //member.team_barrier();

        switch (_state) {
        case 0: { // tree parallelsim
          if (_info.serial_thres_size > _s.max_decendant_supernode_size) {
            r_val = factorize_internal(member, _s.max_decendant_schur_size, true);
            Kokkos::single(Kokkos::PerTeam(member), [&]() {
                if (r_val) Kokkos::respawn(this, sched, Kokkos::TaskPriority::Low);
                else       _state = done;
              });
          } else {
            Kokkos::single(Kokkos::PerTeam(member), [&]() {
                auto f_when_all = sched.when_all(_s.nchildren, [&](const ordinal_type i) {
                    // for debugging, serialize the tasks
                    // auto f = Kokkos::task_spawn
                    //   (Kokkos::TaskTeam(sched, i > 0 ? dep[i-1] : future_type(), Kokkos::TaskPriority::Regular),
                    //    TaskFunctor_FactorizeChol(sched, _bufpool, _info, _s.children[i]));
                    auto f = Kokkos::task_spawn(Kokkos::TaskTeam(sched, Kokkos::TaskPriority::Regular),
                                                TaskFunctor_FactorizeChol(_bufpool, _info, _s.children[i]));
                    TACHO_TEST_FOR_ABORT(f.is_null(), "task allocation fails");
                    return f;
                  });
                
                // respawn with updating state
                _state = 1;
                Kokkos::respawn(this, f_when_all, Kokkos::TaskPriority::Regular);
              });
          }
          break;
        }
        case 1: {
          r_val = factorize_internal(member, _s.n - _s.m, false);
          Kokkos::single(Kokkos::PerTeam(member), [&]() {
              if (r_val) Kokkos::respawn(this, sched, Kokkos::TaskPriority::Low);
              else       _state = done;
            });
          break;
        }
        }
        //member.team_barrier();
      }
    };

}

#endif
