# ReSharper for C++

Home: [ReSharper for C++](http://www.jetbrains.com/resharper-cpp/)

Version: 10.0.2

Notes:

* No quick fix is available for **Add Block Delimiter**.
* **Add Override** is available as a quick fix.
* **Add Parameter** is available through **Change Signature**.  Default file selections were accepted and the argument value of zero was chosen.
* **Create Multi-Variable Declaration** is available as a quick fix.

* **Remove Block Delimiter** is available as a quick fix.

## Add Override
Case | Result
---- | ------
AO1  | Pass
AO2  | Pass
AO3  | Pass
AO4  | Pass
AO5  | Pass

## Add Parameter
Case | Result
---- | ------
AP1  | Failure (does nothing)
AP2  | Pass
AP3  | Failure (does nothing)
AP4  | Pass
AP5  | Pass
AP6  | Pass
AP7  | Pass
AP8  | Pass
AP9  | Pass
AP10 | Pass
AP11 | Pass
AP12 | Pass
AP13 | Failure (can't cope with overloads)
AP14 | Pass
AP15 | Pass
AP16 | Pass
AP17 | Pass
AP18 | Pass
AP19 | Failure (does nothing)
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Failure (does nothing)

## Change Signature
Case | Result
---- | ------
CS1  | Pass
CS2  | Pass
CS3  | Pass
CS4  | Pass
CS5  | Pass
CS6  | Pass
CS7  | Pass
CS8  | Pass
CS9  | Pass
CS10 | Pass
CS11 | Pass

## Create Declaration From Implementation

## Create Implementation From Declaration

## Create Method Stub

## Create Multi-Variable Declaration
Case | Result
---- | ------
CMVD1  | Pass
CMVD2  | Pass
CMVD3  | Pass
CMVD4  | Pass
CMVD5  | Pass
CMVD6  | Failure
CMVD7  | Pass
CMVD8  | Pass
CMVD9  | Pass
CMVD10 | Pass
CMVD11 | Pass
CMVD12 | Pass

## Extract Function
Case | Result
---- | ------
EXF1 | 
EXF2 | 
EXF3 | 
EXF4 | 
EXF5 | 
EXF6 | 
EXF7 | 
EXF8 | 
EXF9 | 
EXF10 | 
EXF11 | 
EXF12 | 
EXF13 | 
EXF14 | 
EXF15 | 
EXF16 | 
EXF17 | 
EXF18 | 
EXF19 | 
EXF20 | 

## Extract Method
Case | Result
---- | ------
EM1 | 
EM2 | 
EM3 | 
EM4 | 
EM5 | 
EM6 | 
EM7 | 
EM8 | 
EM9 | 
EM10 | 
EM11 | 
EM12 | 
EM13 | 
EM14 | 
EM15 | 
EM16 | 
EM17 | 
EM18 | 
EM19 | 
EM20 | 

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | 
MISF2  | 
MISF3  | 
MISF4  | 
MISF5  | 
MISF6  | 
MISF7  | 
MISF8  | 
MISF9  | 
MISF10 | 
MISF11 | 
MISF12 | 
MISF13 | 
MISF14 | 
MISF15 | 
MISF16 | 
MISF17 | 
MISF18 | 
MISF19 | 
MISF20 | 
MISF21 | 
MISF22 | 
MISF23 | 
MISF24 | 
MISF25 | 
MISF26 | 

## Remove Block Delimiter
Case | Result
---- | ------
RBD1 | Pass
RBD2 | Pass
RBD3 | Pass
RBD4 | Pass
RBD5 | Pass
RBD6 | Pass
RBD7 | Pass
RBD8 | Pass

## Rename
Case | Result
---- | ------
R1   | Pass
R2   | Pass
R3   | Pass
R4   | Pass
R5   | Pass
R6   | Pass
R7   | Pass
R8   | Pass
R9   | Pass
R10  | Pass
R11  | Pass
R12  | Pass
R13  | Pass
R14  | Pass
R15  | Pass
R16  | Pass
R17  | Pass
R18  | Pass
R19  | Pass
R20  | Pass
R21  | Pass
R22  | Pass
R23  | Pass
R24  | Pass
R25  | Failure (unavailable)
R26  | Pass
R27  | Pass
R28  | Pass
R29  | Pass
R30  | Pass
R31  | Pass
R32  | Failure (misses usage in typedef)
R33  | Pass
R34  | Pass
R35  | Pass
R36  | Pass
R37  | Pass
R38  | Pass
R39  | Pass
R40  | Pass
R41  | Pass
R42  | Pass
R43  | Pass
R44  | Pass
R45  | Pass
R46  | Pass
R47  | Pass
R48  | Pass
R49  | Pass
R50  | Pass
R51  | Pass
R52  | Pass
R53  | Pass
R54  | Pass
R55  | Pass
R56  | Pass
R57  | Pass
R58  | Pass
R59  | Pass
R60  | Pass
R61  | Pass
R62  | Pass
R63  | Pass
R64  | Pass
R65  | Pass
R66  | Pass
R67  | Pass
R68  | Pass
R69  | Pass
R70  | Pass
R71  | Pass
R72  | Pass
R73  | Pass
R74  | Pass
R75  | Pass
R76  | Pass
R77  | Pass
R78  | Pass
R79  | Pass
R80  | Pass
R81  | Pass
R82  | Failure (unavailable)
R83  | Failure (unavailable)
R84  | Pass
R85  | Pass
R86  | Pass
R87  | Pass
R88  | Pass
R89  | Pass
R90  | Pass
R91  | n/a
R92  | n/a
R93  | Pass
R94  | Pass
R95  | Pass
R96  | Pass
R97  | Pass
R98  | Pass
