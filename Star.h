#pragma once
#include <string>
#include "Info.h"
class Star
{
private:
	std::string name;		// ��������
	double radius;			// ����뾶
	double rotationPeriod;	// ��ת����
	double currentRotation;	// ��ǰ��ת�Ƕ�
	std::wstring texturePath;	// ��������·��
	Info starInfo;			// ������Ϣ
public:
	// ���캯��
	Star(const std::string& starName, double starRadius, double starRotationPeriod, const std::wstring& starTexturePath, string infoPath = "StarInfo.txt");
	void update(double elapsedTime);					// ����������ת�Ƕ�
	void draw(double centerX, double centerY) const;	// ��������
	double getRotationSpeed() const;					// ��ȡ������ת�ٶ�	
	double getRadius() const;						// ��ȡ����뾶
	std::string getName() const;					// ��ȡ��������
	std::wstring getTexturePath() const;			// ��ȡ��������·��
	double getCurrentRotation() const;				// ��ȡ����ǰ��ת�Ƕ�
	void setCurrentRotation(double rotation);		// ��������ǰ��ת�Ƕ�
	void setRadius(double starRadius);				// ��������뾶
	void setRotationPeriod(double period);			// ����������ת����
	void setTexturePath(const std::wstring& starTexturePath);	// ������������·��
	void setName(const std::string& starName);		// ������������
	Info& getStarInfo();							// ��ȡ������Ϣ
};

