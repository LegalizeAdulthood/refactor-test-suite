@setlocal
@cls
@echo %1
@git diff -i RefactorTest
@if NOT "X%1"=="X" set name=%1
@if "X%name%"=="X" set /p "name=Test Name? "
@if EXIST results\diffs\%name%.txt @echo Updating %name%.txt
git diff RefactorTest > results\diffs\%name%.txt
git restore RefactorTest
@git --no-pager diff -i results
