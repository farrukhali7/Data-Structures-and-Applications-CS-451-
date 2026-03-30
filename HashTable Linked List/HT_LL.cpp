#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* HT[10] = {nullptr};

void insert(int value){
    int ind = value % 10;
    
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = nullptr;
    
    if(HT[ind] == nullptr){
        HT[ind] = tmp;
    }
    else{
        tmp->next = HT[ind];
        HT[ind] = tmp;
    }
}

void Search(int val){
    int ind = val % 10;
    Node* tmp = HT[ind];
    
    while(tmp != NULL){
        if(tmp->data == val){
            cout << "Value Found!" << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Value Not Found!" << endl;
}


void Display(){
    for(int i = 0; i < 10 ; i++){
        cout << i << " :";
        Node* tmp = HT[i];
        while(tmp != nullptr){
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << "Null \n";
    }
}

int main() {
    insert(67);
    insert(32);
    insert(35);
    insert(12);
    insert(34);
    insert(76);
    insert(83);
    insert(26);
    insert(59);
    insert(30);
    insert(17);
    insert(31);
    insert(29);
    insert(38);
    insert(04);
    insert(84);
    insert(72);
    Display();
    
    Search(44);
    Search(84);
    Search(59);
    Search(32);
    Search(26);
}
