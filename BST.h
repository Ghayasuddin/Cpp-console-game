#ifndef  BST_H_INCLUDED
#define BST_H_INCLUDED

template <class T>
class BstNode{
public:
    T data;
    BstNode* left;
    BstNode* right;

    void breadthFirst(BstNode* root);
};

#endif
