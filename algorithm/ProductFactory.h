#ifndef _PRODUCT_FACTORY_H_
#define _PRODUCT_FACTORY_H_

#include "Product.h"

//抽象代码格式工厂
class CodeStyleFactory
{
public:
	//工厂方法,创建具体的Cpp格式对象
	virtual CppCodeStyle * CreateCpp() = 0;

	//工厂方法,创建具体的Java格式对象
	virtual JavaCodeStyle * CreateJava() = 0;
};


//Windows代码格式工厂
class WindowsCodeStyleFactory : public CodeStyleFactory
{
public:
	//工厂方法,创建具体的Cpp格式对象
	CppCodeStyle * CreateCpp()
	{
		CppCodeStyle * pCppCodeStyle = new WindowsCppCodeStyle();

		return pCppCodeStyle;
	}

	//工厂方法,创建具体的Java格式对象
	JavaCodeStyle * CreateJava()
	{
		JavaCodeStyle * pJavaCodeStyle = new WindowsJavaCodeStyle();

		return pJavaCodeStyle;
	}
};


//Linux代码格式工厂
class LinuxCodeStyleFactory : public CodeStyleFactory
{
public:
	//工厂方法,创建具体的Cpp格式对象
	CppCodeStyle * CreateCpp()
	{
		CppCodeStyle * pCppCodeStyle = new LinuxCppCodeStyle();

		return pCppCodeStyle;
	}

	//工厂方法,创建具体的Java格式对象
	JavaCodeStyle * CreateJava()
	{
		JavaCodeStyle * pJavaCodeStyle = new LinuxJavaCodeStyle();
		
		return pJavaCodeStyle;
	}
};

#endif
