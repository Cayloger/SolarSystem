#include "Star.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, const LPCSTR starTexturePath, std::string infoPath)
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
	setfillcolor(YELLOW);
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 1);
	fillcircle(centerX, centerY, radius*1.3);

	// 显示星球名字
	settextcolor(BLACK);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	RECT rect{ centerX - 20, centerY - 20, centerX + 20, centerY + 20 };
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	drawtext(s, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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

LPCSTR Star::getTexturePath() const
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

void Star::setTexturePath(const LPCSTR& starTexturePath)
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