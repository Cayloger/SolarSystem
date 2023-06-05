#pragma once
#include <string>
#include "Info.h"
class Star
{
private:
	std::string name;		// 星球名称
	double radius;			// 星球半径
	double rotationPeriod;	// 自转周期
	double currentRotation;	// 当前自转角度
	LPCSTR texturePath;	// 星球纹理路径
	Info starInfo;			// 星球信息
public:
	// 构造函数
	Star(const std::string& starName, double starRadius, double starRotationPeriod, const LPCSTR starTexturePath, string infoPath = "StarInfo.txt");
	void update(double elapsedTime);					// 更新星球自转角度
	void draw(double centerX, double centerY) const;	// 绘制星球
	double getRotationSpeed() const;					// 获取星球自转速度	
	double getRadius() const;						// 获取星球半径
	std::string getName() const;					// 获取星球名称
	LPCSTR getTexturePath() const;			// 获取星球纹理路径
	double getCurrentRotation() const;				// 获取星球当前自转角度
	void setCurrentRotation(double rotation);		// 设置星球当前自转角度
	void setRadius(double starRadius);				// 设置星球半径
	void setRotationPeriod(double period);			// 设置星球自转周期
	void setTexturePath(const LPCSTR& starTexturePath);	// 设置星球纹理路径
	void setName(const std::string& starName);		// 设置星球名称
	Info& getStarInfo();							// 获取星球信息
};

