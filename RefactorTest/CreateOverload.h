#pragma once
#include <string>

namespace CreateOverloadNamespace
{
    class CreateOverloadAbstract
    {
    public:
        virtual ~CreateOverloadAbstract() = 0;

        // #TEST#: CO1 Create overload for virtual method
        virtual void bar1(const char *text, int arg1) = 0;

        // #TEST#: CO2 Create overload for virtual method, remove default argument
        // #TEST#: CO3 Create overload for virtual method, remove first argument
        virtual void bar2(const char *text, int arg1 = 0) = 0;

        // #TEST#: CO4 Create overload for virtual const method
        virtual void bar3(const char *text, int arg1) const = 0;

        // #TEST#: CO5 Create overload for virtual const method, remove default argument
        // #TEST#: CO6 Create overload for virtual const method, remove first argument
        virtual void bar4(const char *text, int arg1 = 0) const = 0;
    };

    class CreateOverload
    {
    public:
        CreateOverload();

        // #TEST#: CO7 Create overload for constructor
        CreateOverload(const char *text, int arg);

        // #TEST#: CO8 Create overload for method
        void bar1(const char *text, int arg1);

        // #TEST#: CO9 Create overload for method, removing default argument
        // #TEST#: CO10 Create overload for method, removing first argument
        void bar2(const char *text, int arg1 = 0);

        // #TEST#: CO11 Create overload for const method
        void bar3(const char *text, int arg1) const;

        // #TEST#: CO12 Create overload for const method, remove default argument
        // #TEST#: CO13 Create overload for const method, remove first argument
        void bar4(const char *text, int arg1 = 0) const;

        // #TEST#: CO14 Create overload for inline method
        void inline1(const std::string &text, int arg1)
        {
        }

        // #TEST#: CO15 Create overload for inline method, remove default argument
        // #TEST#: CO16 Create overload for inline method, remove first argument
        void inline2(const std::string &text, int arg1 = 0)
        {
        }

        // #TEST#: C017 Create overload for inline const method
        void inline3(const std::string &text, int arg1) const
        {
        }

        // #TEST#: CO18 Create overload for inline const method, remove default argument
        // #TEST#: CO19 Create overload for inline const method, remove first argument
        void inline4(const std::string &text, int arg1 = 0) const
        {
        }

        // #TEST#: CO54 Create overload for static method
        static int function1(const char *text)
        {
            return text ? static_cast<int>(std::string(text).size()) : 0;
        }
    };

    struct CreateOverloadAbstractStruct
    {
        virtual ~CreateOverloadAbstractStruct() = 0;

        // #TEST#: CO45 Create overload for virtual method
        virtual void bar1(const char *text, int arg1) = 0;

        // #TEST#: CO46 Create overload for virtual method, remove default argument
        // #TEST#: CO47 Create overload for virtual method, remove first argument
        virtual void bar2(const char *text, int arg1 = 0) = 0;

        // #TEST#: CO48 Create overload for virtual const method
        virtual void bar3(const char *text, int arg1) const = 0;

        // #TEST#: CO49 Create overload for virtual const method, remove default argument
        // #TEST#: CO50 Create overload for virtual const method, remove first argument
        virtual void bar4(const char *text, int arg1 = 0) const = 0;
    };

    struct CreateOverloadStruct
    {
        CreateOverloadStruct();

        // #TEST#: CO20 Create overload for c'tor on struct
        CreateOverloadStruct(const char *text, int arg);

        // #TEST#: CO21 Create overload for struct method
        void bar1(const char *text, int arg1);

        // #TEST#: CO22 Create overload for struct method, remove default argument
        // #TEST#: CO23 Create overload for struct method, remove first argument
        void bar2(const char *text, int arg1 = 0);

        // #TEST#: CO24 Create overload for const struct method
        void bar3(const char *text, int arg1) const;

        // #TEST#: CO25 Create overload for const struct method, remove default argument
        // #TEST#: CO26 Create overload for const struct method, remove first argument
        void bar4(const char *text, int arg1 = 0) const;

        // #TEST#: CO27 Create overload for inline struct method
        void inline1(const char *text, int arg1)
        {
        }

        // #TEST#: CO28 Create overload for inline struct method, remove default argument
        // #TEST#: CO29 Create overload for inline struct method, remove first argument
        void inline2(const char *text, int arg1 = 0)
        {
        }

        // #TEST#: CO30 Create overload for inline const struct method
        void inline3(const char *text, int arg1) const
        {
        }

        // #TEST#: CO31 Create overload for inline const struct method, remove default argument
        // #TEST#: CO32 Create overload for inline const struct method, remove first argument
        void inline4(const char *text, int arg1 = 0) const
        {
        }

        // #TEST#: CO51 Create overload for method, remove first argument
        void inline5(const char *arg1, int arg2 = -1)
        {
        }

        // #TEST#: CO52 Create overload for method, remove first argument
        void inline6(const char *arg1, int arg2 = function1("This is a test"))
        {
        }

        // #TEST#: CO53 Create overload for static method
        static int function1(const char *text)
        {
            return text ? static_cast<int>(std::string(text).size()) : 0;
        }
    };

    union CreateOverloadUnion
    {
        int x;
        float y;

        // #TEST#: CO33 Create overload for union method
        void bar1(int x, float y);

        // #TEST#: CO34 Create overload for union method, remove default argument
        // #TEST#: CO35 Create overload for union method, remove first argument
        void bar2(int x, float y = 1.0f);

        // #TEST#: CO36 Create overload for union const method
        void bar3(int x, float y) const;

        // #TEST#: CO37 Create overload for union const method, remove default argument
        // #TEST#: CO38 Create overload for union const method, remove first argument
        void bar4(int x, float y = 1.0f) const;

        // #TEST#: CO39 Create overload for inline union method
        void inline1(int x, float y)
        {
        }

        // #TEST#: CO40 Create overload for inline union method, remove default argument
        // #TEST#: CO41 Create overload for inline union method, remove first argument
        void inline2(int x, float y = 1.0f)
        {
        }

        // #TEST#: CO42 Create overload for inline const union method
        void inline3(int x, float y) const
        {
        }

        // #TEST#: CO43 Create overload for inline const union method, remove default argument
        // #TEST#: CO44 Create overload for inline const union method, remove first argument
        void inline4(int x, float y = -1.0f) const
        {
        }

        // #TEST#: CO55 Create overload for static method
        static int function1(const char *text)
        {
            return text ? static_cast<int>(std::string(text).size()) : 0;
        }

        // #TEST#: CO56 Create overload for static method with volatile argument
        static void method1(volatile int *arg1, int arg2)
        {
            *arg1 = arg2;
        }
    };
}
