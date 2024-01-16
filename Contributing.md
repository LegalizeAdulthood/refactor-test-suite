# How To Contribute

There are several ways you can contribute to this test suite:

- [Execute test cases](#execute-missing-test-cases) for products without results
- [Execute test cases](#update-test-cases) for newer versions of existing products
- [Add new test cases](#add-new-test-cases-for-an-existing-refactoring) for existing refactorings
- [Add tests](#add-tests-for-a-new-refactoring) for a new refactoring

All of these are easy!

As you develop test cases, it will be handy to use `git` to record a
safety backstop against which you can run the refactorings and then
discard any changes made to restore the test suite to its original
state.

# Test Cases

All test cases are signalled in source files with a comment of the
form:

```C++
// #TEST#: STF44 Do the stunky fluff refactoring below
```

The `#TEST#` token indicates every line in the suite where a test case is
located.  The `STF44` token is the unique identifier for this test case.
The `STF` prefix is a short way of identifying the particular refactoring.
For instance, `R` is for Rename.  The numbers indicate the specific
test case for the refactoring.  The remainder of the comment tells the
user what to do in order to invoke the test case.

To assist in performing testing a number of [support scripts](#support-scripts)
have added to the repository.  They are described at the end of this
document.

## Execute Missing Test Cases

Tools for which only preliminary results are available need test cases
executed for the first time.  The workflow is identical to the
[update test cases](#update-test-cases) workflow, except that the
tests are being executed for the first time.

1. Fork the github repository.
1. Create a new branch for your results.
1. Build the code using the CMake workflow preset: `cmake --workflow --preset default`
1. Open the results markdown file for the tool.
1. Look for tests with no results.
1. Execute the test cases.
1. Update the results.
1. Commit the results to your git branch.
   You can record the results with one commit per refactoring or
   one commit for all the updated results.
1. Update the version information for the tool at the top of the results file.
1. Run `ctest --preset default` to validate your changes to the results file.
1. Use the [tool-summary](#executable-tool-summary) support tool to regenerate the
   appropriate summary results markdown for the tool.
1. Issue a pull request with your changes.

## Update Test Cases

When new versions of a refactoring tool come out, we'll want to check
any previous failures to see if they've been fixed and check for
regressions of previously passing test cases.

First, we'll want to check the failures:

1. Fork the github repository.
1. Create a new branch for your results.
1. Build the code using the CMake workflow preset: `cmake --workflow --preset default`
1. Open the results markdown file for the tool.
1. Look for `Failure` markers and execute those tests.
1. Update the results.
1. Commit the results to your git branch.
   You can record the results with one commit per refactoring or
   one commit for all the updated results.
1. Update the version information for the tool at the top of the results file.
1. Add a note at the top of the results file indicating which refactorings
   were tested for the updated version.
1. Run `ctest --preset default` to validate your changes to the results file.
1. Use the support tool [tool-summary](#executable-tool-summary) to regenerate the
   appropriate summary results markdown for the tool.
1. Issue a pull request with your changes.

Re-checking the passing tests to look for regressions is similar,
but is more work.  Make a note at the top of the results file indicating
which tests were executed against the updated version.

## Add New Test Cases for an Existing Refactoring

1. Fork the github repository.
1. Create a new branch for your test cases.
1. Locate the source file for the existing test cases.
1. Review the existing test cases to make sure that your new tests
   check a different scenario than existing test cases.
1. Add the new test cases to the source files using temporary test markers of the form
   `#GOINK#: ID <instructions>` instead of `#TEST#: ID <instructions>`.
   This temporary marker will prevent automated test failures while you develop
   the test cases.  Add runtime tests for the new test cases to validate the semantics
   of the code being refactored.
1. After all the test cases have been added, use the support tool
   [add-tests](#executable-add-tests) to adjust the temporary test markers with
   appropriate test markers for the refactoring, numbering new test cases for you and
   adding the test cases to all the results files that support this refactoring.
1. Build the test suite.  You should get no errors, but warnings about missing diffs
   for your new test cases.
1. Commit the test cases with git to have a record of the source code
   before it is refactored.
1. Execute the test cases and record the results:
   1. Add the test case id and result to the table
   1. If the test case failed, consider creating a bug report with
      the product vendor.  Include a copy of the test suite
       by creating an archive with `git archive`, e.g. `git archive -o before.zip HEAD`
   1. Add a link to the bug report in the results table.
1. Revert any changes made by the refactoring to restore the original test case code.
1. The [support scripts](#support-scripts) can assist you in recording test results,
   read through them before executing your new test cases.
1. Build the test suite to validate that all warnings about missing diffs are gone.
1. Use the support tool [test-results](#executable-test-results) to validate your changes
   to the results file for the tool you're testing.
1. Run `ctest --preset default` to validate your changes to the results file for all the tools.
1. Use the [tool-summary](#executable-tool-summary) support tool to regenerate the summary
   reports.
1. Issue a pull request with your changes, which should include:
   1. Modified test case files.
   1. Added result diffs for new test cases.
   1. Updated tool results file for the tool you tested.
   1. Updated tool results files with blank results for any other tools supporting the refactoring.
   1. Updated summary results.

## Add Tests for a New Refactoring

1. Fork the github repository.
1. Create a new branch for your test cases.
1. Create a new source file to hold the test cases.
1. Update the list of refactoring names and abbreviations in `Tools/TestCases/TestCases.cpp`
   to include a new entry for your refactoring.  By default refactorings require a diff for
   each test case.
1. Add the source file to the `CMakeLists.txt` build
   1. If the source file depends on language features after C++11, add it to
      the appropriate library target named after that C++ version, e.g. `refactor-20`.
1. Declare the runtime test function in `RefactorTest.h`.
   If the runtime function depends on newer versions of C++,
   guard the declaraiont with the appropriate preprocessor symbol from `Config.h`
   and declare an empty inline function if the symbol is not defined.
1. Call the runtime test function from `RefactorTest.cpp`
1. Add the runtime test function to the new source file.
1. Build and execute the test suite to make sure this works.
1. Add a new section with a table of results to the relevant
   product file in the `results` directory.
1. Commit this initial change.
1. Add new test cases:
   1. Add new test cases using the temporary test marker `#GOINK#: ID <instructions>`
   1. Add a test case to the new source file and perform runtime checks where
      feasible to ensure that the refactoring hasn't changed the meaning of
      the code.  The file `Require.h` contains a simple function for comparing
      an expected value with an actual value.
   1. After all the test cases have been added, use the support tool
      [add-tests](#executable-add-tests) to adjust the temporary test markers with
      appropriate test markers for the refactoring, numbering new test cases for you and
      adding the test cases to all the results files that support this refactoring.
   1. Build the test suite.  You should get no errors, but warnings about missing diffs
      for your new test cases.
   1. Commit the test case with git to have a record of the source code
      before it is refactored.
   1. Execute the test cases and record the results:
      1. Add the test case id and result to the table.
      2. If the test case failed, consider creating a bug report with the product
         vendor.  Include a copy of the test suite by creating an archive with
         `git archive`.
      3. Add a link to the bug report in the results table.
      4. Revert any changes made by the refactoring to restore the
         original test case code between test cases.
      5. The [support scripts](#support-scripts) can be of assistance in executing test cases.
1. Build the test suite and validate that there are no warnings about missing diffs.
1. Use the support tool [test-results](#executable-test-results) to validate your changes
   to the results file for the tool you're testing.
1. Run `ctest --preset default` to validate your changes to the results file for all the tools.
1. Use the [tool-summary](#executable-tool-summary) support tool to regenerate the summary
   reports.
1. Issue a pull request with your changes.

# Repository Organization

The repository contains two types of source files: tests and supporting
tool source code.  All test cases are located in the directory [`RefactorTest`](RefactorTest/).
All supporting tool source code is located in the directory [`Tools`](Tools/).

Markdown files reporting the results of applying test cases against a
refactoring tool are in the [`results`](results/) directory.  Reports for
tools that have been exercised with a significant number of tests are in
this directory.  Some tools only have only been tested with a few test cases
and their results are reported in the [`results/preliminary`](results/preliminary/)
directory.

To assist in validating the result of refactorings, source code diffs are
recorded.  The directory [`results/diffs`](results/diffs/) has diffs for
individual test cases and the directory [`results/file-diffs`](results/file-diffs/)
contains diffs for entire files for tools that operate in batch mode on
entire source files.

# Support Scripts

Since the test cases must be invoked manually, it can become tedious
to perform a large batch of tests.  To assist in this process, some
simple Windows batch files have been created in the directory
[`results/scripts`](results/scripts/).  The workflow used by these
scripts assumes that the `results/scripts` directory and the CMake
build directory containing support tool binaries, e.g. `build/Debug/bin`,
are in the user's executable search path.  There is also a dependency
on the programs `diff` and `git`.  (Windows users will likely find
`diff` in their git distribution, e.g. `%ProgramFiles%\Git\usr\bin`.)

1. `check.bat [id]`: creates a git diff of the `RefactorTest` directory
   into a temporary file and compares to the diff in `results/diffs/[id].txt`
   to the diff of the git workspace.  Comment-only lines are stripped
   to make it easier to review the 'diff of diffs'.
2. `file-check.bat [test]`: similar to `check`, creates a git diff of
   the `RefactorTest` directory into a temporary file and compares to
   the file diff in `results/file-diffs/[test].txt`.  Comment-only lines
   are stripped to make it easier to review the 'diff of diffs'.
3. `update.bat [id]`: creates a git diff of the `RefactorTest` directory
   into the file `results/diffs/[id].txt` and then shows a git diff of
   the updated diff.  The user is expected to add the updated diff to
   the index in order to record the update in a commit.
4. `restore.bat`: adds the `results` directory to the current git index
   and restores any changes made to the `RefactorTest` directory.  The
   idea is that after a refactoring test case has been exercised and
   the results recorded in the `Results.md` file for the tool, the
   changes to the results are added to the index and the test case source
   files are restored to their original state to prepare for the next
   test case.
5. `check-seq.bat [test] [num]`: enters a loop for exercising test cases
   starting at the given number and increasing.   The user is prompted
   to execute a test case and then the results are compared against the
   recorded diff for the test case and the user is prompted to continue
   with the next test case.  If RETURN is pressed, the script restores
   the workspace by calling `restore.bat` and then continues to the next
   numbered test case.
6. `run-clang-tidy.bat [check] [file]`: runs `clang-tidy` with the given
   check on the given source file in 'fix' mode to apply generated fixits
   to the given file.  ClangTidy depends on a `compile_commands.json`
   compilation database, generated by the CMake Ninja generator using
   the `ninja` CMake configuration preset.

# Support Tools

Several tools have been written to assist in the authoring of tests,
reporting test results for a tool and generating reports.

## Library test-cases

This static library contains common code used to scan test case source
files and test report markdown files.  The results of the scan produce
data structures that can be used by the tools.

The file `Tools/TestCases/TestCases.cpp` contains a mapping of test names
to their identifier abbreviation, e.g. "Rename" corresponds to "R".

## Executable test-diffs

Example: `test-diffs RefactorTest results/diffs`

The executable test-diffs ensures that test cases have an associated
diff.  It runs a a post-build step every time the refactoring test suite
is built and issues a warning for any non-deprecated test label that
does not have an associated diff.

## Executable test-names

Example: `test-names RefactorTest > Tool.md`

The executable test-names checks for missing test cases and generates
a prototype markdown file for a tool, named `Tool.md`, in the build
directory.  The prototype markdown file can be used to add or update
the results for a tool.  Since all test case identifiers are consecutive,
missing test case identifiers indicate some sort of problem in the test
case ids.

## Executable test-results

Example: `test-results RefactorTest results/ClangTidyResults.md`

The executable test-results can be used to validate that the results for
a tool are consistent with the test cases.  It is an error if a deprecated
test case is not marked deprecated in the tool results, or if a test case
is not listed for a tool.  A tool is not required to report list test cases
for refactorings it does not support, but if it supports a refactoring, then
all test cases must be listed.  If test results are not known then the result
field of the table is left empty.  Missing test results are reported as warnings.

[CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) test cases are
generated for all the tools for which results are recorded in the repository.
These tests can be built using the [CMake preset](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
with the command `ctest --preset default` in the repository directory.

## Executable tool-summary

Example: `tool-summary results > SummaryResults.md`

The executable tool-summary collects the results for a group of tools and
generates a summary markdown file for the group to standard output.
This is used to regenerate the [summary results](SummaryResults.md) and
[preliminary results](PreliminaryResults.md) reports when test results for a
tool are updated.

## Executable add-tests

Example: `add-tests RefactorTest R RefactorTest/NewRename.cpp results`

The executable add-tests scans the test case directory for existing test cases
and replaces temporary test markers in a source file with consecutive markers
for new test cases.  The temporary markers are of the form:

```C++
// #GOINK#: ID <instructions>
```

The text `#GOINK#` is replaced with `#TEST#`, the `ID` text is ignored and
replaced with test ids for the given prefix, starting after the last test
case number found in the test case directory.

Using a temporary test case marker while developing tests keeps the automated
tests passing while new test cases are under development.  Once add-tests has
been run and consecutive test ids have been added, tool markdown files can be
updated from the generated `Tool.md` and result diffs can be added as the cases
are tested.

## Executable renumber-tests

Example: `renumber-tests RefactorTest R R results`

The executable renumber-tests is used to renumber the test cases sequentially
within the source files.  This makes the test cases easier to execute since
results can be recorded sequentially for a tool.  The tool will renumber the
test markers in source files, in results files and update the corresponding
test case diffs.  The tool assumes that a single file only has test cases for
a single refactoring.  All the test files in the test suite follow this pattern.

Use this tool if you add new test cases somewhere in the middle of an existing
test case source file.  First run add-tests to add the new test cases where they
are in the file and then use renumber-tests to resequence all the tests, including
your new tests, as a single group of tests.  Best practice is to git commit the
results of add-tests and then make a separate commit for the results of renumber-tests.

## Executable drop-comments

Example: `cat results/diffs/ABD1.txt | drop-comments`

The executable drop-comments filters out any lines on standard input
that contain only a C++ single-line comment.  This is used to simplify
diffs when checking the result of a refactorign.
