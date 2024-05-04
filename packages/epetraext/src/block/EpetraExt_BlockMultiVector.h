//@HEADER
// ***********************************************************************
//
//     EpetraExt: Epetra Extended - Linear Algebra Services Package
//                 Copyright (2011) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
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

#ifndef EPETRAEXT_BLOCKMULTIVECTOR_H
#define EPETRAEXT_BLOCKMULTIVECTOR_H

#include "Epetra_MultiVector.h" 
#include "Teuchos_RCP.hpp"
#include <vector>

//! EpetraExt::BlockMultiVector: A class for constructing a distributed block multivector

/*! The EpetraExt::BlockMultiVector allows construction of a block multivector made up of Epetra_MultiVector blocks as well as access to the full systems as a Epetra_MultiVector.  It derives from and extends the Epetra_MultiVector class

<b>Constructing EpetraExt::BlockMultiVector objects</b>

*/    

namespace EpetraExt {

class BlockMultiVector: public Epetra_MultiVector {
 public:

  //@{ \name Constructors/Destructor.
  //! BlockMultiVector constuctor with one block row per processor.
  /*! Creates a BlockMultiVector object and allocates storage.  
    
	\param In
	BaseMap - Map determining local structure, can be distrib. over subset of proc.'s
	\param In 
	GlobalMap - Full map describing the overall global structure, generally generated by the construction of a BlockCrsMatrix object
	\param In 
	NumVectors - Number of vectors in object
  */
  BlockMultiVector( const Epetra_BlockMap & BaseMap, const Epetra_BlockMap & GlobalMap,
 int NumVectors );

   /*! Creates a BlockMultiVector object from an existing Epetra_MultiVector.  
    
	\param In 
        Epetra_DataAccess - Enumerated type set to Copy or View.
        \param In
	BaseMap - Map determining local structure, can be distrib. over subset of proc.'s
	\param In 
	BlockVec - Source Epetra multi vector whose map must be the full map for the block multi vector
  */
  BlockMultiVector(Epetra_DataAccess CV, const Epetra_BlockMap & BaseMap, 
	      const Epetra_MultiVector & BlockVec);

  //! Copy constructor.
  BlockMultiVector( const BlockMultiVector & MV );

  //! Destructor
  virtual ~BlockMultiVector();
  //@}
  
  //! Extract a single block from a Block Vector: block row is global, not a stencil value
  int ExtractBlockValues( Epetra_MultiVector & BaseVec, long long BlockRow) const;

  //! Load a single block into a Block Vector: block row is global, not a stencil value
  int LoadBlockValues(const Epetra_MultiVector & BaseVec, long long BlockRow);

  //! Return Epetra_MultiVector for given block row
  Teuchos::RCP<const Epetra_MultiVector> GetBlock(long long BlockRow) const;

  //! Return Epetra_MultiVector for given block row
  Teuchos::RCP<Epetra_MultiVector> GetBlock(long long BlockRow);

  //! Return base map
  const Epetra_BlockMap& GetBaseMap() const;
	
 protected:

  Epetra_BlockMap BaseMap_;

  long long Offset_;

};

} //namespace EpetraExt

#endif /* EPETRAEXT_BLOCKMULTIVECTOR_H */

#if defined(EpetraExt_SHOW_DEPRECATED_WARNINGS)
#ifdef __GNUC__
#warning "The EpetraExt package is deprecated"
#endif
#endif

