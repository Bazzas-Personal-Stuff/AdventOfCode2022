project "gtest"
    kind "StaticLib"
    language "C++"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "googletest/include",
        "googletest",
    }

    files {
        "googletest/**.h",
        "googletest/**.hpp",
        "googletest/src/gtest-all.cc",
    }