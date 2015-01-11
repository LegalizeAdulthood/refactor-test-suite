# How To Contribute

There are several ways you can contribute to this test suite:

- Add tests for a new refactoring
- Add new test cases for existing refactorings
- Execute test cases for newer versions of existing products
- Execute test cases for products without results

All of these are easy!

As you develop test cases, it will be handy to use `git` to record a
safety backstop against which you can run the refactorings and then
discard any changes made to restore the test suite to its original
state.

All test cases are signalled in source files with a comment of the
form:

```C++
// #TEST#: STF44 Do the stunky fluff refactoring below
```

The `#TEST#` token indicates every line in the suite where a test case is
located.  The `STF44` token is the unique identifier for this test case.
The `STF` prefix is a short way of identifying the particular refactoring.
For instance, `MM` is for Move Method.  The numbers indicate the specific
test case for the refactoring.  The remainder of the comment tells the
user what to do in order to invoke the test case.

## Add Tests for a New Refactoring

1. Fork the github repository.
1. Create a new branch for your test cases.
1. Create a new source file to hold the test cases.
1. Add the source file to the `CMakeLists.txt` build
1. Declare the runtime test function in `stdafx.h`
1. Call the runtime test function from `RefactorTest.cpp`
1. Add the runtime test function to the new source file.
1. Build and execute the test suite to make sure this works.
1. Add a new section with a table of results to the relevant
  product file in the `results` directory.
1. Commit this initial change.
1. Add new test cases:
 1. Add a test case to the new source file and perform runtime checks where
   feasible to ensure that the refactoring hasn't changed the meaning of
   the code.  The file `Require.h` contains a simple function for comparing
   an expected value with an actual value.
 1. Commit the test case with git to have a record of the source code
   before it is refactored.
 1. Execute the test case and record the results:
    1. Add the test case id and result to the table.
    2. If the test case failed, create a bug report with the product
       vendor.  Include a copy of the test suite by creating an archive with
       `git archive`.
    3. Add a link to the bug report in the results table.
 1. Revert any changes made by the refactoring to restore the
    original test case code.
 1. Repeat for any remaining test cases.
1. Issue a pull request with your changes.

## Add New Test Cases for an Existing Refactoring

1. Fork the github repository.
1. Create a new branch for your test cases.
1. Locate the source file for the existing test cases.
1. Review the existing test cases to make sure that your new tests
  check a different scenario than existing test cases.
1. For each new test case:
 1. Add a test case to the source file.
 1. Commit the test case with git to have a record of the source code
   before it is refactored.
 1. Execute the test case and record the results:
    1. Add the test case id and result to the table
    1. If the test case failed, create a bug report with
       the product vendor.  Include a copy of the test suite
       by creating an archive with `git archive`.
    1. Add a link to the bug report in the results table.
 1. Revert any changes made by the refactoring to restore the
   original test case code.
 1. Repeat for any remaining test cases.
1. Issue a pull request with your changes.

## Execute Test Cases for Newer Versions of Existing Products

## Execute Test Cases for Products Without Results
