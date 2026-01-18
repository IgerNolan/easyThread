-- set_xmakever("3.0.0")
set_project(path.basename(os.projectdir()))
local PROJECT_VERSION = "1.0.0"
set_version(PROJECT_VERSION)
set_languages("cxx11")
set_defaultmode("release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"})
add_defines("THREAD_POOL_VERSION=\"" .. PROJECT_VERSION .. "\"")

target("easyThread")
    set_kind("static")
    set_targetdir(os.projectdir() .. "/lib")
    add_includedirs(os.projectdir() .. "/include")
    add_files(os.projectdir() .. "/src/**.cc")
    add_cxflags(
        "-O2",
        "-Wall",
        "-Wbuiltin-macro-redefined",
        "-Wcast-align",
        "-Wcast-qual",
        "-Wconversion",
        "-Wdouble-promotion",
        "-Wduplicated-branches",
        "-Wduplicated-cond",
        "-Werror",
        "-Wextra",
        "-Wfloat-conversion",
        "-Wformat-overflow=2",
        "-Wformat-truncation=2",
        "-Wformat=2",
        "-Winit-self",
        "-Wlogical-op",
        "-Wmissing-declarations",
        "-Wmissing-include-dirs",
        "-Wnull-dereference",
        "-Wpedantic",
        "-Wredundant-decls",
        "-Wshadow",
        "-Wsign-conversion",
        "-Wstrict-aliasing",
        "-Wstrict-overflow=2",
        "-Wswitch-default",
        "-Wswitch-enum",
        "-Wtrampolines",
        "-Wundef",
        "-Wuninitialized",
        "-Wunused"
    )
target_end()

target("test")
    set_kind("binary")
    set_targetdir(os.projectdir() .. "/bin")
    add_includedirs(os.projectdir() .. "/include")
    add_includedirs(os.projectdir() .. "/test/include")
    add_files(os.projectdir() .. "/test/src/**.cc")
    add_linkdirs(os.projectdir() .. "/lib")
    add_links("easyThread")
    add_syslinks("pthread", "stdc++fs")
    add_cxflags(
        "-O2",
        "-Wall",
        "-Wbuiltin-macro-redefined",
        "-Wcast-align",
        "-Wcast-qual",
        "-Wconversion",
        "-Wdouble-promotion",
        "-Wduplicated-branches",
        "-Wduplicated-cond",
        "-Werror",
        "-Wextra",
        "-Wfloat-conversion",
        "-Wformat-overflow=2",
        "-Wformat-truncation=2",
        "-Wformat=2",
        "-Winit-self",
        "-Wlogical-op",
        "-Wmissing-declarations",
        "-Wmissing-include-dirs",
        "-Wnull-dereference",
        "-Wpedantic",
        "-Wredundant-decls",
        "-Wshadow",
        "-Wsign-conversion",
        "-Wstrict-aliasing",
        "-Wstrict-overflow=2",
        "-Wswitch-default",
        "-Wswitch-enum",
        "-Wtrampolines",
        "-Wundef",
        "-Wuninitialized",
        "-Wunused"
    )
target_end()
