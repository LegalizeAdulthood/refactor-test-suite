@echo off
if not exist ..\build-ninja goto no-ninja
if "X%1"=="X" goto bad-args
if "X%2"=="X" goto bad-args

clang-tidy --fix -p ../build-ninja --checks=-*,%1 %2
exit /b 0

:no-ninja
echo Missing build-ninja directory.  Use CMake preset ninja to generate compile_commands.json in ninja build.
exit /b 1

:badargs
echo Usage: run-clang-tidy [check] [file]
exit /b 1
