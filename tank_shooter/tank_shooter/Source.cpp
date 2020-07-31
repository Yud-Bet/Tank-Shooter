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
	g_map m1;
	m1.print();
    
    //object initialization
    Object a(50, 70);
    a.print();
    a.setDirection(4);

    while (true) {
        a.clear();
        a.setDirection(Randoms(1, 10));
        a.move();
        a.print();
        sleep_for(milliseconds(100));
    }
}