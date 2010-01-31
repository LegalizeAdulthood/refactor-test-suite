extern void AddParameterFn();
extern void AddParameterFn(int first);
extern void AddParameterFn(float &first);
extern void AddParameterFn(const float &first);
extern void AddParameterFnRef(const int &first);
extern void AddParameterFnDefault(int first = 0);

class AddParameterTester
{
public:
	AddParameterTester()
	{
	}
	~AddParameterTester()
	{
	}

	// #TEST#: AP1 Add parameter
	void AddParameter()
	{
	}

	// #TEST#: AP2 Add parameter
	template <typename T>
	void AddParameter2()
	{
	}

	// #TEST#: AP3 Add parameter
	void AddParameter(int first);
	// #TEST#: AP4 Add parameter
	void AddParameterRef(const int &first);
	// #TEST#: AP5 Add parameter
	void AddParameterDefault(int first = 0);

	// #TEST#: AP6 Add parameter
	static void AddParameterStaticInline()
	{
	}
	// #TEST#: AP7 Add parameter
	static void AddParameterStaticDefaultInline(int first = 0)
	{
	}
	// #TEST#: AP8 Add parameter
	static void Static();
	// #TEST#: AP9 Add parameter
	static void StaticDefault(int x, int y = 0);
	// #TEST#: AP10 Add parameter
	template <typename T>
	static void StaticTemplate(int x)
	{
		T val = x;
	}
	// #TEST#: AP11 Add parameter
	template <typename T>
	static void StaticTemplateDefault(int x = 0)
	{
	}
};

template <typename T>
class AddParameterTemplateClass
{
public:
	static T StaticTemplate()
	{
		return T(0);
	}

	T Template()
	{
		return T(0);
	}

	static void StaticTemplateArg(T arg)
	{
	}

	void TemplateArg(T arg)
	{
	}

	void TemplateArgDefault(T arg = 0)
	{
	}
};

// #TEST#: AP12 Add parameter
template <typename T>
void AddParameter2()
{
	T::AddParameter();
}

struct AddParameterStruct
{
	AddParameterStruct()
	{
	}
	~AddParameterStruct()
	{
	}

	void AddParameter()
	{
	}

	template <typename T>
	void AddParameter2()
	{
	}

	void AddParameter(int first);
	void AddParameterRef(const int &first);
	void AddParameterDefault(int first = 0);

	static void AddParameterStaticInline()
	{
	}
	static void AddParameterStaticDefaultInline(int first = 0)
	{
	}
	static void Static();
	static void StaticDefault(int x, int y = 0);
	template <typename T>
	static void StaticTemplate(int x)
	{
		T val = x;
	}
	template <typename T>
	static void StaticTemplateDefault(int x = 0)
	{
	}
};

union AddParameterUnion
{
public:
	AddParameterUnion()
	{
	}
	~AddParameterUnion()
	{
	}

	void AddParameter()
	{
	}

	template <typename T>
	void AddParameter2()
	{
	}

	void AddParameter(int first);
	void AddParameterRef(const int &first);
	void AddParameterDefault(int first = 0);

	static void AddParameterStaticInline()
	{
	}
	static void AddParameterStaticDefaultInline(int first = 0)
	{
	}
	static void Static();
	static void StaticDefault(int x, int y = 0);
	template <typename T>
	static void StaticTemplate(int x)
	{
		T val = x;
	}
	template <typename T>
	static void StaticTemplateDefault(int x = 0)
	{
	}
};

template <typename Other>
union AddParameterUnionTemplate
{
public:
	AddParameterUnionTemplate()
	{
	}
	~AddParameterUnionTemplate()
	{
	}

	void AddParameter()
	{
	}

	template <typename T>
	void AddParameter2()
	{
	}

	void AddParameter(int first);
	void AddParameterRef(const int &first);
	void AddParameterDefault(int first = 0);

	static void AddParameterStaticInline()
	{
	}
	static void AddParameterStaticDefaultInline(int first = 0)
	{
	}
	static void Static();
	static void StaticDefault(int x, int y = 0);
	template <typename T>
	static void StaticTemplate(int x)
	{
		T val = x;
	}
	template <typename T>
	static void StaticTemplateDefault(int x = 0)
	{
	}

	static Other OtherStaticTemplate()
	{
		return Other(0);
	}
	Other OtherTemplate()
	{
		return Other(0);
	}
};

namespace AddParameterNamespace
{
	class Outer
	{
	public:
		Outer()
		{
		}
		~Outer()
		{
		}

		void Operation()
		{
		}

		class Inner
		{
		public:
			Inner()
			{
			}

			void Operation()
			{
			}
		};
	};
}
