#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;     //in doubly linked list traversal is both sided
};

Node* list = NULL;      //list is the starting point
void insert(int value){
    // tmp = (Node*)malloc(sizeof(Node)); or we can use:
    Node* tmp = new Node();
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = NULL;
    
    if(list == NULL){        //if list is empty make the tmp the head of the list
        list = tmp;
    }else{
        Node* cur = list;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = tmp;        //points forward 
        tmp->prev = cur;        //points backward => this and above are used for doubly linked list
    }
}

void display(){
    Node* cur = list;
    while(cur->next != NULL){
        cout << cur->data << "  ";
        cur = cur->next;
    }
    cout << "\n";
}


void search(int value){
    Node* cur = list;
    while(cur != NULL){     //loop until the last element
        if(value == cur->data){
            cout << "Value is Present! \n";
            return;
        }
        cur = cur->next;
    }
    cout << "Value is NOt Present in the List! \n";
}

void deleteElement(int value){
    Node* cur = list;
    while(cur != NULL){
        if(cur->data == value){
            //deleting head
            if(cur == list){
                list = cur->next;
                if(list != NULL){
                    list->prev = NULL;
                }
            }else{
                if(cur->prev != NULL){
                    cur->prev->next = cur->next;
                }
                if(cur->next != NULL){
                    cur->next->prev = cur->prev;
                }
            }
            delete cur;  // free memory
            return;
        }
        cur = cur->next;
    }
    cout << "Value not found!\n";
}

void sorting(){
    //Bubble sort:
    if(list == NULL){
        return;
    }
    Node* i;
    Node* j;        //used for comparing values from i
    int tmp;        // so that we can swap values(pointer is not used so that we can swap values not addresses)
    
     for(i = list; i->next != NULL ; i = i->next){      //list is the starting position(head)
         for( j = i->next ; j != NULL; j = j->next){        //starts after i
             if(i->data > j->data){
                 tmp = i->data;
                 i->data = j->data;
                 j->data = tmp;
             }
         }
     }
}


int main() {
    insert(93);
    insert(87);
    insert(72);
    insert(64);
    insert(57);
    insert(49);
    insert(36);
    insert(24);
    insert(13);
    display();
    
    search(36);
    search(77);
    deleteElement(87);
    
    sorting();
    
    display();
}
