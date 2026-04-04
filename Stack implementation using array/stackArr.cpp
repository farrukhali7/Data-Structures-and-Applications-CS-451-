//Stack(LIFO) implemented by using an array(static)

#include <iostream>
using namespace std;

struct Stack{       
    int arr[10];
    int top = 0;
    
    void push(int value){
        if(top == 10){
            cout << "Stack overflow " << endl;
            return;
        }else{
            arr[top] = value;
            top++;
            cout << value << " added into the array." << endl;
        }
    }
    
    void pop(){
        if(top == 0){
            cout << "Stack underflow" << endl;
            return;
        }else{
            --top;
            int val = arr[top];
            cout << val << " is removed" << endl;
        }
    }
    
    void display(){
        for(int i = 0; i < top ; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    Stack s;
    s.pop();
    s.push(64);
    s.push(11);
    s.push(53);
    s.display();
    s.pop();
    s.display();
    
    s.push(65);
    s.push(92);
    s.push(26);
    s.push(37);
    s.push(19);
    s.pop();
    s.pop();
    s.push(02);
    s.push(66);
    s.push(17);
    s.push(83);
    s.push(52);
    s.push(73);
    s.display();
}
