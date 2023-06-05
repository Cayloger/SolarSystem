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
	// 更新角度
	// θ = ω * t
	// ω = 2 * π / T
	// θ = 2 * π * t / T
	currentAngle += getOrbitalSpeed() * elapsedTime;
	currentRotation += getRotationSpeed() * elapsedTime;
}

void Planet::draw(float centerX, float centerY) const
{
	// 计算行星距离太阳的距离
	float distance;
	distance = distanceFromSun / (1 - eccentricity);
	
	// 画轨道
	setlinecolor(WHITE);
	setlinestyle(PS_JOIN_ROUND | PS_ENDCAP_ROUND, 2);
	circle(centerX, centerY, distance);

	// 画行星
	setfillcolor(CYAN);
	setlinecolor(CYAN);
	fillcircle(getOrbitalX(centerX), getOrbitalY(centerY), 7);

	// 为行星添加贴图
	setbkmode(TRANSPARENT);
	IMAGE planet;
	loadimage(&planet, texturePath, 20, 20, true);
	putimage((int)getOrbitalX(centerX) - 10, (int)getOrbitalY(centerY) - 10, &planet);


	// 显示行星信息
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	// 显示行星名字
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)getOrbitalX(centerX) + 5, (int)getOrbitalY(centerY) + 5, s);
}

float Planet::getOrbitalSpeed() const
{
	// 计算半长轴
	// a = r / (1 - e)
	float semimajorAxis = distanceFromSun / (1 - eccentricity);
	return (2 * M_PI * semimajorAxis) / orbitPeriod;
}

float Planet::getRotationSpeed() const
{
	// 计算自转速度
	// w = 2 * pi / T
	return (2 * M_PI) / rotationPeriod;
}

float Planet::getOrbitalX(float centerX) const
{
	// 计算半长轴
	// a = r / (1 - e)
	// 计算椭圆的参数方程
	// x = a * cos(theta) * cos(i)
	float semimajorAxis = distanceFromSun / (1 - eccentricity);
	return centerX + semimajorAxis * std::cos(currentAngle) * std::cos(inclination * M_PI / 180);
}

float Planet::getOrbitalY(float centerY) const
{
	// 计算半长轴
	// a = r / (1 - e)
	// 计算椭圆的参数方程
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