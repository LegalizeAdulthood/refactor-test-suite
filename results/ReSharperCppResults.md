# ReSharper for C++

Home: [ReSharper for C++](http://www.jetbrains.com/resharper-cpp/)

Version: JetBrains ReSharper 2023.3.2
Build 233.0.20231218.91950 built on 2023-12-18

Notes:
* `clang-tidy` is integrated with ReSharper for C++ and provides quick fixes for issues found by clang-tidy.
  Only results implemented directly by ReSharper for C++ are reported here.
* **Add Block Delimiter** is available as the quick fix *Surround with block*.
  The tests pass if only code is selected and not the surrounding comment lines.
* **Add Override** is available as the quick fix *Add 'override' specifier to an overriding function*.
* **Add Parameter** is available through **Change Signature**.
  Default file selections were accepted and the argument value of zero was chosen.
* **Create Method Stub** is available as the quick fix *Create member function*,
  *Create constructor* or *Create global function* followed by the quick fix
  *Generate inline implementation of function*.
* **Create Multi-Variable Declaration** is available by selecting the multiple declarations and
  applying the quick fix *Join declarations*.
* **Flatten Conditional** is available as the quick fix *Merge nested 'if' statements*.
* **Inline Macro** is available as the quick fix *Substitute macro call*.
* **Inline Type Alias** is available as the quick fix *Substitute type alias* or *Substitute typedef*.
* **Make Method Static** is available as a quick fix.
* **Move Implementation to Source File** is available as the quick fix *Move definition to source file* or
  *Move definition out of class scope*.
* **Remove Block Delimiter** is available as the quick fix *Remove braces*.
* **Remove Unused Parameter** is available as a quick fix.
* **Reorder Parameters** is available through **Change Signature**.
* **Replace auto With Type** is available as the quick fix *Specify type explicitly*.
* **Replace If With Ternary** is available as the quick fix *Convert 'if' to '?:'*.
* **Replace NULL/0 With nullptr** is available as the quick fix *Replace expression with 'nullptr'*.
* **Replace String Literal With Raw String Literal** is available as the quick fix *Convert to raw string literal*.
* **Replace Ternary With If** is available as the quick fix *Convert '?:' to 'if'*.
* **Replace typedef With Type Alias** is available as the quick fix *Replace with a type alias*.
* **Replace Type WIth Auto** is available as the quick fix *Use 'auto'*.
* **Reverse Conditional** is available as the quick fix *Invert 'if' statement*.
* **Split Initialization From Declaration** is available as the quick fix *Split declaration and assignment*.
* **Split Multi-Variable Declaration** is available as the quick fix *Split declaration*.

<hr/>

## Add Block Delimiter
Case | Result
---- | ------
ABD1 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD2 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD3 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD4 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD5 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD6 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)
ABD7 | Failure (unavailable) [RSCPP-15789](https://youtrack.jetbrains.com/issue/RSCPP-15789)

## Add Override
Case | Result
---- | ------
AO1  | Pass
AO2  | Pass
AO3  | Pass
AO4  | Pass
AO5  | Pass
AO6  | Pass
AO7  | Pass
AO8  | Pass
AO9  | Pass
AO10 | Pass
AO11 | Pass
AO12 | Pass 
AO13 | Pass
AO14 | Pass
AO15 | Pass
AO16 | Pass

## Add Parameter
Case | Result
---- | ------
AP1  | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP2  | Pass
AP3  | Pass
AP4  | Pass
AP5  | Pass
AP6  | Pass
AP7  | Pass
AP8  | Pass
AP9  | Pass
AP10 | Pass
AP11 | Pass
AP12 | Pass
AP13 | Pass
AP14 | Pass
AP15 | Pass
AP16 | Pass
AP17 | Pass
AP18 | Pass
AP19 | Pass
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Failure (doesn't update other template arguments) [RSCPP-21202](https://youtrack.jetbrains.com/issue/RSCPP-21202/Adding-a-parameter-with-Change-Signature-doesnt-follow-template-usages-and-change-all-methods-accordingly)
AP25 | Failure (unavailable) [RSCPP-35262](https://youtrack.jetbrains.com/issue/RSCPP-35262/Change-Signature-unavailable-on-call-site-in-template-function)
AP26 | Failure (doesn't update other template arguments) [RSCPP-21202](https://youtrack.jetbrains.com/issue/RSCPP-21202/Adding-a-parameter-with-Change-Signature-doesnt-follow-template-usages-and-change-all-methods-accordingly)
AP27 | Pass
AP28 | Pass
AP29 | Pass
AP30 | Pass
AP31 | Pass
AP32 | Pass
AP33 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP34 | Pass
AP35 | Pass
AP36 | Pass
AP37 | Pass
AP38 | Pass
AP39 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP40 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP41 | Pass
AP42 | Pass
AP43 | Pass
AP44 | Pass
AP45 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP46 | Pass
AP47 | Pass
AP48 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP49 | Pass
AP50 | Pass
AP51 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP52 | Pass
AP53 | Pass
AP54 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP55 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP56 | Pass
AP57 | Pass
AP58 | Pass
AP59 | Pass
AP60 | Pass
AP61 | Pass
AP62 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP63 | Pass
AP64 | Pass
AP65 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP66 | Pass
AP67 | Pass
AP68 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP69 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP70 | Pass
AP71 | Pass
AP72 | Pass
AP73 | Pass
AP74 | Pass
AP75 | Pass
AP76 | Pass
AP77 | Pass
AP78 | Pass
AP79 | Pass
AP80 | Pass
AP81 | Pass
AP82 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP83 | Pass
AP84 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP85 | Pass
AP86 | Pass
AP87 | Pass
AP88 | Pass
AP89 | Pass
AP90 | Pass
AP91 | Pass
AP92 | Pass
AP93 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP94 | Pass
AP95 | Pass
AP96 | Pass
AP97 | Pass
AP98 | Pass
AP99 | Pass
AP100 | Pass
AP101 | Pass
AP102 | Pass
AP103 | Pass
AP104 | Pass
AP105 | Pass
AP106 | Pass
AP107 | Pass
AP108 | Pass
AP109 | Pass
AP110 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP111 | Pass
AP112 | Pass
AP113 | Pass
AP114 | Pass
AP115 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP116 | Pass
AP117 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP118 | Pass
AP119 | Pass
AP120 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP121 | Pass
AP122 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP123 | Pass
AP124 | Pass
AP125 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP126 | Pass
AP127 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP128 | Pass
AP129 | Pass
AP130 | Pass
AP131 | Pass
AP132 | Pass
AP133 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP134 | Pass
AP135 | Pass
AP136 | Pass
AP137 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP138 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP139 | Pass
AP140 | Pass
AP141 | Failure (not available) [RSCPP-12542](https://youtrack.jetbrains.com/issue/RSCPP-12542/Change-signature-doesnt-work-for-constructors)
AP142 | Pass
AP143 | Pass
AP144 | Pass
AP145 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP146 | Pass
AP147 | Pass
AP148 | Failure (creates invalid code) [RSCPP-35261](https://youtrack.jetbrains.com/issue/RSCPP-35261/Change-Signature-cant-add-parameters-with-default-values)
AP149 | Pass
AP150 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP151 | Pass
AP152 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP153 | Pass
AP154 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP155 | Pass
AP156 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP157 | Pass
AP158 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP159 | Pass
AP160 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP161 | Pass
AP162 | Pass
AP163 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP164 | Pass
AP165 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP166 | Pass
AP167 | Failure (creates invalid code) [RSCPP-35031](https://youtrack.jetbrains.com/issue/RSCPP-35031/Invalid-code-in-macro-call-after-change-signature)
AP168 | Pass
AP169 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP170 | Pass
AP171 | Pass
AP172 | Pass
AP173 | Pass
AP174 | Pass
AP175 | Pass
AP176 | Pass
AP177 | Pass
AP178 | Pass
AP179 | Pass
AP180 | Failure (modifies unrelated code) [RSCPP-35259](https://youtrack.jetbrains.com/issue/RSCPP-35259/Change-Signature-modifies-unrelated-template-usage)
AP181 | Pass
AP182 | Pass
AP183 | Pass
AP184 | Pass
AP185 | Pass
AP186 | Pass
AP187 | Pass
AP188 | Pass
AP189 | Pass
AP190 | Pass
AP191 | Pass
AP192 | Pass
AP193 | Pass
AP194 | Pass
AP195 | Pass
AP196 | Pass
AP197 | Pass
AP198 | Pass
AP199 | Pass
AP200 | Pass
AP201 | Pass
AP202 | Pass

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
CS12 | Pass
CS13 | Pass
CS14 | Pass
CS15 | Pass
CS16 | Pass
CS17 | Pass
CS18 | Pass
CS19 | Pass
CS20 | Pass
CS21 | Pass
CS22 | Pass
CS23 | Pass
CS24 | Pass
CS25 | Pass
CS26 | Pass
CS27 | Pass
CS28 | Pass
CS29 | Pass
CS30 | Pass
CS31 | Pass
CS32 | Pass
CS33 | Pass
CS34 | Pass
CS35 | Pass
CS36 | Pass
CS37 | Pass
CS38 | Pass
CS39 | Pass
CS40 | Pass
CS41 | Pass
CS42 | Pass
CS43 | Pass
CS44 | Pass
CS45 | Pass

## Create Method Stub
Case | Result
---- | ------
CMS1  | Pass
CMS2  | Pass
CMS3  | Pass
CMS4  | Failure (does not build) [RSCPP-21496](https://youtrack.jetbrains.com/issue/RSCPP-21496)
CMS5  | Failure (does not build) [RSCPP-21496](https://youtrack.jetbrains.com/issue/RSCPP-21496)
CMS6  | Pass
CMS7  | Pass
CMS8  | Pass
CMS9  | Pass
CMS10 | Pass
CMS11 | Pass
CMS12 | Pass
CMS13 | Pass
CMS14 | Failure (does not build) [RSCPP-35263](https://youtrack.jetbrains.com/issue/RSCPP-35263/Create-member-function-generates-code-with-incorrect-visibility)
CMS15 | Pass
CMS16 | Pass
CMS17 | Pass
CMS18 | Pass
CMS19 | Pass
CMS20 | Pass
CMS21 | Pass
CMS22 | Pass

## Create Multi-Variable Declaration
Case | Result
---- | ------
CMVD1  | Pass
CMVD2  | Pass
CMVD3  | Pass
CMVD4  | Pass
CMVD5  | Pass
CMVD6  | Failure [RSCPP-15791](https://youtrack.jetbrains.com/issue/RSCPP-15791/CMVD-Joining-delcarations-is-confused-by-class-struct-union-keywords)
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
EXF19 | Pass

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
EM21 | Pass

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
IM7 | Pass

## Inline Type Alias
Case | Result
---- | ------
ITA1 | Pass
ITA2 | Pass
ITA3 | Pass
ITA4 | Pass
ITA5 | Pass
ITA6 | Pass
ITA7 | Pass
ITA8 | Pass
ITA9 | Pass
ITA10 | Pass
ITA11 | Pass
ITA12 | Pass
ITA13 | Pass

## Inline Variable
Case | Result
---- | ------
IV1  | Pass
IV2  | Pass
IV3  | Pass
IV4  | Pass (leaves behind syntactical noise, doesn't inline all occurrences) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205), [RSCPP-21204](https://youtrack.jetbrains.com/issue/RSCPP-21204)
IV5  | Pass (leaves behind syntactical noise, doesn't inline all occurrences) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205), [RSCPP-21204](https://youtrack.jetbrains.com/issue/RSCPP-21204)
IV6  | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV7  | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV8  | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV9  | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV10 | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV11 | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
IV12 | Pass

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

## Remove Unused Includes
Case | Result
---- | ------
RUI1 | Pass

## Remove Unused Parameter
Case | Result
---- | ------
RUP1 | Pass
RUP2 | Pass
RUP3 | Failure (claims errors in the source) [RSCPP-21207](https://youtrack.jetbrains.com/issue/RSCPP-21207)
RUP4 | Failure (creates invalid syntax in macro arguments) [RSCPP-21208](https://youtrack.jetbrains.com/issue/RSCPP-21208)

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
R91  | (deprecated)
R92  | (deprecated)
R93  | Pass
R94  | Pass
R95  | Pass
R96  | Pass
R97  | Pass
R98  | Pass
R99  | Failure (unavailable) [RSCPP-15796](https://youtrack.jetbrains.com/issue/RSCPP-15796)
R100 | Pass
R101 | Pass
R102 | Pass
R103 | Pass
R104 | Pass
R105 | Pass
R106 | Pass
R107 | Pass
R108 | Pass
R109 | Pass
R110 | Pass
R111 | Pass
R112 | Pass
R113 | Pass
R114 | Pass
R115 | Pass
R116 | Pass
R117 | Pass
R118 | Pass
R119 | Pass
R120 | Pass
R121 | Pass
R122 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R123 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R124 | Pass
R125 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R126 | Pass
R127 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R128 | Pass
R129 | Pass
R130 | Pass
R131 | Pass
R132 | Pass
R133 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R134 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R135 | Pass
R136 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R137 | Pass
R138 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R139 | Pass
R140 | Pass
R141 | Pass
R142 | Pass
R143 | Pass
R144 | Pass
R145 | Pass
R146 | Pass
R147 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R148 | Pass
R149 | Pass
R150 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R151 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R152 | Pass
R153 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R154 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R155 | Failure (doesn't select all usages) [RSCPP-13845](https://youtrack.jetbrains.com/issue/RSCPP-13845)
R156 | Pass
R157 | Pass
R158 | Pass
R159 | Pass
R160 | Pass
R161 | Pass
R162 | Pass
R163 | Pass
R164 | Pass
R165 | Pass
R166 | Pass
R167 | Pass
R168 | Pass
R169 | Pass
R170 | Pass
R171 | Pass
R172 | Pass
R173 | Pass
R174 | Pass
R175 | Pass
R176 | Pass
R177 | Pass
R178 | Pass
R179 | Pass
R180 | Pass
R181 | Pass
R182 | Pass
R183 | Pass
R184 | Pass
R185 | Pass
R186 | Pass
R187 | Pass
R188 | Pass
R189 | Pass
R190 | Pass
R191 | Pass
R192 | Pass
R193 | Pass
R194 | Pass
R195 | Pass
R196 | Pass
R197 | Pass
R198 | Pass
R199 | Pass
R200 | Pass
R201 | Pass
R202 | Pass
R203 | Pass
R204 | Pass
R205 | Pass
R206 | Pass
R207 | Pass
R208 | Pass
R209 | Pass
R210 | Pass
R211 | Pass
R212 | Pass
R213 | Pass
R214 | Pass
R215 | Pass
R216 | Pass
R217 | Pass
R218 | Pass
R219 | Pass
R220 | Pass
R221 | Pass
R222 | Pass
R223 | Pass
R224 | Pass
R225 | Pass
R226 | Pass
R227 | Pass
R228 | Pass
R229 | Pass
R230 | Pass
R231 | Pass
R232 | Pass
R233 | Pass
R234 | Pass
R235 | Pass
R236 | Pass
R237 | Pass
R238 | Pass
R239 | Pass
R240 | Pass
R241 | Pass
R242 | Pass
R243 | Pass
R244 | Pass
R245 | Pass
R246 | Pass
R247 | Pass
R248 | Pass
R249 | Pass
R250 | Pass
R251 | Pass
R252 | Pass
R253 | Pass
R254 | Pass
R255 | Pass
R256 | Pass
R257 | Pass
R258 | Pass
R259 | Pass
R260 | Pass
R261 | Pass
R262 | Pass
R263 | Pass
R264 | Pass
R265 | Pass
R266 | Pass
R267 | Pass
R268 | Pass
R269 | Pass
R270 | Pass
R271 | Pass
R272 | Pass
R273 | Pass
R274 | Pass
R275 | Pass
R276 | Pass
R277 | Pass
R278 | Pass
R279 | Pass
R280 | Pass
R281 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R282 | Pass
R283 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R284 | Pass
R285 | Pass (moves cursor location) [RSCPP-21198](https://youtrack.jetbrains.com/issue/RSCPP-21198)
R286 | Pass
R287 | Pass
R288 | Pass
R289 | Pass
R290 | Pass
R291 | Pass
R292 | Pass
R293 | Pass
R294 | Pass
R295 | Pass
R296 | Pass
R297 | Pass
R298 | Pass
R299 | Pass
R300 | Pass
R301 | Pass
R302 | Pass
R303 | Pass
R304 | Pass
R305 | Pass
R306 | Pass
R307 | Pass
R308 | Pass
R309 | Pass
R310 | Pass
R311 | Pass
R312 | Pass
R313 | Pass
R314 | Pass
R315 | Pass
R316 | Pass
R317 | Pass
R318 | Pass
R319 | Pass
R320 | Pass
R321 | Pass
R322 | Pass
R323 | Pass
R324 | Pass
R325 | Pass
R326 | Pass
R327 | Pass
R328 | Pass
R329 | Pass
R330 | Pass
R331 | Pass
R332 | Pass
R333 | Pass
R334 | Pass
R335 | Pass
R336 | Pass
R337 | Pass
R338 | Pass
R339 | Pass
R340 | Pass
R341 | Pass
R342 | Pass
R343 | Pass
R344 | Pass
R345 | Pass
R346 | Pass
R347 | Pass
R348 | Pass
R349 | Pass
R350 | Pass
R351 | Pass
R352 | Pass
R353 | Pass
R354 | Pass
R355 | Pass
R356 | Pass
R357 | Pass
R358 | Pass
R359 | Pass
R360 | Pass
R361 | Pass
R362 | Pass
R363 | Pass
R364 | Pass
R365 | Pass
R366 | Pass
R367 | Pass
R368 | Pass
R369 | Pass
R370 | Pass
R371 | Pass
R372 | Pass
R373 | Pass
R374 | Pass
R375 | Pass
R376 | Pass
R377 | Pass
R378 | Pass
R379 | Pass
R380 | Pass
R381 | Pass
R382 | Pass
R383 | Pass
R384 | Pass
R385 | Pass
R386 | Pass
R387 | Pass
R388 | Pass
R389 | Pass
R390 | Pass
R391 | Pass
R392 | Pass
R393 | Pass
R394 | Pass
R395 | Pass
R396 | Pass
R397 | Pass
R398 | Pass
R399 | Pass
R400 | Pass
R401 | Pass
R402 | Pass
R403 | Pass
R404 | Pass
R405 | Pass
R406 | Pass
R407 | Pass
R408 | Pass
R409 | Pass
R410 | Pass
R411 | Pass
R412 | Pass
R413 | Pass
R414 | Pass
R415 | Pass
R416 | Pass
R417 | Pass
R418 | Pass
R419 | Pass
R420 | Pass
R421 | Pass
R422 | Pass
R423 | Pass
R424 | Pass
R425 | Pass
R426 | Pass
R427 | Pass
R428 | Pass
R429 | Pass
R430 | Pass
R431 | Pass
R432 | Pass
R433 | Pass
R434 | Pass
R435 | Pass
R436 | Pass
R437 | Pass
R438 | Pass
R439 | Pass
R440 | Pass
R441 | Pass
R442 | Pass
R443 | Pass
R444 | Pass
R445 | Pass
R446 | Pass
R447 | Pass
R448 | Pass
R449 | Pass
R450 | Pass
R451 | Pass
R452 | Pass
R453 | Pass
R454 | Pass
R455 | Pass
R456 | Pass
R457 | Pass
R458 | Pass
R459 | Pass
R460 | Pass
R461 | Pass
R462 | Pass
R463 | Pass
R464 | Pass
R465 | Pass
R466 | Pass
R467 | Pass
R468 | Pass
R469 | Pass
R470 | Pass
R471 | Pass
R472 | Pass
R473 | Pass
R474 | Pass
R475 | Pass
R476 | Pass
R477 | Pass
R478 | Pass
R479 | Pass
R480 | Pass
R481 | Pass
R482 | Pass
R483 | Pass
R484 | Pass
R485 | Pass
R486 | Pass
R487 | Pass
R488 | Pass
R489 | Pass
R490 | Pass
R491 | Pass
R492 | Pass
R493 | Pass
R494 | Pass
R495 | Pass
R496 | Pass
R497 | Pass
R498 | Pass
R499 | Pass
R500 | Pass
R501 | Pass
R502 | Pass
R503 | Pass
R504 | Pass
R505 | Pass
R506 | Pass
R507 | Pass
R508 | Pass
R509 | Pass
R510 | Pass
R511 | Pass
R512 | Pass
R513 | Pass
R514 | Pass
R515 | Failure (unavailable) [RSCPP-21422](https://youtrack.jetbrains.com/issue/RSCPP-21422)
R516 | Pass
R517 | Pass
R518 | Pass
R519 | Pass
R520 | Pass
R521 | Pass
R522 | Pass
R523 | Pass
R524 | Pass
R525 | Pass
R526 | Pass
R527 | Pass
R528 | Pass
R529 | Pass
R530 | Pass
R531 | Pass
R532 | Pass
R533 | Pass
R534 | Pass
R535 | Pass
R536 | Pass
R537 | Pass
R538 | Pass
R539 | Pass
R540 | Pass
R541 | Pass
R542 | Pass
R543 | Pass
R544 | Pass
R545 | Pass
R546 | Pass
R547 | Pass
R548 | Pass
R549 | Pass
R550 | Pass
R551 | Pass
R552 | Pass
R553 | Pass
R554 | Pass
R555 | Pass
R556 | Pass
R557 | Pass
R558 | Pass
R559 | Pass
R560 | Pass
R561 | Pass
R562 | (deprecated)
R563 | Pass
R564 | Pass
R565 | Pass
R566 | Pass
R567 | Pass
R568 | Pass
R569 | Pass
R570 | Pass
R571 | Pass
R572 | Pass
R573 | Pass
R574 | Pass
R575 | Pass
R576 | Pass
R577 | Pass
R578 | Pass
R579 | Pass
R580 | Pass
R581 | Pass
R582 | Pass
R583 | Pass
R584 | Pass
R585 | Pass
R586 | Pass
R587 | Pass
R588 | Pass
R589 | Pass
R590 | Pass
R591 | Pass
R592 | Pass
R593 | Pass
R594 | Pass
R595 | Pass
R596 | Pass
R597 | Pass
R598 | Pass
R599 | Pass
R600 | Pass
R601 | Pass
R602 | Pass
R603 | Pass
R604 | Pass
R605 | Pass
R606 | 
R607 | 
R608 | 
R609 | 
R610 | 
R611 | 
R612 | 
R613 | 
R614 | 
R615 | 
R616 | 
R617 | 
R618 | 
R619 | 
R620 | 
R621 | 
R622 | 
R623 | 
R624 | 
R625 | 
R626 | 
R627 | 
R628 | 
R629 | 
R630 | 
R631 | 
R632 | 
R633 | 
R634 | 
R635 | 
R636 | 
R637 | 
R638 | 
R639 | 
R640 | 
R641 | 
R642 | 
R643 | 
R644 | 
R645 | 
R646 | 
R647 | 
R648 | 
R649 | 
R650 | 
R651 | 
R652 | 
R653 | 
R654 | 
R655 | 
R656 | 
R657 | 
R658 | 
R659 | 
R660 | 
R661 | 
R662 | 
R663 | 
R664 | 
R665 | 
R666 | 
R667 | 
R668 | 
R669 | 
R670 | 
R671 | 
R672 | 
R673 | 
R674 | 
R675 | 
R676 | 
R677 | 
R678 | 
R679 | 
R680 | 
R681 | 
R682 | 
R683 | 
R684 | 
R685 | 
R686 | 
R687 | 
R688 | 
R689 | 
R690 | 
R691 | 
R692 | 
R693 | 
R694 | 
R695 | 
R696 | 
R697 | 
R698 | 
R699 | 
R700 | 
R701 | 
R702 | 
R703 | 
R704 | 
R705 | 
R706 | 
R707 | 
R708 | 
R709 | 
R710 | 
R711 | 
R712 | 
R713 | 
R714 | 
R715 | 
R716 | 
R717 | 
R718 | 
R719 | 
R720 | 
R721 | 
R722 | 
R723 | 
R724 | 
R725 | 
R726 | 
R727 | 
R728 | 
R729 | 
R730 | 
R731 | 
R732 | 
R733 | 
R734 | 
R735 | 
R736 | 
R737 | 
R738 | 
R739 | 
R740 | 
R741 | 
R742 | 
R743 | 
R744 | 
R745 | 
R746 | 
R747 | 
R748 | 
R749 | 
R750 | 
R751 | 
R752 | 
R753 | 
R754 | 
R755 | 
R756 | 
R757 | 
R758 | 
R759 | 
R760 | 
R761 | 
R762 | 
R763 | 
R764 | 
R765 | 
R766 | 
R767 | 
R768 | 
R769 | 
R770 | 
R771 | 
R772 | 
R773 | 
R774 | 
R775 | 
R776 | 
R777 | 
R778 | 
R779 | 
R780 | 
R781 | 
R782 | 
R783 | 
R784 | 
R785 | 
R786 | 
R787 | 
R788 | 
R789 | 
R790 | 
R791 | 
R792 | 
R793 | 
R794 | 
R795 | 
R796 | 
R797 | 
R798 | 
R799 | 
R800 | 
R801 | 
R802 | 
R803 | 
R804 | 
R805 | 
R806 | 
R807 | 
R808 | 
R809 | 
R810 | 
R811 | 
R812 | 
R813 | 
R814 | 
R815 | 
R816 | 
R817 | 
R818 | 
R819 | 
R820 | 
R821 | 
R822 | 
R823 | 
R824 | 
R825 | 
R826 | 
R827 | 
R828 | 
R829 | 
R830 | 
R831 | 
R832 | 
R833 | 
R834 | 
R835 | 
R836 | 
R837 | 
R838 | 
R839 | 
R840 | 
R841 | 
R842 | 
R843 | 
R844 | 
R845 | 
R846 | 
R847 | 
R848 | 
R849 | 
R850 | 
R851 | 
R852 | 
R853 | 
R854 | 
R855 | 
R856 | 
R857 | 
R858 | 
R859 | 
R860 | 
R861 | 
R862 | 
R863 | 
R864 | 
R865 | 
R866 | 
R867 | 
R868 | 
R869 | 
R870 | 
R871 | 
R872 | 
R873 | 
R874 | 
R875 | 
R876 | 
R877 | 
R878 | 
R879 | 
R880 | 
R881 | 
R882 | 
R883 | 
R884 | 
R885 | 
R886 | 
R887 | 
R888 | 
R889 | 
R890 | 
R891 | 
R892 | 
R893 | 
R894 | 
R895 | 
R896 | 
R897 | 
R898 | 
R899 | 
R900 | 
R901 | 
R902 | 
R903 | 
R904 | 
R905 | 
R906 | 
R907 | 
R908 | 
R909 | 
R910 | 
R911 | 
R912 | 
R913 | 
R914 | 
R915 | 
R916 | 
R917 | 
R918 | 
R919 | 
R920 | 
R921 | 
R922 | 
R923 | 
R924 | 
R925 | 
R926 | 
R927 | 
R928 | 
R929 | 
R930 | 
R931 | 
R932 | 
R933 | 
R934 | 
R935 | 
R936 | 
R937 | 
R938 | 
R939 | 
R940 | 
R941 | 
R942 | 
R943 | 
R944 | 
R945 | 
R946 | 
R947 | 
R948 | 
R949 | 
R950 | 
R951 | 
R952 | 
R953 | 
R954 | 
R955 | 
R956 | 
R957 | 
R958 | 
R959 | 
R960 | 
R961 | 
R962 | 
R963 | 
R964 | 
R965 | 
R966 | 
R967 | 
R968 | 
R969 | 
R970 | 
R971 | 
R972 | 
R973 | 
R974 | 
R975 | 
R976 | 
R977 | 
R978 | 
R979 | 
R980 | 
R981 | 
R982 | 
R983 | 
R984 | 
R985 | 
R986 | 

## Reorder Parameters
Case | Result
---- | ------
RP1 | (deprecated)
RP2 | Failure (creates invalid code in macro argument) [RSCPP-21210](https://youtrack.jetbrains.com/issue/RSCPP-21210)
RP3 | Pass
RP4 | Failure (unable to update usage) [RSCPP-21211](https://youtrack.jetbrains.com/issue/RSCPP-21211)
RP5 | Failure (creates invalid code in macro argument) [RSCPP-21210](https://youtrack.jetbrains.com/issue/RSCPP-21210)
RP6 | Failure (unable to update usage) [RSCPP-21211](https://youtrack.jetbrains.com/issue/RSCPP-21211)
RP7 | (deprecated)
RP8 | (deprecated)
RP9 | (deprecated)

## Replace auto With Type
Case | Result
---- | ------
RAWT1 | 
RAWT2 | 
RAWT3 | 
RAWT4 | 
RAWT5 | 
RAWT6 | 
RAWT7 | 
RAWT8 | 
RAWT9 | 
RAWT10 | 
RAWT11 | 
RAWT12 | 
RAWT13 | 
RAWT14 | 
RAWT15 | 
RAWT16 | 
RAWT17 | 
RAWT18 | 
RAWT19 | 
RAWT20 | 
RAWT21 | 
RAWT22 | 
RAWT23 | 
RAWT24 | 
RAWT25 | 
RAWT26 | 
RAWT27 | 
RAWT28 | 
RAWT29 | 
RAWT30 | 

## Replace If With Ternary
Case | Result
---- | ------
RIT1 | Pass
RIT2 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT3 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT4 | Failure (not available) [RSCPP-15800](https://youtrack.jetbrains.com/issue/RSCPP-15800)
RIT5 | Pass
RIT6 | Pass
RIT7 | Pass
RIT8 | Pass
RIT9 | Pass

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
RZNP27 | Pass
RZNP28 | Pass

## Replace String Literal With Raw String Literal
Case | Result
---- | ------
RAW1 | 
RAW2 | 
RAW3 | 
RAW4 | 
RAW5 | 
RAW6 | 
RAW7 | 
RAW8 | 
RAW9 | 
RAW10 | 

## Replace Ternary With If
Case | Result
---- | ------
RTI1 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI2 | Pass
RTI3 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI4 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI5 | Pass
RTI6 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI7 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI8 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI9 | Failure (not available) [RSCPP-16133](https://youtrack.jetbrains.com/issue/RSCPP-16133)
RTI10 | Pass
RTI11 | Pass

## Replace typedef With Type Alias
Case | Result
---- | ------
RTDTA1 | 
RTDTA2 | 
RTDTA3 | 
RTDTA4 | 
RTDTA5 | 
RTDTA6 | 
RTDTA7 | 

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

## Split Initialization From Declaration
Case | Result
---- | ------
SID1 | 
SID2 | 
SID3 | 
SID4 | 
SID5 | 
SID6 | 
SID7 | 
SID8 | 
SID9 | 
SID10 | 
SID11 | 

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
