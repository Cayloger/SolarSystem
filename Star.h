#pragma once
#include <string>
#include "Info.h"
#include "AstronomicalObject.h"
class Star : public AstronomicalObject
{
private:
	double rotationPeriod;	// 自转周期
	double currentRotation;	// 当前自转角度
public:
	Star(const std::string& starName, double starRadius, double starRotationPeriod, double isize, const LPCSTR starTexturePath, string infoPath = "Information//StarInfo.txt");	// 构造函数
	void update(double elapsedTime);					// 更新星球自转角度
	void draw(double centerX, double centerY);	// 绘制星球
	double getRotationSpeed() const;					// 获取星球自转速度	
	double getCurrentRotation() const;				// 获取星球当前自转角度
	void setCurrentRotation(double rotation);		// 设置星球当前自转角度
	void setRotationPeriod(double period);			// 设置星球自转周期
};

