@echo off
rem Implements a workflow for running through a sequence of tests
rem and adding/updating recorded diffs.
rem
rem Usage: update-seq [test] [start]
rem
rem Example: update-seq R 100
rem
setlocal
set prefix=%1
set i=%2
if "X%prefix%"=="X" goto badargs
if "X%i%"=="X" goto badargs
:next
echo.
echo Perform test %prefix%%i%
set /p "cont=Continue? "
if not "X%cont%"=="X" exit /b 0
call update %prefix%%i%
set /p "next=Next? "
if not "X%next%"=="X" exit /b 0
call restore
set /a i=i+1
goto next
goto next

:badargs
echo Usage: update-seq [prefix] [number]
exit /b 1
