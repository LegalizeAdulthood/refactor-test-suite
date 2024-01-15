@echo off
rem
rem Usage: file-check [test]
rem
rem Example: file-check ABD
rem
setlocal
set diff=%TEMP%\diff.txt
cls
git diff RefactorTest | find /v "index" | drop-comments > %diff%
if not exist results\file-diffs\%1.txt exit /b 1
echo Comparing file diffs for %1
find /v "index" < results\file-diffs\%1.txt | drop-comments | diff -i -c - %diff%
