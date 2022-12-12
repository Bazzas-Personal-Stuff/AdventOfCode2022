workspace "AdventOfCode2022"
    architecture "x64"
    startproject "AdventOfCode2022"

    configurations{
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "vendor/gtest"

group ""

project "AdventOfCode2022"
    --location "AdventOfCode2022"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "%{prj.name}")
    
    pchheader "pch.h"
    pchsource "src/pch.cpp"

    includedirs {
        "src/Util",
        "vendor/gtest/googletest/include",
        --"vendor/gtest/googletest",
    }

    files {
        --"%{prj.name}/src/**.h",
        --"%{prj.name}/src/**.cpp",
        "src/**.h",
        "src/**.cpp",
    }

    links {
        "gtest",
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Debug"
        runtime "Release"
        optimize "On"
