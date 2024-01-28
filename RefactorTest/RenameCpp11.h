#pragma once

#include <string>

namespace RenameCpp11
{
// #TEST#: R241 Rename T
template <typename T>
// #TEST#: R242 Rename Extern
struct Extern
{
    // #TEST#: R243 Rename Extern
    Extern()
    {
    }
    // #TEST#: R244 Rename Extern
    Extern(T t) : t(t)
    {
    }
    T t = T();
};

// #TEST#: R245 Rename Extern
extern template struct Extern<int>;
// #TEST#: R246 Rename Extern
extern template struct Extern<std::string>;

}    // namespace RenameCpp11

extern void TestRenameCpp11();
