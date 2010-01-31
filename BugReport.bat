@echo off
set dest=Bugs\%1
set rt=%dest%\RefactorTest
mkdir %dest%
mkdir %rt%

copy *.sln %dest%
copy RefactorTest\*.h %rt%
copy RefactorTest\*.cpp %rt%
copy RefactorTest\*.vcproj %rt%
