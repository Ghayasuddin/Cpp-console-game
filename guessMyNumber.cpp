void loading(){
    system("cls");

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tLoading ";
        for(int i=0;i<10;i++){
            Sleep(230);
            cout<<". ";
        }

    system("cls");
}

void guess()
{
	int upperLimit=1000, lowerLimit=0, guess=0, i=0;
	int answer=0;
	system("cls");
	system("color c");
	cout<<"\t\t\"Can i guess your number in 10 turns\"\n\n";
	cout<<"Think Of A Number Between 1 to 1000(press to start): \n\n";
	system("pause");
	loading();
	for (i=1;i<=10;i++)
	{
		guess=(upperLimit + lowerLimit) / 2;
		while ( !(answer == 1 || answer == 2))
			{
				system("cls");
				cout<<"\n\n\n\tGuess no "<<i<<": Your Number Is "<<guess<< "?(1 for yes) and (2 for no):\n";
				while(!(cin>>answer)){
                    cin.clear();
                    cin.ignore(99,'\n');
                    cout<<"\nInvalid! Try again: ";
                }
			}
				if(answer == 1)
				{
					cout<<("\a\n\tOh yeah! I guessed your number!!!\n");
					i=11;
				}
				else
				{
					answer = 'x';
						if (i<10){
							while (!(answer == 1 || answer == 2)){
								cout<<"\n\tIs your number is greater than "<<guess<<" ?(1 for yes) and (2 for no):\n";
                                cin>>answer;
				}
					if(answer == 1){
						lowerLimit = guess;
					}
					else{
						upperLimit = guess;
					}
				}
			}
		answer='x';
	}
	if(i!=12){
		cout<<("\a\n\n\t\t\t\t\tComputer Loses...");
	}
}