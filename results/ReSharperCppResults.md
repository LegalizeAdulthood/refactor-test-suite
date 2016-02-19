# ReSharper for C++

Home: [ReSharper for C++](http://www.jetbrains.com/resharper-cpp/)

Version: 10.0.2

Notes:
* **Add Block Delimiter** is available as a quick fix.  The tests pass if only code is selected and not the surrounding comment lines.
* **Add Override** is available as the quick fix *Add 'override' specifier to an overriding function*.
* **Add Parameter** is available through **Change Signature**.  Default file selections were accepted and the argument value of zero was chosen.
* **Create Multi-Variable Declaration** is available as the quick fix *Join declarations*.
* **Flatten Conditional** is available as the quick fix *Merge nested 'if' statements*.
* **Inline Macro** is available as the quick fix *Substitute macro call*.
* **Make Method Static** is available as a quick fix.
* **Move Implementation to Source File** is available as the quick fix *Move function implementation to source file*.
* **Remove Block Delimiter** is available as the quick fix *Remove braces*.
* **Remove Unused Parameter** is available as a quick fix.
* **Reorder Parameters** is available through **Change Signature**.
* **Replace If With Ternary** is available as the quick fix *Convert 'if' to '?:'*.
* **Reverse Conditional** is available as the quick fix *Invert 'if' statement*.
* **Split Multi-Variable Declaration** is available as the quick fix *Split declaration with multiple declarators*.

<hr/>

## Add Block Delimiter
Case | Result
---- | ------
ABD1 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD2 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD3 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD4 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD5 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD6 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD7 | Failure (tries to surround lines with parenthesis) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)

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
AP1  | Failure (does nothing) [RSCPP-15790](https://youtrack.jetbrains.com/issue/RSCPP-15790)
AP2  | Pass
AP3  | Failure (does nothing) [RSCPP-15790](https://youtrack.jetbrains.com/issue/RSCPP-15790)
AP4  | Pass
AP5  | Pass
AP6  | Pass
AP7  | Pass
AP8  | Pass
AP9  | Pass
AP10 | Pass
AP11 | Pass
AP12 | Pass
AP13 | Failure (can't cope with overloads) [RSCPP-15790](https://youtrack.jetbrains.com/issue/RSCPP-15790)
AP14 | Pass
AP15 | Pass
AP16 | Pass
AP17 | Pass
AP18 | Pass
AP19 | Failure (does nothing) [RSCPP-15790](https://youtrack.jetbrains.com/issue/RSCPP-15790)
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Failure (does nothing) [RSCPP-15790](https://youtrack.jetbrains.com/issue/RSCPP-15790)

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

## Create Multi-Variable Declaration
Case | Result
---- | ------
CMVD1  | Pass
CMVD2  | Pass
CMVD3  | Pass
CMVD4  | Pass
CMVD5  | Pass
CMVD6  | Failure [RSCPP-15791](https://youtrack.jetbrains.com/issue/RSCPP-15791)
CMVD7  | Pass
CMVD8  | Pass
CMVD9  | Pass
CMVD10 | Pass
CMVD11 | Pass
CMVD12 | Pass

## Extract Function
Case | Result
---- | ------
EXF1 | Pass
EXF2 | Pass
EXF3 | Pass
EXF4 | Pass
EXF5 | Pass
EXF6 | Pass
EXF7 | Pass
EXF8 | Pass
EXF9 | Pass
EXF10 | Pass
EXF11 | Pass
EXF12 | Pass
EXF13 | Pass
EXF14 | Pass
EXF15 | Pass
EXF16 | Pass
EXF17 | Pass
EXF18 | Pass
EXF19 | Failure (does nothing) [RSCPP-15792](https://youtrack.jetbrains.com/issue/RSCPP-15792)

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Pass
EM3 | Pass
EM4 | Pass
EM5 | Pass
EM6 | Pass
EM7 | Pass
EM8 | Pass
EM9 | Pass
EM10 | Pass
EM11 | Pass
EM12 | Pass
EM13 | Pass
EM14 | Pass
EM15 | Pass
EM16 | Pass
EM17 | Pass
EM18 | Pass
EM19 | Pass
EM20 | Pass

## Extract Variable
Case | Result
---- | ------
EXV1 | Pass
EXV2 | Pass
EXV3 | Pass
EXV4 | Pass
EXV5 | Pass
EXV6 | Pass

## Flatten Conditional
Case | Result
---- | ------
FC1 | Failure

## Inline Macro
Case | Result
---- | ------
IM1 | Failure (not available) [RSCPP-15900](https://youtrack.jetbrains.com/issue/RSCPP-15900)
IM2 | Pass
IM3 | Pass
IM4 | Pass
IM5 | Pass
IM6 | Pass

## Inline Variable
Case | Result
---- | ------
IV1 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV2 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV3 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV4 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV5 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV6 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV7 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV8 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV9 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV10 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV11 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)
IV12 | Failure (not available) [RSCPP-15793](https://youtrack.jetbrains.com/issue/RSCPP-15793)

## Make Method Static
Case | Result
---- | ------
MMS1 | Failure (does not update usages) [RSCPP-15794](https://youtrack.jetbrains.com/issue/RSCPP-15794)
MMS2 | Failure (does not update usages) [RSCPP-15794](https://youtrack.jetbrains.com/issue/RSCPP-15794)
MMS3 | Failure (does not update usages) [RSCPP-15794](https://youtrack.jetbrains.com/issue/RSCPP-15794)

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass
MISF2  | Pass
MISF3  | Pass
MISF4  | Pass
MISF5  | Pass
MISF6  | Pass
MISF7  | Pass
MISF8  | Pass
MISF9  | Pass
MISF10 | Pass
MISF11 | Pass
MISF12 | Pass
MISF13 | Pass
MISF14 | Pass
MISF15 | Pass
MISF16 | Pass
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Pass

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

## Remove Unused Parameter
Case | Result
---- | ------
RUP1 | Pass
RUP2 | Pass
RUP3 | Failure (does not update usages) [RSCPP-15795](https://youtrack.jetbrains.com/issue/RSCPP-15795)
RUP4 | Failure (does not update usages) [RSCPP-15795](https://youtrack.jetbrains.com/issue/RSCPP-15795)

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
R25  | Failure (unavailable) [RSCPP-15796](https://youtrack.jetbrains.com/issue/RSCPP-15796)
R26  | Pass
R27  | Pass
R28  | Pass
R29  | Pass
R30  | Pass
R31  | Pass
R32  | Failure (misses usage in typedef) [RSCPP-15797](https://youtrack.jetbrains.com/issue/RSCPP-15797)
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
R82  | Failure (unavailable) [RSCPP-15798](https://youtrack.jetbrains.com/issue/RSCPP-15798)
R83  | Failure (unavailable) [RSCPP-15798](https://youtrack.jetbrains.com/issue/RSCPP-15798)
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

## Reorder Parameters
Case | Result
---- | ------
RP1 | Failure (functionality not available)
RP2 | Failure [RSCPP-15799](https://youtrack.jetbrains.com/issue/RSCPP-15799)
RP3 | Pass
RP4 | Failure [RSCPP-15799](https://youtrack.jetbrains.com/issue/RSCPP-15799)
RP5 | Failure [RSCPP-15799](https://youtrack.jetbrains.com/issue/RSCPP-15799)
RP6 | Failure [RSCPP-15799](https://youtrack.jetbrains.com/issue/RSCPP-15799)
RP7 | Failure (functionality not available)
RP8 | Failure (functionality not available)
RP9 | Failure (functionality not available)

## Replace If With Ternary Expression
Case | Result
---- | ------
RIT1 | Pass
RIT2 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT3 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT4 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT5 | Pass
RIT6 | Pass
RIT7 | Pass (but generates odd syntax) [RSCPP-15801](https://youtrack.jetbrains.com/issue/RSCPP-15801)
RIT8 | Pass
RIT9 | Failure (generates invalid syntax) [RSCPP-15802](https://youtrack.jetbrains.com/issue/RSCPP-15802)

## Replace NULL/0 With nullptr
Case | Result
---- | ------
RZNP1 | Pass
RZNP2 | Pass
RZNP3 | Pass
RZNP4 | Pass
RZNP5 | Pass
RZNP6 | Pass
RZNP7 | Pass
RZNP8 | Pass
RZNP9 | Pass
RZNP10 | Pass
RZNP11 | Pass
RZNP12 | Pass
RZNP13 | Pass
RZNP14 | Pass
RZNP15 | Pass
RZNP16 | Pass
RZNP17 | Pass
RZNP18 | Pass
RZNP19 | Pass
RZNP20 | Pass
RZNP21 | Pass
RZNP22 | Pass
RZNP23 | Pass
RZNP24 | Pass
RZNP25 | Pass
RZNP26 | Pass
RZNP27 | Failure (not available) [RSCPP-15803](https://youtrack.jetbrains.com/issue/RSCPP-15803)
RZNP28 | Failure (not available) [RSCPP-15803](https://youtrack.jetbrains.com/issue/RSCPP-15803)

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
RTWA22 | n/a
RTWA23 | Pass
RTWA24 | n/a
RTWA25 | Pass
RTWA26 | n/a
RTWA27 | Pass
RTWA28 | Pass
RTWA29 | Pass
RTWA30 | Pass
RTWA31 | Pass
RTWA32 | Pass

## Reverse Conditional
Case | Result
---- | ------
RC1 | Pass
RC2 | Pass
RC3 | Pass
RC4 | Pass
RC5 | Pass
RC6 | Pass
RC7 | Pass
RC8 | Pass

## Split Multi-Variable Declaration
Case | Result
---- | ------
SMVD1 | Pass
SMVD2 | Pass
SMVD3 | Pass
SMVD4 | Pass
SMVD5 | Pass
SMVD6 | Failure (not available) [RSCPP-15804](https://youtrack.jetbrains.com/issue/RSCPP-15804)
SMVD7 | Pass
SMVD8 | Failure (not available) [RSCPP-15804](https://youtrack.jetbrains.com/issue/RSCPP-15804)
SMVD9 | Pass
SMVD10 | Failure (not available) [RSCPP-15804](https://youtrack.jetbrains.com/issue/RSCPP-15804)
SMVD11 | Pass
SMVD12 | Pass
SMVD13 | Pass
SMVD14 | Pass
SMVD15 | Pass
SMVD16 | Pass
SMVD17 | Pass
SMVD18 | Pass
SMVD19 | Pass
