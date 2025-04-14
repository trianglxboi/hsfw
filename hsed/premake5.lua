project "hsed"
	language "c++"
	cppdialect "c++17"
	
	targetdir "%{outdir.bin}/%{prj.name}"
	objdir    "%{outdir.obj}/%{prj.name}"
	
	pchheader "hspch.hh"
	pchsource "%{incdir.hscore}/hspch.cc"
	
	files
	{
		"%{incdir.hscore}/hspch.hh",
		"%{incdir.hscore}/hspch.cc",
		
		"src/**.hh",
		"src/**.cc"
	}
	
	includedirs
	{
		"%{incdir.hscore}",
		"src",

		"%{incdir.glm}",
		"%{incdir.spdlog}"
	}
	
	links
	{
		"hscore"
	}
	
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"HS_PLATFORM_WINDOWS",
			"__CRT_SECURE_NO_WARNINGS"
		}
	
	filter "system:linux"
		defines
		{
			"HS_PLATFORM_LINUX"
		}
	
	filter "configurations:devel"
		runtime "debug"
		symbols "on"
		kind "consoleapp"
		defines
		{
			"HS_DEVEL"
		}
	
	filter "configurations:dist"
		runtime "release"
		optimize "speed"
		kind "windowedapp"
		defines
		{
			"HS_DIST"
		}
	