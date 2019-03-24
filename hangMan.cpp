#include "LinkedList.cpp"
using namespace std;

void hangMenu(){
    system("cls");
    ifstream f("Art/hangManArt.txt");

    if (f.is_open())
        cout << f.rdbuf();

    cout<<"\n\t****************Hang Man****************";
    cout<<"\n\n\t>>Enter 1 to Play the Game";
    cout<<"\n\n\t>>Enter 2 to add word in the Game"<<endl;
}

void hanged(string word){
    system("cls");
    ifstream f("Art/hangedArt.txt");

    if (f.is_open())
        cout << f.rdbuf();

    cout<<"\n\nYou got hanged!!!!!!\n";
    cout<<"\nThe word was: "<<word<<endl;
}

void readFile(LinkedList &wordList){
    ifstream words;
    string data, cat;
    words.open("data/wordsList.txt");
    while(!words.eof()){
        //words>>data>>cat; old style
        getline(words,data);
        getline(words,cat);
        wordList.addEnd(data,cat);
    }
    words.close();
}

void writeFile(LinkedList &wordList){
    node *temp = wordList.head;
    ofstream words;
    words.open("data/wordsList.txt");
    while(temp){
        words<<temp->data<<"\n"<<temp->category;
        if(temp->next != NULL)
            words<<endl;
        temp = temp->next;
    }
    words.close();
}

string setStars(string word){
    string star = word;
    for(int i=0; i<star.length(); i++){
        star[i] = '*';
    }
    return star;
}

char changeCase(char ch){
    if(isupper(ch) == 0)
        return ch;
    else
        return ch+32;
}

int countLetter(string &word, char letter){
    int count = 0;
    for(int i=0; i<word.length(); i++){
        if(word[i] == letter)
            count++;
    }
    if(count == 0)
        return 0;
    if(count == 1)
        return 1;
    if(count > 1)
        return -1;
}

int checking = 0;
void Hint(string &word, string &star){
hint:
    srand(time(NULL));
    int Len = word.length() - 1;
    int number = (rand()%Len);

    int flag = countLetter(word, word[number]);

    if(flag == -1 && checking >= Len){
            if(word[number] == star[number])
                goto hint;
            else{
                char ch = word[number];
                ch = changeCase(ch);
                for(int i=Len; i>=0; i--){
                        if(ch == word[i] || ch == word[i]+32){
                            star[i] = word[i];
                            checking = 0;
                            return;
                        }
                }
                //star[number] = word[number];
            }
    }

    if(flag == -1 && checking < Len){
        checking++;
        goto hint;
    }
    else{
        if(flag == 1){
            if(word[number] == star[number])
                goto hint;
            else
                star[number] = word[number];
        }
    }
    checking = 0;
}

int checkLetter(char ch, string word, string &star){
    int found = 0;
    ch = changeCase(ch);
    for(int i=0; i<word.length(); i++){
        if(ch == star[i] || ch == star[i]+32)
            return found;
        if(ch == word[i] || ch == word[i]+32){
            star[i] = word[i];
            found++;
        }
    }
    return found;
}

void fillSpace(string &word, string &star){
    for(int i=0; i<star.length(); i++){
        if(word[i] == ' ')
            star[i] = ' ';
        else{
            if(word[i] == '.')
                star[i] = '.';
        }
    }
}

int maxWrong = 5;

void hangMan(){
    LinkedList wordList;
    string star, word, category;
    char letter;
    int wrong = 0, choice = 0, n = 0, score = 0, prevRand, hints = 1;
	Player *userH = new Player;

    readFile(wordList);

	do{
		hangMenu();
		while(!(cin>>choice)){
				cin.clear();
				cin.ignore(99,'\n');
				cout<<"Invalid! Try again: ";
		}
	}while(choice<0 || choice>2);

    if(choice == 1){
        cin.clear();
        cin.ignore();
		cout<<"\n\tEnter Your Name: ";
		getline(cin,word); userH->setName(word);

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

        hints = n/2;
		for(int j=1; j<=n; j++){
			wrong = 0;
			system("cls");
            Generate:
                srand(time(NULL));
                int number = (rand()%wordList.count());
                if(prevRand == number)
                    goto Generate;
                prevRand = number;

			wordList.get(number, word, category);

			star = setStars(word);
			fillSpace(word,star);

			while(wrong < maxWrong){
				system("cls");
				cout<<"\nEnter 1 for hint.\n";
				cout<<"\nYou have "<<hints<<" Hints left.\n";
				cout<<"\nYou have "<<maxWrong - wrong<<" guesses left.\n";
				if(category != "")
                    cout<<"\n\nThe Word belongs to "<<category<<" category.";
				cout<<"\n\n"<<star;
            LetterIN:
				cout<<"\n\nGuess a Letter: ";

				while(!(cin>>letter)){
                    cin.clear();
                    cin.ignore(99,'\n');
                    cout<<"Invalid! Try again: ";
                }

                if(letter == '1' && hints == 0){
                    cout<<"\nNo Hints left...  ;(";
                    goto LetterIN;
                }
                if(letter == '1' && hints != 0){
                    Hint(word, star);
                    hints--;
                    goto match;
                }

				if(checkLetter(letter,word,star) == 0){
					cout<<"\nLetter is not used in a word\n";
					wrong++;
					Beep(322,300);
				}
				else{
					cout<<"\nYou found a letter!\n";
					score += 10;
				}
            match:
				system("pause");

				if(star == word){
					cout<<"\n"<<word<<endl;
					cout<<"\nYou got it!\n";
					break;
				}
			}
			if(wrong == maxWrong){
				hanged(word);
				break;
			}

            if(j != n){
                cout<<"\nPress any key to play next round";
                system("pause>NULL");
            }

            if(j == n/2)
                hints =+ (n/3);
		}

		userH->setScore(score);
		userH->HangManScore(*userH);
    }
    else if(choice == 2){
            do{
                cout<<"\n\n\tHow many words do you want to add?: ";
                while(!(cin>>n)){
                    cin.clear();
                    cin.ignore(99,'\n');
                    cout<<"Invalid! Try again: ";
                }
            }while(n<0);

		if(n == 0)
			return;

        cin.ignore();
        cin.clear();
        for(int i=0; i<n; i++){
            system("cls");

            cout<<"\nEnter your word: ";
            getline(cin,word);

            cout<<"\nEnter Category or Hint for your word: ";
            getline(cin,category);

            wordList.addEnd(word,category);
            writeFile(wordList);
        }
    }
    return;
}
