# Visual Studio

Home: [Visual Studio 2022](http://www.visualstudio.com/)

Version: Microsoft Visual Studio Community 2022, Version 17.7.5

Notes:
* All extensions that can provide refactorings, such as ReSharper for C++,
  are disabled while testing to ensure that only core Visual Studio refactoring
  capabilities are tested.
* Intellisense must be enabled for most refactorings to work properly.
* When applying an operation, the default selections on any prompting dialogs
  were used.

  Getting the default selection correct for a refactoring is important,
  particularly when changing a name that is used in thousands of places.
  Making the developer manually resolve which identical text is actually a
  related name makes the developer act like a compiler.  The compiler already
  knows which names refer to the same thing by using the context of the names.
  Any refactoring tool worth using has to employ the same logic as the compiler
  to correctly resolve names.  In other words, a refactoring tool has to be at
  least as smart as a compiler.

  If the correct instances of a name can't be selected by a refactoring tool,
  then you might as well use Find/Replace across a file set.
* Change locations to files are listed in the *Visual C++ Refactoring* tab of the Output pane.
* **Add Block Delimiter** is available by selecting a block of code and typing `{`.
* **Add Parameter** is available through **Change Signature**.
* **Move Implementation to Source File** is available as **Move Definition
  Location**.
* **Remove Unused Parameters** is available through **Change Signature**, but the unused
  parameters are not indicated visually in the IDE.
* **Reorder Parameters** is available through **Change Signature**.
* **Replace String Literal WIth Raw String Literal** is available through the action *Edit.ConvertToRawStringLiteral*.
* In general, bugs reported against Visual Studio refactoring functionality get closed with no action taken.
  Not a single bug reported in 2017 was marked as fixed, although some test cases now pass.

<hr/>

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
AP8  | Failure (definition not updated)
AP9  | Pass
AP10 | Pass
AP11 | Pass
AP12 | Failure (unrelated code changed)
AP13 | Failure (declaration not updated)
AP14 | Pass
AP15 | Failure (changes unrelated overloads; disregards dialog selection)
AP16 | Failure (changes unrelated overloads; disregards dialog selection)
AP17 | Pass
AP18 | Pass
AP19 | Pass
AP20 | Pass
AP21 | Pass
AP22 | Failure (declaration not updated)
AP23 | Pass
AP24 | Failure (template usages not updated)
AP25 | Failure (not available)
AP26 | Failure (template usages not updated)
AP27 | Failure (error occured while applying changes; Value does not fall within expected range)
AP28 | Pass
AP29 | Failure (changes unrelated overloads; disregards dialog selection)
AP30 | Failure (changes unrelated overloads; disregards dialog selection)
AP31 | Pass
AP32 | Pass
AP33 | Failure (c'tor usages not updated)
AP34 | Pass
AP35 | Pass
AP36 | Pass
AP37 | Pass
AP38 | Pass
AP39 | Failure (c'tor usages not updated)
AP40 | Pass
AP41 | Pass
AP42 | Pass
AP43 | Pass
AP44 | Pass
AP45 | Failure (default value on definition, not declaration)
AP46 | Pass
AP47 | Pass
AP48 | Pass
AP49 | Failure (definition not updated)
AP50 | Pass
AP51 | Failure (default value on definition, not declaration)
AP52 | Pass
AP53 | Pass
AP54 | Failure (c'tor usages not updated)
AP55 | Pass
AP56 | Pass
AP57 | Pass
AP58 | Pass
AP59 | Pass
AP60 | Pass
AP61 | Pass
AP62 | Pass
AP63 | Failure (definition not updated)
AP64 | Pass
AP65 | Failure (default value on definition, not declaration)
AP66 | Pass
AP67 | Pass
AP68 | Failure (c'tor usages not updated)
AP69 | Pass
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
AP82 | Failure (c'tor usages not updated)
AP83 | Pass
AP84 | Failure (c'tor usages not updated)
AP85 | Pass
AP86 | Failure (declaration not updated)
AP87 | Pass
AP88 | Failure (changes unrelated overloads; disregards dialog selection)
AP89 | Failure (changes unrelated overloads; disregards dialog selection)
AP90 | Pass
AP91 | Pass
AP92 | Pass
AP93 | Failure (error occured while applying changes; Value does not fall within expected range)
AP94 | Failure (error occured while applying changes; textIndex out of range)
AP95 | Failure (changes unrelated overloads)
AP96 | Failure (changes unrelated overloads)
AP97 | Pass
AP98 | Pass
AP99 | Pass
AP100 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP101 | Pass
AP102 | Pass
AP103 | Failure (declaration not updated)
AP104 | Pass
AP105 | Pass
AP106 | Pass
AP107 | Pass
AP108 | Pass
AP109 | Failure (error occured while applying changes; Value does not fall within expected range)
AP110 | Failure (error occured while applying changes; Value does not fall within expected range)
AP111 | Pass
AP112 | Failure (error occured while applying changes; Value does not fall within expected range)
AP113 | Pass
AP114 | Pass
AP115 | Failure (default value on definition, not declaration)
AP116 | Pass
AP117 | Failure (default value on definition, not declaration)
AP118 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP119 | Pass
AP120 | Pass
AP121 | Pass
AP122 | Pass
AP123 | Failure (declaration not updated)
AP124 | Pass
AP125 | Failure (default value on definition, not declaration)
AP126 | Pass
AP127 | Failure (default value on definition, not declaration)
AP128 | Pass
AP129 | Pass
AP130 | Pass
AP131 | Failure (error occured while applying changes; Value does not fall within expected range)
AP132 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP133 | Failure (error occured while applying changes; Value does not fall within expected range)
AP134 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP135 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP136 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP137 | Failure (error occured while applying changes; Value does not fall within expected range)
AP138 | Failure (error occured while applying changes; Value does not fall within expected range)
AP139 | Pass
AP140 | Pass
AP141 | Failure (error occured while applying changes; Value does not fall within expected range)
AP142 | Pass
AP143 | Pass
AP144 | Pass
AP145 | Failure (default value on definition, not declaration)
AP146 | Failure (declaration not updated)
AP147 | Pass
AP148 | Failure (default value on definition, not declaration)
AP149 | Pass
AP150 | Failure (declarations not updated; not all usages updated)
AP151 | Failure (declarations not updated; not all usages updated)
AP152 | Failure (declarations not updated; not all usages updated)
AP153 | Failure (declarations not updated; not all usages updated)
AP154 | Failure (declarations not updated; not all usages updated)
AP155 | Failure (declarations not updated; not all usages updated)
AP156 | Failure (declarations not updated; not all usages updated)
AP157 | Failure (declarations not updated; not all usages updated)
AP158 | Failure (declarations not updated; not all usages updated)
AP159 | Failure (declarations not updated; not all usages updated)
AP160 | Failure (declarations not updated; not all usages updated)
AP161 | Failure (declarations not updated; not all usages updated)
AP162 | Failure (declarations not updated; not all usages updated)
AP163 | Failure (declarations not updated; not all usages updated)
AP164 | Failure (declarations not updated; not all usages updated)
AP165 | Failure (declarations not updated; not all usages updated)
AP166 | Failure (declarations not updated; not all usages updated)
AP167 | Failure (declarations not updated; not all usages updated)
AP168 | Failure (declarations not updated; not all usages updated)
AP169 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP170 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP171 | Pass
AP172 | Pass
AP173 | Pass
AP174 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP175 | Pass
AP176 | Failure (declaration not updated)
AP177 | Pass
AP178 | Pass
AP179 | Pass
AP180 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP181 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP182 | Pass
AP183 | Pass
AP184 | Pass
AP185 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP186 | Pass
AP187 | Failure (error occured while applying changes; Value does not fall within expected range)
AP188 | Pass
AP189 | Pass
AP190 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP191 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP192 | Pass
AP193 | Pass
AP194 | Pass
AP195 | Failure (declaration not updated)
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
CS1  | Failure (instances not renamed)
CS2  | Failure (instances not renamed)
CS3  | Failure (unavailable)
CS4  | Pass
CS5  | Pass
CS6  | Pass
CS7  | Failure (instances not renamed)
CS8  | Failure (instances not renamed)
CS9  | Failure (unavailable)
CS10 | Pass
CS11 | Pass
CS12 | Failure (instances not renamed)
CS13 | Failure (instances not renamed)
CS14 | Failure (unavailable)
CS15 | Pass
CS16 | Failure (unavailable)
CS17 | Failure (instances not renamed)
CS18 | Failure (instances not renamed)
CS19 | Pass
CS20 | Failure (not available)
CS21 | Failure (instances not renamed)
CS22 | Failure (instances not renamed)
CS23 | Failure (not available)
CS24 | Pass
CS25 | Pass
CS26 | Failure (instances not renamed)
CS27 | Failure (instances not renamed)
CS28 | Failure (not available)
CS29 | Pass
CS30 | Failure (not available)
CS31 | Failure (instances not renamed)
CS32 | Failure (instances not renamed)
CS33 | Failure (not available)
CS34 | Pass
CS35 | Pass
CS36 | Failure (instances not renamed)
CS37 | Failure (instances not renamed)
CS38 | Failure (not available)
CS39 | Pass
CS40 | Pass
CS41 | Failure (instances not renamed)
CS42 | Failure (instances not renamed)
CS43 | Failure (not available)
CS44 | Pass
CS45 | Pass

## Extract Function
Case | Result
---- | ------
EXF1  | Failure (not available)
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
EXF13 | Failure (references typedef before it is declared)
EXF14 | Failure (references class before it is declared)
EXF15 | Failure (references typedef before it is declared)
EXF16 | Failure (references class before it is declared)
EXF17 | Failure (references typedef before it is declared)
EXF18 | Failure (unavailable)
EXF19 | Pass

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Pass
EM3 | Pass (unnecessary use of namespace)
EM4 | Pass (unnecessary use of namespace)
EM5 | Pass (unnecessary use of namespace)
EM6 | Pass (unnecessary use of namespace)
EM7 | Pass
EM8 | Pass
EM9 | Pass
EM10 | Pass
EM11 | Failure (creates invalid code)
EM12 | Pass (unnecessary use of namespace)
EM13 | Pass
EM14 | Pass
EM15 | Pass
EM16 | Pass
EM17 | Failure (creates invalid code)
EM18 | Pass
EM19 | Failure (unavailable)
EM20 | Pass (unnecessary use of namespace)
EM21 | Pass

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass (leaves `inline` in header)
MISF2  | Failure (unknown error)
MISF3  | Pass (sensitive to cursor placement)
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
MISF16 | Failure (creates invalid code)
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure (creates invalid code)

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
R25  | Failure (not available)
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
R74  | Failure (selects unrelated instances, doesn't select all instances)
R75  | Failure (selects unrelated instances, doesn't select all instances)
R76  | Failure (selects unrelated instances, doesn't select all instances)
R77  | Failure (selects unrelated instances, doesn't select all instances)
R78  | Failure (selects unrelated instances, doesn't select all instances)
R79  | Failure (selects unrelated instances, doesn't select all instances)
R80  | Failure (selects unrelated instances, doesn't select all instances)
R81  | Failure (selects unrelated instances, doesn't select all instances)
R82  | Pass
R83  | Pass
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
R99  | Failure (not available)
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
R157 | Pass
R158 | Pass
R159 | Pass
R160 | Pass
R161 | Pass
R162 | Pass
R163 | Pass
R164 | Pass
R165 | Pass
R166 | Failure (action not enabled in dialog)
R167 | Pass
R168 | Failure (action not enabled in dialog)
R169 | Failure (action not enabled in dialog)
R170 | Pass
R171 | Failure (action not enabled in dialog)
R172 | Failure (action not enabled in dialog)
R173 | Pass
R174 | Failure (action not enabled in dialog)
R175 | Failure (action not enabled in dialog)
R176 | Pass
R177 | Pass
R178 | Failure (action not enabled in dialog)
R179 | Failure (action not enabled in dialog)
R180 | Pass
R181 | Pass
R182 | Failure (action not enabled in dialog)
R183 | Failure (action not enabled in dialog)
R184 | Pass
R185 | Pass
R186 | Failure (action not enabled in dialog)
R187 | Failure (action not enabled in dialog)
R188 | Pass
R189 | Pass
R190 | Failure (action not enabled in dialog)
R191 | Failure (action not enabled in dialog)
R192 | Pass
R193 | Pass
R194 | Failure (action not enabled in dialog)
R195 | Failure (action not enabled in dialog)
R196 | Pass
R197 | Pass
R198 | Failure (action not enabled in dialog)
R199 | Failure (action not enabled in dialog)
R200 | Pass
R201 | Pass
R202 | Pass
R203 | Pass
R204 | Failure (action not enabled in dialog)
R205 | Failure (action not enabled in dialog)
R206 | Pass
R207 | Pass
R208 | Pass
R209 | Pass
R210 | Failure (action not enabled in dialog)
R211 | Failure (action not enabled in dialog)
R212 | Pass
R213 | Pass
R214 | Pass
R215 | Pass
R216 | Failure (action not enabled in dialog)
R217 | Failure (action not enabled in dialog)
R218 | Pass
R219 | Pass
R220 | Pass
R221 | Pass
R222 | Failure (action not enabled in dialog)
R223 | Pass
R224 | Failure (not all instances selected)
R225 | Pass
R226 | Failure (not all instances selected)
R227 | Failure (selects incorrect instances)
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
R281 | Pass
R282 | Pass
R283 | Pass
R284 | Pass
R285 | Pass
R286 | Pass
R287 | Pass
R288 | Failure (not all instances selected)
R289 | Pass
R290 | Failure (does nothing)
R291 | Pass
R292 | Failure (not all instances selected)
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
R429 | Failure (not all instances selected)
R430 | Failure (not available)
R431 | Failure (not available)
R432 | Pass
R433 | Failure (not all instances selected)
R434 | Failure (not all instances selected)
R435 | Failure (not all instances selected)
R436 | Failure (not all instances selected)
R437 | Failure (not available)
R438 | Pass
R439 | Pass
R440 | Pass
R441 | Pass
R442 | Pass
R443 | Pass
R444 | Failure (not all instances selected)
R445 | Failure (not all instances selected)
R446 | Failure (not available)
R447 | Pass
R448 | Pass
R449 | Pass
R450 | Pass
R451 | Pass
R452 | Pass
R453 | Pass
R454 | Failure (selects wrong instances)
R455 | Pass
R456 | Failure (selects wrong instances)
R457 | Pass
R458 | Pass
R459 | Pass
R460 | Failure (selects wrong instances)
R461 | Pass
R462 | Failure (selects wrong instances)
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
R487 | Failure (selects unrelated instances)
R488 | Pass
R489 | Failure (selects unrelated instances)
R490 | Pass
R491 | Pass
R492 | Failure (selects unrelated instances)
R493 | Pass
R494 | Pass
R495 | Failure (selects unrelated instances)
R496 | Pass
R497 | Failure (selects unrelated instances)
R498 | Pass
R499 | Pass
R500 | Failure (selects unrelated instances)
R501 | Pass
R502 | Pass
R503 | Pass
R504 | Failure (fails to select all instances)
R505 | Failure (fails to select all instances)
R506 | Pass
R507 | Pass
R508 | Pass
R509 | Pass
R510 | Pass
R511 | Pass
R512 | Pass
R513 | Pass
R514 | Pass
R515 | Failure (fails to select all instances)
R516 | Pass
R517 | Pass
R518 | Pass
R519 | Pass
R520 | Pass
R521 | Pass
R522 | Failure (fails to select all instances)
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
R544 | Failure (fails to select all instances)
R545 | Pass
R546 | Pass
R547 | Failure (fails to select all instances)
R548 | Pass
R549 | Pass
R550 | Pass
R551 | Pass
R552 | Pass
R553 | Failure (fails to rename selected instance)
R554 | Pass
R555 | Failure (fails to rename selected instance)
R556 | Pass
R557 | Pass
R558 | Pass
R559 | Pass
R560 | Pass
R561 | Pass
R562 | (deprecated)
R563 | Pass
R564 | Pass
R565 | Failure (use in decltype not selected)
R566 | Pass
R567 | Failure (use in decltype not selected)
R568 | Failure (selects unrelated instances)
R569 | Failure (selects unrelated instances)
R570 | Pass
R571 | Failure (use in decltype not selected)
R572 | Failure (use in decltype not selected)
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
R608 | Failure (usages not selected)
R609 | Pass
R610 | Failure (usages not selected)
R611 | Pass
R612 | Failure (usages not selected)
R613 | Failure (usages not selected)
R614 | Failure (usages not selected)
R615 | Failure (usages not selected)
R616 | Pass
R617 | Pass
R618 | Failure (usages not selected)
R619 | Pass
R620 | Failure (usages not selected)
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
R786 | Failure (doesn't select all usages)
R787 | Failure (doesn't select all usages)
R788 | Pass
R789 | Pass
R790 | Failure (doesn't select all usages)
R791 | Pass
R792 | Pass
R793 | Failure (doesn't select all usages)
R794 | Pass
R795 | Pass
R796 | Failure (doesn't select all usages)
R797 | Pass
R798 | Failure (doesn't select all usages)
R799 | Pass
R800 | Pass
R801 | Failure (doesn't select all usages)
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
R841 | Pass
R842 | Pass
R843 | Pass
R844 | Pass
R845 | Pass
R846 | Pass
R847 | Pass
R848 | Pass
R849 | Pass
R850 | Pass
R851 | Pass
R852 | Pass
R853 | Pass
R854 | Pass
R855 | Pass
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
R910 | Pass
R911 | Pass
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
R929 | Failure (doesn't select all usages)
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

## Reorder Parameters
Case | Result
---- | ------
RP1  | (deprecated)
RP2  | Failure (not available)
RP3  | Failure (selects wrong instances)
RP4  | Pass
RP5  | Failure (selects unrelated instances)
RP6  | Pass
RP7  | (deprecated)
RP8  | (deprecated)
RP9  | (deprecated)

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
