@echo off
setlocal
rem
rem Updates (or adds) the diff associated with a test.
rem
rem Usage: update [id]
rem
rem Example: update R100
rem
cls
echo %1
git diff -i RefactorTest
if NOT "X%1"=="X" set name=%1
if "X%name%"=="X" set /p "name=Test Name? "
if EXIST results\diffs\%name%.txt @echo Updating %name%.txt
if NOT EXIST results\diffs\%name%.txt @echo Adding %name%.txt
@echo on
git diff RefactorTest | more > results\diffs\%name%.txt
@git --no-pager diff -i results\diffs
