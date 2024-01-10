@echo off
rem Implements a workflow for running through a sequence of tests
rem and comparing local changes to the git repository to recorded
rem diffs for tests.
setlocal
set prefix=%1
set i=%2
if "X%prefix%"=="X" goto badargs
if "X%i%"=="X" goto badargs
:next
if not exist results\diffs\%prefix%%i%.txt goto no-such-diff
type c:\tmp\oneline.txt
echo Perform test %prefix%%i%
pause
call check %prefix%%i%
set /p "next=Next? "
if not "X%next%"=="X" exit /b 0
call restore
set /a i=i+1
goto next
goto next

:no-such-diff
echo No diff for test %prefix%%i%
exit /b 1

:badargs
echo Usage: check-seq [prefix] [number]
exit /b 1
