VENDOR = "%{wks.location}/vendor"

outdir = {}
outdir["cc"] = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
outdir["bin"] = "%{wks.location}/bin/%{outdir.cc}"
outdir["obj"] = "%{wks.location}/bin-obj/%{outdir.cc}"

prjdir = {}
prjdir["hscore"] = "%{wks.location}/hscore"
prjdir["hsed"] = "%{wks.location}/hsed"
prjdir["hsrt"] = "%{wks.location}/hsrt"

incdir = {}
incdir["hscore"] = "%{prjdir.hscore}/src"
incdir["hsed"] = "%{prjdir.hsed}/src"
incdir["hsrt"] = "%{prjdir.hsrt}/src"
incdir["glm"] = "%{VENDOR}/glm"
incdir["spdlog"] = "%{VENDOR}/spdlog/include"
