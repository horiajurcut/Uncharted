workspace "Uncharted"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Uncharted"
    location "Uncharted"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
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

        defines
        {
            "UNCHARTED_PLATFORM_WINDOWS",
            "UNCHARTED_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "UNCHARTED_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UNCHARTED_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "UNCHARTED_DIST"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs
        {
            "Uncharted/vendor/spdlog/include",
            "Uncharted/src"
        }

        links
        {
            "Uncharted"
        }
    
        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "UNCHARTED_PLATFORM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "UNCHARTED_DEBUG"
            symbols "On"
    
        filter "configurations:Release"
            defines "UNCHARTED_RELEASE"
            optimize "On"
    
        filter "configurations:Dist"
            defines "UNCHARTED_DIST"
            optimize "On"
