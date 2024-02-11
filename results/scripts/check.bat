@echo off
rem
rem Usage: check [id]
rem
rem Example: check R100
rem
setlocal
set diff=%TEMP%\diff.txt
set toolDiff=%TEMP%\diff-tools.txt
set empty=%TEMP%\empty.txt
set out=%TEMP%\out.txt
if not exist %empty% copy nul: %empty% > nul:
cls
git diff RefactorTest | find /v "index" | drop-comments > %diff%
if not exist results\diffs\%1.txt exit /b 1
call :compare %1 > %out%
more < %out%
exit /b 0

:compare
echo Comparing diffs for %1
find /v "index" < results\diffs\%1.txt | drop-comments | @diff -i -c - %diff%
git diff Tools > %toolDiff%
comp %empty% %toolDiff% /m > nul:
if not errorlevel 1 exit /b 0
echo.
echo Tools were changed:
git status Tools | find "modified:"
echo.
exit /b 0
