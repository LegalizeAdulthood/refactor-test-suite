#pragma once

namespace RenameCpp17
{

// #TEST#: R806 Rename A
// #TEST#: R807 Rename B
// #TEST#: R808 Rename C
namespace A::B::C
{
// #TEST#: R809 Rename x
extern int x;

extern int y;
extern int z;
}    // namespace A::B::C

// #TEST#: R664 Rename variable g_counter
inline int g_counter{0};

}    // namespace RenameCpp17
