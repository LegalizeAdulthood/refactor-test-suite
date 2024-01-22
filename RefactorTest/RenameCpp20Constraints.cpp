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
    explicit Rope(std::string text) :
        m_text(std::move(text))
    {
    }
    explicit Rope(const char *text) :
        m_text(text)
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
// #TEST#: R987 Rename template parameter T
template <typename T>
// #TEST#: R988 Rename concept Squareable
// #TEST#: R989 Rename use of T
// #TEST#: R990 Rename parameter lhs
concept Squareable = requires(T lhs)
{
    // #TEST#: R991 Rename first use of lhs
    // #TEST#: R992 Rename second use of lhs
    lhs * lhs;
};

// Simple concept with multiple template parameters
// #TEST#: R993 Rename template parameter T
// #TEST#: R994 Rename template parameter U
template <typename T, typename U>
// #TEST#: R995 Rename concept Multiplicable
// #TEST#: R996 Rename use of T
// #TEST#: R997 Rename parameter lhs
// #TEST#: R998 Rename use of U
// #TEST#: R999 Rename parameter rhs
concept Multiplicable = requires(T lhs, U rhs)
{
    // #TEST#: R1000 Rename use of lhs
    // #TEST#: R1001 Rename use of rhs
    lhs * rhs;
};
// clang-format on

// single template parameter function with simple constraint on template parameter
// #TEST#: R1002 Rename template parameter T
template <typename T>
// #TEST#: R1003 Rename concept Squareable
// #TEST#: R1004 Rename use of T
    requires Squareable<T>
// #TEST#: R1005 Rename first use of T
// #TEST#: R1006 Rename function square1
// #TEST#: R1007 Rename second use of T
// #TEST#: R1008 Rename parameter value
T square1(T value)
{
    // #TEST#: R1009 Rename first use of value
    // #TEST#: R1010 Rename second use of value
    return value * value;
}

// single template parameter function with simple constraint on function
// #TEST#: R1011 Rename template parameter T
template <typename T>
// #TEST#: R1012 Rename first use of T
// #TEST#: R1013 Rename function square2
// #TEST#: R1014 Rename second use of T
// #TEST#: R1015 Rename parameter value
T square2(T value)
    // #TEST#: R1016 Rename concept Squareable
    // #TEST#: R1017 Rename use of T
    requires Squareable<T>
{
    // #TEST#: R1018 Rename first use of value
    // #TEST#: R1019 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on template parameter
// #TEST#: R1020 Rename template parameter T
template <typename T>
// #TEST#: R1021 Rename first use of T
// #TEST#: R1022 Rename concept Squareable
// #TEST#: R1023 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1024 Rename first use of T
// #TEST#: R1025 Rename function square3
// #TEST#: R1026 Rename second use of T
// #TEST#: R1027 Rename parameter value
T square3(T value)
{
    // #TEST#: R1028 Rename first use of value
    // #TEST#: R1029 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on template parameter
// #TEST#: R1030 Rename template parameter T
template <typename T>
// #TEST#: R1031 Rename first use of T
// #TEST#: R1032 Rename concept Squareable
// #TEST#: R1033 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1034 Rename first use of T
// #TEST#: R1035 Rename function square4
// #TEST#: R1036 Rename second use of T
// #TEST#: R1037 Rename parameter value
T square4(T value)
{
    // #TEST#: R1038 Rename first use of value
    // #TEST#: R1039 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on function
// #TEST#: R1040 Rename template parameter T
template <typename T>
// #TEST#: R1041 Rename first use of T
// #TEST#: R1042 Rename function square5
// #TEST#: R1043 Rename second use of T
// #TEST#: R1044 Rename parameter value
T square5(T value)
    // #TEST#: R1045 Rename first use of T
    // #TEST#: R1046 Rename concept Squareable
    // #TEST#: R1047 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
{
    // #TEST#: R1048 Rename first use of value
    // #TEST#: R1049 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on function
// #TEST#: R1050 Rename template parameter T
template <typename T>
// #TEST#: R1051 Rename first use of T
// #TEST#: R1052 Rename function square6
// #TEST#: R1053 Rename second use of T
// #TEST#: R1054 Rename parameter value
T square6(T value)
    // #TEST#: R1055 Rename first use of T
    // #TEST#: R1056 Rename concept Squareable
    // #TEST#: R1057 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
{
    // #TEST#: R1058 Rename first use of value
    // #TEST#: R1059 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on template parameter
// #TEST#: R1060 Rename template parameter T
template <typename T>
// #TEST#: R1061 Rename first use of T
// #TEST#: R1062 Rename second use of T
// #TEST#: R1063 Rename concept Squareable
// #TEST#: R1064 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1065 Rename first use of T
// #TEST#: R1066 Rename function square7
// #TEST#: R1067 Rename second use of T
// #TEST#: R1068 Rename parameter value
T square7(T value)
{
    // #TEST#: R1069 Rename first use of value
    // #TEST#: R1070 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on function
// #TEST#: R1071 Rename template parameter T
template <typename T>
// #TEST#: R1072 Rename first use of T
// #TEST#: R1073 Rename function square8
// #TEST#: R1074 Rename second use of T
// #TEST#: R1075 Rename parameter value
T square8(T value)
    // #TEST#: R1076 Rename first use of T
    // #TEST#: R1077 Rename second use of T
    // #TEST#: R1078 Rename concept Squareable
    // #TEST#: R1079 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
{
    // #TEST#: R1080 Rename first use of value
    // #TEST#: R1081 Rename second use of value
    return value * value;
}

// multiple template parameter function with simple constraint on template parameters
// #TEST#: R1082 Rename template parameter T
// #TEST#: R1083 Rename template parameter U
// #TEST#: R1084 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1085 Rename concept Multiplicable
// #TEST#: R1086 Rename use of T
// #TEST#: R1087 Rename use of U
    requires Multiplicable<T, U>
// #TEST#: R1088 Rename function product1
// #TEST#: R1089 Rename use of T
// #TEST#: R1090 Rename parameter lhs
// #TEST#: R1091 Rename use of U
// #TEST#: R1092 Rename parameter rhs
// #TEST#: R1093 Rename use of lhs
// #TEST#: R1094 Rename use of rhs
auto product1(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1095 Rename use of lhs
    // #TEST#: R1096 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with simple constraint on function
// #TEST#: R1097 Rename template parameter T
// #TEST#: R1098 Rename template parameter U
// #TEST#: R1099 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1100 Rename function product2
// #TEST#: R1101 Rename use of T
// #TEST#: R1102 Rename parameter lhs
// #TEST#: R1103 Rename use of U
// #TEST#: R1104 Rename parameter rhs
// #TEST#: R1105 Rename use of lhs
// #TEST#: R1106 Rename use of rhs
auto product2(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1107 Rename concept Multiplicable
    // #TEST#: R1108 Rename use of T
    // #TEST#: R1109 Rename use of U
    requires Multiplicable<T, U>
{
    // #TEST#: R1110 Rename use of lhs
    // #TEST#: R1111 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on template parameters
// #TEST#: R1112 Rename template parameter T
// #TEST#: R1113 Rename template parameter U
// #TEST#: R1114 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1115 Rename first use of T
// #TEST#: R1116 Rename concept Multiplicable
// #TEST#: R1117 Rename second use of T
// #TEST#: R1118 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
// #TEST#: R1119 Rename function product3
// #TEST#: R1120 Rename use of T
// #TEST#: R1121 Rename parameter lhs
// #TEST#: R1122 Rename use of U
// #TEST#: R1123 Rename parameter rhs
// #TEST#: R1124 Rename use of lhs
// #TEST#: R1125 Rename use of rhs
auto product3(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1126 Rename use of lhs
    // #TEST#: R1127 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on function
// #TEST#: R1128 Rename template parameter T
// #TEST#: R1129 Rename template parameter U
// #TEST#: R1130 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1131 Rename function product4
// #TEST#: R1132 Rename use of T
// #TEST#: R1133 Rename parameter lhs
// #TEST#: R1134 Rename use of U
// #TEST#: R1135 Rename parameter rhs
// #TEST#: R1136 Rename use of lhs
// #TEST#: R1137 Rename use of rhs
auto product4(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1138 Rename first use of T
    // #TEST#: R1139 Rename concept Multiplicable
    // #TEST#: R1140 Rename second use of T
    // #TEST#: R1141 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
{
    // #TEST#: R1142 Rename use of lhs
    // #TEST#: R1143 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on template parameters
// #TEST#: R1144 Rename template parameter T
// #TEST#: R1145 Rename template parameter U
// #TEST#: R1146 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1147 Rename first use of T
// #TEST#: R1148 Rename concept Multiplicable
// #TEST#: R1149 Rename second use of T
// #TEST#: R1150 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
// #TEST#: R1151 Rename function product5
// #TEST#: R1152 Rename use of T
// #TEST#: R1153 Rename parameter lhs
// #TEST#: R1154 Rename use of U
// #TEST#: R1155 Rename parameter rhs
// #TEST#: R1156 Rename use of lhs
// #TEST#: R1157 Rename use of rhs
auto product5(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1158 Rename use of lhs
    // #TEST#: R1159 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on function
// #TEST#: R1160 Rename template parameter T
// #TEST#: R1161 Rename template parameter U
// #TEST#: R1162 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1163 Rename function product6
// #TEST#: R1164 Rename use of T
// #TEST#: R1165 Rename parameter lhs
// #TEST#: R1166 Rename use of U
// #TEST#: R1167 Rename parameter rhs
// #TEST#: R1168 Rename use of lhs
// #TEST#: R1169 Rename use of rhs
auto product6(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1170 Rename first use of T
    // #TEST#: R1171 Rename concept Multiplicable
    // #TEST#: R1172 Rename second use of T
    // #TEST#: R1173 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
{
    // #TEST#: R1174 Rename use of lhs
    // #TEST#: R1175 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on template parameters
// #TEST#: R1176 Rename template parameter T
// #TEST#: R1177 Rename template parameter U
// #TEST#: R1178 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1179 Rename first use of T
// #TEST#: R1180 Rename first use of U
// #TEST#: R1181 Rename concept Multiplicable
// #TEST#: R1182 Rename second use of T
// #TEST#: R1183 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
// #TEST#: R1184 Rename function product7
// #TEST#: R1185 Rename use of T
// #TEST#: R1186 Rename parameter lhs
// #TEST#: R1187 Rename use of U
// #TEST#: R1188 Rename parameter rhs
// #TEST#: R1189 Rename use of lhs
// #TEST#: R1190 Rename use of rhs
auto product7(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1191 Rename use of lhs
    // #TEST#: R1192 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on function
// #TEST#: R1193 Rename template parameter T
// #TEST#: R1194 Rename template parameter U
// #TEST#: R1195 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1196 Rename function product8
// #TEST#: R1197 Rename use of T
// #TEST#: R1198 Rename parameter lhs
// #TEST#: R1199 Rename use of U
// #TEST#: R1200 Rename parameter rhs
// #TEST#: R1201 Rename use of lhs
// #TEST#: R1202 Rename use of rhs
auto product8(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1203 Rename first use of T
    // #TEST#: R1204 Rename first use of U
    // #TEST#: R1205 Rename concept Multiplicable
    // #TEST#: R1206 Rename second use of T
    // #TEST#: R1207 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
{
    // #TEST#: R1208 Rename use of lhs
    // #TEST#: R1209 Rename use of rhs
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
    // single template parameter function with simple constraint on template parameter
    {
        // #TEST#: R1210 Rename function square1
        REQUIRE_EQUAL(4, square1(2));
        // #TEST#: R1211 Rename function square1
        const double d = square1(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1212 Rename function square1
        const Rope r = square1(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with simple constraint on function
    {
        // #TEST#: R1213 Rename function square2
        REQUIRE_EQUAL(4, square2(2));
        // #TEST#: R1214 Rename function square2
        const double d = square2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1215 Rename function square2
        const Rope r = square2(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with disjunctive constraint on template parameter
    {
        // #TEST#: R1216 Rename function square3
        REQUIRE_EQUAL(4, square3(2));
        // #TEST#: R1217 Rename function square3
        const double d = square3(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1218 Rename function square3
        const Rope r = square3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on template parameter
    {
        // #TEST#: R1219 Rename function square4
        REQUIRE_EQUAL(4, square4(2));
        // #TEST#: R1220 Rename function square4
        const double d = square4(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1221 Rename function square5
        REQUIRE_EQUAL(4, square5(2));
        // #TEST#: R1222 Rename function square5
        const double d = square5(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1223 Rename function square5
        const Rope r = square5(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1224 Rename function square6
        REQUIRE_EQUAL(4, square6(2));
        // #TEST#: R1225 Rename function square6
        const double d = square6(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on template parameter
    {
        // #TEST#: R1226 Rename function square7
        REQUIRE_EQUAL(4, square7(2));
        // #TEST#: R1227 Rename function square7
        const double d = square7(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on function
    {
        // #TEST#: R1228 Rename function square8
        REQUIRE_EQUAL(4, square8(2));
        // #TEST#: R1229 Rename function square8
        const double d = square8(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // multiple template parameter function with simple constraint on template parameters
    {
        // #TEST#: R1230 Rename function product1
        REQUIRE_EQUAL(6.0, product1(2, 3.0));
        // #TEST#: R1231 Rename function product1
        const double d = product1(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1232 Rename function product1
        const Rope r = product1(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with simple constraint on function
    {
        // #TEST#: R1233 Rename function product2
        REQUIRE_EQUAL(6.0, product2(2, 3.0));
        // #TEST#: R1234 Rename function product2
        const double d = product2(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1235 Rename function product2
        const Rope r = product2(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on template parameters
    {
        // #TEST#: R1236 Rename function product3
        REQUIRE_EQUAL(6.0, product3(2, 3.0));
        // #TEST#: R1237 Rename function product3
        const double d = product3(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1238 Rename function product3
        const Rope r = product3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1239 Rename function product4
        REQUIRE_EQUAL(6.0, product4(2, 3.0));
        // #TEST#: R1240 Rename function product4
        const double d = product4(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1521 Rename function product4
        const Rope r = product4(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with conjunctive constraint on template parameters
    {
        // #TEST#: R1241 Rename function product5
        REQUIRE_EQUAL(6.0, product5(2, 3.0));
        // #TEST#: R1242 Rename function product5
        const double d = product5(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1243 Rename function product6
        REQUIRE_EQUAL(6.0, product6(2, 3.0));
        // #TEST#: R1244 Rename function product6
        const double d = product6(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with combined constraint on template parameters
    {
        // #TEST#: R1245 Rename function product7
        REQUIRE_EQUAL(6.0, product7(2, 3.0));
        // #TEST#: R1246 Rename function product7
        const double d = product7(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1247 Rename function product7
        const Rope r = product7(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with combined constraint on function
    {
        // #TEST#: R1248 Rename function product8
        REQUIRE_EQUAL(6.0, product8(2, 3.0));
        // #TEST#: R1249 Rename function product8
        const double d = product8(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1250 Rename function product8
        const Rope r = product8(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
}

// single constraint on single template parameter
// #TEST#: R1251 Rename template parameter T
template <typename T>
// #TEST#: R1252 Rename concept Squareable
// #TEST#: R1253 Rename use of T
    requires Squareable<T>
// #TEST#: R1254 Rename class Sqr1
class Sqr1
{
public:
    // #TEST#: R1255 Rename first use of T
    // #TEST#: R1256 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1257 Rename template parameter T
template <typename T>
// #TEST#: R1258 Rename concept Squareable
// #TEST#: R1259 Rename use of T
    requires Squareable<T>
// #TEST#: R1260 Rename class SqrStruct1
struct SqrStruct1
{
    // #TEST#: R1261 Rename first use of T
    // #TEST#: R1262 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1263 Rename template parameter T
template <typename T>
// #TEST#: R1264 Rename concept Squareable
// #TEST#: R1265 Rename use of T
    requires Squareable<T>
// #TEST#: R1266 Rename class SqrUnion1
union SqrUnion1
{
    // #TEST#: R1267 Rename first use of T
    // #TEST#: R1268 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, disjunction
// #TEST#: R1269 Rename template parameter T
template <typename T>
// #TEST#: R1522 Rename first use of T
// #TEST#: R1270 Rename concept Squareable
// #TEST#: R1271 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1272 Rename class Sqr2
class Sqr2
{
public:
    // #TEST#: R1273 Rename first use of T
    // #TEST#: R1274 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1275 Rename template parameter T
template <typename T>
// #TEST#: R1523 Rename first use of T
// #TEST#: R1276 Rename concept Squareable
// #TEST#: R1277 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1278 Rename class SqrStruct2
struct SqrStruct2
{
    // #TEST#: R1279 Rename first use of T
    // #TEST#: R1280 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1281 Rename template parameter T
template <typename T>
// #TEST#: R1524 Rename first use of T
// #TEST#: R1282 Rename concept Squareable
// #TEST#: R1283 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1284 Rename class SqrUnion2
union SqrUnion2
{
    // #TEST#: R1285 Rename first use of T
    // #TEST#: R1286 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, conjunction
// #TEST#: R1287 Rename template parameter T
template <typename T>
// #TEST#: R1525 Rename first use of T
// #TEST#: R1288 Rename concept Squareable
// #TEST#: R1289 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1290 Rename class Sqr3
class Sqr3
{
public:
    // #TEST#: R1291 Rename first use of T
    // #TEST#: R1292 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1293 Rename template parameter T
template <typename T>
// #TEST#: R1526 Rename first use of T
// #TEST#: R1294 Rename concept Squareable
// #TEST#: R1295 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1296 Rename class SqrStruct3
struct SqrStruct3
{
    // #TEST#: R1297 Rename first use of T
    // #TEST#: R1298 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1299 Rename template parameter T
template <typename T>
// #TEST#: R1527 Rename first use of T
// #TEST#: R1300 Rename concept Squareable
// #TEST#: R1301 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1302 Rename class SqrUnion3
union SqrUnion3
{
    // #TEST#: R1303 Rename first use of T
    // #TEST#: R1304 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, combination
// #TEST#: R1305 Rename template parameter T
template <typename T>
// #TEST#: R1528 Rename first use of T
// #TEST#: R1529 Rename second use of T
// #TEST#: R1306 Rename concept Squareable
// #TEST#: R1307 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1308 Rename class Sqr4
class Sqr4
{
public:
    // #TEST#: R1309 Rename first use of T
    // #TEST#: R1310 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1311 Rename template parameter T
template <typename T>
// #TEST#: R1530 Rename first use of T
// #TEST#: R1531 Rename second use of T
// #TEST#: R1312 Rename concept Squareable
// #TEST#: R1313 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1314 Rename class SqrStruct4
struct SqrStruct4
{
    // #TEST#: R1315 Rename first use of T
    // #TEST#: R1316 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1317 Rename template parameter T
template <typename T>
// #TEST#: R1532 Rename first use of T
// #TEST#: R1533 Rename second use of T
// #TEST#: R1318 Rename concept Squareable
// #TEST#: R1319 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1320 Rename class SqrUnion4
union SqrUnion4
{
    // #TEST#: R1321 Rename first use of T
    // #TEST#: R1322 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// single constraint on multiple template parameters
// #TEST#: R1323 Rename template parameter T
// #TEST#: R1324 Rename template parameter U
// #TEST#: R1534 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1325 Rename concept Multiplicable
// #TEST#: R1326 Rename use of T
// #TEST#: R1327 Rename use of U
    requires Multiplicable<T, U>
class Product1
{
public:
    // #TEST#: R1328 Rename use of T
    // #TEST#: R1329 Rename parameter lhs
    // #TEST#: R1330 Rename use of U
    // #TEST#: R1331 Rename parameter rhs
    // #TEST#: R1332 Rename first use of lhs
    // #TEST#: R1333 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1334 Rename lhs
        // #TEST#: R1335 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1336 Rename template parameter T
// #TEST#: R1337 Rename template parameter U
// #TEST#: R1535 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1338 Rename concept Multiplicable
// #TEST#: R1339 Rename use of T
// #TEST#: R1340 Rename use of U
    requires Multiplicable<T, U>
struct ProductStruct1
{
    // #TEST#: R1341 Rename use of T
    // #TEST#: R1342 Rename parameter lhs
    // #TEST#: R1343 Rename use of U
    // #TEST#: R1344 Rename parameter rhs
    // #TEST#: R1345 Rename first use of lhs
    // #TEST#: R1346 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1347 Rename lhs
        // #TEST#: R1348 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1349 Rename template parameter T
// #TEST#: R1350 Rename template parameter U
// #TEST#: R1536 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1351 Rename concept Multiplicable
// #TEST#: R1352 Rename use of T
// #TEST#: R1353 Rename use of U
    requires Multiplicable<T, U>
union ProductUnion1
{
    // #TEST#: R1354 Rename use of T
    // #TEST#: R1355 Rename parameter lhs
    // #TEST#: R1356 Rename use of U
    // #TEST#: R1357 Rename parameter rhs
    // #TEST#: R1358 Rename first use of lhs
    // #TEST#: R1359 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1360 Rename lhs
        // #TEST#: R1361 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, disjunction
// #TEST#: R1362 Rename template parameter T
// #TEST#: R1363 Rename template parameter U
// #TEST#: R1537 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1364 Rename first use of T
// #TEST#: R1365 Rename concept Multiplicable
// #TEST#: R1366 Rename second use of T
// #TEST#: R1367 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
class Product2
{
public:
    // #TEST#: R1368 Rename use of T
    // #TEST#: R1369 Rename parameter lhs
    // #TEST#: R1370 Rename use of U
    // #TEST#: R1371 Rename parameter rhs
    // #TEST#: R1372 Rename first use of lhs
    // #TEST#: R1373 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1374 Rename lhs
        // #TEST#: R1375 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1376 Rename template parameter T
// #TEST#: R1377 Rename template parameter U
// #TEST#: R1538 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1378 Rename first use of T
// #TEST#: R1379 Rename concept Multiplicable
// #TEST#: R1380 Rename second use of T
// #TEST#: R1381 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
struct ProductStruct2
{
    // #TEST#: R1382 Rename use of T
    // #TEST#: R1383 Rename parameter lhs
    // #TEST#: R1384 Rename use of U
    // #TEST#: R1385 Rename parameter rhs
    // #TEST#: R1386 Rename first use of lhs
    // #TEST#: R1387 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1388 Rename lhs
        // #TEST#: R1389 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1390 Rename template parameter T
// #TEST#: R1391 Rename template parameter U
// #TEST#: R1539 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1392 Rename first use of T
// #TEST#: R1393 Rename concept Multiplicable
// #TEST#: R1394 Rename second use of T
// #TEST#: R1395 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
union ProductUnion2
{
    // #TEST#: R1396 Rename use of T
    // #TEST#: R1397 Rename parameter lhs
    // #TEST#: R1398 Rename use of U
    // #TEST#: R1399 Rename parameter rhs
    // #TEST#: R1400 Rename first use of lhs
    // #TEST#: R1401 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1402 Rename lhs
        // #TEST#: R1403 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, conjunction
// #TEST#: R1404 Rename template parameter T
// #TEST#: R1405 Rename template parameter U
// #TEST#: R1540 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1406 Rename first use of T
// #TEST#: R1407 Rename concept Multiplicable
// #TEST#: R1408 Rename second use of T
// #TEST#: R1409 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
class Product3
{
public:
    // #TEST#: R1410 Rename use of T
    // #TEST#: R1411 Rename parameter lhs
    // #TEST#: R1412 Rename use of U
    // #TEST#: R1413 Rename parameter rhs
    // #TEST#: R1414 Rename first use of lhs
    // #TEST#: R1415 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1416 Rename lhs
        // #TEST#: R1417 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1418 Rename template parameter T
// #TEST#: R1419 Rename template parameter U
// #TEST#: R1541 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1420 Rename first use of T
// #TEST#: R1421 Rename concept Multiplicable
// #TEST#: R1422 Rename second use of T
// #TEST#: R1423 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
struct ProductStruct3
{
    // #TEST#: R1424 Rename use of T
    // #TEST#: R1425 Rename parameter lhs
    // #TEST#: R1426 Rename use of U
    // #TEST#: R1427 Rename parameter rhs
    // #TEST#: R1428 Rename first use of lhs
    // #TEST#: R1429 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1430 Rename lhs
        // #TEST#: R1431 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1432 Rename template parameter T
// #TEST#: R1433 Rename template parameter U
// #TEST#: R1542 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1434 Rename first use of T
// #TEST#: R1435 Rename concept Multiplicable
// #TEST#: R1436 Rename second use of T
// #TEST#: R1437 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
union ProductUnion3
{
    // #TEST#: R1438 Rename use of T
    // #TEST#: R1439 Rename parameter lhs
    // #TEST#: R1440 Rename use of U
    // #TEST#: R1441 Rename parameter rhs
    // #TEST#: R1442 Rename first use of lhs
    // #TEST#: R1443 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1444 Rename lhs
        // #TEST#: R1445 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, combination
// #TEST#: R1446 Rename template parameter T
// #TEST#: R1447 Rename template parameter U
// #TEST#: R1543 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1448 Rename first use of T
// #TEST#: R1449 Rename second use of T
// #TEST#: R1450 Rename concept Multiplicable
// #TEST#: R1451 Rename third use of T
// #TEST#: R1452 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
class Product4
{
public:
    // #TEST#: R1453 Rename use of T
    // #TEST#: R1454 Rename parameter lhs
    // #TEST#: R1455 Rename use of U
    // #TEST#: R1456 Rename parameter rhs
    // #TEST#: R1457 Rename first use of lhs
    // #TEST#: R1458 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1459 Rename lhs
        // #TEST#: R1460 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1461 Rename template parameter T
// #TEST#: R1462 Rename template parameter U
// #TEST#: R1544 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1463 Rename first use of T
// #TEST#: R1464 Rename second use of T
// #TEST#: R1465 Rename concept Multiplicable
// #TEST#: R1466 Rename third use of T
// #TEST#: R1467 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
struct ProductStruct4
{
    // #TEST#: R1468 Rename use of T
    // #TEST#: R1469 Rename parameter lhs
    // #TEST#: R1470 Rename use of U
    // #TEST#: R1471 Rename parameter rhs
    // #TEST#: R1472 Rename first use of lhs
    // #TEST#: R1473 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1474 Rename lhs
        // #TEST#: R1475 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1476 Rename template parameter T
// #TEST#: R1477 Rename template parameter U
// #TEST#: R1545 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1478 Rename first use of T
// #TEST#: R1479 Rename second use of T
// #TEST#: R1480 Rename concept Multiplicable
// #TEST#: R1481 Rename third use of T
// #TEST#: R1482 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
union ProductUnion4
{
    // #TEST#: R1483 Rename use of T
    // #TEST#: R1484 Rename parameter lhs
    // #TEST#: R1485 Rename use of U
    // #TEST#: R1486 Rename parameter rhs
    // #TEST#: R1487 Rename first use of lhs
    // #TEST#: R1488 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1489 Rename lhs
        // #TEST#: R1490 Rename rhs
        return lhs * rhs;
    }
};

// Simple constraint expressions via require clauses
// [X] class/struct/union templates
//     [X] single template parameter
//         [X] single constraint on template parameters
//         [X] compound constraint on template parameters
//             [X] conjunction
//             [X] disjunction
//             [X] combination
//     [X] multiple template parameters
//         [X] single constraint on template parameters
//         [X] compound constraint on template parameters
//             [X] conjunction
//             [X] disjunction
//             [X] combination
void f2()
{
    // single constraint on single template parameter
    {
        // #TEST#: R1491 Rename Sqr1
        Sqr1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1492 Rename Sqr1
        Sqr1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1493 Rename Sqr1
        Sqr1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1494 Rename SqrStruct1
        SqrStruct1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1495 Rename SqrStruct1
        SqrStruct1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1496 Rename SqrStruct1
        SqrStruct1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1497 Rename SqrUnion1
        SqrUnion1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1498 Rename SqrUnion1
        SqrUnion1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1499 Rename SqrUnion1
        SqrUnion1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, disjunction
    {
        // #TEST#: R1500 Rename Sqr2
        Sqr2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1501 Rename Sqr2
        Sqr2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1502 Rename Sqr2
        Sqr2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1503 Rename SqrStruct2
        SqrStruct2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1504 Rename SqrStruct2
        SqrStruct2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1505 Rename SqrStruct2
        SqrStruct2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1506 Rename SqrUnion2
        SqrUnion2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1507 Rename SqrUnion2
        SqrUnion2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1508 Rename SqrUnion2
        SqrUnion2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, conjunction
    {
        // #TEST#: R1509 Rename Sqr3
        Sqr3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1510 Rename Sqr3
        Sqr3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1511 Rename SqrStruct3
        SqrStruct3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1512 Rename SqrStruct3
        SqrStruct3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1513 Rename SqrUnion3
        SqrUnion3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1514 Rename SqrUnion3
        SqrUnion3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on single template parameter, combination
    {
        // #TEST#: R1515 Rename Sqr4
        Sqr4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1516 Rename Sqr4
        Sqr4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1517 Rename SqrStruct4
        SqrStruct4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1518 Rename SqrStruct4
        SqrStruct4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1519 Rename SqrUnion4
        SqrUnion4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1520 Rename SqrUnion4
        SqrUnion4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // single constraint on multiple template parameters
    {
        // #TEST#: R1546 Rename Product1
        Product1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1547 Rename Product1
        Product1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1548 Rename Product1
        Product1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1549 Rename ProductStruct1
        ProductStruct1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1550 Rename ProductStruct1
        ProductStruct1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1551 Rename ProductStruct1
        ProductStruct1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1552 Rename ProductUnion1
        ProductUnion1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1553 Rename ProductUnion1
        ProductUnion1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1554 Rename ProductUnion1
        ProductUnion1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, disjunction
    {
        // #TEST#: R1555 Rename Product2
        Product2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1556 Rename Product2
        Product2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1557 Rename Product2
        Product2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1558 Rename ProductStruct2
        ProductStruct2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1559 Rename ProductStruct2
        ProductStruct2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1560 Rename ProductStruct2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1561 Rename ProductUnion2
        ProductUnion2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1562 Rename ProductUnion2
        ProductUnion2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1563 Rename ProductUnion2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, conjunction
    {
        // #TEST#: R1564 Rename Product3
        Product3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1565 Rename Product3
        Product3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1566 Rename ProductStruct3
        ProductStruct3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1567 Rename ProductStruct3
        ProductStruct3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1568 Rename ProductUnion3
        ProductUnion3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1569 Rename ProductUnion3
        ProductUnion3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on multiple template parameters, combination
    {
        // #TEST#: R1570 Rename Product4
        Product4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1571 Rename Product4
        Product4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1572 Rename ProductStruct4
        ProductStruct4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1573 Rename ProductStruct4
        ProductStruct4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1574 Rename ProductUnion4
        ProductUnion4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1575 Rename ProductUnion4
        ProductUnion4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
}

}    // namespace

namespace RenameCpp20
{

void TestRenameConstraints()
{
    f1();
    f2();
}

}    // namespace RenameCpp20
