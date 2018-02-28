# ReSharper for C++

Home: [ReSharper for C++](http://www.jetbrains.com/resharper-cpp/)

Version: 2017.3.2

Notes:
* **Add Block Delimiter** is available as a quick fix.  The tests pass if only code is selected and not the surrounding comment lines.
* **Add Override** is available as the quick fix *Add 'override' specifier to an overriding function*.
* **Add Parameter** is available through **Change Signature**.  Default file selections were accepted and the argument value of zero was chosen.
* **Create Multi-Variable Declaration** is available as the quick fix *Join declarations*.
* **Flatten Conditional** is available as the quick fix *Merge nested 'if' statements*.
* **Inline Macro** is available as the quick fix *Substitute macro call*.
* **Make Method Static** is available as a quick fix.
* **Move Implementation to Source File** is available as the quick fix *Move function implementation to source file*.
* **Remove Block Delimiter** is available as the quick fix *Remove braces*.
* **Remove Unused Parameter** is available as a quick fix.
* **Reorder Parameters** is available through **Change Signature**.
* **Replace If With Ternary** is available as the quick fix *Convert 'if' to '?:'*.
* **Replace Ternary With If** is available as the quick fix *Convert '?:' to 'if'*.
* **Reverse Conditional** is available as the quick fix *Invert 'if' statement*.
* **Split Multi-Variable Declaration** is available as the quick fix *Split declaration with multiple declarators*.

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
AP19 | Pass (but suggests irrelevant change points) [RSCPP-21202](https://youtrack.jetbrains.com/issue/RSCPP-21202)
AP20 | Pass
AP21 | Pass
AP22 | Pass
AP23 | Pass
AP24 | Failure (doensn't update other template arguments) [RSCPP-21202](https://youtrack.jetbrains.com/issue/RSCPP-21202)

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

## Create Multi-Variable Declaration
Case | Result
---- | ------
CMVD1  | Pass
CMVD2  | Pass
CMVD3  | Pass
CMVD4  | Pass
CMVD5  | Pass
CMVD6  | Failure [RSCPP-15791](https://youtrack.jetbrains.com/issue/RSCPP-15791)
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

## Inline Variable
Case | Result
---- | ------
IV1  | Pass (deletes comment) [RSCPP-19617](https://youtrack.jetbrains.com/issue/RSCPP-19617)
IV2  | Pass (leaves behind syntactical noise) [RSCPP-21205](https://youtrack.jetbrains.com/issue/RSCPP-21205)
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
R91  | n/a
R92  | n/a
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

## Reorder Parameters
Case | Result
---- | ------
RP1 | Failure (functionality not available) [RSCPP-21236](https://youtrack.jetbrains.com/issue/RSCPP-21236)
RP2 | Failure (creates invalid code in macro argument) [RSCPP-21210](https://youtrack.jetbrains.com/issue/RSCPP-21210)
RP3 | Pass
RP4 | Failure (unable to update usage) [RSCPP-21211](https://youtrack.jetbrains.com/issue/RSCPP-21211)
RP5 | Failure (creates invalid code in macro argument) [RSCPP-21210](https://youtrack.jetbrains.com/issue/RSCPP-21210)
RP6 | Failure (unable to update usage) [RSCPP-21211](https://youtrack.jetbrains.com/issue/RSCPP-21211)
RP7 | Failure (functionality not available) [RSCPP-21236](https://youtrack.jetbrains.com/issue/RSCPP-21236)
RP8 | Failure (functionality not available) [RSCPP-21236](https://youtrack.jetbrains.com/issue/RSCPP-21236)
RP9 | Failure (functionality not available) [RSCPP-21236](https://youtrack.jetbrains.com/issue/RSCPP-21236)

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
RTWA22 | n/a
RTWA23 | Pass
RTWA24 | n/a
RTWA25 | Pass
RTWA26 | n/a
RTWA27 | Pass
RTWA28 | Pass
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
