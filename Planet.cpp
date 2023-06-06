#include "Planet.h"
#include "Info.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846

/*
* 构造函数
* planetName: 行星名字
* distance: 行星距离太阳的距离
* planetRadius: 行星半径
* orbitPeriod: 行星公转周期
* rotationPeriod: 行星自转周期
* planetInclination: 行星轨道倾角
*/
Planet::Planet(const std::string& planetName, double distance, double planetRadius,
	double orbitPeriod, double rotationPeriod, double planetInclination,
	double planetEccentricity, double isize, const LPCSTR planetTexturePath, const std::string infoPath)
	: AstronomicalObject(planetName, planetRadius, isize, planetTexturePath, infoPath)
{
	this->distanceFromSun = distance;
	this->orbitPeriod = orbitPeriod;
	this->rotationPeriod = rotationPeriod;
	this->inclination = planetInclination;
	this->eccentricity = planetEccentricity;
	this->currentAngle = 0;
	this->currentRotation = 0;
}

void Planet::update(double elapsedTime)
{
	// 更新角度
	// θ = ω * t
	// ω = 2 * π / T
	// θ = 2 * π * t / T
	currentAngle += getOrbitalSpeed() * elapsedTime;
	currentRotation += getRotationSpeed() * elapsedTime;
}

void Planet::draw(double centerX, double centerY)
{
	// 计算行星距离太阳的距离
	double distance;
	distance = distanceFromSun / (1 - eccentricity);
	
	// 画轨道
	setlinecolor(WHITE);
	setlinestyle(PS_JOIN_ROUND | PS_ENDCAP_ROUND, 2);
	circle(centerX, centerY, distance);

	// 为行星添加贴图
	AstronomicalObject::draw((int) getOrbitalX(centerX), (int) getOrbitalY(centerY));

	// 显示行星信息
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	// 显示行星名字
	_bstr_t bstr(getName().c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)getOrbitalX(centerX) + 8, (int)getOrbitalY(centerY) + 8, s);
}

double Planet::getOrbitalSpeed() const
{
	// 计算半长轴
	// a = r / (1 - e)
	double semimajorAxis = distanceFromSun / (1 - eccentricity);
	return (2 * M_PI * semimajorAxis) / orbitPeriod;
}

double Planet::getRotationSpeed() const
{
	// 计算自转速度
	// w = 2 * pi / T
	return (2 * M_PI) / rotationPeriod;
}

double Planet::getOrbitalX(double centerX) const
{
	// 计算半长轴
	// a = r / (1 - e)
	// 计算椭圆的参数方程
	// x = a * cos(theta) * cos(i)
	double semimajorAxis = distanceFromSun / (1 - eccentricity);
	return centerX + semimajorAxis * std::cos(currentAngle) * std::cos(inclination * M_PI / 180);
}

double Planet::getOrbitalY(double centerY) const
{
	// 计算半长轴
	// a = r / (1 - e)
	// 计算椭圆的参数方程
	// y = a * sin(theta) * cos(i)
	double semimajorAxis = distanceFromSun / (1 - eccentricity);
	return centerY + semimajorAxis * std::sin(currentAngle) * std::cos(inclination * M_PI / 180);
}

//double Planet::getRadius() const
//{
//	return radius;
//}

double Planet::getDistanceFromSun() const
{
	return distanceFromSun;
}

double Planet::getCurrentAngle() const
{
	return currentAngle;
}

double Planet::getCurrentRotation() const
{
	return currentRotation;
}

void Planet::setCurrentAngle(double angle)
{
	currentAngle = angle;
}

void Planet::setCurrentRotation(double rotation)
{
	currentRotation = rotation;
}

void Planet::setDistanceFromSun(double distance)
{
	distanceFromSun = distance;
}

void Planet::setOrbitPeriod(double period)
{
	orbitPeriod = period;
}

void Planet::setRotationPeriod(double period)
{
	rotationPeriod = period;
}

void Planet::setInclination(double planetInclination)
{
	inclination = planetInclination;
}

void Planet::setEccentricity(double planetEccentricity)
{
	eccentricity = planetEccentricity;
}
