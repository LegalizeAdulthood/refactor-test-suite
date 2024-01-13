@echo off
setlocal
set diff=%TEMP%\diff.txt
cls
git diff RefactorTest | find /v "index" > %diff%
if not exist results\diffs\%1.txt exit /b 1
echo Comparing diffs for %1
find /v "index" < results\diffs\%1.txt | @diff -i -c - %diff%
