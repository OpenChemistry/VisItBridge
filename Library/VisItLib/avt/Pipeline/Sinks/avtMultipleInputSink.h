/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                          avtMultipleInputSink.h                           //
// ************************************************************************* //

#ifndef AVT_MULTIPLE_INPUT_SINK_H
#define AVT_MULTIPLE_INPUT_SINK_H

#include <pipeline_exports.h>

#include <avtDataObjectSink.h>
#include <avtDataTree.h>

class     avtDatasetSink;


// ****************************************************************************
//  Class: avtMultipleInputSink
//
//  Purpose:
//      The sink for a data object.  This can be either an originating sink
//      (one that originates a pipeline) or part of a filter.
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//
// ****************************************************************************

class PIPELINE_API avtMultipleInputSink : virtual public avtDataObjectSink
{
  public:
                                  avtMultipleInputSink();
    virtual                      ~avtMultipleInputSink();

    void                          SetNthInput(avtDataObject_p, int);

  protected:
    avtDataObjectSink           **sinks;
    int                           nSinks;

    virtual avtDataObject_p       GetInput(void);
    virtual const avtDataObject_p GetInput(void) const;
    virtual void                  SetTypedInput(avtDataObject_p);
    virtual bool                  UpdateInput(avtContract_p);

    avtDataObject_p               GetNthInput(int);
    void                          SetNumSinks(int);
    void                          SetSink(avtDataObjectSink *, int);

    avtDataTree_p                 GetTreeFromSink(avtDatasetSink *);
};


#endif

