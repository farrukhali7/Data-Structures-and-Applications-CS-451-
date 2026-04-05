#include <iostream>
using namespace std;

struct Node{
   int data;
   Node* next;
};

struct stack{
    Node* top = NULL;

    void push(int value){
        Node* tmp = new Node();
        tmp->data = value;
        tmp->next = top;
        top = tmp;
        cout << value << " is pushed in the stack" << endl;
    } 

int pop(){
    if(top == NULL){
        cout << "Stack underflow" << endl;
        return -1;
    }else{
        Node* tmp = top;
        int val = tmp->data;
        top = top->next;
        delete tmp;
        cout << val << " is deleted from the list" << endl;
        return val;
    }
}

void display(){
    if(top == NULL){
        cout << "Stack is empty" << endl ;
        return;
    }else{
    Node* cur = top;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    }
}
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    
    s.pop();
    s.display();
}
