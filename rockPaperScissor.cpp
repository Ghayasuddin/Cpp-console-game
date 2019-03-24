using namespace std;

void loser(){
    system("cls");
    std::ifstream f("Art/SkeletonArt.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}

void Winner(){
    system("cls");
    std::ifstream f("Art/TressureArt.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}

void Tie(){
    system("cls");
    std::ifstream f("Art/TieArt.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}

int pointCount(int points, int player, int computer)
{
	if ((player == 0) && (computer == 2) || ((player == 2 ) && (computer == 1)) || ((player == 1) && (computer == 0)))
		points=points+2;
	else if (player == computer)
		points=points+1;
	return points;
}

void rockPaperScissor()
{
	int i=0,randomNumber=0, player=5, computerGuess=0, computerPoints=0, playerPoints=0, n=0;
	system("cls");
	system("color F0");
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
	cout<<"\a\nGet Ready!!\n";
	cout<<"\n\nPress any key to Start...";
    system("pause>NULL");
	for(i=1;i<=n;i++)
	{
	    system("cls");
		while ((player<0) || (player>2))
		{
                cout<<"\nEnter,\n '0' For Rock\n '1' for Paper\n '2' for Scissor.\n";
				cout<<"\nChoose one of above option:";
				while(!(cin>>player)){
                    cin.clear();
                    cin.ignore(99,'\n');
                    cout<<"Invalid! Try again: ";
                }
		}
		srand(time(NULL));
		randomNumber = rand();
		computerGuess = randomNumber % 3;
		cout<<"\nComputer choice: "<< computerGuess<<"\n";

		computerPoints=pointCount(computerPoints,computerGuess, player);
		playerPoints = pointCount(playerPoints, player, computerGuess);

		if (((player == 0) && (computerGuess == 2)) || ((player == 2 ) && (computerGuess == 1)) || ((player == 1) && (computerGuess == 0)))
            cout<<"\nWoW!! You actually Won!\n\nplayer Points:"<<playerPoints<<"\ncomputer Points:"<<computerPoints;
        else if ((computerGuess == 0) && (player == 2) || ((computerGuess == 2 ) && (player == 1)) || ((computerGuess == 1) && (player == 0)))
            cout<<"\nOops...You lose!\nComputer won\n\nplayer Points: "<<playerPoints<<"\ncomputer Points: "<<computerPoints;
        else if (player==computerGuess)
            cout<<"\nWoah!...You managed to tie!\n\nplayer Points: "<<playerPoints<<"\ncomputer Points: "<<computerPoints;

		player=5;

		if(i != n){
            cout<<"\n\nPress any key to play next round...";
            system("pause>NULL");
		}
	}
	if (playerPoints>computerPoints)
		Winner();
	else if (playerPoints<computerPoints)
		loser();
	else
		Tie();
}
