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
AP1 | Failure (error occured while applying changes; Value does not fall within expected range)
AP2 | Pass
AP3 | Failure (changes unrelated overloads; disregards dialog selection)
AP4 | Failure (changes unrelated overloads; disregards dialog selection)
AP5 | Pass
AP6 | Pass
AP7 | Failure (c'tor usages not updated)
AP8  | Pass
AP9  | Pass
AP10  | Pass
AP11  | Pass
AP12  | Pass
AP13  | Pass
AP14  | Pass
AP15  | Failure (definition not updated)
AP16  | Pass
AP17 | Pass
AP18 | Pass
AP19 | Pass
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Failure (unrelated code changed)
AP25 | Failure (not available)
AP26 | Failure (c'tor usages not updated)
AP27 | Pass
AP28 | Pass
AP29 | Pass
AP30 | Pass
AP31 | Pass
AP32 | Failure (default value on definition, not declaration)
AP33 | Pass
AP34 | Pass
AP35 | Pass
AP36 | Failure (definition not updated)
AP37 | Pass
AP38 | Failure (default value on definition, not declaration)
AP39 | Pass
AP40 | Pass
AP41 | Failure (c'tor usages not updated)
AP42 | Pass
AP43 | Pass
AP44 | Pass
AP45 | Pass
AP46 | Pass
AP47 | Pass
AP48 | Pass
AP49 | Pass
AP50 | Failure (definition not updated)
AP51 | Pass
AP52 | Failure (default value on definition, not declaration)
AP53 | Pass
AP54 | Pass
AP55 | Failure (c'tor usages not updated)
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
AP69 | Failure (c'tor usages not updated)
AP70 | Pass
AP71 | Failure (c'tor usages not updated)
AP72 | Pass
AP73 | Pass
AP74 | Pass
AP75 | Pass
AP76 | Pass
AP77 | Pass
AP78 | Pass
AP79 | Failure (template usages not updated)
AP80 | Failure (template usages not updated)
AP81 | Failure (declaration not updated)
AP82 | Pass
AP83 | Failure (changes unrelated overloads; disregards dialog selection)
AP84 | Failure (changes unrelated overloads; disregards dialog selection)
AP85 | Pass
AP86 | Pass
AP87 | Pass
AP88 | Failure (error occured while applying changes; Value does not fall within expected range)
AP89 | Failure (error occured while applying changes; textIndex out of range)
AP90 | Failure (changes unrelated overloads)
AP91 | Failure (changes unrelated overloads)
AP92 | Pass
AP93 | Pass
AP94 | Pass
AP95 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP96 | Pass
AP97 | Pass
AP98 | Failure (declaration not updated)
AP99 | Pass
AP100 | Pass
AP101 | Pass
AP102 | Pass
AP103 | Pass
AP104 | Failure (error occured while applying changes; Value does not fall within expected range)
AP105 | Failure (error occured while applying changes; Value does not fall within expected range)
AP106 | Pass
AP107 | Failure (error occured while applying changes; Value does not fall within expected range)
AP108 | Pass
AP109 | Pass
AP110 | Failure (default value on definition, not declaration)
AP111 | Pass
AP112 | Failure (default value on definition, not declaration)
AP113 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP114 | Pass
AP115 | Pass
AP116 | Pass
AP117 | Pass
AP118 | Failure (declaration not updated)
AP119 | Pass
AP120 | Failure (default value on definition, not declaration)
AP121 | Pass
AP122 | Failure (default value on definition, not declaration)
AP123 | Pass
AP124 | Pass
AP125 | Pass
AP126 | Failure (error occured while applying changes; Value does not fall within expected range)
AP127 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP128 | Failure (error occured while applying changes; Value does not fall within expected range)
AP129 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP130 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP131 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP132 | Failure (error occured while applying changes; Value does not fall within expected range)
AP133 | Failure (error occured while applying changes; Value does not fall within expected range)
AP134 | Pass
AP135 | Pass
AP136 | Failure (error occured while applying changes; Value does not fall within expected range)
AP137 | Failure (declaration not updated)
AP138 | Pass
AP139 | Failure (changes unrelated overloads; disregards dialog selection)
AP140 | Failure (changes unrelated overloads; disregards dialog selection)
AP141 | Pass
AP142 | Pass
AP143 | Pass
AP144 | Pass
AP145 | Pass
AP146 | Failure (declaration not updated)
AP147 | Pass
AP148 | Pass
AP149 | Pass
AP150 | Pass
AP151 | Failure (default value on definition, not declaration)
AP152 | Failure (declaration not updated)
AP153 | Pass
AP154 | Failure (default value on definition, not declaration)
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
AP169 | Failure (declarations not updated; not all usages updated)
AP170 | Failure (declarations not updated; not all usages updated)
AP171 | Failure (declarations not updated; not all usages updated)
AP172 | Failure (declarations not updated; not all usages updated)
AP173 | Failure (declarations not updated; not all usages updated)
AP174 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP175 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP176 | Pass
AP177 | Pass
AP178 | Pass
AP179 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP180 | Pass
AP181 | Failure (declaration not updated)
AP182 | Pass
AP183 | Pass
AP184 | Pass
AP185 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP186 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP187 | Pass
AP188 | Pass
AP189 | Pass
AP190 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP191 | Pass
AP192 | Failure (error occured while applying changes; Value does not fall within expected range)
AP193 | Pass
AP194 | Pass
AP195 | Pass
AP196 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP197 | Failure (error occured while applying changes; Object reference not set to an instance of an object)
AP198 | Pass
AP199 | Pass
AP200 | Pass
AP201 | Failure (declaration not updated)
AP202 | Pass

## Change Signature
Case | Result
---- | ------
CS1  | Failure (instances not renamed)
CS2  | Failure (instances not renamed)
CS3  | Failure (not available)
CS4  | Pass
CS5  | Pass
CS6  | Pass
CS7  | Failure (instances not renamed)
CS8  | Failure (instances not renamed)
CS9  | Failure (not available)
CS10 | Pass
CS11 | Pass
CS12 | Failure (instances not renamed)
CS13 | Failure (instances not renamed)
CS14 | Failure (not available)
CS15 | Pass
CS16 | Failure (not available)
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
EXF18 | Failure (not available)
EXF19 | Pass

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Failure (not available)
EM3 | Pass
EM4 | Pass (unnecessary use of namespace)
EM5 | Pass (unnecessary use of namespace)
EM6 | Pass (unnecessary use of namespace)
EM7 | Pass (unnecessary use of namespace)
EM8 | Pass (unnecessary use of namespace)
EM9 | Pass
EM10 | Pass
EM11 | Pass
EM12 | Pass
EM13 | Failure (creates invalid code)
EM14 | Pass (unnecessary use of namespace)
EM15 | Pass
EM16 | Pass
EM17 | Pass
EM18 | Pass
EM19 | Failure (creates invalid code)
EM20 | Pass
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
R1  | Pass
R2  | Failure (not available)
R3  | Failure (not available)
R4  | Pass
R5   | Pass
R6   | Pass
R7  | Pass
R8  | Pass
R9  | Pass
R10   | Pass
R11   | Pass
R12   | Pass
R13   | Pass
R14   | Pass
R15   | Pass
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
R37  | Failure (selects unrelated instances, doesn't select all instances)
R38  | Failure (selects unrelated instances, doesn't select all instances)
R39  | Failure (selects unrelated instances, doesn't select all instances)
R40  | Failure (selects unrelated instances, doesn't select all instances)
R41  | Failure (selects unrelated instances, doesn't select all instances)
R42  | Failure (selects unrelated instances, doesn't select all instances)
R43  | Failure (selects unrelated instances, doesn't select all instances)
R44  | Failure (selects unrelated instances, doesn't select all instances)
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
R71 | Failure (selects unrelated instances)
R72 | Pass
R73 | Failure (selects unrelated instances)
R74 | Pass
R75 | Pass
R76 | Failure (selects unrelated instances)
R77 | Pass
R78 | Pass
R79 | Failure (selects unrelated instances)
R80 | Pass
R81 | Failure (selects unrelated instances)
R82 | Pass
R83 | Pass
R84 | Failure (selects unrelated instances)
R85 | Pass
R86 | Pass
R87 | Pass
R88 | Failure (fails to select all instances)
R89 | Failure (fails to select all instances)
R90 | Pass
R91 | Pass
R92 | Pass
R93 | Pass
R94 | Pass
R95 | Pass
R96 | Pass
R97 | Pass
R98 | Pass
R99 | Failure (fails to select all instances)
R100 | Pass
R101 | Pass
R102 | Pass
R103 | Pass
R104 | Pass
R105 | Pass
R106 | Failure (fails to select all instances)
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
R128 | Failure (fails to select all instances)
R129 | Pass
R130 | Pass
R131 | Failure (fails to select all instances)
R132 | Pass
R133 | Pass
R134 | Pass
R135 | Pass
R136 | Pass
R137 | Failure (fails to rename selected instance)
R138 | Pass
R139 | Failure (fails to rename selected instance)
R140 | Pass
R141 | Pass
R142 | Pass
R143 | Pass
R144 | Pass
R145 | Pass
R146 | Pass
R147 | Pass
R148 | Failure (use in decltype not selected)
R149 | Pass
R150 | Failure (use in decltype not selected)
R151 | Failure (selects unrelated instances)
R152 | Failure (selects unrelated instances)
R153 | Pass
R154 | Failure (use in decltype not selected)
R155 | Failure (use in decltype not selected)
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
R189  | Pass
R190  | Pass
R191  | Pass
R192  | Pass
R193  | Pass
R194  | Pass
R195  | Pass
R196  | Pass
R197  | Pass
R198  | Pass
R199  | Pass
R200  | Pass
R201  | Pass
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
R212  | Pass
R213  | Pass
R214  | Pass
R215  | Pass
R216  | Pass
R217  | Pass
R218  | Pass
R219  | Pass
R220  | Pass
R221  | Pass
R222  | Pass
R223  | Pass
R224  | Pass
R225  | Pass
R226  | Pass
R227  | Pass
R228  | Pass
R229  | Pass
R230  | Pass
R231  | Pass
R232  | Pass
R233  | Pass
R234  | Pass
R235  | Pass
R236  | Pass
R237  | Pass
R238  | Pass
R239  | Pass
R240  | Pass
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
R313 | Failure (action not enabled in dialog)
R314 | Pass
R315 | Failure (action not enabled in dialog)
R316 | Pass
R317 | Failure (action not enabled in dialog)
R318 | Pass
R319 | Failure (action not enabled in dialog)
R320 | Pass
R321 | Pass
R322 | Failure (action not enabled in dialog)
R323 | Pass
R324 | Pass
R325 | Failure (action not enabled in dialog)
R326 | Pass
R327 | Pass
R328 | Failure (action not enabled in dialog)
R329 | Pass
R330 | Pass
R331 | Failure (action not enabled in dialog)
R332 | Pass
R333 | Pass
R334 | Failure (action not enabled in dialog)
R335 | Pass
R336 | Pass
R337 | Failure (action not enabled in dialog)
R338 | Pass
R339 | Pass
R340 | Pass
R341 | Pass
R342 | Failure (action not enabled in dialog)
R343 | Pass
R344 | Pass
R345 | Pass
R346 | Pass
R347 | Failure (action not enabled in dialog)
R348 | Pass
R349 | Pass
R350 | Pass
R351 | Pass
R352 | Failure (action not enabled in dialog)
R353 | Pass
R354 | Pass
R355 | Pass
R356 | Pass
R357 | Failure (action not enabled in dialog)
R358 | Failure (action not enabled in dialog)
R359 | Failure (action not enabled in dialog)
R360 | Failure (action not enabled in dialog)
R361 | Failure (action not enabled in dialog)
R362 | Failure (action not enabled in dialog)
R363 | Failure (action not enabled in dialog)
R364 | Failure (action not enabled in dialog)
R365 | Failure (action not enabled in dialog)
R366 | Failure (action not enabled in dialog)
R367 | Failure (action not enabled in dialog)
R368 | Failure (action not enabled in dialog)
R369 | Failure (action not enabled in dialog)
R370 | Pass
R371 | Failure (not all instances selected)
R372 | Pass
R373 | Failure (not all instances selected)
R374 | Failure (selects incorrect instances)
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
R435 | Failure (not all instances selected)
R436 | Pass
R437 | Failure (does nothing)
R438 | Pass
R439 | Failure (not all instances selected)
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
R555 | Failure (not all instances selected)
R556 | Failure (not available)
R557 | Failure (not available)
R558 | Pass
R559 | Failure (not all instances selected)
R560 | Failure (not all instances selected)
R561 | Failure (not all instances selected)
R562 | Failure (not all instances selected)
R563 | Failure (not available)
R564 | Pass
R565 | Pass
R566 | Pass
R567 | Pass
R568 | Pass
R569 | Pass
R570 | Failure (not all instances selected)
R571 | Failure (not all instances selected)
R572 | Failure (not available)
R573 | Pass
R574 | Pass
R575 | Pass
R576 | Pass
R577 | Pass
R578 | Pass
R579 | Pass
R580 | Failure (selects wrong instances)
R581 | Pass
R582 | Failure (selects wrong instances)
R583 | Pass
R584 | Pass
R585 | Pass
R586 | Failure (selects wrong instances)
R587 | Pass
R588 | Failure (selects wrong instances)
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
R605 | Failure (usages not selected)
R606 | Pass
R607 | Pass
R608 | Pass
R609 | Pass
R610 | Pass
R611 | Failure (usages not selected)
R612 | Pass
R613 | Pass
R614 | Pass
R615 | Failure (usages not selected)
R616 | Pass
R617 | Pass
R618 | Pass
R619 | Pass
R620 | Failure (usages not selected)
R621 | Pass
R622 | Failure (usages not selected)
R623 | Failure (usages not selected)
R624 | Failure (usages not selected)
R625 | Failure (usages not selected)
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
R804 | Failure (doesn't select all usages)
R805 | Failure (doesn't select all usages)
R806 | Pass
R807 | Pass
R808 | Failure (doesn't select all usages)
R809 | Pass
R810 | Pass
R811 | Pass
R812 | Failure (doesn't select all usages)
R813 | Pass
R814 | Pass
R815 | Failure (doesn't select all usages)
R816 | Pass
R817 | Failure (doesn't select all usages)
R818 | Pass
R819 | Pass
R820 | Failure (doesn't select all usages)
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
R948 | Failure (doesn't select all usages)
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
R984 |
R985 |
R986 |
R987 |
R988 | Pass
R989 | Pass
R990 | Pass
R991 | Failure (doesn't select all instances)
R992 | Failure (not available)
R993 | Failure (not available)
R994 | Pass
R995 | Pass
R996 | Pass
R997 | Pass
R998 | Failure (doesn't select all instances)
R999 | Pass
R1000 | Failure (doesn't select all instances)
R1001 | Failure (not available)
R1002 | Failure (not available)
R1003 | Pass
R1004 | Pass
R1005 | Pass
R1006 | Pass
R1007 | Pass
R1008 | Pass
R1009 | Pass
R1010 | Pass
R1011 | Pass
R1012 | Pass
R1013 | Pass
R1014 | Pass
R1015 | Pass
R1016 | Pass
R1017 | Pass
R1018 | Pass
R1019 | Pass
R1020 | Pass
R1021 | Pass
R1022 | Pass
R1023 | Pass
R1024 | Pass
R1025 | Pass
R1026 | Pass
R1027 | Pass
R1028 | Pass
R1029 | Pass
R1030 | Pass
R1031 | Pass
R1032 | Pass
R1033 | Pass
R1034 | Pass
R1035 | Pass
R1036 | Pass
R1037 | Pass
R1038 | Pass
R1039 | Pass
R1040 | Pass
R1041 | Pass
R1042 | Pass
R1043 | Pass
R1044 | Pass
R1045 | Pass
R1046 | Pass
R1047 | Pass
R1048 | Pass
R1049 | Pass
R1050 | Pass
R1051 | Pass
R1052 | Pass
R1053 | Pass
R1054 | Pass
R1055 | Pass
R1056 | Pass
R1057 | Pass
R1058 | Pass
R1059 | Pass
R1060 | Pass
R1061 | Pass
R1062 | Pass
R1063 | Pass
R1064 | Pass
R1065 | Pass
R1066 | Pass
R1067 | Pass
R1068 | Pass
R1069 | Pass
R1070 | Pass
R1071 | Pass
R1072 | Pass
R1073 | Pass
R1074 | Pass
R1075 | Pass
R1076 | Pass
R1077 | Pass
R1078 | Pass
R1079 | Pass
R1080 | Pass
R1081 | Pass
R1082 | Pass
R1083 | Pass
R1084 | Pass
R1085 | Pass
R1086 | Pass
R1087 | Pass
R1088 | Pass
R1089 | Pass
R1090 | Pass
R1091 | Failure (doesn't select all instances)
R1092 | Pass
R1093 | Failure (doesn't select all instances)
R1094 | Failure (not available)
R1095 | Failure (not available)
R1096 | Failure (doesn't select all instances)
R1097 | Failure (doesn't select all instances)
R1098 | Pass 
R1099 | Pass
R1100 | Pass
R1101 | Pass
R1102 | Pass
R1103 | Failure (doesn't select all instances)
R1104 | Pass
R1105 | Failure (doesn't select all instances)
R1106 | Failure (not available)
R1107 | Failure (not available)
R1108 | Pass
R1109 | Pass
R1110 | Pass
R1111 | Failure (doesn't select all instances)
R1112 | Failure (doesn't select all instances)
R1113 | Pass
R1114 | Pass
R1115 | Pass
R1116 | Pass
R1117 | Pass
R1118 | Pass
R1119 | Pass
R1120 | Pass
R1121 | Pass
R1122 | Failure (doesn't select all instances)
R1123 | Pass
R1124 | Failure (doesn't select all instances)
R1125 | Failure (not available)
R1126 | Failure (not available)
R1127 | Failure (doesn't select all instances)
R1128 | Failure (doesn't select all instances)
R1129 | Pass
R1130 | Pass
R1131 | Pass
R1132 | Pass
R1133 | Pass
R1134 | Failure (doesn't select all instances)
R1135 | Pass
R1136 | Failure (doesn't select all instances)
R1137 | Failure (not available)
R1138 | Failure (not available)
R1139 | Pass
R1140 | Pass
R1141 | Pass
R1142 | Pass
R1143 | Failure (doesn't select all instances)
R1144 | Failure (doesn't select all instances)
R1145 | Pass
R1146 | Pass
R1147 | Pass
R1148 | Pass
R1149 | Pass
R1150 | Pass
R1151 | Pass
R1152 | Pass
R1153 | Pass
R1154 | Failure (doesn't select all instances)
R1155 | Pass
R1156 | Failure (doesn't select all instances)
R1157 | Failure (not available)
R1158 | Failure (not available)
R1159 | Failure (doesn't select all instances)
R1160 | Failure (doesn't select all instances)
R1161 | Pass
R1162 | Pass
R1163 | Pass
R1164 | Pass
R1165 | Pass
R1166 | Failure (doesn't select all instances)
R1167 | Pass
R1168 | Failure (doesn't select all instances)
R1169 | Failure (not available)
R1170 | Failure (not available)
R1171 | Pass
R1172 | Pass
R1173 | Pass
R1174 | Pass
R1175 | Failure (doesn't select all instances)
R1176 | Failure (doesn't select all instances)
R1177 | Pass
R1178 | Pass
R1179 | Pass
R1180 | Pass
R1181 | Pass
R1182 | Pass
R1183 | Pass
R1184 | Pass
R1185 | Pass
R1186 | Pass
R1187 | Failure (doesn't select all instances)
R1188 | Pass
R1189 | Failure (doesn't select all instances)
R1190 | Failure (not available)
R1191 | Failure (not available)
R1192 | Failure (doesn't select all instances)
R1193 | Failure (doesn't select all instances)
R1194 | Pass
R1195 | Pass
R1196 | Pass
R1197 | Pass
R1198 | Pass
R1199 | Failure (doesn't select all instances)
R1200 | Pass
R1201 | Failure (doesn't select all instances)
R1202 | Failure (not available)
R1203 | Failure (not available)
R1204 | Pass
R1205 | Pass
R1206 | Pass
R1207 | Pass
R1208 | Pass
R1209 | Failure (doesn't select all instances)
R1210 | Failure (doesn't select all instances)
R1211 | Pass
R1212 | Pass
R1213 | Pass
R1214 | Pass
R1215 | Pass
R1216 | Pass
R1217 | Pass
R1218 | Pass
R1219 | Pass
R1220 | Pass
R1221 | Pass
R1222 | Pass
R1223 | Pass
R1224 | Pass
R1225 | Pass
R1226 | Pass
R1227 | Pass
R1228 | Pass
R1229 | Pass
R1230 | Pass
R1231 | Pass
R1232 | Pass
R1233 | Pass
R1234 | Pass
R1235 | Pass
R1236 | Pass
R1237 | Pass
R1238 | Pass
R1239 | Pass
R1240 | Pass
R1241 | Pass
R1242 | Pass
R1243 | Pass
R1244 | Pass
R1245 | Pass
R1246 | Pass
R1247 | Pass
R1248 | Pass
R1249 | Pass
R1250 | Pass
R1251 | Pass
R1252 | Pass
R1253 | Pass
R1254 | Pass
R1255 | Pass
R1256 | Pass
R1257 | Pass
R1258 | Pass
R1259 | Pass
R1260 | Pass
R1261 | Pass
R1262 | Pass
R1263 | Pass
R1264 | Pass
R1265 | Pass
R1266 | Pass
R1267 | Pass
R1268 | Pass
R1269 | Pass
R1270 | Pass
R1271 | Pass
R1272 | Pass
R1273 | Pass
R1274 | Pass
R1275 | Pass
R1276 | Pass
R1277 | Pass
R1278 | Pass
R1279 | Pass
R1280 | Pass
R1281 | Pass
R1282 | Pass
R1283 | Pass
R1284 | Pass
R1285 | Pass
R1286 | Pass
R1287 | Pass
R1288 | Pass
R1289 | Pass
R1290 | Pass
R1291 | Pass
R1292 | Pass
R1293 | Pass
R1294 | Pass
R1295 | Pass
R1296 | Pass
R1297 | Pass
R1298 | Pass
R1299 | Pass
R1300 | Pass
R1301 | Pass
R1302 | Pass
R1303 | Pass
R1304 | Pass
R1305 | Pass
R1306 | Pass
R1307 | Pass
R1308 | Pass
R1309 | Pass
R1310 | Pass
R1311 | Pass
R1312 | Pass
R1313 | Pass
R1314 | Pass
R1315 | Pass
R1316 | Pass
R1317 | Pass
R1318 | Pass
R1319 | Pass
R1320 | Pass
R1321 | Pass
R1322 | Pass
R1323 | Pass
R1324 | Pass
R1325 | Pass
R1326 | Pass
R1327 | Pass
R1328 | Pass
R1329 | Pass
R1330 | Pass
R1331 | Pass
R1332 | Pass
R1333 | Pass
R1334 | Pass
R1335 | Pass
R1336 | Pass
R1337 | Pass
R1338 | Pass
R1339 | Pass
R1340 | Pass
R1341 | Pass
R1342 | Pass
R1343 | Pass
R1344 | Failure (doesn't select all instances)
R1345 | Pass
R1346 | Failure (doesn't select all instances)
R1347 | Failure (not available)
R1348 | Failure (not available)
R1349 | Failure (doesn't select all instances)
R1350 | Failure (doesn't select all instances)
R1351 | Pass
R1352 | Pass
R1353 | Pass
R1354 | Pass
R1355 | Pass
R1356 | Pass
R1357 | Pass
R1358 | Failure (doesn't select all instances)
R1359 | Pass
R1360 | Failure (doesn't select all instances)
R1361 | Failure (not available)
R1362 | Failure (not available)
R1363 | Failure (doesn't select all instances)
R1364 | Failure (doesn't select all instances)
R1365 | Pass
R1366 | Pass
R1367 | Pass
R1368 | Pass
R1369 | Pass
R1370 | Pass
R1371 | Pass
R1372 | Failure (doesn't select all instances)
R1373 | Pass
R1374 | Failure (doesn't select all instances)
R1375 | Failure (not available)
R1376 | Failure (not available)
R1377 | Failure (doesn't select all instances)
R1378 | Failure (doesn't select all instances)
R1379 | Pass
R1380 | Pass
R1381 | Pass
R1382 | Pass
R1383 | Pass
R1384 | Pass
R1385 | Pass
R1386 | Pass
R1387 | Failure (doesn't select all instances)
R1388 | Pass
R1389 | Failure (doesn't select all instances)
R1390 | Failure (not available)
R1391 | Failure (not available)
R1392 | Failure (doesn't select all instances)
R1393 | Failure (doesn't select all instances)
R1394 | Pass
R1395 | Pass
R1396 | Pass
R1397 | Pass
R1398 | Pass
R1399 | Pass
R1400 | Pass
R1401 | Pass
R1402 | Failure (doesn't select all instances)
R1403 | Pass
R1404 | Failure (doesn't select all instances)
R1405 | Failure (not available)
R1406 | Failure (not available)
R1407 | Failure (doesn't select all instances)
R1408 | Failure (doesn't select all instances)
R1409 | Pass
R1410 | Pass
R1411 | Pass
R1412 | Pass
R1413 | Pass
R1414 | Pass
R1415 | Pass
R1416 | Pass
R1417 | Failure (doesn't select all instances)
R1418 |
R1419 | Failure (doesn't select all instances)
R1420 | Failure (not available)
R1421 | Failure (not available)
R1422 | Failure (doesn't select all instances)
R1423 | Failure (doesn't select all instances)
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
R1576 |

## Reorder Parameters
Case | Result
---- | ------
RP1  | Failure (error occured while applying changes; Value does not fall within expected range)
RP2  | Failure (error occured while applying changes; textIndex out of range)
RP3  | Failure (error occured while applying changes; Value does not fall within expected range)
RP4  | Failure (error occured while applying changes; textIndex out of range)
RP5  | Failure (error occured while applying changes; Value does not fall within expected range)

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
RAW11 | Pass
RAW12 | Pass
