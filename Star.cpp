#include "Star.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, const std::wstring& starTexturePath, std::string infoPath)
	: name(starName),
	radius(starRadius),
	rotationPeriod(starRotationPeriod),
	texturePath(starTexturePath),
	currentRotation(0),
	starInfo(infoPath, starName) {}

void Star::update(double elapsedTime)
{
	// 更新星球自转角度
	currentRotation += getRotationSpeed() * elapsedTime;
}

void Star::draw(double centerX, double centerY) const
{
	// 绘制星球
	setfillcolor(RED);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 1);
	fillcircle(centerX, centerY, radius);

	// 显示星球名字
	settextcolor(WHITE);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	outtextxy((int)centerX - 10, (int)centerY - 8, s);
}

double Star::getRotationSpeed() const
{
	// 计算自转速度
	return (2 * M_PI) / rotationPeriod;
}

double Star::getRadius() const
{
	return radius;
}

std::string Star::getName() const
{
	return name;
}

std::wstring Star::getTexturePath() const
{
	return texturePath;
}

double Star::getCurrentRotation() const
{
	return currentRotation;
}

void Star::setCurrentRotation(double rotation)
{
	currentRotation = rotation;
}

void Star::setRadius(double starRadius)
{
	radius = starRadius;
}

void Star::setRotationPeriod(double period)
{
	rotationPeriod = period;
}

void Star::setTexturePath(const std::wstring& starTexturePath)
{
	texturePath = starTexturePath;
}

void Star::setName(const std::string& starName)
{
	name = starName;
}

Info& Star::getStarInfo()
{
	return starInfo;
}