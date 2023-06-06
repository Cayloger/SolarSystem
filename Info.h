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
	string info;	// ������Ϣ���ַ������ͣ�
	LPCTSTR output;	// ������Ϣ�����ڻ��������
public:
	Info()
	{
		info = "������Ϣ";
		output = info.c_str();
	}	// Ĭ�Ϲ��캯��
	Info(const std::string& infoPath, std::string name);	// ���캯��
	std::string getInfo() const;	// ��ȡ������Ϣ
	void Print(int x, int y, int width, int height) const;	// ��ʾ������Ϣ
	friend ostream& operator<<(ostream& os, const Info& info);	// ������������
};