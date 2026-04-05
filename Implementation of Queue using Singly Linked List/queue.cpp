#include <iostream>
using namespace std;

struct Node{
   int data;
   Node* next;
};

struct Queue{       //FIFO 
    Node* front = NULL;
    Node* end = NULL;
    
    void enQueue(int value){
       Node* tmp = new Node();
       tmp->data = value;
       tmp->next = NULL;
       
       if(front == NULL || end == NULL){        //both means the same 
           front = end =tmp;
       }else{
           end->next = tmp; //this attaches new node(tmp) to the end of the node(end)
           end = tmp;   //this pointer will now points to the new last node
       }
       cout << value << " enqueued" << endl;
    } 

void deQueue(){
    if(front == NULL){
        cout << "Queue Underflow" << endl;
        return ;
    }else{
        Node* tmp = front;
        int val = front->data;
        front = front->next;
        delete tmp;
        cout << val << " dequeued" << endl;
    }
}

void display(){
    if(front == NULL){
        cout << "List is Empty" <<  endl;
        return;
    }else{
        Node* cur = front;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }  
}
};

int main(){
 Queue q;
q.enQueue(56);
q.enQueue(93);
q.enQueue(22);
q.display();

q.deQueue();
q.display();

q.enQueue(72);
q.enQueue(16);
q.enQueue(94);
q.deQueue();
q.display();
}
