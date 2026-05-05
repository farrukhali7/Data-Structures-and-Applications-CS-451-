// Heap
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* list = NULL;
void insert(int value){
    Node* tmp = new Node();
    tmp->data = value;
    tmp->left = NULL;
    tmp->right = NULL;
    
    if(list == NULL){
        list = tmp;
        return;
    }else{
        Node* cur = list;
        while(cur != NULL){
        if(value < cur->data){
            if(cur->left == NULL){
                cur->left = tmp;
                return;
            }else{
                cur =cur->left;
            }
        }else{      // value >= cur->data
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

struct QNode{
    Node* node;
    QNode* next;
};

struct Queue{       //FIFO
    QNode* front = NULL;
    QNode* end = NULL;
    
    void enQueue(Node* value){
        QNode* tmp = new QNode();
        tmp->node = value;
        tmp->next = NULL;
        
        if(end == NULL){
            front = tmp;
            end = tmp;
        }else{
            end->next = tmp;
            end = tmp;
        }
    }
    
    Node* deQueue(){
        if(front == NULL){
            cout << "Queue underflow" << endl;
            return NULL;
        }else{
            QNode* cur = front;
            Node* val = cur->node;
            front = front->next;
            if(front == NULL) end = NULL;
            delete cur;
            return val;
        }
    }
    
    void display(){     // breath-first traversal
        if(list == NULL){
            return;
        }
        QNode* cur = front;
        while(cur != NULL){
            cout << cur->node->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return front == NULL;
    }
};

void BFS(Node* root){
    if(root == NULL){
        return;
    }
    Queue q;
    q.enQueue(root);
    
    while(!q.isEmpty()){        //if q is not empty
        Node* cur = q.deQueue();
        cout << cur->data << " ";
        
        if(cur->left != NULL){
            q.enQueue(cur->left);
        }
        if(cur->right != NULL){
            q.enQueue(cur->right);
        }
    }
        cout << endl;
}

// void delete(){
    
// }

// void sort(){
    
// }

int main(){
    insert(10);
    insert(45);
    insert(17);
    insert(22);
    insert(77);
    insert(52);
    insert(83);
    
    BFS(list);
    
    //// can be used for displaying but this wont be breath-first traversal
    // Queue q;         
    // q.enQueue(list);
    // q.enQueue(list->left);
    // q.enQueue(list->right);
    // q.display();
}
