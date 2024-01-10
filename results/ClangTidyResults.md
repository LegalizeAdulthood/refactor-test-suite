# clang-tidy

Home: [clang-tidy](https://clang.llvm.org/extra/clang-tidy/index.html)

Version: 17.0.6

* clang-tidy support may be integrated into an IDE, such as ReSharper for C++.
* All tests performed by invoking clang-tidy from the command-line on a source file.
* clang-tidy checks configured through `.clang-tidy` configuration file
* **Add Block Delimiter** available through check [*readability-braces-around-statements*](https://clang.llvm.org/extra/clang-tidy/checks/readability-braces-around-statements.html)
* **Add Override** available through check [*modernize-use-override*](https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-override.html)
* **Replace `auto_ptr` With `unique_ptr`** available through check [*modernize-replace-auto-ptr*](https://clang.llvm.org/extra/clang-tidy/checks/modernize-replace-auto-ptr.html)
* **Replace Iterative For With Range For** available through check [*modernize-loop-convert*](https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html)
* **Replace `NULL`/`0` With `nullptr`** available through check [*modernize-use-nullptr*](https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-nullptr.html)
* **Replace Type With `auto`** available through check [*modernize-use-auto*](https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-auto.html)

## Add Block Delimiter
Case | Result
---- | ------
ABD1 | Pass
ABD2 | Pass
ABD3 | Pass
ABD4 | Pass
ABD5 | Pass
ABD6 | Pass
ABD7 | Pass

## Add Override
Case | Result
---- | ------
AO1 | Pass
AO2 | Pass
AO3 | Pass
AO4 | Pass
AO5 | Pass
AO6 | Pass
AO7 | Pass
AO8 | Pass
AO9 | Pass
AO10 | Pass
AO11 | Pass
AO12 | Pass
AO13 | Pass
AO14 | Pass
AO15 | Pass
AO16 | Pass

## Replace auto_ptr With unique_ptr
Case | Result
---- | ------
RAWU1 | Pass
RAWU2 | Pass
RAWU3 | Pass
RAWU4 | Pass

## Replace Iterative For With Range For
Case | Result
---- | ------
RIRF1 | Pass
RIRF2 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF3 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF4 | Pass
RIRF5 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF6 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF7 | Pass
RIRF8 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF9 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF10 | Pass
RIRF11 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF12 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF13 | Pass
RIRF14 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF15 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF16 | Pass
RIRF17 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF18 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF19 | Pass
RIRF20 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF21 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF22 | Pass
RIRF23 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF24 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF25 | Pass
RIRF26 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF27 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF28 | Pass
RIRF29 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF30 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF31 | Pass
RIRF32 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF33 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF34 | Pass
RIRF35 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF36 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF37 | Pass
RIRF38 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF39 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF40 | Pass
RIRF41 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF42 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF43 | Pass
RIRF44 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF45 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF46 | Pass
RIRF47 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF48 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF49 | Failure (substitutes internal typedefs) [36688](https://bugs.llvm.org/show_bug.cgi?id=36688)
RIRF50 | Failure (doesn't recognize caching end compare) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF51 | Failure (doesn't recognize caching end compare, reverse loop) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196), [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF52 | Failure (doesn't recognize caching end compare) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF53 | Failure (doesn't recognize caching end compare, reverse loop) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196), [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF54 | Pass
RIRF55 | Failure (doesn't recognize caching end compare, reverse loop) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196), [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF56 | Pass
RIRF57 | Pass
RIRF58 | Failure (doesn't recognize 0..N-1 loop) [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF59 | Pass
RIRF60 | Pass
RIRF61 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF62 | Pass
RIRF63 | Pass
RIRF64 | Failure (doesn't recognize caching end compare, 0..N-1 loop) [22196](http://llvm.org/bugs/show_bug.cgi?id=22196), [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF65 | Pass
RIRF66 | Pass
RIRF67 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF68 | Failure (doesn't recognize reverse loop) [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)

## Replace NULL/0 With nullptr
Case | Result
---- | ------
RZNP1   | Pass
RZNP2   | Pass
RZNP3   | Pass
RZNP4   | Pass
RZNP5   | Pass
RZNP6   | Pass
RZNP7   | Pass
RZNP8   | Pass
RZNP9   | Pass
RZNP10  | Pass
RZNP11  | Pass
RZNP12  | Pass
RZNP13  | Pass
RZNP14  | Pass
RZNP15  | Pass
RZNP16  | Pass
RZNP17  | Pass
RZNP18  | Pass
RZNP19  | Pass
RZNP20  | Pass
RZNP21  | Pass
RZNP22  | Pass
RZNP23  | Pass
RZNP24  | Pass
RZNP25  | Pass
RZNP26  | Pass
RZNP27 | 
RZNP28 | 

## Replace Type With auto
Case | Result
---- | ------
RTWA1 | Pass
RTWA2 | Pass
RTWA3 | Pass
RTWA4 | Pass
RTWA5 | Pass
RTWA6 | Pass
RTWA7 | Pass
RTWA8 | Pass
RTWA9 | Pass
RTWA10 | Pass
RTWA11 | Pass
RTWA12 | Pass
RTWA13 | Pass
RTWA14 | Pass
RTWA15 | Pass
RTWA16 | Pass
RTWA17 | Pass
RTWA18 | Pass
RTWA19 | Pass
RTWA20 | Pass
RTWA21 | Pass
RTWA22 | (deprecated)
RTWA23 | Pass
RTWA24 | (deprecated)
RTWA25 | Pass
RTWA26 | (deprecated)
RTWA27 | Pass
RTWA28 | (deprecated)
RTWA29 | Pass
RTWA30 | Pass
RTWA31 | Pass
RTWA32 | Pass
