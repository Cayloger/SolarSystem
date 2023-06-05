#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <vector>
#include <cmath>
#include <graphics.h>
#include "Info.h"

class Planet {
private:
	std::string name;		// ��������
	float distanceFromSun;	// ����̫���ľ���
	float radius;			// ���ǰ뾶
	float orbitPeriod;		// ��ת����
	float rotationPeriod;	// ��ת����
	float inclination;		// ������
	float eccentricity;		// ���������
	LPCSTR texturePath;	// ��������·��

	float currentAngle;		// ��ǰ�Ƕ�
	float currentRotation;	// ��ǰ��ת�Ƕ�

	Info planetInfo;		// ������Ϣ

public:
	// ���캯��
	Planet(const std::string& planetName, float distance, float planetRadius,
		float orbitPeriod, float rotationPeriod, float planetInclination,
		float planetEccentricity, const LPCSTR planetTexturePath, const std::string infoPath = "PlanetInfo.txt");

	void update(float elapsedTime);					// ����������Ϣ
	void draw(float centerX, float centerY) const;	// ��������
	float getOrbitalSpeed() const;					// ��ȡ���ǹ�ת�ٶ�	
	float getRotationSpeed() const;					// ��ȡ������ת�ٶ�
	float getOrbitalX(float centerX) const;			// ��ȡ������X���ϵ�����
	float getOrbitalY(float centerY) const;			// ��ȡ������Y���ϵ�����

	float getRadius() const;						// ��ȡ���ǰ뾶
	float getDistanceFromSun() const;				// ��ȡ���Ǿ���̫���ľ���
	std::string getName() const;					// ��ȡ��������
	LPCSTR getTexturePath() const;			// ��ȡ��������·��

	float getCurrentAngle() const;					// ��ȡ��ǰ�Ƕ�
	float getCurrentRotation() const;				// ��ȡ��ǰ��ת�Ƕ�

	Info& getPlanetInfo();							// ��ȡ������Ϣ

	void setCurrentAngle(float angle);				// ���õ�ǰ�Ƕ�
	void setCurrentRotation(float rotation);		// ���õ�ǰ��ת�Ƕ�

	void setDistanceFromSun(float distance);		// �������Ǿ���̫���ľ���
	void setRadius(float planetRadius);				// �������ǰ뾶
	void setOrbitPeriod(float period);				// �������ǹ�ת����
	void setRotationPeriod(float period);			// ����������ת����
	void setInclination(float planetInclination);	// �������ǹ�����
	void setEccentricity(float planetEccentricity);	// �������ǹ��������
	void setTexturePath(const LPCSTR& planetTexturePath);	// ������������·��

	void setName(const std::string& planetName);	// ������������

};

#endif
