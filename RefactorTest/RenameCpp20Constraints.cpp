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
// #TEST#: R991 Rename template parameter T
template <typename T>
// #TEST#: R992 Rename concept Squareable
// #TEST#: R993 Rename use of T
// #TEST#: R994 Rename parameter lhs
concept Squareable = requires(T lhs)
{
    // #TEST#: R995 Rename first use of lhs
    // #TEST#: R996 Rename second use of lhs
    lhs * lhs;
};

// Simple concept with multiple template parameters
// #TEST#: R997 Rename template parameter T
// #TEST#: R998 Rename template parameter U
template <typename T, typename U>
// #TEST#: R999 Rename concept Multiplicable
// #TEST#: R1000 Rename use of T
// #TEST#: R1001 Rename parameter lhs
// #TEST#: R1002 Rename use of U
// #TEST#: R1003 Rename parameter rhs
concept Multiplicable = requires(T lhs, U rhs)
{
    // #TEST#: R1004 Rename use of lhs
    // #TEST#: R1005 Rename use of rhs
    lhs * rhs;
};
// clang-format on

// single template parameter function with simple constraint on template parameter
// #TEST#: R1006 Rename template parameter T
template <typename T>
// #TEST#: R1007 Rename concept Squareable
// #TEST#: R1008 Rename use of T
    requires Squareable<T>
// #TEST#: R1009 Rename first use of T
// #TEST#: R1010 Rename function square1
// #TEST#: R1011 Rename second use of T
// #TEST#: R1012 Rename parameter value
T square1(T value)
{
    // #TEST#: R1013 Rename first use of value
    // #TEST#: R1014 Rename second use of value
    return value * value;
}

// single template parameter function with simple constraint on function
// #TEST#: R1015 Rename template parameter T
template <typename T>
// #TEST#: R1016 Rename first use of T
// #TEST#: R1017 Rename function square2
// #TEST#: R1018 Rename second use of T
// #TEST#: R1019 Rename parameter value
T square2(T value)
    // #TEST#: R1020 Rename concept Squareable
    // #TEST#: R1021 Rename use of T
    requires Squareable<T>
{
    // #TEST#: R1022 Rename first use of value
    // #TEST#: R1023 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on template parameter
// #TEST#: R1024 Rename template parameter T
template <typename T>
// #TEST#: R1025 Rename first use of T
// #TEST#: R1026 Rename concept Squareable
// #TEST#: R1027 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1028 Rename first use of T
// #TEST#: R1029 Rename function square3
// #TEST#: R1030 Rename second use of T
// #TEST#: R1031 Rename parameter value
T square3(T value)
{
    // #TEST#: R1032 Rename first use of value
    // #TEST#: R1033 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on template parameter
// #TEST#: R1034 Rename template parameter T
template <typename T>
// #TEST#: R1035 Rename first use of T
// #TEST#: R1036 Rename concept Squareable
// #TEST#: R1037 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1038 Rename first use of T
// #TEST#: R1039 Rename function square4
// #TEST#: R1040 Rename second use of T
// #TEST#: R1041 Rename parameter value
T square4(T value)
{
    // #TEST#: R1042 Rename first use of value
    // #TEST#: R1043 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on function
// #TEST#: R1044 Rename template parameter T
template <typename T>
// #TEST#: R1045 Rename first use of T
// #TEST#: R1046 Rename function square5
// #TEST#: R1047 Rename second use of T
// #TEST#: R1048 Rename parameter value
T square5(T value)
    // #TEST#: R1049 Rename first use of T
    // #TEST#: R1050 Rename concept Squareable
    // #TEST#: R1051 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
{
    // #TEST#: R1052 Rename first use of value
    // #TEST#: R1053 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on function
// #TEST#: R1054 Rename template parameter T
template <typename T>
// #TEST#: R1055 Rename first use of T
// #TEST#: R1056 Rename function square6
// #TEST#: R1057 Rename second use of T
// #TEST#: R1058 Rename parameter value
T square6(T value)
    // #TEST#: R1059 Rename first use of T
    // #TEST#: R1060 Rename concept Squareable
    // #TEST#: R1061 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
{
    // #TEST#: R1062 Rename first use of value
    // #TEST#: R1063 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on template parameter
// #TEST#: R1064 Rename template parameter T
template <typename T>
// #TEST#: R1065 Rename first use of T
// #TEST#: R1066 Rename second use of T
// #TEST#: R1067 Rename concept Squareable
// #TEST#: R1068 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1069 Rename first use of T
// #TEST#: R1070 Rename function square7
// #TEST#: R1071 Rename second use of T
// #TEST#: R1072 Rename parameter value
T square7(T value)
{
    // #TEST#: R1073 Rename first use of value
    // #TEST#: R1074 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on function
// #TEST#: R1075 Rename template parameter T
template <typename T>
// #TEST#: R1076 Rename first use of T
// #TEST#: R1077 Rename function square8
// #TEST#: R1078 Rename second use of T
// #TEST#: R1079 Rename parameter value
T square8(T value)
    // #TEST#: R1080 Rename first use of T
    // #TEST#: R1081 Rename second use of T
    // #TEST#: R1082 Rename concept Squareable
    // #TEST#: R1083 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
{
    // #TEST#: R1084 Rename first use of value
    // #TEST#: R1085 Rename second use of value
    return value * value;
}

// multiple template parameter function with simple constraint on template parameters
// #TEST#: R1086 Rename template parameter T
// #TEST#: R1087 Rename template parameter U
// #TEST#: R1088 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1089 Rename concept Multiplicable
// #TEST#: R1090 Rename use of T
// #TEST#: R1091 Rename use of U
    requires Multiplicable<T, U>
// #TEST#: R1092 Rename function product1
// #TEST#: R1093 Rename use of T
// #TEST#: R1094 Rename parameter lhs
// #TEST#: R1095 Rename use of U
// #TEST#: R1096 Rename parameter rhs
// #TEST#: R1097 Rename use of lhs
// #TEST#: R1098 Rename use of rhs
auto product1(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1099 Rename use of lhs
    // #TEST#: R1100 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with simple constraint on function
// #TEST#: R1101 Rename template parameter T
// #TEST#: R1102 Rename template parameter U
// #TEST#: R1103 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1104 Rename function product2
// #TEST#: R1105 Rename use of T
// #TEST#: R1106 Rename parameter lhs
// #TEST#: R1107 Rename use of U
// #TEST#: R1108 Rename parameter rhs
// #TEST#: R1109 Rename use of lhs
// #TEST#: R1110 Rename use of rhs
auto product2(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1111 Rename concept Multiplicable
    // #TEST#: R1112 Rename use of T
    // #TEST#: R1113 Rename use of U
    requires Multiplicable<T, U>
{
    // #TEST#: R1114 Rename use of lhs
    // #TEST#: R1115 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on template parameters
// #TEST#: R1116 Rename template parameter T
// #TEST#: R1117 Rename template parameter U
// #TEST#: R1118 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1119 Rename first use of T
// #TEST#: R1120 Rename concept Multiplicable
// #TEST#: R1121 Rename second use of T
// #TEST#: R1122 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
// #TEST#: R1123 Rename function product3
// #TEST#: R1124 Rename use of T
// #TEST#: R1125 Rename parameter lhs
// #TEST#: R1126 Rename use of U
// #TEST#: R1127 Rename parameter rhs
// #TEST#: R1128 Rename use of lhs
// #TEST#: R1129 Rename use of rhs
auto product3(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1130 Rename use of lhs
    // #TEST#: R1131 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on function
// #TEST#: R1132 Rename template parameter T
// #TEST#: R1133 Rename template parameter U
// #TEST#: R1134 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1135 Rename function product4
// #TEST#: R1136 Rename use of T
// #TEST#: R1137 Rename parameter lhs
// #TEST#: R1138 Rename use of U
// #TEST#: R1139 Rename parameter rhs
// #TEST#: R1140 Rename use of lhs
// #TEST#: R1141 Rename use of rhs
auto product4(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1142 Rename first use of T
    // #TEST#: R1143 Rename concept Multiplicable
    // #TEST#: R1144 Rename second use of T
    // #TEST#: R1145 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
{
    // #TEST#: R1146 Rename use of lhs
    // #TEST#: R1147 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on template parameters
// #TEST#: R1148 Rename template parameter T
// #TEST#: R1149 Rename template parameter U
// #TEST#: R1150 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1151 Rename first use of T
// #TEST#: R1152 Rename concept Multiplicable
// #TEST#: R1153 Rename second use of T
// #TEST#: R1154 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
// #TEST#: R1155 Rename function product5
// #TEST#: R1156 Rename use of T
// #TEST#: R1157 Rename parameter lhs
// #TEST#: R1158 Rename use of U
// #TEST#: R1159 Rename parameter rhs
// #TEST#: R1160 Rename use of lhs
// #TEST#: R1161 Rename use of rhs
auto product5(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1162 Rename use of lhs
    // #TEST#: R1163 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on function
// #TEST#: R1164 Rename template parameter T
// #TEST#: R1165 Rename template parameter U
// #TEST#: R1166 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1167 Rename function product6
// #TEST#: R1168 Rename use of T
// #TEST#: R1169 Rename parameter lhs
// #TEST#: R1170 Rename use of U
// #TEST#: R1171 Rename parameter rhs
// #TEST#: R1172 Rename use of lhs
// #TEST#: R1173 Rename use of rhs
auto product6(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1174 Rename first use of T
    // #TEST#: R1175 Rename concept Multiplicable
    // #TEST#: R1176 Rename second use of T
    // #TEST#: R1177 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
{
    // #TEST#: R1178 Rename use of lhs
    // #TEST#: R1179 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on template parameters
// #TEST#: R1180 Rename template parameter T
// #TEST#: R1181 Rename template parameter U
// #TEST#: R1182 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1183 Rename first use of T
// #TEST#: R1184 Rename first use of U
// #TEST#: R1185 Rename concept Multiplicable
// #TEST#: R1186 Rename second use of T
// #TEST#: R1187 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
// #TEST#: R1188 Rename function product7
// #TEST#: R1189 Rename use of T
// #TEST#: R1190 Rename parameter lhs
// #TEST#: R1191 Rename use of U
// #TEST#: R1192 Rename parameter rhs
// #TEST#: R1193 Rename use of lhs
// #TEST#: R1194 Rename use of rhs
auto product7(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1195 Rename use of lhs
    // #TEST#: R1196 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on function
// #TEST#: R1197 Rename template parameter T
// #TEST#: R1198 Rename template parameter U
// #TEST#: R1199 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1200 Rename function product8
// #TEST#: R1201 Rename use of T
// #TEST#: R1202 Rename parameter lhs
// #TEST#: R1203 Rename use of U
// #TEST#: R1204 Rename parameter rhs
// #TEST#: R1205 Rename use of lhs
// #TEST#: R1206 Rename use of rhs
auto product8(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1207 Rename first use of T
    // #TEST#: R1208 Rename first use of U
    // #TEST#: R1209 Rename concept Multiplicable
    // #TEST#: R1210 Rename second use of T
    // #TEST#: R1211 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
{
    // #TEST#: R1212 Rename use of lhs
    // #TEST#: R1213 Rename use of rhs
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
        // #TEST#: R1214 Rename function square1
        REQUIRE_EQUAL(4, square1(2));
        // #TEST#: R1215 Rename function square1
        const double d = square1(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1216 Rename function square1
        const Rope r = square1(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with simple constraint on function
    {
        // #TEST#: R1217 Rename function square2
        REQUIRE_EQUAL(4, square2(2));
        // #TEST#: R1218 Rename function square2
        const double d = square2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1219 Rename function square2
        const Rope r = square2(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with disjunctive constraint on template parameter
    {
        // #TEST#: R1220 Rename function square3
        REQUIRE_EQUAL(4, square3(2));
        // #TEST#: R1221 Rename function square3
        const double d = square3(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1222 Rename function square3
        const Rope r = square3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on template parameter
    {
        // #TEST#: R1223 Rename function square4
        REQUIRE_EQUAL(4, square4(2));
        // #TEST#: R1224 Rename function square4
        const double d = square4(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1225 Rename function square5
        REQUIRE_EQUAL(4, square5(2));
        // #TEST#: R1226 Rename function square5
        const double d = square5(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1227 Rename function square5
        const Rope r = square5(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1228 Rename function square6
        REQUIRE_EQUAL(4, square6(2));
        // #TEST#: R1229 Rename function square6
        const double d = square6(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on template parameter
    {
        // #TEST#: R1230 Rename function square7
        REQUIRE_EQUAL(4, square7(2));
        // #TEST#: R1231 Rename function square7
        const double d = square7(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on function
    {
        // #TEST#: R1232 Rename function square8
        REQUIRE_EQUAL(4, square8(2));
        // #TEST#: R1233 Rename function square8
        const double d = square8(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // multiple template parameter function with simple constraint on template parameters
    {
        // #TEST#: R1234 Rename function product1
        REQUIRE_EQUAL(6.0, product1(2, 3.0));
        // #TEST#: R1235 Rename function product1
        const double d = product1(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1236 Rename function product1
        const Rope r = product1(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with simple constraint on function
    {
        // #TEST#: R1237 Rename function product2
        REQUIRE_EQUAL(6.0, product2(2, 3.0));
        // #TEST#: R1238 Rename function product2
        const double d = product2(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1239 Rename function product2
        const Rope r = product2(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on template parameters
    {
        // #TEST#: R1240 Rename function product3
        REQUIRE_EQUAL(6.0, product3(2, 3.0));
        // #TEST#: R1241 Rename function product3
        const double d = product3(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1242 Rename function product3
        const Rope r = product3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1243 Rename function product4
        REQUIRE_EQUAL(6.0, product4(2, 3.0));
        // #TEST#: R1244 Rename function product4
        const double d = product4(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1245 Rename function product4
        const Rope r = product4(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with conjunctive constraint on template parameters
    {
        // #TEST#: R1246 Rename function product5
        REQUIRE_EQUAL(6.0, product5(2, 3.0));
        // #TEST#: R1247 Rename function product5
        const double d = product5(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1248 Rename function product6
        REQUIRE_EQUAL(6.0, product6(2, 3.0));
        // #TEST#: R1249 Rename function product6
        const double d = product6(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with combined constraint on template parameters
    {
        // #TEST#: R1250 Rename function product7
        REQUIRE_EQUAL(6.0, product7(2, 3.0));
        // #TEST#: R1251 Rename function product7
        const double d = product7(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1252 Rename function product7
        const Rope r = product7(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with combined constraint on function
    {
        // #TEST#: R1253 Rename function product8
        REQUIRE_EQUAL(6.0, product8(2, 3.0));
        // #TEST#: R1254 Rename function product8
        const double d = product8(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1255 Rename function product8
        const Rope r = product8(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
}

// single constraint on single template parameter
// #TEST#: R1256 Rename template parameter T
template <typename T>
// #TEST#: R1257 Rename concept Squareable
// #TEST#: R1258 Rename use of T
    requires Squareable<T>
// #TEST#: R1259 Rename class Sqr1
class Sqr1
{
public:
    // #TEST#: R1260 Rename first use of T
    // #TEST#: R1261 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1262 Rename template parameter T
template <typename T>
// #TEST#: R1263 Rename concept Squareable
// #TEST#: R1264 Rename use of T
    requires Squareable<T>
// #TEST#: R1265 Rename class SqrStruct1
struct SqrStruct1
{
    // #TEST#: R1266 Rename first use of T
    // #TEST#: R1267 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1268 Rename template parameter T
template <typename T>
// #TEST#: R1269 Rename concept Squareable
// #TEST#: R1270 Rename use of T
    requires Squareable<T>
// #TEST#: R1271 Rename class SqrUnion1
union SqrUnion1
{
    // #TEST#: R1272 Rename first use of T
    // #TEST#: R1273 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, disjunction
// #TEST#: R1274 Rename template parameter T
template <typename T>
// #TEST#: R1275 Rename first use of T
// #TEST#: R1276 Rename concept Squareable
// #TEST#: R1277 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1278 Rename class Sqr2
class Sqr2
{
public:
    // #TEST#: R1279 Rename first use of T
    // #TEST#: R1280 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1281 Rename template parameter T
template <typename T>
// #TEST#: R1282 Rename first use of T
// #TEST#: R1283 Rename concept Squareable
// #TEST#: R1284 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1285 Rename class SqrStruct2
struct SqrStruct2
{
    // #TEST#: R1286 Rename first use of T
    // #TEST#: R1287 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1288 Rename template parameter T
template <typename T>
// #TEST#: R1289 Rename first use of T
// #TEST#: R1290 Rename concept Squareable
// #TEST#: R1291 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1292 Rename class SqrUnion2
union SqrUnion2
{
    // #TEST#: R1293 Rename first use of T
    // #TEST#: R1294 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, conjunction
// #TEST#: R1295 Rename template parameter T
template <typename T>
// #TEST#: R1296 Rename first use of T
// #TEST#: R1297 Rename concept Squareable
// #TEST#: R1298 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1299 Rename class Sqr3
class Sqr3
{
public:
    // #TEST#: R1300 Rename first use of T
    // #TEST#: R1301 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1302 Rename template parameter T
template <typename T>
// #TEST#: R1303 Rename first use of T
// #TEST#: R1304 Rename concept Squareable
// #TEST#: R1305 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1306 Rename class SqrStruct3
struct SqrStruct3
{
    // #TEST#: R1307 Rename first use of T
    // #TEST#: R1308 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1309 Rename template parameter T
template <typename T>
// #TEST#: R1310 Rename first use of T
// #TEST#: R1311 Rename concept Squareable
// #TEST#: R1312 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1313 Rename class SqrUnion3
union SqrUnion3
{
    // #TEST#: R1314 Rename first use of T
    // #TEST#: R1315 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, combination
// #TEST#: R1316 Rename template parameter T
template <typename T>
// #TEST#: R1317 Rename first use of T
// #TEST#: R1318 Rename second use of T
// #TEST#: R1319 Rename concept Squareable
// #TEST#: R1320 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1321 Rename class Sqr4
class Sqr4
{
public:
    // #TEST#: R1322 Rename first use of T
    // #TEST#: R1323 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1324 Rename template parameter T
template <typename T>
// #TEST#: R1325 Rename first use of T
// #TEST#: R1326 Rename second use of T
// #TEST#: R1327 Rename concept Squareable
// #TEST#: R1328 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1329 Rename class SqrStruct4
struct SqrStruct4
{
    // #TEST#: R1330 Rename first use of T
    // #TEST#: R1331 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1332 Rename template parameter T
template <typename T>
// #TEST#: R1333 Rename first use of T
// #TEST#: R1334 Rename second use of T
// #TEST#: R1335 Rename concept Squareable
// #TEST#: R1336 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1337 Rename class SqrUnion4
union SqrUnion4
{
    // #TEST#: R1338 Rename first use of T
    // #TEST#: R1339 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// single constraint on multiple template parameters
// #TEST#: R1340 Rename template parameter T
// #TEST#: R1341 Rename template parameter U
// #TEST#: R1342 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1343 Rename concept Multiplicable
// #TEST#: R1344 Rename use of T
// #TEST#: R1345 Rename use of U
    requires Multiplicable<T, U>
class Product1
{
public:
    // #TEST#: R1346 Rename use of T
    // #TEST#: R1347 Rename parameter lhs
    // #TEST#: R1348 Rename use of U
    // #TEST#: R1349 Rename parameter rhs
    // #TEST#: R1350 Rename first use of lhs
    // #TEST#: R1351 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1352 Rename lhs
        // #TEST#: R1353 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1354 Rename template parameter T
// #TEST#: R1355 Rename template parameter U
// #TEST#: R1356 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1357 Rename concept Multiplicable
// #TEST#: R1358 Rename use of T
// #TEST#: R1359 Rename use of U
    requires Multiplicable<T, U>
struct ProductStruct1
{
    // #TEST#: R1360 Rename use of T
    // #TEST#: R1361 Rename parameter lhs
    // #TEST#: R1362 Rename use of U
    // #TEST#: R1363 Rename parameter rhs
    // #TEST#: R1364 Rename first use of lhs
    // #TEST#: R1365 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1366 Rename lhs
        // #TEST#: R1367 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1368 Rename template parameter T
// #TEST#: R1369 Rename template parameter U
// #TEST#: R1370 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1371 Rename concept Multiplicable
// #TEST#: R1372 Rename use of T
// #TEST#: R1373 Rename use of U
    requires Multiplicable<T, U>
union ProductUnion1
{
    // #TEST#: R1374 Rename use of T
    // #TEST#: R1375 Rename parameter lhs
    // #TEST#: R1376 Rename use of U
    // #TEST#: R1377 Rename parameter rhs
    // #TEST#: R1378 Rename first use of lhs
    // #TEST#: R1379 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1380 Rename lhs
        // #TEST#: R1381 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, disjunction
// #TEST#: R1382 Rename template parameter T
// #TEST#: R1383 Rename template parameter U
// #TEST#: R1384 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1385 Rename first use of T
// #TEST#: R1386 Rename concept Multiplicable
// #TEST#: R1387 Rename second use of T
// #TEST#: R1388 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
class Product2
{
public:
    // #TEST#: R1389 Rename use of T
    // #TEST#: R1390 Rename parameter lhs
    // #TEST#: R1391 Rename use of U
    // #TEST#: R1392 Rename parameter rhs
    // #TEST#: R1393 Rename first use of lhs
    // #TEST#: R1394 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1395 Rename lhs
        // #TEST#: R1396 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1397 Rename template parameter T
// #TEST#: R1398 Rename template parameter U
// #TEST#: R1399 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1400 Rename first use of T
// #TEST#: R1401 Rename concept Multiplicable
// #TEST#: R1402 Rename second use of T
// #TEST#: R1403 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
struct ProductStruct2
{
    // #TEST#: R1404 Rename use of T
    // #TEST#: R1405 Rename parameter lhs
    // #TEST#: R1406 Rename use of U
    // #TEST#: R1407 Rename parameter rhs
    // #TEST#: R1408 Rename first use of lhs
    // #TEST#: R1409 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1410 Rename lhs
        // #TEST#: R1411 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1412 Rename template parameter T
// #TEST#: R1413 Rename template parameter U
// #TEST#: R1414 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1415 Rename first use of T
// #TEST#: R1416 Rename concept Multiplicable
// #TEST#: R1417 Rename second use of T
// #TEST#: R1418 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
union ProductUnion2
{
    // #TEST#: R1419 Rename use of T
    // #TEST#: R1420 Rename parameter lhs
    // #TEST#: R1421 Rename use of U
    // #TEST#: R1422 Rename parameter rhs
    // #TEST#: R1423 Rename first use of lhs
    // #TEST#: R1424 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1425 Rename lhs
        // #TEST#: R1426 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, conjunction
// #TEST#: R1427 Rename template parameter T
// #TEST#: R1428 Rename template parameter U
// #TEST#: R1429 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1430 Rename first use of T
// #TEST#: R1431 Rename concept Multiplicable
// #TEST#: R1432 Rename second use of T
// #TEST#: R1433 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
class Product3
{
public:
    // #TEST#: R1434 Rename use of T
    // #TEST#: R1435 Rename parameter lhs
    // #TEST#: R1436 Rename use of U
    // #TEST#: R1437 Rename parameter rhs
    // #TEST#: R1438 Rename first use of lhs
    // #TEST#: R1439 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1440 Rename lhs
        // #TEST#: R1441 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1442 Rename template parameter T
// #TEST#: R1443 Rename template parameter U
// #TEST#: R1444 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1445 Rename first use of T
// #TEST#: R1446 Rename concept Multiplicable
// #TEST#: R1447 Rename second use of T
// #TEST#: R1448 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
struct ProductStruct3
{
    // #TEST#: R1449 Rename use of T
    // #TEST#: R1450 Rename parameter lhs
    // #TEST#: R1451 Rename use of U
    // #TEST#: R1452 Rename parameter rhs
    // #TEST#: R1453 Rename first use of lhs
    // #TEST#: R1454 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1455 Rename lhs
        // #TEST#: R1456 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1457 Rename template parameter T
// #TEST#: R1458 Rename template parameter U
// #TEST#: R1459 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1460 Rename first use of T
// #TEST#: R1461 Rename concept Multiplicable
// #TEST#: R1462 Rename second use of T
// #TEST#: R1463 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
union ProductUnion3
{
    // #TEST#: R1464 Rename use of T
    // #TEST#: R1465 Rename parameter lhs
    // #TEST#: R1466 Rename use of U
    // #TEST#: R1467 Rename parameter rhs
    // #TEST#: R1468 Rename first use of lhs
    // #TEST#: R1469 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1470 Rename lhs
        // #TEST#: R1471 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, combination
// #TEST#: R1472 Rename template parameter T
// #TEST#: R1473 Rename template parameter U
// #TEST#: R1474 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1475 Rename first use of T
// #TEST#: R1476 Rename second use of T
// #TEST#: R1477 Rename concept Multiplicable
// #TEST#: R1478 Rename third use of T
// #TEST#: R1479 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
class Product4
{
public:
    // #TEST#: R1480 Rename use of T
    // #TEST#: R1481 Rename parameter lhs
    // #TEST#: R1482 Rename use of U
    // #TEST#: R1483 Rename parameter rhs
    // #TEST#: R1484 Rename first use of lhs
    // #TEST#: R1485 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1486 Rename lhs
        // #TEST#: R1487 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1488 Rename template parameter T
// #TEST#: R1489 Rename template parameter U
// #TEST#: R1490 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1491 Rename first use of T
// #TEST#: R1492 Rename second use of T
// #TEST#: R1493 Rename concept Multiplicable
// #TEST#: R1494 Rename third use of T
// #TEST#: R1495 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
struct ProductStruct4
{
    // #TEST#: R1496 Rename use of T
    // #TEST#: R1497 Rename parameter lhs
    // #TEST#: R1498 Rename use of U
    // #TEST#: R1499 Rename parameter rhs
    // #TEST#: R1500 Rename first use of lhs
    // #TEST#: R1501 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1502 Rename lhs
        // #TEST#: R1503 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1504 Rename template parameter T
// #TEST#: R1505 Rename template parameter U
// #TEST#: R1506 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1507 Rename first use of T
// #TEST#: R1508 Rename second use of T
// #TEST#: R1509 Rename concept Multiplicable
// #TEST#: R1510 Rename third use of T
// #TEST#: R1511 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
union ProductUnion4
{
    // #TEST#: R1512 Rename use of T
    // #TEST#: R1513 Rename parameter lhs
    // #TEST#: R1514 Rename use of U
    // #TEST#: R1515 Rename parameter rhs
    // #TEST#: R1516 Rename first use of lhs
    // #TEST#: R1517 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1518 Rename lhs
        // #TEST#: R1519 Rename rhs
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
        // #TEST#: R1520 Rename Sqr1
        Sqr1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1521 Rename Sqr1
        Sqr1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1522 Rename Sqr1
        Sqr1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1523 Rename SqrStruct1
        SqrStruct1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1524 Rename SqrStruct1
        SqrStruct1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1525 Rename SqrStruct1
        SqrStruct1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1526 Rename SqrUnion1
        SqrUnion1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1527 Rename SqrUnion1
        SqrUnion1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1528 Rename SqrUnion1
        SqrUnion1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, disjunction
    {
        // #TEST#: R1529 Rename Sqr2
        Sqr2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1530 Rename Sqr2
        Sqr2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1531 Rename Sqr2
        Sqr2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1532 Rename SqrStruct2
        SqrStruct2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1533 Rename SqrStruct2
        SqrStruct2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1534 Rename SqrStruct2
        SqrStruct2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1535 Rename SqrUnion2
        SqrUnion2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1536 Rename SqrUnion2
        SqrUnion2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1537 Rename SqrUnion2
        SqrUnion2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, conjunction
    {
        // #TEST#: R1538 Rename Sqr3
        Sqr3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1539 Rename Sqr3
        Sqr3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1540 Rename SqrStruct3
        SqrStruct3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1541 Rename SqrStruct3
        SqrStruct3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1542 Rename SqrUnion3
        SqrUnion3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1543 Rename SqrUnion3
        SqrUnion3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on single template parameter, combination
    {
        // #TEST#: R1544 Rename Sqr4
        Sqr4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1545 Rename Sqr4
        Sqr4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1546 Rename SqrStruct4
        SqrStruct4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1547 Rename SqrStruct4
        SqrStruct4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1548 Rename SqrUnion4
        SqrUnion4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1549 Rename SqrUnion4
        SqrUnion4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // single constraint on multiple template parameters
    {
        // #TEST#: R1550 Rename Product1
        Product1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1551 Rename Product1
        Product1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1552 Rename Product1
        Product1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1553 Rename ProductStruct1
        ProductStruct1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1554 Rename ProductStruct1
        ProductStruct1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1555 Rename ProductStruct1
        ProductStruct1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1556 Rename ProductUnion1
        ProductUnion1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1557 Rename ProductUnion1
        ProductUnion1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1558 Rename ProductUnion1
        ProductUnion1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, disjunction
    {
        // #TEST#: R1559 Rename Product2
        Product2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1560 Rename Product2
        Product2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1561 Rename Product2
        Product2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1562 Rename ProductStruct2
        ProductStruct2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1563 Rename ProductStruct2
        ProductStruct2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1564 Rename ProductStruct2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1565 Rename ProductUnion2
        ProductUnion2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1566 Rename ProductUnion2
        ProductUnion2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1567 Rename ProductUnion2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, conjunction
    {
        // #TEST#: R1568 Rename Product3
        Product3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1569 Rename Product3
        Product3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1570 Rename ProductStruct3
        ProductStruct3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1571 Rename ProductStruct3
        ProductStruct3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1572 Rename ProductUnion3
        ProductUnion3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1573 Rename ProductUnion3
        ProductUnion3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on multiple template parameters, combination
    {
        // #TEST#: R1574 Rename Product4
        Product4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1575 Rename Product4
        Product4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1576 Rename ProductStruct4
        ProductStruct4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1577 Rename ProductStruct4
        ProductStruct4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1578 Rename ProductUnion4
        ProductUnion4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1579 Rename ProductUnion4
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
