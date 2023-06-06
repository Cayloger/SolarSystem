#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <graphics.h>
#include <conio.h>
using namespace std;

class Info
{
private:
	string info;	// 星球信息（字符串类型）
	LPCTSTR output;	// 星球信息（用于画面输出）
public:
	Info()
	{
		info = "暂无信息";
		output = info.c_str();
	}	// 默认构造函数
	Info(const std::string& infoPath, std::string name);	// 构造函数
	std::string getInfo() const;	// 获取星球信息
	void Print(int x, int y, int width, int height) const;	// 显示星球信息
	friend ostream& operator<<(ostream& os, const Info& info);	// 重载输出运算符
};