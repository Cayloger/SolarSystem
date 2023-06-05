#pragma once
#include "Planet.h"
#include "Info.h"
#include <graphics.h>
#include <comdef.h>
#pragma comment( lib, "MSIMG32.LIB")
#define M_PI 3.14159265358979323846

/*
* ͸����ͼ����
* dstimg: Ŀ��ͼ��
* x, y: Ŀ��ͼ������Ͻ�����
* srcimg: Դͼ��
*/
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);	//��ȡĿ��ͼ��ľ��
	HDC srcDC = GetImageHDC(srcimg);	//��ȡԴͼ��ľ��
	int w = srcimg->getwidth();			//��ȡԴͼ��Ŀ��
	int h = srcimg->getheight();		//��ȡԴͼ��ĸ߶�
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };	//���û�Ϻ���
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);		//��ϻ�ͼ
}

/*
* ���캯��
* planetName: ��������
* distance: ���Ǿ���̫���ľ���
* planetRadius: ���ǰ뾶
* orbitPeriod: ���ǹ�ת����
* rotationPeriod: ������ת����
* planetInclination: ���ǹ�����
*/
Planet::Planet(const std::string& planetName, float distance, float planetRadius,
	float orbitPeriod, float rotationPeriod, float planetInclination,
	float planetEccentricity, float size, const LPCSTR planetTexturePath, const std::string infoPath) :
	name(planetName), distanceFromSun(distance), radius(planetRadius), orbitPeriod(orbitPeriod),
	rotationPeriod(rotationPeriod), inclination(planetInclination), eccentricity(planetEccentricity),
	imagesize(size), texturePath(planetTexturePath), currentAngle(0), currentRotation(0), 
	planetInfo(infoPath, planetName) {}

void Planet::update(float elapsedTime)
{
	// ���½Ƕ�
	// �� = �� * t
	// �� = 2 * �� / T
	// �� = 2 * �� * t / T
	currentAngle += getOrbitalSpeed() * elapsedTime;
	currentRotation += getRotationSpeed() * elapsedTime;
}

void Planet::draw(float centerX, float centerY) const
{
	// �������Ǿ���̫���ľ���
	float distance;
	distance = distanceFromSun / (1 - eccentricity);
	
	// �����
	setlinecolor(WHITE);
	setlinestyle(PS_JOIN_ROUND | PS_ENDCAP_ROUND, 2);
	circle(centerX, centerY, distance);

	// Ϊ���������ͼ
	float size_x, size_y;
	size_x = 25.0 * imagesize;
	size_y = 25.0 * imagesize;
	setbkmode(TRANSPARENT);
	IMAGE planet;
	loadimage(&planet, texturePath, size_x, size_y, true);
	transparentimage3(NULL, (int)getOrbitalX(centerX) - size_x / 2, (int)getOrbitalY(centerY) - size_y / 2, &planet);

	// ��ʾ������Ϣ
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	// ��ʾ��������
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)getOrbitalX(centerX) + 8, (int)getOrbitalY(centerY) + 8, s);
}

float Planet::getOrbitalSpeed() const
{
	// ����볤��
	// a = r / (1 - e)
	float semimajorAxis = distanceFromSun / (1 - eccentricity);
	return (2 * M_PI * semimajorAxis) / orbitPeriod;
}

float Planet::getRotationSpeed() const
{
	// ������ת�ٶ�
	// w = 2 * pi / T
	return (2 * M_PI) / rotationPeriod;
}

float Planet::getOrbitalX(float centerX) const
{
	// ����볤��
	// a = r / (1 - e)
	// ������Բ�Ĳ�������
	// x = a * cos(theta) * cos(i)
	float semimajorAxis = distanceFromSun / (1 - eccentricity);
	return centerX + semimajorAxis * std::cos(currentAngle) * std::cos(inclination * M_PI / 180);
}

float Planet::getOrbitalY(float centerY) const
{
	// ����볤��
	// a = r / (1 - e)
	// ������Բ�Ĳ�������
	// y = a * sin(theta) * cos(i)
	float semimajorAxis = distanceFromSun / (1 - eccentricity);
	return centerY + semimajorAxis * std::sin(currentAngle) * std::cos(inclination * M_PI / 180);
}

float Planet::getRadius() const
{
	return radius;
}

float Planet::getDistanceFromSun() const
{
	return distanceFromSun;
}

std::string Planet::getName() const
{
	return name;
}

LPCSTR Planet::getTexturePath() const
{
	return texturePath;
}

float Planet::getCurrentAngle() const
{
	return currentAngle;
}

float Planet::getCurrentRotation() const
{
	return currentRotation;
}

void Planet::setCurrentAngle(float angle)
{
	currentAngle = angle;
}

void Planet::setCurrentRotation(float rotation)
{
	currentRotation = rotation;
}

void Planet::setDistanceFromSun(float distance)
{
	distanceFromSun = distance;
}

void Planet::setRadius(float planetRadius)
{
	radius = planetRadius;
}

void Planet::setOrbitPeriod(float period)
{
	orbitPeriod = period;
}

void Planet::setRotationPeriod(float period)
{
	rotationPeriod = period;
}

void Planet::setInclination(float planetInclination)
{
	inclination = planetInclination;
}

void Planet::setEccentricity(float planetEccentricity)
{
	eccentricity = planetEccentricity;
}

void Planet::setTexturePath(const LPCSTR& planetTexturePath)
{
	texturePath = planetTexturePath;
}

void Planet::setName(const std::string& planetName)
{
	name = planetName;
}

Info& Planet::getPlanetInfo()
{
	return planetInfo;
}