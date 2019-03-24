#include "BST.cpp"

using namespace std;

int getAnswer(){							// return 1 if yes , 0 if no, -1 if anything else
    string choice;
    cin>>choice;

    if(choice == "yes" || choice == "Yes" || choice == "YES")
        return 1;
    else{
        if(choice == "no" || choice == "No" || choice == "NO")
            return 0;
        else
            return -1;
    }
}

void create_tree(ifstream& in_file, string file){			//open file
    in_file.open(&file[0], ios::in);

    if(in_file.fail()){
        cout<<"Game Load Fail! \nRestart it!";
    }
    else
        return;
}

BstNode<string>* readFile(BstNode<string>* root, ifstream& in_file){    //reading in preOrder from file
    string str;
    getline(in_file, str);

    if(str != "isNull"){
        root = new BstNode<string>();
        root->data = str;
        root->left = readFile(root->left, in_file);
        root->right = readFile(root->right, in_file);
    }
    else{
        root = NULL;
    }
    return root;
}

void writeFile(BstNode<string>* root, ofstream& out_file){          //preOrder writing to file (NLR)
    if(root == NULL)
        out_file<<"isNull"<<endl;									//writing isNULL if parent has no child
    else{
        out_file<<root->data<<endl;
        writeFile(root->left, out_file);
        writeFile(root->right, out_file);
    }
}

string aOrAn(string animal){									//return an if animal name start with vowel otherwise return a
    if(animal[0] == 'a' || animal[0] == 'A')
        return "an";
    if(animal[0] == 'i' || animal[0] == 'I')
        return "an";
    if(animal[0] == 'o' || animal[0] == 'O')
        return "an";
    if(animal[0] == 'e' || animal[0] == 'E')
        return "an";
    if(animal[0] == 'u' || animal[0] == 'U')
        return "an";
    else
        return "a";
}

int isYourAnimal(BstNode<string>* root){											//printing animal return 0 if guess is correct
    int choice;																			//return 1 if guess wrong
    cout<<"\nIs Your Animal "<<aOrAn(root->data)<<" "<<root->data<<"?"<<endl;
    choice = getAnswer();

    if(choice == 0)
        return 0;
    else{
        if(choice == 1)
            return 1;
        else{
            cout<<"\nPardon.. Invalid Answer";
            return isYourAnimal(root);
        }
    }
}
BstNode<string>* prevNode;
void setPrevNode(BstNode<string>* root){
    prevNode = root;
}

void ask(BstNode<string>* root){
    int choice  = 0;
    setPrevNode(root);
    if(root->left == NULL && root->right == NULL)
        return;
    else{
        cout<<"Question: "<<root->data<<endl;
        choice = getAnswer();

        if(choice == 0){
            ask(root->right);
        }
        else{
            if(choice == 1){
                ask(root->left);
            }
            else{
                cout<<"\nError 404: Try Again\n";
                ask(root);
            }
        }
    }
}

void gameAI(BstNode<string>* root){
    string yourAnimal, yourQuestion;

    cout<<"\nWhat is your animal?: ";
    cin.ignore();
    getline(cin, yourAnimal);

    cout<<"\nNice!\n";
    cout<<"Write a distinguishing question that answers";
    cout<<"\nyes for "<<yourAnimal<<" and NO for "<<root->data<<":\n";
    getline(cin,yourQuestion);

    BstNode<string>* YES = new BstNode<string>();
    YES->data = yourAnimal;
    YES->left = NULL;
    YES->right = NULL;

    BstNode<string>* NO = new BstNode<string>();
    NO->data = root->data;
    NO->left = NULL;
    NO->right = NULL;

    root->data = yourQuestion;
    root->left = YES;
    root->right = NO;
}

void AnimalGuess(){
    BstNode<string>* root;

    ofstream out_file;
    ifstream in_file;
    string file = "data/Animals.txt";

    ifstream Art("Art/horseArt.txt");

    if (Art.is_open())
        cout << Art.rdbuf();

    cout<<"****************Animal Guessing Game****************"<<endl;

    cout<<"\nAre you ready?\nYes OR NO?"<<endl;
    if(getAnswer() == 1)
        cout<<"\nGet Ready!!\n"<<endl;
    else{
        cout<<"\nNothing is permanent in this wicked world"<<endl;
        cout<<"not even our troubles.\n\t - Charlie Chaplin"<<endl;
        return;
    }

    create_tree(in_file, file);
    root = readFile(root, in_file);
    in_file.close();

    ask(root);

    if(isYourAnimal(prevNode) == 1){
        cout<<"\n\nI Knew it! *Evil laugh* HAHAHAHAHA!!!\n";
    }
    else{
        cout<<"\nGuess i'm not smart enough..";
        gameAI(prevNode);
        cout<<"\n\nThank you for teaching me!"<<(char)2<<endl<<endl;
    }

    out_file.open(&file[0],ios::out);
    writeFile(root,out_file);
    out_file.close();

   return;
}
