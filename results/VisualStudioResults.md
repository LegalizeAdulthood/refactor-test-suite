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
CS12 | 
CS13 | 
CS14 | 
CS15 | 
CS16 | 
CS17 | 
CS18 | 
CS19 | 
CS20 | 
CS21 | 
CS22 | 
CS23 | 
CS24 | 
CS25 | 
CS26 | 
CS27 | 
CS28 | 
CS29 | 
CS30 | 
CS31 | 
CS32 | 
CS33 | 
CS34 | 
CS35 | 
CS36 | 
CS37 | 
CS38 | 
CS39 | 
CS40 | 
CS41 | 
CS42 | 
CS43 | 
CS44 | 
CS45 | 

## Extract Function
Case | Result
---- | ------
EXF1  | Failure (data flow)
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
EXF14 | Pass
EXF15 | Pass
EXF16 | Failure (creates invalid code)
EXF17 | Pass
EXF18 | Failure (data flow)
EXF19 | Failure (creates invalid code)
EXF20 |

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
EM19 | Failure (data flow)
EM20 | Pass (unnecessary use of namespace)
EM21 | 

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
R70  | Failure (doesn't select correct instances)
R71  | Failure (doesn't select correct instances)
R72  | Failure (doesn't select correct instances)
R73  | Failure (doesn't select correct instances)
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
R91 | (deprecated)
R92 | (deprecated)
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
R108 | Failure (selects unrelated instances)
R109 | Failure (selects unrelated instances)
R110 | Failure (selects unrelated instances)
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
R146 | Failure (selects unrelated instances)
R147 | Failure (selects unrelated instances)
R148 | Failure (selects unrelated instances)
R149 | Pass
R150 | Failure (selects unrelated instances)
R151 | Pass
R152 | Pass
R153 | Pass
R154 | Failure (selects unrelated instances)
R155 | Pass
R156 | Failure (selects unrelated instances)
R157 | Pass
R158 | Pass
R159 | Failure (selects unrelated instances)
R160 | Pass
R161 | Pass
R162 | Pass
R163 | Failure (selects unrelated instances)
R164 | Failure (selects unrelated instances)
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
R236 | Failure (not all instances selected)
R237 | Pass
R238 | Pass
R239 | Failure (can't find definition)
R240 | Pass
R241 | Pass
R242 | Failure (selects unrelated instances)
R243 | Failure (selects unrelated instances)
R244 | Pass
R245 | Pass
R246 | Failure (selects unrelated instances)
R247 | Failure (selects unrelated instances)
R248 | Failure (selects unrelated instances)
R249 | Pass
R250 | Failure (selects unrelated instances)
R251 | Pass
R252 | Failure (selects unrelated instances)
R253 | Failure (selects unrelated instances)
R254 | Failure (selects unrelated instances)
R255 | Pass
R256 | Failure (selects unrelated instances)
R257 | Pass
R258 | Pass
R259 | Pass
R260 | Pass
R261 | Pass
R262 | Pass
R263 | Failure (selects unrelated instances)
R264 | Pass
R265 | Failure (selects unrelated instances)
R266 | Pass
R267 | Pass
R268 | Pass
R269 | Pass
R270 | Pass
R271 | Pass
R272 | Pass
R273 | Pass
R274 | Failure (selects unrelated instances)
R275 | Failure (selects unrelated instances)
R276 | Failure (selects unrelated instances)
R277 | Pass
R278 | Pass
R279 | Failure (selects unrelated instances)
R280 | Pass
R281 | Pass
R282 | Pass
R283 | Pass
R284 | Pass
R285 | Pass
R286 | Pass
R287 | Failure (selects unrelated instances)
R288 | Failure (not all instances selected)
R289 | Failure (selects unrelated instances)
R290 | Failure (can't find definition)
R291 | Failure (selects unrelated instances)
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
R376 | Failure (selects unrelated instances)
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
R416 | Failure (selects unrelated instances)
R417 | Failure (selects unrelated instances)
R418 | Pass
R419 | Failure (selects unrelated instances)
R420 | Pass
R421 | Failure (selects unrelated instances)
R422 | Pass
R423 | Pass
R424 | Pass
R425 | Pass
R426 | Pass
R427 | Pass
R428 | Pass
R429 | Failure (not all instances selected)
R430 | Failure (can't find definition)
R431 | Failure (can't find definition)
R432 | Pass
R433 | Failure (not all instances selected)
R434 | Failure (not all instances selected)
R435 | Failure (not all instances selected)
R436 | Failure (not all instances selected)
R437 | Failure (not all instances selected)
R438 | Pass
R439 | Pass
R440 | Pass
R441 | Pass
R442 | Pass
R443 | Pass
R444 | Failure (not all instances selected)
R445 | Failure (not all instances selected)
R446 | Failure (not all instances selected)
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
R526 | Failure (selects unrelated instances)
R527 | Failure (pops up symbol dialog)
R528 | Failure (fails to select all instances)
R529 | Pass
R530 | Pass
R531 | Failure (fails to select all instances)
R532 | Pass
R533 | Pass
R534 | Failure (fails to select all instances)
R535 | Pass
R536 | Failure (fails to select all instances)
R537 | Pass
R538 | Failure (fails to select all instances)
R539 | Pass
R540 | Failure (fails to select all instances)
R541 | Pass
R542 | Failure (selects unrelated instances)
R543 | Pass
R544 | Failure (fails to select all instances)
R545 | Failure (selects unrelated instances)
R546 | Failure (selects unrelated instances)
R547 | Failure (fails to select all instances)
R548 | Failure (selects unrelated instances)
R549 | Pass
R550 | Failure (fails to select all instances)
R551 | Failure (fails to select all instances)
R552 | Pass
R553 | Failure (fails to rename selected instance)
R554 | Pass
R555 | Failure (fails to rename selected instance)
R556 | Pass
R557 | Failure (fails to rename selected instance)
R558 | Pass
R559 | Failure (fails to rename selected instance)
R560 | Failure (selects unrelated instances)
R561 | Failure (selects unrelated instances)
R562 | (deprecated)
R563 | Pass
R564 | Failure (selects unrelated instances)
R565 | Failure (use in decltype not selected)
R566 | Failure (selects unrelated instances)
R567 | Failure (use in decltype not selected)
R568 | Failure (selects unrelated instances)
R569 | Failure (selects unrelated instances)
R570 | Pass
R571 | Failure (use in decltype not selected)
R572 | Failure (use in decltype not selected)
R573 | Failure (selects unrelated instances)
R574 | Failure (selects unrelated instances)
R575 | Pass
R576 | Failure (selects unrelated instances)
R577 | Failure (selects unrelated instances)
R578 | Failure (selects unrelated instances)
R579 | Pass
R580 | Failure (selects unrelated instances)
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
