workspace "Lilasoul"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lilasoul"
    location "Practice"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h"
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        define
        {
            "LS_PLATFORM_WINDOWS"; 
            "LS_BUILD_DLL"; 
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configuration:Debug"
        defines "LS_DEBUG"
        symbols "On"
        
    filter "configuration:Release"
        defines "LS_RELEASE"
        optimize "On"

    filter "configuration:Dist"
        defines "LS_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"

    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h"
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Practice/vendor/spdlog/include"
        "Practice/src"
    }

    links
    {
        "Lilasoul"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        define
        {
            "LS_PLATFORM_WINDOWS"; 
        }


    filter "configuration:Debug"
        defines "LS_DEBUG"
        symbols "On"
        
    filter "configuration:Release"
        defines "LS_RELEASE"
        optimize "On"

    filter "configuration:Dist"
        defines "LS_DIST"
        optimize "On"