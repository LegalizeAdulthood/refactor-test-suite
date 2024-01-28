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
// #TEST#: R988 Rename template parameter T
template <typename T>
// #TEST#: R989 Rename concept Squareable
// #TEST#: R990 Rename use of T
// #TEST#: R991 Rename parameter lhs
concept Squareable = requires(T lhs)
{
    // #TEST#: R992 Rename first use of lhs
    // #TEST#: R993 Rename second use of lhs
    lhs * lhs;
};

// Simple concept with multiple template parameters
// #TEST#: R994 Rename template parameter T
// #TEST#: R995 Rename template parameter U
template <typename T, typename U>
// #TEST#: R996 Rename concept Multiplicable
// #TEST#: R997 Rename use of T
// #TEST#: R998 Rename parameter lhs
// #TEST#: R999 Rename use of U
// #TEST#: R1000 Rename parameter rhs
concept Multiplicable = requires(T lhs, U rhs)
{
    // #TEST#: R1001 Rename use of lhs
    // #TEST#: R1002 Rename use of rhs
    lhs * rhs;
};
// clang-format on

// single template parameter function with simple constraint on template parameter
// #TEST#: R1003 Rename template parameter T
template <typename T>
// #TEST#: R1004 Rename concept Squareable
// #TEST#: R1005 Rename use of T
    requires Squareable<T>
// #TEST#: R1006 Rename first use of T
// #TEST#: R1007 Rename function square1
// #TEST#: R1008 Rename second use of T
// #TEST#: R1009 Rename parameter value
T square1(T value)
{
    // #TEST#: R1010 Rename first use of value
    // #TEST#: R1011 Rename second use of value
    return value * value;
}

// single template parameter function with simple constraint on function
// #TEST#: R1012 Rename template parameter T
template <typename T>
// #TEST#: R1013 Rename first use of T
// #TEST#: R1014 Rename function square2
// #TEST#: R1015 Rename second use of T
// #TEST#: R1016 Rename parameter value
T square2(T value)
    // #TEST#: R1017 Rename concept Squareable
    // #TEST#: R1018 Rename use of T
    requires Squareable<T>
{
    // #TEST#: R1019 Rename first use of value
    // #TEST#: R1020 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on template parameter
// #TEST#: R1021 Rename template parameter T
template <typename T>
// #TEST#: R1022 Rename first use of T
// #TEST#: R1023 Rename concept Squareable
// #TEST#: R1024 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1025 Rename first use of T
// #TEST#: R1026 Rename function square3
// #TEST#: R1027 Rename second use of T
// #TEST#: R1028 Rename parameter value
T square3(T value)
{
    // #TEST#: R1029 Rename first use of value
    // #TEST#: R1030 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on template parameter
// #TEST#: R1031 Rename template parameter T
template <typename T>
// #TEST#: R1032 Rename first use of T
// #TEST#: R1033 Rename concept Squareable
// #TEST#: R1034 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1035 Rename first use of T
// #TEST#: R1036 Rename function square4
// #TEST#: R1037 Rename second use of T
// #TEST#: R1038 Rename parameter value
T square4(T value)
{
    // #TEST#: R1039 Rename first use of value
    // #TEST#: R1040 Rename second use of value
    return value * value;
}

// single template parameter function with disjunctive constraint on function
// #TEST#: R1041 Rename template parameter T
template <typename T>
// #TEST#: R1042 Rename first use of T
// #TEST#: R1043 Rename function square5
// #TEST#: R1044 Rename second use of T
// #TEST#: R1045 Rename parameter value
T square5(T value)
    // #TEST#: R1046 Rename first use of T
    // #TEST#: R1047 Rename concept Squareable
    // #TEST#: R1048 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
{
    // #TEST#: R1049 Rename first use of value
    // #TEST#: R1050 Rename second use of value
    return value * value;
}

// single template parameter function with conjunctive constraint on function
// #TEST#: R1051 Rename template parameter T
template <typename T>
// #TEST#: R1052 Rename first use of T
// #TEST#: R1053 Rename function square6
// #TEST#: R1054 Rename second use of T
// #TEST#: R1055 Rename parameter value
T square6(T value)
    // #TEST#: R1056 Rename first use of T
    // #TEST#: R1057 Rename concept Squareable
    // #TEST#: R1058 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
{
    // #TEST#: R1059 Rename first use of value
    // #TEST#: R1060 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on template parameter
// #TEST#: R1061 Rename template parameter T
template <typename T>
// #TEST#: R1062 Rename first use of T
// #TEST#: R1063 Rename second use of T
// #TEST#: R1064 Rename concept Squareable
// #TEST#: R1065 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1066 Rename first use of T
// #TEST#: R1067 Rename function square7
// #TEST#: R1068 Rename second use of T
// #TEST#: R1069 Rename parameter value
T square7(T value)
{
    // #TEST#: R1070 Rename first use of value
    // #TEST#: R1071 Rename second use of value
    return value * value;
}

// single template parameter function with combined constraint on function
// #TEST#: R1072 Rename template parameter T
template <typename T>
// #TEST#: R1073 Rename first use of T
// #TEST#: R1074 Rename function square8
// #TEST#: R1075 Rename second use of T
// #TEST#: R1076 Rename parameter value
T square8(T value)
    // #TEST#: R1077 Rename first use of T
    // #TEST#: R1078 Rename second use of T
    // #TEST#: R1079 Rename concept Squareable
    // #TEST#: R1080 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
{
    // #TEST#: R1081 Rename first use of value
    // #TEST#: R1082 Rename second use of value
    return value * value;
}

// multiple template parameter function with simple constraint on template parameters
// #TEST#: R1083 Rename template parameter T
// #TEST#: R1084 Rename template parameter U
// #TEST#: R1085 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1086 Rename concept Multiplicable
// #TEST#: R1087 Rename use of T
// #TEST#: R1088 Rename use of U
    requires Multiplicable<T, U>
// #TEST#: R1089 Rename function product1
// #TEST#: R1090 Rename use of T
// #TEST#: R1091 Rename parameter lhs
// #TEST#: R1092 Rename use of U
// #TEST#: R1093 Rename parameter rhs
// #TEST#: R1094 Rename use of lhs
// #TEST#: R1095 Rename use of rhs
auto product1(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1096 Rename use of lhs
    // #TEST#: R1097 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with simple constraint on function
// #TEST#: R1098 Rename template parameter T
// #TEST#: R1099 Rename template parameter U
// #TEST#: R1100 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1101 Rename function product2
// #TEST#: R1102 Rename use of T
// #TEST#: R1103 Rename parameter lhs
// #TEST#: R1104 Rename use of U
// #TEST#: R1105 Rename parameter rhs
// #TEST#: R1106 Rename use of lhs
// #TEST#: R1107 Rename use of rhs
auto product2(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1108 Rename concept Multiplicable
    // #TEST#: R1109 Rename use of T
    // #TEST#: R1110 Rename use of U
    requires Multiplicable<T, U>
{
    // #TEST#: R1111 Rename use of lhs
    // #TEST#: R1112 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on template parameters
// #TEST#: R1113 Rename template parameter T
// #TEST#: R1114 Rename template parameter U
// #TEST#: R1115 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1116 Rename first use of T
// #TEST#: R1117 Rename concept Multiplicable
// #TEST#: R1118 Rename second use of T
// #TEST#: R1119 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
// #TEST#: R1120 Rename function product3
// #TEST#: R1121 Rename use of T
// #TEST#: R1122 Rename parameter lhs
// #TEST#: R1123 Rename use of U
// #TEST#: R1124 Rename parameter rhs
// #TEST#: R1125 Rename use of lhs
// #TEST#: R1126 Rename use of rhs
auto product3(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1127 Rename use of lhs
    // #TEST#: R1128 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with disjunctive constraint on function
// #TEST#: R1129 Rename template parameter T
// #TEST#: R1130 Rename template parameter U
// #TEST#: R1131 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1132 Rename function product4
// #TEST#: R1133 Rename use of T
// #TEST#: R1134 Rename parameter lhs
// #TEST#: R1135 Rename use of U
// #TEST#: R1136 Rename parameter rhs
// #TEST#: R1137 Rename use of lhs
// #TEST#: R1138 Rename use of rhs
auto product4(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1139 Rename first use of T
    // #TEST#: R1140 Rename concept Multiplicable
    // #TEST#: R1141 Rename second use of T
    // #TEST#: R1142 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
{
    // #TEST#: R1143 Rename use of lhs
    // #TEST#: R1144 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on template parameters
// #TEST#: R1145 Rename template parameter T
// #TEST#: R1146 Rename template parameter U
// #TEST#: R1147 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1148 Rename first use of T
// #TEST#: R1149 Rename concept Multiplicable
// #TEST#: R1150 Rename second use of T
// #TEST#: R1151 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
// #TEST#: R1152 Rename function product5
// #TEST#: R1153 Rename use of T
// #TEST#: R1154 Rename parameter lhs
// #TEST#: R1155 Rename use of U
// #TEST#: R1156 Rename parameter rhs
// #TEST#: R1157 Rename use of lhs
// #TEST#: R1158 Rename use of rhs
auto product5(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1159 Rename use of lhs
    // #TEST#: R1160 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with conjunctive constraint on function
// #TEST#: R1161 Rename template parameter T
// #TEST#: R1162 Rename template parameter U
// #TEST#: R1163 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1164 Rename function product6
// #TEST#: R1165 Rename use of T
// #TEST#: R1166 Rename parameter lhs
// #TEST#: R1167 Rename use of U
// #TEST#: R1168 Rename parameter rhs
// #TEST#: R1169 Rename use of lhs
// #TEST#: R1170 Rename use of rhs
auto product6(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1171 Rename first use of T
    // #TEST#: R1172 Rename concept Multiplicable
    // #TEST#: R1173 Rename second use of T
    // #TEST#: R1174 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
{
    // #TEST#: R1175 Rename use of lhs
    // #TEST#: R1176 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on template parameters
// #TEST#: R1177 Rename template parameter T
// #TEST#: R1178 Rename template parameter U
// #TEST#: R1179 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1180 Rename first use of T
// #TEST#: R1181 Rename first use of U
// #TEST#: R1182 Rename concept Multiplicable
// #TEST#: R1183 Rename second use of T
// #TEST#: R1184 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
// #TEST#: R1185 Rename function product7
// #TEST#: R1186 Rename use of T
// #TEST#: R1187 Rename parameter lhs
// #TEST#: R1188 Rename use of U
// #TEST#: R1189 Rename parameter rhs
// #TEST#: R1190 Rename use of lhs
// #TEST#: R1191 Rename use of rhs
auto product7(T lhs, U rhs) -> decltype(lhs * rhs)
{
    // #TEST#: R1192 Rename use of lhs
    // #TEST#: R1193 Rename use of rhs
    return lhs * rhs;
}

// multiple template parameter function with combined constraint on function
// #TEST#: R1194 Rename template parameter T
// #TEST#: R1195 Rename template parameter U
// #TEST#: R1196 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1197 Rename function product8
// #TEST#: R1198 Rename use of T
// #TEST#: R1199 Rename parameter lhs
// #TEST#: R1200 Rename use of U
// #TEST#: R1201 Rename parameter rhs
// #TEST#: R1202 Rename use of lhs
// #TEST#: R1203 Rename use of rhs
auto product8(T lhs, U rhs) -> decltype(lhs * rhs)
    // #TEST#: R1204 Rename first use of T
    // #TEST#: R1205 Rename first use of U
    // #TEST#: R1206 Rename concept Multiplicable
    // #TEST#: R1207 Rename second use of T
    // #TEST#: R1208 Rename second use of U
    requires(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>) || Multiplicable<T, U>
{
    // #TEST#: R1209 Rename use of lhs
    // #TEST#: R1210 Rename use of rhs
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
        // #TEST#: R1211 Rename function square1
        REQUIRE_EQUAL(4, square1(2));
        // #TEST#: R1212 Rename function square1
        const double d = square1(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1213 Rename function square1
        const Rope r = square1(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with simple constraint on function
    {
        // #TEST#: R1214 Rename function square2
        REQUIRE_EQUAL(4, square2(2));
        // #TEST#: R1215 Rename function square2
        const double d = square2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1216 Rename function square2
        const Rope r = square2(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with disjunctive constraint on template parameter
    {
        // #TEST#: R1217 Rename function square3
        REQUIRE_EQUAL(4, square3(2));
        // #TEST#: R1218 Rename function square3
        const double d = square3(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1219 Rename function square3
        const Rope r = square3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on template parameter
    {
        // #TEST#: R1220 Rename function square4
        REQUIRE_EQUAL(4, square4(2));
        // #TEST#: R1221 Rename function square4
        const double d = square4(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1222 Rename function square5
        REQUIRE_EQUAL(4, square5(2));
        // #TEST#: R1223 Rename function square5
        const double d = square5(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1224 Rename function square5
        const Rope r = square5(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    // single template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1225 Rename function square6
        REQUIRE_EQUAL(4, square6(2));
        // #TEST#: R1226 Rename function square6
        const double d = square6(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on template parameter
    {
        // #TEST#: R1227 Rename function square7
        REQUIRE_EQUAL(4, square7(2));
        // #TEST#: R1228 Rename function square7
        const double d = square7(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    // single template parameter function with combined constraint on function
    {
        // #TEST#: R1229 Rename function square8
        REQUIRE_EQUAL(4, square8(2));
        // #TEST#: R1230 Rename function square8
        const double d = square8(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // multiple template parameter function with simple constraint on template parameters
    {
        // #TEST#: R1231 Rename function product1
        REQUIRE_EQUAL(6.0, product1(2, 3.0));
        // #TEST#: R1232 Rename function product1
        const double d = product1(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1233 Rename function product1
        const Rope r = product1(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with simple constraint on function
    {
        // #TEST#: R1234 Rename function product2
        REQUIRE_EQUAL(6.0, product2(2, 3.0));
        // #TEST#: R1235 Rename function product2
        const double d = product2(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1236 Rename function product2
        const Rope r = product2(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on template parameters
    {
        // #TEST#: R1237 Rename function product3
        REQUIRE_EQUAL(6.0, product3(2, 3.0));
        // #TEST#: R1238 Rename function product3
        const double d = product3(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1239 Rename function product3
        const Rope r = product3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with disjunctive constraint on function
    {
        // #TEST#: R1240 Rename function product4
        REQUIRE_EQUAL(6.0, product4(2, 3.0));
        // #TEST#: R1241 Rename function product4
        const double d = product4(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1242 Rename function product4
        const Rope r = product4(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with conjunctive constraint on template parameters
    {
        // #TEST#: R1243 Rename function product5
        REQUIRE_EQUAL(6.0, product5(2, 3.0));
        // #TEST#: R1244 Rename function product5
        const double d = product5(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with conjunctive constraint on function
    {
        // #TEST#: R1245 Rename function product6
        REQUIRE_EQUAL(6.0, product6(2, 3.0));
        // #TEST#: R1246 Rename function product6
        const double d = product6(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // Rope is not std::is_arithmetic
    }
    // multiple template parameter function with combined constraint on template parameters
    {
        // #TEST#: R1247 Rename function product7
        REQUIRE_EQUAL(6.0, product7(2, 3.0));
        // #TEST#: R1248 Rename function product7
        const double d = product7(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1249 Rename function product7
        const Rope r = product7(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    // multiple template parameter function with combined constraint on function
    {
        // #TEST#: R1250 Rename function product8
        REQUIRE_EQUAL(6.0, product8(2, 3.0));
        // #TEST#: R1251 Rename function product8
        const double d = product8(2.0, 3.0);
        REQUIRE_EQUAL(6.0, d);
        // #TEST#: R1252 Rename function product8
        const Rope r = product8(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
}

// single constraint on single template parameter
// #TEST#: R1253 Rename template parameter T
template <typename T>
// #TEST#: R1254 Rename concept Squareable
// #TEST#: R1255 Rename use of T
    requires Squareable<T>
// #TEST#: R1256 Rename class Sqr1
class Sqr1
{
public:
    // #TEST#: R1257 Rename first use of T
    // #TEST#: R1258 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1259 Rename template parameter T
template <typename T>
// #TEST#: R1260 Rename concept Squareable
// #TEST#: R1261 Rename use of T
    requires Squareable<T>
// #TEST#: R1262 Rename class SqrStruct1
struct SqrStruct1
{
    // #TEST#: R1263 Rename first use of T
    // #TEST#: R1264 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1265 Rename template parameter T
template <typename T>
// #TEST#: R1266 Rename concept Squareable
// #TEST#: R1267 Rename use of T
    requires Squareable<T>
// #TEST#: R1268 Rename class SqrUnion1
union SqrUnion1
{
    // #TEST#: R1269 Rename first use of T
    // #TEST#: R1270 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, disjunction
// #TEST#: R1271 Rename template parameter T
template <typename T>
// #TEST#: R1272 Rename first use of T
// #TEST#: R1273 Rename concept Squareable
// #TEST#: R1274 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1275 Rename class Sqr2
class Sqr2
{
public:
    // #TEST#: R1276 Rename first use of T
    // #TEST#: R1277 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1278 Rename template parameter T
template <typename T>
// #TEST#: R1279 Rename first use of T
// #TEST#: R1280 Rename concept Squareable
// #TEST#: R1281 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1282 Rename class SqrStruct2
struct SqrStruct2
{
    // #TEST#: R1283 Rename first use of T
    // #TEST#: R1284 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1285 Rename template parameter T
template <typename T>
// #TEST#: R1286 Rename first use of T
// #TEST#: R1287 Rename concept Squareable
// #TEST#: R1288 Rename second use of T
    requires std::is_arithmetic_v<T> || Squareable<T>
// #TEST#: R1289 Rename class SqrUnion2
union SqrUnion2
{
    // #TEST#: R1290 Rename first use of T
    // #TEST#: R1291 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, conjunction
// #TEST#: R1292 Rename template parameter T
template <typename T>
// #TEST#: R1293 Rename first use of T
// #TEST#: R1294 Rename concept Squareable
// #TEST#: R1295 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1296 Rename class Sqr3
class Sqr3
{
public:
    // #TEST#: R1297 Rename first use of T
    // #TEST#: R1298 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1299 Rename template parameter T
template <typename T>
// #TEST#: R1300 Rename first use of T
// #TEST#: R1301 Rename concept Squareable
// #TEST#: R1302 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1303 Rename class SqrStruct3
struct SqrStruct3
{
    // #TEST#: R1304 Rename first use of T
    // #TEST#: R1305 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1306 Rename template parameter T
template <typename T>
// #TEST#: R1307 Rename first use of T
// #TEST#: R1308 Rename concept Squareable
// #TEST#: R1309 Rename second use of T
    requires std::is_arithmetic_v<T> && Squareable<T>
// #TEST#: R1310 Rename class SqrUnion3
union SqrUnion3
{
    // #TEST#: R1311 Rename first use of T
    // #TEST#: R1312 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// compound constraint on single template parameter, combination
// #TEST#: R1313 Rename template parameter T
template <typename T>
// #TEST#: R1314 Rename first use of T
// #TEST#: R1315 Rename second use of T
// #TEST#: R1316 Rename concept Squareable
// #TEST#: R1317 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1318 Rename class Sqr4
class Sqr4
{
public:
    // #TEST#: R1319 Rename first use of T
    // #TEST#: R1320 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1321 Rename template parameter T
template <typename T>
// #TEST#: R1322 Rename first use of T
// #TEST#: R1323 Rename second use of T
// #TEST#: R1324 Rename concept Squareable
// #TEST#: R1325 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1326 Rename class SqrStruct4
struct SqrStruct4
{
    // #TEST#: R1327 Rename first use of T
    // #TEST#: R1328 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// #TEST#: R1329 Rename template parameter T
template <typename T>
// #TEST#: R1330 Rename first use of T
// #TEST#: R1331 Rename second use of T
// #TEST#: R1332 Rename concept Squareable
// #TEST#: R1333 Rename third use of T
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Squareable<T>
// #TEST#: R1334 Rename class SqrUnion4
union SqrUnion4
{
    // #TEST#: R1335 Rename first use of T
    // #TEST#: R1336 Rename second of T
    T operator()(T value) const
    {
        return value * value;
    }
};

// single constraint on multiple template parameters
// #TEST#: R1337 Rename template parameter T
// #TEST#: R1338 Rename template parameter U
// #TEST#: R1339 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1340 Rename concept Multiplicable
// #TEST#: R1341 Rename use of T
// #TEST#: R1342 Rename use of U
    requires Multiplicable<T, U>
class Product1
{
public:
    // #TEST#: R1343 Rename use of T
    // #TEST#: R1344 Rename parameter lhs
    // #TEST#: R1345 Rename use of U
    // #TEST#: R1346 Rename parameter rhs
    // #TEST#: R1347 Rename first use of lhs
    // #TEST#: R1348 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1349 Rename lhs
        // #TEST#: R1350 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1351 Rename template parameter T
// #TEST#: R1352 Rename template parameter U
// #TEST#: R1353 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1354 Rename concept Multiplicable
// #TEST#: R1355 Rename use of T
// #TEST#: R1356 Rename use of U
    requires Multiplicable<T, U>
struct ProductStruct1
{
    // #TEST#: R1357 Rename use of T
    // #TEST#: R1358 Rename parameter lhs
    // #TEST#: R1359 Rename use of U
    // #TEST#: R1360 Rename parameter rhs
    // #TEST#: R1361 Rename first use of lhs
    // #TEST#: R1362 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1363 Rename lhs
        // #TEST#: R1364 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1365 Rename template parameter T
// #TEST#: R1366 Rename template parameter U
// #TEST#: R1367 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1368 Rename concept Multiplicable
// #TEST#: R1369 Rename use of T
// #TEST#: R1370 Rename use of U
    requires Multiplicable<T, U>
union ProductUnion1
{
    // #TEST#: R1371 Rename use of T
    // #TEST#: R1372 Rename parameter lhs
    // #TEST#: R1373 Rename use of U
    // #TEST#: R1374 Rename parameter rhs
    // #TEST#: R1375 Rename first use of lhs
    // #TEST#: R1376 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1377 Rename lhs
        // #TEST#: R1378 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, disjunction
// #TEST#: R1379 Rename template parameter T
// #TEST#: R1380 Rename template parameter U
// #TEST#: R1381 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1382 Rename first use of T
// #TEST#: R1383 Rename concept Multiplicable
// #TEST#: R1384 Rename second use of T
// #TEST#: R1385 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
class Product2
{
public:
    // #TEST#: R1386 Rename use of T
    // #TEST#: R1387 Rename parameter lhs
    // #TEST#: R1388 Rename use of U
    // #TEST#: R1389 Rename parameter rhs
    // #TEST#: R1390 Rename first use of lhs
    // #TEST#: R1391 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1392 Rename lhs
        // #TEST#: R1393 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1394 Rename template parameter T
// #TEST#: R1395 Rename template parameter U
// #TEST#: R1396 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1397 Rename first use of T
// #TEST#: R1398 Rename concept Multiplicable
// #TEST#: R1399 Rename second use of T
// #TEST#: R1400 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
struct ProductStruct2
{
    // #TEST#: R1401 Rename use of T
    // #TEST#: R1402 Rename parameter lhs
    // #TEST#: R1403 Rename use of U
    // #TEST#: R1404 Rename parameter rhs
    // #TEST#: R1405 Rename first use of lhs
    // #TEST#: R1406 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1407 Rename lhs
        // #TEST#: R1408 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1409 Rename template parameter T
// #TEST#: R1410 Rename template parameter U
// #TEST#: R1411 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1412 Rename first use of T
// #TEST#: R1413 Rename concept Multiplicable
// #TEST#: R1414 Rename second use of T
// #TEST#: R1415 Rename use of U
    requires std::is_arithmetic_v<T> || Multiplicable<T, U>
union ProductUnion2
{
    // #TEST#: R1416 Rename use of T
    // #TEST#: R1417 Rename parameter lhs
    // #TEST#: R1418 Rename use of U
    // #TEST#: R1419 Rename parameter rhs
    // #TEST#: R1420 Rename first use of lhs
    // #TEST#: R1421 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1422 Rename lhs
        // #TEST#: R1423 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, conjunction
// #TEST#: R1424 Rename template parameter T
// #TEST#: R1425 Rename template parameter U
// #TEST#: R1426 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1427 Rename first use of T
// #TEST#: R1428 Rename concept Multiplicable
// #TEST#: R1429 Rename second use of T
// #TEST#: R1430 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
class Product3
{
public:
    // #TEST#: R1431 Rename use of T
    // #TEST#: R1432 Rename parameter lhs
    // #TEST#: R1433 Rename use of U
    // #TEST#: R1434 Rename parameter rhs
    // #TEST#: R1435 Rename first use of lhs
    // #TEST#: R1436 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1437 Rename lhs
        // #TEST#: R1438 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1439 Rename template parameter T
// #TEST#: R1440 Rename template parameter U
// #TEST#: R1441 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1442 Rename first use of T
// #TEST#: R1443 Rename concept Multiplicable
// #TEST#: R1444 Rename second use of T
// #TEST#: R1445 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
struct ProductStruct3
{
    // #TEST#: R1446 Rename use of T
    // #TEST#: R1447 Rename parameter lhs
    // #TEST#: R1448 Rename use of U
    // #TEST#: R1449 Rename parameter rhs
    // #TEST#: R1450 Rename first use of lhs
    // #TEST#: R1451 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1452 Rename lhs
        // #TEST#: R1453 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1454 Rename template parameter T
// #TEST#: R1455 Rename template parameter U
// #TEST#: R1456 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1457 Rename first use of T
// #TEST#: R1458 Rename concept Multiplicable
// #TEST#: R1459 Rename second use of T
// #TEST#: R1460 Rename use of U
    requires std::is_arithmetic_v<T> && Multiplicable<T, U>
union ProductUnion3
{
    // #TEST#: R1461 Rename use of T
    // #TEST#: R1462 Rename parameter lhs
    // #TEST#: R1463 Rename use of U
    // #TEST#: R1464 Rename parameter rhs
    // #TEST#: R1465 Rename first use of lhs
    // #TEST#: R1466 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1467 Rename lhs
        // #TEST#: R1468 Rename rhs
        return lhs * rhs;
    }
};

// compound constraint on multiple template parameters, combination
// #TEST#: R1469 Rename template parameter T
// #TEST#: R1470 Rename template parameter U
// #TEST#: R1471 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1472 Rename first use of T
// #TEST#: R1473 Rename second use of T
// #TEST#: R1474 Rename concept Multiplicable
// #TEST#: R1475 Rename third use of T
// #TEST#: R1476 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
class Product4
{
public:
    // #TEST#: R1477 Rename use of T
    // #TEST#: R1478 Rename parameter lhs
    // #TEST#: R1479 Rename use of U
    // #TEST#: R1480 Rename parameter rhs
    // #TEST#: R1481 Rename first use of lhs
    // #TEST#: R1482 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1483 Rename lhs
        // #TEST#: R1484 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1485 Rename template parameter T
// #TEST#: R1486 Rename template parameter U
// #TEST#: R1487 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1488 Rename first use of T
// #TEST#: R1489 Rename second use of T
// #TEST#: R1490 Rename concept Multiplicable
// #TEST#: R1491 Rename third use of T
// #TEST#: R1492 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
struct ProductStruct4
{
    // #TEST#: R1493 Rename use of T
    // #TEST#: R1494 Rename parameter lhs
    // #TEST#: R1495 Rename use of U
    // #TEST#: R1496 Rename parameter rhs
    // #TEST#: R1497 Rename first use of lhs
    // #TEST#: R1498 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1499 Rename lhs
        // #TEST#: R1500 Rename rhs
        return lhs * rhs;
    }
};

// #TEST#: R1501 Rename template parameter T
// #TEST#: R1502 Rename template parameter U
// #TEST#: R1503 Rename use of T
template <typename T, typename U = T>
// #TEST#: R1504 Rename first use of T
// #TEST#: R1505 Rename second use of T
// #TEST#: R1506 Rename concept Multiplicable
// #TEST#: R1507 Rename third use of T
// #TEST#: R1508 Rename use of U
    requires(std::is_integral_v<T> || std::is_floating_point_v<T>) && Multiplicable<T, U>
union ProductUnion4
{
    // #TEST#: R1509 Rename use of T
    // #TEST#: R1510 Rename parameter lhs
    // #TEST#: R1511 Rename use of U
    // #TEST#: R1512 Rename parameter rhs
    // #TEST#: R1513 Rename first use of lhs
    // #TEST#: R1514 Rename first use of rhs
    auto operator()(T lhs, U rhs) const -> decltype(lhs * rhs)
    {
        // #TEST#: R1515 Rename lhs
        // #TEST#: R1516 Rename rhs
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
        // #TEST#: R1517 Rename Sqr1
        Sqr1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1518 Rename Sqr1
        Sqr1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1519 Rename Sqr1
        Sqr1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1520 Rename SqrStruct1
        SqrStruct1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1521 Rename SqrStruct1
        SqrStruct1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1522 Rename SqrStruct1
        SqrStruct1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1523 Rename SqrUnion1
        SqrUnion1<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1524 Rename SqrUnion1
        SqrUnion1<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1525 Rename SqrUnion1
        SqrUnion1<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, disjunction
    {
        // #TEST#: R1526 Rename Sqr2
        Sqr2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1527 Rename Sqr2
        Sqr2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1528 Rename Sqr2
        Sqr2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1529 Rename SqrStruct2
        SqrStruct2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1530 Rename SqrStruct2
        SqrStruct2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1531 Rename SqrStruct2
        SqrStruct2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }
    {
        // #TEST#: R1532 Rename SqrUnion2
        SqrUnion2<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1533 Rename SqrUnion2
        SqrUnion2<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1534 Rename SqrUnion2
        SqrUnion2<Rope> s3;
        const Rope r = s3(Rope{"square"});
        REQUIRE_EQUAL(Rope{"square square"}, r);
    }

    // compound constraint on single template parameter, conjunction
    {
        // #TEST#: R1535 Rename Sqr3
        Sqr3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1536 Rename Sqr3
        Sqr3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1537 Rename SqrStruct3
        SqrStruct3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1538 Rename SqrStruct3
        SqrStruct3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1539 Rename SqrUnion3
        SqrUnion3<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1540 Rename SqrUnion3
        SqrUnion3<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on single template parameter, combination
    {
        // #TEST#: R1541 Rename Sqr4
        Sqr4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1542 Rename Sqr4
        Sqr4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1543 Rename SqrStruct4
        SqrStruct4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1544 Rename SqrStruct4
        SqrStruct4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1545 Rename SqrUnion4
        SqrUnion4<int> s1;
        REQUIRE_EQUAL(4, s1(2));
        // #TEST#: R1546 Rename SqrUnion4
        SqrUnion4<double> s2;
        const double d = s2(2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // single constraint on multiple template parameters
    {
        // #TEST#: R1547 Rename Product1
        Product1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1548 Rename Product1
        Product1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1549 Rename Product1
        Product1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1550 Rename ProductStruct1
        ProductStruct1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1551 Rename ProductStruct1
        ProductStruct1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1552 Rename ProductStruct1
        ProductStruct1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1553 Rename ProductUnion1
        ProductUnion1<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1554 Rename ProductUnion1
        ProductUnion1<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1555 Rename ProductUnion1
        ProductUnion1<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, disjunction
    {
        // #TEST#: R1556 Rename Product2
        Product2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1557 Rename Product2
        Product2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1558 Rename Product2
        Product2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1559 Rename ProductStruct2
        ProductStruct2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1560 Rename ProductStruct2
        ProductStruct2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1561 Rename ProductStruct2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }
    {
        // #TEST#: R1562 Rename ProductUnion2
        ProductUnion2<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1563 Rename ProductUnion2
        ProductUnion2<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // #TEST#: R1564 Rename ProductUnion2
        ProductStruct2<Rope> s3;
        const Rope r = s3(Rope{"two"}, Rope{"three"});
        REQUIRE_EQUAL(Rope{"two three"}, r);
    }

    // compound constraint on multiple template parameters, conjunction
    {
        // #TEST#: R1565 Rename Product3
        Product3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1566 Rename Product3
        Product3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1567 Rename ProductStruct3
        ProductStruct3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1568 Rename ProductStruct3
        ProductStruct3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1569 Rename ProductUnion3
        ProductUnion3<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1570 Rename ProductUnion3
        ProductUnion3<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }

    // compound constraint on multiple template parameters, combination
    {
        // #TEST#: R1571 Rename Product4
        Product4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1572 Rename Product4
        Product4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1573 Rename ProductStruct4
        ProductStruct4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1574 Rename ProductStruct4
        ProductStruct4<double> p2;
        const double d = p2(2.0, 2.0);
        REQUIRE_EQUAL(4.0, d);
        // Rope is not std::is_arithmetic
    }
    {
        // #TEST#: R1575 Rename ProductUnion4
        ProductUnion4<int, double> p1;
        REQUIRE_EQUAL(6.0, p1(2, 3.0));
        // #TEST#: R1576 Rename ProductUnion4
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
