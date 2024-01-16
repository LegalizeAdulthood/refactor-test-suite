#include "Require.h"

#include <concepts>
#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>

namespace
{

struct Rope
{
    explicit Rope(std::string text) : m_text(std::move(text))
    {
    }
    explicit Rope(const char *text) : m_text(text)
    {
    }

    Rope operator*(const Rope &rhs) const
    {
        return Rope{m_text + ' ' + rhs.m_text};
    }

    std::string m_text;
};

inline bool operator==(const Rope &lhs, const Rope &rhs)
{
    return lhs.m_text == rhs.m_text;
}

inline bool operator!=(const Rope &lhs, const Rope &rhs)
{
    return !(lhs == rhs);
}

inline std::ostream &operator<<(std::ostream &str, const Rope &value)
{
    return str << "Rope{" << value.m_text << '}';
}

// clang-format off
// Simple concept with single template parameter
// #GOINK#: R987 Rename template parameter T
template <typename T>
// #GOINK#: R988 Rename concept Squareable
// #GOINK#: R989 Rename use of T
// #GOINK#: R990 Rename parameter lhs
concept Squareable = requires(T lhs)
{
    // #GOINK#: R991 Rename first use of lhs
    // #GOINK#: R992 Rename second use of lhs
    lhs * lhs;
};

// Simple concept with multiple template parameters
// #GOINK#: R993 Rename template parameter T
// #GOINK#: R994 Rename template parameter U
template <typename T, typename U>
// #GOINK#: R995 Rename concept Multiplicable
// #GOINK#: R996 Rename use of T
// #GOINK#: R997 Rename parameter lhs
// #GOINK#: R998 Rename use of U
// #GOINK#: R999 Rename parameter rhs
concept Multiplicable = requires(T lhs, U rhs)
{
    // #GOINK#: R1000 Rename use of lhs
    // #GOINK#: R1001 Rename use of rhs
    lhs * rhs;
};
// clang-format on

// single template parameter function with simple constraint on template parameter
// #GOINK#: R1002 Rename template parameter T
template <typename T>
    // #GOINK#: R1003 Rename concept Squareable
    // #GOINK#: R1004 Rename use of T
    requires Squareable<T>
// #GOINK#: R1005 Rename first use of T
// #GOINK#: R1006 Rename function square1
// #GOINK#: R1007 Rename second use of T
// #GOINK#: R1008 Rename parameter value
T square1(T value)
{
    // #GOINK#: R1009 Rename first use of value
    // #GOINK#: R1010 Rename second use of value
    return value * value;
}

// single template parameter function with simple constraint on function
// #GOINK#: R1011 Rename template parameter T
template <typename T>
// #GOINK#: R1012 Rename first use of T
// #GOINK#: R1013 Rename function square2
// #GOINK#: R1014 Rename second use of T
// #GOINK#: R1015 Rename parameter value
T square2(T value)
    // #GOINK#: R1016 Rename concept Squareable
    // #GOINK#: R1017 Rename use of T
    requires Squareable<T>
{
    // #GOINK#: R1018 Rename first use of value
    // #GOINK#: R1019 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on template parameter
// #GOINK#: R1020 Rename template parameter T
template <typename T>
    // #GOINK#: R1021 Rename first use of T
    // #GOINK#: R1022 Rename concept Squareable
    // #GOINK#: R1023 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #GOINK#: R1024 Rename first use of T
// #GOINK#: R1025 Rename function square3
// #GOINK#: R1026 Rename second use of T
// #GOINK#: R1027 Rename parameter value
T square3(T value)
{
    // #GOINK#: R1028 Rename first use of value
    // #GOINK#: R1029 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on template parameter
// #GOINK#: R1030 Rename template parameter T
template <typename T>
    // #GOINK#: R1031 Rename first use of T
    // #GOINK#: R1032 Rename concept Squareable
    // #GOINK#: R1033 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #GOINK#: R1034 Rename first use of T
// #GOINK#: R1035 Rename function square4
// #GOINK#: R1036 Rename second use of T
// #GOINK#: R1037 Rename parameter value
T square4(T value)
{
    // #GOINK#: R1038 Rename first use of value
    // #GOINK#: R1039 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on function
// #GOINK#: R1040 Rename template parameter T
template <typename T>
// #GOINK#: R1041 Rename first use of T
// #GOINK#: R1042 Rename function square5
// #GOINK#: R1043 Rename second use of T
// #GOINK#: R1044 Rename parameter value
T square5(T value)
    // #GOINK#: R1045 Rename first use of T
    // #GOINK#: R1046 Rename concept Squareable
    // #GOINK#: R1047 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
{
    // #GOINK#: R1048 Rename first use of value
    // #GOINK#: R1049 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on function
// #GOINK#: R1050 Rename template parameter T
template <typename T>
// #GOINK#: R1051 Rename first use of T
// #GOINK#: R1052 Rename function square6
// #GOINK#: R1053 Rename second use of T
// #GOINK#: R1054 Rename parameter value
T square6(T value)
    // #GOINK#: R1055 Rename first use of T
    // #GOINK#: R1056 Rename concept Squareable
    // #GOINK#: R1057 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
{
    // #GOINK#: R1058 Rename first use of value
    // #GOINK#: R1059 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on function
// #GOINK#: R1060 Rename template parameter T
template <typename T>
// #GOINK#: R1061 Rename first use of T
// #GOINK#: R1062 Rename function square7
// #GOINK#: R1063 Rename second use of T
// #GOINK#: R1064 Rename parameter value
T square7(T value)
    // #GOINK#: R1065 Rename first use of T
    // #GOINK#: R1066 Rename second use of T
    // #GOINK#: R1067 Rename concept Squareable
    // #GOINK#: R1068 Rename third use of T
    requires (std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
{
    // #GOINK#: R1069 Rename first use of value
    // #GOINK#: R1070 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on function
// #GOINK#: R1071 Rename template parameter T
template <typename T>
// #GOINK#: R1072 Rename first use of T
// #GOINK#: R1073 Rename function square8
// #GOINK#: R1074 Rename second use of T
// #GOINK#: R1075 Rename parameter value
T square8(T value)
    // #GOINK#: R1076 Rename first use of T
    // #GOINK#: R1077 Rename second use of T
    // #GOINK#: R1078 Rename concept Squareable
    // #GOINK#: R1079 Rename third use of T
    requires (std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
{
    // #GOINK#: R1080 Rename first use of value
    // #GOINK#: R1081 Rename second use of value
    return value * value;
}

// multiple template parameter function with simple constraint on template parameters
// #GOINK#: R1082 Rename template parameter T
// #GOINK#: R1083 Rename template parameter U
// #GOINK#: R1084 Rename use of T
template <typename T, typename U = T>
    // #GOINK#: R1085 Rename concept Multiplicable
    // #GOINK#: R1086 Rename use of T
    // #GOINK#: R1087 Rename use of U
    requires Multiplicable<T, U>
// #GOINK#: R1088 Rename function product1
// #GOINK#: R1089 Rename use of T
// #GOINK#: R1090 Rename parameter lhs
// #GOINK#: R1091 Rename use of U
// #GOINK#: R1092 Rename parameter rhs
// #GOINK#: R1093 Rename use of lhs
// #GOINK#: R1094 Rename use of rhs
auto product1(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #GOINK#: R1095 Rename use of lhs
    // #GOINK#: R1096 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with simple constraint on function
// #GOINK#: R1097 Rename template parameter T
// #GOINK#: R1098 Rename template parameter U
// #GOINK#: R1099 Rename use of T
template <typename T, typename U = T>
// #GOINK#: R1100 Rename function product2
// #GOINK#: R1101 Rename use of T
// #GOINK#: R1102 Rename parameter lhs
// #GOINK#: R1103 Rename use of U
// #GOINK#: R1104 Rename parameter rhs
// #GOINK#: R1105 Rename use of lhs
// #GOINK#: R1106 Rename use of rhs
auto product2(T lhs, U rhs) -> decltype(lhs * rhs)
    // #GOINK#: R1107 Rename concept Multiplicable
    // #GOINK#: R1108 Rename use of T
    // #GOINK#: R1109 Rename use of U
    requires Multiplicable<T, U>
{
    // #GOINK#: R1110 Rename use of lhs
    // #GOINK#: R1111 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on template parameters
// #GOINK#: R1112 Rename template parameter T
// #GOINK#: R1113 Rename template parameter U
// #GOINK#: R1114 Rename use of T
template <typename T, typename U = T>
    // #GOINK#: R1115 Rename first use of T
    // #GOINK#: R1116 Rename concept Multiplicable
    // #GOINK#: R1117 Rename second use of T
    // #GOINK#: R1118 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
// #GOINK#: R1119 Rename function product3
// #GOINK#: R1120 Rename use of T
// #GOINK#: R1121 Rename parameter lhs
// #GOINK#: R1122 Rename use of U
// #GOINK#: R1123 Rename parameter rhs
// #GOINK#: R1124 Rename use of lhs
// #GOINK#: R1125 Rename use of rhs
auto product3(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #GOINK#: R1126 Rename use of lhs
    // #GOINK#: R1127 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on template parameters
// #GOINK#: R1128 Rename template parameter T
// #GOINK#: R1129 Rename template parameter U
// #GOINK#: R1130 Rename use of T
template <typename T, typename U = T>
// #GOINK#: R1131 Rename function product4
// #GOINK#: R1132 Rename use of T
// #GOINK#: R1133 Rename parameter lhs
// #GOINK#: R1134 Rename use of U
// #GOINK#: R1135 Rename parameter rhs
// #GOINK#: R1136 Rename use of lhs
// #GOINK#: R1137 Rename use of rhs
auto product4(T lhs, U rhs) -> decltype(lhs * rhs)
    // #GOINK#: R1138 Rename first use of T
    // #GOINK#: R1139 Rename concept Multiplicable
    // #GOINK#: R1140 Rename second use of T
    // #GOINK#: R1141 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
{
    // #GOINK#: R1142 Rename use of lhs
    // #GOINK#: R1143 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on function
// #GOINK#: R1144 Rename template parameter T
// #GOINK#: R1145 Rename template parameter U
// #GOINK#: R1146 Rename use of T
template <typename T, typename U = T>
    // #GOINK#: R1147 Rename first use of T
    // #GOINK#: R1148 Rename concept Multiplicable
    // #GOINK#: R1149 Rename second use of T
    // #GOINK#: R1150 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
// #GOINK#: R1151 Rename function product5
// #GOINK#: R1152 Rename use of T
// #GOINK#: R1153 Rename parameter lhs
// #GOINK#: R1154 Rename use of U
// #GOINK#: R1155 Rename parameter rhs
// #GOINK#: R1156 Rename use of lhs
// #GOINK#: R1157 Rename use of rhs
auto product5(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #GOINK#: R1158 Rename use of lhs
    // #GOINK#: R1159 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on function
// #GOINK#: R1160 Rename template parameter T
// #GOINK#: R1161 Rename template parameter U
// #GOINK#: R1162 Rename use of T
template <typename T, typename U = T>
// #GOINK#: R1163 Rename function product6
// #GOINK#: R1164 Rename use of T
// #GOINK#: R1165 Rename parameter lhs
// #GOINK#: R1166 Rename use of U
// #GOINK#: R1167 Rename parameter rhs
// #GOINK#: R1168 Rename use of lhs
// #GOINK#: R1169 Rename use of rhs
auto product6(T lhs, U rhs) -> decltype(lhs * rhs)
    // #GOINK#: R1170 Rename first use of T
    // #GOINK#: R1171 Rename concept Multiplicable
    // #GOINK#: R1172 Rename second use of T
    // #GOINK#: R1173 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
{
    // #GOINK#: R1174 Rename use of lhs
    // #GOINK#: R1175 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on function
// #GOINK#: R1176 Rename template parameter T
// #GOINK#: R1177 Rename template parameter U
// #GOINK#: R1178 Rename use of T
template <typename T, typename U = T>
    // #GOINK#: R1179 Rename first use of T
    // #GOINK#: R1180 Rename first use of U
    // #GOINK#: R1181 Rename concept Multiplicable
    // #GOINK#: R1182 Rename second use of T
    // #GOINK#: R1183 Rename second use of U
    requires (std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
// #GOINK#: R1184 Rename function product7
// #GOINK#: R1185 Rename use of T
// #GOINK#: R1186 Rename parameter lhs
// #GOINK#: R1187 Rename use of U
// #GOINK#: R1188 Rename parameter rhs
// #GOINK#: R1189 Rename use of lhs
// #GOINK#: R1190 Rename use of rhs
auto product7(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #GOINK#: R1191 Rename use of lhs
    // #GOINK#: R1192 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on function
// #GOINK#: R1193 Rename template parameter T
// #GOINK#: R1194 Rename template parameter U
// #GOINK#: R1195 Rename use of T
template <typename T, typename U = T>
// #GOINK#: R1196 Rename function product8
// #GOINK#: R1197 Rename use of T
// #GOINK#: R1198 Rename parameter lhs
// #GOINK#: R1199 Rename use of U
// #GOINK#: R1200 Rename parameter rhs
// #GOINK#: R1201 Rename use of lhs
// #GOINK#: R1202 Rename use of rhs
auto product8(T lhs, U rhs) -> decltype(lhs * rhs)
    // #GOINK#: R1203 Rename first use of T
    // #GOINK#: R1204 Rename first use of U
    // #GOINK#: R1205 Rename concept Multiplicable
    // #GOINK#: R1206 Rename second use of T
    // #GOINK#: R1207 Rename second use of U
    requires (std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
{
    // #GOINK#: R1208 Rename use of lhs
    // #GOINK#: R1209 Rename use of rhs
    return lhs * rhs;
}

// Simple constraint expressions via require clauses
// [X] function templates
//     [X] single template parameter
//         [X] single constraint on template parameters
//         [X] single constraint on function
//         [X] compound constraint on template parameters
//             [X] conjunction
//             [X] disjunction
//             [X] combination
//         [X] compound constraint on function
//             [X] conjunction
//             [X] disjunction
//             [X] combination
//     [X] multiple template parameters
//         [X] single constraint on template parameters
//         [X] single constraint on function
//         [X] compound constraint on template parameters
//             [X] conjunction
//             [X] disjunction
//             [X] combination
//         [X] compound constraint on function
//             [X] conjunction
//             [X] disjunction
//             [X] combination
void f1()
{
    {
        // #GOINK#: R1210 Rename function square1
        REQUIRE_EQUAL(4, square1(2));
        // #GOINK#: R1211 Rename function square1
        const double d = square1(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #GOINK#: R1212 Rename function square1
        const Rope r = square1(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #GOINK#: R1213 Rename function square2
        REQUIRE_EQUAL(4, square2(2));
        // #GOINK#: R1214 Rename function square2
        const double d = square2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #GOINK#: R1215 Rename function square2
        const Rope r = square2(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #GOINK#: R1216 Rename function square3
        REQUIRE_EQUAL(4, square3(2));
        // #GOINK#: R1217 Rename function square3
        const double d = square3(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #GOINK#: R1218 Rename function square3
        const Rope r = square3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #GOINK#: R1219 Rename function square4
        REQUIRE_EQUAL(4, square4(2));
        // #GOINK#: R1220 Rename function square4
        const double d = square4(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1221 Rename function square5
        REQUIRE_EQUAL(4, square5(2));
        // #GOINK#: R1222 Rename function square5
        const double d = square5(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #GOINK#: R1223 Rename function square5
        const Rope r = square5(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #GOINK#: R1224 Rename function square6
        REQUIRE_EQUAL(4, square6(2));
        // #GOINK#: R1225 Rename function square6
        const double d = square6(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1226 Rename function square7
        REQUIRE_EQUAL(4, square7(2));
        // #GOINK#: R1227 Rename function square7
        const double d = square7(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1228 Rename function square8
        REQUIRE_EQUAL(4, square8(2));
        // #GOINK#: R1229 Rename function square8
        const double d = square8(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1230 Rename function product1
        REQUIRE_EQUAL(6, product1(2, 3));
        // #GOINK#: R1231 Rename function product1
        const double d = product1(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1232 Rename function product1
        const Rope r = product1(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #GOINK#: R1233 Rename function product2
        REQUIRE_EQUAL(6, product2(2, 3));
        // #GOINK#: R1234 Rename function product2
        const double d = product2(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1235 Rename function product2
        const Rope r = product2(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #GOINK#: R1236 Rename function product3
        REQUIRE_EQUAL(6, product3(2, 3));
        // #GOINK#: R1237 Rename function product3
        const double d = product3(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1238 Rename function product3
        const Rope r = product3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #GOINK#: R1239 Rename function product4
        REQUIRE_EQUAL(6, product4(2, 3));
        // #GOINK#: R1240 Rename function product4
        const double d = product4(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1241 Rename function product5
        REQUIRE_EQUAL(6, product5(2, 3));
        // #GOINK#: R1242 Rename function product5
        const double d = product5(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1243 Rename function product5
        const Rope r = product5(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #GOINK#: R1244 Rename function product6
        REQUIRE_EQUAL(6, product6(2, 3));
        // #GOINK#: R1245 Rename function product6
        const double d = product6(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic_v
    }
    {
        // #GOINK#: R1246 Rename function product7
        REQUIRE_EQUAL(6, product7(2, 3));
        // #GOINK#: R1247 Rename function product7
        const double d = product7(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1248 Rename function product7
        const Rope r = product7(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #GOINK#: R1249 Rename function product8
        REQUIRE_EQUAL(6, product8(2, 3));
        // #GOINK#: R1250 Rename function product8
        const double d = product8(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #GOINK#: R1251 Rename function product8
        const Rope r = product8(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
}

// constraints
// [ ] class templates
//     [ ] single template parameter
//         [ ] single constraint
//         [ ] compound constraint
//             [ ] conjunction
//             [ ] disjunction
//     [ ] multiple template parameters
//         [ ] single constraint
//         [ ] compound constraint
//             [ ] conjunction
//             [ ] disjunction
// [ ] class template member functions
//     [ ] single template parameter
//         [ ] single constraint
//         [ ] compound constraint
//             [ ] conjunction
//             [ ] disjunction
//     [ ] multiple template parameters
//         [ ] single constraint
//         [ ] compound constraint
//             [ ] conjunction
//             [ ] disjunction
//

}    // namespace

namespace RenameCpp20
{

void TestRenameConstraints()
{
    f1();
}

}

