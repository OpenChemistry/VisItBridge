// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                             BadDomainException.C                          //
// ************************************************************************* //

#include <stdio.h>               // for sprintf
#include <BadDomainException.h>


// ****************************************************************************
//  Method: BadDomainException constructor
//
//  Arguments:
//      index        The domain number that was out of range.
//      numDomains   The total number of domains.
//
//  Programmer: Hank Childs
//  Creation:   July 24, 2000
//
// ****************************************************************************

BadDomainException::BadDomainException(int index, int numDomains)
{
    char str[1024];
    sprintf(str, "Tried to access %d of %d.", index, numDomains);
    msg = str;
}


