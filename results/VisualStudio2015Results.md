# Visual AssistX

Home: [Visual Studio 2015](http://www.visualstudio.com/)

Version: 14.0.23107.0 D14REL

Notes:

When applying an operation, the default selections on any prompting dialogs
were used.  Unfortunately, this means that almost all Rename tests fail.

Getting the default selection correct for a refactoring is important,
particularly when changing a name that is used in thousands of places.
Making the developer manually resolve which identical text is actually a
related name makes the developer act like a compiler.  The compiler already
knows which names refer to the same thing by using the context of the names.
Any refactoring tool worth using has to employ the same logic as the compiler
to correctly resolve names.

<hr/>

## Change Signature

## Create Declaration From Implementation

## Create Implementation From Declaration

## Create Method Stub

## Extract Function

## Extract Method
Case | Result
---- | ------
EM1 | Failure (not available)
EM2 | Failure (not available)
EM3 | Failure (not available)
EM4 | Failure (not available)
EM5 | Failure (not available)
EM6 | Failure (not available)
EM7 | Failure (not available)
EM8 | Failure (not available)
EM9 | Failure (not available)
EM10 | Failure (not available)
EM11 | Failure (not available)
EM12 | Failure (not available)
EM13 | Failure (not available)
EM14 | Failure (not available)
EM15 | Failure (not available)
EM16 | Failure (not available)
EM17 | Failure (not available)
EM18 | Failure (not available)
EM19 | Failure (not available)
EM20 | Failure (not available)

## Move Method to Header/Source

## Rename
Case | Result
---- | ------
R1   | Failure (no instances selected by default)
R2   | Failure (no instances selected by default)
R3   | Failure (no instances selected by default)
R4   | Failure (no instances selected by default)
R5   | Failure (no instances selected by default)
R6   | Failure (no instances selected by default)
R7   | Failure (no instances selected by default)
R8   | Failure (no instances selected by default)
R9   | Failure (no instances selected by default)
R10  | Failure (no instances selected by default)
R11  | Failure (not available)
R12  | Failure (no instances selected by default)
R13  | Failure (no instances selected by default)
R14  | Failure (no instances selected by default)
R15  | Failure (no instances selected by default)
R16  | Failure (not available)
R17  | Failure (no instances selected by default)
R18  | Failure (not available)
R19  | Failure (no instances selected by default)
R20  | Failure (no instances selected by default)
R21  | Failure (no instances selected by default)
R22  | Failure (no instances selected by default)
R23  | Failure (no instances selected by default)
R24  | Failure (no instances selected by default)
R25  | Failure (not available)
R26  | Failure (no instances selected by default)
R27  | Failure (no instances selected by default)
R28  | Failure (no instances selected by default)
R29  | Failure (no instances selected by default)
R30  | Failure (no instances selected by default)
R31  | Failure (no instances selected by default)
R32  | Failure (no instances selected by default)
R33  | Failure (no instances selected by default)
R34  | Failure (no instances selected by default)
R35  | Failure (no instances selected by default)
R36  | Failure (no instances selected by default)
R37  | Failure (no instances selected by default)
R38  | Failure (no instances selected by default)
R39  | Failure (no instances selected by default)
R40  | Failure (no instances selected by default)
R41  | Failure (not available)
R42  | Failure (no instances selected by default)
R43  | Failure (no instances selected by default)
R44  | Failure (no instances selected by default)
R45  | Failure (not available)
R46  | Failure (no instances selected by default)
R47  | Failure (no instances selected by default)
R48  | Failure (no instances selected by default)
R49  | Failure (no instances selected by default)
R50  | Failure (no instances selected by default)
R51  | Failure (no instances selected by default)
R52  | Failure (no instances selected by default)
R53  | Failure (no instances selected by default)
R54  | Failure (no instances selected by default)
R55  | Failure (no instances selected by default)
R56  | Failure (no instances selected by default)
R57  | Failure (no instances selected by default)
R58  | Failure (no instances selected by default)
R59  | Failure (no instances selected by default)
R60  | Failure (not available)
R61  | Failure (not available)
R62  | Failure (no instances selected by default)
R63  | Failure (not available)
R64  | Failure (not available)
R65  | Failure (no instances selected by default)
R66  | Failure (not available)
R67  | Failure (not available)
R68  | Failure (not available)
R69  | Failure (no instances selected by default)
R70  | Failure (no instances selected by default)
R71  | Failure (no instances selected by default)
R72  | Failure (no instances selected by default)
R73  | Failure (no instances selected by default)
R74  | Failure (wrong symbol selected by default)
R75  | Failure (wrong symbol selected by default)
R76  | Failure (wrong symbol selected by default)
R77  | Failure (wrong symbol selected by default)
R78  | Failure (wrong symbol selected by default)
R79  | Failure (wrong symbol selected by default)
R80  | Failure (wrong symbol selected by default)
R81  | Failure (wrong symbol selected by default)
R82  | Failure (not available)
R83  | Failure (not available)
R84  | Failure (not available)
R85  | Failure (wrong symbol selected by default; correct symbol not an option)
R86  | Failure (not available)
R87  | Failure (no instances selected by default)
R88  | Failure (not available)
R89  | Failure (not available)
R90  | Failure (not available)
R93  | Failure (not available)
R94  | Failure (not available)
R95  | Failure (not available)
R96  | Failure (not available)
R97  | Failure (not available)
R98  | Failure (wrong symbol selected by default)

## Replace String Literal with Raw String Literal
Case | Result
---- | ------
RAW1 | Pass
RAW2 | Pass
RAW3 | Pass
RAW4 | Pass
RAW5 | Pass
RAW6 | Pass
RAW7 | Pass
RAW8 | Pass
