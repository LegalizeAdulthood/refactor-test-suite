@echo off
rem Copies one test case diff to another test case.
rem
rem Usage: copy-diff [test] [src] [dst]
rem
rem Example: copy-diff R 230 240
rem
setlocal
set prefix=%1
set src=%2
set dst=%3
@echo on
copy results\diffs\%prefix%%src%.txt results\diffs\%prefix%%dst%.txt /y > nul:
@git diff results
