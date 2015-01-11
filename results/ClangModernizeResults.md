# clang-modernize

Home: [clang-modernize](http://clang.llvm.org/extra/clang-modernize.html)

Version: 3.4

## Add override
Case | Result
---- | ------
AO1 | Pass
AO2 | Pass
AO3 | Pass
AO4 | Pass
AO5 | Pass

## Replace auto_ptr with unique_ptr
Case | Result
---- | ------
RAWU1 | Pass
RAWU2 | Pass
RAWU3 | Pass
RAWU4 | Pass

## Replace iterative for with range for
Case | Result
---- | ------
RIRF1 | Pass
RIRF2 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF3 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF4 | Pass
RIRF5 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF6 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF7 | Pass
RIRF8 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF9 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF10 | Pass
RIRF11 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF12 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF13 | Pass
RIRF14 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF15 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF16 | Pass
RIRF17 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF18 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF19 | Pass
RIRF20 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF21 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF22 | Pass
RIRF23 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF24 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF25 | Pass
RIRF26 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF27 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF28 | Pass
RIRF29 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF30 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF31 | Pass
RIRF32 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF33 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF34 | Pass
RIRF35 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF36 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF37 | Pass
RIRF38 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF39 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF40 | Pass
RIRF41 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF42 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF43 | Pass
RIRF44 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF45 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF46 | Pass
RIRF47 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF48 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF49 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF50 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF51 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF52 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF53 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF54 | Pass
RIRF55 | Failure [22196](http://llvm.org/bugs/show_bug.cgi?id=22196)
RIRF56 | Pass
RIRF57 | Pass
RIRF58 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF59 | Pass
RIRF60 | Pass
RIRF61 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF62 | Pass
RIRF63 | Pass
RIRF64 | Failure [22194](http://llvm.org/bugs/show_bug.cgi?id=22194)
RIRF65 | Pass
RIRF66 | Pass
RIRF67 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)
RIRF68 | Failure [22195](http://llvm.org/bugs/show_bug.cgi?id=22195)

## Replace NULL/0 with nullptr
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

## Replace type with auto
Case | Result
---- | ------
RTWA1 |
RTWA2 |
RTWA3 |
RTWA4 |
RTWA5 |
RTWA6 |
RTWA7 |
RTWA8 |
RTWA9 |
RTWA10 |
RTWA11 |
RTWA12 |
RTWA13 |
RTWA14 |
RTWA15 |
RTWA16 |
RTWA17 |
RTWA18 |
RTWA19 |
RTWA20 |
RTWA21 |
RTWA22 |
RTWA23 |
RTWA24 |
RTWA25 |
RTWA26 |
RTWA27 |
RTWA28 |
RTWA29 |
RTWA30 |
RTWA31 |
RTWA32 |
