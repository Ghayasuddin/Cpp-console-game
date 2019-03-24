int check(char ans,string option,int r,int count1){

    if(ans == option[r] || ans == option[r]+32)
            {
                    (r<5)?count1+=20000:(r<10)?count1+=80000:count1+=100000;
                    return count1;
            }
        cout<<"wrong answer"<<endl;
        return count1;

}

int $(int i){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int count1=0;

    for(int j=0;j<15;j++){

        if(j==0||j==5||j==10)
            SetConsoleTextAttribute(hConsole,12);
        else if(j==i)
            SetConsoleTextAttribute(hConsole,14);
        else
            SetConsoleTextAttribute(hConsole,7);
       if(j==0||j==5||j==10)
            cout<<"\n";
		cout<<count1<<"$\t";
        (j<5)?count1+=20000:(j<10)?count1+=80000:count1+=100000;
    }

    SetConsoleTextAttribute(hConsole,10);
    cout<<"\n"<<count1<<"$\n";
    SetConsoleTextAttribute(hConsole,7);
}

void KBC(){

    char stop='.',ans,choice,an='A',use;
    int lifeline=0,lifeline1=0,count1=0,money=0,count2=0,k=0;
    string option="DAADCCBBCCCBCAC";
    string first;
    ifstream file;
    file.open("a.txt");


    for(int i=0;i<15;i++){
            $(i);

        cout<<endl;
		getline(file, first, stop);
        cout<<first<<endl;
        if(i != 0){
                    cout<<"\n\nyou want to continue? wrong answer will bring you at red point $(y/n)"<<endl;
                    cin>>ans;

                    if(ans=='n'||ans=='N'){
						k++;
						break;
                    }
        }
        if(lifeline1 == 0 || lifeline1 == 1){

                if(lifeline1 == 0){
                    cout<<"\nYou have 50/50 lifeline and Two option selector,\ndo you want to use it (y/n)\n"<<endl;
                    cin>>choice;
                }
                else {
                    cout<<"\n\n1 lifeline remaninig. do you want to use it (y/n)\n"<<endl;
                    cin>>choice;
                }

                if(choice == 'y' || choice == 'Y'){

                        if(lifeline == 0){

							do{
								cout<<"\nWhich lifeline you want to use? 1 for 50 50 2 for two option selector"<<endl;
								while(!(cin>>lifeline)){
									cin.clear();
									cin.ignore(99,'\n');
									cout<<"Invalid! Try again: ";
								}
							}while(lifeline>2 || lifeline<1);

                        }

                        if(lifeline == 1){
                            int temp=count1;

                            (option[i]=='A')?an=1+option[i]:an=option[i]-1;

                            cout<<"\nTwo options are  "<<an<<"  "<<option[i]<<endl;
                            cout<<"\nEnter: ";
							cin>>ans;

                            count1=check(ans,option,i,count1);

                            if(i==4||i==9)count2=count1;

                            if(count1==temp)
								break;

							lifeline++;
                            lifeline1++;
                        }

                        else if(lifeline==2){

                            int temp=count1;
                            cout<<"\nYou can select two options"<<endl;
                            cout<<"\nEnter: ";
							cin>>ans;
                            count1=check(ans,option,i,count1);

                            if(i==4||i==9)count2=count1;
                                if(count1==temp){

                                cout<<"\nTry again: "<<endl;
                                cin>>ans;
                                count1=check(ans,option,i,count1);

								if(i==4||i==9)
									count2=count1;
                            }
                            if(count1==temp)
								break;

							lifeline--;
                            lifeline1++;
                        }

                }
                else{
							cout<<"\nEnter: ";
							cin>>ans;
                            int temp=count1;
                            count1=check(ans,option,i,count1);

							if(i==4||i==9)
								count2=count1;

							if(count1==temp)
								break;
                    }
        }

        else{
                int temp=count1;
				cout<<"\nEnter: ";
				cin>>ans;

                count1=check(ans,option,i,count1);
                if(i==4||i==9)
					count2=count1;

				if(count1==temp)
					break;
        }

        system("cls");
    }
    (k==0)?cout<<"you won :"<<count2<<"$":cout<<"you won :"<<count1;
}
