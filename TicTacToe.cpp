char sq[10] = {'o','1','2','3','4','5','6','7','8','9'};

void resetBoard(){
	sq[1] = '1';sq[2] = '2';sq[3] = '3';sq[4] = '4';sq[5] = '5';sq[6] = '6';sq[7] = '7';sq[8] = '8';sq[9] = '9';
}

int checkWin()
{
	if (sq[1] == sq[2] && sq[2] == sq[3])
		return 1;
	else if (sq[4] == sq[5] && sq[5] == sq[6])
		return 1;
	else if (sq[7] == sq[8] && sq[8] == sq[9])
		return 1;
	else if (sq[1] == sq[4] && sq[4] == sq[7])
		return 1;
	else if (sq[2] == sq[5] && sq[5] == sq[8])
		return 1;
	else if (sq[3] == sq[6] && sq[6] == sq[9])
		return 1;
	else if (sq[1] == sq[5] && sq[5] == sq[9])
		return 1;
	else if (sq[3] == sq[5] && sq[5] == sq[7])
		return 1;
	else if (sq[1] != '1' && sq[2] != '2' && sq[3] != '3' && sq[4] != '4' && sq[5] != '5' && sq[6] != '6' && sq[7] != '7' && sq[8] != '8' && sq[9] != '9')
		return 0;
	else
		return -1;
}

void board()
{
	system("cls");
	cout<<"\n\n\tTic Tac Toe\n\n";
	cout<<"Player 1 (X)  VS  Player 2 (O)" <<endl<<endl;
	cout<<endl;
	cout<< "     |     |     " <<endl;
	cout<< "  " << sq[1] << "  |  " << sq[2] << "  |  " << sq[3] <<endl;
	cout<< "_____|_____|_____" <<endl;
	cout<< "     |     |     " <<endl;
	cout<< "  " << sq[4] << "  |  " << sq[5] << "  |  " << sq[6] <<endl;
	cout<< "_____|_____|_____" <<endl;
	cout<< "     |     |     " <<endl;
	cout<< "  " << sq[7] << "  |  " << sq[8] << "  |  " << sq[9] <<endl;
	cout<< "     |     |     " <<endl<<endl;
}

void ttt()
{
    system("cls");
    system("color A1");

	int player = 1,i,choice,n;
	char mark;
	
	do{
        cout<<"\n\n\tHow many rounds do you want to play?: ";
        while(!(cin>>n)){
            cin.clear();
            cin.ignore(99,'\n');
            cout<<"Invalid! Try again: ";
        }
	}while(n<0);
	
	if(n == 0)
        return;

    cout<<"\n\nPress any key To Play...";
    system("pause>NULL");

	for(int j=1; j<=n; j++)
	{
		system("cls");
        
		do
        {
        Again:
            board();
            player=(player%2)?1:2;
			cout << "Player " << player << ", enter a number:  ";

            while(!(cin >> choice)){
				cout<<"\nInvalid move\nTry again: ";
				cin.clear();
                cin.ignore(99,'\n');
			}

            mark=(player == 1) ? 'X' : 'O';
            if (choice == 1 && sq[1] == '1')
                sq[1] = mark;
            else if (choice == 2 && sq[2] == '2')
                sq[2] = mark;
            else if (choice == 3 && sq[3] == '3')
                sq[3] = mark;
            else if (choice == 4 && sq[4] == '4')
                sq[4] = mark;
            else if (choice == 5 && sq[5] == '5')
                sq[5] = mark;
            else if (choice == 6 && sq[6] == '6')
                sq[6] = mark;
            else if (choice == 7 && sq[7] == '7')
                sq[7] = mark;
            else if (choice == 8 && sq[8] == '8')
                sq[8] = mark;
            else if (choice == 9 && sq[9] == '9')
                sq[9] = mark;
            else
            {
                cout<<"\nInvalid move\nTry again: ";
                goto Again;
            }

            i = checkWin();
            player++;
        }while(i==-1);

        board();
        if(i==1)
            cout<<"\n==>\aPlayer "<<--player<<" won!!\n";
        else
            cout<<"\n==>\aDraw\n";

        cin.ignore();
        cin.get();
        
		resetBoard();
	}
}