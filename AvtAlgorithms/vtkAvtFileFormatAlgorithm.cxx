/*=========================================================================

   Program: ParaView
   Module:    vtkAvtFileFormatAlgorithm.cxx

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#include "vtkAvtFileFormatAlgorithm.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkUnstructuredGridAlgorithm.h"
#include "vtkUnstructuredGrid.h"

#include "avtFileFormat.h"
#include "avtDatabaseMetaData.h"

vtkStandardNewMacro(vtkAvtFileFormatAlgorithm);

//-----------------------------------------------------------------------------
vtkAvtFileFormatAlgorithm::vtkAvtFileFormatAlgorithm()
{
  this->FileName = 0;
  this->SetNumberOfInputPorts(0);
  this->SetNumberOfOutputPorts(1);

  this->AvtReader = NULL;
  this->ReaderMetaData = NULL;
}

//-----------------------------------------------------------------------------
vtkAvtFileFormatAlgorithm::~vtkAvtFileFormatAlgorithm()
{
  this->SetFileName(0);
  if ( this->AvtReader )
    {
    delete this->AvtReader;
    }

  if ( this->ReaderMetaData )
    {
    delete this->ReaderMetaData;
    }
}
//-----------------------------------------------------------------------------
int vtkAvtFileFormatAlgorithm::CanReadFile(const char *fname)
{

}

//-----------------------------------------------------------------------------
int vtkAvtFileFormatAlgorithm::RequestInformation(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector)
{

  if ( !this->ReaderMetaData )
    {
    //construct an AVT meta data, that we will allow the avt reader to populate
    this->ReaderMetaData = new avtDatabaseMetaData( );
    }

  //get all the meta data the avt reader has
  this->AvtReader->SetDatabaseMetaData( this->ReaderMetaData );

  //now cycle through and convert all the meta data that was added to paraview framework

  return 1;
}


//-----------------------------------------------------------------------------
int vtkAvtFileFormatAlgorithm::RequestData(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector)
{
  /*if (!this->AvtReader )
    {
    return 0;
    }

  vtkInformation *outInfo = outputVector->GetInformationObject(0);
  vtkUnstructuredGrid *output = vtkUnstructuredGrid::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  stringVector names = this->ReaderMetaData->GetAllMeshNames();
  size_t size = names.size();
  if ( size == 1 )
    {
    vtkUnstructuredGrid *mesh = vtkUnstructuredGrid::SafeDownCast(
      this->AvtReader->GetMesh( 0, names.at(0).c_str() ) );
    if ( mesh )
      {
      output->ShallowCopy( mesh );
      }
    mesh->Delete();
    }
    */
  return 1;
}

//-----------------------------------------------------------------------------
void vtkAvtFileFormatAlgorithm::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

