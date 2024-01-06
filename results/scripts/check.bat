@cls
@git diff RefactorTest | find /v "index" | find /v "//" > c:\tmp\diff.txt
@echo %1
@find /v "index" < results\diffs\%1.txt | find /v "//" | @diff -i -c - c:\tmp\diff.txt
