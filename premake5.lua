workspace "ConsoleApp"
	architecture "x86_64"
	startproject "Application"

	configurations
	{
		"Debug",
		"Development",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Core"
include "Application"