#include "RenameCpp11.h"
#include "Require.h"

#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

namespace
{

// #TEST#: R104 Rename flag used in static_assert
constexpr bool flag = true;
// #TEST#: R105 Rename flag used in static_assert
constexpr bool flag2 = false;
// #TEST#: R106 Rename flag used in noexcept specification
constexpr bool flag3 = true;
// #TEST#: R107 Rename flag used in noexcept specification
constexpr bool flag4 = false;

// #TEST#: R100 Rename flag in static_assert
static_assert(flag, "Flag is false");
// #TEST#: R101 Rename flag2 in static_assert
static_assert(!flag2, "Flag2 is true");

// #TEST#: R102 Rename flag3 in noexcept specifier
void f1() noexcept(flag3)
{
}

// #TEST#: R103 Rename flag4 in noexcept specifier
void f2() noexcept(!flag4)
{
}

// #TEST#: R108 Rename T used in noexcept expression
template <typename T>
// #TEST#: R109 Rename T in noexcept expression
void f3() noexcept(noexcept(T()))
{
    // #TEST#: R110 Rename T used in noexcept expression
    T x = T();
}

void f4()
{
    // #TEST#: R111 Rename c16
    char16_t c16 = u'x';
    // #TEST#: R112 Rename c32
    char32_t c32 = U'x';

    std::ostringstream s;
    // #TEST#: R113 Rename c16
    s << static_cast<int>(c16);
    // #TEST#: R114 Rename c32
    s << static_cast<int>(c32);
}

void f5()
{
    // #TEST#: R115 Rename X used in alignof operator expression
    struct alignas(4) X
    {
        int x;
        char b;
    };
    // #TEST#: R116 Rename X
    require_equal(std::size_t{4}, alignof(X));
}

void f6()
{
    // #TEST#: R117 Rename X used in alignas specifier
    struct alignas(int) X
    {
        float y;
        char b;
    };
    // #TEST#: R118 Rename X in alignas specifier
    struct alignas(X) Y
    {
        float y;
        char b;
    };
    // #TEST#: R119 Rename X used in alignas specifier
    require_equal(alignof(int), alignof(X));
    // #TEST#: R120 Rename X used in alignas specifier
    require_equal(alignof(X), alignof(Y));
}

void f7()
{
    // #TEST#: R121 Rename X
    struct X
    {
        // #TEST#: R122 Rename X via default c'tor
        X() = default;
        // #TEST#: R123 Rename X via default copy c'tor
        // #TEST#: R124 Rename X via default copy c'tor argument
        X(const X &rhs) = default;
        // #TEST#: R125 Rename X via default move c'tor
        // #TEST#: R126 Rename X via default move c'tor argument
        X(X &&rhs) = default;
        // #TEST#: R127 Rename X via default d'tor
        ~X() = default;
        // #TEST#: R128 Rename X via default copy assignment return type
        // #TEST#: R129 Rename X via default copy assignment argument
        X &operator=(const X &rhs) = default;
        // #TEST#: R130 Rename X via default move assignment return type
        // #TEST#: R131 Rename X via default move assignment argument
        X &operator=(X &&rhs) = default;

        int x = 1;
        int y = 2;
        std::string s = "foo";
    };
    const auto check = [](const X &x)
    {
        require_equal(1, x.x);
        require_equal(2, x.y);
        require_equal(std::string("foo"), x.s);
    };
    const X x1;
    check(x1);
    const X x2(x1);
    check(x2);
    X x3;
    x3.x = -1;
    x3.y = -2;
    x3 = x1;
    check(x3);
    const X x4{X()};
    check(x4);
    X x5;
    x5 = X();
    check(x5);
}

void f8()
{
   // #TEST#: R132 Rename X
    struct X
    {
        // #TEST#: R133 Rename X via deleted c'tor
        X() = delete;
        // #TEST#: R134 Rename X via deleted copy c'tor
        // #TEST#: R135 Rename X via deleted copy c'tor argument
        X(const X &rhs) = delete;
        // #TEST#: R136 Rename X via deleted move c'tor
        // #TEST#: R137 Rename X via deleted move c'tor argument
        X(X &&rhs) = delete;
        // #TEST#: R138 Rename X via deleted d'tor
        ~X() = delete;
        // #TEST#: R139 Rename X via deleted copy assignment return type
        // #TEST#: R140 Rename X via deleted copy assignment argument
        X &operator=(const X &rhs) = delete;
        // #TEST#: R141 Rename X via deleted move assignment return type
        // #TEST#: R142 Rename X via deleted move assignment argument
        X &operator=(X &&rhs) = delete;

        int x = 1;
        int y = 2;
        std::string s = "foo";
    };
    // #TEST#: R143 Rename X
    X *x = nullptr;
 }

void f9()
{
    // #TEST#: R144 Rename x
    thread_local int x = 0;
    // #TEST#: R145 Rename use of x
    require_equal(0, x);
}

template <typename T>
void f10_aux(std::ostream &stream, T head)
{
    stream << head << '\n';
}

// #TEST#: R146 Rename T
// #TEST#: R147 Rename Args
template <typename T, typename... Args>
// #TEST#: R148 Rename T
// #TEST#: R149 Rename head
// #TEST#: R150 Rename Args
// #TEST#: R151 Rename tail
void f10_aux(std::ostream &stream, T head, Args... tail)
{
    // #TEST#: R152 Rename head
    stream << head << '\n';
    // #TEST#: R153 Rename tail
    // #TEST#: R154 Rename Args
    if (sizeof...(tail) > 0 || sizeof...(Args) > 0)
    {
        // #TEST#: R155 Rename tail
        f10_aux(stream, tail...);
    }
}

void f10()
{
    std::ostringstream result;
    f10_aux(result, 10, 20.5, "hello world!");
    require_equal(std::string{"10\n" "20.5\n" "hello world!\n"}, result.str());
}

// #TEST#: R156 Rename Args
template <typename... Args>
// #TEST#: R157 Rename X
class X
{
public:
    // #TEST#: R158 Rename X
    // #TEST#: R159 Rename Args
    // #TEST#: R160 Rename args
    X(Args... args)
    {
        std::ostringstream result;
        // #TEST#: R161 Rename args
        f10_aux(result, args...);
        m_str = result.str();
    }

    const std::string &str() const
    {
        return m_str;
    }

private:
    std::string m_str;
};

void f11()
{
    // #TEST#: R162 Rename X
    X<int, double, std::string> x{10, 20.5, "hello world!"};
    require_equal(std::string{"10\n" "20.5\n" "hello world!\n"}, x.str());
}

// #TEST#: R163 Rename Types
template <typename... Types>
// #TEST#: R164 Rename Types
using Tuple = std::tuple<Types...>;

void f12()
{
    Tuple<int, double, std::string> t{10, 20.0, "hello world!"};
    require_equal(10, std::get<0>(t));
    require_equal(20.0, std::get<1>(t));
    require_equal(std::string{"hello world!"}, std::get<2>(t));
}

// #TEST#: R165 Rename text
template <char... text>
// #TEST#: R166 Rename xull
unsigned long long operator""_xull()
{
    unsigned long long value = 0;
    // #TEST#: R167 Rename text
    std::initializer_list<char> chars{text...};
    for (char c : chars)
    {
        value *= 10ULL;
        value += c - '0';
    }
    return value;
}

// #TEST#: R169 Rename xull2
// #TEST#: R170 Rename text
unsigned long long operator""_xull2(const char *text)
{
    unsigned long long value = 0;
    while (*text)
    {
        value *= 10ULL;
        value += *text - '0';
        ++text;
    }
    return value;
}

// #TEST#: R172 Rename xd
// #TEST#: R173 Rename text
double operator""_xd(const char *text)
{
    const auto is_e = [](char c) { return c == 'e' || c == 'E'; };
    double value = 0.0;
    bool positive = true;
    if (*text == '-' || *text == '+')
    {
        positive = *text == '+';
        ++text;
    }
    while (*text)
    {
        if (*text == '.' || is_e(*text))
        {
            break;
        }
        value *= 10.0;
        value += *text - '0';
        ++text;
    }
    if (*text == '.')
    {
        ++text;
        double fraction = 1.0;
        while (*text)
        {
            if (is_e(*text))
            {
                break;
            }
            fraction /= 10.0;
            value += (*text - '0')*fraction;
            ++text;
        }
    }
    if (is_e(*text))
    {
        ++text;
        unsigned int exponent = 0;
        while (*text)
        {
            exponent *= 10U;
            exponent += *text - '0';
            ++text;
        }
        value *= std::pow(10.0, exponent);
    }
    return value;
}

// #TEST#: R175 Rename xull3
// #TEST#: R176 Rename value
int operator""_xull3(unsigned long long int value)
{
    // #TEST#: R177 Rename value
    return static_cast<int>(value);
}

// #TEST#: R179 Rename xd2
// #TEST#: R180 Rename value
double operator""_xd2(long double value)
{
    // #TEST#: R181 Rename value
    return static_cast<double>(value);
}

// #TEST#: R183 Rename xc
// #TEST#: R184 Rename value
char operator""_xc(char value)
{
    // #TEST#: R185 Rename value
    return value;
}

// #TEST#: R187 Rename xc2
// #TEST#: R188 Rename value
wchar_t operator""_xc2(wchar_t value)
{
    // #TEST#: R189 Rename value
    return value;
}

// #TEST#: R191 Rename xc3
// #TEST#: R192 Rename value
char16_t operator""_xc3(char16_t value)
{
    // #TEST#: R193 Rename value
    return value;
}

// #TEST#: R195 Rename xc4
// #TEST#: R196 Rename value
char32_t operator""_xc4(char32_t value)
{
    // #TEST#: R197 Rename value
    return value;
}

// #TEST#: R199 Rename xs
// #TEST#: R200 Rename text
// #TEST#: R201 Rename len
std::string operator""_xs(const char *text, std::size_t len)
{
    // #TEST#: R202 Rename text
    // #TEST#: R203 Rename len
    return std::string(text, len);
}

template <typename T>
std::string narrow(const std::basic_string<T> &wide)
{
    std::string value;
    value.resize(wide.length());
    std::transform(wide.begin(), wide.end(), value.begin(),
        [](T c) { return static_cast<char>(c); });
    return value;
}

// #TEST#: R205 Rename xs2
// #TEST#: R206 Rename text
// #TEST#: R207 Rename len
std::wstring operator""_xs2(const wchar_t *text, std::size_t len)
{
    // #TEST#: R208 Rename text
    // #TEST#: R209 Rename len
    return std::wstring(text, len);
}

// #TEST#: R211 Rename xs3
// #TEST#: R212 Rename text
// #TEST#: R213 Rename len
std::basic_string<char16_t> operator""_xs3(const char16_t *text, std::size_t len)
{
    // #TEST#: R214 Rename text
    // #TEST#: R215 Rename len
    return {text, len};
}

// #TEST#: R217 Rename xs4
// #TEST#: R218 Rename text
// #TEST#: R219 Rename len
std::basic_string<char32_t> operator""_xs4(const char32_t *text, std::size_t len)
{
    // #TEST#: R220 Rename text
    // #TEST#: R221 Rename len
    return {text, len};
}

void f13()
{
    // #TEST#: R168 Rename xull
    require_equal(555ULL, 555_xull);
    // #TEST#: R171 Rename xull2
    require_equal(666ULL, 666_xull2);
    // #TEST#: R174 Rename xd
    require_equal(2.0, 2.0_xd);
    // #TEST#: R178 Rename xull3
    require_equal(-555, -555_xull3);
    // #TEST#: R182 Rename xd2
    require_equal(2.0, 2.0_xd2);
    // #TEST#: R186 Renamve xc
    require_equal('c', 'c'_xc);
    // #TEST#: R190 Rename xc2
    require_equal(L'c', L'c'_xc2);
    // #TEST#: R194 Rename xc3
    require_equal(u'c', u'c'_xc3);
    // #TEST#: R198 Rename xc4
    require_equal(U'c', U'c'_xc4);
    // #TEST#: R204 Rename xs
    require_equal(std::string{"foo"}, "foo"_xs);
    // #TEST#: R210 Rename xs2
    require_equal(std::string{"foo"}, narrow(L"foo"_xs2));
    // #TEST#: R216 Rename xs3
    require_equal(std::string{"foo"}, narrow(u"foo"_xs3));
    // #TEST#: R222 Rename xs4
    require_equal(std::string{"foo"}, narrow(U"foo"_xs4));
}

// #TEST#: R223 Rename Char
template <typename Char>
// #TEST#: R224 Rename String
// #TEST#: R225 Rename Char
using String = std::basic_string<Char>;

void f14()
{
    // #TEST#: R226 Rename String
    String<char> s{"foo"};
    // #TEST#: R227 Rename String
    require_equal(String<char>{"foo"}, s);
}

void f15()
{
    // #TEST#: R228 Rename X
    enum class X : char
    {
        // #TEST#: R229 Rename One
        One,
        Two,
        Three
    };
    enum class Y : int
    {
        // #TEST#: R230 Rename One
        One,
        Two,
        Three
    };
    // #TEST#: R231 Rename X on lhs
    // #TEST#: R232 Rename x
    // #TEST#: R233 Rename X on rhs
    // #TEST#: R234 Rename One
    X x = X::One;
    // #TEST#: R235 Rename One
    Y y = Y::One;
    require_equal(static_cast<int>(x), static_cast<int>(y));
}

void f16()
{
    // #TEST#: R236 Rename j
    constexpr int j = 6;
    struct X
    {
        // #TEST#: R237 Rename x
        int x = 3;
        // #TEST#: R238 Rename y
        // #TEST#: R239 Rename j
        int y = j;
    };
    X v;
    // #TEST#: R240 Rename x
    require_equal(3, v.x);
    // #TEST#: R241 Rename y
    require_equal(j, v.y);
}

// #TEST#: R242 Rename Args
template <typename... Args>
struct Initializer
{
    // #TEST#: R243 Rename Args
    // #TEST#: R244 Rename args constructor argument
    // #TEST#: R245 Rename args initializer
    Initializer(Args... args) : t(args...) {}
    // #TEST#: R246 Rename Args
    std::tuple<Args...> t;
};

void f17()
{
    Initializer<int, float, double> i(10, 20.0f, 30.0);
    require_equal(10, std::get<0>(i.t));
    require_equal(20.0f, std::get<1>(i.t));
    require_equal(30.0, std::get<2>(i.t));
}

// #TEST#: R247 Rename Args
template <typename... Args>
// #TEST#: R248 Rename Args
// #TEST#: R249 Rename args
void f18_aux(std::ostream &stream, Args... args)
{
    // #TEST#: R250 Rename Args
    // #TEST#: R251 Rename args
    int ignored[sizeof...(Args)] = { (stream << args << ' ', 0)... };
}

void f18()
{
    std::ostringstream result;
    f18_aux(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10 20.5 hello, world! "}, result.str());
}

// #TEST#: R252 Rename Args
template <typename... Args>
struct f19_aux
{
    // #TEST#: R253 Rename Args
    template <Args...>
    struct apply
    {
        // #TEST#: R254 Rename Args
        // #TEST#: R255 Rename args
        apply(Args... args) : t(args...) {}

        // #TEST#: R256 Rename Args
        std::tuple<Args...> t;
    };
};

void f19()
{
    f19_aux<int, int, int>::apply<10, 20, 30> x(10, 20, 30);
    require_equal(10, std::get<0>(x.t));
    require_equal(20, std::get<1>(x.t));
    require_equal(30, std::get<2>(x.t));
}

// #TEST#: R257 Rename Bases
template <typename... Bases>
// #TEST#: R258 Rename Bases
struct Mixin : Bases...
{
    // #TEST#: R259 Rename Bases in constructor argument list
    // #TEST#: R260 Rename bases in constructor argument list
    // #TEST#: R261 Rename Bases in initializer list pack expansion
    // #TEST#: R262 Rename bases in initializer list pack expansion
    Mixin(const Bases &...bases) : Bases(bases)...
    {
    }
};

void f20()
{
    struct Int
    {
        Int(int i) : m(i) {}
        int m;
    };
    struct Float
    {
        Float(float f) : m(f) {}
        float m;
    };
    Mixin<Int, std::string, Float> m(10, std::string{"foo"}, 20.f);
    require_equal(10, static_cast<Int &>(m).m);
    require_equal(std::string{"foo"}, static_cast<std::string &>(m));
    require_equal(20.f, static_cast<Float &>(m).m);
}

// #TEST#: R263 Rename Args
template <typename... Args>
// #TEST#: R264 Renem stream
// #TEST#: R265 Rename Args
// #TEST#: R266 Rename args
void f21_aux(std::ostream &stream, Args... args)
{
    // #TEST#: R267 Rename args
    // #TEST#: R268 Rename s
    [&, args...](std::ostream &s)
    {
        // #TEST#: R269 Rename s
        // #TEST#: R270 Rename args
        f10_aux(s, args...);
    // #TEST#: R271 Rename stream
    }(stream);
}

void f21()
{
    std::ostringstream result;
    f21_aux(result, 10, 20.5, "hello world!");
    require_equal(std::string{"10\n" "20.5\n" "hello world!\n"}, result.str());
}

// #TEST#: R272 Renema Exceptions
template <typename... Exceptions>
// #TEST#: R273 Rename Exceptions
void f22_aux() throw (Exceptions...)
{
}

void f22()
{
    f22_aux<std::runtime_error, std::invalid_argument>();
}

// #TEST#: R274 Rename Types
template <typename... Types>
// #TEST#: R275 Rename Types
struct alignas(Types...) Aligned
{
    // #TEST#: R276 Rename Types
    // #TEST#: R277 Rename args in constructor parameter list
    // #TEST#: R278 Rename args in initializer list
    Aligned(Types... args) : t(args...) {}
    // #TEST#: R279 Rename Types
    std::tuple<Types...> t;
};

void f23()
{
    Aligned<int, double, std::string> x(10, 20.5, "hello world!");
    require_equal(10, std::get<0>(x.t));
    require_equal(20.5, std::get<1>(x.t));
    require_equal(std::string{"hello world!"}, std::get<2>(x.t));
}

void f24()
{
    // #TEST#: R280 Rename X
    struct X
    {
        // #TEST#: R281 Rename constructor X
        // #TEST#: R282 Rename delegated constructor X
        X() : X(10) {}
        // #TEST#: R283 Rename constructor X
        // #TEST#: R284 Rename delegated constructor X
        X(int x) : X(x, "hello world!") {}
        // #TEST#: R285 Rename constructor X
        X(int num, const char *text) : x(num), s(text) {}

        int x;
        std::string s;
    };
    // #TEST#: R286 Rename X
    X x;
    require_equal(10, x.x);
    require_equal(std::string{"hello world!"}, x.s);
}

// #TEST#: R287 Rename T
template <typename T, typename U>
// #TEST#: R288 Rename arg in parameter list
// #TEST#: R289 Rename T
// #TEST#: R290 REname arg in decltype expression
auto f25_aux(U arg) -> decltype(T(arg))
{
    // #TEST#: R291 Rename T
    // #TEST#: R292 Rename arg
    return T(arg);
}

void f25()
{
    require_equal(10, f25_aux<int>(10));
    require_equal(20.5, f25_aux<double>(20.5f));
    require_equal(std::string{"hello world!"}, f25_aux<std::string>("hello world!"));
}

void f26()
{
    // #TEST#: R293 Rename x
    int x = 10;
    // #TEST#: R294 Rename x in lambda parameter list
    // #TEST#: R295 Rename x in lambda body
    // #TEST#: R296 Rename x in lambda argument list
    require_equal(100, [](int x){ return x*10; }(x));

    // #TEST#: R297 Rename f
    double f = 20.5;
    // #TEST#: R298 Rename f in lambda capture list
    // #TEST#: R299 Rename x in lambda parameter list
    // #TEST#: R300 Rename x in lambda body
    // #TEST#: R301 Rename f in lambda body
    // #TEST#: R302 Rename x in lambda argument list
    require_equal(205.0, [f](int x){ return x*f; }(x));

    // #TEST#: R303 Rename x in lambda parameter list
    // #TEST#: R304 Rename x in lambda body
    // #TEST#: R305 Rename f in lambda body
    // #TEST#: R306 Rename x in lambda argument list
    require_equal(205.0, [=](int x){ return x*f; }(x));

    // #TEST#: R307 Rename x in lambda capture list
    // #TEST#: R308 Rename x in lambda body
    require_equal(1, [&x]{ return x /= 10; }());
    require_equal(1, x);

    // #TEST#: R309 Rename f in lambda body
    require_equal(205.0, [&]{ return f *= 10.0; }());
    require_equal(205.0, f);

    // #TEST#: R310 Rename l
    // #TEST#: R311 Rename f in lambda body
    const auto l = [&]{ return f /= 10.0; };
    // #TEST#: R312 Rename l
    require_equal(20.5, l());
    require_equal(20.5, f);

    // #TEST#: R313 Rename s
    const std::string s{"hello world!"};
    // #TEST#: R314 Rename s in lambda parameter list
    // #TEST#: R315 Rename nl declaration in lambda body
    // #TEST#: R316 Rename s in lambda body
    // #TEST#: R317 Rename nl in expression in lambda body
    // #TEST#: R318 Rename s in lambda argument list
    require_equal(std::string{"hello world!\n"}, [](const std::string &s){ std::string nl{"\n"}; return s + nl; }(s));

    // #TEST#: R319 Rename E
    enum class E
    {
        one,
        // #TEST#: R320 Rename two
        two,
        three
    };
    // #TEST#: R321 Rename E in declaration
    // #TEST#: R322 Rename E in initialization expression
    E e = E::one;
    // #TEST#: R323 Rename E in first argument to require_equal
    // #TEST#: R324 Rename E in lambda return type
    // #TEST#: R325 Rename E in lambda body
    // #TEST#: R326 Rename two in lambda body
    require_equal(static_cast<int>(E::two), static_cast<int>([]() -> E { return E::two; }()));
}

void f27()
{
    // #TEST#: R327 Rename v
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostringstream result;
    // #TEST#: R328 Rename i
    // #TEST#: R329 Rename v
    for (int i : v)
    {
        // #TEST#: R330 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());

    // #TEST#: R331 Rename i
    // #TEST#: R332 Rename v
    for (int &i : v)
    {
        // #TEST#: R333 Rename i
        i *= 10;
    }
    result.str("");
    std::for_each(v.begin(), v.end(), [&result](int i) { result << i << '\n'; });
    require_equal(std::string{"10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n"}, result.str());

    result.str("");
    // #TEST#: R334 Rename i
    // #TEST#: R335 Rename v
    for (auto i : v)
    {
        // #TEST#: R336 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n"}, result.str());

    // #TEST#: R337 Rename i
    // #TEST#: R338 Rename v
    for (auto &i : v)
    {
        // #TEST#: R339 Rename i
        i /= 10;
    }
    result.str("");
    std::for_each(v.begin(), v.end(), [&result](int i) { result << i << '\n'; });
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());

    result.str("");
    // #TEST#: R340 Rename i
    // #TEST#: R341 Rename v
    for (const auto i : v)
    {
        // #TEST#: R342 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());
}

void f28()
{
    // #TEST#: R343 Rename x
    auto x = 3;
    // #TEST#: R344 Rename x
    require_equal(3, x);
    // #TEST#: R345 Rename y
    // #TEST#: R346 Rename x
    auto y = 3*x;
    // #TEST#: R347 Rename y
    require_equal(9, y);
    // #TEST#: R348 Rename x
    x *= 3;
    // #TEST#: R349 Rename z
    // #TEST#: R350 Rename x
    const auto z = x;
    // #TEST#: R351 Rename z
    require_equal(9, z);
}

void f29()
{
    // #TEST#: R352 Rename x
    int x = 3;
    // #TEST#: R353 Rename x in decltype argument
    // #TEST#: R354 Rename y
    // #TEST#: R355 Rename x in initializing expression
    decltype(x) y = x;
    // #TEST#: R356 Rename y
    require_equal(3, y);
    // #TEST#: R357 Rename y
    // #TEST#: R358 Rename x
    require_equal(true, std::is_same<decltype(y), decltype(x)>::value);
    // #TEST#: R359 Rename first x in expression
    // #TEST#: R360 Rename first y in expression
    // #TEST#: R361 Rename second x in expression
    // #TEST#: R362 Rename second y in expression
    // #TEST#: R363 Rename z
    decltype(x + y - x - y) z = 10;
    // #TEST#: R364 Rename z
    require_equal(10, z);
}

void f30()
{
    // #TEST#: R365 Rename x
    int x = 10;
    // #TEST#: R366 Rename y
    int y = 20;
    // #TEST#: R367 REname z
    int z = 30;
    std::ostringstream result;
    // #TEST#: R368 Rename x
    // #TEST#: R369 Rename y
    // #TEST#: R370 Rename z
    for (int i : { 1, x, y, z, 4 })
    {
        result << i << '\n';
    }
    require_equal(std::string{"1\n10\n20\n30\n4\n"}, result.str());
}

void f31()
{
    // #TEST#: R371 Rename Extern
    using RenameCpp11::Extern;
    // #TEST#: R372 Rename Extern
    Extern<int> x(10);
    require_equal(10, x.t);
    // #TEST#: R373 Rename Extern
    Extern<std::string> y("hello world!");
    require_equal(std::string{"hello world!"}, y.t);
}

void f32()
{
    // #TEST#: R382 Rename Integer
    using Integer = int;
    // #TEST#: R383 Rename Integer
    Integer x = 10;
    require_equal(10, x);
    // #TEST#: R384 Rename Integral
    // #TEST#: R385 Rename Integer
    using Integral = Integer;
    // #TEST#: R386 Rename Integral
    Integral y = 10;
    require_equal(10, y);
}

// #TEST#: R387 Rename ii
constexpr int ii = 15;

void f33()
{
    // #TEST#: R388 Rename i
    constexpr int i = 6;
    // #TEST#: R389 Rename x
    // #TEST#: R390 Rename i
    int constexpr x = 2*i;
    // #TEST#: R391 Rename x
    require_equal(12, x);
    // #TEST#: R392 Rename ii
    require_equal(15, ii);
}

// #TEST#: R393 Rename f34_aux
// #TEST#: R394 Rename j
constexpr int f34_aux(int j)
{
    return ii + j;
}

// #TEST#: R395 Rename f34_aux
static_assert(f34_aux(3) == 18, "f34_aux(3) == 18");

void f34()
{
    // #TEST#: R396 Rename f34_aux
    constexpr int x = f34_aux(3);
    require_equal(18, x);
    int j = 15;
    // #TEST#: R397 Rename f34_aux
    require_equal(30, f34_aux(j));
    j += 15;
    require_equal(30, j);
}

struct X35
{
    // #TEST#: R398 Rename size
    constexpr std::size_t size() const { return sizeof(X35); }

    // #TEST#: R399 Rename sz
    static constexpr int sz = 4;
};

void f35()
{
    X35 x;
    // #TEST#: R400 Rename size member function
    constexpr std::size_t size = x.size();
    require_equal(std::size_t{1}, size);
    // #TEST#: R401 Rename sz static member
    constexpr int s = X35::sz;
    require_equal(4, s);
}

inline namespace Inline36
{

// #TEST#: R402 Rename x36
int x36 = 10;
// #TEST#: R403 Rename d36
double d36 = 20.5;
// #TEST#: R404 Rename s36
std::string s36()
{
    return "hello world!";
}

}

void f36()
{
    // #TEST#: R405 Renaem x36
    require_equal(10, x36);
    // #TEST#: R406 Rename d36
    require_equal(20.5, d36);
    // #TEST#: R407 Rename s36
    require_equal(std::string{"hello world!"}, s36());
}

void f37()
{
    // #TEST#: R408 Rename s1
    const char *s1{u8"foo"};
    // #TEST#: R409 Rename s1
    require_equal(std::string{"foo"}, std::string{s1});

    // #TEST#: R410 Rename s2
    const char16_t *s2{u"foo"};
    // #TEST#: R411 Rename s2
    require_equal(std::string{"foo"}, narrow(std::basic_string<char16_t>{s2}));

    // #TEST#: R412 Rename s3
    const char32_t *s3{U"foo"};
    // #TEST#: R413 Rename s3
    require_equal(std::string{"foo"}, narrow(std::basic_string<char32_t>{s3}));

    // #TEST#: R414 Rename s4
    const char *s4{R"(I say, "Hello, World!")"};
    // #TEST#: R415 Rename s4
    require_equal(std::string{R"(I say, "Hello, World!")"}, std::string{s4});
}

// #TEST#: R429 Rename F38_AUX
// #TEST#: R430 Rename stream_ in macro argument list
// #TEST#: R431 Rename stream_ in macro expansion text
// #TEST#: R432 Rename not available for __VA_ARGS__ in macro expansion text
#define F38_AUX(stream_, ...) f10_aux(stream_, __VA_ARGS__)

void f38()
{
    std::ostringstream result;
    // #TEST#: R433 Rename F38_AUX
    F38_AUX(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10\n20.5\nhello, world!\n"}, result.str());
}

// #TEST#: R434 Rename F38_AUX
#undef F38_AUX

// #TEST#: R435 Rename F39_AUX
#define F39_AUX(...) f10_aux(__VA_ARGS__)

void f39()
{
    std::ostringstream result;
    // #TEST#: R436 Rename F39_AUX
    F39_AUX(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10\n20.5\nhello, world!\n"}, result.str());
}

// #TEST#: R437 Rename F39_AUX
#undef F39_AUX

// #TEST#: R438 Rename X40
struct X40
{
    // #TEST#: R439 Rename x
    static int x;
};

// #TEST#: R440 Rename X40
// #TEST#: R441 Rename x
int X40::x = 0;

void f40()
{
    // #TEST#: R442 Rename X40
    // #TEST#: R443 Rename x
    require_equal(1, []{ return X40::x + 1; }());
}

// #TEST#: R444 Rename F41_AUX
#define F41_AUX 15

void f41()
{
    // #TEST#: R445 Rename F41_AUX
    require_equal(15, []{ return F41_AUX; }());
}

// #TEST#: R446 Rename F41_AUX
#undef F41_AUX

// #TEST#: R447 Rename f42_aux
void f42_aux(std::ostream &stream, int x)
{
    f10_aux(stream, x);
}

void f42()
{
    std::ostringstream result;
    // #TEST#: R448 Rename f42_aux
    [](std::ostream &s, int x) { f42_aux(s, x); }(result, 10);
    require_equal(std::string{"10\n"}, result.str());
}

template <typename T>
// #TEST#: R449 Rename f43_aux
void f43_aux(std::ostream &stream, T value)
{
    stream << value << '\n';
}

void f43()
{
    std::ostringstream result;
    // #TEST#: R450 Rename f43_aux
    [&result](int value) { f43_aux(result, value); }(10);
    require_equal(std::string{"10\n"}, result.str());
}

void f44()
{
    // #TEST#: R451 Rename X
    class X
    {
    public:
        X(const std::string &s) : m_s(s + " lvalue") {}
        // #TEST#: R452 Rename parameter s
        // #TEST#: R453 Rename parameter s in initializer list
        X(std::string &&s) : m_s(s + " rvalue") {}

        // #TEST#: R454 Rename method s
        const std::string &s() const & { return m_s; }
        // #TEST#: R455 Rename method s
        std::string s() const && { return m_s + " rvalue"; }

        // #TEST#: R456 Rename method set
        void set(const std::string &s) { m_s = s + " lvalue"; }
        // #TEST#: R457 Rename method set
        // #TEST#: R458 Rename parameter s
        // #TEST#: R459 Rename parameter s in method body
        void set(std::string &&s) { m_s = s + " rvalue"; }

    private:
        std::string m_s;
    };
    X x(std::string{"foo"});
    // #TEST#: R460 Rename method s
    require_equal(std::string{"foo rvalue"}, x.s());

    const std::string ss{"meh"};
    X xx(ss);
    require_equal(std::string{"meh lvalue"}, xx.s());

    // #TEST#: R461 Rename method set
    x.set(std::string{"bar"});
    require_equal(std::string{"bar rvalue"}, x.s());

    std::string s2{"meh"};
    // #TEST#: R462 Rename method set
    x.set(s2);
    require_equal(std::string{"meh lvalue"}, x.s());

    // #TEST#: R463 Rename method s
    require_equal(std::string{"meh rvalue rvalue"}, X{std::string{"meh"}}.s());

    // #TEST#: R464 Rename variable x2
    std::string &&x2 = std::string{"hello"} + ' ' + std::string{"world!"};
    // #TEST#: R465 Rename variable x2
    require_equal(std::string{"hello world!"}, x2);
    // #TEST#: R466 Rename variable x2
    x2 += "  goodbye!";
    // #TEST#: R467 Rename variable x2
    require_equal(std::string{"hello world!  goodbye!"}, x2);
}

template <typename T>
// #TEST#: R468 Rename function g45_aux
// #TEST#: R469 Rename parameter x
T g45_aux(T &&x)
{
    // #TEST#: R470 Rename parameter x
    T y(x);
    return y;
}

template <typename T>
// #TEST#: R471 Rename function f45_aux
// #TEST#: R472 Rename parameter x
T f45_aux(T &&x)
{
    // #TEST#: R473 Rename function g45_aux
    // #TEST#: R474 Rename parameter x
    return g45_aux(std::forward<T>(x));
}

void f45()
{
    struct X
    {
        X() {}
        X(const std::string &s) : s(s) {}
        X(std::string &&s) noexcept : s(std::move(s)), c(false) {}
        X(const X &rhs) : s(rhs.s) {}
        X(X &&rhs) noexcept : s(std::move(rhs.s)), c(false) {}

        std::string s;
        bool c = true;
    };
    X x1;
    x1.s = "foo";
    REQUIRE_EQUAL(std::string{"foo"}, x1.s);
    REQUIRE_EQUAL(true, x1.c);
    X x2(f45_aux(X("meh")));
    REQUIRE_EQUAL(std::string{"meh"}, x2.s);
}

}

namespace RenameCpp11
{

// #TEST#: R374 Rename Extern
template struct Extern<int>;
// #TEST#: R375 Rename Extern
template struct Extern<std::string>;

}

void TestRenameCpp11()
{
    f1();
    f2();
    f3<int>();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
    f10();
    f11();
    f12();
    f13();
    f14();
    f15();
    f16();
    f17();
    f18();
    f19();
    f20();
    f21();
    f22();
    f23();
    f24();
    f25();
    f26();
    f27();
    f28();
    f29();
    f30();
    f31();
    f32();
    f33();
    f34();
    f35();
    f36();
    f37();
    f38();
    f39();
    f40();
    f41();
    f42();
    f43();
    f44();
    f45();
}
