worspace "Mirror"
 architecture "x64"

 configurations{
	  "Debug",
	  "Release",
	  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "Mirror"
  location "Mirror"
  kind "Sharedlib"
  language "C++"

  targetdir ("bin/"..outputdir.."/%{prj.name}")
  objdir ("bin-int/"..outputdir.."/%{prj.name}")

  files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

  }

  includedirs{

           "%{prj.name}/vendor/spdlog/include"

  }

  filter "system:windows"
      cppdialect "c++17"
	  staticruntime "on"
	  systemversion "latest"

	  defines{
			"MR_PLATFORM_WINDOWS",
			"MR_BUILD_DLL"
	  }

	  postbuildcommands{
	  ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Interface")
	  }

   filter "configurations:Debug"
      define "MR_DEBUG"
	  symbols "on"

   filter "configurations:Release"
      define "MR_DEBUG"
	  optimize "on"
   
   filter "configurations:Dist"
      define "MR_DEBUG"
	  optimize "on"





 project "Interface"
  location "Interface"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/"..outputdir.."/%{prj.name}")
  objdir ("bin-int/"..outputdir.."/%{prj.name}")

  files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

  }

  includedirs{

           "%{prj.name}/vendor/spdlog/include",
		   "Mirror\src"
  }

  links{
		"Mirror"
  }

  filter "system:windows"
      cppdialect "c++17"
	  staticruntime "on"
	  systemversion "latest"

	  defines{
			"MR_PLATFORM_WINDOWS"
	  }

	 
   filter "configurations:Debug"
      define "MR_DEBUG"
	  symbols "on"

   filter "configurations:Release"
      define "MR_DEBUG"
	  optimize "on"
   
   filter "configurations:Dist"
      define "MR_DEBUG"
	  optimize "on"
