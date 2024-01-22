@echo off
rem
rem Usage: check [id]
rem
rem Example: check R100
rem
setlocal
set diff=%TEMP%\diff.txt
cls
git diff RefactorTest | find /v "index" | drop-comments > %diff%
if not exist results\diffs\%1.txt exit /b 1
echo Comparing diffs for %1
find /v "index" < results\diffs\%1.txt | drop-comments | @diff -i -c - %diff% | more
