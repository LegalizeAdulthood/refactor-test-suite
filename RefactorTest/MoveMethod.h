#pragma once

#include <string>

class MoveMethod
{
public:
    MoveMethod();
    // #TEST#: MM1 Move method to cpp
    ~MoveMethod()
    {
    }

    void MethodDefault(char const *text, int arg1 = 0);

    // #TEST#: MM2 Move method to cpp
    void MethodInline(const std::string &text)
    {
        _text = text;
    }

    // #TEST#: MM13 Move method to cpp
    void MethodConstInline(const std::string &text) const
    {
    }

    void MethodConst(const std::string &text) const;

    // #TEST#: MM31 Move method to cpp
    void MethodDefaultInline(const char *text, int arg1 = 0)
    {
    }

private:
    int _int;
    std::string _text;
    std::string _bar;
};

class MoveMethod2
{
public:
    // #TEST#: MM3 Move method to cpp
    MoveMethod2()
        : _int(0)
    {
    }

    // destructor
    ~MoveMethod2();

    // #TEST#: MM9 Move method to cpp
    void MethodDefault(char const *text, int arg1 = 0)
    {
        SetProtectedString(text);
        SetProtectedInt(arg1);
    }

    // #TEST#: MM32 Move method to cpp
    void MethodDefault2(char *(*text)(), int arg1 = 0)
    {
        SetProtectedString((*text)());
        SetProtectedInt(arg1);
    }

    // #TEST#: MM33 Move method to cpp
    void MethodDefault3(int (MoveMethod2::*member)(), int arg1 = 0)
    {
        int sum = arg1 + (this->*member)();
    }

    // #TEST#: MM34 Move method to cpp
    void MethodDefault4(void (MoveMethod2::*member)(int) const, int arg1 = 0)
    {
        (this->*member)(arg1);
    }

    int Operation1() { return 1; }
    int Operation2() { return 2; }
    void ConstOp1(int x) const { }
    void ConstOp2(int x) const { }

    void Method(const std::string &text);

protected:
    void SetProtectedInt(int arg);
    // #TEST#: MM4 Move method to source
    void SetProtectedString(const std::string &text)
    {
        SetString(text);
    }

private:
    void SetInt(int arg);
    // #TEST#: MM5 Move method to source
    void SetString(const std::string &text)
    {
        _text = text;
    }

    int _int;
    std::string _text;
};

namespace MoveMethodNamespace
{

class MoveMethodAbstractInline
{
public:
    // #TEST#: MM15 Move method to source file
    MoveMethodAbstractInline()
    {
    }

    // #TEST#: MM16 Move method to source file
    virtual ~MoveMethodAbstractInline()
    {
    }

    // #TEST#: MM17 Move method to source file
    void Operation()
    {
    }

    // #TEST#: MM18 Move method to source file
    void OperationConst() const
    {
    }

    // #TEST#: MM19 Move method to source file
    virtual void OperationVirtual()
    {
    }

    virtual void OperationAbstract() = 0;
};

class MoveMethodConcreteInline : public MoveMethodAbstractInline
{
public:
    // #TEST#: MM20 Move method to source file
    MoveMethodConcreteInline()
    {
    }

    // #TEST#: MM21 Move method to source file
    virtual ~MoveMethodConcreteInline()
    {
    }

    // #TEST#: MM22 Move method to source file
    virtual void OperationAbstract()
    {
    }
};

class MoveMethodAbstract
{
public:
    MoveMethodAbstract();
    virtual ~MoveMethodAbstract();
    void Operation();
    void OperationConst() const;
    virtual void OperationVirtual();
    virtual void OperationAbstract() = 0;
};

class MoveMethodConcrete : public MoveMethodAbstract
{
public:
    MoveMethodConcrete();
    virtual ~MoveMethodConcrete();
    virtual void OperationAbstract();
};

class MoveMethodExplicit
{
public:
    explicit MoveMethodExplicit();
};

class MoveMethodExplicit2
{
public:
    // #TEST#: MM36 Move method to source file
    explicit MoveMethodExplicit2()
    {
    }
};

}
