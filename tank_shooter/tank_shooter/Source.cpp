#include "my_console.h"
#include "g_map.h"
#include "Object.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
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
     
     






        //a tim thay b
        if (a.found(b)) {
            gotoxy(0, 21);
            system("pause");
        }


        sleep_for(milliseconds(50));
    }
}