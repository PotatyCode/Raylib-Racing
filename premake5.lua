workspace "RacingGame"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "RacingGame"

    -- Output directories
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include directories
    IncludeDirs = {}
    IncludeDirs["raylib"] = "vendor/raylib/include"

    -- Library directories
    LibDirs = {}
    LibDirs["raylib"] = "vendor/raylib/lib"

project "RacingGame"
    location "."
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "src/main.cpp",
        "game/src/**.cpp",
        "core/src/**.cpp",
        "game/include/**.hpp",
        "core/include/**.hpp"
    }

    includedirs
    {
        "core/include",
        "game/include",
        "%{IncludeDirs.raylib}"
    }

    libdirs
    {
        "%{LibDirs.raylib}"
    }

    links
    {
        "raylib"
    }

    -- Platform-specific settings
    filter "system:windows"
        systemversion "latest"
        links { "winmm", "gdi32", "opengl32" }

    filter "system:linux"
        links { "dl", "pthread", "GL", "m", "X11" }

    filter "system:macosx"
        links { "Cocoa.framework", "OpenGL.framework", "IOKit.framework" }

    -- Debug configuration
    filter "configurations:Debug"
        defines { "DEBUG", "_DEBUG" }
        runtime "Debug"
        symbols "On"
        optimize "Off"
        flags { "MultiProcessorCompile" }

    -- Debug GCC/Clang specific flags (Linux/Mac)
    filter { "configurations:Debug", "toolset:gcc or clang" }
        buildoptions { 
            "-g",
            "-O0",
            "-fno-omit-frame-pointer"
        }

    -- Debug MSVC specific flags (Windows)
    filter { "configurations:Debug", "system:windows" }
        buildoptions { "/Od", "/Zi" }

    -- Release configuration  
    filter "configurations:Release"
        defines { "NDEBUG", "RELEASE" }
        runtime "Release"
        optimize "Speed"
        symbols "Off"
        flags { 
            "LinkTimeOptimization",
            "MultiProcessorCompile"
        }

    -- Release GCC/Clang specific flags (Linux/Mac)
    filter { "configurations:Release", "toolset:gcc or clang" }
        buildoptions {
            "-O3",
            "-march=native",
            "-mtune=native",
            "-flto",
            "-ffast-math",
            "-funroll-loops",
            "-fomit-frame-pointer"
        }
        linkoptions {
            "-flto",
            "-s"
        }

    -- Release MSVC specific flags (Windows)
    filter { "configurations:Release", "system:windows" }
        buildoptions { 
            "/O2",          -- Max optimization
            "/GL",          -- Whole program optimization
            "/fp:fast"      -- Fast floating point
        }
        linkoptions { "/LTCG" }  -- Link-time code generation

    filter {}

-- Helper premake commands
newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate files",
    execute = function()
        print("Cleaning...")
        os.rmdir("./bin")
        os.rmdir("./bin-int")
        os.remove("Makefile")
        os.remove("*.make")
        os.remove("RacingGame.sln")
        os.remove("RacingGame.vcxproj")
        os.remove("RacingGame.vcxproj.filters")
        os.remove("RacingGame.vcxproj.user")
        print("Done.")
    end
}
