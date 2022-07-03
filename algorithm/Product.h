#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>
#include <string>
using namespace std;

//抽象Cpp代码格式类
class CppCodeStyle
{
public:
	//虚函数，用于显示处理的代码格式
	virtual void DisplayCodeStyle() = 0;
};


//Windows Cpp代码格式
class WindowsCppCodeStyle : public CppCodeStyle
{
public:
	void DisplayCodeStyle()
	{
		cout << "我对Windows Cpp文件进行代码比较" << endl;
	}
};


//Linux Cpp代码格式
class LinuxCppCodeStyle : public CppCodeStyle
{
public:
	void DisplayCodeStyle()
	{
		cout << "我对Linux Cpp文件进行代码比较" << endl;
	}
};

/*********************************************************/
/*********************************************************/

//抽象Java代码格式
class JavaCodeStyle
{
public:
	//虚函数，用于显示处理的代码格式
	virtual void DisplayCodeStyle() = 0;
};


//Windows Java代码格式
class WindowsJavaCodeStyle : public JavaCodeStyle
{
public:
	void DisplayCodeStyle()
	{
		cout << "我对Windows Java文件进行代码比较" << endl;
	}
};


//Linux Java代码格式
class LinuxJavaCodeStyle : public JavaCodeStyle
{
public:
	void DisplayCodeStyle()
	{
		cout << "我对Linux Java文件进行代码比较" << endl;
	}
};

#endif
