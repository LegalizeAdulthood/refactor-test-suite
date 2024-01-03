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
EM2 | Failure [case=82956](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11883)
EM3 | Failure [case=82956](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11883)
EM4 | Pass
EM5 | Failure
EM6 | Pass
EM7 | Pass
EM8 | Failure
EM9 | Failure
EM10 | Pass
EM11 | Failure
EM12 | Pass
EM13 | Pass
EM14 | Failure
EM15 | Failure
EM16 | Pass
EM17 | Failure
EM18 | Pass
EM19 | Failure [case=2063](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11884)
EM20 | Failure [case=83005](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11885)
EM21 |

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass
MISF2  | Failure (invalid syntax)
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
MISF16 | Failure (not available)
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure (not available)

## Rename
Case | Result
---- | ------
R1      | Failure (doesn't select all instances of identifier) [case=58805](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11900)
R2      | Failure (doesn't select all instances of identifier)
R3      | Failure (doesn't select all instances of identifier)
R4      | Failure (doesn't select all instances of identifier) [case=1384](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11901)
R5      | Pass
R6      | Pass
R7      | Pass
R8      | Pass [case=34692](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11904)
R9      | Pass
R10     | Pass
R11     | Pass
R12     | Pass
R13     | Pass
R14     | Failure (doesn't select all instances of identifier)
R15     | Pass
R16     | Pass
R17     | Pass
R18     | Pass
R19     | Failure (doesn't select all instances of identifier)
R20     | Failure (doesn't select all instances of identifier)
R21     | Pass
R22     | Pass
R23     | Pass
R24     | Pass
R25     | Failure (not available) [case=83603](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11905)
R26     | Pass
R27     | Failure (doesn't select all instances of identifier)
R28     | Pass
R29     | Failure (doesn't select all instances of identifier) [~~~case=83847~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11906)
R30     | Pass
R31     | Pass
R32     | Failure (suggested identifier contains ~ and is allowed)
R33     | Failure (doesn't select all instances of identifier)
R34     | Failure (doesn't select all instances of identifier)
R35     | Failure (not available)
R36     | Failure (doesn't select all instances of identifier) [~~~case=83847~~~](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11907)
R37     | Pass
R38     | Pass
R39     | Pass
R40     | Pass
R41     | Failure (not available) [case=83848](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11908)
R42     | Pass
R43     | Pass
R44     | Pass
R45     | Failure (not available)
R46     | Pass
R47     | Pass
R48     | Pass
R49     | Pass
R50     | Pass
R51     | Pass
R52     | Pass
R53     | Pass
R54     | Pass
R55     | Pass
R56     | Pass
R57     | Pass
R58     | Pass
R59     | Pass
R60     | Pass
R61     | Pass
R62     | Pass
R63     | Pass
R64     | Pass
R65     | Pass
R66     | Pass
R67     | Pass
R68     | Pass
R69     | Pass
R70     | Pass
R71     | Failure (doesn't select all instances of identifier)
R72     | Failure (doesn't select all instances of identifier)
R73     | Failure (doesn't select all instances of identifier)
R74     | Pass [case=83856](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11909), [case=58805](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11909)
R75     | Pass
R76     | Pass
R77     | Failure (not available) [case=83858](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11910)
R78     | Pass
R79     | Pass
R80     | Pass
R81     | Failure (not available) [case=83858](http://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=11910)
R82     | Failure (doesn't select all instances of identifier)
R83     | Failure (doesn't select all instances of identifier)
R84     | Pass
R85     | Pass
R86     | Pass
R87     | Pass
R88     | Pass
R89     | Pass
R90     | Pass
R91     | (deprecated)
R92     | (deprecated)
R93     | Pass
R94     | Pass
R95     | Pass
R96     | Pass
R97     | Pass
R98     | Pass
R99 | 
R100 | 
R101 | 
R102 | 
R103 | 
R104 | 
R105 | 
R106 | 
R107 | 
R108 | 
R109 | 
R110 | 
R111 | 
R112 | 
R113 | 
R114 | 
R115 | 
R116 | 
R117 | 
R118 | 
R119 | 
R120 | 
R121 | 
R122 | 
R123 | 
R124 | 
R125 | 
R126 | 
R127 | 
R128 | 
R129 | 
R130 | 
R131 | 
R132 | 
R133 | 
R134 | 
R135 | 
R136 | 
R137 | 
R138 | 
R139 | 
R140 | 
R141 | 
R142 | 
R143 | 
R144 | 
R145 | 
R146 | 
R147 | 
R148 | 
R149 | 
R150 | 
R151 | 
R152 | 
R153 | 
R154 | 
R155 | 
R156 | 
R157 | 
R158 | 
R159 | 
R160 | 
R161 | 
R162 | 
R163 | 
R164 | 
R165 | 
R166 | 
R167 | 
R168 | 
R169 | 
R170 | 
R171 | 
R172 | 
R173 | 
R174 | 
R175 | 
R176 | 
R177 | 
R178 | 
R179 | 
R180 | 
R181 | 
R182 | 
R183 | 
R184 | 
R185 | 
R186 | 
R187 | 
R188 | 
R189 | 
R190 | 
R191 | 
R192 | 
R193 | 
R194 | 
R195 | 
R196 | 
R197 | 
R198 | 
R199 | 
R200 | 
R201 | 
R202 | 
R203 | 
R204 | 
R205 | 
R206 | 
R207 | 
R208 | 
R209 | 
R210 | 
R211 | 
R212 | 
R213 | 
R214 | 
R215 | 
R216 | 
R217 | 
R218 | 
R219 | 
R220 | 
R221 | 
R222 | 
R223 | 
R224 | 
R225 | 
R226 | 
R227 | 
R228 | 
R229 | 
R230 | 
R231 | 
R232 | 
R233 | 
R234 | 
R235 | 
R236 | 
R237 | 
R238 | 
R239 | 
R240 | 
R241 | 
R242 | 
R243 | 
R244 | 
R245 | 
R246 | 
R247 | 
R248 | 
R249 | 
R250 | 
R251 | 
R252 | 
R253 | 
R254 | 
R255 | 
R256 | 
R257 | 
R258 | 
R259 | 
R260 | 
R261 | 
R262 | 
R263 | 
R264 | 
R265 | 
R266 | 
R267 | 
R268 | 
R269 | 
R270 | 
R271 | 
R272 | 
R273 | 
R274 | 
R275 | 
R276 | 
R277 | 
R278 | 
R279 | 
R280 | 
R281 | 
R282 | 
R283 | 
R284 | 
R285 | 
R286 | 
R287 | 
R288 | 
R289 | 
R290 | 
R291 | 
R292 | 
R293 | 
R294 | 
R295 | 
R296 | 
R297 | 
R298 | 
R299 | 
R300 | 
R301 | 
R302 | 
R303 | 
R304 | 
R305 | 
R306 | 
R307 | 
R308 | 
R309 | 
R310 | 
R311 | 
R312 | 
R313 | 
R314 | 
R315 | 
R316 | 
R317 | 
R318 | 
R319 | 
R320 | 
R321 | 
R322 | 
R323 | 
R324 | 
R325 | 
R326 | 
R327 | 
R328 | 
R329 | 
R330 | 
R331 | 
R332 | 
R333 | 
R334 | 
R335 | 
R336 | 
R337 | 
R338 | 
R339 | 
R340 | 
R341 | 
R342 | 
R343 | 
R344 | 
R345 | 
R346 | 
R347 | 
R348 | 
R349 | 
R350 | 
R351 | 
R352 | 
R353 | 
R354 | 
R355 | 
R356 | 
R357 | 
R358 | 
R359 | 
R360 | 
R361 | 
R362 | 
R363 | 
R364 | 
R365 | 
R366 | 
R367 | 
R368 | 
R369 | 
R370 | 
R371 | 
R372 | 
R373 | 
R374 | 
R375 | 
R376 | 
R377 | 
R378 | 
R379 | 
R380 | 
R381 | 
R382 | 
R383 | 
R384 | 
R385 | 
R386 | 
R387 | 
R388 | 
R389 | 
R390 | 
R391 | 
R392 | 
R393 | 
R394 | 
R395 | 
R396 | 
R397 | 
R398 | 
R399 | 
R400 | 
R401 | 
R402 | 
R403 | 
R404 | 
R405 | 
R406 | 
R407 | 
R408 | 
R409 | 
R410 | 
R411 | 
R412 | 
R413 | 
R414 | 
R415 | 
R416 | 
R417 | 
R418 | 
R419 | 
R420 | 
R421 | 
R422 | 
R423 | 
R424 | 
R425 | 
R426 | 
R427 | 
R428 | 
R429 | 
R430 | 
R431 | 
R432 | 
R433 | 
R434 | 
R435 | 
R436 | 
R437 | 
R438 | 
R439 | 
R440 | 
R441 | 
R442 | 
R443 | 
R444 | 
R445 | 
R446 | 
R447 | 
R448 | 
R449 | 
R450 | 
R451 | 
R452 | 
R453 | 
R454 | 
R455 | 
R456 | 
R457 | 
R458 | 
R459 | 
R460 | 
R461 | 
R462 | 
R463 | 
R464 | 
R465 | 
R466 | 
R467 | 
R468 | 
R469 | 
R470 | 
R471 | 
R472 | 
R473 | 
R474 | 
R475 | 
R476 | 
R477 | 
R478 | 
R479 | 
R480 | 
R481 | 
R482 | 
R483 | 
R484 | 
R485 | 
R486 | 
R487 | 
R488 | 
R489 | 
R490 | 
R491 | 
R492 | 
R493 | 
R494 | 
R495 | 
R496 | 
R497 | 
R498 | 
R499 | 
R500 | 
R501 | 
R502 | 
R503 | 
R504 | 
R505 | 
R506 | 
R507 | 
R508 | 
R509 | 
R510 | 
R511 | 
R512 | 
R513 | 
R514 | 
R515 | 
R516 | 
R517 | 
R518 | 
R519 | 
R520 | 
R521 | 
R522 | 
R523 | 
R524 | 
R525 | 
R526 | 
R527 | 
R528 | 
R529 | 
R530 | 
R531 | 
R532 | 
R533 | 
R534 | 
R535 | 
R536 | 
R537 | 
R538 | 
R539 | 
R540 | 
R541 | 
R542 | 
R543 | 
R544 | 
R545 | 
R546 | 
R547 | 
R548 | 
R549 | 
R550 | 
R551 | 
R552 | 
R553 | 
R554 | 
R555 | 
R556 | 
R557 | 
R558 | 
R559 | 
R560 | 
R561 | 
R562 | (deprecated)
R563 | 
R564 | 
R565 | 
R566 | 
R567 | 
R568 | 
R569 | 
R570 | 
R571 | 
R572 | 
R573 | 
R574 | 
R575 | 
R576 | 
R577 | 
R578 | 
R579 | 
R580 | 
R581 | 
R582 | 
R583 | 
R584 | 
R585 | 
R586 | 
R587 | 
R588 | 
R589 | 
R590 | 
R591 | 
R592 | 
R593 | 
R594 | 
R595 | 
R596 | 
R597 | 
R598 | 
R599 | 
R600 | 
R601 | 
R602 | 
R603 | 
R604 | 
R605 | 
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
