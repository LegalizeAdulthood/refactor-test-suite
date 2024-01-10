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
* **Create Setter Method** is performed with Code / Generate... / Setter.
* **Flatten Conditional** is performed by repeatedly applying the action *Merge
Nested Ifs*.
* **Replace If With Ternary** is performed by applying the action *Replace
'if else' with '?:'*.
* **Replace Ternary With If** is performed by applying the action *Replace
'?;' with 'if else'*.
* **Reorder Parameters** is performed with **Change Signature**.
* **Reverse Conditional** is performed with Invert Condition
* **Create Multi Variable Declaration** is not available.

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
AP1  | Pass
AP2  | Pass
AP3  | Pass
AP4  | Pass
AP5  | Pass
AP6  | Pass
AP7  | Pass
AP8  | Failure (doesn't update definition)
AP9  | Failure (doesn't update definition)
AP10 | Pass
AP11 | Pass
AP12 | Pass
AP13 | Failure (doesn't update declaration)
AP14 | Pass
AP15 | Pass
AP16 | Pass
AP17 | Pass
AP18 | Failure (gets confused about default values)
AP19 | Pass
AP20 | Pass
AP21 | Failure (gets confused about default values)
AP22 | Pass
AP23 | Failure (gets confused about default values)
AP24 | Failure (doesn't update other template arguments) [CPP-16560](https://youtrack.jetbrains.com/issue/CPP-16560)
AP25 | Failure (not available) [CPP-16560](https://youtrack.jetbrains.com/issue/CPP-16560)
AP26 | Failure (doesn't update template related uses)
AP27 | Pass
AP28 | Pass
AP29 | Failure (creates invalid code)
AP30 | Pass
AP31 | Pass
AP32 | Pass
AP33 | Pass
AP34 | Pass
AP35 | Pass
AP36 | Pass
AP37 | Pass
AP38 | Pass
AP39 | Pass
AP40 | Pass
AP41 | Pass
AP42 | Failure (doesn't update definition)
AP43 | Pass
AP44 | Pass
AP45 | Failure (not available)
AP46 | Pass
AP47 | Pass
AP48 | Failure (not available)
AP49 | Failure (doesn't update definition)
AP50 | Pass
AP51 | Failure (not available)
AP52 | Pass
AP53 | Pass
AP54 | Pass
AP55 | Pass
AP56 | Pass
AP57 | Failure (doesn't update definition)
AP58 | Pass
AP59 | Pass
AP60 | Pass
AP61 | Pass
AP62 | Failure (not available)
AP63 | Failure (doesn't update definition)
AP64 | Pass
AP65 | Failure (not available)
AP66 | Pass
AP67 | Pass
AP68 | Pass
AP69 | Pass
AP70 | Pass
AP71 | Pass
AP72 | Pass
AP73 | Pass
AP74 | Pass
AP75 | Pass
AP76 | Failure (doesn't update definition)
AP77 | Pass
AP78 | Pass
AP79 | Pass
AP80 | Pass
AP81 | Pass
AP82 | Pass
AP83 | Failure (changes unrelated code)
AP84 | Pass
AP85 | Failure (changes unrelated code)
AP86 | Pass
AP87 | Pass
AP88 | Pass
AP89 | Pass
AP90 | Pass
AP91 | Failure (drops default argument)
AP92 | Failure (drops default argument)
AP93 | Pass
AP94 | Pass
AP95 | Pass
AP96 | Pass
AP97 | Pass
AP98 | Failure (drops default argument)
AP99 | Failure (drops default argument)
AP100 | Pass
AP101 | Pass
AP102 | Pass
AP103 | Pass
AP104 | Failure (drops default argument)
AP105 | Failure (drops default argument)
AP106 | Pass
AP107 | Pass
AP108 | Pass
AP109 | Pass
AP110 | Pass
AP111 | Pass
AP112 | Pass
AP113 | Pass
AP114 | Failure (drops default argument)
AP115 | Failure (not available)
AP116 | Failure (drops default argument)
AP117 | Failure (not available)
AP118 | Pass
AP119 | Pass
AP120 | Failure (not available)
AP121 | Pass
AP122 | Failure (not available)
AP123 | Pass
AP124 | Failure (drops default argument)
AP125 | Failure (not available)
AP126 | Failure (drops default argument)
AP127 | Failure (not available)
AP128 | Pass
AP129 | Pass
AP130 | Pass
AP131 | Pass
AP132 | Failure (changes unrelated code)
AP133 | Pass
AP134 | Failure (changes unrelated code)
AP135 | Failure (changes unrelated code)
AP136 | Failure (changes unrelated code)
AP137 | Pass
AP138 | Pass
AP139 | Pass
AP140 | Pass
AP141 | Pass
AP142 | Pass
AP143 | Pass 
AP144 | Failure (drops default argument)
AP145 | Failure (not available)
AP146 | Pass
AP147 | Failure (drops default argument)
AP148 | Failure (not available)
AP149 | Pass
AP150 | Pass
AP151 | Pass
AP152 | Pass
AP153 | Pass
AP154 | Pass
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
AP173 | Failure (drops default argument)
AP174 | Pass
AP175 | Pass
AP176 | Pass
AP177 | Failure (drops default argument)
AP178 | Pass
AP179 | Pass
AP180 | Pass
AP181 | Pass
AP182 | Pass
AP183 | Pass
AP184 | Failure (drops default argument)
AP185 | Pass
AP186 | Pass
AP187 | Pass
AP188 | Failure (drops default argument)
AP189 | Pass
AP190 | Pass
AP191 | Pass
AP192 | Pass
AP193 | Pass
AP194 | Failure (drops default argument)
AP195 | Pass
AP196 | Failure (drops default argument)
AP197 | Pass
AP198 | Pass
AP199 | Failure (drops default argument)
AP200 | Pass
AP201 | Failure (drops default argument)
AP202 | Pass  

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

## Create Method Stub
Case | Result
---- | ------
CMS1  | Pass
CMS2  | Pass
CMS3  | Pass
CMS4  | Failure [CPP-1601](https://youtrack.jetbrains.com/issue/CPP-1601)
CMS5  | Failure [CPP-1601](https://youtrack.jetbrains.com/issue/CPP-1601)
CMS6  | Pass
CMS7  | Pass
CMS8  | Failure (not available) [CPP-1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS9  | Failure (not available) [CPP-1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS10 | Failure (not available) [CPP-1908](https://youtrack.jetbrains.com/issue/CPP-1908)
CMS11 | Pass
CMS12 | Pass
CMS13 | Pass
CMS14 | Pass
CMS15 | Pass
CMS16 | Pass
CMS17 | Pass
CMS18 | Pass
CMS19 | Pass
CMS20 | Pass
CMS21 | Pass
CMS22 | Pass

## Create Setter Method
Case | Result
---- | ------
CSM1  | Pass
CSM2  | Pass
CSM3  | Pass
CSM4  | Pass
CSM5  | Pass
CSM6  | Pass
CSM7  | Pass
CSM8  | Pass
CSM9  | Pass
CSM10 | Pass
CSM11 | Pass
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
CSM24 | Pass
CSM25 | Pass
CSM26 | Pass
CSM27 | Pass
CSM28 | Pass
CSM29 | Failure (not available)
CSM30 | Pass
CSM31 | Pass

## Extract Constant
Case | Result
---- | ------
EC1  | Pass
EC2  | Pass
EC3  | Pass
EC4  | Pass
EC5  | Failure [CPP-1928](https://youtrack.jetbrains.com/issue/CPP-1928)
EC6  | Pass
EC7  | Failure [CPP-1929](https://youtrack.jetbrains.com/issue/CPP-1929), [CPP-1930](https://youtrack.jetbrains.com/issue/CPP-1930)
EC8  | Pass
EC9  | Failure [CPP-1928](https://youtrack.jetbrains.com/issue/CPP-1928)
EC10 | Pass
EC11 | Failure [CPP-1929](https://youtrack.jetbrains.com/issue/CPP-1929), [CPP-1930](https://youtrack.jetbrains.com/issue/CPP-1930)
EC12 | Pass
EC13 | Pass

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
EXF14 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF15 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF16 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF17 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
EXF18 | Failure [CPP-1916](https://youtrack.jetbrains.com/issue/CPP-1916)
EXF19 | Pass

## Extract Method
Case | Result
---- | ------
EM1  | Pass
EM2  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM3  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM4  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM5  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM6  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM7  | Pass
EM8  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM9  | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM10 | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM11 | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM12 | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)
EM13 | Failure [CPP-1918](https://youtrack.jetbrains.com/issue/CPP-1918)
EM14 | Pass
EM15 | Failure [CPP-1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM16 | Failure [CPP-1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM17 | Failure [CPP-1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM18 | Failure [CPP-1919](https://youtrack.jetbrains.com/issue/CPP-1919)
EM19 | Pass
EM20 | Failure [CPP-1917](https://youtrack.jetbrains.com/issue/CPP-1917)

## Extract Parameter
Case | Result
---- | ------
EP1  | Failure [CPP-1920](https://youtrack.jetbrains.com/issue/CPP-1920)
EP2  | Failure [CPP-16582](https://youtrack.jetbrains.com/issue/CPP-16582)
EP3  | Failure (should not be available) [CPP-1921](https://youtrack.jetbrains.com/issue/CPP-1921)
EP4  | Pass
EP5  | Failure [CPP-1920](https://youtrack.jetbrains.com/issue/CPP-1920)
EP6  | Pass

## Extract Variable
Case | Result
---- | ------
EXV1 | Failure [CPP-1931](https://youtrack.jetbrains.com/issue/CPP-1931)
EXV2 | Pass
EXV3 | Pass
EXV4 | Pass
EXV5 | Pass
EXV6 | Failure [CPP-1932](https://youtrack.jetbrains.com/issue/CPP-1932)

## Flatten Conditional
Case | Result
---- | ------
FC1  | Pass

## Inline Macro
Case | Result
---- | ------
IM1  | Failure [CPP-1922](https://youtrack.jetbrains.com/issue/CPP-1922)
IM2  | Pass
IM3  | Pass
IM4  | Pass
IM5  | Pass
IM6  | Pass

## Inline Variable
Case | Result
---- | ------
IV1  | Pass
IV2  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV3  | Pass
IV4  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV5  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV6  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV7  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV8  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV9  | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV10 | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV11 | Failure (not available) [CPP-1925](https://youtrack.jetbrains.com/issue/CPP-1925)
IV12 | Failure (not available) [CPP-2252](https://youtrack.jetbrains.com/issue/CPP-2252)

## Make Method Static
Case | Result
---- | ------
MMS1 | Pass
MMS2 | Pass
MMS3 | Failure 

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
MISF16 | Failure
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure

## Move Method
Case | Result
---- | ------
MM1   | Pass
MM2   | Pass
MM3   | Pass
MM4   | Pass
MM5   | Pass
MM6   | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM7   | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM8   | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM9   | Pass
MM10  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM11  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM12  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM13  | Pass
MM14  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM15  | Pass
MM16  | Pass
MM17  | Pass
MM18  | Pass
MM19  | Pass
MM20  | Pass
MM21  | Pass
MM22  | Pass
MM23  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM24  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM25  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM26  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM27  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM28  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM29  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM30  | Failure [CPP-1933](https://youtrack.jetbrains.com/issue/CPP-1933)
MM31  | Pass
MM32  | Pass
MM33  | Failure [CPP-16587](https://youtrack.jetbrains.com/issue/CPP-16587)
MM34  | Failure [CPP-16587](https://youtrack.jetbrains.com/issue/CPP-16587)
MM35  | Failure [CPP-1936](https://youtrack.jetbrains.com/issue/CPP-1936)
MM36  | Pass

## Remove Block Delimiter (Not available)
Case | Result
---- | ------
RBD1 | Failure (not available)
RBD2 | Failure (not available)
RBD3 | Pass
RBD4 | Failure (not available)
RBD5 | Failure (not available)
RBD6 | Failure (not available)
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
RUP4 | Failure [CPP-16644](https://youtrack.jetbrains.com/issue/CPP-16644)

## Rename
Case | Result
---- | ------
R1   | Failure [CPP-1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R2   | Failure [CPP-1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R3   | Failure [CPP-1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R4   | Pass
R5   | Pass
R6   | Pass
R7   | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R8   | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R9   | Pass
R10  | Pass
R11  | Pass
R12  | Failure (not available) [CPP-1940](https://youtrack.jetbrains.com/issue/CPP-1940)
R13  | Pass
R14  | Pass
R15  | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R16  | Pass
R17  | Pass
R18  | Pass
R19  | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R20  | Pass
R21  | Pass
R22  | Pass
R23  | Pass
R24  | Pass
R25  | Pass
R26  | Pass
R27  | Pass
R28  | Pass
R29  | Pass
R30  | Pass
R31  | Pass
R32  | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R33  | Failure [CPP-1938](https://youtrack.jetbrains.com/issue/CPP-1938)
R34  | Pass
R35  | Pass
R36  | Failure [CPP-1939](https://youtrack.jetbrains.com/issue/CPP-1939)
R37  | Pass
R38  | Pass
R39  | Pass
R40  | Pass
R41  | Pass
R42  | Pass
R43  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R44  | Pass
R45  | Pass
R46  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R47  | Pass
R48  | Pass
R49  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R50  | Pass
R51  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R52  | Pass
R53  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R54  | Pass
R55  | Pass
R56  | Pass
R57  | Pass
R58  | Pass
R59  | Pass
R60  | Pass
R61  | Pass
R62  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R63  | Pass
R64  | Pass
R65  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R66  | Pass
R67  | Pass
R68  | Pass
R69  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R70  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R71  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R72  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R73  | Pass (unrelated comments selected by default) [CPP-1942](https://youtrack.jetbrains.com/issue/CPP-1942)
R74  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R75  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R76  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R77  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R78  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R79  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R80  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R81  | Failure (selects unrelated macro by default) [CPP-1943](https://youtrack.jetbrains.com/issue/CPP-1943)
R82  | Pass
R83  | Pass
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
R98  | Failure [CPP-1941](https://youtrack.jetbrains.com/issue/CPP-1941)
R99  | Pass
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
R127 | Failure [CPP-16647](https://youtrack.jetbrains.com/issue/CPP-16647)
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
R138 | Failure [CPP-16647](https://youtrack.jetbrains.com/issue/CPP-16647)
R139 | Pass
R140 | Pass
R141 | Pass
R142 | Pass
R143 | Pass
R144 | Pass
R145 | Pass
R146 | Pass
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
R157 | Failure [CPP-16649](https://youtrack.jetbrains.com/issue/CPP-16649)
R158 | Failure [CPP-16649](https://youtrack.jetbrains.com/issue/CPP-16649)
R159 | Pass
R160 | Pass
R161 | Pass
R162 | Failure [CPP-16649](https://youtrack.jetbrains.com/issue/CPP-16649)
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
R224 | Failure [CPP-16658](https://youtrack.jetbrains.com/issue/CPP-16658)
R225 | Pass
R226 | Failure [CPP-16658](https://youtrack.jetbrains.com/issue/CPP-16658)
R227 | Failure [CPP-16658](https://youtrack.jetbrains.com/issue/CPP-16658)
R228 | Pass
R229 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R230 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R231 | Pass
R232 | Pass
R233 | Pass
R234 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R235 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R236 | Pass
R237 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R238 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R239 | Pass
R240 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R241 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
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
R260 | Failure [CPP-16683](https://youtrack.jetbrains.com/issue/CPP-16683)
R261 | Pass
R262 | Failure [CPP-16683](https://youtrack.jetbrains.com/issue/CPP-16683)
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
R281 | Pass
R282 | Failure [CPP-16649](https://youtrack.jetbrains.com/issue/CPP-16649)
R283 | Pass
R284 | Pass
R285 | Pass
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
R320 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
R321 | Pass
R322 | Pass
R323 | Pass
R324 | Pass
R325 | Pass
R326 | Failure [CPP-16659](https://youtrack.jetbrains.com/issue/CPP-16659)
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
R432 | Failure [CPP-16690](https://youtrack.jetbrains.com/issue/CPP-16690)
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
R504 | Failure [CPP-16696](https://youtrack.jetbrains.com/issue/CPP-16696)
R505 | Failure [CPP-16696](https://youtrack.jetbrains.com/issue/CPP-16696)
R506 | Pass
R507 | Pass
R508 | Pass
R509 | Pass
R510 | Pass
R511 | Pass
R512 | Pass
R513 | Pass
R514 | Pass
R515 | Failure [CPP-16696](https://youtrack.jetbrains.com/issue/CPP-16696)
R516 | Pass
R517 | Pass
R518 | Pass
R519 | Pass
R520 | Pass
R521 | Pass
R522 | Failure [CPP-16696](https://youtrack.jetbrains.com/issue/CPP-16696)
R523 | Pass
R524 | Pass
R525 | Pass
R526 | Pass
R527 | Pass
R528 | Pass
R529 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R530 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R531 | Pass
R532 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R533 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R534 | Pass
R535 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R536 | Pass
R537 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R538 | Pass
R539 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R540 | Pass
R541 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R542 | Pass
R543 | Pass
R544 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R545 | Pass
R546 | Pass
R547 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R548 | Pass
R549 | Pass
R550 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R551 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R552 | Pass
R553 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R554 | Pass
R555 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R556 | Pass
R557 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
R558 | Pass
R559 | Failure [CPP-16699](https://youtrack.jetbrains.com/issue/CPP-16699)
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

## Reorder Parameters
Case| Result
--- | -----
RP1 | Failure (Not available) [CPP-16645](https://youtrack.jetbrains.com/issue/CPP-16645)
RP2 | Pass
RP3 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
RP4 | Failure [CPP-1915](https://youtrack.jetbrains.com/issue/CPP-1915)
RP5 | Pass
RP6 | Pass
RP7 | Failure (Not available) [CPP-16645](https://youtrack.jetbrains.com/issue/CPP-16645)
RP8 | Failure (Not available) [CPP-16645](https://youtrack.jetbrains.com/issue/CPP-16645)
RP9 | Failure (Not available) [CPP-16645](https://youtrack.jetbrains.com/issue/CPP-16645)

## Replace auto_ptr With unique_ptr
Case  | Result
----- | ------
RAWU1 | Pass
RAWU2 | Pass
RAWU3 | Pass
RAWU4 | Pass

## Replace If With Ternary
Case | Result
---- | ------
RIT1 | Pass
RIT2 | Failure (not available) [CPP-1944](https://youtrack.jetbrains.com/issue/CPP-1944)
RIT3 | Pass
RIT4 | Failure (not available) [CPP-1944](https://youtrack.jetbrains.com/issue/CPP-1944)
RIT5 | Pass
RIT6 | Pass
RIT7 | Pass
RIT8 | Pass
RIT9 | Failure [CPP-1945](https://youtrack.jetbrains.com/issue/CPP-1945)

## Replace Iterative For With Range For
Case   | Result
------ | ------
RIRF1  | Pass
RIRF2  | Failure (not available)
RIRF3  | Failure (not available)
RIRF4  | Pass
RIRF5  | Failure (not available)
RIRF6  | Failure (not available)
RIRF7  | Pass
RIRF8  | Failure (not available)
RIRF9  | Failure (not available)
RIRF10 | Pass
RIRF11 | Failure (not available)
RIRF12 | Failure (not available)
RIRF13 | Pass
RIRF14 | Failure (not available)
RIRF15 | Failure (not available)
RIRF16 | Pass
RIRF17 | Failure (not available)
RIRF18 | Failure (not available)
RIRF19 | Pass
RIRF20 | Failure (not available)
RIRF21 | Failure (not available)
RIRF22 | Pass
RIRF23 | Failure (not available)
RIRF24 | Failure (not available)
RIRF25 | Pass
RIRF26 | Failure (not available)
RIRF27 | Failure (not available)
RIRF28 | Pass
RIRF29 | Failure (not available)
RIRF30 | Failure (not available)
RIRF31 | Pass
RIRF32 | Failure (not available)
RIRF33 | Failure (not available)
RIRF34 | Pass
RIRF35 | Failure (not available)
RIRF36 | Failure (not available)
RIRF37 | Pass
RIRF38 | Failure (not available)
RIRF39 | Failure (not available)
RIRF40 | Pass
RIRF41 | Failure (not available)
RIRF42 | Failure (not available)
RIRF43 | Pass
RIRF44 | Failure (not available)
RIRF45 | Failure (not available)
RIRF46 | Pass
RIRF47 | Failure (not available)
RIRF48 | Failure (not available)
RIRF49 | Pass
RIRF50 | Failure (not available)
RIRF51 | Failure (not available)
RIRF52 | Failure (not available)
RIRF53 | Failure (not available)
RIRF54 | Pass
RIRF55 | Failure (not available)
RIRF56 | Pass
RIRF57 | Pass
RIRF58 | Failure (not available)
RIRF59 | Pass
RIRF60 | Pass
RIRF61 | Failure (not available)
RIRF62 | Pass
RIRF63 | Pass
RIRF64 | Failure (not available)
RIRF65 | Pass
RIRF66 | Pass
RIRF67 | Failure (not available)
RIRF68 | Failure (not available)

## Replace NULL/0 With nullptr
Case   | Result
------ | ------
RZNP1  | Pass
RZNP2  | Pass
RZNP3  | Pass
RZNP4  | Pass
RZNP5  | Pass
RZNP6  | Pass
RZNP7  | Pass
RZNP8  | Pass
RZNP9  | Pass
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
Case  | Result
----- | ------
RAW1  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW2  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW3  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW4  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW5  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW6  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW7  | Pass
RAW8  | Pass
RAW9  | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)
RAW10 | Failure [CPP-16674](https://youtrack.jetbrains.com/issue/CPP-16674)

## Replace Ternary With If
Case | Result
---- | ------
RTI1 | Pass
RTI2 | Failure [CPP-1946](https://youtrack.jetbrains.com/issue/CPP-1946)
RTI3 | Pass
RTI4 | Pass
RTI5 | Failure [CPP-1946](https://youtrack.jetbrains.com/issue/CPP-1946)
RTI6 | Pass
RTI7 | Pass
RTI8 | Pass
RTI9 | Pass

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
RTWA22 | Pass
RTWA23 | Pass
RTWA24 | Pass
RTWA25 | Pass
RTWA26 | Pass
RTWA27 | Pass
RTWA28 | Pass
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
SID2  | Failure [CPP-1947](https://youtrack.jetbrains.com/issue/CPP-1947)
SID3  | Pass
SID4  | Pass
SID5  | Pass
SID6  | Pass
SID7  | Pass
SID8  | Pass
SID9  | Pass
SID10 | Pass
SID11 | Failure (not available) [CPP-1948](https://youtrack.jetbrains.com/issue/CPP-1948)

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
