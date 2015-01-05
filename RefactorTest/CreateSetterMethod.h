#pragma once

#include <string>
#include <vector>

namespace CreateSetterMethodNamespace
{
	template <typename T>
	class CreateSetterMethodTemplate
	{
	public:
		CreateSetterMethodTemplate() : _t(0)
		{
		}

		// #TEST#: CSM30 Create setter method
		T _t;

		// #TEST#: CSM31 Create setter method
		static T _st;

		void Operation()
		{
			_t = T(0);
		}
		static void StaticOperation()
		{
			_st = T(0);
		}
	};

	class CreateSetterMethod
	{
	public:
		CreateSetterMethod(const std::string &s1)
			: _a(0),
			_b(0),
			_t(0),
			_s1(s1),
			_s2()
		{
		}

		// #TEST#: CSM1 Create setter method
		int _a;

		// #TEST#: CSM2 Create setter method
		int _b;

		// #TEST#: CSM3 Create setter method
		const char *_t;

		// #TEST#: CSM4 Create setter method (should not be available)
		const std::string &_s1;

		// #TEST#: CSM5 Create setter method
		std::string _s2;

		// #TEST#: CSM6 Create setter method
		static int _sa;

		// #TEST#: CSM7 Create setter method
		static const char *_sb;

		// #TEST#: CSM8 Create setter method (should not be available)
		static const std::string &_ss1;

		// #TEST#: CSM9 Create setter method
		static std::string &_ss2;

		// #TEST#: CSM10 Create setter method
		static std::string _ss3;

		void OperationInline()
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
		}
		void Operation();

		static void StaticOperationInline()
		{
			_sa = -2;
			_sb = "This is a test";
			static std::string foo = _sb;
			_ss2 = foo;
			_ss3 = foo;
		}
		static void StaticOperation();
	};

	struct CreateSetterMethodStruct
	{
		// #TEST#: CSM11 Create setter method
		int _i;

		// #TEST#: CSM12 Create setter method
		const char *_s;

		// #TEST#: CSM13 Create setter method
		std::string _str;

		// #TEST#: CSM14 Create setter method
		static int _si;

		// #TEST#: CSM15 Create setter method
		static const char *_ss;

		// #TEST#: CSM16 Create setter method
		static std::string _sstr;
	};

	template <typename T>
	struct CreateSetterMethodTemplateStruct
	{
		// #TEST#: CSM24 Create setter method
		T _t;

		// #TEST#: CSM25 Create setter method
		T *_tp;

		// #TEST#: CSM26 Create setter method
		std::vector<T> _tv;

		// #TEST#: CSM27 Create setter method
		static T _st;

		// #TEST#: CSM28 Create setter method
		static T *_stp;

#if 0
		// #TEST#: CSM29 Create setter method
		static std::vector<T> _stv;
#endif
	};

	union CreateSetterMethodUnion
	{
		// #TEST#: CSM17 Create setter method
		int _i;

		// #TEST#: CSM18 Create setter method
		const char *_s;
	};

	struct CreateSetterMethodStructAnonymous
	{
		// #TEST#: CSM19 Create setter method
		int _type;
		union
		{
			// #TEST#: CSM20 Create setter method
			int _i;

			// #TEST#: CSM21 Create setter method
			float _f;

			// #TEST#: CSM22 Create setter method
			double _d;

			// #TEST#: CSM23 Create setter method
			const char *_s;
		};
	};
}
