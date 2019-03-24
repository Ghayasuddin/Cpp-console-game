#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <math.h>
#include <string>
#include <ctype.h>
#include <windows.h>
#include <fstream>
#include "function.h"
using namespace std;
using std::string;

int main()
{
    cout << '\a';
GAME:
    char option;
    int n;

    menu();
    option = getch();
    if (option == 'V' || option == 'v')
	{
        viewScore();
        cout<<"\n\nPress any key to Return to Main Menu...";
        system("pause>NULL");
        goto GAME;
	}
    else if(option == 'H' || option == 'h')
	{
        help();
        cout<<"\n\nPress any key to Return to Main Menu...";
        system("pause>NULL");
        goto GAME;
	}
	else if(option == 'C' || option == 'c')
	{
        viewAns();
        cout<<"\n\nPress any key to Return to Main Menu...";
        system("pause>NULL");
        goto GAME;
	}
    else if(option == 'S' || option == 's')
    {
        gameMenu();
        gameMenuSelect();
        cout<<"\n\nPress any key to Return to Main Menu...";
        system("pause>NULL");
        goto GAME;
    }
    else if (option == 'Q' || option == 'q')
    {
         return 0;
    }
    goto GAME;
    return 0;
}
