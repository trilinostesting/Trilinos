#ifndef __Panzer_STK_PeriodicBC_Matcher_hpp__
#define __Panzer_STK_PeriodicBC_Matcher_hpp__

#include "Teuchos_Tuple.hpp"
#include "Teuchos_RCP.hpp"

#include "Panzer_STK_Version.hpp"
#include "Panzer_STK_config.hpp"
#include "Panzer_STK_Interface.hpp"

namespace panzer_stk {

/** These functions are utilities to support the implementation of
  * peridic boundary conditions.  They should not be used by externally
  * as their interface is likely to change.
  */
namespace periodic_helpers {

   /** Construct the vector pair (similar to <code>getLocallyMatchedPair</code>)
     * usign specified side sets, mesh object, and matcher object. This
     * is primarily a utility function.
     */
   template <typename Matcher>
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   matchPeriodicSides(const std::string & left,const std::string & right,
                     const STK_Interface & mesh,
                     const Matcher & matcher);

   template <typename Matcher>
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   matchPeriodicSides(const std::string & left,const std::string & right,
                     const STK_Interface & mesh,
                     const Matcher & matcher,
                     const std::vector<std::pair<std::size_t,std::size_t> > & current);

   /** This returns all the global IDs and coordinates for 
     * a particular side. By "all" that means across all processors.
     */
   std::pair<Teuchos::RCP<std::vector<std::size_t> >,
             Teuchos::RCP<std::vector<Teuchos::Tuple<double,3> > > >
   getSideIdsAndCoords(const STK_Interface & mesh,
                       const std::string & sideName);
 
   /** This returns the locally owned global IDs and coordinates for 
     * a particular side. 
     */
   std::pair<Teuchos::RCP<std::vector<std::size_t> >,
             Teuchos::RCP<std::vector<Teuchos::Tuple<double,3> > > >
   getLocalSideIdsAndCoords(const STK_Interface & mesh,
                            const std::string & sideName);
 
   /** This returns the locally resident (includes ghosted) global IDs
     * for a particular side. 
     */
   Teuchos::RCP<std::vector<std::size_t> >
   getLocalSideIds(const STK_Interface & mesh,
                   const std::string & sideName);
 
   /** Determine a map from the specified side to the set of coordinates
     * and Ids passed in. A vector of pairs that maps from (passed in gids)->(locally owned gids)
     * is returned.
     */
   template <typename Matcher>
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   getLocallyMatchedSideIds(const std::vector<std::size_t> & side_ids,
                            const std::vector<Teuchos::Tuple<double,3> > & side_coords,
                            const STK_Interface & mesh,
                            const std::string & sideName,const Matcher & matcher);
 
   /** Builds a vector of local ids and their matching global indices.
     * This requires a previously discovered vector of pairs of locally matched
     * ids to distribute. This vector comes from the getLocallyMatchedSideIds.
     */
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   getGlobalPairing(const std::vector<std::size_t> & locallyRequiredIds,
                    const std::vector<std::pair<std::size_t,std::size_t> > & locallyMatchedIds,
                    const STK_Interface & mesh,bool failure);

} // end periodic_helpers

/** Simply returns a vector of pairs that match
  * the IDs owned by this processor to their
  * matching IDs on the periodic boundary.
  *
  * Notice that the matched boundaries are not 
  * specified by this object. This is done in the 
  * inherited class.
  */
class PeriodicBC_MatcherBase {
public:
   virtual ~PeriodicBC_MatcherBase() {}

   /** Simply returns a vector of pairs that match
     * the IDs owned by this processor to their
     * matching IDs on the periodic boundary.
     *
     * \returns A vector of pairs. The first entry in the
     *          pair is the global node ID of a node used
     *          on this processor. The second is the global
     *          node ID (not necessarily on this processor)
     *          that replaces it.
     */
   virtual 
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   getMatchedPair(const STK_Interface & mesh,
                  const Teuchos::RCP<const std::vector<std::pair<std::size_t,std::size_t> > >  & currentState = Teuchos::null
                  ) const = 0;

   /** Return a one line string that describes this periodic
     * boundary condition.
     */
   virtual std::string getString() const = 0;
};

/** Default implementation class for the periodic boundary conditions.
  * This simply takes a <code>Matcher</code> object as the coordinate matching
  * operation. For details on the <code>Matcher</code> see the
  * <code>CoordMatcher</code> struct.
  */
template <typename Matcher>
class PeriodicBC_Matcher : public PeriodicBC_MatcherBase {
public:
   PeriodicBC_Matcher(const std::string & left, const std::string & right,const Matcher & matcher)
      : left_(left), right_(right), matcher_(matcher) {}
   PeriodicBC_Matcher(const PeriodicBC_Matcher & src)
      : left_(src.left_), right_(src.right_), matcher_(src.matcher_) {}

   /** Simply returns a vector of pairs that match
     * the IDs owned by this processor to their
     * matching IDs on the periodic boundary.
     *
     * \returns A vector of pairs. The first entry in the
     *          pair is the global node ID of a node used
     *          on this processor. The second is the global
     *          node ID (not necessarily on this processor)
     *          that replaces it.
     */
   Teuchos::RCP<std::vector<std::pair<std::size_t,std::size_t> > >
   getMatchedPair(const STK_Interface & mesh,
                  const Teuchos::RCP<const std::vector<std::pair<std::size_t,std::size_t> > >  & currentState = Teuchos::null
                  ) const
   { 
      if(currentState==Teuchos::null) 
         return periodic_helpers::matchPeriodicSides(left_,right_,mesh,matcher_); 
      else
         return periodic_helpers::matchPeriodicSides(left_,right_,mesh,matcher_,*currentState); 
   }

   std::string getString() const 
   { 
      std::stringstream ss;
      ss << "condition: " << matcher_.getString() << ", sides = [ "
         << "\"" << left_ << "\", "
         << "\"" << right_ << "\" ]";
      return ss.str();
   }

private:
   PeriodicBC_Matcher(); // hidden!

   std::string left_;  // here left & right are stand in names just so
   std::string right_; // that we realize that these boundaries are
                               // opposite of each other.
   Matcher matcher_;

};

/** A simple constructor function for building a matcher object.
  * This prevents the need to directly instantiate the templated 
  * derived class. It is a convenience.
  */
template <typename Matcher>
Teuchos::RCP<PeriodicBC_MatcherBase> 
buildPeriodicBC_Matcher(const std::string & left, const std::string & right, const Matcher & matcher)
{ return Teuchos::rcp(new PeriodicBC_Matcher<Matcher>(left,right,matcher)); }

} // end panzer_stk

#include "Panzer_STK_PeriodicBC_MatcherT.hpp"

#endif
