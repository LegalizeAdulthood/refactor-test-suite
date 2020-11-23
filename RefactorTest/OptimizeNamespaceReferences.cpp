// #TEST#: ONR1 Optimize away these headers
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// Removes unused namespace references (unused #include files in C++).

void TestOptimizeNamespaceReferences() {}
