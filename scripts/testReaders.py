from paraview.simple import *

sm = paraview.servermanager
sources = sm.sources.__dict__

for source in sources:
  try:
    s = sources[source]()
    s.UpdateVTKObjects()
    print s
  except Exception, e:
    raise
  else:
    pass
  finally:
    pass
