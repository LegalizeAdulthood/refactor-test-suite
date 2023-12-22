#pragma once

namespace RenameCpp14
{

// #TEST#: R616 Rename template parameter T
template <class T>
// #TEST#: R617 Rename template parameter T
// #TEST#: R618 Rename template variable pi2
// #TEST#: R619 Rename template variable pi2
constexpr T pi2 = T(2.0L) * T(3.1415926535897932385L);

template <class T>
T circularArea2(T r)
{
    // #TEST#: R620 Rename template variable pi2
    return pi2<T> * r * r;
}

}
