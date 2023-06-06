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
* ��ʾ����
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
* ��ʾ��ʾ��Ϣ
* @return void
* @param void
* @note
*/
inline void Show() {
	LPCTSTR title = "̫��ϵģ��ϵͳ";
	LPCTSTR tips = "���ּ�1-8ѡ�����ǣ����ּ�0ѡ��̫��������Esc���˳�";
	
	settextcolor(WHITE);
	settextstyle(48, 0, _T("΢���ź�"), 0, 0, FW_HEAVY, 0, 0, 0, DEFAULT_CHARSET, 0, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	outtextxy(1000, 50, title);
	settextcolor(WHITE);
	settextstyle(22, 0, _T("΢���ź�"), 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	outtextxy(930, 100, tips);
}


/*
* ��ʾ����
* @return void
* @param planets: ��������
* @param sun: ̫��
* @note
*/
inline void Display(std::vector<Planet> planets, Star sun) {

	int flag = -1;		// �����жϵ�ǰѡ������ĸ�����
	int tempflag = -1;	// �����жϵ�ǰѡ������ĸ�����
	const int centerx = 400;	// Բ��x����
	const int centery = 400;	// Բ��y����
	while (true)
	{
		BeginBatchDraw();	// ������ͼ

		for (auto& planet : planets)
			planet.update(0.01f);	// ��������λ��

		cleardevice();	// ����
		
		thread t3(Background);	// ��ʾ����
		t3.join();	// �ȴ��߳̽���
		
		sun.draw(centerx, centery);	// ��ʾ̫��


		for (auto& planet : planets) {
			planet.draw(centerx, centery);	// ��ʾ����
		}

		thread t2(Show);	// ��ʾ��ʾ��Ϣ
		t2.join();	// �ȴ��߳̽���

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
		}	// ѡ������

		if (flag >= 1) {
			planets[static_cast<std::vector<Planet, std::allocator<Planet>>::size_type>(flag) - 1].getInfo().Print(830, 150, 670, 900);
		}	// ��ʾ������Ϣ
		else if (flag == 0) {
			sun.getInfo().Print(830, 150, 670, 900);
		}	// ��ʾ������Ϣ

		if (tempflag != flag) {
			tempflag = flag;
			if (flag > 0) {
				cout << planets[static_cast<std::vector<Planet, std::allocator<Planet>>::size_type>(flag) - 1].getInfo() << endl;
			}	// ��ʾ������Ϣ
			else if (flag == 0) {
				cout<<sun.getInfo()<<endl;
			}	// ��ʾ������Ϣ
		}

		EndBatchDraw();	// ����������ͼ

		if (GetAsyncKeyState(VK_ESCAPE))
			break;	// ����Esc���˳�

	}
}

int main()
{
	initgraph(1600, 900);	// ��ʼ��ͼ�ν���

	vector<Planet> planets;	// ��������
	planets.emplace_back("Mercury", 35, 2, 88, 58, 7, 0.205, 25, _T("Image//Mercury.png"));
	planets.emplace_back("Venus", 85, 6, 225, 243, 3.4, 0.007, 25, _T("Image//Venus.png"));
	planets.emplace_back("Earth", 125, 6, 365, 1, 0, 0.017, 25, _T("Image//Earth.png"));
	planets.emplace_back("Mars", 155, 3, 687, 1, 1.9, 0.093, 25, _T("Image//Mars.png"));
	planets.emplace_back("Jupiter", 205, 69, 4333, 0.4, 1.3, 0.048, 25, _T("Image//Jupiter.png"));
	planets.emplace_back("Saturn", 245, 58, 10759, 0.4, 2.5, 0.056, 27,  _T("Image//Saturn.png"));
	planets.emplace_back("Uranus", 290, 25, 30688, 0.7, 0.8, 0.047, 35, _T("Image//Uranus.png"));
	planets.emplace_back("Neptune", 345, 24, 60182, 0.7, 1.8, 0.009, 25, _T("Image//Neptune.png"));

	Star sun("Sun", 218, 0, 50, _T("Image//Sun.png"));	// ̫��

	thread t1(Display, planets, sun);		// ��ʾ����
	t1.join();	// �ȴ��߳̽���

	closegraph();	// �ر�ͼ�ν���
	return 0;
}
