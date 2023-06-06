#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <vector>
#include <cmath>
#include <graphics.h>
#include "Info.h"
#include "AstronomicalObject.h"

class Planet : public AstronomicalObject{
private:
	//std::string name;		// ��������
	double distanceFromSun;	// ����̫���ľ���
	//double radius;			// ���ǰ뾶
	double orbitPeriod;		// ��ת����
	double rotationPeriod;	// ��ת����
	double inclination;		// ������
	double eccentricity;		// ���������
	//LPCSTR texturePath;	// ��������·��

	double currentAngle;		// ��ǰ�Ƕ�
	double currentRotation;	// ��ǰ��ת�Ƕ�
	//double imagesize;		// ͼƬ��С

	//Info planetInfo;		// ������Ϣ

public:
	// ���캯��
	Planet(const std::string& planetName, double distance, double planetRadius,
		double orbitPeriod, double rotationPeriod, double planetInclination,
		double planetEccentricity, double isize, const LPCSTR planetTexturePath, 
		const std::string infoPath = "Information//PlanetInfo.txt");

	void update(double elapsedTime);					// ����������Ϣ
	void draw(double centerX, double centerY);	// ��������
	double getOrbitalSpeed() const;					// ��ȡ���ǹ�ת�ٶ�	
	double getRotationSpeed() const;					// ��ȡ������ת�ٶ�
	double getOrbitalX(double centerX) const;			// ��ȡ������X���ϵ�����
	double getOrbitalY(double centerY) const;			// ��ȡ������Y���ϵ�����

	double getDistanceFromSun() const;				// ��ȡ���Ǿ���̫���ľ���

	double getCurrentAngle() const;					// ��ȡ��ǰ�Ƕ�
	double getCurrentRotation() const;				// ��ȡ��ǰ��ת�Ƕ�

	void setCurrentAngle(double angle);				// ���õ�ǰ�Ƕ�
	void setCurrentRotation(double rotation);		// ���õ�ǰ��ת�Ƕ�

	void setDistanceFromSun(double distance);		// �������Ǿ���̫���ľ���
	void setOrbitPeriod(double period);				// �������ǹ�ת����
	void setRotationPeriod(double period);			// ����������ת����
	void setInclination(double planetInclination);	// �������ǹ�����
	void setEccentricity(double planetEccentricity);	// �������ǹ��������
};

#endif
