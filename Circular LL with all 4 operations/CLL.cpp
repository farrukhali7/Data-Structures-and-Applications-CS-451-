#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* list = NULL;      //list means head/start
void insert(int value){
    // tmp = (Node*)malloc(sizeof(Node));
    Node* tmp = new Node();
    tmp->data = value;
    
    if(list == NULL){
        list = tmp;
        list->next = list;
    }else{
        Node* cur = list;
        while(cur->next != list){
            cur = cur->next;
        }
        cur->next = tmp;
        tmp->next = list;
    }
}



void searchAndDelete(int value){
   if (list == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* cur = list;
    Node* prev = NULL;
    // deleting list or starting point
    if (list->data == value) {
        // If only one node
        cout << "Value " << value << " is found and present in the list.\n";
        if (list->next == list) {
            delete list;
            list = NULL;
            return;
        }
        //finding last node(when more than 1 element is present)
        Node* last = list;  //last is pointing at the list
        while (last->next != list) {
            last = last->next;  //Move last forward so it now points to the next node in the chain.
        }
        last->next = list->next;   // last points to new head
        Node* temp = list;
        list = list->next;         //list or new starting point
        delete temp;
        return;
    }

    // for middle cases:
    do {
        prev = cur;
        cur = cur->next;
        if (cur->data == value) {
            cout << "Value " << value << " is found and present in the list.\n";
            prev->next = cur->next;
            delete cur;
            return;
        }
    } while (cur != list);

    cout << "Value not found!\n";
}




void print(){
    if(list == NULL){
        cout << "List is Empty!";
        return;
    }
    Node* cur = list;
    do{
        cout << cur->data << " ";
        cur = cur->next;
    }while(cur != list);
        cout << "";
}



void sorting(){
    if(list == NULL){
        return;
    }
    
    Node* i;
    Node* j;
    int tmp;
    for(i = list ; i->next !=list ; i = i->next ){
        for( j = i->next ; j !=list ; j = j->next){
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
    searchAndDelete(9);
    searchAndDelete(22);
    searchAndDelete(17);
    searchAndDelete(7);
    
    sorting();
    print();
    
}
