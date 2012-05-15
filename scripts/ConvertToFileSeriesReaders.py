import os
import fileinput
from lxml.etree import ElementTree, tostring, Element
from copy import deepcopy

#convert xml defintions for ST readers
#to use a file series reader
files = [
"vtkVisItADAPTReader.h",
"vtkVisItANALYZEReader.h",
"vtkVisItANSYSReader.h",
"vtkVisItAuxFileReader.h",
"vtkVisItBOVReader.h",
"vtkVisItCCSM_STSD_Reader.h",
"vtkVisItCEAucdReader.h",
"vtkVisItCMATReader.h",
"vtkVisItCTRLReader.h",
"vtkVisItChomboReader.h",
"vtkVisItCurve2DReader.h",
"vtkVisItDDCMDReader.h",
"vtkVisItDyna3DReader.h",
"vtkVisItExtrudedVolReader.h",
"vtkVisItFLASHReader.h",
"vtkVisItFVCOM_STSDReader.h",
"vtkVisItFluentReader.h",
"vtkVisItGTCReader.h",
"vtkVisItGadgetReader.h",
"vtkVisItImageReader.h",
"vtkVisItLinesReader.h",
"vtkVisItNASTRANReader.h",
"vtkVisItOVERFLOWReader.h",
"vtkVisItPATRANReader.h",
"vtkVisItPLOT2DReader.h",
"vtkVisItPLOT3DReader.h",
"vtkVisItPOSCARReader.h",
"vtkVisItParaDISReader.h",
"vtkVisItParaDISTecplotReader.h",
"vtkVisItPlainTextReader.h",
"vtkVisItPoint3DReader.h",
"vtkVisItProteinDataBankReader.h",
"vtkVisItRAWReader.h",
"vtkVisItSARReader.h",
"vtkVisItSpheralReader.h",
"vtkVisItTFTReader.h",
"vtkVisItTSurfReader.h",
"vtkVisItTecplotBinaryReader.h",
"vtkVisItTecplotReader.h",
"vtkVisItUNICReader.h",
"vtkVisItVelodyneReader.h",
"vtkVisItVsReader.h",
"vtkVisItXmdvReader.h",
"vtkVisItSiloReader.h"
]


def cleanedPath(x):
  #extract the name without extension and vtk 
  if(x[-2]=="."):
    x=x[:-2]
  if(x[:3]!="vtk"):
    x="vtk"+x
  return x

#converts a proxy name to an internal proxy name
def convertNameToInternalName(x):
  return x + "Core"

#converts an proxy to internal proxy
def convertProxyToInternalProxy(y):
  #will rename the proxy to use the Core convention
  #will also strip the hints
  x = deepcopy(y)
  x.set("base_proxyname","VisItReaderFileSeriesBase")
  x.set("name",convertNameToInternalName(x.get("name")))
  return x

#returns if the passes in proxy is in the valid reader list
def isSingleTimeStepReader(x,validReaders):
  return x.get("class") in validReaders

#returns if an xml element is the internal_readers xml element
def isInternalReaderGroup(x):
  return x.get("name") == "internal_readers" 

#concerts a collection of items into the valid readers
def buildSTReaderList(f):
  result = map(cleanedPath,files)
  return result

#searches the given tree for all valid single timestep readers
def findValidReaders(tree, validReaders):
  proxies = list(tree.iter("SourceProxy"))
  return [proxy for proxy in proxies if isSingleTimeStepReader(proxy,validReaders)]

#finds the root of the internal readers xml group
def findInternalReadersGroup(tree):
  #find the internal readers group and return that
  proxies = list(tree.iter("ProxyGroup"))
  return filter(isInternalReaderGroup,proxies)[0]

#converts a collection of readers to internal readers
def addReadersToInternalGroup(proxies, convertProxyToInternalProxyGroup):
  #convert a proxy to an internal proxy
  iproxies = map(convertProxyToInternalProxy,proxies)

  #add proxies to the convertProxyToInternalProxy group
  convertProxyToInternalProxyGroup.extend(iproxies)

#converts a reader to file series readers
def makeReaderFileSeries(reader):
  n = reader.get("name")
  del reader.attrib["base_proxygroup"]
  del reader.attrib["base_proxyname"]
  reader.set("class","vtkFileSeriesReader")
  reader.set("si_class","vtkSIFileSeriesReaderProxy")
  reader.set("file_name_method","SetFileName")

  fileSeriesTree = ElementTree();
  fileSeriesTree.parse("FileSeries.xml")
  reader.extend(fileSeriesTree.getroot())
  for p in reader.iter("Proxy"):
    p.set("proxyname",convertNameToInternalName(n))

def updateXML( validReaders ):
  #read in the xml file
  tree = ElementTree()
  tree.parse("databases/visit_readers.xml")
  
  proxies = findValidReaders(tree, validReaders)
  addReadersToInternalGroup(proxies,  findInternalReadersGroup(tree) )
  map(makeReaderFileSeries,proxies)

  return tostring(tree.getroot(),pretty_print=True)

if __name__ == "__main__":
  readers = buildSTReaderList(files)
  updatedXML = updateXML(readers)
  #write out pretty xml
  f = open("test.xml","w")
  f.write(updatedXML)
  f.close()
   
