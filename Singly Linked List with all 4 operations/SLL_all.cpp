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

void Delete(int value){
    if(list == NULL){
        cout << "There are no elements in the list";
        return;
    }
    Node* cur = list;
    if(value == list->data){
        list = list->next;
        free(cur);
        return;
    }
    cur= list->next;
    Node* prev = list;
    while(cur != NULL){
        if(value == cur->data){
            prev->next = cur->next;
            free(cur);
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
}

void print(){
    Node* cur = list;
    while(cur != nullptr){
        cout << cur->data << " ";
        cur = cur->next;
    }
}

void sorting(){
    if(list == NULL){
        return;
    }
    
    Node* i;
    Node* j;
    int tmp;
    for(i = list ; i->next != NULL ; i = i->next){
        for(j = i->next ; j != NULL ; j = j->next){
            if(i->data > j->data){
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

int main(){
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(5);
    insert(11);
    insert(12);
    insert(42);
    insert(22);
    insert(52);
    insert(78);
    insert(94);
    insert(68);
    print();
    
    cout << "\n \t Updated List: \n \t \t";
    Delete(9);
    Delete(22);
    Delete(12);
    Delete(7);
    
    sorting();
    print();
    
}
