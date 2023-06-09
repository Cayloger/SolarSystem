#include "AstronomicalObject.h"
#include <graphics.h>
#include <iostream>
#pragma comment( lib, "MSIMG32.LIB")

AstronomicalObject::AstronomicalObject()
{
	this->name = "未命名";
	this->radius = 0;
	this->imagesize = 0;
	this->texturePath = "";
	this->ObjectInfo = Info();
}

AstronomicalObject::AstronomicalObject(const std::string& starName, double starRadius, double size, const LPCSTR& starTexturePath, string infoPath)
{
	this->name = starName;
	this->radius = starRadius;
	this->imagesize = size;
	this->texturePath = starTexturePath;
	this->ObjectInfo = Info(infoPath, name);
}

void AstronomicalObject::transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	/*
	* 参数说明：
	* dstimg：目标图像，如果为NULL，则默认为当前窗口
	* x：目标图像的x坐标
	* y：目标图像的y坐标
	* srcimg：源图像
	*/
	HDC dstDC = GetImageHDC(dstimg);	//获取目标图像的句柄
	HDC srcDC = GetImageHDC(srcimg);	//获取源图像的句柄
	int w = srcimg->getwidth();			//获取源图像的宽度
	int h = srcimg->getheight();		//获取源图像的高度
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };	//设置混合函数
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);		//混合绘图
}

void AstronomicalObject::draw(double centerX, double centerY)
{
	/*
	* 参数说明：
	* centerX：星球中心的x坐标
	* centerY：星球中心的y坐标
	*/
	IMAGE outline;
	loadimage(&outline, texturePath, imagesize, imagesize, true);
	transparentimage(NULL, (int)centerX - imagesize / 2, (int)centerY - imagesize / 2, &outline);
}

double AstronomicalObject::getRadius() const
{
	return radius;
}

double AstronomicalObject::getImageSize() const
{
	return imagesize;
}

std::string AstronomicalObject::getName() const
{
	return name;
}

LPCSTR AstronomicalObject::getTexturePath() const
{
	return texturePath;
}

void AstronomicalObject::setRadius(double starRadius)
{
	this->radius = starRadius;
}

void AstronomicalObject::setImageSize(double starImageSize)
{
	this->imagesize = starImageSize;
}

void AstronomicalObject::setTexturePath(const LPCSTR& starTexturePath)
{
	this->texturePath = starTexturePath;
}

void AstronomicalObject::setName(const std::string& starName)
{
	this->name = starName;
}

Info& AstronomicalObject::getInfo()
{
	return ObjectInfo;
}