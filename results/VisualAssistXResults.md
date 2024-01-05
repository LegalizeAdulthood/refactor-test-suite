# Visual AssistX

Home: [Visual AssistX](http://www.wholetomato.com/)

Version: 10.5.1738.0, 10.8.2043.0

Notes:

* Version 10.8.2043.0 was used for Move Implementation to Source File testing.
* Visual AssistX performs Create Method Stub with Create Implementation From Usage.
* Visual AssistX provides the following [refactorings](https://www.wholetomato.com/features/feature-refactoring):
  * Change Signature
  * Convert Between Pointer and Instance
  * Encapsulate Field
  * Extract Method
  * Introduce Variable
  * Move Implementation to Header File
  * Move Implementation to Source File
  * Move Method Implementations to Source File
  * Move Selection to New File
  * Rename
  * Rename Files
  * Simplify Instance Declaration
* Visual AssistX provides the following refactorings Under [Code Generation](https://www.wholetomato.com/features/feature-code-generation)
  * Add Forward Declaration
  * Add Member
  * Add Missing Case Statements
  * Add Similar Member
  * Add Using Directive
  * Add Include Directive
  * Add/Remove Braces
  * Create Declaration
  * Create File
  * Create from Usage
  * Create Implementation
  * Create Method Implementations
  * Document Method
  * Implement Interface/Virtual Methods

<hr/>

## Change Signature
Case | Result
---- | ------
CS1 | Failure (not available)
CS2 | Failure (not available)
CS3 | Failure (not available)
CS4 | Failure (not available)
CS5 | Failure (not available)
CS6 | Failure (not available)
CS7 | Pass
CS8 | Pass
CS9 | Pass
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
CS31 | Failure (not available)
CS32 | Failure (not available)
CS33 | Failure (not available)
CS34 | Failure (not available)
CS35 | Failure (not available)
CS36 | Pass
CS37 | Pass
CS38 | Pass
CS39 | Pass
CS40 | Pass
CS41 | Failure (not available)
CS42 | Failure (not available)
CS43 | Failure (not available)
CS44 | Failure (not available)
CS45 | Failure (not available)

## Extract Function
Case | Result
---- | ------
EXF1 | Failure (creates invalid code)
EXF2 | Pass
EXF3 | Failure (changes meaning of code)
EXF4 | Pass
EXF5 | Pass
EXF6 | Pass
EXF7 | Failure (changes meaning of code)
EXF8 | Pass
EXF9 | Failure (changes meaning of code)
EXF10 | Pass
EXF11 | Pass
EXF12 | Failure (creates invalid code)
EXF13 | Failure (creates invalid code)
EXF14 | Failure (creates invalid code)
EXF15 | Failure (reads uninitialized data)
EXF16 | Failure (creates invalid code)
EXF17 | Failure (reads uninitialized data)
EXF18 | Failure (creates invalid code)
EXF19 | Failure (changes meaning of code)

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Failure (creates invalid code)
EM3 | Failure (creates invalid code)
EM4 | Pass (reads uninitialized memory)
EM5 | Failure (creates invalid code)
EM6 | Pass (reads uninitialized memory)
EM7 | Pass
EM8 | Failure (creates invalid code)
EM9 | Pass
EM10 | Pass
EM11 | Failure (creates invalid code)
EM12 | Pass
EM13 | Pass
EM14 | Pass
EM15 | Pass
EM16 | Pass
EM17 | Failure (creates invalid code)
EM18 | Pass
EM19 | Failure (creates invalid code)
EM20 | Failure (creates invalid code)
EM21 | Failure (changes meaning of code)

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Failure (loses namespace qualifier)
MISF2  | Failure (loses namespace qualifier)
MISF3  | Failure (loses namespace qualifier)
MISF4  | Failure (loses namespace qualifier)
MISF5  | Failure (loses namespace qualifier)
MISF6  | Failure (loses namespace qualifier)
MISF7  | Failure (loses namespace qualifier)
MISF8  | Pass
MISF9  | Failure (loses namespace qualifier)
MISF10 | Pass
MISF11 | Failure (loses namespace qualifier)
MISF12 | Failure (loses namespace qualifier)
MISF13 | Failure (loses namespace qualifier)
MISF14 | Failure (loses namespace qualifier)
MISF15 | Failure (loses namespace qualifier)
MISF16 | Failure (not available)
MISF17 | Failure (loses namespace qualifier)
MISF18 | Pass
MISF19 | Failure (loses namespace qualifier)
MISF20 | Pass
MISF21 | Pass
MISF22 | Failure (loses namespace qualifier)
MISF23 | Failure (loses namespace qualifier)
MISF24 | Failure (loses namespace qualifier)
MISF25 | Failure (loses namespace qualifier)
MISF26 | Failure (not available)

## Rename

**Rename** can be very sensitive to recent changes in the editor,
which different matches and selections showing up in the selection
dialog when invoked repeatedly after recent editor changes.  This
can often result in a test case failing initially, only to succeed
if the selection dialog is dismissed and re-invoked via the keyboard
shortcut.  To get reliable results, make sure that Intellisense has
completely updated before refactoring.

Case | Result
---- | ------
R1   | Failure (renames unrelated identifiers)
R2   | Failure (renames unrelated identifiers, doesn't select all instances of identifier)
R3   | Failure (renames unrelated identifiers, doesn't select all instances of identifier)
R4   | Failure (renames unrelated identifiers)
R5   | Failure (renames unrelated identifiers)
R6   | Failure (renames unrelated identifiers)
R7   | Failure (renames unrelated identifiers)
R8   | Failure (renames unrelated identifiers)
R9   | Pass
R10  | Failure (renames unrelated identifiers)
R11  | Pass
R12  | Failure (renames unrelated identifiers)
R13  | Pass
R14  | Failure (renames unrelated identifiers)
R15  | Failure (renames unrelated identifiers)
R16  | Pass
R17  | Pass
R18  | Pass
R19  | Failure (renames unrelated identifiers)
R20  | Failure (renames unrelated identifiers)
R21  | Failure (renames unrelated identifiers)
R22  | Failure (renames unrelated identifiers)
R23  | Failure (renames unrelated identifiers)
R24  | Pass
R25  | Failure (not available)
R26  | Pass
R27  | Failure (renames unrelated identifiers)
R28  | Failure (renames unrelated identifiers)
R29  | Failure (renames unrelated identifiers)
R30  | Pass
R31  | Pass
R32  | Failure (renames unrelated identifiers)
R33  | Failure (renames unrelated identifiers)
R34  | Pass
R35  | Pass
R36  | Failure (renames unrelated identifiers)
R37  | Failure (renames unrelated identifiers)
R38  | Pass
R39  | Failure (not available)
R40  | Failure (renames unrelated identifiers)
R41  | Failure (renames unrelated identifiers)
R42  | Failure (not available)
R43  | Failure (not available)
R44  | Pass
R45  | Failure (not available)
R46  | Failure (doesn't select all instances)
R47  | Failure (doesn't select all instances)
R48  | Pass
R49  | Failure (doesn't select all instances)
R50  | Pass
R51  | Failure (not available)
R52  | Failure (renames unrelated identifiers, creates invalid code)
R53  | Failure (doesn't select all instances)
R54  | Failure (doesn't select all instances)
R55  | Pass
R56  | Pass
R57  | Failure (selects no instances)
R58  | Pass
R59  | Failure (doesn't select all instances)
R60  | Pass
R61  | Pass
R62  | Failure (doesn't select all instances)
R63  | Pass
R64  | Pass
R65  | Failure (doesn't select all instances)
R66  | Pass
R67  | Pass
R68  | Pass
R69  | Failure (doesn't select all instances)
R70  | Pass
R71  | Pass
R72  | Pass
R73  | Pass
R74  | Failure (deosn't select all instances, selects unrelated instances)
R75  | Failure (deosn't select all instances, selects unrelated instances)
R76  | Failure (deosn't select all instances, selects unrelated instances)
R77  | Failure (not available)
R78  | Failure (deosn't select all instances, selects unrelated instances)
R79  | Failure (deosn't select all instances, selects unrelated instances)
R80  | Failure (deosn't select all instances, selects unrelated instances)
R81  | Failure (not available)
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
R93  | Failure (creates invalid code)
R94  | Pass
R95  | Pass
R96  | Pass
R97  | Pass
R98  | Pass
R99  | Failure (unavailable)
R100 | Failure (selects unrelated instances)
R101 | Pass
R102 | Pass
R103 | Pass
R104 | Failure (selects unrelated instances)
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
R147 | Failure (not available)
R148 | Failure (selects unrelated instances)
R149 | Pass
R150 | Failure (not available)
R151 | Failure (not available)
R152 | Pass
R153 | Failure (not available)
R154 | Failure (not available)
R155 | Failure (not available)
R156 | Failure (not available)
R157 | Failure (selects unrelated instances)
R158 | Failure (selects unrelated instances)
R159 | Failure (not available)
R160 | Failure (not available)
R161 | Failure (not available)
R162 | Failure (selects unrelated instances)
R163 | Failure (not available)
R164 | Failure (not available)
R165 | Failure (not available)
R166 | Failure (not available)
R167 | Failure (not available)
R168 | Failure (not available)
R169 | Failure (not available)
R170 | Pass
R171 | Failure (not available)
R172 | Failure (not available)
R173 | Pass
R174 | Failure (not available)
R175 | Failure (not available)
R176 | Pass
R177 | Pass
R178 | Failure (not available)
R179 | Failure (not available)
R180 | Pass
R181 | Pass
R182 | Failure (not available)
R183 | Failure (not available)
R184 | Pass
R185 | Pass
R186 | Failure (not available)
R187 | Failure (not available)
R188 | Pass
R189 | Pass
R190 | Failure (not available)
R191 | Failure (not available)
R192 | Pass
R193 | Pass
R194 | Failure (not available)
R195 | Failure (not available)
R196 | Pass
R197 | Pass
R198 | Failure (not available)
R199 | Failure (not available)
R200 | Pass
R201 | Pass
R202 | Pass
R203 | Pass
R204 | Failure (not available)
R205 | Failure (not available)
R206 | Pass
R207 | Pass
R208 | Pass
R209 | Pass
R210 | Failure (not available)
R211 | Failure (not available)
R212 | Pass
R213 | Pass
R214 | Pass
R215 | Pass
R216 | Failure (not available)
R217 | Failure (not available)
R218 | Pass
R219 | Pass
R220 | Pass
R221 | Pass
R222 | Failure (not available)
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
R242 | Failure (not available)
R243 | Failure (not available)
R244 | Failure (not available)
R245 | Failure (not available)
R246 | Failure (not available)
R247 | Failure (not available)
R248 | Failure (not available)
R249 | Failure (not available)
R250 | Failure (not available)
R251 | Failure (not available)
R252 | Failure (not available)
R253 | Failure (not available)
R254 | Failure (not available)
R255 | Failure (not available)
R256 | Failure (not available)
R257 | Failure (not available)
R258 | Failure (not available)
R259 | Failure (doesn't select all instances)
R260 | Failure (not available)
R261 | Failure (doesn't select all instances)
R262 | Failure (not available)
R263 | Failure (not available)
R264 | Pass
R265 | Failure (not available)
R266 | Failure (not available)
R267 | Failure (not available)
R268 | Failure (not available)
R269 | Failure (not available)
R270 | Failure (not available)
R271 | Pass
R272 | Failure (not available)
R273 | Failure (not available)
R274 | Failure (not available)
R275 | Failure (not available)
R276 | Failure (not available)
R277 | Failure (not available)
R278 | Failure (not available)
R279 | Failure (not available)
R280 | Failure (not available)
R281 | Pass
R282 | Pass
R283 | Pass
R284 | Pass
R285 | Pass
R286 | Pass
R287 | Failure (selects unrelated instances)
R288 | Pass
R289 | Failure (selects unrelated instances)
R290 | Pass
R291 | Failure (selects unrelated instances)
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
R319 | Failure (doesn't select all instances)
R320 | Pass
R321 | Failure (doesn't select all instances)
R322 | Failure (doesn't select all instances)
R323 | Failure (doesn't select all instances)
R324 | Failure (not available)
R325 | Failure (doesn't select all instances)
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
R418 | Failure (selects unrelated instances)
R419 | Failure (selects unrelated instances)
R420 | Pass
R421 | Failure (selects unrelated instances)
R422 | Pass
R423 | Pass
R424 | Pass
R425 | Failure (selects unrelated instances)
R426 | Failure (selects unrelated instances)
R427 | Failure (selects unrelated instances)
R428 | Failure (selects unrelated instances)
R429 | Failure (doesn't select all instances)
R430 | Failure (not available)
R431 | Failure (not available)
R432 | Pass
R433 | Failure (doesn't select all instances)
R434 | Failure (not available)
R435 | Failure (doesn't select all instances)
R436 | Failure (doesn't select all instances)
R437 | Failure (not available)
R438 | Pass
R439 | Pass
R440 | Pass
R441 | Pass
R442 | Pass
R443 | Pass
R444 | Failure (doesn't select all instances)
R445 | Failure (doesn't select all instances)
R446 | Failure (unavailable)
R447 | Pass
R448 | Pass
R449 | Pass
R450 | Pass
R451 | Pass
R452 | Pass
R453 | Pass
R454 | Failure (selects unrelated instances)
R455 | Failure (selects unrelated instances)
R456 | Failure (selects unrelated instances)
R457 | Failure (selects unrelated instances)
R458 | Pass
R459 | Pass
R460 | Failure (selects unrelated instances)
R461 | Pass
R462 | Failure (selects unrelated instances)
R463 | Failure (selects unrelated instances)
R464 | Pass
R465 | Pass
R466 | Pass
R467 | Pass
R468 | Pass
R469 | Pass
R470 | Pass
R471 | Pass
R472 | Pass
R473 | Failure (changes unrelated code)
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
R502 | Failure (selects unrelated instances)
R503 | Failure (selects unrelated instances)
R504 | Pass
R505 | Pass
R506 | Failure (selects unrelated instances)
R507 | Failure (selects unrelated instances)
R508 | Failure (selects unrelated instances)
R509 | Failure (doesn't select all instances)
R510 | Failure (selects unrelated instances)
R511 | Pass
R512 | Failure (selects unrelated instances)
R513 | Pass
R514 | Pass
R515 | Pass
R516 | Failure (selects unrelated instances)
R517 | Failure (selects unrelated instances)
R518 | Pass
R519 | Failure (selects unrelated instances)
R520 | Failure (selects unrelated instances)
R521 | Pass
R522 | Failure (selects unrelated instances)
R523 | Pass
R524 | Failure (selects unrelated instances)
R525 | Failure (selects unrelated instances)
R526 | Failure (selects unrelated instances)
R527 | Pass
R528 | Pass
R529 | Pass
R530 | Pass
R531 | Pass
R532 | Pass
R533 | Pass
R534 | Pass
R535 | Failure (selects unrelated instances)
R536 | Pass
R537 | Failure (unavailable)
R538 | Pass
R539 | Failure (selects unrelated instances)
R540 | Pass
R541 | Failure (unavailable)
R542 | Failure (selects unrelated instances)
R543 | Pass
R544 | Pass
R545 | Failure (selects unrelated instances)
R546 | Failure (selects unrelated instances)
R547 | Pass
R548 | Failure (selects unrelated instances)
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
R560 | Failure (selects unrelated instances)
R561 | Failure (selects unrelated instances)
R562 | (deprecated)
R563 | Pass
R564 | Failure (selects unrelated instances)
R565 | Pass
R566 | Failure (selects unrelated instances)
R567 | Pass
R568 | Pass
R569 | Pass
R570 | Pass
R571 | Pass
R572 | Pass
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
R606 | Failure (selects unrelated instances)
R607 | Failure (selects unrelated instances)
R608 | Pass
R609 | Failure (selects unrelated instances)
R610 | Pass
R611 | Failure (selects unrelated instances)
R612 | Pass
R613 | Pass
R614 | Pass
R615 | Pass
R616 | Failure (selects unrelated instances)
R617 | Failure (selects unrelated instances)
R618 | Pass
R619 | Failure (selects unrelated instances)
R620 | Pass
R621 | Pass
R622 | Pass
R623 | Pass
R624 | Pass
R625 | Pass
R626 | Pass
R627 | Failure (not available)
R628 | Failure (not available)
R629 | Pass
R630 | Failure (not available)
R631 | Failure (not available)
R632 | Pass
R633 | Pass
R634 | Failure (not available)
R635 | Failure (not available)
R636 | Pass
R637 | Failure (not available)
R638 | Failure (not available)
R639 | Pass
R640 | Pass
R641 | Pass
R642 | Pass
R643 | Pass
R644 | Pass
R645 | Pass
R646 | Pass
R647 | Pass
R648 | Failure (selects unrelated instances)
R649 | Pass
R650 | Pass
R651 | Failure (selects unrelated instances)
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
R686 | Failure (not available)
R687 | Failure (not available)
R688 | Pass
R689 | Failure (not available)
R690 | Failure (not available)
R691 | Pass
R692 | Failure (not available)
R693 | Failure (not available)
R694 | Failure (not available)
R695 | Failure (not available)
R696 | Pass
R697 | Failure (not available)
R698 | Failure (not available)
R699 | Failure (not available)
R700 | Failure (not available)
R701 | Pass
R702 | Failure (not available)
R703 | Failure (not available)
R704 | Failure (not available)
R705 | Failure (not available)
R706 | Pass
R707 | Failure (not available)
R708 | Failure (not available)
R709 | Failure (not available)
R710 | Failure (not available)
R711 | Pass
R712 | Failure (not available)
R713 | Failure (not available)
R714 | Failure (not available)
R715 | Failure (not available)
R716 | Pass
R717 | Failure (not available)
R718 | Failure (not available)
R719 | Failure (not available)
R720 | Failure (not available)
R721 | Pass
R722 | Failure (not available)
R723 | Failure (not available)
R724 | Pass
R725 | Pass
R726 | Pass
R727 | Pass
R728 | Pass
R729 | Failure (not available)
R730 | Failure (not available)
R731 | Failure (not available)
R732 | Failure (not available)
R733 | Failure (not available)
R734 | Failure (not available)
R735 | Failure (not available)
R736 | Pass
R737 | Failure (not available)
R738 | Failure (not available)
R739 | Failure (not available)
R740 | Failure (not available)
R741 | Pass
R742 | Failure (not available)
R743 | Failure (not available)
R744 | Failure (not available)
R745 | Failure (not available)
R746 | Pass
R747 | Failure (not available)
R748 | Pass
R749 | Failure (not available)
R750 | Pass
R751 | Failure (not available)
R752 | Failure (not available)
R753 | Pass
R754 | Failure (not available)
R755 | Pass
R756 | Failure (not available)
R757 | Pass
R758 | Failure (not available)
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
R785 | Failure (selects unrelated instances)
R786 | Pass
R787 | Pass
R788 | Failure (selects unrelated instances)
R789 | Failure (selects unrelated instances)
R790 | Pass
R791 | Failure (selects unrelated instances)
R792 | Failure (selects unrelated instances)
R793 | Pass
R794 | Failure (selects unrelated instances)
R795 | Failure (selects unrelated instances)
R796 | Pass
R797 | Failure (selects unrelated instances)
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
R890 | Failure (selects unrelated instances)
R891 | Failure (selects unrelated instances)
R892 | Failure (selects unrelated instances)
R893 | Failure (selects unrelated instances)
R894 | Pass
R895 | Failure (selects unrelated instances)
R896 | Failure (not available)
R897 | Failure (selects unrelated instances)
R898 | Failure (selects unrelated instances)
R899 | Failure (not available)
R900 | Failure (not available)
R901 | Pass
R902 | Pass
R903 | Failure (not available)
R904 | Pass
R905 | Failure (not available)
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
R948 | Failure (not available)
R949 | Pass
R950 | Failure (not available)
R951 | Pass
R952 | Pass
R953 | Pass
R954 | Pass
R955 | Pass
R956 | Pass
R957 | Pass
R958 | Pass
R959 | Failure (selects unrelated instances)
R960 | Failure (selects unrelated instances)
R961 | Failure (selects unrelated instances)
R962 | Failure (selects unrelated instances)
R963 | Failure (selects unrelated instances)
R964 | Failure (selects unrelated instances)
R965 | Failure (selects unrelated instances)
R966 | Failure (selects unrelated instances)
R967 | Pass
R968 | Pass
R969 | Pass
R970 | Failure (not available)
R971 | Failure (not available)
R972 | Failure (selects unrelated instances)
R973 | Pass
R974 | Pass
R975 | Pass
R976 | Pass
R977 | Failure (selects unrelated instances)
R978 | Failure (selects unrelated instances)
R979 | Failure (selects unrelated instances)
R980 | Failure (selects unrelated instances)
R981 | Pass
R982 | Pass
R983 | Pass
R984 | Pass
R985 | Pass
R986 | Pass

<hr/>

Other issues:

* when double clicking a list item in the Rename selection dialog,
  it should put the selected line at the center of the editor window
  if it repositions the scroll bar
* Extract Method gives no feedback on names [case=83040](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11890)
* File should not be selected when no items selected [case=83859](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11902)
* Change Signature doesn't adjust ptr to member [case=83184](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11913), [case=83185](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11913)
* VAX colors raw string literal as a type [case=65734](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11975)
* Create From Declaration unavailable for operator== [case=84291](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11981)
* Move Implementation to Source File fails with C11 [~~~case=79737~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=12074)
