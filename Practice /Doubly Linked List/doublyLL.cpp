// doubly linked list

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* list = NULL;
void insert(int value){
    Node* tmp = new Node();
    tmp->data = value;
    tmp->prev = NULL;
    tmp->next = NULL;
    
    if(list == NULL){
        list = tmp;
    }else{
        Node* cur = list;
        while(cur->next != NULL){
        cur = cur->next;
        }
        cur->next = tmp;
        tmp->prev = cur;
        cout << "Value " << value << " inserted" <<  endl;
    }
}

void Delete(int value){
    if(list == NULL){
        cout << "List is empty" << endl;
        return;
    }
    
    Node* cur = list;
    while(cur != NULL){
        if(cur->data == value){
            if(cur->prev == NULL){
                list = cur->next;
                if(list != NULL) {
                    list->prev = NULL;
                }
            }else{
                cur->prev->next = cur->next;
                if(cur->next != NULL){
                    cur->next->prev = cur->prev; 
                }
            }
            delete cur;
            cout << "Value " << value << " is deleted"<< endl; 
            return;
            }
            cur = cur->next;
        }
        cout << "Value is not present" <<endl;
}

void search(int value){
    Node* cur = list;
    while(cur != NULL){
        if(value == cur->data){
            cout << "Value Found!" << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Value Not Found!" << endl;
}

void display(){
    Node* cur = list;
    while(cur != NULL){
        cout << cur->data << " <-> "; 
        cur = cur->next;
    }
    cout << endl;
}


int main(){
    insert(22);
    insert(74);
    insert(55);
    insert(18);
    insert(97);
    insert(81);
    insert(66);
    insert(70);
    display();
    
    search(88);
    search(81);
    Delete(97);
    display();
}
