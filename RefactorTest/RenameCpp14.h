#pragma once

namespace RenameCpp14
{

// #TEST#: R616 Rename template parameter T
template <class T>
// #TEST#: R617 Rename template parameter T
// #TEST#: R618 Rename variable template pi2
// #TEST#: R619 Rename first use of T
// #TEST#: R962 Rename second use of T
constexpr T pi2 = T(2.0L) * T(3.1415926535897932385L);

// #TEST#: R963 Rename template parameter T
template <class T>
// #TEST#: R964 Rename first use of T
// #TEST#: R965 Rename second use of T
T circularArea2(T r)
{
    // #TEST#: R620 Rename use of pi2
    // #TEST#: R966 Rename use of T
    return pi2<T> * r * r;
}

}    // namespace RenameCpp14
