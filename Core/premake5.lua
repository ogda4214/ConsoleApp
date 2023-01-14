project "Core"
	kind "StaticLib"
	language "C++"
	toolset "v142"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"src/**.h",
		"src/**.cpp"
	}

  	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

   includedirs
   {
		"src",
		"vendor/spdlog/include"
   }

   links
   {
		"opengl32.lib"
   }

   filter "system:windows"
		systemversion "latest"

   filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

   filter "configurations:Development"
		runtime "Release"
		optimize "on"

   filter "configurations:Release"
		runtime "Release"
		optimize "on"