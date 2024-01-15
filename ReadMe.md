[![CMake workflow](https://github.com/LegalizeAdulthood/refactor-test-suite/actions/workflows/cmake.yml/badge.svg)](https://github.com/LegalizeAdulthood/refactor-test-suite/actions/workflows/cmake.yml)

# Introduction

This is a test suite for C++ refactoring tools.  It consists of
a set of source files with comments marking different locations
in the code where a refactoring could be tested.

Over time, I've tried to add runtime assertions to the code to
give an additional level of testing around the refactored area.
While these assertions help to verify the validity of a refactoring
applied by a tool, the pass or fail of a test case is up to the
person invoking the refactoring tool and examining the diffs.

In general, when evaluating results from a refactoring tool,
you should treat the tool as skeptically as you would treat
any other programmer on your team.  If you wouldn't accept a
set of diffs from a human, then you shouldn't accept those
same diffs from a computer.

The original release of the test suite is described
[in this blog post](http://legalizeadulthood.wordpress.com/2010/02/02/c-refactoring-tools-test-suite-available/).

This test suite is explained in detail in a [Utah C++ Programmers](https://utahcpp.wordpress.com)
video [Refactoring Tools Roundup](https://www.youtube.com/watch?v=TzQ4-zoDG44) from January, 2024.

# [How To Contribute](Contributing.md)

# Results (January, 2024)

## [Summary Results](SummaryResults.md)

Results for tools with significant testing.

- [CLion 2023.3.2](results/CLionResults.md)
- [clang-tidy 17.0.6](results/ClangTidyResults.md)
- [ReSharper for C++ 2023.3.2](results/ReSharperCppResults.md)
- [Visual AssistX 10.9.2508.0](results/VisualAssistXResults.md)
- [Visual Studio 2022, 17.7.5](results/VisualStudioResults.md)

## [Preliminary Results](PreliminaryResults.md)

Preliminary results for tools with minimal testing.

- [Apple Xcode](results/AppleXcodeResults.md)
- [Eclipse CDT](results/EclipseCDTResults.md)
- [Qt Creator](results/QtCreatorResults.md)

## Unknown Results

- [Cevelop](https://www.cevelop.com/) - Extensions for Eclipse CDT
- [Code::Blocks](http://www.codeblocks.org/)
- [KDevelop](https://www.kdevelop.org/) - [Refactoring](https://community.kde.org/KDevelop/RefactoringTools)

# Building

CMake presets are provided for building the code.  The
`default` workflow preset configures, builds the code
and runs the tests.  To rebuild the test suite and perform
internal validation, simply build the code using the
`default` preset for configuration and build.  To run the
CTest related tests, the `default` preset can be used.

Examples:

```shell
cmake --preset default               # configure
cmake --build --preset default       # build
ctest --preset default               # test
cmake --workflow --preset default    # configure, build and test
```

The `refactor-test-suite` target compiles all the source code
to be refactored.  The code contains some runtime checks to
validate that the semantics of refactored code has not changed.
The test suite executes as a post-build event so that simply
building `refactor-test-suite` validates the semantics as
part of the build.

The CTest related tests perform validation of the results
files for the tools.

To execute `clang-tidy` related tests, a `compile_commands.json`
compilation database is required.  This can be generated with the
`ninja` configuration preset:

```shell
cmake --preset ninja
```

See the documentation on [how to contribute](Contributing.md) for
information about how to execute tests.
