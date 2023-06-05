#include "Planet.h"
#include "Info.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846

Planet::Planet(const std::string& planetName, float distance, float planetRadius,
	float orbitPeriod, float rotationPeriod, float planetInclination,
	float planetEccentricity, const LPCSTR planetTexturePath, const std::string infoPath) :
	name(planetName), distanceFromSun(distance), radius(planetRadius), orbitPeriod(orbitPeriod),
	rotationPeriod(rotationPeriod), inclination(planetInclination), eccentricity(planetEccentricity),
	texturePath(planetTexturePath), currentAngle(0), currentRotation(0), planetInfo(infoPath, planetName) {}

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

	// ������
	setfillcolor(CYAN);
	setlinecolor(CYAN);
	fillcircle(getOrbitalX(centerX), getOrbitalY(centerY), 7);

	// Ϊ���������ͼ
	setbkmode(TRANSPARENT);
	IMAGE planet;
	loadimage(&planet, texturePath, 20, 20, true);
	putimage((int)getOrbitalX(centerX) - 10, (int)getOrbitalY(centerY) - 10, &planet);


	// ��ʾ������Ϣ
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	// ��ʾ��������
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)getOrbitalX(centerX) + 5, (int)getOrbitalY(centerY) + 5, s);
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