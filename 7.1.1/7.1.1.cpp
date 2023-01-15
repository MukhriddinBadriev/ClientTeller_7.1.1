﻿#include <iostream>

#include <thread>
#include <chrono>
#include <Windows.h>

class consol_color
{
public:
    static void SetColor(int text, int background)
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
};

int n = 1;

void Client() {
    
    while (n != 10) {
        ++n;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        consol_color::SetColor(12, 0);
        std::cout << n << " ";
    }
}

void Teller() {
    
    while (n != 0) {
        --n;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        consol_color::SetColor(10, 0);
        std::cout << n << " ";
    }
}


int main()
{
    std::thread t1(Client);

    std::thread t2(Teller);

    t1.join();
    t2.join();     
        
    return 0;
}