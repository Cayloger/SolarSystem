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
	ifstream fin(infoPath);	// ���ļ�
	string line;			// ��ȡ�ļ���ÿһ��
	// ��ȡ�ļ���ֱ���ҵ���Ӧ��������Ϣ
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
	// �ر��ļ�
	fin.close();
	// ��string����ת��ΪLPCTSTR����
	output = info.c_str();
}

std::string Info::getInfo() const
{
	return info;
}

void Info::Print(int x, int y, int width, int height) const
{
	// ��ʾ������Ϣ
	// ����������ɫ����ʽ
	RECT rect = { x,y,x + width,y + height };
	settextcolor(WHITE);
	settextstyle(26, 0, _T("΢���ź�"));
	drawtext(output, &rect, DT_LEFT | DT_WORDBREAK);
}

ostream& operator<<(ostream& os, const Info& info)
{
	// ������������
	os << info.info;
	return os;
}