@cls
@git diff RefactorTest | find /v "index" | find /v "//" > c:\tmp\diff.txt
@if not exist results\file-diffs\%1.txt exit /b 1
@echo Comparing file diffs for %1
@find /v "index" < results\file-diffs\%1.txt | find /v "//" | @diff -i -c - c:\tmp\diff.txt
