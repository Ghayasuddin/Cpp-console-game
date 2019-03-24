#ifndef  LinkedList_H_INCLUDED
#define LinkedList_H_INCLUDED
using namespace std;
struct node{
    node* next;
    string category;
    string data;
};

class LinkedList{
public:
    node* head;

    LinkedList();
    ~LinkedList();
    void print();
    void get(int i, string &word, string &cat);
    int count();
    void addEnd(string data, string cat);
    void removeStart();
    void removeEnd();
};

#endif
