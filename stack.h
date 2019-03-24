#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class SNode{
private:
     SNode<T> *next;
     T data;
public:
    void setNext(SNode *newnode);
    SNode *getNext();
    T getData();
    void setData(T value);
};

template <class T>

class Stack{
    private:
        int count1;
        int limit;
    public:
        SNode<T> *topNode;

        Stack(){
            count1 = 0;
        }
        Stack(int value);

        void push(T value);
        void pop();
        void print();
        T top();
};
#endif
