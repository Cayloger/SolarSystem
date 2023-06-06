#pragma once
#include "Star.h"
#include <graphics.h>
#include <comdef.h>
#define M_PI 3.14159265358979323846

/*
* 构造函数
* starName: 星球名字
* starRadius: 星球半径
* starRotationPeriod: 星球自转周期
* starTexturePath: 星球纹理路径
* infoPath: 星球信息路径
*/
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, double isize, const LPCSTR starTexturePath, std::string infoPath)
	: AstronomicalObject(starName, starRadius, isize, starTexturePath, infoPath)
{
	this->rotationPeriod = starRotationPeriod;
	this->currentRotation = 0;
}

/*
* 更新星球状态
* elapsedTime: 上一帧到当前帧的时间间隔
*/
void Star::update(double elapsedTime)
{
	// 更新星球自转角度
	currentRotation += getRotationSpeed() * elapsedTime;
}

/*
* 绘制星球
* centerX: 星球中心点x坐标
* centerY: 星球中心点y坐标
* 
* 说明：星球纹理的宽高应该为半径的两倍
*/
void Star::draw(double centerX, double centerY)
{
	AstronomicalObject::draw(centerX, centerY);

	// 显示星球名字
	settextcolor(RED);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	RECT rect{ centerX - 20, centerY - 20, centerX + 20, centerY + 20 };
	_bstr_t bstr(getName().c_str());
	LPTSTR s = (LPTSTR)bstr;
	drawtext(s, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/*
* 获取星球自转速度
* 
* 说明：自转速度为弧度制
* 
* 返回值：星球自转速度
*/
double Star::getRotationSpeed() const
{
	// 计算自转速度
	// 2 * PI / T
	return (2 * M_PI) / rotationPeriod;
}

/*
* 获取星球自转角度
* 
* 返回值：星球自转角度
* 
* 说明：角度单位为弧度
*/
double Star::getCurrentRotation() const
{
	return currentRotation;
}

/*
* 设置星球自转角度
* 
* rotation: 星球自转角度
* 
* 说明：角度单位为弧度
*/
void Star::setCurrentRotation(double rotation)
{
	currentRotation = rotation;
}

/*
* 设置星球自转周期
* 
* period: 星球自转周期
* 
* 说明：周期单位为秒
*/
void Star::setRotationPeriod(double period)
{
	rotationPeriod = period;
}
