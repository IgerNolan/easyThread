@echo off

xmake g --theme=ninja -q
xmake f -c -p mingw --toolchain=gcc
xmake || (pause & cls & exit /b 1)

cls
