// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtGGCMFileFormat.h                           //
// ************************************************************************* //

#ifndef AVT_GGCM_FILE_FORMAT_H
#define AVT_GGCM_FILE_FORMAT_H

#include <avtMTSDFileFormat.h>

#include <vector>

class DBOptionsAttributes;
class vtkRectilinearGrid;

// ****************************************************************************
//  Class: avtGGCMFileFormat
//
//  Purpose:
//      Reads in GGCM files as a plugin to VisIt.
//
//  Programmer: tfogal -- generated by xml2avt
//  Creation:   Thu Jun 1 13:38:54 PST 2006
//
// ****************************************************************************

class avtGGCMFileFormat : public avtMTSDFileFormat
{
  public:
                       avtGGCMFileFormat(const char *, DBOptionsAttributes *);
    virtual           ~avtGGCMFileFormat();

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, const char *type,
    //                                     int timestep, void *args, 
    //                                     DestructorFunction &);
    //

    //
    // If you know the times and cycle numbers, overload this function.
    // Otherwise, VisIt will make up some reasonable ones for you.
    //
    // virtual void        GetCycles(std::vector<int> &);
    // virtual void        GetTimes(std::vector<double> &);
    //

    virtual int            GetNTimesteps(void);

    virtual const char    *GetType(void)   { return "GGCM"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

    /** how VisIt gives subset contract info, to be used later */
    virtual void RegisterDataSelections(
                 const std::vector<avtDataSelection_p> &sels,
                 std::vector<bool> *selectionsApplied);


  protected:
    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *, int);

    private:
        unsigned int dim[3]; /**< 3d field dimensions */
        char *fn_grid;       /**< grid filename, derived from data filename */

        /** subset contract information */
        std::vector<avtDataSelection_p> selList;
        std::vector<bool> *selsApplied;
        double min[3];   /**< minimums for {x,y,z} dimensions */
        double max[3];   /**< maximums for {x,y,z} dimensions */
        bool restricted; /**< should we obey min[],max[]? */

    private:
        /** reads selList && selsApplied to create a domain / area of data to
         * read in. */
        void SetupDomain();
};
#endif
