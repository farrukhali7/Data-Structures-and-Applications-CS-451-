#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

const int table_size = 10;
Node* HT[table_size] = {NULL};

void insert(int value){
    int ind = value % table_size;
    Node* tmp = new Node();
    tmp->data = value;
    tmp->next = NULL;
    
    if(HT[ind] == NULL){
        HT[ind] = tmp;
    }else{
        Node* cur = HT[ind];
        while(cur->next != NULL){
            cur = cur->next;
        }
    cur->next = tmp;
    }
}

void display() {
    for(int i = 0; i < table_size; i++) {
        cout << i << ": ";    // each 'i' is the head of the linked list
        Node* cur = HT[i];
        while(cur != NULL) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
}


int main() {
    insert(15);
    insert(25);
    insert(35);
    insert(5);
    insert(12);
    insert(24);
    insert(59);
    insert(39);
    insert(89);
    display();
}
