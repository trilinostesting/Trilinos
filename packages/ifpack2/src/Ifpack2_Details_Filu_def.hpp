/*@HEADER
// ***********************************************************************
//
//       Ifpack2: Templated Object-Oriented Algebraic Preconditioner Package
//                 Copyright (2009) Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ***********************************************************************
//@HEADER
*/

/// @file Ifpack2_filu_def.hpp

#ifndef __IFPACK2_FILU_DEF_HPP__ 
#define __IFPACK2_FILU_DEF_HPP__ 

#include "Ifpack2_Details_Filu_decl.hpp"
#include "Ifpack2_Details_CrsArrays.hpp"
#include "Ifpack2_Details_getCrsMatrix.hpp"
#include <Kokkos_Timer.hpp>
#include <shylu_fastilu.hpp>

namespace Ifpack2
{
namespace Details
{

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
Filu(Teuchos::RCP<const TRowMatrix> A) :
  FastILU_Base<Scalar, LocalOrdinal, GlobalOrdinal, Node>(A) {}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
int Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
getSweeps() const
{
  return localPrec_->getNFact();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
std::string Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
getSpTrsvType() const
{
  return localPrec_->getSpTrsvType();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
int Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
getNTrisol() const
{
  return localPrec_->getNTrisol();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
void Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
checkLocalILU() const
{
  localPrec_->checkILU();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
void Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
checkLocalIC() const
{
  localPrec_->checkIC();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
void Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
initLocalPrec()
{
  auto nRows = this->mat_->getLocalNumRows();
  auto& p = this->params_;
  auto matCrs = Ifpack2::Details::getCrsMatrix(this->mat_);

  bool skipSortMatrix = !matCrs.is_null() && matCrs->getCrsGraph()->isSorted() &&
                        !p.use_metis;
  const int blockCrsSize = p.blockCrs ? p.blockCrsSize : 1;
  localPrec_ = Teuchos::rcp(new LocalFILU(skipSortMatrix, this->localRowPtrs_, this->localColInds_, this->localValues_, nRows, p.sptrsv_algo,
                                          p.nFact, p.nTrisol, p.level, p.omega, p.shift, p.guessFlag ? 1 : 0, p.blockSizeILU, p.blockSize,
                                          blockCrsSize));
  localPrec2_ = Teuchos::rcp(new LocalFILU(skipSortMatrix, this->localRowPtrs2_, this->localColInds2_, this->localValues2_, nRows*blockCrsSize, p.sptrsv_algo,
                                           p.nFact, p.nTrisol, p.level, p.omega, p.shift, p.guessFlag ? 1 : 0, p.blockSizeILU, p.blockSize,
                                           1));
  #ifdef HAVE_IFPACK2_METIS
  if (p.use_metis) {
    localPrec_->setMetisPerm(this->metis_perm_, this->metis_iperm_);
  }
  #endif
  localPrec_->initialize();
  localPrec2_->initialize();
  localPrec_->verify(*localPrec2_, true);
  this->initTime_ = localPrec_->getInitializeTime();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
void Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
computeLocalPrec()
{
  //update values in local prec (until compute(), values aren't needed)
  localPrec_->setValues(this->localValues_);
  localPrec2_->setValues(this->localValues2_);
  localPrec_->compute();
  localPrec2_->compute();
  this->computeTime_ = localPrec_->getComputeTime();

  localPrec_->verify(*localPrec2_);
  std::cout << "JGF VERIFICATION OF COMPUTE COMPLETE!" << std::endl;
  exit(0);
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
void Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
applyLocalPrec(ImplScalarArray x, ImplScalarArray y) const
{
  localPrec_->apply(x, y);
  localPrec2_->apply(x, y);
  //since this may be applied to multiple vectors, add to applyTime_ instead of setting it
  this->applyTime_ += localPrec_->getApplyTime();
}

template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
std::string Filu<Scalar, LocalOrdinal, GlobalOrdinal, Node>::
getName() const
{
  return "Filu";
}

#define IFPACK2_DETAILS_FILU_INSTANT(S, L, G, N) \
template class Ifpack2::Details::Filu<S, L, G, N>;

} //namespace Details
} //namespace Ifpack2

#endif

