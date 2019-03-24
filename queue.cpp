#include "queue.h"
using namespace std;

template <class T>
void Node<T>::set(T data){
    this->data = data;
}

template <class T>
T Node<T>::get(){
    return this->data;
}

template <class T>
void Node<T>::setNext(Node* temp){
    this->next = temp;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template <class T>
Queue<T>::Queue(){
    rear = NULL;
    front = NULL;
 }

 template <class T>
Queue<T>::~Queue(){}

template <class T>
void Queue<T>::enque(T data){
    Node<T>* newNode = new Node<T>();
    newNode->set(data);
    newNode->setNext(NULL);

    if(front == NULL){
        front = newNode;
    }
    else{
        rear->setNext(newNode);
    }
    rear = newNode;
}

template <class T>
T Queue<T>::deque(){
    if(front == NULL){
        cout<<"\nEMPTY!!"<<endl;
        return 0;
    }
    else{
        T value = front->get();

        Node<T> *temp = new Node<T>();
        temp = front;
        front = front->getNext();
        delete temp;

        return value;
    }
}

template <class T>
void Queue<T>::display(){
    if(front == NULL){
        cout<<"\nEMPTY!!"<<endl;
    }
    else{
        Node<T>* temp = front;

        cout<<"\n"<<temp->get()<<endl;
        temp = temp->getNext();
    }
}
