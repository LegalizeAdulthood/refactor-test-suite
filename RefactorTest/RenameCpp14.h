#pragma once

namespace RenameCpp14
{

// #TEST#: R606 Rename template parameter T
template <class T>
// #TEST#: R607 Rename template parameter T
// #TEST#: R608 Rename variable template pi2
// #TEST#: R609 Rename first use of T
// #TEST#: R610 Rename second use of T
constexpr T pi2 = T(2.0L) * T(3.1415926535897932385L);

// #TEST#: R611 Rename template parameter T
template <class T>
// #TEST#: R612 Rename first use of T
// #TEST#: R613 Rename second use of T
T circularArea2(T r)
{
    // #TEST#: R614 Rename use of pi2
    // #TEST#: R615 Rename use of T
    return pi2<T> * r * r;
}

}    // namespace RenameCpp14
