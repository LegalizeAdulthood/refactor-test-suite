#pragma once

namespace RenameCpp17
{

// #TEST#: R645 Rename A
// #TEST#: R646 Rename B
// #TEST#: R647 Rename C
namespace A::B::C
{
// #TEST#: R648 Rename x
extern int x;

extern int y;
extern int z;
}    // namespace A::B::C

// #TEST#: R649 Rename variable g_counter
inline int g_counter{0};

}    // namespace RenameCpp17
