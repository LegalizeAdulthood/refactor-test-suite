# clang-tidy

Home: [clang-tidy](https://clang.llvm.org/extra/clang-tidy/index.html)

Version: 17.0.6

* clang-tidy support may be integrated into an IDE, such as ReSharper for C++.
* All tests performed by invoking clang-tidy from the command-line on a source file.
* clang-tidy checks configured through `.clang-tidy` configuration file
* **Add Block Delimiter** available through check [*readability-braces-around-statements*](https://clang.llvm.org/extra/clang-tidy/checks/readability/braces-around-statements.html)
* **Add Override** available through check [*modernize-use-override*](https://clang.llvm.org/extra/clang-tidy/checks/modernize/use-override.html)
* **Make Method Static** available through check [*readability-convert-member-functions-to-static*](https://clang.llvm.org/extra/clang-tidy/checks/readability/convert-member-functions-to-static.html)
* **Replace `auto_ptr` With `unique_ptr`** available through check [*modernize-replace-auto-ptr*](https://clang.llvm.org/extra/clang-tidy/checks/modernize/replace-auto-ptr.html)
* **Replace Iterative For With Range For** available through check [*modernize-loop-convert*](https://clang.llvm.org/extra/clang-tidy/checks/modernize/loop-convert.html)
* **Replace `NULL`/`0` With `nullptr`** available through check [*modernize-use-nullptr*](https://clang.llvm.org/extra/clang-tidy/checks/modernize/use-nullptr.html)
* **Replace Type With `auto`** available through check [*modernize-use-auto*](https://clang.llvm.org/extra/clang-tidy/checks/modernize/use-auto.html)
* **Simplify Boolean Expression** available through check [*readability-simplify-boolean-expression*](https://clang.llvm.org/extra/clang-tidy/checks/readability/simplify-boolean-expr.html)

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

## Add Override
Case | Result
---- | ------
AO1 | Pass
AO2 | Pass
AO3 | Pass
AO4 | Pass
AO5 | Pass
AO6 | Pass
AO7 | Pass
AO8 | Pass
AO9 | Pass
AO10 | Pass
AO11 | Pass
AO12 | Pass
AO13 | Pass
AO14 | Pass
AO15 | Pass
AO16 | Pass

## Replace auto_ptr With unique_ptr
Case | Result
---- | ------
RAWU1 | Pass
RAWU2 | Pass
RAWU3 | Pass
RAWU4 | Pass

## Replace Iterative For With Range For
Case | Result
---- | ------
RIRF1 | Pass
RIRF2 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF3 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF4 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF5 | Pass
RIRF6 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF7 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF8 | Pass
RIRF9 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF10 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF11 | Pass
RIRF12 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF13 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF14 | Pass
RIRF15 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF16 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF17 | Pass
RIRF18 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF19 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF20 | Pass
RIRF21 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF22 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF23 | Pass
RIRF24 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF25 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF26 | Pass
RIRF27 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF28 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF29 | Pass
RIRF30 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF31 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF32 | Pass
RIRF33 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF34 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF35 | Pass
RIRF36 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF37 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF38 | Pass
RIRF39 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF40 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF41 | Pass
RIRF42 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF43 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF44 | Pass
RIRF45 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF46 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF47 | Pass
RIRF48 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF49 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF50 | Failure (substitutes internal typedefs) [36688](https://llvm.org/show_bug.cgi?id=36688)
RIRF51 | Failure (doesn't recognize caching end compare) [22570](https://github.com/llvm/llvm-project/issues/22570)
RIRF52 | Failure (doesn't recognize caching end compare, reverse loop) [22570](https://github.com/llvm/llvm-project/issues/22570), [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF53 | Failure (doesn't recognize caching end compare) [22570](https://github.com/llvm/llvm-project/issues/22570)
RIRF54 | Failure (doesn't recognize caching end compare, reverse loop) [22570](https://github.com/llvm/llvm-project/issues/22570), [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF55 | Pass
RIRF56 | Failure (doesn't recognize caching end compare, reverse loop) [22570](https://github.com/llvm/llvm-project/issues/22570), [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF57 | Pass
RIRF58 | Pass
RIRF59 | Failure (doesn't recognize 0..N-1 loop) [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF60 | Pass
RIRF61 | Pass
RIRF62 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)
RIRF63 | Pass
RIRF64 | Pass
RIRF65 | Failure (doesn't recognize caching end compare, 0..N-1 loop) [22570](https://github.com/llvm/llvm-project/issues/22570), [22568](https://github.com/llvm/llvm-project/issues/22568)
RIRF66 | Pass
RIRF67 | Pass
RIRF68 | Failure (doesn't recognize reverse loop) [22569](https://github.com/llvm/llvm-project/issues/22569)

## Replace NULL/0 With nullptr
Case | Result
---- | ------
RZNP1   | Pass
RZNP2   | Pass
RZNP3   | Pass
RZNP4   | Pass
RZNP5   | Pass
RZNP6   | Pass
RZNP7   | Pass
RZNP8   | Pass
RZNP9   | Pass
RZNP10  | Pass
RZNP11  | Pass
RZNP12  | Pass
RZNP13  | Pass
RZNP14  | Pass
RZNP15  | Pass
RZNP16  | Pass
RZNP17  | Pass
RZNP18  | Pass
RZNP19  | Pass
RZNP20  | Pass
RZNP21  | Pass
RZNP22  | Pass
RZNP23  | Pass
RZNP24  | Pass
RZNP25  | Pass
RZNP26  | Pass
RZNP27 | Pass
RZNP28 | Pass

## Replace String Literal With Raw String Literal

Case | Result
---- | ------
RAW1 | Pass
RAW2 | Failure (not available)
RAW3 | Failure (not available)
RAW4 | Pass
RAW5 | Pass
RAW6 | Pass
RAW7 | Pass
RAW8 | Pass
RAW9 | Pass
RAW10 | Pass
RAW11 | Pass
RAW12 | Pass

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

## Simplify Boolean Expression
Case | Result
---- | ------
SB1 | Pass
SB2 | Pass
SB3 | Pass
SB4 | Pass
SB5 | Failure
SB6 | Pass
SB7 | Pass
SB8 | Failure
SB9 | Failure
SB10 | Failure
SB11 | Failure
SB12 | Failure
SB13 | Failure
