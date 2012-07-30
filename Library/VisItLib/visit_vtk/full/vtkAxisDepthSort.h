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
//                             vtkAxisDepthSort.h                            //
// ************************************************************************* //

#ifndef __vtkAxisDepthSort_h
#define __vtkAxisDepthSort_h
#include <visit_vtk_exports.h>
#include <vtkPolyDataAlgorithm.h>


// ****************************************************************************
//  Class: vtkAxisDepthSort
//
//  Purpose:
//      This will sort poly data along all six axes (+x, -x, +y, -y, +z, -z).
//
//  Programmer: Hank Childs
//  Creation:   July 13, 2002
//
//  Modifications:
//    Brad Whitlock, Mon Jul 15 15:43:22 PST 2002
//    Added API.
//
// ****************************************************************************

class VISIT_VTK_API vtkAxisDepthSort : public vtkPolyDataAlgorithm
{
  public:
    static vtkAxisDepthSort      *New();

    vtkPolyData                  *GetPlusXOutput(vtkInformationVector*);
    vtkPolyData                  *GetMinusXOutput(vtkInformationVector*);
    vtkPolyData                  *GetPlusYOutput(vtkInformationVector*);
    vtkPolyData                  *GetMinusYOutput(vtkInformationVector*);
    vtkPolyData                  *GetPlusZOutput(vtkInformationVector*);
    vtkPolyData                  *GetMinusZOutput(vtkInformationVector*);

  protected:
                                  vtkAxisDepthSort();
    virtual                      ~vtkAxisDepthSort() {;};

    virtual int                   RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  private:
    vtkPolyData                   *GetOutput(int, vtkInformationVector*);
                                  vtkAxisDepthSort(const vtkAxisDepthSort &);
                                  void operator=(const vtkAxisDepthSort &);
};


#endif

