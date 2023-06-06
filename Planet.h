#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <vector>
#include <cmath>
#include <graphics.h>
#include "Info.h"
#include "AstronomicalObject.h"

class Planet : public AstronomicalObject{
private:
	//std::string name;		// 行星名称
	double distanceFromSun;	// 距离太阳的距离
	//double radius;			// 行星半径
	double orbitPeriod;		// 公转周期
	double rotationPeriod;	// 自转周期
	double inclination;		// 轨道倾角
	double eccentricity;		// 轨道离心率
	//LPCSTR texturePath;	// 行星纹理路径

	double currentAngle;		// 当前角度
	double currentRotation;	// 当前自转角度
	//double imagesize;		// 图片大小

	//Info planetInfo;		// 行星信息

public:
	// 构造函数
	Planet(const std::string& planetName, double distance, double planetRadius,
		double orbitPeriod, double rotationPeriod, double planetInclination,
		double planetEccentricity, double isize, const LPCSTR planetTexturePath, 
		const std::string infoPath = "Information//PlanetInfo.txt");

	void update(double elapsedTime);					// 更新行星信息
	void draw(double centerX, double centerY);	// 绘制行星
	double getOrbitalSpeed() const;					// 获取行星公转速度	
	double getRotationSpeed() const;					// 获取行星自转速度
	double getOrbitalX(double centerX) const;			// 获取行星在X轴上的坐标
	double getOrbitalY(double centerY) const;			// 获取行星在Y轴上的坐标

	double getDistanceFromSun() const;				// 获取行星距离太阳的距离

	double getCurrentAngle() const;					// 获取当前角度
	double getCurrentRotation() const;				// 获取当前自转角度

	void setCurrentAngle(double angle);				// 设置当前角度
	void setCurrentRotation(double rotation);		// 设置当前自转角度

	void setDistanceFromSun(double distance);		// 设置行星距离太阳的距离
	void setOrbitPeriod(double period);				// 设置行星公转周期
	void setRotationPeriod(double period);			// 设置行星自转周期
	void setInclination(double planetInclination);	// 设置行星轨道倾角
	void setEccentricity(double planetEccentricity);	// 设置行星轨道离心率
};

#endif
