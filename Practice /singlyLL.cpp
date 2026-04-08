// Singly Linked List practice:

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* list = NULL;
void insert(int value){
    Node* tmp = new Node();
    tmp->data = value;
    tmp->next = NULL;
    
    if(list == NULL){
        list = tmp;
    }else{
        Node* cur = list;
        while(cur->next != NULL){
        cur = cur->next;
        }
        cur->next = tmp;
        cout << "Value " << value << " inserted" << endl;
    }
}

void Delete(int value){
    if(list == NULL){
        cout << "List is empty" << endl;
        return;
    }
    
    Node* cur = list;
    Node* prev = NULL;
    while(cur != NULL){
        if(value == cur->data){
            if(prev == NULL){
                list = cur->next;
            }else{
             prev->next = cur->next;
            }
            delete(cur);
            cout << "Value " << value << " is deleted"<< endl;
            return ;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Value is not present" << endl;
}

void display(){
    Node* cur = list;
    while(cur != NULL){
        cout << cur->data << " -> " ;
        cur = cur->next;
    }
    cout << endl;
}

void search(int value){
    Node* cur = list;
    while(cur != NULL){
        if(value == cur->data){
            cout << "Value is present in the List" << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Value not Found!" <<endl;
}

int main() {
    insert(22);
    insert(73);
    insert(94);
    insert(19);
    insert(82);
    insert(58);
    insert(55);
    insert(19);
    display();
    
    search(33);
    search(82);
    Delete(58);
    display();
}
