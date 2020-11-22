#include "CreateSetterMethod.h"

// Creates a setter method for a private field and optionally replaces
// all field assignments with the calls to the newly created method.

namespace CreateSetterMethodNamespace
{
static std::string Foo = "foo";
static const std::string Bar("bar");

int CreateSetterMethod::_sa = 0;
const char *CreateSetterMethod::_sb = 0;
const std::string &CreateSetterMethod::_ss1 = Foo;
std::string &CreateSetterMethod::_ss2 = Foo;
std::string CreateSetterMethod::_ss3 = "Bar";

int CreateSetterMethodStruct::_si = 0;
const char *CreateSetterMethodStruct::_ss = "Text";
std::string CreateSetterMethodStruct::_sstr = Foo;

template <>
int CreateSetterMethodTemplate<int>::_st = 0;
template <>
float CreateSetterMethodTemplate<float>::_st = 1.0f;
template <>
double CreateSetterMethodTemplate<double>::_st = 2.0;

template <>
int CreateSetterMethodTemplateStruct<int>::_st = 0;
template <>
int *CreateSetterMethodTemplateStruct<int>::_stp = 0;
#if 0
template <>
std::vector<int> CreateSetterMethodTemplateStruct<int>::_stv;
#endif
template <>
float CreateSetterMethodTemplateStruct<float>::_st = 0.0f;
template <>
float *CreateSetterMethodTemplateStruct<float>::_stp = 0;
#if 0
template <>
std::vector<float> CreateSetterMethodTemplateStruct<float>::_stv;
#endif
template <>
double CreateSetterMethodTemplateStruct<double>::_st = 0.0;
template <>
double *CreateSetterMethodTemplateStruct<double>::_stp = 0;
#if 0
template <>
std::vector<double> CreateSetterMethodTemplateStruct<double>::_stv;
#endif

void CreateSetterMethod::Operation()
{
    _a = 1;
    _b = -1;
    _t = "This is a yotz";
    static std::string foo = "foo";
    _s2 = foo;
    _sa = -2;
    _sb = _t;
    _ss2 = foo;
    _ss3 = foo;
    this->_a = 1;
    this->_t = "This is another one";
}

void CreateSetterMethod::StaticOperation()
{
    _sa = -2;
    _sb = "This is a test";
    static std::string foo = _sb;
    _ss2 = foo;
    _ss3 = foo;
}

void TestCreateSetterMethodTemplateClass()
{
    CreateSetterMethodTemplate<int> ti;
    ti._t = -1;
    ti.Operation();
    CreateSetterMethodTemplate<int>::_st = -2;
    CreateSetterMethodTemplate<int>::StaticOperation();
    CreateSetterMethodTemplate<int> *tip = new CreateSetterMethodTemplate<int>();
    tip->_t = -1;
    tip->Operation();
    delete tip;

    CreateSetterMethodTemplate<float> tf;
    tf._t = -1.0f;
    tf.Operation();
    CreateSetterMethodTemplate<float>::_st = -3.0f;
    CreateSetterMethodTemplate<float>::StaticOperation();
    CreateSetterMethodTemplate<float> *tfp = new CreateSetterMethodTemplate<float>();
    tfp->_t = -1.0f;
    tfp->Operation();
    delete tfp;

    CreateSetterMethodTemplate<double> td;
    td._t = -1.0;
    td.Operation();
    CreateSetterMethodTemplate<double>::_st = -4.0;
    CreateSetterMethodTemplate<double>::StaticOperation();
    CreateSetterMethodTemplate<double> *tdp = new CreateSetterMethodTemplate<double>();
    tdp->_t = -1.0;
    tdp->Operation();
    delete tdp;
}

void TestCreateSetterMethodTemplateStruct()
{
    CreateSetterMethodTemplateStruct<int> si;
    si._t = -1;
    si._tp = new int;
    si._tp[0] = -4;
    delete si._tp;
    si._tv = std::vector<int>(4);
    CreateSetterMethodTemplateStruct<int>::_st = -2;
    CreateSetterMethodTemplateStruct<int>::_stp = new int;
    CreateSetterMethodTemplateStruct<int>::_stp[0] = -3;
    delete CreateSetterMethodTemplateStruct<int>::_stp;
#if 0
    CreateSetterMethodTemplateStruct<int>::_stv = std::vector<int>(4);
#endif

    CreateSetterMethodTemplateStruct<float> sf;
    sf._t = -1.0f;
    sf._tp = new float;
    sf._tp[0] = -4.0f;
    delete sf._tp;
    sf._tv = std::vector<float>(4);
    CreateSetterMethodTemplateStruct<float>::_st = -2.0f;
    CreateSetterMethodTemplateStruct<float>::_stp = new float;
    CreateSetterMethodTemplateStruct<float>::_stp[0] = -3.0f;
    delete CreateSetterMethodTemplateStruct<float>::_stp;
#if 0
    CreateSetterMethodTemplateStruct<float>::_stv = std::vector<float>(4);
#endif

    CreateSetterMethodTemplateStruct<double> sd;
    sd._t = -1.0;
    sd._tp = new double;
    sd._tp[0] = -4.0;
    delete sd._tp;
    sd._tv = std::vector<double>(4);
    CreateSetterMethodTemplateStruct<double>::_st = -2.0;
    CreateSetterMethodTemplateStruct<double>::_stp = new double;
    CreateSetterMethodTemplateStruct<double>::_stp[0] = -3.0;
    delete CreateSetterMethodTemplateStruct<double>::_stp;
#if 0
    CreateSetterMethodTemplateStruct<double>::_stv = std::vector<double>(4);
#endif
}

}    // namespace CreateSetterMethodNamespace

using namespace CreateSetterMethodNamespace;

void TestCreateSetterMethod()
{
    CreateSetterMethod csm(Foo);
    csm._a = 1;
    csm._b = 2;
    csm._t = "foo";
    csm._s2 = "blargh";
    CreateSetterMethod::_sa = 1;
    CreateSetterMethod::_sb = "foo";
    CreateSetterMethod::_ss2 = Foo;
    CreateSetterMethod::_ss3 = Foo;

    CreateSetterMethod *csm2 = new CreateSetterMethod(Foo);
    csm2->_a = -1;
    csm2->_t = "This is another foo";
    csm2->_s2 = Foo;
    delete csm2;

    CreateSetterMethodStruct s;
    s._i = -1;
    s._s = 0;
    s._s = "foo";
    s._str = Foo;
    CreateSetterMethodStruct::_si = -2;
    CreateSetterMethodStruct::_ss = "blarg";
    CreateSetterMethodStruct::_sstr = Foo;

    CreateSetterMethodUnion u;
    u._i = -2;
    u._s = 0;
    u._s = "foo";
    u._s = Foo.c_str();

    CreateSetterMethodStructAnonymous a;
    a._type = -3;
    a._i = -4;
    a._f = 1.0f;
    a._d = 2.0;
    a._s = 0;
    a._s = "foo";
    a._i = csm._a + csm._b;
    a._d = double(csm._ss2.length());

    TestCreateSetterMethodTemplateClass();
    TestCreateSetterMethodTemplateStruct();
}
