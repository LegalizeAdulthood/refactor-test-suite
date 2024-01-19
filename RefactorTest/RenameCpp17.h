#pragma once

namespace RenameCpp17
{

// #TEST#: R648 Rename A
// #TEST#: R649 Rename B
// #TEST#: R650 Rename C
namespace A::B::C
{
// #TEST#: R651 Rename x
extern int x;

extern int y;
extern int z;
}    // namespace A::B::C

// #TEST#: R652 Rename variable g_counter
inline int g_counter{0};

}    // namespace RenameCpp17
