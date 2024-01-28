#include "RenameCpp11.h"

#include "Require.h"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

namespace
{
// #TEST#: R247 Rename flag used in static_assert
constexpr bool flag = true;
// #TEST#: R248 Rename flag used in static_assert
constexpr bool flag2 = false;
// #TEST#: R249 Rename flag used in noexcept specification
constexpr bool flag3 = true;
// #TEST#: R250 Rename flag used in noexcept specification
constexpr bool flag4 = false;

// #TEST#: R251 Rename flag in static_assert
static_assert(flag, "Flag is false");
// #TEST#: R252 Rename flag2 in static_assert
static_assert(!flag2, "Flag2 is true");

// #TEST#: R253 Rename flag3 in noexcept specifier
void f1() noexcept(flag3)
{
}

// #TEST#: R254 Rename flag4 in noexcept specifier
void f2() noexcept(!flag4)
{
}

// #TEST#: R255 Rename T used in noexcept expression
template <typename T>
// #TEST#: R256 Rename T in noexcept expression
void f3() noexcept(noexcept(T()))
{
    // #TEST#: R257 Rename T used in noexcept expression
    T x = T();
}

void f4()
{
    // #TEST#: R258 Rename c16
    char16_t c16 = u'x';
    // #TEST#: R259 Rename c32
    char32_t c32 = U'x';

    std::ostringstream s;
    // #TEST#: R260 Rename c16
    s << static_cast<int>(c16);
    // #TEST#: R261 Rename c32
    s << static_cast<int>(c32);
}

void f5()
{
    // #TEST#: R262 Rename X used in alignof operator expression
    struct alignas(4) X
    {
        int x;
        char b;
    };
    // #TEST#: R263 Rename X
    require_equal(std::size_t{4}, alignof(X));
}

void f6()
{
    // #TEST#: R264 Rename X used in alignas specifier
    struct alignas(int) X
    {
        float y;
        char b;
    };
    // #TEST#: R265 Rename X in alignas specifier
    struct alignas(X) Y
    {
        float y;
        char b;
    };
    // #TEST#: R266 Rename X used in alignas specifier
    require_equal(alignof(int), alignof(X));
    // #TEST#: R267 Rename X used in alignas specifier
    require_equal(alignof(X), alignof(Y));
}

void f7()
{
    // #TEST#: R268 Rename X
    struct X
    {
        // #TEST#: R269 Rename X via default c'tor
        X() = default;
        // #TEST#: R270 Rename X via default copy c'tor
        // #TEST#: R271 Rename X via default copy c'tor argument
        X(const X &rhs) = default;
        // #TEST#: R272 Rename X via default move c'tor
        // #TEST#: R273 Rename X via default move c'tor argument
        X(X &&rhs) = default;
        // #TEST#: R274 Rename X via default d'tor
        ~X() = default;
        // #TEST#: R275 Rename X via default copy assignment return type
        // #TEST#: R276 Rename X via default copy assignment argument
        X &operator=(const X &rhs) = default;
        // #TEST#: R277 Rename X via default move assignment return type
        // #TEST#: R278 Rename X via default move assignment argument
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
    // #TEST#: R279 Rename X
    struct X
    {
        // #TEST#: R280 Rename X via deleted c'tor
        X() = delete;
        // #TEST#: R281 Rename X via deleted copy c'tor
        // #TEST#: R282 Rename X via deleted copy c'tor argument
        X(const X &rhs) = delete;
        // #TEST#: R283 Rename X via deleted move c'tor
        // #TEST#: R284 Rename X via deleted move c'tor argument
        X(X &&rhs) = delete;
        // #TEST#: R285 Rename X via deleted d'tor
        ~X() = delete;
        // #TEST#: R286 Rename X via deleted copy assignment return type
        // #TEST#: R287 Rename X via deleted copy assignment argument
        X &operator=(const X &rhs) = delete;
        // #TEST#: R288 Rename X via deleted move assignment return type
        // #TEST#: R289 Rename X via deleted move assignment argument
        X &operator=(X &&rhs) = delete;

        int x = 1;
        int y = 2;
        std::string s = "foo";
    };
    // #TEST#: R290 Rename X
    X *x = nullptr;
}

void f9()
{
    // #TEST#: R291 Rename x
    thread_local int x = 0;
    // #TEST#: R292 Rename use of x
    require_equal(0, x);
}

template <typename T>
void f10_aux(std::ostream &stream, T head)
{
    stream << head << '\n';
}

// #TEST#: R293 Rename T
// #TEST#: R294 Rename Args
template <typename T, typename... Args>
// #TEST#: R295 Rename T
// #TEST#: R296 Rename head
// #TEST#: R297 Rename Args
// #TEST#: R298 Rename tail
void f10_aux(std::ostream &stream, T head, Args... tail)
{
    // #TEST#: R299 Rename head
    stream << head << '\n';
    // #TEST#: R300 Rename tail
    // #TEST#: R301 Rename Args
    if (sizeof...(tail) > 0 || sizeof...(Args) > 0)
    {
        // #TEST#: R302 Rename tail
        f10_aux(stream, tail...);
    }
}

void f10()
{
    std::ostringstream result;
    f10_aux(result, 10, 20.5, "hello world!");
    require_equal(std::string{"10\n"
                              "20.5\n"
                              "hello world!\n"},
                  result.str());
}

// #TEST#: R303 Rename Args
template <typename... Args>
// #TEST#: R304 Rename X
class X
{
public:
    // #TEST#: R305 Rename X
    // #TEST#: R306 Rename Args
    // #TEST#: R307 Rename args
    X(Args... args)
    {
        std::ostringstream result;
        // #TEST#: R308 Rename args
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
    // #TEST#: R309 Rename X
    X<int, double, std::string> x{10, 20.5, "hello world!"};
    require_equal(std::string{"10\n"
                              "20.5\n"
                              "hello world!\n"},
                  x.str());
}

// #TEST#: R310 Rename Types
template <typename... Types>
// #TEST#: R311 Rename Types
using Tuple = std::tuple<Types...>;

void f12()
{
    Tuple<int, double, std::string> t{10, 20.0, "hello world!"};
    require_equal(10, std::get<0>(t));
    require_equal(20.0, std::get<1>(t));
    require_equal(std::string{"hello world!"}, std::get<2>(t));
}

// #TEST#: R312 Rename text
template <char... text>
// #TEST#: R313 Rename xull
unsigned long long operator""_xull()
{
    unsigned long long value = 0;
    // #TEST#: R314 Rename text
    std::initializer_list<char> chars{text...};
    for (char c : chars)
    {
        value *= 10ULL;
        value += c - '0';
    }
    return value;
}

// #TEST#: R315 Rename xull2
// #TEST#: R316 Rename text
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

// #TEST#: R317 Rename xd
// #TEST#: R318 Rename text
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
            value += (*text - '0') * fraction;
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

// #TEST#: R319 Rename xull3
// #TEST#: R320 Rename value
int operator""_xull3(unsigned long long int value)
{
    // #TEST#: R321 Rename value
    return static_cast<int>(value);
}

// #TEST#: R322 Rename xd2
// #TEST#: R323 Rename value
double operator""_xd2(long double value)
{
    // #TEST#: R324 Rename value
    return static_cast<double>(value);
}

// #TEST#: R325 Rename xc
// #TEST#: R326 Rename value
char operator""_xc(char value)
{
    // #TEST#: R327 Rename value
    return value;
}

// #TEST#: R328 Rename xc2
// #TEST#: R329 Rename value
wchar_t operator""_xc2(wchar_t value)
{
    // #TEST#: R330 Rename value
    return value;
}

// #TEST#: R331 Rename xc3
// #TEST#: R332 Rename value
char16_t operator""_xc3(char16_t value)
{
    // #TEST#: R333 Rename value
    return value;
}

// #TEST#: R334 Rename xc4
// #TEST#: R335 Rename value
char32_t operator""_xc4(char32_t value)
{
    // #TEST#: R336 Rename value
    return value;
}

// #TEST#: R337 Rename xs
// #TEST#: R338 Rename text
// #TEST#: R339 Rename len
std::string operator""_xs(const char *text, std::size_t len)
{
    // #TEST#: R340 Rename text
    // #TEST#: R341 Rename len
    return std::string(text, len);
}

template <typename T>
std::string narrow(const std::basic_string<T> &wide)
{
    std::string value;
    value.resize(wide.length());
    std::transform(wide.begin(), wide.end(), value.begin(), [](T c) { return static_cast<char>(c); });
    return value;
}

// #TEST#: R342 Rename xs2
// #TEST#: R343 Rename text
// #TEST#: R344 Rename len
std::wstring operator""_xs2(const wchar_t *text, std::size_t len)
{
    // #TEST#: R345 Rename text
    // #TEST#: R346 Rename len
    return std::wstring(text, len);
}

// #TEST#: R347 Rename xs3
// #TEST#: R348 Rename text
// #TEST#: R349 Rename len
std::basic_string<char16_t> operator""_xs3(const char16_t *text, std::size_t len)
{
    // #TEST#: R350 Rename text
    // #TEST#: R351 Rename len
    return {text, len};
}

// #TEST#: R352 Rename xs4
// #TEST#: R353 Rename text
// #TEST#: R354 Rename len
std::basic_string<char32_t> operator""_xs4(const char32_t *text, std::size_t len)
{
    // #TEST#: R355 Rename text
    // #TEST#: R356 Rename len
    return {text, len};
}

void f13()
{
    // #TEST#: R357 Rename xull
    require_equal(555ULL, 555_xull);
    // #TEST#: R358 Rename xull2
    require_equal(666ULL, 666_xull2);
    // #TEST#: R359 Rename xd
    require_equal(2.0, 2.0_xd);
    // #TEST#: R360 Rename xull3
    require_equal(-555, -555_xull3);
    // #TEST#: R361 Rename xd2
    require_equal(2.0, 2.0_xd2);
    // #TEST#: R362 Rename xc
    require_equal('c', 'c'_xc);
    // #TEST#: R363 Rename xc2
    require_equal(L'c', L'c'_xc2);
    // #TEST#: R364 Rename xc3
    require_equal(u'c', u'c'_xc3);
    // #TEST#: R365 Rename xc4
    require_equal(U'c', U'c'_xc4);
    // #TEST#: R366 Rename xs
    require_equal(std::string{"foo"}, "foo"_xs);
    // #TEST#: R367 Rename xs2
    require_equal(std::string{"foo"}, narrow(L"foo"_xs2));
    // #TEST#: R368 Rename xs3
    require_equal(std::string{"foo"}, narrow(u"foo"_xs3));
    // #TEST#: R369 Rename xs4
    require_equal(std::string{"foo"}, narrow(U"foo"_xs4));
}

// #TEST#: R370 Rename Char
template <typename Char>
// #TEST#: R371 Rename String
// #TEST#: R372 Rename Char
using String = std::basic_string<Char>;

void f14()
{
    // #TEST#: R373 Rename String
    String<char> s{"foo"};
    // #TEST#: R374 Rename String
    require_equal(String<char>{"foo"}, s);
}

void f15()
{
    // #TEST#: R375 Rename X
    enum class X : char
    {
        // #TEST#: R376 Rename One
        One,
        Two,
        Three
    };
    enum class Y : int
    {
        // #TEST#: R377 Rename One
        One,
        Two,
        Three
    };
    // #TEST#: R378 Rename X on lhs
    // #TEST#: R379 Rename x
    // #TEST#: R380 Rename X on rhs
    // #TEST#: R381 Rename One
    X x = X::One;
    // #TEST#: R382 Rename One
    Y y = Y::One;
    require_equal(static_cast<int>(x), static_cast<int>(y));
}

void f16()
{
    // #TEST#: R383 Rename j
    constexpr int j = 6;
    struct X
    {
        // #TEST#: R384 Rename x
        int x = 3;
        // #TEST#: R385 Rename y
        // #TEST#: R386 Rename j
        int y = j;
    };
    X v;
    // #TEST#: R387 Rename x
    require_equal(3, v.x);
    // #TEST#: R388 Rename y
    require_equal(j, v.y);
}

// #TEST#: R389 Rename Args
template <typename... Args>
struct Initializer
{
    // #TEST#: R390 Rename Args
    // #TEST#: R391 Rename args constructor argument
    // #TEST#: R392 Rename args initializer
    Initializer(Args... args) : t(args...)
    {
    }
    // #TEST#: R393 Rename Args
    std::tuple<Args...> t;
};

void f17()
{
    Initializer<int, float, double> i(10, 20.0f, 30.0);
    require_equal(10, std::get<0>(i.t));
    require_equal(20.0f, std::get<1>(i.t));
    require_equal(30.0, std::get<2>(i.t));
}

// #TEST#: R394 Rename Args
template <typename... Args>
// #TEST#: R395 Rename Args
// #TEST#: R396 Rename args
void f18_aux(std::ostream &stream, Args... args)
{
    // #TEST#: R397 Rename Args
    // #TEST#: R398 Rename args
    int ignored[sizeof...(Args)] = {(stream << args << ' ', 0)...};
}

void f18()
{
    std::ostringstream result;
    f18_aux(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10 20.5 hello, world! "}, result.str());
}

// #TEST#: R399 Rename Args
template <typename... Args>
struct f19_aux
{
    // #TEST#: R400 Rename Args
    template <Args...>
    struct apply
    {
        // #TEST#: R401 Rename Args
        // #TEST#: R402 Rename args
        apply(Args... args) : t(args...)
        {
        }

        // #TEST#: R403 Rename Args
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

// #TEST#: R404 Rename Bases
template <typename... Bases>
// #TEST#: R405 Rename Bases
struct Mixin : Bases...
{
    // #TEST#: R406 Rename Bases in constructor argument list
    // #TEST#: R407 Rename bases in constructor argument list
    // #TEST#: R408 Rename Bases in initializer list pack expansion
    // #TEST#: R409 Rename bases in initializer list pack expansion
    Mixin(const Bases &...bases) : Bases(bases)...
    {
    }
};

void f20()
{
    struct Int
    {
        Int(int i) : m(i)
        {
        }
        int m;
    };
    struct Float
    {
        Float(float f) : m(f)
        {
        }
        float m;
    };
    Mixin<Int, std::string, Float> m(10, std::string{"foo"}, 20.f);
    require_equal(10, static_cast<Int &>(m).m);
    require_equal(std::string{"foo"}, static_cast<std::string &>(m));
    require_equal(20.f, static_cast<Float &>(m).m);
}

// #TEST#: R410 Rename Args
template <typename... Args>
// #TEST#: R411 Rename stream
// #TEST#: R412 Rename Args
// #TEST#: R413 Rename args
void f21_aux(std::ostream &stream, Args... args)
{
    // #TEST#: R414 Rename args
    // #TEST#: R415 Rename s
    [&, args...](std::ostream &s)
    {
        // #TEST#: R416 Rename s
        // #TEST#: R417 Rename args
        f10_aux(s, args...);
        // #TEST#: R418 Rename stream
    }(stream);
}

void f21()
{
    std::ostringstream result;
    f21_aux(result, 10, 20.5, "hello world!");
    require_equal(std::string{"10\n"
                              "20.5\n"
                              "hello world!\n"},
                  result.str());
}

// #TEST#: R419 Rename Exceptions
template <typename... Exceptions>
// #TEST#: R420 Rename Exceptions
void f22_aux() throw(Exceptions...)
{
}

void f22()
{
    f22_aux<std::runtime_error, std::invalid_argument>();
}

// #TEST#: R421 Rename Types
template <typename... Types>
// #TEST#: R422 Rename Types
struct alignas(Types...) Aligned
{
    // #TEST#: R423 Rename Types
    // #TEST#: R424 Rename args in constructor parameter list
    // #TEST#: R425 Rename args in initializer list
    Aligned(Types... args) : t(args...)
    {
    }
    // #TEST#: R426 Rename Types
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
    // #TEST#: R427 Rename X
    struct X
    {
        // #TEST#: R428 Rename constructor X
        // #TEST#: R429 Rename delegated constructor X
        X() : X(10)
        {
        }
        // #TEST#: R430 Rename constructor X
        // #TEST#: R431 Rename delegated constructor X
        X(int x) : X(x, "hello world!")
        {
        }
        // #TEST#: R432 Rename constructor X
        X(int num, const char *text) : x(num), s(text)
        {
        }

        int x;
        std::string s;
    };
    // #TEST#: R433 Rename X
    X x;
    require_equal(10, x.x);
    require_equal(std::string{"hello world!"}, x.s);
}

// #TEST#: R434 Rename T
template <typename T, typename U>
// #TEST#: R435 Rename arg in parameter list
// #TEST#: R436 Rename T
// #TEST#: R437 Rename arg in decltype expression
auto f25_aux(U arg) -> decltype(T(arg))
{
    // #TEST#: R438 Rename T
    // #TEST#: R439 Rename arg
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
    // #TEST#: R440 Rename x
    int x = 10;
    // #TEST#: R441 Rename x in lambda parameter list
    // #TEST#: R442 Rename x in lambda body
    // #TEST#: R443 Rename x in lambda argument list
    require_equal(100, [](int x) { return x * 10; }(x));

    // #TEST#: R444 Rename f
    double f = 20.5;
    // #TEST#: R445 Rename f in lambda capture list
    // #TEST#: R446 Rename x in lambda parameter list
    // #TEST#: R447 Rename x in lambda body
    // #TEST#: R448 Rename f in lambda body
    // #TEST#: R449 Rename x in lambda argument list
    require_equal(205.0, [f](int x) { return x * f; }(x));

    // #TEST#: R450 Rename x in lambda parameter list
    // #TEST#: R451 Rename x in lambda body
    // #TEST#: R452 Rename f in lambda body
    // #TEST#: R453 Rename x in lambda argument list
    require_equal(205.0, [=](int x) { return x * f; }(x));

    // #TEST#: R454 Rename x in lambda capture list
    // #TEST#: R455 Rename x in lambda body
    require_equal(1, [&x] { return x /= 10; }());
    require_equal(1, x);

    // #TEST#: R456 Rename f in lambda body
    require_equal(205.0, [&] { return f *= 10.0; }());
    require_equal(205.0, f);

    // #TEST#: R457 Rename l
    // #TEST#: R458 Rename f in lambda body
    const auto l = [&] { return f /= 10.0; };
    // #TEST#: R459 Rename l
    require_equal(20.5, l());
    require_equal(20.5, f);

    // #TEST#: R460 Rename s
    const std::string s{"hello world!"};
    // #TEST#: R461 Rename s in lambda parameter list
    // #TEST#: R462 Rename nl declaration in lambda body
    // #TEST#: R463 Rename s in lambda body
    // #TEST#: R464 Rename nl in expression in lambda body
    // #TEST#: R465 Rename s in lambda argument list
    require_equal(std::string{"hello world!\n"},
                  [](const std::string &s)
                  {
                      std::string nl{"\n"};
                      return s + nl;
                  }(s));

    // #TEST#: R466 Rename E
    enum class E
    {
        one,
        // #TEST#: R467 Rename two
        two,
        three
    };
    // #TEST#: R468 Rename E in declaration
    // #TEST#: R469 Rename E in initialization expression
    E e = E::one;
    // #TEST#: R470 Rename E in first argument to require_equal
    // #TEST#: R471 Rename E in lambda return type
    // #TEST#: R472 Rename E in lambda body
    // #TEST#: R473 Rename two in lambda body
    require_equal(static_cast<int>(E::two), static_cast<int>([]() -> E { return E::two; }()));
}

void f27()
{
    // #TEST#: R474 Rename v
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostringstream result;
    // #TEST#: R475 Rename i
    // #TEST#: R476 Rename v
    for (int i : v)
    {
        // #TEST#: R477 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());

    // #TEST#: R478 Rename i
    // #TEST#: R479 Rename v
    for (int &i : v)
    {
        // #TEST#: R480 Rename i
        i *= 10;
    }
    result.str("");
    std::for_each(v.begin(), v.end(), [&result](int i) { result << i << '\n'; });
    require_equal(std::string{"10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n"}, result.str());

    result.str("");
    // #TEST#: R481 Rename i
    // #TEST#: R482 Rename v
    for (auto i : v)
    {
        // #TEST#: R483 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n"}, result.str());

    // #TEST#: R484 Rename i
    // #TEST#: R485 Rename v
    for (auto &i : v)
    {
        // #TEST#: R486 Rename i
        i /= 10;
    }
    result.str("");
    std::for_each(v.begin(), v.end(), [&result](int i) { result << i << '\n'; });
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());

    result.str("");
    // #TEST#: R487 Rename i
    // #TEST#: R488 Rename v
    for (const auto i : v)
    {
        // #TEST#: R489 Rename i
        result << i << '\n';
    }
    require_equal(std::string{"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"}, result.str());
}

void f28()
{
    // #TEST#: R490 Rename x
    auto x = 3;
    // #TEST#: R491 Rename x
    require_equal(3, x);
    // #TEST#: R492 Rename y
    // #TEST#: R493 Rename x
    auto y = 3 * x;
    // #TEST#: R494 Rename y
    require_equal(9, y);
    // #TEST#: R495 Rename x
    x *= 3;
    // #TEST#: R496 Rename z
    // #TEST#: R497 Rename x
    const auto z = x;
    // #TEST#: R498 Rename z
    require_equal(9, z);
}

void f29()
{
    // #TEST#: R499 Rename x
    int x = 3;
    // #TEST#: R500 Rename x in decltype argument
    // #TEST#: R501 Rename y
    // #TEST#: R502 Rename x in initializing expression
    decltype(x) y = x;
    // #TEST#: R503 Rename y
    require_equal(3, y);
    // #TEST#: R504 Rename y
    // #TEST#: R505 Rename x
    require_equal(true, std::is_same<decltype(y), decltype(x)>::value);
    // #TEST#: R506 Rename first x in expression
    // #TEST#: R507 Rename first y in expression
    // #TEST#: R508 Rename second x in expression
    // #TEST#: R509 Rename second y in expression
    // #TEST#: R510 Rename z
    decltype(x + y - x - y) z = 10;
    // #TEST#: R511 Rename z
    require_equal(10, z);
}

void f30()
{
    // #TEST#: R512 Rename x
    int x = 10;
    // #TEST#: R513 Rename y
    int y = 20;
    // #TEST#: R514 REname z
    int z = 30;
    std::ostringstream result;
    // #TEST#: R515 Rename x
    // #TEST#: R516 Rename y
    // #TEST#: R517 Rename z
    for (int i : {1, x, y, z, 4})
    {
        result << i << '\n';
    }
    require_equal(std::string{"1\n10\n20\n30\n4\n"}, result.str());
}

void f31()
{
    // #TEST#: R518 Rename Extern
    using RenameCpp11::Extern;
    // #TEST#: R519 Rename Extern
    Extern<int> x(10);
    require_equal(10, x.t);
    // #TEST#: R520 Rename Extern
    Extern<std::string> y("hello world!");
    require_equal(std::string{"hello world!"}, y.t);
}

void f32()
{
    // #TEST#: R521 Rename Integer
    using Integer = int;
    // #TEST#: R522 Rename Integer
    Integer x = 10;
    require_equal(10, x);
    // #TEST#: R523 Rename Integral
    // #TEST#: R524 Rename Integer
    using Integral = Integer;
    // #TEST#: R525 Rename Integral
    Integral y = 10;
    require_equal(10, y);
}

// #TEST#: R526 Rename ii
constexpr int ii = 15;

void f33()
{
    // #TEST#: R527 Rename i
    constexpr int i = 6;
    // #TEST#: R528 Rename x
    // #TEST#: R529 Rename i
    int constexpr x = 2 * i;
    // #TEST#: R530 Rename x
    require_equal(12, x);
    // #TEST#: R531 Rename ii
    require_equal(15, ii);
}

// #TEST#: R532 Rename f34_aux
// #TEST#: R533 Rename j
constexpr int f34_aux(int j)
{
    return ii + j;
}

// #TEST#: R534 Rename f34_aux
static_assert(f34_aux(3) == 18, "f34_aux(3) == 18");

void f34()
{
    // #TEST#: R535 Rename f34_aux
    constexpr int x = f34_aux(3);
    require_equal(18, x);
    int j = 15;
    // #TEST#: R536 Rename f34_aux
    require_equal(30, f34_aux(j));
    j += 15;
    require_equal(30, j);
}

struct X35
{
    // #TEST#: R537 Rename size
    constexpr std::size_t size() const
    {
        return sizeof(X35);
    }

    // #TEST#: R538 Rename sz
    static constexpr int sz = 4;
};

void f35()
{
    X35 x;
    // #TEST#: R539 Rename size member function
    constexpr std::size_t size = x.size();
    require_equal(std::size_t{1}, size);
    // #TEST#: R540 Rename sz static member
    constexpr int s = X35::sz;
    require_equal(4, s);
}

inline namespace Inline36
{
// #TEST#: R541 Rename x36
int x36 = 10;
// #TEST#: R542 Rename d36
double d36 = 20.5;
// #TEST#: R543 Rename s36
std::string s36()
{
    return "hello world!";
}

}    // namespace Inline36

void f36()
{
    // #TEST#: R544 Rename x36
    require_equal(10, x36);
    // #TEST#: R545 Rename d36
    require_equal(20.5, d36);
    // #TEST#: R546 Rename s36
    require_equal(std::string{"hello world!"}, s36());
}

void f37()
{
    // #TEST#: R547 Rename s1
    const char *s1{u8"foo"};
    // #TEST#: R548 Rename s1
    require_equal(std::string{"foo"}, std::string{s1});

    // #TEST#: R549 Rename s2
    const char16_t *s2{u"foo"};
    // #TEST#: R550 Rename s2
    require_equal(std::string{"foo"}, narrow(std::basic_string<char16_t>{s2}));

    // #TEST#: R551 Rename s3
    const char32_t *s3{U"foo"};
    // #TEST#: R552 Rename s3
    require_equal(std::string{"foo"}, narrow(std::basic_string<char32_t>{s3}));

    // #TEST#: R553 Rename s4
    const char *s4{R"(I say, "Hello, World!")"};
    // #TEST#: R554 Rename s4
    require_equal(std::string{R"(I say, "Hello, World!")"}, std::string{s4});
}

// #TEST#: R555 Rename F38_AUX
// #TEST#: R556 Rename stream_ in macro argument list
// #TEST#: R557 Rename stream_ in macro expansion text
// #TEST#: R558 Rename not available for __VA_ARGS__ in macro expansion text
#define F38_AUX(stream_, ...) f10_aux(stream_, __VA_ARGS__)

void f38()
{
    std::ostringstream result;
    // #TEST#: R559 Rename F38_AUX
    F38_AUX(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10\n20.5\nhello, world!\n"}, result.str());
}

// #TEST#: R560 Rename F38_AUX
#undef F38_AUX

// #TEST#: R561 Rename F39_AUX
#define F39_AUX(...) f10_aux(__VA_ARGS__)

void f39()
{
    std::ostringstream result;
    // #TEST#: R562 Rename F39_AUX
    F39_AUX(result, 10, 20.5, "hello, world!");
    require_equal(std::string{"10\n20.5\nhello, world!\n"}, result.str());
}

// #TEST#: R563 Rename F39_AUX
#undef F39_AUX

// #TEST#: R564 Rename X40
struct X40
{
    // #TEST#: R565 Rename x
    static int x;
};

// #TEST#: R566 Rename X40
// #TEST#: R567 Rename x
int X40::x = 0;

void f40()
{
    // #TEST#: R568 Rename X40
    // #TEST#: R569 Rename x
    require_equal(1, [] { return X40::x + 1; }());
}

// #TEST#: R570 Rename F41_AUX
#define F41_AUX 15

void f41()
{
    // #TEST#: R571 Rename F41_AUX
    require_equal(15, [] { return F41_AUX; }());
}

// #TEST#: R572 Rename F41_AUX
#undef F41_AUX

// #TEST#: R573 Rename f42_aux
void f42_aux(std::ostream &stream, int x)
{
    f10_aux(stream, x);
}

void f42()
{
    std::ostringstream result;
    // #TEST#: R574 Rename f42_aux
    [](std::ostream &s, int x) { f42_aux(s, x); }(result, 10);
    require_equal(std::string{"10\n"}, result.str());
}

template <typename T>
// #TEST#: R575 Rename f43_aux
void f43_aux(std::ostream &stream, T value)
{
    stream << value << '\n';
}

void f43()
{
    std::ostringstream result;
    // #TEST#: R576 Rename f43_aux
    [&result](int value) { f43_aux(result, value); }(10);
    require_equal(std::string{"10\n"}, result.str());
}

void f44()
{
    // #TEST#: R577 Rename X
    class X
    {
    public:
        X(const std::string &s) : m_s(s + " lvalue")
        {
        }
        // #TEST#: R578 Rename parameter s
        // #TEST#: R579 Rename parameter s in initializer list
        X(std::string &&s) : m_s(s + " rvalue")
        {
        }

        // #TEST#: R580 Rename method s
        const std::string &s() const &
        {
            return m_s;
        }
        // #TEST#: R581 Rename method s
        std::string s() const &&
        {
            return m_s + " rvalue";
        }

        // #TEST#: R582 Rename method set
        void set(const std::string &s)
        {
            m_s = s + " lvalue";
        }
        // #TEST#: R583 Rename method set
        // #TEST#: R584 Rename parameter s
        // #TEST#: R585 Rename parameter s in method body
        void set(std::string &&s)
        {
            m_s = s + " rvalue";
        }

    private:
        std::string m_s;
    };
    X x(std::string{"foo"});
    // #TEST#: R586 Rename method s
    require_equal(std::string{"foo rvalue"}, x.s());

    const std::string ss{"meh"};
    X xx(ss);
    require_equal(std::string{"meh lvalue"}, xx.s());

    // #TEST#: R587 Rename method set
    x.set(std::string{"bar"});
    require_equal(std::string{"bar rvalue"}, x.s());

    std::string s2{"meh"};
    // #TEST#: R588 Rename method set
    x.set(s2);
    require_equal(std::string{"meh lvalue"}, x.s());

    // #TEST#: R589 Rename method s
    require_equal(std::string{"meh rvalue rvalue"}, X{std::string{"meh"}}.s());

    // #TEST#: R590 Rename variable x2
    std::string &&x2 = std::string{"hello"} + ' ' + std::string{"world!"};
    // #TEST#: R591 Rename variable x2
    require_equal(std::string{"hello world!"}, x2);
    // #TEST#: R592 Rename variable x2
    x2 += "  goodbye!";
    // #TEST#: R593 Rename variable x2
    require_equal(std::string{"hello world!  goodbye!"}, x2);
}

template <typename T>
// #TEST#: R594 Rename function g45_aux
// #TEST#: R595 Rename parameter x
T g45_aux(T &&x)
{
    // #TEST#: R596 Rename parameter x
    T y(x);
    return y;
}

template <typename T>
// #TEST#: R597 Rename function f45_aux
// #TEST#: R598 Rename parameter x
T f45_aux(T &&x)
{
    // #TEST#: R599 Rename function g45_aux
    // #TEST#: R600 Rename parameter x
    return g45_aux(std::forward<T>(x));
}

void f45()
{
    struct X
    {
        X()
        {
        }
        X(const std::string &s) : s(s)
        {
        }
        X(std::string &&s) noexcept : s(std::move(s)), c(false)
        {
        }
        X(const X &rhs) : s(rhs.s)
        {
        }
        X(X &&rhs) noexcept : s(std::move(rhs.s)), c(false)
        {
        }

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

}    // namespace

namespace RenameCpp11
{
// #TEST#: R601 Rename Extern
template struct Extern<int>;
// #TEST#: R602 Rename Extern
template struct Extern<std::string>;

}    // namespace RenameCpp11

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
