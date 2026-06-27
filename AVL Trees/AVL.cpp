// AVL TREES
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

struct QueueNode{
    Node* data;
    QueueNode* next;
};

struct Queue{
    QueueNode* front;
    QueueNode* end;
    
    void enQ(Node* value){
        QueueNode* tmp = new QueueNode;
        tmp->data = value;
        tmp->next = NULL;
        
        if(front == NULL || end == NULL){
            front = end = tmp;
        }else{
            end->next = tmp;
            end = tmp;
        }
        cout << value << " enqueued!" << endl;
    }
    
    Node* deQ(){
        if(front == NULL){
            cout << "Queue Underflow" << endl;
            return NULL;
        }else{
            QueueNode* cur = front;
            Node* val = front->data;
            front = front->next;
            delete cur;
            cout << val << " dequeued!" << endl;
            return val;
        }
    }
    
    // is empty and size is used in height func
    bool isEmpty(){
        return front == NULL;
    }
    
    int size(){
        int count = 0;
        QueueNode* cur = front;
        while(cur != NULL){
            count = count + 1;
            cur = cur->next;
        }
        return count;
    }
};

Node* list = NULL;
void insertSeq(int value){
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
                cur =cur->left;
            }
        }else{      //value > cur->data
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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    
    Queue q;
    q.enQ(root);
    int h =0;
    
    
        while(!q.isEmpty()){
            int levelsize = q.size();
            
            for(int i=0; i < levelsize; i++){
                Node* cur = q.deQ();
                if(cur->left){
                    q.enQ(cur->left);
                }
                if(cur->right){
                    q.enQ(cur->right);
                }
            }
                h = h + 1;
            }
            return h;
}

// ROTATIONS
    Node* LLRotation(Node* root){
        Node* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
    Node* RRRotation(Node* root){
        Node* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }
    Node* LRRotation(Node* root){
        root->left = RRRotation(root->left);
        return LLRotation(root);
    }
    Node* RLRotation(Node* root){
        root->right = LLRotation(root->right);
        return RRRotation(root);
    }
    
    
Node* checkBalanceFactor(Node* cur){
    int bF = height(cur->left) - height(cur->right);
    
    if(bF != 0 && bF != -1 && bF != 1){
       if(bF == 2){
           if(height(cur->left->left) >= height(cur->left->right))
           cur = LLRotation(cur);
       }else{
          cur=  LRRotation(cur);
       }
       if(bF == -2){
           if(height(cur->right->right) >= height(cur->right->left))
           cur= RRRotation(cur);
       }else{      
           cur = RLRotation(cur);
       }
    }
       return cur;
}

void inOrder(Node* n){     //LNR
    if(n != NULL){
        inOrder(n->left);
        cout << n->data << " " << endl;
        inOrder(n->right);
    }
    
    //preOrder  // NLR
    // void preOrder(Node* n){
    //     if(n != NULL){
    //         cout << n->data << " " << endl;
    //         preOrder(n->left);
    //         preOrder(n->right);
    //     }
    // }
    
    //postOrder  // LRN
    // void postOrder(Node* n){
    //     if(n != NULL){
    //         postOrder(n->left);
    //         postOrder(n->right);
    //         cout << n->data << " " << endl;
    //     }
    // }
}

int main(){
    insertSeq(10);
    list = checkBalanceFactor(list);

    insertSeq(20);
    list = checkBalanceFactor(list);

    insertSeq(30);
    list = checkBalanceFactor(list);

    cout << "InOrder Traversal: ";
    inOrder(list);
    cout << endl;
}
