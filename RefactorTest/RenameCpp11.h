#pragma once

#include <string>

namespace RenameCpp11
{
// #TEST#: R376 Rename T
template <typename T>
// #TEST#: R377 Rename Extern
struct Extern
{
    // #TEST#: R378 Rename Extern
    Extern() {}
    // #TEST#: R379 Rename Extern
    Extern(T t) : t(t) {}
    T t = T();
};

// #TEST#: R380 Rename Extern
extern template struct Extern<int>;
// #TEST#: R381 Rename Extern
extern template struct Extern<std::string>;

}    // namespace RenameCpp11

extern void TestRenameCpp11();
