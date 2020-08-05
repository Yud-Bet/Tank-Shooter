#include "my_console.h"
#include "g_map.h"
#include "Object.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"
using namespace std::this_thread;
using namespace std::chrono;

int main()
{
    srand(time(0));
    ShowConsoleCursor(false);
	g_map m1(20,20);
	m1.print();
    
    //object initialization
    Object a(1, 1);
    Object b(17, 17);
    b.setDirection(2);
    BulletLine b_bullet{ b.getPos(), b.getDirection(), m1 };
    a.print();
    a.setDirection(4);
    b.print();
    
    while (true) {
        //obj a
        if (!m1.isTrungMap(a.ifMove())) {
            a.move();
            a.setDirection(Randoms(1, 10));
        }
        else a.setDirection(Randoms(1, 10));
        
        b_bullet.clr();
        b_bullet.move(m1);
        int ch = inputKey();
        if (ch == 32)
        {
            b_bullet.refresh(b.getPos(), b.getDirection(), m1);
        }
        else if (ch == KEY_UP)
        {
            b.setDirection(2);
            if(!m1.isTrungMap(b.ifMove())) b.move();
        }
        else if (ch == KEY_DOWN)
        {
            b.setDirection(4);
            if (!m1.isTrungMap(b.ifMove())) b.move();
        }
        else if (ch == KEY_LEFT)
        {
            b.setDirection(3);
            if (!m1.isTrungMap(b.ifMove())) b.move();
        }
        else if (ch == KEY_RIGHT)
        {
            b.setDirection(1);
            if (!m1.isTrungMap(b.ifMove())) b.move();
        }
        b_bullet.print();

        //a tim thay b
        if (a.found(b)) {
            gotoxy(0, 21);
            system("pause");
        }


        sleep_for(milliseconds(50));
    }
}