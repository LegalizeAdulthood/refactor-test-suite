#include <string>

// Generates a method for the selected method call with appropriate parameters.

// test functions that have been declared, but not defined.
// test methods that have been declared, but not defined.

//void foo()
//{
//  int i = 12;
//  float f = 3.0;
//  bar(i, f);
//}

namespace CreateMethodStubNamespace
{
    class Foo
    {
    public:
        Foo();
        int Operation1(int x) { return 1-x; }
        int Operation2(int x) { return 2*x; }
    };

    Foo::Foo()
    {
        // #TEST#: CMS7 Create stub for method bar
        //bar(12, "foo");
    }

    // #TEST#: CMS22 Create method stub after member param (should not be available)
    void TestMemberPointer(Foo &f, int (Foo::*member)(int), int i)
    {
        int j;
        if (i < 0)
        {
            j = (f.*member)(i);
        }
        else
        {
            j = (f.*member)(i*2);
        }
        j = (f.*member)(j);
    }

    class Foo2
    {
    public:
        Foo2();

    private:
        void bar(const std::string &arg)
        {
        }
        void gronk() const;
        int _i;
    };

    Foo2::Foo2() : _i(0)
    {
        _i = 12;
        float f = 3.0;
        // #TEST#: CMS8 Create stub for method bar
        //bar(f);
        // #TEST#: CMS9 Create stub for method bar
        //this->bar(1.0);
        // #TEST#: CMS10 Create stub for method bar
        //(*this).bar(1.0);
        std::string foo = "Yeeha!";
        std::string nelly = "Whoa, Nelly";
        // #TEST#: CMS11 Create overloaded stub for method bar
        //(*this).bar(foo, nelly);
    }

    void Foo2::gronk() const
    {
        // #TEST#: CMS15 Create method stub for blab; method should be const
        //(*this).blab();
    }

    class Foo3
    {
    public:
        int Operation() const
        {
            Foo2 *f = new Foo2();
            // #TEST#: CMS14 Create stub for method Operation
            //f->Operation();
            delete f;
            return 1;
        }
    };

    union Foo4
    {
        int x;
        float y;

        void Operation()
        {
            // #TEST#: CMS16 Create stub for method Operation2
            //Operation2();
        }
    };

    struct Foo5
    {
        int x;
        float y;

        void Operation()
        {
            // #TEST#: CMS17 Create stub for method Operation2
            //Operation2();
        }
    };

    void TestFoo45()
    {
        {
            Foo4 *foo4 = new Foo4();
            // #TEST#: CMS18 Create stub for method void Foo4::Operation2()
            //foo4->Operation2();
            delete foo4;
        }
        {
            Foo4 foo4;
            foo4.Operation();
            // #TEST#: CMS20 Create stub for method void Foo4::Operation2()
            //foo4.Operation2();
        }

        {
            Foo5 *foo5 = new Foo5();
            // #TEST#: CMS19 Create stub for method void Foo5::Operation2()
            //foo5->Operation2();
            delete foo5;
        }
        {
            Foo5 foo5;
            foo5.Operation();
            // #TEST#: CMS21 Create stub for method void Foo5::Operation2()
            //foo5.Operation2();
        }
    }
}

void TestCreateMethodStub()
{
    // #TEST#: CMS1 Create function stub for CreateMethodStubReturnsInteger()
    //int xint = CreateMethodStubReturnsInteger();

    // #TEST#: CMS2 Create function stub for CreateMethodStubNoReturnValue()
    //CreateMethodStubNoReturnValue();

    // #TEST#: CMS12 Create function stub for CreateMethodStubReturnsString()
    //std::string text = CreateMethodStubReturnsString();

    // #TEST#: CMS3 Create method stub for c'tor; shouldn't work
    using CreateMethodStubNamespace::Foo;
    Foo f = Foo();

    using CreateMethodStubNamespace::Foo3;
    // #TEST#: CMS4 Create method stub for Foo3 c'tor
    //Foo3 f3 = Foo3(3);

    Foo3 *pf3 = 0;
    // #TEST#: CMS5 Create method stub for Foo3 c'tor
    //pf3 = new Foo3(3);
    delete pf3;

    Foo3 x;
    x.Operation();
    // #TEST#: CMS6 Create method stub for Operation2
    //x.Operation2(0.0f);

    // #TEST#: CMS13 Create function stub in namespace
    //CreateMethodStubNamespace::TestInsideNamespace();

    CreateMethodStubNamespace::TestFoo45();
}
