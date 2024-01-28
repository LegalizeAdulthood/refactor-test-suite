#pragma once

namespace RenameCpp14
{

// #TEST#: R603 Rename template parameter T
template <class T>
// #TEST#: R604 Rename template parameter T
// #TEST#: R605 Rename variable template pi2
// #TEST#: R606 Rename first use of T
// #TEST#: R607 Rename second use of T
constexpr T pi2 = T(2.0L) * T(3.1415926535897932385L);

// #TEST#: R608 Rename template parameter T
template <class T>
// #TEST#: R609 Rename first use of T
// #TEST#: R610 Rename second use of T
T circularArea2(T r)
{
    // #TEST#: R611 Rename use of pi2
    // #TEST#: R612 Rename use of T
    return pi2<T> * r * r;
}

}    // namespace RenameCpp14
