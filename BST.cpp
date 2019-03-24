#include <cstdlib>
#include <queue>
#include "BST.h"

using namespace std;

template <class T>
void BstNode<T>::breadthFirst(BstNode<T>* root){
    if(root == NULL)
        return;

    queue<BstNode<T>*> q;

    q.push(root);

    while(q.empty() == false){
        BstNode<T>* node = q.front();
        cout<<" "<<node->data<<endl;
        q.pop();

        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
    }
}
