#pragma once
#include <string>
#include <graphics.h>
#include "Info.h"
using namespace std;
class AstronomicalObject
{
private:
	std::string name;		// ��������
	double radius;			// ���ǰ뾶
	double imagesize;		// ����ͼƬ��С
	LPCSTR texturePath;		// ��������·��
	Info ObjectInfo;			// ������Ϣ
public:
	AstronomicalObject();	// Ĭ�Ϲ��캯��
	AstronomicalObject(const std::string& starName, double starRadius, double size, const LPCSTR& starTexturePath, string infoPath);
	void draw(double centerX, double centerY);	// ��������
	double getRadius() const;						// ��ȡ����뾶
	double getImageSize() const;					// ��ȡ����ͼƬ��С
	std::string getName() const;					// ��ȡ��������
	LPCSTR getTexturePath() const;					// ��ȡ��������·��
	void setRadius(double starRadius);				// ��������뾶
	void setImageSize(double starImageSize);		// ��������ͼƬ��С
	void setTexturePath(const LPCSTR& starTexturePath);	// ������������·��
	void setName(const std::string& starName);		// ������������
	void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);	// ͸����ͼ
	Info& getInfo();							// ��ȡ������Ϣ
};

