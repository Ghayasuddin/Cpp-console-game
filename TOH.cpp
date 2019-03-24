#include "stack.cpp"
using namespace std;

void tohMenu(){
    system("cls");
    ifstream f("Art/towerArt.txt");

    if (f.is_open())
        cout << f.rdbuf();

    cout<<"\n\t****************Tower Of Hanoi****************";
    cout<<"\n>> Rules: ";
    cout<<"\n>> 		You have to move disks from tower A to C in same orders";
    cout<<"\n>> 		You can not move larger number disk over smaller";
	cout<<"\n\n\t>>Press any key to Play the Game"<<endl;
    system("pause>NULL");
    system("cls");
}

void display(int i, Stack<int> &A,Stack<int> &B,Stack<int> &C){

    SNode<int>* temp1 = new SNode<int>();
    temp1 = A.topNode;
    SNode<int>* temp2 = new SNode<int>();
    temp2 = B.topNode;
    SNode<int>* temp3 = new SNode<int>();
    temp3 = C.topNode;
    int j=0;
    while(j<i){
        if(temp1!=NULL){
               (temp1->getData()==0)?  cout<<" *\t\t": cout<<" "<<temp1->getData()<<"\t\t";
                (temp2->getData()==0)? cout<<" *\t\t":cout<<" "<<temp2->getData()<<"\t\t";
                (temp3->getData()==0)? cout<<" *\t\t\n":cout<<" "<<temp3->getData()<<"\t\t\n";
        }

        if(temp1->getNext()!=NULL)
            temp1=temp1->getNext();
        if(temp2->getNext()!=NULL)
            temp2=temp2->getNext();
        if(temp3->getNext()!=NULL)
            temp3=temp3->getNext();

            j++;
    }
         cout<<"___\t\t___\t\t___\n";
         cout<<" A\t\t B\t\t C";

}

int interChange (Stack<int> &A,Stack<int> &B){
            int change =0,i=0;

            SNode<int>* temp = new SNode<int>();
            temp = A.topNode;

            while(temp->getData() == 0 && temp->getNext() != NULL){
                temp=temp->getNext();
            }

            change = temp->getData();
            temp->setData(0);

            while(B.topNode->getNext() != NULL && B.top() == 0){
                B.pop();
                i++;
            }

            if(B.top() != 0){
                 i--;
                if(change > B.top()){
                    return 1;
                }
            }
            else{
                B.pop();
                //i--;
            }

            B.push(change);
            //B.print();
            while(i != 0){
                B.push(0);
                i--;
            }
    return 0;
}

void towerOfHanoi(){

    tohMenu();

    int number,result=0,flag=0;
    Stack<int> *A= new Stack<int> (10);
    Stack<int> *B= new Stack<int> (10);
    Stack<int> *C= new Stack<int> (10);

    for(int j=2;j<12;j++){

        for(int i=j;i>0;i--){
            A->push(i);
            B->push(0);
            C->push(0);
        }

        int mov=0;

        result=pow(2,j)-1;

        for(int k=1;k<=result;k++){


            cout<<"A -> B press 1 \tA -> C press 2  \nB -> C press 3";
            cout<<"\tB -> A press 4 \nC -> A press 5\tC -> B press 6\n"<<endl;

            display(j,*A,*B,*C);

            cout<<"\n\nmove:"<<mov<<"\t\tremaining moves:"<<result-k+1<<endl;
            cout<<endl<<endl;
            cin>>number;

            switch(number){

                    case 1:
                            flag = interChange(*A,*B);
                            break;
                    case 2:
                            flag = interChange(*A,*C);
                            break;

                    case 3:
                            flag = interChange(*B,*C);
                            break;

                    case 4:
                            flag = interChange(*B,*A);
                            break;
                    case 5:
                            flag = interChange(*C,*A);
                            break;
                    case 6:
                            flag = interChange(*C,*B);
                            break;
            }
            if(flag == 1){
                cout<<"\nGame Over\n";
                return;
            }
            system("cls");
            mov++;
        }
        cout<<endl;
        display(j,*A,*B,*C);

        int a=0;
        for(int k=1;k<=j;k++){
            int temp=1;

            A->pop();
            B->pop();
            temp=C->top();
            C->pop();
            if(temp!=k){
                cout<<"\n\nBetter luck next time\n\n"<<endl;
                a++;
                break;
            }
        }

        cout<<endl;
        if(a==0)
            cout<<"\n****congratulations you are qualify for the Next Round****\n"<<endl;
        else
            break;
    }
}
