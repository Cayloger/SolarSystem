#pragma once
#include "Star.h"
#include <graphics.h>
#include <comdef.h>
#pragma comment( lib, "MSIMG32.LIB")
#define M_PI 3.14159265358979323846

/*
* ͸����ͼ����
* dstimg: Ŀ��ͼ��
* x, y: Ŀ��ͼ������Ͻ�����
* srcimg: Դͼ��
*/
void transparentimage4(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //�°�png
{
	HDC dstDC = GetImageHDC(dstimg);	//��ȡĿ��ͼ��ľ��
	HDC srcDC = GetImageHDC(srcimg);	//��ȡԴͼ��ľ��
	int w = srcimg->getwidth();			//��ȡԴͼ��Ŀ��
	int h = srcimg->getheight();		//��ȡԴͼ��ĸ߶�
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };	//���û�Ϻ���
	/*
	* ��Ϻ�������˵����
	* 1. ��ϲ������룬ָ����ν�Դ��Ŀ�����ɫ���ݽ��л��
	* 2. Դ��Ŀ���ϵ�͸����
	* 3. Դ��Ŀ���ϵ�͸����
	* 4. ��ϲ������룬ָ����ν�Դ��Ŀ���alpha���ݽ��л��
	*/
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);		//��ϻ�ͼ
}

/*
* ���캯��
* starName: ��������
* starRadius: ����뾶
* starRotationPeriod: ������ת����
* starTexturePath: ��������·��
* infoPath: ������Ϣ·��
*/
Star::Star(const std::string& starName, double starRadius, double starRotationPeriod, const LPCSTR starTexturePath, std::string infoPath)
	: name(starName),
	radius(starRadius),
	rotationPeriod(starRotationPeriod),
	texturePath(starTexturePath),
	currentRotation(0),
	starInfo(infoPath, starName) {}

/*
* ��������״̬
* elapsedTime: ��һ֡����ǰ֡��ʱ����
*/
void Star::update(double elapsedTime)
{
	// ����������ת�Ƕ�
	currentRotation += getRotationSpeed() * elapsedTime;
}

/*
* ��������
* centerX: �������ĵ�x����
* centerY: �������ĵ�y����
* 
* ˵������������Ŀ��Ӧ��Ϊ�뾶������
*/
void Star::draw(double centerX, double centerY) const
{
	// ������������
	IMAGE img;
	loadimage(&img, texturePath, radius, radius, true);
	transparentimage4(NULL, centerX - radius / 2, centerY - radius / 2, &img);


	// ��ʾ��������
	settextcolor(RED);
	settextstyle(15, 0, _T("Arial"), 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	
	RECT rect{ centerX - 20, centerY - 20, centerX + 20, centerY + 20 };
	_bstr_t bstr(name.c_str());
	LPTSTR s = (LPTSTR)bstr;
	drawtext(s, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/*
* ��ȡ������ת�ٶ�
* 
* ˵������ת�ٶ�Ϊ������
* 
* ����ֵ��������ת�ٶ�
*/
double Star::getRotationSpeed() const
{
	// ������ת�ٶ�
	// 2 * PI / T
	return (2 * M_PI) / rotationPeriod;
}

/*
* ��ȡ����뾶
* 
* ����ֵ������뾶
* 
* ˵�����뾶��λΪ����
*/
double Star::getRadius() const
{
	return radius;
}

/*
* ��ȡ������ת����
* 
* ����ֵ��������ת����
* 
* ˵�������ڵ�λΪ��
*/
std::string Star::getName() const
{
	return name;
}

/*
* ��ȡ��������·��
* 
* ����ֵ����������·��
* 
* ˵��������·��Ϊ���·��
*/
LPCSTR Star::getTexturePath() const
{
	return texturePath;
}

/*
* ��ȡ������ת�Ƕ�
* 
* ����ֵ��������ת�Ƕ�
* 
* ˵�����Ƕȵ�λΪ����
*/
double Star::getCurrentRotation() const
{
	return currentRotation;
}

/*
* ����������ת�Ƕ�
* 
* rotation: ������ת�Ƕ�
* 
* ˵�����Ƕȵ�λΪ����
*/
void Star::setCurrentRotation(double rotation)
{
	currentRotation = rotation;
}

/*
* ��������뾶
* 
* starRadius: ����뾶
* 
* ˵�����뾶��λΪ����
*/
void Star::setRadius(double starRadius)
{
	radius = starRadius;
}

/*
* ����������ת����
* 
* period: ������ת����
* 
* ˵�������ڵ�λΪ��
*/
void Star::setRotationPeriod(double period)
{
	rotationPeriod = period;
}

/*
* ������������·��
* 
* starTexturePath: ��������·��
* 
* ˵��������·��Ϊ���·��
*/
void Star::setTexturePath(const LPCSTR& starTexturePath)
{
	texturePath = starTexturePath;
}

/*
* ������������
* 
* starName: ��������
* 
* ˵��������Ϊstring����
*/
void Star::setName(const std::string& starName)
{
	name = starName;
}

/*
* ��ȡ������Ϣ
* 
* ����ֵ��������Ϣ
* 
* ˵������ϢΪInfo����
*/
Info& Star::getStarInfo()
{
	return starInfo;
}