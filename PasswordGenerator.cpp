#include <iostream>
#include "PasswordGenerator.h"

#include <Windows.h>

int main()
{
    system("title Password Generator Tester By LegendsZ#1526 @ Discord");

    PasswordGenerator pG;
    while (true) {
        pG.randomizePasswordLength();
        pG.randomizePassword();
        std::cout << "Random Password = " << pG.getPassword() << "!\n\n";
        system("pause");
        system("cls");
    }

    std::cin.get();
}