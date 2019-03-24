#ifndef  QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Node{
private:
    T data;
    Node *next;
public:
    void setNext(Node* temp);
    Node* getNext();
    void set(T data);
    T get();

};

template <class T>
class Queue{
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Queue();
    ~Queue();
    void enque(T data);
    T deque();
    void display();
};
#endif
