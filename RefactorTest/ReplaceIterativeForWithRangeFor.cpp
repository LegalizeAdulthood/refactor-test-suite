#include "stdafx.h"
#include <cassert>
#include <vector>

static int fileDataImplicitSize[] = { 1, 0 };

static void TestFileArrayImplicitSize()
{
    // #TEST#: RIRF1 Replace iterative for with range for
    for (int i = 0; i < 2; ++i)
    {
        ++fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 2);
    assert(fileDataImplicitSize[1] == 1);

    // #TEST#: RIRF2 Replace iterative for with range for
    for (int i = 0; i <= 1; ++i)
    {
        --fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 1);
    assert(fileDataImplicitSize[1] == 0);

    // #TEST#: RIRF3 Replace iterative for with range for
    for (int i = 1; i >= 0; --i)
    {
        ++fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 2);
    assert(fileDataImplicitSize[1] == 1);

    // #TEST#: RIRF4 Replace iterative for with range for
    for (int i = 0; i < sizeof(fileDataImplicitSize)/sizeof(fileDataImplicitSize[0]); ++i)
    {
        --fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 1);
    assert(fileDataImplicitSize[1] == 0);

    // #TEST#: RIRF5 Replace iterative for with range for
    for (int i = 0; i <= sizeof(fileDataImplicitSize)/sizeof(fileDataImplicitSize[0])-1; ++i)
    {
        ++fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 2);
    assert(fileDataImplicitSize[1] == 1);

    // #TEST#: RIRF6 Replace iterative for with range for
    for (int i = sizeof(fileDataImplicitSize)/sizeof(fileDataImplicitSize[0])-1; i >= 0; --i)
    {
        --fileDataImplicitSize[i];
    }
    assert(fileDataImplicitSize[0] == 1);
    assert(fileDataImplicitSize[1] == 0);
}

static int const constantFileDataImplicitSize[] = { 'f', 'o', 'o' };

void TestConstantFileArrayImplicitSize()
{
    int sum = 0;
    // #TEST#: RIRF7 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF8 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF9 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF10 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantFileDataImplicitSize)/sizeof(constantFileDataImplicitSize[0]); ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF11 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantFileDataImplicitSize)/sizeof(constantFileDataImplicitSize[0])-1; ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF12 Replace iterative for with range for
    for (int i = sizeof(constantFileDataImplicitSize)/sizeof(constantFileDataImplicitSize[0])-1; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    assert(int('f') + int('o') + int('o') == sum);
}

static int fileDataExplicitSize[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

static void TestFileArrayExplicitSize()
{
    // #TEST#: RIRF13 Replace iterative for with range for
    for (int i = 0; i < 10; ++i)
    {
        ++fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 10);
    assert(fileDataExplicitSize[1] == 9);
    assert(fileDataExplicitSize[2] == 8);
    assert(fileDataExplicitSize[3] == 7);
    assert(fileDataExplicitSize[4] == 6);
    assert(fileDataExplicitSize[5] == 5);
    assert(fileDataExplicitSize[6] == 4);
    assert(fileDataExplicitSize[7] == 3);
    assert(fileDataExplicitSize[8] == 2);
    assert(fileDataExplicitSize[9] == 1);

    // #TEST#: RIRF14 Replace iterative for with range for
    for (int i = 0; i <= 9; ++i)
    {
        --fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 9);
    assert(fileDataExplicitSize[1] == 8);
    assert(fileDataExplicitSize[2] == 7);
    assert(fileDataExplicitSize[3] == 6);
    assert(fileDataExplicitSize[4] == 5);
    assert(fileDataExplicitSize[5] == 4);
    assert(fileDataExplicitSize[6] == 3);
    assert(fileDataExplicitSize[7] == 2);
    assert(fileDataExplicitSize[8] == 1);
    assert(fileDataExplicitSize[9] == 0);

    // #TEST#: RIRF15 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        ++fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 10);
    assert(fileDataExplicitSize[1] == 9);
    assert(fileDataExplicitSize[2] == 8);
    assert(fileDataExplicitSize[3] == 7);
    assert(fileDataExplicitSize[4] == 6);
    assert(fileDataExplicitSize[5] == 5);
    assert(fileDataExplicitSize[6] == 4);
    assert(fileDataExplicitSize[7] == 3);
    assert(fileDataExplicitSize[8] == 2);
    assert(fileDataExplicitSize[9] == 1);

    // #TEST#: RIRF16 Replace iterative for with range for
    for (int i = 0; i < sizeof(fileDataExplicitSize)/sizeof(fileDataExplicitSize[0]); ++i)
    {
        --fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 9);
    assert(fileDataExplicitSize[1] == 8);
    assert(fileDataExplicitSize[2] == 7);
    assert(fileDataExplicitSize[3] == 6);
    assert(fileDataExplicitSize[4] == 5);
    assert(fileDataExplicitSize[5] == 4);
    assert(fileDataExplicitSize[6] == 3);
    assert(fileDataExplicitSize[7] == 2);
    assert(fileDataExplicitSize[8] == 1);
    assert(fileDataExplicitSize[9] == 0);

    // #TEST#: RIRF17 Replace iterative for with range for
    for (int i = 0; i <= sizeof(fileDataExplicitSize)/sizeof(fileDataExplicitSize[0])-1; ++i)
    {
        ++fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 10);
    assert(fileDataExplicitSize[1] == 9);
    assert(fileDataExplicitSize[2] == 8);
    assert(fileDataExplicitSize[3] == 7);
    assert(fileDataExplicitSize[4] == 6);
    assert(fileDataExplicitSize[5] == 5);
    assert(fileDataExplicitSize[6] == 4);
    assert(fileDataExplicitSize[7] == 3);
    assert(fileDataExplicitSize[8] == 2);
    assert(fileDataExplicitSize[9] == 1);

    // #TEST#: RIRF18 Replace iterative for with range for
    for (int i = sizeof(fileDataExplicitSize)/sizeof(fileDataExplicitSize[0])-1; i >= 0; --i)
    {
        --fileDataExplicitSize[i];
    }
    assert(fileDataExplicitSize[0] == 9);
    assert(fileDataExplicitSize[1] == 8);
    assert(fileDataExplicitSize[2] == 7);
    assert(fileDataExplicitSize[3] == 6);
    assert(fileDataExplicitSize[4] == 5);
    assert(fileDataExplicitSize[5] == 4);
    assert(fileDataExplicitSize[6] == 3);
    assert(fileDataExplicitSize[7] == 2);
    assert(fileDataExplicitSize[8] == 1);
    assert(fileDataExplicitSize[9] == 0);
}

static int const constantFileDataExplicitSize[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

static void TestConstantFileArrayExplicitSize()
{
    int sum = 0;
    // #TEST#: RIRF19 Replace iterative for with range for
    for (int i = 0; i < 10; ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);

    sum = 0;
    // #TEST#: RIRF20 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);

    sum = 0;
    // #TEST#: RIRF21 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);

    sum = 0;
    // #TEST#: RIRF22 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantFileDataExplicitSize)/sizeof(constantFileDataExplicitSize[0]); ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);

    sum = 0;
    // #TEST#: RIRF23 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantFileDataExplicitSize)/sizeof(constantFileDataExplicitSize[0])-1; ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);

    sum = 0;
    // #TEST#: RIRF24 Replace iterative for with range for
    for (int i = sizeof(constantFileDataExplicitSize)/sizeof(constantFileDataExplicitSize[0])-1; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    assert(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 == sum);
}

static void TestFileArray()
{
    TestFileArrayImplicitSize();
    TestFileArrayExplicitSize();
    TestConstantFileArrayImplicitSize();
    TestConstantFileArrayExplicitSize();
}

static void TestStackArrayImplicitSize()
{
    int stackDataImplicitSize[] = { 'f', 'o', 'o' };
    // #TEST#: RIRF25 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        ++stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'g');
    assert(stackDataImplicitSize[1] == 'p');
    assert(stackDataImplicitSize[2] == 'p');

    // #TEST#: RIRF26 Replace iterative for with range for
    for (int i = 0; i <= 2; ++i)
    {
        --stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'f');
    assert(stackDataImplicitSize[1] == 'o');
    assert(stackDataImplicitSize[2] == 'o');

    // #TEST#: RIRF27 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        ++stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'g');
    assert(stackDataImplicitSize[1] == 'p');
    assert(stackDataImplicitSize[2] == 'p');

    // #TEST#: RIRF28 Replace iterative for with range for
    for (int i = 0; i < sizeof(stackDataImplicitSize)/sizeof(stackDataImplicitSize[0]); ++i)
    {
        --stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'f');
    assert(stackDataImplicitSize[1] == 'o');
    assert(stackDataImplicitSize[2] == 'o');

    // #TEST#: RIRF29 Replace iterative for with range for
    for (int i = 0; i <= sizeof(stackDataImplicitSize)/sizeof(stackDataImplicitSize[0])-1; ++i)
    {
        ++stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'g');
    assert(stackDataImplicitSize[1] == 'p');
    assert(stackDataImplicitSize[2] == 'p');

    // #TEST#: RIRF30 Replace iterative for with range for
    for (int i = sizeof(stackDataImplicitSize)/sizeof(stackDataImplicitSize[0])-1; i >= 0; --i)
    {
        --stackDataImplicitSize[i];
    }
    assert(stackDataImplicitSize[0] == 'f');
    assert(stackDataImplicitSize[1] == 'o');
    assert(stackDataImplicitSize[2] == 'o');
}

static void TestConstantStackArrayImplicitSize()
{
    int const constantStackDataImplicitSize[] = { 'b', 'a', 'r' };
    int sum = 0;
    // #TEST#: RIRF31 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);

    sum = 0;
    // #TEST#: RIRF32 Replace iterative for with range for
    for (int i = 0; i <= 2; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);

    sum = 0;
    // #TEST#: RIRF33 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);

    sum = 0;
    // #TEST#: RIRF34 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantStackDataImplicitSize)/sizeof(constantStackDataImplicitSize[0]); ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);

    sum = 0;
    // #TEST#: RIRF35 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantStackDataImplicitSize)/sizeof(constantStackDataImplicitSize[0])-1; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);

    sum = 0;
    // #TEST#: RIRF36 Replace iterative for with range for
    for (int i = sizeof(constantStackDataImplicitSize)/sizeof(constantStackDataImplicitSize[0])-1; i >= 0; --i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    assert(int('b') + int('a') + int('r') == sum);
}

static void TestStackArrayExplicitSize()
{
    int stackDataExplicitSize[4] = { 'q', 'u', 'x' };
    // #TEST#: RIRF37 Replace iterative for with range for
    for (int i = 0; i < 4; ++i)
    {
        ++stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'r');
    assert(stackDataExplicitSize[1] == 'v');
    assert(stackDataExplicitSize[2] == 'y');
    assert(stackDataExplicitSize[3] == 1);

    // #TEST#: RIRF38 Replace iterative for with range for
    for (int i = 0; i <= 3; ++i)
    {
        --stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'q');
    assert(stackDataExplicitSize[1] == 'u');
    assert(stackDataExplicitSize[2] == 'x');
    assert(stackDataExplicitSize[3] == 0);

    // #TEST#: RIRF39 Replace iterative for with range for
    for (int i = 3; i >= 0; --i)
    {
        ++stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'r');
    assert(stackDataExplicitSize[1] == 'v');
    assert(stackDataExplicitSize[2] == 'y');
    assert(stackDataExplicitSize[3] == 1);

    // #TEST#: RIRF40 Replace iterative for with range for
    for (int i = 0; i < sizeof(stackDataExplicitSize)/sizeof(stackDataExplicitSize[0]); ++i)
    {
        --stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'q');
    assert(stackDataExplicitSize[1] == 'u');
    assert(stackDataExplicitSize[2] == 'x');
    assert(stackDataExplicitSize[3] == 0);

    // #TEST#: RIRF41 Replace iterative for with range for
    for (int i = sizeof(stackDataExplicitSize)/sizeof(stackDataExplicitSize[0])-1; i >= 0; --i)
    {
        ++stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'r');
    assert(stackDataExplicitSize[1] == 'v');
    assert(stackDataExplicitSize[2] == 'y');
    assert(stackDataExplicitSize[3] == 1);

    // #TEST#: RIRF42 Replace iterative for with range for
    for (int i = sizeof(stackDataExplicitSize)/sizeof(stackDataExplicitSize[0])-1; i >= 0; --i)
    {
        --stackDataExplicitSize[i];
    }
    assert(stackDataExplicitSize[0] == 'q');
    assert(stackDataExplicitSize[1] == 'u');
    assert(stackDataExplicitSize[2] == 'x');
    assert(stackDataExplicitSize[3] == 0);
}

static void TestConstantStackArrayExplicitSize()
{
    int const constantStackdataExlicitSize[4] = { 's', 'o', 'x' };
    int sum = 0;
    // #TEST#: RIRF43 Replace iterative for with range for
    for (int i = 0; i < 4; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);

    sum = 0;
    // #TEST#: RIRF44 Replace iterative for with range for
    for (int i = 0; i <= 3; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);

    sum = 0;
    // #TEST#: RIRF45 Replace iterative for with range for
    for (int i = 3; i >= 0; --i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);

    sum = 0;
    // #TEST#: RIRF46 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantStackdataExlicitSize)/sizeof(constantStackdataExlicitSize[0]); ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);

    sum = 0;
    // #TEST#: RIRF47 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantStackdataExlicitSize)/sizeof(constantStackdataExlicitSize[0])-1; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);

    sum = 0;
    // #TEST#: RIRF48 Replace iterative for with range for
    for (int i = sizeof(constantStackdataExlicitSize)/sizeof(constantStackdataExlicitSize[0])-1; i >= 0; --i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    assert(int('s') + int('o') + int('x') == sum);
}

static void TestStackArray()
{
    TestStackArrayImplicitSize();
    TestConstantStackArrayImplicitSize();
    TestStackArrayExplicitSize();
    TestConstantStackArrayExplicitSize();
}

static void TestArrays()
{
    TestStackArray();
    TestFileArray();
}

static void TestContainersWithIterators()
{
    std::vector<int> c;
    c.push_back('f');
    c.push_back('o');
    c.push_back('o');

    int sum = 0;
    // #TEST#: RIRF49 Replace iterative for with range for
    for (std::vector<int>::const_iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF50 Replace iterative for with range for
    for (std::vector<int>::const_iterator it = c.begin(), end = c.end();
        end != it; ++it)
    {
        sum += *it;
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF51 Replace iterative for with range for
    for (std::vector<int>::const_reverse_iterator it = c.rbegin(), end = c.rend();
        end != it; ++it)
    {
        sum += *it;
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF52 Replace iterative for with range for
    for (std::vector<int>::const_iterator it = c.cbegin(), end = c.cend();
        end != it; ++it)
    {
        sum += *it;
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF53 Replace iterative for with range for
    for (std::vector<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(int('f') + int('o') + int('o') == sum);

    // #TEST#: RIRF54 Replace iterative for with range for
    for (std::vector<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++*it;
    }
    assert('g' == c[0]);
    assert('p' == c[1]);
    assert('p' == c[2]);

    // #TEST#: RIRF55 Replace iterative for with range for
    for (std::vector<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --*it;
    }
    assert('f' == c[0]);
    assert('o' == c[1]);
    assert('o' == c[2]);
}

static void TestContainersWithSubscriptUsingSizeType()
{
    std::vector<int> c;
    c.push_back('f');
    c.push_back('o');
    c.push_back('o');

    int sum = 0;
    // #TEST#: RIRF56 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0; i < c.size(); ++i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF57 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size(); i < size; ++i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF58 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size()-1; i <= size; ++i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);
}

static void TestContainersWithSubscriptUsingInt()
{
    std::vector<int> c;
    c.push_back('f');
    c.push_back('o');
    c.push_back('o');

    int sum = 0;
    // #TEST#: RIRF59 Replace iterative for with range for
    for (int i = 0; i < int(c.size()); ++i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF60 Replace iterative for with range for
    for (int i = 0, size = int(c.size()); i < size; ++i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF61 Replace iterative for with range for
    for (int i = int(c.size())-1; i >= 0; --i)
    {
        sum += c[i];
    }
    assert(int('f') + int('o') + int('o') == sum);
}

static void TestContainersWithSubscript()
{
    TestContainersWithSubscriptUsingSizeType();
    TestContainersWithSubscriptUsingInt();
}

static void TestContainersWithAtUsingSizeType()
{
    std::vector<int> c;
    c.push_back('f');
    c.push_back('o');
    c.push_back('o');

    int sum = 0;
    // #TEST#: RIRF62 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0; i < c.size(); ++i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF63 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size(); i < size; ++i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF64 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size()-1; i <= size; ++i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);
}

static void TestContainersWithAtUsingInt()
{
    std::vector<int> c;
    c.push_back('f');
    c.push_back('o');
    c.push_back('o');

    int sum = 0;
    // #TEST#: RIRF65 Replace iterative for with range for
    for (int i = 0; i < int(c.size()); ++i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF66 Replace iterative for with range for
    for (int i = 0, size = int(c.size()); i < size; ++i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);

    sum = 0;
    // #TEST#: RIRF67 Replace iterative for with range for
    for (int i = int(c.size())-1; i >= 0; --i)
    {
        sum += c.at(i);
    }
    assert(int('f') + int('o') + int('o') == sum);
}

static void TestContainersWithAt()
{
    TestContainersWithAtUsingSizeType();
    TestContainersWithAtUsingInt();
}

void TestReplaceIterativeForWithRangeFor()
{
    TestArrays();
    TestContainersWithIterators();
    TestContainersWithSubscript();
    TestContainersWithAt();
}
