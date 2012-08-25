vtk_module(vtkIOVisItBridge
  DEPENDS
    vtkCommonDataModel
    vtkCommonExecutionModel
    vtknetcdf
    vtkhdf5
    VisItLib
  TEST_DEPENDS
  EXCLUDE_FROM_WRAP_HIERARCHY
)

# paraview-sepecfic extensions to a module to bring in proxy xmls.
set_property (GLOBAL PROPERTY
  vtkIOVisItBridge_SERVERMANAGER_XMLS
  ${CMAKE_CURRENT_LIST_DIR}/visit_readers.xml)

set_property (GLOBAL PROPERTY
  vtkIOVisItBridge_PARAVIEW_GUI_XMLS
  ${CMAKE_CURRENT_LIST_DIR}/visit_readers_gui.xml)

#-----------------------------------------------------------------------------
# GMV Reader needs OpenGLU library. So check if it exists before enabling the
# GMV reader.
find_package(OpenGL)
if (NOT OPENGL_GLU_FOUND)
  message(STATUS "Disabling VisIt GMV reader since GLU library not found.")
endif()
if (OPENGL_GLU_FOUND)
  set_property (GLOBAL APPEND PROPERTY
    vtkIOVisItBridge_SERVERMANAGER_XMLS
    ${CMAKE_CURRENT_LIST_DIR}/visit_readers_gmv.xml)
endif()
