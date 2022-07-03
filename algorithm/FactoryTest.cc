#include <iostream>
using namespace std;
#include "Product.h"
#include "ProductFactory.h"

int main()
{
	/*************创建Windows Cpp ************************************/
	CodeStyleFactory * pWindowsCodeStyleFactory = new WindowsCodeStyleFactory();
	CppCodeStyle * pWindowsCppCodeStyle = pWindowsCodeStyleFactory->CreateCpp();
	pWindowsCppCodeStyle->DisplayCodeStyle();

	/*************创建Windows Java ************************************/
	JavaCodeStyle * pWindowsJavaCodeStyle = pWindowsCodeStyleFactory->CreateJava();
	pWindowsJavaCodeStyle->DisplayCodeStyle();
	
	cout << "***********************************" << endl;

	/*************创建Linux Cpp ************************************/
	CodeStyleFactory * pLinuxCodeStyleFactory = new LinuxCodeStyleFactory();
	CppCodeStyle * pLinuxCppCodeStyle = pLinuxCodeStyleFactory->CreateCpp();
	pLinuxCppCodeStyle->DisplayCodeStyle();
	
	/*************创建Linux Java ************************************/
	JavaCodeStyle * pLinuxJavaCodeStyle = pLinuxCodeStyleFactory->CreateJava();
	pLinuxJavaCodeStyle->DisplayCodeStyle();

	/*************销毁Windows相关对象操作****************************/
	delete pWindowsCodeStyleFactory;
	pWindowsCodeStyleFactory = NULL;
	delete pWindowsCppCodeStyle;
	pWindowsCppCodeStyle = NULL;
	delete pWindowsJavaCodeStyle;
	pWindowsJavaCodeStyle = NULL;

	/*************销毁Linux相关对象操作****************************/
	delete pLinuxCodeStyleFactory;
	pLinuxCodeStyleFactory = NULL;
	delete pLinuxCppCodeStyle;
	pLinuxCppCodeStyle = NULL;
	delete pLinuxJavaCodeStyle;
	pLinuxJavaCodeStyle = NULL;

	return 0;
}
