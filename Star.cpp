#pragma once
#include "Star.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846

/*
* ���캯��
* starName: ��������
* starRadius: ����뾶
* starRotationPeriod: ������ת����
* starTexturePath: ��������·��
* infoPath: ������Ϣ·��
*/
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, double isize, const LPCSTR starTexturePath, std::string infoPath)
	: AstronomicalObject(starName, starRadius, isize, starTexturePath, infoPath)
{
	this->rotationPeriod = starRotationPeriod;
	this->currentRotation = 0;
}

/*
* ��������״̬
* elapsedTime: ��һ֡����ǰ֡��ʱ����
*/
void Star::update(double elapsedTime)
{
	// ����������ת�Ƕ�
	currentRotation += getRotationSpeed() * elapsedTime;
}

/*
* ��������
* centerX: �������ĵ�x����
* centerY: �������ĵ�y����
* 
* ˵������������Ŀ��Ӧ��Ϊ�뾶������
*/
void Star::draw(double centerX, double centerY)
{
	AstronomicalObject::draw(centerX, centerY);

	// ��ʾ��������
	settextcolor(RED);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	RECT rect{ centerX - 20, centerY - 20, centerX + 20, centerY + 20 };
	_bstr_t bstr(getName().c_str());
	LPTSTR s = (LPTSTR)bstr;
	drawtext(s, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/*
* ��ȡ������ת�ٶ�
* 
* ˵������ת�ٶ�Ϊ������
* 
* ����ֵ��������ת�ٶ�
*/
double Star::getRotationSpeed() const
{
	// ������ת�ٶ�
	// 2 * PI / T
	return (2 * M_PI) / rotationPeriod;
}

/*
* ��ȡ������ת�Ƕ�
* 
* ����ֵ��������ת�Ƕ�
* 
* ˵�����Ƕȵ�λΪ����
*/
double Star::getCurrentRotation() const
{
	return currentRotation;
}

/*
* ����������ת�Ƕ�
* 
* rotation: ������ת�Ƕ�
* 
* ˵�����Ƕȵ�λΪ����
*/
void Star::setCurrentRotation(double rotation)
{
	currentRotation = rotation;
}

/*
* ����������ת����
* 
* period: ������ת����
* 
* ˵�������ڵ�λΪ��
*/
void Star::setRotationPeriod(double period)
{
	rotationPeriod = period;
}
