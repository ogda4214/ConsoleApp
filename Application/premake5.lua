project "Application"
  kind "ConsoleApp"
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
	
   includedirs
   {
		"%{wks.location}/Core/src",
   		"%{wks.location}/Core/vendor/spdlog/include",
		"%{wks.location}/Core/vendor"
   }

   links
   {
		"Core"
   }

   filter "system:windows"
		systemversion "latest"
		staticruntime "on"

   filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

   filter "configurations:Development"
		runtime "Release"
		optimize "on"

   filter "configurations:Release"
		runtime "Release"
		optimize "on"