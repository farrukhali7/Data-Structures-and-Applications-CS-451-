#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* list = NULL;
void insert(int value){
    Node *tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = NULL;
    
    if(list == NULL){
        list = tmp;
    }else{
        Node *cur = list;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void print(){
    Node* cur = list;
    while(cur != nullptr){
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main(){
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(5);
    print();
}
