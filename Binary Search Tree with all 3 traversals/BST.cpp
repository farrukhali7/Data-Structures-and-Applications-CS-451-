#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* list = NULL;
void insert(int value){
    Node* tmp = new Node();
    tmp->data = value;
    tmp->right = NULL;
    tmp->left = NULL;
    
    if(list == NULL){
        list = tmp;
    }else{
        Node* cur = list;
        while(cur != NULL){
        if(value < cur->data){
            if(cur->left == NULL){
                cur->left = tmp; 
                return;
            }else{
                cur = cur->left;
            }
        }else{          //value > cur->data
            if(cur->right == NULL){
                cur->right = tmp;
                return;
            }else{
                cur = cur->right;
            }
        }
        }
    }
}

void inOrder(Node* root){    //LNR      //root = top most node
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root){       //LRN
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void preOrder(Node* root){        //NLR
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main() {
    insert(10);
    insert(45);
    insert(17);
    insert(22);
    insert(77);
    insert(52);
    insert(83);
    
    inOrder(list);
    cout << endl;
    
    postOrder(list);
    cout << endl;
    
    preOrder(list);
    cout << endl;
}
