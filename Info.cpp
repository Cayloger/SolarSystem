#include "Info.h"
#include <fstream>
#include <sstream>
#include <comdef.h>
#include <string>
#include <graphics.h>
using namespace std;

Info::Info(const std::string& infoPath, std::string name)
{
	info = "";
	ifstream fin(infoPath);	// 打开文件
	string line;			// 读取文件的每一行
	// 读取文件，直到找到对应的星球信息
	while (getline(fin, line))
	{
		if (line == name)
		{
			while (getline(fin, line))
			{
				if (line == "end")
					break;
				info += line;
				info += '\n';
				info += '\n';
			}
			break;
		}
	}
	// 关闭文件
	fin.close();
	// 将string类型转换为LPCTSTR类型
	output = info.c_str();
}

std::string Info::getInfo() const
{
	return info;
}

void Info::Print(int x, int y, int width, int height) const
{
	// 显示星球信息
	// 设置字体颜色和样式
	RECT rect = { x,y,x + width,y + height };
	settextcolor(WHITE);
	settextstyle(26, 0, _T("微软雅黑"));
	drawtext(output, &rect, DT_LEFT | DT_WORDBREAK);
}

ostream& operator<<(ostream& os, const Info& info)
{
	// 重载输出运算符
	os << info.info;
	return os;
}