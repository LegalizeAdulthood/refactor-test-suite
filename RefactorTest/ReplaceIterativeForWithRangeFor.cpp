#include "Require.h"

#include <vector>

static int fileDataImplicitSize[] = {1, 0};

static void TestFileArrayImplicitSize()
{
    // #TEST#: RIRF1 Replace iterative for with range for
    for (int i = 0; i < 2; ++i)
    {
        ++fileDataImplicitSize[i];
    }
    require_equal(2, fileDataImplicitSize[0]);
    require_equal(1, fileDataImplicitSize[1]);

    // #TEST#: RIRF2 Replace iterative for with range for
    for (int i = 0; i <= 1; ++i)
    {
        --fileDataImplicitSize[i];
    }
    require_equal(1, fileDataImplicitSize[0]);
    require_equal(0, fileDataImplicitSize[1]);

    // #TEST#: RIRF3 Replace iterative for with range for
    for (int i = 1; i >= 0; --i)
    {
        ++fileDataImplicitSize[i];
    }
    require_equal(2, fileDataImplicitSize[0]);
    require_equal(1, fileDataImplicitSize[1]);

    int sum = 0;
    // #TEST#: RIRF68 Replace iterative for with range for
    for (int i = 1; i > -1; --i)
    {
        sum += fileDataImplicitSize[i];
    }
    require_equal(3, sum);

    // #TEST#: RIRF4 Replace iterative for with range for
    for (int i = 0; i < sizeof(fileDataImplicitSize) / sizeof(fileDataImplicitSize[0]); ++i)
    {
        --fileDataImplicitSize[i];
    }
    require_equal(1, fileDataImplicitSize[0]);
    require_equal(0, fileDataImplicitSize[1]);

    // #TEST#: RIRF5 Replace iterative for with range for
    for (int i = 0; i <= sizeof(fileDataImplicitSize) / sizeof(fileDataImplicitSize[0]) - 1; ++i)
    {
        ++fileDataImplicitSize[i];
    }
    require_equal(2, fileDataImplicitSize[0]);
    require_equal(1, fileDataImplicitSize[1]);

    // #TEST#: RIRF6 Replace iterative for with range for
    for (int i = sizeof(fileDataImplicitSize) / sizeof(fileDataImplicitSize[0]) - 1; i >= 0; --i)
    {
        --fileDataImplicitSize[i];
    }
    require_equal(1, fileDataImplicitSize[0]);
    require_equal(0, fileDataImplicitSize[1]);
}

static int const constantFileDataImplicitSize[] = {'f', 'o', 'o'};

void TestConstantFileArrayImplicitSize()
{
    int sum = 0;
    // #TEST#: RIRF7 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF8 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF9 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF10 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantFileDataImplicitSize) / sizeof(constantFileDataImplicitSize[0]); ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF11 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantFileDataImplicitSize) / sizeof(constantFileDataImplicitSize[0]) - 1; ++i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF12 Replace iterative for with range for
    for (int i = sizeof(constantFileDataImplicitSize) / sizeof(constantFileDataImplicitSize[0]) - 1; i >= 0; --i)
    {
        sum += constantFileDataImplicitSize[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);
}

static int fileDataExplicitSize[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

static void TestFileArrayExplicitSize()
{
    // #TEST#: RIRF13 Replace iterative for with range for
    for (int i = 0; i < 10; ++i)
    {
        ++fileDataExplicitSize[i];
    }
    require_equal(10, fileDataExplicitSize[0]);
    require_equal(9, fileDataExplicitSize[1]);
    require_equal(8, fileDataExplicitSize[2]);
    require_equal(7, fileDataExplicitSize[3]);
    require_equal(6, fileDataExplicitSize[4]);
    require_equal(5, fileDataExplicitSize[5]);
    require_equal(4, fileDataExplicitSize[6]);
    require_equal(3, fileDataExplicitSize[7]);
    require_equal(2, fileDataExplicitSize[8]);
    require_equal(1, fileDataExplicitSize[9]);

    // #TEST#: RIRF14 Replace iterative for with range for
    for (int i = 0; i <= 9; ++i)
    {
        --fileDataExplicitSize[i];
    }
    require_equal(9, fileDataExplicitSize[0]);
    require_equal(8, fileDataExplicitSize[1]);
    require_equal(7, fileDataExplicitSize[2]);
    require_equal(6, fileDataExplicitSize[3]);
    require_equal(5, fileDataExplicitSize[4]);
    require_equal(4, fileDataExplicitSize[5]);
    require_equal(3, fileDataExplicitSize[6]);
    require_equal(2, fileDataExplicitSize[7]);
    require_equal(1, fileDataExplicitSize[8]);
    require_equal(0, fileDataExplicitSize[9]);

    // #TEST#: RIRF15 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        ++fileDataExplicitSize[i];
    }
    require_equal(10, fileDataExplicitSize[0]);
    require_equal(9, fileDataExplicitSize[1]);
    require_equal(8, fileDataExplicitSize[2]);
    require_equal(7, fileDataExplicitSize[3]);
    require_equal(6, fileDataExplicitSize[4]);
    require_equal(5, fileDataExplicitSize[5]);
    require_equal(4, fileDataExplicitSize[6]);
    require_equal(3, fileDataExplicitSize[7]);
    require_equal(2, fileDataExplicitSize[8]);
    require_equal(1, fileDataExplicitSize[9]);

    // #TEST#: RIRF16 Replace iterative for with range for
    for (int i = 0; i < sizeof(fileDataExplicitSize) / sizeof(fileDataExplicitSize[0]); ++i)
    {
        --fileDataExplicitSize[i];
    }
    require_equal(9, fileDataExplicitSize[0]);
    require_equal(8, fileDataExplicitSize[1]);
    require_equal(7, fileDataExplicitSize[2]);
    require_equal(6, fileDataExplicitSize[3]);
    require_equal(5, fileDataExplicitSize[4]);
    require_equal(4, fileDataExplicitSize[5]);
    require_equal(3, fileDataExplicitSize[6]);
    require_equal(2, fileDataExplicitSize[7]);
    require_equal(1, fileDataExplicitSize[8]);
    require_equal(0, fileDataExplicitSize[9]);

    // #TEST#: RIRF17 Replace iterative for with range for
    for (int i = 0; i <= sizeof(fileDataExplicitSize) / sizeof(fileDataExplicitSize[0]) - 1; ++i)
    {
        ++fileDataExplicitSize[i];
    }
    require_equal(10, fileDataExplicitSize[0]);
    require_equal(9, fileDataExplicitSize[1]);
    require_equal(8, fileDataExplicitSize[2]);
    require_equal(7, fileDataExplicitSize[3]);
    require_equal(6, fileDataExplicitSize[4]);
    require_equal(5, fileDataExplicitSize[5]);
    require_equal(4, fileDataExplicitSize[6]);
    require_equal(3, fileDataExplicitSize[7]);
    require_equal(2, fileDataExplicitSize[8]);
    require_equal(1, fileDataExplicitSize[9]);

    // #TEST#: RIRF18 Replace iterative for with range for
    for (int i = sizeof(fileDataExplicitSize) / sizeof(fileDataExplicitSize[0]) - 1; i >= 0; --i)
    {
        --fileDataExplicitSize[i];
    }
    require_equal(9, fileDataExplicitSize[0]);
    require_equal(8, fileDataExplicitSize[1]);
    require_equal(7, fileDataExplicitSize[2]);
    require_equal(6, fileDataExplicitSize[3]);
    require_equal(5, fileDataExplicitSize[4]);
    require_equal(4, fileDataExplicitSize[5]);
    require_equal(3, fileDataExplicitSize[6]);
    require_equal(2, fileDataExplicitSize[7]);
    require_equal(1, fileDataExplicitSize[8]);
    require_equal(0, fileDataExplicitSize[9]);
}

static int const constantFileDataExplicitSize[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

static void TestConstantFileArrayExplicitSize()
{
    int sum = 0;
    // #TEST#: RIRF19 Replace iterative for with range for
    for (int i = 0; i < 10; ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);

    sum = 0;
    // #TEST#: RIRF20 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);

    sum = 0;
    // #TEST#: RIRF21 Replace iterative for with range for
    for (int i = 9; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);

    sum = 0;
    // #TEST#: RIRF22 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantFileDataExplicitSize) / sizeof(constantFileDataExplicitSize[0]); ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);

    sum = 0;
    // #TEST#: RIRF23 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantFileDataExplicitSize) / sizeof(constantFileDataExplicitSize[0]) - 1; ++i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);

    sum = 0;
    // #TEST#: RIRF24 Replace iterative for with range for
    for (int i = sizeof(constantFileDataExplicitSize) / sizeof(constantFileDataExplicitSize[0]) - 1; i >= 0; --i)
    {
        sum += constantFileDataExplicitSize[i];
    }
    require_equal(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, sum);
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
    int stackDataImplicitSize[] = {'f', 'o', 'o'};
    // #TEST#: RIRF25 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        ++stackDataImplicitSize[i];
    }
    require_equal(int('g'), stackDataImplicitSize[0]);
    require_equal(int('p'), stackDataImplicitSize[1]);
    require_equal(int('p'), stackDataImplicitSize[2]);

    // #TEST#: RIRF26 Replace iterative for with range for
    for (int i = 0; i <= 2; ++i)
    {
        --stackDataImplicitSize[i];
    }
    require_equal(int('f'), stackDataImplicitSize[0]);
    require_equal(int('o'), stackDataImplicitSize[1]);
    require_equal(int('o'), stackDataImplicitSize[2]);

    // #TEST#: RIRF27 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        ++stackDataImplicitSize[i];
    }
    require_equal(int('g'), stackDataImplicitSize[0]);
    require_equal(int('p'), stackDataImplicitSize[1]);
    require_equal(int('p'), stackDataImplicitSize[2]);

    // #TEST#: RIRF28 Replace iterative for with range for
    for (int i = 0; i < sizeof(stackDataImplicitSize) / sizeof(stackDataImplicitSize[0]); ++i)
    {
        --stackDataImplicitSize[i];
    }
    require_equal(int('f'), stackDataImplicitSize[0]);
    require_equal(int('o'), stackDataImplicitSize[1]);
    require_equal(int('o'), stackDataImplicitSize[2]);

    // #TEST#: RIRF29 Replace iterative for with range for
    for (int i = 0; i <= sizeof(stackDataImplicitSize) / sizeof(stackDataImplicitSize[0]) - 1; ++i)
    {
        ++stackDataImplicitSize[i];
    }
    require_equal(int('g'), stackDataImplicitSize[0]);
    require_equal(int('p'), stackDataImplicitSize[1]);
    require_equal(int('p'), stackDataImplicitSize[2]);

    // #TEST#: RIRF30 Replace iterative for with range for
    for (int i = sizeof(stackDataImplicitSize) / sizeof(stackDataImplicitSize[0]) - 1; i >= 0; --i)
    {
        --stackDataImplicitSize[i];
    }
    require_equal(int('f'), stackDataImplicitSize[0]);
    require_equal(int('o'), stackDataImplicitSize[1]);
    require_equal(int('o'), stackDataImplicitSize[2]);
}

static void TestConstantStackArrayImplicitSize()
{
    int const constantStackDataImplicitSize[] = {'b', 'a', 'r'};
    int sum = 0;
    // #TEST#: RIRF31 Replace iterative for with range for
    for (int i = 0; i < 3; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);

    sum = 0;
    // #TEST#: RIRF32 Replace iterative for with range for
    for (int i = 0; i <= 2; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);

    sum = 0;
    // #TEST#: RIRF33 Replace iterative for with range for
    for (int i = 2; i >= 0; --i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);

    sum = 0;
    // #TEST#: RIRF34 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantStackDataImplicitSize) / sizeof(constantStackDataImplicitSize[0]); ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);

    sum = 0;
    // #TEST#: RIRF35 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantStackDataImplicitSize) / sizeof(constantStackDataImplicitSize[0]) - 1; ++i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);

    sum = 0;
    // #TEST#: RIRF36 Replace iterative for with range for
    for (int i = sizeof(constantStackDataImplicitSize) / sizeof(constantStackDataImplicitSize[0]) - 1; i >= 0; --i)
    {
        sum += constantStackDataImplicitSize[i];
    }
    require_equal(int('b') + int('a') + int('r'), sum);
}

static void TestStackArrayExplicitSize()
{
    int stackDataExplicitSize[4] = {'q', 'u', 'x'};
    // #TEST#: RIRF37 Replace iterative for with range for
    for (int i = 0; i < 4; ++i)
    {
        ++stackDataExplicitSize[i];
    }
    require_equal(int('r'), stackDataExplicitSize[0]);
    require_equal(int('v'), stackDataExplicitSize[1]);
    require_equal(int('y'), stackDataExplicitSize[2]);
    require_equal(1, stackDataExplicitSize[3]);

    // #TEST#: RIRF38 Replace iterative for with range for
    for (int i = 0; i <= 3; ++i)
    {
        --stackDataExplicitSize[i];
    }
    require_equal(int('q'), stackDataExplicitSize[0]);
    require_equal(int('u'), stackDataExplicitSize[1]);
    require_equal(int('x'), stackDataExplicitSize[2]);
    require_equal(0, stackDataExplicitSize[3]);

    // #TEST#: RIRF39 Replace iterative for with range for
    for (int i = 3; i >= 0; --i)
    {
        ++stackDataExplicitSize[i];
    }
    require_equal(int('r'), stackDataExplicitSize[0]);
    require_equal(int('v'), stackDataExplicitSize[1]);
    require_equal(int('y'), stackDataExplicitSize[2]);
    require_equal(1, stackDataExplicitSize[3]);

    // #TEST#: RIRF40 Replace iterative for with range for
    for (int i = 0; i < sizeof(stackDataExplicitSize) / sizeof(stackDataExplicitSize[0]); ++i)
    {
        --stackDataExplicitSize[i];
    }
    require_equal(int('q'), stackDataExplicitSize[0]);
    require_equal(int('u'), stackDataExplicitSize[1]);
    require_equal(int('x'), stackDataExplicitSize[2]);
    require_equal(0, stackDataExplicitSize[3]);

    // #TEST#: RIRF41 Replace iterative for with range for
    for (int i = sizeof(stackDataExplicitSize) / sizeof(stackDataExplicitSize[0]) - 1; i >= 0; --i)
    {
        ++stackDataExplicitSize[i];
    }
    require_equal(int('r'), stackDataExplicitSize[0]);
    require_equal(int('v'), stackDataExplicitSize[1]);
    require_equal(int('y'), stackDataExplicitSize[2]);
    require_equal(1, stackDataExplicitSize[3]);

    // #TEST#: RIRF42 Replace iterative for with range for
    for (int i = sizeof(stackDataExplicitSize) / sizeof(stackDataExplicitSize[0]) - 1; i >= 0; --i)
    {
        --stackDataExplicitSize[i];
    }
    require_equal(int('q'), stackDataExplicitSize[0]);
    require_equal(int('u'), stackDataExplicitSize[1]);
    require_equal(int('x'), stackDataExplicitSize[2]);
    require_equal(0, stackDataExplicitSize[3]);
}

static void TestConstantStackArrayExplicitSize()
{
    int const constantStackdataExlicitSize[4] = {'s', 'o', 'x'};
    int sum = 0;
    // #TEST#: RIRF43 Replace iterative for with range for
    for (int i = 0; i < 4; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);

    sum = 0;
    // #TEST#: RIRF44 Replace iterative for with range for
    for (int i = 0; i <= 3; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);

    sum = 0;
    // #TEST#: RIRF45 Replace iterative for with range for
    for (int i = 3; i >= 0; --i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);

    sum = 0;
    // #TEST#: RIRF46 Replace iterative for with range for
    for (int i = 0; i < sizeof(constantStackdataExlicitSize) / sizeof(constantStackdataExlicitSize[0]); ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);

    sum = 0;
    // #TEST#: RIRF47 Replace iterative for with range for
    for (int i = 0; i <= sizeof(constantStackdataExlicitSize) / sizeof(constantStackdataExlicitSize[0]) - 1; ++i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);

    sum = 0;
    // #TEST#: RIRF48 Replace iterative for with range for
    for (int i = sizeof(constantStackdataExlicitSize) / sizeof(constantStackdataExlicitSize[0]) - 1; i >= 0; --i)
    {
        sum += constantStackdataExlicitSize[i];
    }
    require_equal(int('s') + int('o') + int('x'), sum);
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
    for (std::vector<int>::const_iterator it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += *it;
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF50 Replace iterative for with range for
    for (std::vector<int>::const_iterator it = c.cbegin(), end = c.cend(); end != it; ++it)
    {
        sum += *it;
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF51 Replace iterative for with range for
    for (std::vector<int>::const_reverse_iterator it = c.crbegin(), end = c.crend(); end != it; ++it)
    {
        sum += *it;
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF52 Replace iterative for with range for
    for (std::vector<int>::const_iterator it = c.cbegin(), end = c.cend(); end != it; ++it)
    {
        sum += *it;
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF53 Replace iterative for with range for
    for (std::vector<int>::reverse_iterator it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        sum += *it;
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    // #TEST#: RIRF54 Replace iterative for with range for
    for (std::vector<int>::iterator it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++*it;
    }
    require_equal(int('g'), c[0]);
    require_equal(int('p'), c[1]);
    require_equal(int('p'), c[2]);

    // #TEST#: RIRF55 Replace iterative for with range for
    for (std::vector<int>::reverse_iterator it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --*it;
    }
    require_equal(int('f'), c[0]);
    require_equal(int('o'), c[1]);
    require_equal(int('o'), c[2]);
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
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF57 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size(); i < size; ++i)
    {
        sum += c[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF58 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size() - 1; i <= size; ++i)
    {
        sum += c[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);
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
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF60 Replace iterative for with range for
    for (int i = 0, size = int(c.size()); i < size; ++i)
    {
        sum += c[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF61 Replace iterative for with range for
    for (int i = int(c.size()) - 1; i >= 0; --i)
    {
        sum += c[i];
    }
    require_equal(int('f') + int('o') + int('o'), sum);
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
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF63 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size(); i < size; ++i)
    {
        sum += c.at(i);
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF64 Replace iterative for with range for
    for (std::vector<int>::size_type i = 0, size = c.size() - 1; i <= size; ++i)
    {
        sum += c.at(i);
    }
    require_equal(int('f') + int('o') + int('o'), sum);
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
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF66 Replace iterative for with range for
    for (int i = 0, size = int(c.size()); i < size; ++i)
    {
        sum += c.at(i);
    }
    require_equal(int('f') + int('o') + int('o'), sum);

    sum = 0;
    // #TEST#: RIRF67 Replace iterative for with range for
    for (int i = int(c.size()) - 1; i >= 0; --i)
    {
        sum += c.at(i);
    }
    require_equal(int('f') + int('o') + int('o'), sum);
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
