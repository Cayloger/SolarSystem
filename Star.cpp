#pragma once
#include "Star.h"
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
void transparentimage4(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //新版png
{
	HDC dstDC = GetImageHDC(dstimg);	//获取目标图像的句柄
	HDC srcDC = GetImageHDC(srcimg);	//获取源图像的句柄
	int w = srcimg->getwidth();			//获取源图像的宽度
	int h = srcimg->getheight();		//获取源图像的高度
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };	//设置混合函数
	/*
	* 混合函数参数说明：
	* 1. 混合操作代码，指定如何将源和目标的颜色数据进行混合
	* 2. 源和目标混合的透明度
	* 3. 源和目标混合的透明度
	* 4. 混合操作代码，指定如何将源和目标的alpha数据进行混合
	*/
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);		//混合绘图
}

/*
* 构造函数
* starName: 星球名字
* starRadius: 星球半径
* starRotationPeriod: 星球自转周期
* starTexturePath: 星球纹理路径
* infoPath: 星球信息路径
*/
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, const LPCSTR starTexturePath, std::string infoPath)
	: name(starName),
	radius(starRadius),
	rotationPeriod(starRotationPeriod),
	texturePath(starTexturePath),
	currentRotation(0),
	starInfo(infoPath, starName) {}

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
void Star::draw(double centerX, double centerY) const
{
	// 绘制星球纹理
	IMAGE img;
	loadimage(&img, texturePath, radius, radius, true);
	transparentimage4(NULL, centerX - radius / 2, centerY - radius / 2, &img);


	// 显示星球名字
	settextcolor(RED);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	RECT rect{ centerX - 20, centerY - 20, centerX + 20, centerY + 20 };
	_bstr_t bstr(name.c_str());
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
* 获取星球半径
* 
* 返回值：星球半径
* 
* 说明：半径单位为像素
*/
double Star::getRadius() const
{
	return radius;
}

/*
* 获取星球自转周期
* 
* 返回值：星球自转周期
* 
* 说明：周期单位为秒
*/
std::string Star::getName() const
{
	return name;
}

/*
* 获取星球纹理路径
* 
* 返回值：星球纹理路径
* 
* 说明：纹理路径为相对路径
*/
LPCSTR Star::getTexturePath() const
{
	return texturePath;
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
* 设置星球半径
* 
* starRadius: 星球半径
* 
* 说明：半径单位为像素
*/
void Star::setRadius(double starRadius)
{
	radius = starRadius;
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

/*
* 设置星球纹理路径
* 
* starTexturePath: 星球纹理路径
* 
* 说明：纹理路径为相对路径
*/
void Star::setTexturePath(const LPCSTR& starTexturePath)
{
	texturePath = starTexturePath;
}

/*
* 设置星球名字
* 
* starName: 星球名字
* 
* 说明：名字为string类型
*/
void Star::setName(const std::string& starName)
{
	name = starName;
}

/*
* 获取星球信息
* 
* 返回值：星球信息
* 
* 说明：信息为Info类型
*/
Info& Star::getStarInfo()
{
	return starInfo;
}