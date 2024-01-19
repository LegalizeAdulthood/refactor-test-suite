#pragma once

#include <string>

namespace RenameCpp11
{
// #TEST#: R244 Rename T
template <typename T>
// #TEST#: R245 Rename Extern
struct Extern
{
    // #TEST#: R246 Rename Extern
    Extern()
    {
    }
    // #TEST#: R247 Rename Extern
    Extern(T t) : t(t)
    {
    }
    T t = T();
};

// #TEST#: R248 Rename Extern
extern template struct Extern<int>;
// #TEST#: R249 Rename Extern
extern template struct Extern<std::string>;

}    // namespace RenameCpp11

extern void TestRenameCpp11();
