#pragma once
#include "Planet.h"
#include "Info.h"
#include <graphics.h>
#include <comdef.h>
#pragma comment( lib, "MSIMG32.LIB")
#define M_PI 3.14159265358979323846

/*
* 透明绘图函数
* dstimg: 目标图像
* x, y: 目标图像的左上角坐标
* srcimg: 源图像
*/
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);	//获取目标图像的句柄
	HDC srcDC = GetImageHDC(srcimg);	//获取源图像的句柄
	int w = srcimg->getwidth();			//获取源图像的宽度
	int h = srcimg->getheight();		//获取源图像的高度
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };	//设置混合函数
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);		//混合绘图
}

/*
* 构造函数
* planetName: 行星名字
* distance: 行星距离太阳的距离
* planetRadius: 行星半径
* orbitPeriod: 行星公转周期
* rotationPeriod: 行星自转周期
* planetInclination: 行星轨道倾角
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

	// 为行星添加贴图
	float size_x, size_y;
	size_x = 25.0 * imagesize;
	size_y = 25.0 * imagesize;
	setbkmode(TRANSPARENT);
	IMAGE planet;
	loadimage(&planet, texturePath, size_x, size_y, true);
	transparentimage3(NULL, (int)getOrbitalX(centerX) - size_x / 2, (int)getOrbitalY(centerY) - size_y / 2, &planet);

	// 显示行星信息
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	// 显示行星名字
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)getOrbitalX(centerX) + 8, (int)getOrbitalY(centerY) + 8, s);
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