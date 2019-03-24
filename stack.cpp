#include "stack.h"
using namespace std;

template <class T>
void SNode<T>::setNext(SNode *newnode){

        next=newnode;
}
template <class T>

SNode<T>* SNode<T>:: getNext(){
        return next;
}

template <class T>
 T SNode<T>::getData(){
        return this->data;
}

template <class T>
void SNode<T>::setData(T data){

        this->data=data;
}

template <class T>
Stack<T>::Stack(int size1){

    topNode=NULL;
    count1=0;
    limit=size1;
}

template <class T>

void Stack<T>::push(T value){

    if(count1==limit){
        cout<<" Stack is Full"<<endl;
    }
    else{

        SNode<T> *newNode=new SNode<T>();

        if(topNode==NULL){

            newNode->setData(value);
            newNode->setNext(NULL);
            topNode=newNode;
            count1++;
        }
        else{
            newNode->setData(value);
            newNode->setNext(topNode);
            topNode=newNode;
            count1++;
        }

    }

}

template <class T>
void Stack<T>::pop(){

    if(count1==0){
        cout<<" Stack is empty"<<endl;
    }
    else{

        SNode<T> *oldNode = new SNode<T>();

        oldNode=topNode;
        topNode=topNode->getNext();
        delete oldNode;
         count1--;
    }
}

template <class T>
T Stack<T>::top(){
    return topNode->getData();
}

template <class T>
void Stack<T>::print(){

    SNode<T> *temp=new SNode<T>();
    temp=topNode;
    while(temp){
        cout<<temp->getData()<<endl;
        temp=temp->getNext();
    }

}
