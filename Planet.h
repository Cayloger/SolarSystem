#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <vector>
#include <cmath>
#include <graphics.h>
#include "Info.h"

class Planet {
private:
	std::string name;		// 行星名称
	float distanceFromSun;	// 距离太阳的距离
	float radius;			// 行星半径
	float orbitPeriod;		// 公转周期
	float rotationPeriod;	// 自转周期
	float inclination;		// 轨道倾角
	float eccentricity;		// 轨道离心率
	LPCSTR texturePath;	// 行星纹理路径

	float currentAngle;		// 当前角度
	float currentRotation;	// 当前自转角度

	Info planetInfo;		// 行星信息

public:
	// 构造函数
	Planet(const std::string& planetName, float distance, float planetRadius,
		float orbitPeriod, float rotationPeriod, float planetInclination,
		float planetEccentricity, const LPCSTR planetTexturePath, const std::string infoPath = "PlanetInfo.txt");

	void update(float elapsedTime);					// 更新行星信息
	void draw(float centerX, float centerY) const;	// 绘制行星
	float getOrbitalSpeed() const;					// 获取行星公转速度	
	float getRotationSpeed() const;					// 获取行星自转速度
	float getOrbitalX(float centerX) const;			// 获取行星在X轴上的坐标
	float getOrbitalY(float centerY) const;			// 获取行星在Y轴上的坐标

	float getRadius() const;						// 获取行星半径
	float getDistanceFromSun() const;				// 获取行星距离太阳的距离
	std::string getName() const;					// 获取行星名称
	LPCSTR getTexturePath() const;			// 获取行星纹理路径

	float getCurrentAngle() const;					// 获取当前角度
	float getCurrentRotation() const;				// 获取当前自转角度

	Info& getPlanetInfo();							// 获取行星信息

	void setCurrentAngle(float angle);				// 设置当前角度
	void setCurrentRotation(float rotation);		// 设置当前自转角度

	void setDistanceFromSun(float distance);		// 设置行星距离太阳的距离
	void setRadius(float planetRadius);				// 设置行星半径
	void setOrbitPeriod(float period);				// 设置行星公转周期
	void setRotationPeriod(float period);			// 设置行星自转周期
	void setInclination(float planetInclination);	// 设置行星轨道倾角
	void setEccentricity(float planetEccentricity);	// 设置行星轨道离心率
	void setTexturePath(const LPCSTR& planetTexturePath);	// 设置行星纹理路径

	void setName(const std::string& planetName);	// 设置行星名称

};

#endif
