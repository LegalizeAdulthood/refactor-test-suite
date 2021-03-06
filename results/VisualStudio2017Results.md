# Visual Studio 2015

Home: [Visual Studio 2017](http://www.visualstudio.com/)

Version: Microsoft Visual Studio Community 2017, Version 15.5.7

Notes:
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
 * **Add Parameter** is available through **Change Signature**.
 * **Move Implementation to Source File** is available as **Move Definition
   Location**.
 * **Rename** shifts the focus to the Visual C++ Refactoring output in the Output
   pane.  This is pretty annoying as it keeps taking the keyboard focus away
   from the editor.
 * **Reorder Parameters** is available through **Change Signature**, but the unused
   parameters are not indicated visually in the IDE.
 * Microsoft retired the Connect bug tracker in January, 2018.  (I never got any
   email notification to the best of my recollection.)  All my URLs to
   previously filed bugs no longer work, preventing me from correlating previous
   results to current results and identifying if claimed fixes are actually fixed.

<hr/>

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
AP8  | Failure (not all instances selected) [206937](https://developercommunity.visualstudio.com/content/problem/206937/change-signature-fails-for-static-class-method.html)
AP9  | Pass
AP10 | Pass
AP11 | Pass
AP12 | Pass
AP13 | Failure (not all instances selected) [206940](https://developercommunity.visualstudio.com/content/problem/206940/change-signature-fails-to-update-forward-declarati.html)
AP14 | Pass
AP15 | Failure (not all instances selected, wrong instances selected) [206941](https://developercommunity.visualstudio.com/content/problem/206941/change-signature-doesnt-select-call-sites-for-over.html), [206943](https://developercommunity.visualstudio.com/content/problem/206943/change-signature-modifies-overload.html)
AP16 | Failure (not all instances selected, wrong instances selected) [206941](https://developercommunity.visualstudio.com/content/problem/206941/change-signature-doesnt-select-call-sites-for-over.html), [206943](https://developercommunity.visualstudio.com/content/problem/206943/change-signature-modifies-overload.html)
AP17 | Pass
AP18 | Pass
AP19 | Pass
AP20 | Pass
AP21 | Pass
AP22 | Failure (declaration not updated) [206946](https://developercommunity.visualstudio.com/content/problem/206946/change-signature-on-static-method-definition-doesn.html)
AP23 | Pass
AP24 | Failure (doesn't select all instances) [206939](https://developercommunity.visualstudio.com/content/problem/206939/change-signature-on-static-method-doesnt-update-us.html)
AP25 | Failure (not available) [206938](https://developercommunity.visualstudio.com/content/problem/206938/change-signature-doesnt-recognize-static-function.html)

## Change Signature
Case | Result
---- | ------
CS1  | Failure (instances not renamed) [206953](https://developercommunity.visualstudio.com/content/problem/206953/change-signature-doesnt-rename-uses-of-parameter.html)
CS2  | Failure (instances not renamed) [206953](https://developercommunity.visualstudio.com/content/problem/206953/change-signature-doesnt-rename-uses-of-parameter.html)
CS3  | Failure (unavailable) [206954](https://developercommunity.visualstudio.com/content/problem/206954/cant-rename-function-from-change-signature.html)
CS4  | Pass
CS5  | Pass
CS6  | Pass
CS7  | Failure (instances not renamed) [206953](https://developercommunity.visualstudio.com/content/problem/206953/change-signature-doesnt-rename-uses-of-parameter.html)
CS8  | Failure (instances not renamed) [206953](https://developercommunity.visualstudio.com/content/problem/206953/change-signature-doesnt-rename-uses-of-parameter.html)
CS9  | Failure (unavailable) [206954](https://developercommunity.visualstudio.com/content/problem/206954/cant-rename-function-from-change-signature.html)
CS10 | Pass
CS11 | Pass

## Extract Function
Case | Result
---- | ------
EXF1  | Failure (data flow) [206897](https://developercommunity.visualstudio.com/content/problem/206897/extract-function-cant-handle-statements-defining-v.html)
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
EXF16 | Failure (creates invalid code) [206898](https://developercommunity.visualstudio.com/content/problem/206898/extract-function-creates-invalid-code.html)
EXF17 | Pass
EXF18 | Failure (data flow) [206897](https://developercommunity.visualstudio.com/content/problem/206897/extract-function-cant-handle-statements-defining-v.html)
EXF19 | Failure (creates invalid code) [206899](https://developercommunity.visualstudio.com/content/problem/206899/extract-function-creates-invalid-code-on-macro-exp.html)

## Extract Method
Case | Result
---- | ------
EM1 | Pass
EM2 | Pass
EM3 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)
EM4 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)
EM5 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)
EM6 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)
EM7 | Pass
EM8 | Pass
EM9 | Pass
EM10 | Pass
EM11 | Failure (creates invalid code) [206911](https://developercommunity.visualstudio.com/content/problem/206911/extract-method-creates-invalid-code.html)
EM12 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)
EM13 | Pass
EM14 | Pass
EM15 | Pass
EM16 | Pass
EM17 | Failure (creates invalid code) [206911](https://developercommunity.visualstudio.com/content/problem/206911/extract-method-creates-invalid-code.html)
EM18 | Pass
EM19 | Failure (data flow) [206897](https://developercommunity.visualstudio.com/content/problem/206897/extract-function-cant-handle-statements-defining-v.html)
EM20 | Pass (unnecessary use of namespace) [206900](https://developercommunity.visualstudio.com/content/problem/206900/extract-method-uses-redundant-namespace-specifier.html)

## Move Implementation to Source File
Case | Result
---- | ------
MISF1  | Pass (leaves `inline` in header) [206912](https://developercommunity.visualstudio.com/content/problem/206912/move-definition-leaves-behind-pointless-inline-spe.html)
MISF2  | Failure (unknown error) [206914](https://developercommunity.visualstudio.com/content/problem/206914/move-definition-location-on-constructor-gives-unkn.html)
MISF3  | Pass (sensitive to cursor placement) [206915](https://developercommunity.visualstudio.com/content/problem/206915/move-definition-fails-to-move-destructor-if-cursor.html)
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
MISF16 | Failure (creates invalid code) [206916](https://developercommunity.visualstudio.com/content/problem/206916/move-definition-location-creates-invalid-code.html)
MISF17 | Pass
MISF18 | Pass
MISF19 | Pass
MISF20 | Pass
MISF21 | Pass
MISF22 | Pass
MISF23 | Pass
MISF24 | Pass
MISF25 | Pass
MISF26 | Failure (creates invalid code) [206916](https://developercommunity.visualstudio.com/content/problem/206916/move-definition-location-creates-invalid-code.html)

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
R25  | Failure (not available) [206917](https://developercommunity.visualstudio.com/content/problem/206917/rename-unavailable-on-macro-argument.html)
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
R70  | Failure (doesn't select correct instances) [206918](https://developercommunity.visualstudio.com/content/problem/206918/rename-of-virtual-method-doesnt-select-all-overrid.html)
R71  | Failure (doesn't select correct instances) [206918](https://developercommunity.visualstudio.com/content/problem/206918/rename-of-virtual-method-doesnt-select-all-overrid.html)
R72  | Failure (doesn't select correct instances) [206918](https://developercommunity.visualstudio.com/content/problem/206918/rename-of-virtual-method-doesnt-select-all-overrid.html)
R73  | Failure (doesn't select correct instances) [206918](https://developercommunity.visualstudio.com/content/problem/206918/rename-of-virtual-method-doesnt-select-all-overrid.html)
R74  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R75  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R76  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R77  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R78  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R79  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R80  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R81  | Failure (selects unrelated instances, doesn't select all instances) [206919](https://developercommunity.visualstudio.com/content/problem/206919/rename-of-macro-selects-unrelated-instances-by-def.html), [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R82  | Pass
R83  | Pass
R84  | Pass
R85  | Pass
R86  | Pass
R87  | Pass
R88  | Pass
R89  | Pass
R90  | Pass
R93  | Pass
R94  | Pass
R95  | Pass
R96  | Pass
R97  | Pass
R98  | Pass
R99  | Failure (not available) [206917](https://developercommunity.visualstudio.com/content/problem/206917/rename-unavailable-on-macro-argument.html)
R100 | Pass
R101 | Pass
R102 | Pass
R103 | Pass
R104 | Pass
R105 | Pass
R106 | Pass
R107 | Pass
R108 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R109 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R110 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
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
R146 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R147 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R148 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R149 | Pass
R150 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R151 | Pass
R152 | Pass
R153 | Pass
R154 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R155 | Pass
R156 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R157 | Pass
R158 | Pass
R159 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R160 | Pass
R161 | Pass
R162 | Pass
R163 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R164 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R165 | Pass
R166 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R167 | Pass
R168 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R169 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R170 | Pass
R171 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R172 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R173 | Pass
R174 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R175 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R176 | Pass
R177 | Pass
R178 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R179 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R180 | Pass
R181 | Pass
R182 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R183 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R184 | Pass
R185 | Pass
R186 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R187 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R188 | Pass
R189 | Pass
R190 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R191 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R192 | Pass
R193 | Pass
R194 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R195 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R196 | Pass
R197 | Pass
R198 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R199 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R200 | Pass
R201 | Pass
R202 | Pass
R203 | Pass
R204 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R205 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R206 | Pass
R207 | Pass
R208 | Pass
R209 | Pass
R210 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R211 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R212 | Pass
R213 | Pass
R214 | Pass
R215 | Pass
R216 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R217 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R218 | Pass
R219 | Pass
R220 | Pass
R221 | Pass
R222 | Failure (action not enabled in dialog) [206922](https://developercommunity.visualstudio.com/content/problem/206922/rename-fails-for-user-defined-literal-operator.html)
R223 | Pass
R224 | Failure (not all instances selected) [206923](https://developercommunity.visualstudio.com/content/problem/206923/rename-of-type-alias-doesnt-select-all-instances.html)
R225 | Pass
R226 | Failure (not all instances selected) [206923](https://developercommunity.visualstudio.com/content/problem/206923/rename-of-type-alias-doesnt-select-all-instances.html)
R227 | Failure (selects incorrect instances) [206924](https://developercommunity.visualstudio.com/content/problem/206924/rename-of-type-alias-selects-symbols-from-standard.html)
R228 | Pass
R229 | Pass
R230 | Pass
R231 | Pass
R232 | Pass
R233 | Pass
R234 | Pass
R235 | Pass
R236 | Failure (not all instances selected) [206925](https://developercommunity.visualstudio.com/content/problem/206925/rename-doesnt-select-instances-in-member-initializ.html)
R237 | Pass
R238 | Pass
R239 | Failure (can't find definition) [206926](https://developercommunity.visualstudio.com/content/problem/206926/rename-of-initializing-expression-cant-find-defini.html)
R240 | Pass
R241 | Pass
R242 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R243 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R244 | Pass
R245 | Pass
R246 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R247 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R248 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R249 | Pass
R250 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R251 | Pass
R252 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R253 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R254 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R255 | Pass
R256 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R257 | Pass
R258 | Pass
R259 | Pass
R260 | Pass
R261 | Pass
R262 | Pass
R263 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R264 | Pass
R265 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R266 | Pass
R267 | Pass
R268 | Pass
R269 | Pass
R270 | Pass
R271 | Pass
R272 | Pass
R273 | Pass
R274 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R275 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R276 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R277 | Pass
R278 | Pass
R279 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R280 | Pass
R281 | Pass
R282 | Pass
R283 | Pass
R284 | Pass
R285 | Pass
R286 | Pass
R287 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R288 | Failure (not all instances selected) [206927](https://developercommunity.visualstudio.com/content/problem/206927/rename-doesnt-select-instances-in-decltype-express.html)
R289 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R290 | Failure (can't find definition) [206928](https://developercommunity.visualstudio.com/content/problem/206928/rename-of-variable-in-decltype-expression-cant-fin.html)
R291 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R292 | Failure (not all instances selected) [206927](https://developercommunity.visualstudio.com/content/problem/206927/rename-doesnt-select-instances-in-decltype-express.html)
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
R376 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
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
R416 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R417 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R418 | Pass
R419 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R420 | Pass
R421 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R422 | Pass
R423 | Pass
R424 | Pass
R425 | Pass
R426 | Pass
R427 | Pass
R428 | Pass
R429 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R430 | Failure (can't find definition) [206917](https://developercommunity.visualstudio.com/content/problem/206917/rename-unavailable-on-macro-argument.html)
R431 | Failure (can't find definition) [206917](https://developercommunity.visualstudio.com/content/problem/206917/rename-unavailable-on-macro-argument.html)
R432 | Pass
R433 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R434 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R435 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R436 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R437 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R438 | Pass
R439 | Pass
R440 | Pass
R441 | Pass
R442 | Pass
R443 | Pass
R444 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R445 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R446 | Failure (not all instances selected) [206920](https://developercommunity.visualstudio.com/content/problem/206920/rename-of-macro-doesnt-find-instances-in-undef.html)
R447 | Pass
R448 | Pass
R449 | Pass
R450 | Pass
R451 | Pass
R452 | Pass
R453 | Pass
R454 | Failure (selects wrong instances) [206930](https://developercommunity.visualstudio.com/content/problem/206930/rename-on-lvalue-ref-method-selects-wrong-instance.html)
R455 | Pass
R456 | Failure (selects wrong instances) [206931](https://developercommunity.visualstudio.com/content/problem/206931/rename-of-method-accepting-lvalue-reference-parame.html)
R457 | Pass
R458 | Pass
R459 | Pass
R460 | Failure (selects wrong instances) [206930](https://developercommunity.visualstudio.com/content/problem/206930/rename-on-lvalue-ref-method-selects-wrong-instance.html)
R461 | Pass
R462 | Failure (selects wrong instances) [206931](https://developercommunity.visualstudio.com/content/problem/206931/rename-of-method-accepting-lvalue-reference-parame.html)
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
R487 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R488 | Pass
R489 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R490 | Pass
R491 | Pass
R492 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R493 | Pass
R494 | Pass
R495 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R496 | Pass
R497 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R498 | Pass
R499 | Pass
R500 | Failure (selects unrelated instances) [212271](https://developercommunity.visualstudio.com/content/problem/212271/rename-of-local-namespace-alias-selects-unrelated.html)
R501 | Pass
R502 | Pass
R503 | Pass
R504 | Failure (fails to select all instances) [212275](https://developercommunity.visualstudio.com/content/problem/212275/renaming-class-member-fails-to-select-all-instance.html)
R505 | Failure (fails to select all instances) [212275](https://developercommunity.visualstudio.com/content/problem/212275/renaming-class-member-fails-to-select-all-instance.html)
R506 | Pass
R507 | Pass
R508 | Pass
R509 | Pass
R510 | Pass
R511 | Pass
R512 | Pass
R513 | Pass
R514 | Pass
R515 | Failure (fails to select all instances) [212276](https://developercommunity.visualstudio.com/content/problem/212276/rename-of-member-of-class-template-argument-fails.html)
R516 | Pass
R517 | Pass
R518 | Pass
R519 | Pass
R520 | Pass
R521 | Pass
R522 | Failure (fails to select all instances) [212276](https://developercommunity.visualstudio.com/content/problem/212276/rename-of-member-of-class-template-argument-fails.html)
R523 | Pass
R524 | Pass
R525 | Pass
R526 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R527 | Failure (pops up symbol dialog) [212279](https://developercommunity.visualstudio.com/content/problem/212279/rename-of-template-class-declaration-pops-up-symbo.html)
R528 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R529 | Pass
R530 | Pass
R531 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R532 | Pass
R533 | Pass
R534 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R535 | Pass
R536 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R537 | Pass
R538 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R539 | Pass
R540 | Failure (fails to select all instances) [212291](https://developercommunity.visualstudio.com/content/problem/212291/renaming-a-template-specialization-doesnt-select-b.html)
R541 | Pass
R542 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R543 | Pass
R544 | Failure (fails to select all instances) [212298](https://developercommunity.visualstudio.com/content/problem/212298/renaming-a-nested-type-in-a-template-class-fails-t.html)
R545 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R546 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R547 | Failure (fails to select all instances) [212298](https://developercommunity.visualstudio.com/content/problem/212298/renaming-a-nested-type-in-a-template-class-fails-t.html)
R548 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R549 | Pass
R550 | Failure (fails to select all instances) [212298](https://developercommunity.visualstudio.com/content/problem/212298/renaming-a-nested-type-in-a-template-class-fails-t.html)
R551 | Failure (fails to select all instances) [212298](https://developercommunity.visualstudio.com/content/problem/212298/renaming-a-nested-type-in-a-template-class-fails-t.html)
R552 | Pass
R553 | Failure (fails to rename selected instance) [212300](https://developercommunity.visualstudio.com/content/problem/212300/renaming-use-of-a-template-class-member-fails-to-r.html)
R554 | Pass
R555 | Failure (fails to rename selected instance) [212300](https://developercommunity.visualstudio.com/content/problem/212300/renaming-use-of-a-template-class-member-fails-to-r.html)
R556 | Pass
R557 | Failure (fails to rename selected instance) [212300](https://developercommunity.visualstudio.com/content/problem/212300/renaming-use-of-a-template-class-member-fails-to-r.html)
R558 | Pass
R559 | Failure (fails to rename selected instance) [212300](https://developercommunity.visualstudio.com/content/problem/212300/renaming-use-of-a-template-class-member-fails-to-r.html)
R560 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R561 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R562 | n/a
R563 | Pass
R564 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R565 | Failure (use in decltype not selected) [212301](https://developercommunity.visualstudio.com/content/problem/212301/rename-of-function-argument-doesnt-select-usage-in.html)
R566 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R567 | Failure (use in decltype not selected) [212301](https://developercommunity.visualstudio.com/content/problem/212301/rename-of-function-argument-doesnt-select-usage-in.html)
R568 | Failure (selects unrelated instances) [212302](https://developercommunity.visualstudio.com/content/problem/212302/rename-of-identifier-in-decltype-expression-select.html)
R569 | Failure (selects unrelated instances) [212302](https://developercommunity.visualstudio.com/content/problem/212302/rename-of-identifier-in-decltype-expression-select.html)
R570 | Pass
R571 | Failure (use in decltype not selected) [212301](https://developercommunity.visualstudio.com/content/problem/212301/rename-of-function-argument-doesnt-select-usage-in.html)
R572 | Failure (use in decltype not selected) [212301](https://developercommunity.visualstudio.com/content/problem/212301/rename-of-function-argument-doesnt-select-usage-in.html)
R573 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R574 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R575 | Pass
R576 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R577 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R578 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
R579 | Pass
R580 | Failure (selects unrelated instances) [206921](https://developercommunity.visualstudio.com/content/problem/206921/rename-of-template-argument-selects-unrelated-inst.html)
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
Case | Result
---- | ------
RP1  | Failure (not available) [206947](https://developercommunity.visualstudio.com/content/problem/206947/enhance-change-signature-to-allow-promotion-of-ret.html) 
RP2  | Failure (not available) [206947](https://developercommunity.visualstudio.com/content/problem/206947/enhance-change-signature-to-allow-promotion-of-ret.html) 
RP3  | Failure (selects wrong instances) [206949](https://developercommunity.visualstudio.com/content/problem/206949/change-signature-selects-unrelated-instances-by-de.html)
RP4  | Pass
RP5  | Failure (selects unrelated instances) [206950](https://developercommunity.visualstudio.com/content/problem/206950/change-signature-selects-unrelated-instances.html)
RP6  | Pass
RP7  | Failure (not available) [206947](https://developercommunity.visualstudio.com/content/problem/206947/enhance-change-signature-to-allow-promotion-of-ret.html) 
RP8  | Failure (not available) [206947](https://developercommunity.visualstudio.com/content/problem/206947/enhance-change-signature-to-allow-promotion-of-ret.html) 
RP9  | Failure (not available) [206947](https://developercommunity.visualstudio.com/content/problem/206947/enhance-change-signature-to-allow-promotion-of-ret.html) 

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
