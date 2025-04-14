project "hscore"
	language "c++"
	cppdialect "c++17"
	kind "staticlib"
	
	targetdir "%{outdir.bin}/%{prj.name}"
	objdir    "%{outdir.obj}/%{prj.name}"
	
	pchheader "hspch.hh"
	pchsource "src/hspch.cc"
	
	files
	{
		"src/**.hh",
		"src/**.cc"
	}
	
	includedirs
	{
		"src",

		"%{incdir.glm}",
		"%{incdir.spdlog}"
	}
	
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"HS_PLATFORM_WINDOWS",
			"__CRT_SECURE_NO_WARNINGS"
		}
		excludes
		{
			"src/platform/linux/**.cc"
		}
	
	filter "system:linux"
		defines
		{
			"HS_PLATFORM_LINUX"
		}
		excludes
		{
			"src/platform/windows/**.cc"
		}
	
	filter "configurations:devel"
		runtime "debug"
		symbols "on"
		defines
		{
			"HS_DEVEL"
		}
	
	filter "configurations:dist"
		runtime "release"
		optimize "speed"
		defines
		{
			"HS_DIST"
		}
	