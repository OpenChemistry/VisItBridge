set(SOURCES
  avtVsFileFormat.C
  avtVsOptions.C
  VsPluginInfo.C
  VsEnginePluginInfo.C
  VsCommonPluginInfo.C
  VsFilter.C
  VsLog.C
  VsMDMesh.C
  VsMDVariable.C
  VsMesh.C
  VsRectilinearMesh.C
  VsSchema.C
  VsStructuredMesh.C
  VsUniformMesh.C
  VsUnstructuredMesh.C
  VsUtils.C
  VsVariable.C
  VsVariableWithMesh.C
  VsRegistry.C
  VsRegistryObject.C
  VsH5Group.C
  VsH5Object.C
  VsH5Dataset.C
  VsH5Attribute.C
  VsH5File.C
  VsH5Reader.C
  )

ADD_VISIT_READER(VisItVsReader "1.0"
  VISIT_READER_TYPE "STSD"
  VISIT_READER_NAME "avtVsFileFormat"
  VISIT_READER_USES_OPTIONS ON
  SERVER_SOURCES ${SOURCES}
  )
