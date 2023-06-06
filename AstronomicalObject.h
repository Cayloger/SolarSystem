#pragma once
#include <string>
#include <graphics.h>
#include "Info.h"
using namespace std;
class AstronomicalObject
{
private:
	std::string name;		// 星球名称
	double radius;			// 行星半径
	double imagesize;		// 星球图片大小
	LPCSTR texturePath;		// 星球纹理路径
	Info ObjectInfo;			// 星球信息
public:
	AstronomicalObject();	// 默认构造函数
	AstronomicalObject(const std::string& starName, double starRadius, double size, const LPCSTR& starTexturePath, string infoPath);
	void draw(double centerX, double centerY);	// 绘制星球
	double getRadius() const;						// 获取星球半径
	double getImageSize() const;					// 获取星球图片大小
	std::string getName() const;					// 获取星球名称
	LPCSTR getTexturePath() const;					// 获取星球纹理路径
	void setRadius(double starRadius);				// 设置星球半径
	void setImageSize(double starImageSize);		// 设置星球图片大小
	void setTexturePath(const LPCSTR& starTexturePath);	// 设置星球纹理路径
	void setName(const std::string& starName);		// 设置星球名称
	void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);	// 透明绘图
	Info& getInfo();							// 获取星球信息
};

