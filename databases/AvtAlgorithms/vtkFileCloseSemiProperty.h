#ifndef _vtkFileCloseSemiProperty_h
#define _vtkFileCloseSemiProperty_h

/*
 * Needs <hdf5.h>, so include this header only after you include the
 * hdf5 header. Because you might need to select the right API for hdf5 (such
 * as with H5_USE_16_API) the hdf5 header is not included here.
 */

class vtkFileCloseSemiProperty
{
public:
  vtkFileCloseSemiProperty ()
  {
    this->Fapl = H5Pcreate(H5P_FILE_ACCESS);
    H5Pset_fclose_degree(this->Fapl, H5F_CLOSE_SEMI);
  }
  ~vtkFileCloseSemiProperty ()
  {
    H5Pclose(this->Fapl);
  }
  operator hid_t() const
  {
    return this->Fapl;
  }


private:
  hid_t Fapl;
};

#endif
