#include "stdafx.h"

// Collapses simple getter or setter code onto a single line.
// Collapses simple getter code onto a single line.
// Collapses simple setter code onto a single line.
// Expands single-line getter or setter code onto multiple lines.
// Expands single-line getter code onto multiple lines.
// Expands single-line setter code onto multiple lines.

class CollapseExpandAccessors
{
public:
    CollapseExpandAccessors()
        : _x(0),
        _y(0)
    {
    }

    // #TEST#: CEA1 Collapse this accessor
    int GetX() const
    {
        return _x;
    }
    // #TEST#: CEA2 Collapse this setter
    void SetX(int x)
    {
        _x = x;
    }
    // #TEST#: CEA3 Expand this accessor
    int GetY() const { return _y; }
    // #TEST#: CEA4 Expand this setter
    void SetY(int y) { _y = y; }

private:
    int _x;
    int _y;
};

void TestCollapseExpandAccessors()
{
    CollapseExpandAccessors test;
    test.SetX(10);
    int x = test.GetX();
    test.SetY(10);
    int y = test.GetY();
    test.SetX(x + y);
}
