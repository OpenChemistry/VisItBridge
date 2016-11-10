SET(SOURCES
avtBoxlib2DFileFormat.C
Boxlib2DCommonPluginInfo.C
Boxlib2DEnginePluginInfo.C
Boxlib2DMDServerPluginInfo.C
Boxlib2DPluginInfo.C
BoxLibHelper.C
)

if(BoxLib_FOUND)
  ADD_VISIT_READER(VisItBoxlib2DReader "1.0"
    VISIT_READER_TYPE "STMD"
    VISIT_READER_NAME "avtBoxlib2DFileFormat"
    VISIT_READER_USES_OPTIONS OFF
    SERVER_SOURCES ${SOURCES}
    )
endif()
