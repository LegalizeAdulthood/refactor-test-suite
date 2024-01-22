# CLion

Home: [CLion](https://www.jetbrains.com/clion/)

Version: 2023.3.2

Notes:

* Methodology:
  * Default suggestions are selected when refactoring.
  * Some refactorings can be performed successfully if suggestions are excluded.
  * If a refactoring is performed via clang-tidy those results are omitted.
* **Add Block Delimiter** is performed by placing the cursor on the enclosing
  control statement and applying the action *Add braces to '...' statement*.
* **Add Override** can be performed through clang-tidy integration.
* **Add Parameter** is performed with **Change Signature**.
* **Create Setter Method** is performed with *Code / Generate... / Setter* on the enclosing class.
* **Flatten Conditional** is performed by repeatedly applying the action
  *Merge Nested Ifs*.
* **Inline Macro** is performed by applying the action *Substitue macro once*.
* **Make Method Static** is available through clang-tidy integration.
* **Remove Block Delimiter** is performed by applying the action
  *Remove braces from '...' statement*.
* For **Rename** only code usages were renamed, if prompted.
* **Reorder Parameters** is performed with **Change Signature**.
* **Replace If With Ternary** is performed by applying the action
  *Replace 'if else' with '?:'*.
* **Replace Ternary With If** is performed by applying the action
  *Replace '?;' with 'if else'*.
* **Replace Type With auto** is performed by applying the action
  *Replace the type with 'auto'*.
* **Reverse Conditional** is performed by applying the action
  *Invert 'if' condition*.
* **Simplify Boolean Expression** is performed by applying the action
  *Simplify expression*.
* **Split Initialization From Declaration** is performed by applying the action
  *Split into declaration and assignment*.
* **Split Multi-Variable Declaration** is performed by applying the action
  *Split into separate declarations*.

<hr/>

## Add Block Delimiter
Case | Result
---- | ------
ABD1 |  Pass
ABD2 |  Pass
ABD3 |  Pass
ABD4 |  Pass
ABD5 |  Pass
ABD6 |  Pass
ABD7 |  Pass

## Add Parameter
Case | Result
---- | ------
AP1 | Pass
AP2 | Pass
AP3 | Failure (creates invalid code) [36993](https://youtrack.jetbrains.com/issue/CPP-36993/Change-Signature-creates-invalid-code-when-definition-and-declaration-use-different-argument-names)
AP4 | Pass
AP5 | Pass
AP6 | Pass
AP7 | Pass
AP8  | Pass
AP9  | Pass
AP10  | Pass
AP11  | Pass
AP12  | Pass
AP13  | Pass
AP14  | Pass
AP15  | Pass
AP16  | Pass
AP17 | Pass
AP18 | Pass
AP19 | Pass
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Pass
AP25 | Failure (not available) [16560](https://youtrack.jetbrains.com/issue/CPP-16560)
AP26 | Pass
AP27 | Pass
AP28 | Pass
AP29 | Pass
AP30 | Pass
AP31 | Pass
AP32 | Failure (creates invalid code) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP33 | Pass
AP34 | Pass
AP35 | Failure (creates invalid code) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP36 | Pass
AP37 | Pass
AP38 | Failure (creates invalid code) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP39 | Pass
AP40 | Pass
AP41 | Pass
AP42 | Pass
AP43 | Pass
AP44 | Pass
AP45 | Pass
AP46 | Pass
AP47 | Pass
AP48 | Pass
AP49 | Failure (creates invalid code) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP50 | Pass
AP51 | Pass
AP52 | Failure (creates invalid code) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP53 | Pass
AP54 | Pass
AP55 | Pass
AP56 | Pass
AP57 | Pass
AP58 | Pass
AP59 | Pass
AP60 | Pass
AP61 | Pass
AP62 | Pass
AP63 | Pass
AP64 | Pass
AP65 | Pass
AP66 | Pass
AP67 | Pass
AP68 | Pass
AP69 | Pass
AP70 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP71 | Pass
AP72 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP73 | Pass
AP74 | Pass
AP75 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP76 | Pass
AP77 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP78 | Pass
AP79 | Failure (doesn't update other template arguments) [16560](https://youtrack.jetbrains.com/issue/CPP-16560)
AP80 | Failure (doesn't update template related uses) [36992](https://youtrack.jetbrains.com/issue/CPP-36992/Change-Signature-doesnt-update-related-template-usages)
AP81 | Pass
AP82 | Pass
AP83 | Pass
AP84 | Pass
AP85 | Pass
AP86 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP87 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP88 | Pass
AP89 | Pass
AP90 | Pass
AP91 | Pass
AP92 | Pass
AP93 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP94 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP95 | Pass
AP96 | Pass
AP97 | Pass
AP98 | Pass
AP99 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP100 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP101 | Pass
AP102 | Pass
AP103 | Pass
AP104 | Pass
AP105 | Pass
AP106 | Pass
AP107 | Pass
AP108 | Pass
AP109 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP110 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP111 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP112 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP113 | Pass
AP114 | Pass
AP115 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP116 | Pass
AP117 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP118 | Pass
AP119 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP120 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP121 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP122 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP123 | Pass
AP124 | Pass
AP125 | Pass
AP126 | Pass
AP127 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP128 | Pass
AP129 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP130 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP131 | Failure (changes unrelated code) [36995](https://youtrack.jetbrains.com/issue/CPP-36995/Change-Signature-modifies-unrelated-code)
AP132 | Pass
AP133 | Pass
AP134 | Pass
AP135 | Pass
AP136 | Pass
AP137 | Pass
AP138 | Pass
AP139 | Pass
AP140 | Pass
AP141 | Pass
AP142 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP143 | Pass
AP144 | Pass
AP145 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP146 | Pass
AP147 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP148 | Pass
AP149 | Pass 
AP150 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP151 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)
AP152 | Pass
AP153 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP154 | Failure (not available) [36994](https://youtrack.jetbrains.com/issue/CPP-36994/Change-SIgnature-cant-add-new-default-arguments)****
AP155 | Pass
AP156 | Pass
AP157 | Pass
AP158 | Pass
AP159 | Pass
AP160 | Pass
AP161 | Pass
AP162 | Pass
AP163 | Pass
AP164 | Pass
AP165 | Pass
AP166 | Pass
AP167 | Pass
AP168 | Pass
AP169 | Pass
AP170 | Pass
AP171 | Pass
AP172 | Pass
AP173 | Pass
AP174 | Pass
AP175 | Pass
AP176 | Pass
AP177 | Pass
AP178 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP179 | Pass
AP180 | Pass
AP181 | Pass
AP182 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP183 | Pass
AP184 | Pass
AP185 | Pass
AP186 | Pass
AP187 | Pass
AP188 | Pass
AP189 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP190 | Pass
AP191 | Pass
AP192 | Pass
AP193 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP194 | Pass  
AP195 | Pass
AP196 | Pass
AP197 | Pass
AP198 | Pass
AP199 | Pass
AP200 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)
AP201 | Pass
AP202 | Failure (drops default argument) [36991](https://youtrack.jetbrains.com/issue/CPP-36991/Change-Signature-drops-default-argument-unnecessarily)

## Change Signature
Case | Result
---- | ------
CS1  |  Pass
CS2  |  Pass
CS3  |  Pass
CS4  |  Pass
CS5  |  Pass
CS6  |  Pass
CS7  |  Pass
CS8  |  Pass
CS9  |  Pass
CS10 |  Pass
CS11 |  Pass
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
CMS2 | Pass
CMS3  | Failure (not available) [1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS4  | Failure (not available) [1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS5 | Failure (not available) [1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS6 | Pass
CMS7 | Pass
CMS8 | Pass
CMS9 | Pass
CMS10 | Pass
CMS11 | Pass
CMS12 | Pass
CMS13 | Pass
CMS14 | Pass
CMS15  | Pass
CMS16  | Pass
CMS17 | Pass
CMS18  | Pass
CMS19  | Failure (doesn't create default c'tor) [1601](https://youtrack.jetbrains.com/issue/CPP-1601)
CMS20  | Failure (doesn't create default c'tor) [1601](https://youtrack.jetbrains.com/issue/CPP-1601)
CMS21  | Pass
CMS22 | Pass

## Create Setter Method
Case | Result
---- | ------
CSM1 | Pass
CSM2 | Pass
CSM3  | Pass
CSM4  | Pass
CSM5  | Pass
CSM6  | Pass
CSM7  | Pass
CSM8  | Pass
CSM9  | Pass
CSM10  | Pass
CSM11  | Pass
CSM12 | Pass
CSM13 | Pass
CSM14 | Pass
CSM15 | Pass
CSM16 | Pass
CSM17 | Pass
CSM18 | Pass
CSM19 | Pass
CSM20 | Pass
CSM21 | Pass
CSM22 | Pass
CSM23 | Pass
CSM24 | (deprecated)
CSM25 | Pass
CSM26 | Pass
CSM27 | Pass
CSM28 | Pass
CSM29 | Pass
CSM30 | Pass
CSM31 | Pass

## Extract Constant
Case | Result
---- | ------
EC1  | Failure (can't extract to class scope) [1928](https://youtrack.jetbrains.com/issue/CPP-1928)
EC2  | Pass
EC3  | Pass
EC4 | Pass
EC5  | Pass
EC6  | Failure (can't extract to class scope) [1928](https://youtrack.jetbrains.com/issue/CPP-1928)
EC7 | Pass
EC8 | Pass
EC9 | Pass
EC10  | Pass
EC11  | Pass
EC12  | Pass
EC13  | Pass

## Extract Function
Case | Result
---- | ------
EXF1  | Pass
EXF2  | Pass
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
EXF13 | Pass
EXF14 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF15 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF16 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF17 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF18 | Failure (changes member ptr to fn ptr) [1916](https://youtrack.jetbrains.com/issue/CPP-1916)
EXF19 | Pass

## Extract Method
Case | Result
---- | ------
EM1  | Pass
EM2 | Pass
EM3  | Failure (generates invalid code) [1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM4  | Failure (generates invalid code) [1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM5  | Pass
EM6 | Failure (generates invalid code) [1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM7  | Failure (generates invalid code) [1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM8  | Pass
EM9  | Pass
EM10  | Failure (generates invalid code) [1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM11  | Pass
EM12 | Pass
EM13 | Pass
EM14 | Pass
EM15 | Failure (generates invalid code when extracted below) [1918](https://youtrack.jetbrains.com/issue/CPP-1918)
EM16 | Pass
EM17 | Failure (generates invalid code when extracted below) [1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM18 | Failure (generates invalid code when extracted below) [1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM19 | Failure (generates invalid code when extracted below) [1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM20 | Failure (generates invalid code when extracted below) [1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM21 | Pass

## Extract Parameter
Case | Result
---- | ------
EP1  | Failure (changes member ptr to fn ptr) [1920](https://youtrack.jetbrains.com/issue/CPP-1920)
EP2  | Failure (creates invalid code) [16582](https://youtrack.jetbrains.com/issue/CPP-16582)
EP3  | Failure (should not be available) [1921](https://youtrack.jetbrains.com/issue/CPP-1921)
EP4  | Pass
EP5  | Pass
EP6  | Failure (changes member ptr to fn ptr) [1920](https://youtrack.jetbrains.com/issue/CPP-1920)

## Extract Variable
Case | Result
---- | ------
EXV1 | Pass
EXV2 | Failure (converts member ptr to fn ptr) [1931](https://youtrack.jetbrains.com/issue/CPP-1931)
EXV3 | Pass
EXV4 | Pass
EXV5 | Failure (expands too many typedefs) [1932](https://youtrack.jetbrains.com/issue/CPP-1932)
EXV6 | Pass

## Flatten Conditional
Case | Result
---- | ------
FC1  | Pass

## Inline Macro
Case | Result
---- | ------
IM1  | Failure (can't inline one macro inside another) [1922](https://youtrack.jetbrains.com/issue/CPP-1922)
IM2 | Pass
IM3  | Pass
IM4  | Pass
IM5  | Pass
IM6  | Pass
IM7  | Pass

## Inline Variable
Case | Result
---- | ------
IV1  | Pass
IV2  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV3 | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV4 | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV5  | Pass
IV6  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV7  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV8  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV9  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV10  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV11  | Failure (not available) [1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV12 | Failure (not available) [2252](https://youtrack.jetbrains.com/issue/CPP-2252)

## Move Implementation to Source File
Case   | Result
------ | ------
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
MISF16 | Failure (operation too complex) [36996](https://youtrack.jetbrains.com/issue/CPP-36996/Split-function-into-declaration-and-definition-fails-with-operation-too-complex)
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure (operation too complex) [36996](https://youtrack.jetbrains.com/issue/CPP-36996/Split-function-into-declaration-and-definition-fails-with-operation-too-complex)

## Move Method
Case | Result
---- | ------
MM1   | Pass
MM2   | Pass
MM3  | Pass
MM4  | Pass
MM5   | Pass
MM6   | Pass
MM7  | Pass
MM8  | Failure [16587](https://youtrack.jetbrains.com/issue/CPP-16587)
MM9  | Failure [16587](https://youtrack.jetbrains.com/issue/CPP-16587)
MM10   | Pass
MM11   | Pass
MM12  | Pass
MM13  | Pass
MM14  | Pass
MM15  | Pass
MM16  | Pass
MM17  | Pass
MM18  | Pass
MM19  | Pass
MM20  | Pass
MM21   | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM22   | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM23  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM24   | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM25  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM26  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM27  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM28  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM29  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM30  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM31  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM32  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM33  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM34  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM35  | Failure [1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM36  | Failure [1936](https://youtrack.jetbrains.com/issue/CPP-1936)

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
---- | -----
RUI1 | Pass

## Remove Unused Parameter
Case | Result
---- | ------
RUP1 | Pass
RUP2 | Pass
RUP3 | Pass
RUP4 | Pass

## Rename
Case | Result
---- | ------
R1  | Pass
R2  | Pass
R3  | Pass
R4  | Pass
R5   | Failure (selects unrelated names) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R6   | Failure (selects unrelated names) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R7  | Failure (selects unrelated instances) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R8  | Failure (selects unrelated instances) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R9  | Pass
R10   | Failure (selects unrelated names) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R11   | Pass
R12   | Pass
R13   | Pass
R14   | Failure (creates invalid code) [1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R15   | Failure (creates invalid code) [1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R16  | Pass
R17   | Pass
R18  | Pass
R19  | Pass
R20  | Pass
R21  | Pass
R22  | Pass
R23  | Pass
R24  | Pass
R25  | Pass
R26  | Pass
R27  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R28  | Pass
R29  | Pass
R30  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R31  | Pass
R32  | Pass
R33  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R34  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R35  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R36  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R37  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R38  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R39  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R40  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R41  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R42  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R43  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R44  | Failure (selects unrelated macro by default) [1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R45  | Pass
R46 | Pass
R47 | Pass
R48 | Pass
R49 | Pass
R50 | Pass
R51 | Pass
R52 | Pass
R53 | Pass
R54 | Pass
R55 | Pass
R56 | Pass
R57 | Pass
R58 | Pass
R59 | Pass
R60 | Pass
R61 | Pass
R62 | Pass
R63 | Pass
R64 | Pass
R65 | Pass
R66 | Pass
R67 | Pass
R68 | Pass
R69 | Pass
R70 | Pass
R71 | Pass
R72 | Pass
R73 | Pass
R74 | Pass
R75 | Pass
R76 | Pass
R77 | Pass
R78 | Pass
R79 | Pass
R80 | Pass
R81 | Pass
R82 | Pass
R83 | Pass
R84 | Pass
R85 | Pass
R86 | Pass
R87 | Pass
R88 | Pass
R89 | Pass
R90 | Pass
R91 | Pass
R92 | Pass
R93 | Pass
R94 | Pass
R95 | Pass
R96 | Pass
R97 | Pass
R98 | Pass
R99 | Failure (doesn't select all instances) [16696](https://youtrack.jetbrains.com/issue/CPP-16696)
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
R122 | Pass
R123 | Pass
R124 | Pass
R125 | Pass
R126 | Pass
R127 | Pass
R128 | Pass
R129 | Pass
R130 | Pass
R131 | Pass
R132 | Pass
R133 | Pass
R134 | Pass
R135 | Pass
R136 | Pass
R137 | Pass
R138 | Pass
R139 | Pass
R140 | Pass
R141 | Pass
R142 | Pass
R143 | Pass
R144 | Pass
R145 | Pass
R146 | (deprecated)
R147 | Pass
R148 | Pass
R149 | Pass
R150 | Pass
R151 | Pass
R152 | Pass
R153 | Pass
R154 | Pass
R155 | Pass
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
R190  | Pass
R191  | Pass
R192  | Failure (doesn't select all instances, selects unrelated instances) [1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R193  | Pass
R194  | Failure (doesn't select all instances, selects unrelated instances) [36997](https://youtrack.jetbrains.com/issue/CPP-36997/Renaming-a-method-from-usage-doesnt-rename-method-and-renames-unrelated-identifiers)
R195  | Pass
R196  | Pass
R197  | Failure (creates invalid code) [1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R198  | Pass
R199  | Pass
R200  | Pass
R201  | Failure (selects unrelated instances) [36998](https://youtrack.jetbrains.com/issue/CPP-36998/Renaming-a-method-from-usage-renames-unrelated-identifiers)
R202  | Pass
R203  | Pass
R204  | Pass
R205  | Pass
R206  | Pass
R207  | Pass
R208  | Pass
R209  | Pass
R210  | Pass
R211  | Pass
R212  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R213  | Pass
R214  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R215  | Pass
R216  | Pass
R217  | Pass
R218  | Pass
R219  | Pass
R220  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R221  | Pass
R222  | Pass
R223  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R224  | Pass
R225  | Pass
R226  | Pass
R227  | Pass (unrelated comments selected by default) [1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R228  | Pass
R229  | Pass
R230  | Pass
R231  | Pass
R232  | Pass
R233  | Pass
R234  | Pass
R235  | Pass
R236  | Pass
R237  | (deprecated)
R238  | (deprecated)
R239  | Pass
R240  | Pass
R241  | Pass
R242  | Pass
R243  | Pass
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
R277 | Failure (creates invalid code) [16647](https://youtrack.jetbrains.com/issue/CPP-16647)
R278 | Pass
R279 | Pass
R280 | Pass
R281 | Pass
R282 | Pass
R283 | Pass
R284 | Pass
R285 | Pass
R286 | Pass
R287 | Pass
R288 | Failure (creates invalid code) [16647](https://youtrack.jetbrains.com/issue/CPP-16647)
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
R307 | Failure (renames unrelated instances) [16649](https://youtrack.jetbrains.com/issue/CPP-16649)
R308 | Failure (renames unrelated instances) [16649](https://youtrack.jetbrains.com/issue/CPP-16649)
R309 | Pass
R310 | Pass
R311 | Pass
R312 | Failure (renames unrelated instances) [16649](https://youtrack.jetbrains.com/issue/CPP-16649)
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
R379 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R380 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R381 | Pass
R382 | Pass
R383 | Pass
R384 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R385 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R386 | Pass
R387 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R388 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R389 | Pass
R390 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R391 | Failure (creates invalid code) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
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
R470 | Failure (doesn't select all instances) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R471 | Pass
R472 | Pass
R473 | Pass
R474 | Pass
R475 | Pass
R476 | Failure (doesn't select all instances) [16659](https://youtrack.jetbrains.com/issue/CPP-16659)
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
R515 | Pass
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
R562 | Pass
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
R606 | Pass
R607 | Pass
R608 | Pass
R609 | Pass
R610 | Pass
R611 | Pass
R612 | Pass
R613 | Pass
R614 | Pass
R615 | Pass
R616 | Pass
R617 | Pass
R618 | Pass
R619 | Pass
R620 | Pass
R621 | Pass
R622 | Pass
R623 | Pass
R624 | Pass
R625 | Pass
R626 | Pass
R627 | Pass
R628 | Pass
R629 | Pass
R630 | Pass
R631 | Pass
R632 | Pass
R633 | Pass
R634 | Pass
R635 | Pass
R636 | Pass
R637 | Pass
R638 | Pass
R639 | Pass
R640 | Pass
R641 | Pass
R642 | Pass
R643 | Pass
R644 | Pass
R645 | Pass
R646 | Pass
R647 | Pass
R648 | Pass
R649 | Pass
R650 | Pass
R651 | Pass
R652 | Pass
R653 | Pass
R654 | Pass
R655 | Pass
R656 | Pass
R657 | Pass
R658 | Pass
R659 | Pass
R660 | Pass
R661 | Pass
R662 | Pass
R663 | Pass
R664 | Pass
R665 | Pass
R666 | Pass
R667 | Pass
R668 | Pass
R669 | Pass
R670 | Pass
R671 | Pass
R672 | Pass
R673 | Pass
R674 | Pass
R675 | Pass
R676 | Pass
R677 | Pass
R678 | Pass
R679 | Pass
R680 | Pass
R681 | Pass
R682 | Pass
R683 | Pass
R684 | Pass
R685 | Pass
R686 | Pass
R687 | Pass
R688 | Pass
R689 | Pass
R690 | Pass
R691 | Pass
R692 | Pass
R693 | Pass
R694 | Pass
R695 | Pass
R696 | Pass
R697 | Pass
R698 | Pass
R699 | Pass
R700 | Pass
R701 | Pass
R702 | Pass
R703 | Pass
R704 | Pass
R705 | Pass
R706 | Pass
R707 | Pass
R708 | Pass
R709 | Pass
R710 | Pass
R711 | Pass
R712 | Pass
R713 | Pass
R714 | Pass
R715 | Pass
R716 | Pass
R717 | Pass
R718 | Pass
R719 | Pass
R720 | Pass
R721 | Pass
R722 | Pass
R723 | Pass
R724 | Pass
R725 | Pass
R726 | Pass
R727 | Pass
R728 | Pass
R729 | Pass
R730 | Pass
R731 | Pass
R732 | Pass
R733 | Pass
R734 | Pass
R735 | Pass
R736 | Pass
R737 | Pass
R738 | Pass
R739 | Pass
R740 | Pass
R741 | Pass
R742 | Pass
R743 | Pass
R744 | Pass
R745 | Pass
R746 | Pass
R747 | Pass
R748 | Pass
R749 | Pass
R750 | Pass
R751 | Pass
R752 | Pass
R753 | Pass
R754 | Pass
R755 | Pass
R756 | Pass
R757 | Pass
R758 | Pass
R759 | Pass
R760 | Pass
R761 | Pass
R762 | Pass
R763 | Pass
R764 | Pass
R765 | Pass
R766 | Pass
R767 | Pass
R768 | Pass
R769 | Pass
R770 | Pass
R771 | Pass
R772 | Pass
R773 | Pass
R774 | Pass
R775 | Pass
R776 | Pass
R777 | Pass
R778 | Pass
R779 | Pass
R780 | Pass
R781 | Pass
R782 | Pass
R783 | Pass
R784 | Pass
R785 | Pass
R786 | Pass
R787 | Pass
R788 | Pass
R789 | Pass
R790 | Pass
R791 | Pass
R792 | Pass
R793 | Pass
R794 | Pass
R795 | Pass
R796 | Pass
R797 | Pass
R798 | Pass
R799 | Pass
R800 | Pass
R801 | Pass
R802 | Pass
R803 | Pass
R804 | Pass
R805 | Pass
R806 | Pass
R807 | Pass
R808 | Pass
R809 | Pass
R810 | Pass
R811 | Pass
R812 | Pass
R813 | Pass
R814 | Pass
R815 | Pass
R816 | Pass
R817 | Pass
R818 | Pass
R819 | Pass
R820 | Pass
R821 | Pass
R822 | Pass
R823 | Pass
R824 | Pass
R825 | Pass
R826 | Pass
R827 | Pass
R828 | Pass
R829 | Pass
R830 | Pass
R831 | Pass
R832 | Pass
R833 | Pass
R834 | Pass
R835 | Pass
R836 | Pass
R837 | Pass
R838 | Pass
R839 | Pass
R840 | Pass
R841 | Failure (not available)
R842 | Pass
R843 | Pass
R844 | Pass
R845 | Pass
R846 | Pass
R847 | Pass
R848 | Failure (not available) [36999](https://youtrack.jetbrains.com/issue/CPP-36999/Cant-Rename-variable-from-usage)
R849 | Pass
R850 | Pass
R851 | Pass
R852 | Pass
R853 | Pass
R854 | Pass
R855 | Failure (not available) [36999](https://youtrack.jetbrains.com/issue/CPP-36999/Cant-Rename-variable-from-usage)
R856 | Pass
R857 | Pass
R858 | Pass
R859 | Pass
R860 | Pass
R861 | Pass
R862 | Pass
R863 | Pass
R864 | Pass
R865 | Pass
R866 | Pass
R867 | Pass
R868 | Pass
R869 | Pass
R870 | Pass
R871 | Pass
R872 | Pass
R873 | Pass
R874 | Pass
R875 | Pass
R876 | Pass
R877 | Pass
R878 | Pass
R879 | Pass
R880 | Pass
R881 | Pass
R882 | Pass
R883 | Pass
R884 | Pass
R885 | Pass
R886 | Pass
R887 | Pass
R888 | Pass
R889 | Pass
R890 | Pass
R891 | Pass
R892 | Pass
R893 | Pass
R894 | Pass
R895 | Pass
R896 | Pass
R897 | Pass
R898 | Pass
R899 | Pass
R900 | Pass
R901 | Pass
R902 | Pass
R903 | Pass
R904 | Pass
R905 | Pass
R906 | Pass
R907 | Pass
R908 | Pass
R909 | Pass
R910 | Failure (not available) [37000](https://youtrack.jetbrains.com/issue/CPP-37000/Cant-rename-explicit-template-parameter-to-lambda-from-usage)
R911 | Failure (not available) [37000](https://youtrack.jetbrains.com/issue/CPP-37000/Cant-rename-explicit-template-parameter-to-lambda-from-usage)
R912 | Pass
R913 | Pass
R914 | Pass
R915 | Pass
R916 | Pass
R917 | Pass
R918 | Pass
R919 | Pass
R920 | Pass
R921 | Pass
R922 | Pass
R923 | Pass
R924 | Pass
R925 | Pass
R926 | Pass
R927 | Pass
R928 | Pass
R929 | Pass
R930 | Pass
R931 | Pass
R932 | Pass
R933 | Pass
R934 | Pass
R935 | Pass
R936 | Pass
R937 | Pass
R938 | Pass
R939 | Pass
R940 | Pass
R941 | Pass
R942 | Pass
R943 | Pass
R944 | Pass
R945 | Pass
R946 | Pass
R947 | Pass
R948 | Pass
R949 | Pass
R950 | Pass
R951 | Pass
R952 | Pass
R953 | Pass
R954 | Pass
R955 | Pass
R956 | Pass
R957 | Pass
R958 | Pass
R959 | Pass
R960 | Pass
R961 | Pass
R962 | Pass
R963 | Pass
R964 | Pass
R965 | Pass
R966 | Pass
R967 | Pass
R968 | Pass
R969 | Pass
R970 | Pass
R971 | Pass
R972 | Pass
R973 | Pass
R974 | Pass
R975 | Pass
R976 | Pass
R977 | Pass
R978 | Pass
R979 | Pass
R980 | Pass
R981 | Pass
R982 | Pass
R983 | Pass
R984 | Pass
R985 | Pass
R986 | Pass
R987 |
R988 |
R989 |
R990 |
R991 |
R992 |
R993 |
R994 |
R995 |
R996 |
R997 |
R998 |
R999 |
R1000 |
R1001 |
R1002 |
R1003 |
R1004 |
R1005 |
R1006 |
R1007 |
R1008 |
R1009 |
R1010 |
R1011 |
R1012 |
R1013 |
R1014 |
R1015 |
R1016 |
R1017 |
R1018 |
R1019 |
R1020 |
R1021 |
R1022 |
R1023 |
R1024 |
R1025 |
R1026 |
R1027 |
R1028 |
R1029 |
R1030 |
R1031 |
R1032 |
R1033 |
R1034 |
R1035 |
R1036 |
R1037 |
R1038 |
R1039 |
R1040 |
R1041 |
R1042 |
R1043 |
R1044 |
R1045 |
R1046 |
R1047 |
R1048 |
R1049 |
R1050 |
R1051 |
R1052 |
R1053 |
R1054 |
R1055 |
R1056 |
R1057 |
R1058 |
R1059 |
R1060 |
R1061 |
R1062 |
R1063 |
R1064 |
R1065 |
R1066 |
R1067 |
R1068 |
R1069 |
R1070 |
R1071 |
R1072 |
R1073 |
R1074 |
R1075 |
R1076 |
R1077 |
R1078 |
R1079 |
R1080 |
R1081 |
R1082 |
R1083 |
R1084 |
R1085 |
R1086 |
R1087 |
R1088 |
R1089 |
R1090 |
R1091 |
R1092 |
R1093 |
R1094 |
R1095 |
R1096 |
R1097 |
R1098 |
R1099 |
R1100 |
R1101 |
R1102 |
R1103 |
R1104 |
R1105 |
R1106 |
R1107 |
R1108 |
R1109 |
R1110 |
R1111 |
R1112 |
R1113 |
R1114 |
R1115 |
R1116 |
R1117 |
R1118 |
R1119 |
R1120 |
R1121 |
R1122 |
R1123 |
R1124 |
R1125 |
R1126 |
R1127 |
R1128 |
R1129 |
R1130 |
R1131 |
R1132 |
R1133 |
R1134 |
R1135 |
R1136 |
R1137 |
R1138 |
R1139 |
R1140 |
R1141 |
R1142 |
R1143 |
R1144 |
R1145 |
R1146 |
R1147 |
R1148 |
R1149 |
R1150 |
R1151 |
R1152 |
R1153 |
R1154 |
R1155 |
R1156 |
R1157 |
R1158 |
R1159 |
R1160 |
R1161 |
R1162 |
R1163 |
R1164 |
R1165 |
R1166 |
R1167 |
R1168 |
R1169 |
R1170 |
R1171 |
R1172 |
R1173 |
R1174 |
R1175 |
R1176 |
R1177 |
R1178 |
R1179 |
R1180 |
R1181 |
R1182 |
R1183 |
R1184 |
R1185 |
R1186 |
R1187 |
R1188 |
R1189 |
R1190 |
R1191 |
R1192 |
R1193 |
R1194 |
R1195 |
R1196 |
R1197 |
R1198 |
R1199 |
R1200 |
R1201 |
R1202 |
R1203 |
R1204 |
R1205 |
R1206 |
R1207 |
R1208 |
R1209 |
R1210 |
R1211 |
R1212 |
R1213 |
R1214 |
R1215 |
R1216 |
R1217 |
R1218 |
R1219 |
R1220 |
R1221 |
R1222 |
R1223 |
R1224 |
R1225 |
R1226 |
R1227 |
R1228 |
R1229 |
R1230 |
R1231 |
R1232 |
R1233 |
R1234 |
R1235 |
R1236 |
R1237 |
R1238 |
R1239 |
R1240 |
R1241 |
R1242 |
R1243 |
R1244 |
R1245 |
R1246 |
R1247 |
R1248 |
R1249 |
R1250 |
R1251 |
R1252 |
R1253 |
R1254 |
R1255 |
R1256 |
R1257 |
R1258 |
R1259 |
R1260 |
R1261 |
R1262 |
R1263 |
R1264 |
R1265 |
R1266 |
R1267 |
R1268 |
R1269 |
R1270 |
R1271 |
R1272 |
R1273 |
R1274 |
R1275 |
R1276 |
R1277 |
R1278 |
R1279 |
R1280 |
R1281 |
R1282 |
R1283 |
R1284 |
R1285 |
R1286 |
R1287 |
R1288 |
R1289 |
R1290 |
R1291 |
R1292 |
R1293 |
R1294 |
R1295 |
R1296 |
R1297 |
R1298 |
R1299 |
R1300 |
R1301 |
R1302 |
R1303 |
R1304 |
R1305 |
R1306 |
R1307 |
R1308 |
R1309 |
R1310 |
R1311 |
R1312 |
R1313 |
R1314 |
R1315 |
R1316 |
R1317 |
R1318 |
R1319 |
R1320 |
R1321 |
R1322 |
R1323 |
R1324 |
R1325 |
R1326 |
R1327 |
R1328 |
R1329 |
R1330 |
R1331 |
R1332 |
R1333 |
R1334 |
R1335 |
R1336 |
R1337 |
R1338 |
R1339 |
R1340 |
R1341 |
R1342 |
R1343 |
R1344 |
R1345 |
R1346 |
R1347 |
R1348 |
R1349 |
R1350 |
R1351 |
R1352 |
R1353 |
R1354 |
R1355 |
R1356 |
R1357 |
R1358 |
R1359 |
R1360 |
R1361 |
R1362 |
R1363 |
R1364 |
R1365 |
R1366 |
R1367 |
R1368 |
R1369 |
R1370 |
R1371 |
R1372 |
R1373 |
R1374 |
R1375 |
R1376 |
R1377 |
R1378 |
R1379 |
R1380 |
R1381 |
R1382 |
R1383 |
R1384 |
R1385 |
R1386 |
R1387 |
R1388 |
R1389 |
R1390 |
R1391 |
R1392 |
R1393 |
R1394 |
R1395 |
R1396 |
R1397 |
R1398 |
R1399 |
R1400 |
R1401 |
R1402 |
R1403 |
R1404 |
R1405 |
R1406 |
R1407 |
R1408 |
R1409 |
R1410 |
R1411 |
R1412 |
R1413 |
R1414 |
R1415 |
R1416 |
R1417 |
R1418 |
R1419 |
R1420 |
R1421 |
R1422 |
R1423 |
R1424 |
R1425 |
R1426 |
R1427 |
R1428 |
R1429 |
R1430 |
R1431 |
R1432 |
R1433 |
R1434 |
R1435 |
R1436 |
R1437 |
R1438 |
R1439 |
R1440 |
R1441 |
R1442 |
R1443 |
R1444 |
R1445 |
R1446 |
R1447 |
R1448 |
R1449 |
R1450 |
R1451 |
R1452 |
R1453 |
R1454 |
R1455 |
R1456 |
R1457 |
R1458 |
R1459 |
R1460 |
R1461 |
R1462 |
R1463 |
R1464 |
R1465 |
R1466 |
R1467 |
R1468 |
R1469 |
R1470 |
R1471 |
R1472 |
R1473 |
R1474 |
R1475 |
R1476 |
R1477 |
R1478 |
R1479 |
R1480 |
R1481 |
R1482 |
R1483 |
R1484 |
R1485 |
R1486 |
R1487 |
R1488 |
R1489 |
R1490 |
R1491 |
R1492 |
R1493 |
R1494 |
R1495 |
R1496 |
R1497 |
R1498 |
R1499 |
R1500 |
R1501 |
R1502 |
R1503 |
R1504 |
R1505 |
R1506 |
R1507 |
R1508 |
R1509 |
R1510 |
R1511 |
R1512 |
R1513 |
R1514 |
R1515 |
R1516 |
R1517 |
R1518 |
R1519 |
R1520 |
R1521 |
R1522 |
R1523 |
R1524 |
R1525 |
R1526 |
R1527 |
R1528 |
R1529 |
R1530 |
R1531 |
R1532 |
R1533 |
R1534 |
R1535 |
R1536 |
R1537 |
R1538 |
R1539 |
R1540 |
R1541 |
R1542 |
R1543 |
R1544 |
R1545 |
R1546 |
R1547 |
R1548 |
R1549 |
R1550 |
R1551 |
R1552 |
R1553 |
R1554 |
R1555 |
R1556 |
R1557 |
R1558 |
R1559 |
R1560 |
R1561 |
R1562 |
R1563 |
R1564 |
R1565 |
R1566 |
R1567 |
R1568 |
R1569 |
R1570 |
R1571 |
R1572 |
R1573 |
R1574 |
R1575 |

## Reorder Parameters
Case| Result
--- | -----
RP1 | (deprecated)
RP2 | Pass
RP3 | (deprecated)
RP4 | (deprecated)
RP5 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
RP6 | Failure (changes member ptr to fn ptr) [1915](https://youtrack.jetbrains.com/issue/CPP-1915)
RP7 | Pass
RP8 | Pass
RP9 | (deprecated)

## Replace If With Ternary
Case | Result
---- | ------
RIT1 | Pass
RIT2 | Failure (not available) [1944](https://youtrack.jetbrains.com/issue/CPP-1944)
RIT3 | Pass
RIT4 | Failure (not available) [1944](https://youtrack.jetbrains.com/issue/CPP-1944)
RIT5 | Pass
RIT6 | Pass
RIT7 | Pass
RIT8 | Pass
RIT9 | Failure (creates invalid code) [1945](https://youtrack.jetbrains.com/issue/CPP-1945)

## Replace Ternary With If
Case | Result
---- | ------
RTI1 | Pass
RTI2 | Failure (should not be available) [1946](https://youtrack.jetbrains.com/issue/CPP-1946)
RTI3 | Pass
RTI4 | Pass
RTI5 | Failure (should not be available) [1946](https://youtrack.jetbrains.com/issue/CPP-1946)
RTI6 | Pass
RTI7 | Pass
RTI8 | Pass
RTI9 | Failure (should not be available) [1946](https://youtrack.jetbrains.com/issue/CPP-1946)
RTI10 | Pass
RTI11 | Failure (should not be available) [1946](https://youtrack.jetbrains.com/issue/CPP-1946)

## Replace Type With auto
Case   | Result
------ | ------
RTWA1  | Pass
RTWA2  | Pass
RTWA3  | Pass
RTWA4  | Pass
RTWA5  | Pass
RTWA6  | Pass
RTWA7  | Pass
RTWA8  | Pass
RTWA9  | Pass
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
RC1  | Pass
RC2  | Pass
RC3  | Pass
RC4  | Pass
RC5  | Pass
RC6  | Pass
RC7  | Pass
RC8  | Pass

## Simplify Boolean Expression
Case | Result
---- | ------
SB1  | Pass
SB2  | Pass
SB3  | Pass
SB4  | Pass
SB5  | Pass
SB6  | Pass
SB7  | Pass
SB8  | Pass
SB9  | Pass
SB10 | Pass
SB11 | Pass
SB12 | Pass
SB13 | Pass

## Split Initialization From Declaration
Case  | Result
----- | ------
SID1  | Pass
SID2  | Pass
SID3  | Pass
SID4  | Pass
SID5  | Pass
SID6  | Pass
SID7  | Pass
SID8  | Pass
SID9  | Pass
SID10 | Pass
SID11 | Failure (not available) [1948](https://youtrack.jetbrains.com/issue/CPP-1948)

## Split Multi-Variable Declaration
Case   | Result
-----  | ------
SMVD1  | Pass
SMVD2  | Pass
SMVD3  | Pass
SMVD4  | Pass
SMVD5  | Pass
SMVD6  | Pass
SMVD7  | Pass
SMVD8  | Pass
SMVD9  | Pass
SMVD10 | Pass
SMVD11 | Pass
SMVD12 | Pass
SMVD13 | Pass
SMVD14 | Pass
SMVD15 | Pass
SMVD16 | Pass
SMVD17 | Pass
SMVD18 | Pass
SMVD19 | Pass
