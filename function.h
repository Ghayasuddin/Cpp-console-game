#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "rockPaperScissor.cpp"
#include "guessMyNumber.cpp"
#include "TicTacToe.cpp"
#include "AnimalGuess.cpp"
#include "KBC.cpp"
#include "quizGame.cpp"
#include "hangMan.cpp"
#include "TOH.cpp"

using namespace std;

void gameMenu(){
    system("cls");
    ifstream f("Art/gamesArt.txt");

    if (f.is_open())
        cout << f.rdbuf();

    system("color A");

    cout<<"\n\t\t****************************************";
    cout<<"\n\t\t >.. Press S to start the Quiz Game";
    cout<<"\n\t\t >.. Press G to start the Guess Magic Game";
    cout<<"\n\t\t >.. Press K to start the Who Wants To Be Millionaire";
    cout<<"\n\t\t >.. Press R to start the Rock Paper Scissor game";
    cout<<"\n\t\t >.. Press H to start the Hang Man game";
    cout<<"\n\t\t >.. Press T to start the Tic Tac Toe game";
    cout<<"\n\t\t >.. Press A to start the Animal Guessing game";
    cout<<"\n\t\t >.. Press O to start the Tower Of Hanoi game";
    cout<<"\n\t\t****************************************\n\n";
}

void gameMenuSelect(){
    char option;
    option = getch();

	if(option == 'T' || option == 't')
	{
	    loading();
        ttt();
	}
	else if(option == 'H' || option == 'h')
	{
	    loading();
        hangMan();
	}
	else if(option == 'G' || option == 'g')
	{
	    loading();
        guess();
	}
	else if(option == 'K' || option == 'k')
	{
		loading();
		KBC();
	}
	else if(option == 'R' || option == 'r')
	{
	    loading();
        rockPaperScissor();
	}
	else if(option == 'O' || option == 'o')
	{
	    loading();
        towerOfHanoi();
	}
	else if(option == 'A' || option == 'a')
	{
	    loading();
        AnimalGuess();
	}
    else if(option == 'S' || option == 's')
    {
		loading();
        quiz();
    }
}

void menu(){
    system("cls");
    ifstream f("Art/MenuArt.txt");

    if (f.is_open())
        cout << f.rdbuf();

    system("color A");

    cout<<"\n\t\t****************************************";
    cout<<"\n\t\t >.. Press S to select the Games";
    cout<<"\n\t\t >.. Press V to view the highest score";
    cout<<"\n\t\t >.. Press C to view the Answers";
    cout<<"\n\t\t >.. press H for help";
    cout<<"\n\t\t >.. press Q to quit the game";
    cout<<"\n\t\t****************************************\n\n";
}

void viewScore(){
    system("cls");
    system("color d");
    string name;
    int s=0;
    ifstream score;
    system("cls");
    score.open("data/score.txt");
    score>>name>>s;
    cout<<"\n\n\t\t ";
    cout<<"\n\n\t\tQuiz: "<<name<<" has secured the Highest Score "<<s<<endl;
    score.close();

    score.open("data/Hscore.txt");
    score>>name>>s;
    cout<<"\n\n\t\tHang Man: "<<name<<" has secured the Highest Score "<<s;
    cout<<"\n\n\t\t ";

    score.close();
}

void help()
{
    system("cls");
    system("color b");

    ifstream Art("Art/HelpArt.txt");

    if (Art.is_open())
        cout << Art.rdbuf();

    int choice;
    cout<<"\n\t\t******************HELP***********************";
    cout<<"\n\t\t >.. Press 1 to Quiz";
    cout<<"\n\t\t >.. Press 2 to Guess Magic Game";
    cout<<"\n\t\t >.. Press 3 to Who Wants To Be Millionaire";
    cout<<"\n\t\t >.. Press 4 to Rock Paper Scissor game";
    cout<<"\n\t\t >.. Press 5 to Tic Tac Toe game";
    cout<<"\n\t\t >.. Press 6 to Animal Guessing game";
    cout<<"\n\t\t >.. Press 7 to Hang Man game";
    cout<<"\n\t\t >.. Press 8 to Tower Of Hanoi game";
    cout<<"\n\t\t****************************************\n\n";
Again:
    do{
        cout<<"\n\nEnter: ";
        while(!(cin>>choice)){
            cin.clear();
            cin.ignore(99,'\n');
            cout<<"Invalid! Try again: ";
        }
    }while(choice>8 || choice<1);

    ifstream file;

    switch(choice){
        case 1:
            file.open("Help/QuizHelp.txt");
            break;

        case 2:
            file.open("Help/GuessNumHelp.txt");
            break;

        case 3:
            file.open("Help/KbcHelp.txt");
            break;

        case 4:
            file.open("Help/RpsHelp.txt");
            break;

        case 5:
            file.open("Help/TttHelp.txt");
            break;

        case 6:
            file.open("Help/AnimalHelp.txt");
            break;

        case 7:
            file.open("Help/hangHelp.txt");
            break;

		case 8:
            file.open("Help/towerHelp.txt");
            break;

        default:
            goto Again;
            break;
    }

    system("cls");
    if (file.is_open())
        cout << file.rdbuf();
}

void viewAns(){
    system("cls");

    ifstream file("data/Ans.txt");

    if (file.is_open())
        cout << file.rdbuf();
}

#endif
