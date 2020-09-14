workspace "Mirror"
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
			"MR_Platform_Windows",
			"MR_Build_DLL"
	  }

	  postbuildcommands{
	  ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Interface")
	  }

   filter "configurations:Debug"
      defines "MR_DEBUG"
	  symbols "on"

   filter "configurations:Release"
      defines "MR_DEBUG"
	  optimize "on"
   
   filter "configurations:Dist"
      defines "MR_DEBUG"
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

           "Mirror/vendor/spdlog/include",
		   "Mirror/src"
  }

  links{
		"Mirror"
  }

  filter "system:windows"
      cppdialect "c++17"
	  staticruntime "on"
	  systemversion "latest"

	  defines{
			"MR_Platform_Windows"
	  }

	 
   filter "configurations:Debug"
      defines "MR_DEBUG"
	  symbols "on"

   filter "configurations:Release"
      defines "MR_DEBUG"
	  optimize "on"
   
   filter "configurations:Dist"
      defines "MR_DEBUG"
	  optimize "on"
