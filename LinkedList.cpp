#include "LinkedList.h"

LinkedList::LinkedList(){
    this->head = NULL;
}
LinkedList::~LinkedList(){}

void LinkedList::addEnd(string data, string cat){
    node *newNode = new node;
    newNode->category = cat;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void LinkedList::print(){
    node* temp = head;

    while(temp){
        std::cout<<"Word: "<<temp->data<<" Category: "<<temp->category<<std::endl;
        temp = temp->next;
    }
}

void LinkedList::get(int i, string &word, string &cat){
    node* temp = head;

    for(int j=0; j<i; j++){
        temp = temp->next;
    }

    word = temp->data;
    cat = temp->category;

    return;
}

void LinkedList::removeStart(){
    if(head == NULL){
        std::cout<<"\nList is already empty"<<std::endl;
    }
    else{
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::removeEnd(){
    if(head == NULL){
        std::cout<<"\nList is already empty"<<std::endl;
    }
    else{
        node *temp = head;
        while(temp->next && temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

int LinkedList::count(){
    node* temp = head;
    int counter=0;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    return counter;
}
