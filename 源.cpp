#include <iostream>
#include <graphics.h>
#include <vector>
#include <string>
#include "Planet.h"
#include "Star.h"
#include "Info.h"
#include <thread>
using namespace std;

/*
* 显示背景
* @return void
* @param void
* @note
*/
inline void Background() {
	setbkmode(TRANSPARENT);
	IMAGE background;
	loadimage(&background, _T("Image//background.jpg"), 1600, 900, true);
	putimage(0, 0, &background);
}


/*
* 显示提示信息
* @return void
* @param void
* @note
*/
inline void Show() {
	LPCTSTR title = "太阳系模拟系统";
	LPCTSTR tips = "数字键1-8选择行星，数字键0选择太阳，按下Esc键退出";
	
	settextcolor(WHITE);
	settextstyle(48, 0, _T("微软雅黑"), 0, 0, FW_HEAVY, 0, 0, 0, DEFAULT_CHARSET, 0, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	outtextxy(1000, 50, title);
	settextcolor(WHITE);
	settextstyle(22, 0, _T("微软雅黑"), 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	outtextxy(930, 100, tips);
}


/*
* 显示行星
* @return void
* @param planets: 行星数组
* @param sun: 太阳
* @note
*/
inline void Display(std::vector<Planet> planets, Star sun) {

	int flag = -1;		// 用于判断当前选择的是哪个行星
	int tempflag = -1;	// 用于判断当前选择的是哪个行星
	const int centerx = 400;	// 圆心x坐标
	const int centery = 400;	// 圆心y坐标
	while (true)
	{
		BeginBatchDraw();	// 批量绘图

		for (auto& planet : planets)
			planet.update(0.01f);	// 更新行星位置

		cleardevice();	// 清屏
		
		thread t3(Background);	// 显示背景
		t3.join();	// 等待线程结束
		
		sun.draw(centerx, centery);	// 显示太阳


		for (auto& planet : planets) {
			planet.draw(centerx, centery);	// 显示行星
		}

		thread t2(Show);	// 显示提示信息
		t2.join();	// 等待线程结束

		if (GetAsyncKeyState(VK_NUMPAD1) || GetAsyncKeyState('1')) {
			flag = 1;
		}
		else if (GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState('2')) {
			flag = 2;
		}
		else if (GetAsyncKeyState(VK_NUMPAD3) || GetAsyncKeyState('3')) {
			flag = 3;
		}
		else if (GetAsyncKeyState(VK_NUMPAD4) || GetAsyncKeyState('4')) {
			flag = 4;
		}
		else if (GetAsyncKeyState(VK_NUMPAD5) || GetAsyncKeyState('5')) {
			flag = 5;
		}
		else if (GetAsyncKeyState(VK_NUMPAD6) || GetAsyncKeyState('6')) {
			flag = 6;
		}
		else if (GetAsyncKeyState(VK_NUMPAD7) || GetAsyncKeyState('7')) {
			flag = 7;
		}
		else if (GetAsyncKeyState(VK_NUMPAD8) || GetAsyncKeyState('8')) {
			flag = 8;
		}
		else if (GetAsyncKeyState(VK_NUMPAD0) || GetAsyncKeyState('0')) {
			flag = 0;
		}	// 选择天体

		if (flag >= 1) {
			planets[static_cast<std::vector<Planet, std::allocator<Planet>>::size_type>(flag) - 1].getInfo().Print(830, 150, 670, 900);
		}	// 显示行星信息
		else if (flag == 0) {
			sun.getInfo().Print(830, 150, 670, 900);
		}	// 显示恒星信息

		if (tempflag != flag) {
			tempflag = flag;
			if (flag > 0) {
				cout << planets[static_cast<std::vector<Planet, std::allocator<Planet>>::size_type>(flag) - 1].getInfo() << endl;
			}	// 显示行星信息
			else if (flag == 0) {
				cout<<sun.getInfo()<<endl;
			}	// 显示恒星信息
		}

		EndBatchDraw();	// 结束批量绘图

		if (GetAsyncKeyState(VK_ESCAPE))
			break;	// 按下Esc键退出

	}
}

int main()
{
	initgraph(1600, 900);	// 初始化图形界面

	vector<Planet> planets;	// 行星数组
	planets.emplace_back("Mercury", 35, 2, 88, 58, 7, 0.205, 25, _T("Image//Mercury.png"));
	planets.emplace_back("Venus", 85, 6, 225, 243, 3.4, 0.007, 25, _T("Image//Venus.png"));
	planets.emplace_back("Earth", 125, 6, 365, 1, 0, 0.017, 25, _T("Image//Earth.png"));
	planets.emplace_back("Mars", 155, 3, 687, 1, 1.9, 0.093, 25, _T("Image//Mars.png"));
	planets.emplace_back("Jupiter", 205, 69, 4333, 0.4, 1.3, 0.048, 25, _T("Image//Jupiter.png"));
	planets.emplace_back("Saturn", 245, 58, 10759, 0.4, 2.5, 0.056, 27,  _T("Image//Saturn.png"));
	planets.emplace_back("Uranus", 290, 25, 30688, 0.7, 0.8, 0.047, 35, _T("Image//Uranus.png"));
	planets.emplace_back("Neptune", 345, 24, 60182, 0.7, 1.8, 0.009, 25, _T("Image//Neptune.png"));

	Star sun("Sun", 218, 0, 50, _T("Image//Sun.png"));	// 太阳

	thread t1(Display, planets, sun);		// 显示行星
	t1.join();	// 等待线程结束

	closegraph();	// 关闭图形界面
	return 0;
}
