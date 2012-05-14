import os
import fileinput
from xml.etree.ElementTree import ElementTree, tostring

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
"vtkVisItEnzoReader.h",
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
"vtkVisItSAMRAIReader.h",
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
"vtkVisItSiloReader"
]

fileSeriesTree = ElementTree();
fileSeriesTree.parse("FileSeries.xml")

def cleanedPath(x):
  #extract the name without extension and vtk 
  if(x[-2]=="."):
    x=x[:-2]
  if(x[:3]=="vtk"):
    x=x[3:]
  return x

#converts a proxy name to an internal proxy name
def convertNameToInternalName(x):
  return x + "Core"

#converts an proxy to internal proxy
def convertProxyToInternalProxy(x):
  #will rename the proxy to use the Core convention
  #will also strip the hints
  x.remove(x.find("Documentation"))
  x.remove(x.find("Hints"))
  n = map(convertNameToInternalName,x.attrib["name"])
  x.set("name",n)
  return x;

#returns if the passes in proxy is in the valid reader list
def isSingleTimeStepReader(x):
  return x.attrib["name"] in validReaders

#returns if an xml element is the internal_readers xml element
def isInternalReaderGroup(x):
  return x.attrib["name"] == "internal_readers" 

#concerts a collection of items into the valid readers
def buildSTReaderList(f):
  result = map(cleanedPath,files)
  return result

#searchs the given tree for all valid single timestep readers
def findValidReaders(tree, validReaders):
  proxies = list(tree.iter("SourceProxy"))
  return filter(isSingleTimeStepReader,proxies)  

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
  convertProxyToInternalProxyGroup.extend(iproxy)

#converts a collection of reader to file series readers
def makeReaderFileSeries(proxies):
  #will insert the FileSeries xml code
  #to the proxy to make it use the proper
  #internal reader
  proxy.append(fileSeriesTree.getroot())
  
    
def updateXML( validReaders ):
  #read in the xml file
  tree = ElementTree()
  tree.parse("databases/visit_readers.xml")
  
  proxies = findValidReaders(tree, validReaders)
  addReadersToInternalGroup(proxies,  findInteralReadersGroup(tree) )
  makeReadersFileSeries(proxies)

  
  x = tostring(tree.getroot())

  print x

if __name__ == "__main__":
  readers = buildSTReaderList(files)
  updateXML(readers)
   