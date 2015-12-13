workspace "cpp-allocator"
	configurations {"Debug", "Release"}
	location "build"
	
project "mem-allocator"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	
	
	files {"inc/**.hpp", "src/**.cpp"}
	
	includedirs{"inc/"}
	
	configurations {"linux", "gmake"}
		buildoptions {"-std=c++11"}
		
	filter "configurations:Debug"
		defines {"DEBUG"}
		flags {"Symbols"}
		
	filter "configurations:Release"
		defines {"NDEBUG"}
		optimize "On"