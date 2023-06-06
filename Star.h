#pragma once
#include <string>
#include "Info.h"
#include "AstronomicalObject.h"
class Star : public AstronomicalObject
{
private:
	double rotationPeriod;	// ��ת����
	double currentRotation;	// ��ǰ��ת�Ƕ�
public:
	Star(const std::string& starName, double starRadius, double starRotationPeriod, double isize, const LPCSTR starTexturePath, string infoPath = "Information//StarInfo.txt");	// ���캯��
	void update(double elapsedTime);					// ����������ת�Ƕ�
	void draw(double centerX, double centerY);	// ��������
	double getRotationSpeed() const;					// ��ȡ������ת�ٶ�	
	double getCurrentRotation() const;				// ��ȡ����ǰ��ת�Ƕ�
	void setCurrentRotation(double rotation);		// ��������ǰ��ת�Ƕ�
	void setRotationPeriod(double period);			// ����������ת����
};

