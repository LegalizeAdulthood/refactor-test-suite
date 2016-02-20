# Visual Studio 2015

Home: [Visual Studio 2015](http://www.visualstudio.com/)

Version: Microsoft Visual Studio Community 2015, Version 14.0.24720.00 Update 1

Notes:
 * Intellisense must be enabled for most refactorings to work properly.
 * **Extract Function** and **Extract Method** were available as an
   additional free add-on, but are included in Update 1 and enabled through
   Tools / Options.
 * **Move Implementation to Source File** is available as *Move Definition
   Location*.
 * When applying an operation, the default selections on any prompting dialogs
   were used.  Unfortunately, this means that all Rename tests fail when
   Intellisense is disabled.
 * Getting the default selection correct for a refactoring is important,
   particularly when changing a name that is used in thousands of places.
   Making the developer manually resolve which identical text is actually a
   related name makes the developer act like a compiler.  The compiler already
   knows which names refer to the same thing by using the context of the names.
   Any refactoring tool worth using has to employ the same logic as the compiler
   to correctly resolve names.
 * If the correct instances of a name can't be selected by a refactoring tool,
   then you might as well use Find/Replace across a file set.

<hr/>

## Extract Function
Case | Result
---- | ------
EXF1  | Failure (data flow) [2381729](https://connect.microsoft.com/VisualStudio/feedback/details/2381729/extract-function-on-declarations-fails)
EXF2  | Pass (but can result in poor formatting) [2381666](https://connect.microsoft.com/VisualStudio/feedback/details/2381666/extract-function-when-entire-line-is-selected-results-in-poor-formatting)
EXF3  | Pass
EXF4  | Pass
EXF5  | Pass
EXF6  | Pass
EXF7  | Pass
EXF8  | Pass
EXF9  | Pass
EXF10 | Pass
EXF11 | Pass
EXF12 | Pass
EXF13 | Failure (creates invalid code) [2381686](https://connect.microsoft.com/VisualStudio/feedback/details/2381686/extract-function-on-a-statement-using-a-typedef-generates-incorrect-code)
EXF14 | Failure (creates invalid code) [2381693](https://connect.microsoft.com/VisualStudio/feedback/details/2381693/extract-function-on-a-statement-using-pointer-to-member-generates-incorrect-code)
EXF15 | Failure (creates invalid code) [2381693](https://connect.microsoft.com/VisualStudio/feedback/details/2381693/extract-function-on-a-statement-using-pointer-to-member-generates-incorrect-code)
EXF16 | Failure (creates invalid code) [2381693](https://connect.microsoft.com/VisualStudio/feedback/details/2381693/extract-function-on-a-statement-using-pointer-to-member-generates-incorrect-code)
EXF17 | Failure (creates invalid code) [2381693](https://connect.microsoft.com/VisualStudio/feedback/details/2381693/extract-function-on-a-statement-using-pointer-to-member-generates-incorrect-code)
EXF18 | Failure (data flow) [2381729](https://connect.microsoft.com/VisualStudio/feedback/details/2381729/extract-function-on-declarations-fails)
EXF19 | Failure (creates invalid code) [2381743](https://connect.microsoft.com/VisualStudio/feedback/details/2381743/extract-function-on-expression-creates-incorrect-code)

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Pass
EM3 | Pass (results in unnecessary use of namespace) [2381802](https://connect.microsoft.com/VisualStudio/feedback/details/2381802/extract-method-results-in-unnecessary-namespace-qualifier)
EM4 | Failure [2381820](https://connect.microsoft.com/VisualStudio/feedback/details/2381820/extract-method-on-statement-using-pointer-to-member-fails)
EM5 | Pass
EM6 | Failure [2381820](https://connect.microsoft.com/VisualStudio/feedback/details/2381820/extract-method-on-statement-using-pointer-to-member-fails)
EM7 | Pass
EM8 | Pass
EM9 | Pass
EM10 | Pass
EM11 | Failure (creates invalid code) [2381840](https://connect.microsoft.com/VisualStudio/feedback/details/2381840/extract-method-on-function-returning-pointer-to-const-member-function-creates-invalid-code)
EM12 | Failure [2381820](https://connect.microsoft.com/VisualStudio/feedback/details/2381820/extract-method-on-statement-using-pointer-to-member-fails)
EM13 | Pass
EM14 | Pass
EM15 | Pass
EM16 | Pass
EM17 | Failure (creates invalid code) [2381840](https://connect.microsoft.com/VisualStudio/feedback/details/2381840/extract-method-on-function-returning-pointer-to-const-member-function-creates-invalid-code)
EM18 | Pass
EM19 | Failure (data flow) [2381729](https://connect.microsoft.com/VisualStudio/feedback/details/2381729/extract-function-on-declarations-fails)
EM20 | Failure [2381854](https://connect.microsoft.com/VisualStudio/feedback/details/2381854/extract-method-on-expression-returning-pointer-to-member-fails)

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass (leaves `inline` in header) [2381887](https://connect.microsoft.com/VisualStudio/feedback/details/2381887/move-definition-location-leaves-inline-behind-in-header)
MISF2  | Failure [2381896](https://connect.microsoft.com/VisualStudio/feedback/details/2381896/move-definition-location-fails-for-constructor)
MISF3  | Pass (adds `inline` to source, sensitive to cursor placement) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation), [2381899](https://connect.microsoft.com/VisualStudio/feedback/details/2381899/move-definition-location-unavailable-if-cursor-at-on-destructor-declaration)
MISF4  | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF5  | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF6  | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF7  | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF8  | Pass
MISF9  | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF10 | Pass
MISF11 | Pass
MISF12 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF13 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF14 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF15 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF16 | Failure (adds `inline` to souce, creates invalid code) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation), [2381916](https://connect.microsoft.com/VisualStudio/feedback/details/2381916/move-definition-location-creates-invalid-code-for-method-returning-pointer-to-const-method)
MISF17 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF18 | Pass
MISF19 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF23 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF24 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF25 | Pass (adds `inline` to source) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation)
MISF26 | Failure (adds `inline` to source, creates invalid code) [2381910](https://connect.microsoft.com/VisualStudio/feedback/details/2381910/move-definition-location-adds-inline-to-implementation), [2381916](https://connect.microsoft.com/VisualStudio/feedback/details/2381916/move-definition-location-creates-invalid-code-for-method-returning-pointer-to-const-method)

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
R25  | Failure (not available) [2382058](https://connect.microsoft.com/VisualStudio/feedback/details/2382058/cant-rename-macro-argument)
R26  | Pass
R27  | Pass
R28  | Pass
R29  | Pass
R30  | Pass
R31  | Pass
R32  | Pass
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
R70  | Failure (doesn't select correct instances) [2382083](https://connect.microsoft.com/VisualStudio/feedback/details/2382083/rename-fails-to-identify-virtual-method-in-inheritance-hierarchy)
R71  | Failure (doesn't select correct instances) [2382083](https://connect.microsoft.com/VisualStudio/feedback/details/2382083/rename-fails-to-identify-virtual-method-in-inheritance-hierarchy)
R72  | Failure (doesn't select correct instances) [2382083](https://connect.microsoft.com/VisualStudio/feedback/details/2382083/rename-fails-to-identify-virtual-method-in-inheritance-hierarchy)
R73  | Failure (doesn't select correct instances) [2382083](https://connect.microsoft.com/VisualStudio/feedback/details/2382083/rename-fails-to-identify-virtual-method-in-inheritance-hierarchy)
R74  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R75  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R76  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R77  | Failure (doesn't select correct instances) [2382118](https://connect.microsoft.com/VisualStudio/feedback/details/2382118/rename-macro-from-undef-selects-wrong-instances)
R78  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R79  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R80  | Failure (doesn't select correct instances) [2382107](https://connect.microsoft.com/VisualStudio/feedback/details/2382107/rename-doesnt-select-correct-instances-of-macro)
R81  | Failure (doesn't select correct instances) [2382118](https://connect.microsoft.com/VisualStudio/feedback/details/2382118/rename-macro-from-undef-selects-wrong-instances)
R82  | Pass
R83  | Pass
R84  | Pass
R85  | Pass Pass
R86  | Pass
R87  | Pass
R88  | Failure (not available) [2382136](https://connect.microsoft.com/VisualStudio/feedback/details/2382136/cant-rename-variable-named-gcnew)
R89  | Failure (not available) [2382144](https://connect.microsoft.com/VisualStudio/feedback/details/2382144/cant-rename-variable-named-interface)
R90  | Failure (not available) [2382153](https://connect.microsoft.com/VisualStudio/feedback/details/2382153/cant-rename-variable-named-internal)
R93  | Failure (not available) [2382157](https://connect.microsoft.com/VisualStudio/feedback/details/2382157/cant-rename-variable-named-override)
R94  | Pass
R95  | Pass
R96  | Failure (not available) [2382162](https://connect.microsoft.com/VisualStudio/feedback/details/2382162/cant-rename-a-variable-named-safe-cast)
R97  | Pass
R98  | Pass

## Replace String Literal With Raw String Literal
Case | Result
---- | ------
RAW1  | Pass
RAW2  | Pass
RAW3  | Pass
RAW4  | Pass
RAW5  | Pass
RAW6  | Pass
RAW7  | Pass
RAW8  | Pass
RAW9  | Pass
RAW10 | Pass
