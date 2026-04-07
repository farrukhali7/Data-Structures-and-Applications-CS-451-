//closed hasing using linear probing
#include <iostream>
using namespace std;

const int table_size = 10;
int HT[table_size] = {-1 ,-1 , -1 , -1 , -1 ,-1,-1,-1,-1,-1};       //initializing value for all array elements or you can create a loop and assign all values with -1

void insert(int value){
    int ind = value % table_size;
    int start = ind;
    
    while(HT[ind] != -1){
        ind = (ind + 1) % table_size;
        if(ind == start){
            cout << "HashTable is full" << endl;
            return;
        }
    }
    HT[ind] = value;
    cout << value << " inserted at index: " << ind << endl;
}

void display(){
    for(int i = 0; i < table_size; i++){
        cout << i << ": " << HT[i] << endl;
    }
}

void searchAndDelete(int value){
    for(int i = 0 ; i < table_size ; i++){
        if(value == HT[i]){
            //delete(HT[i]);  //delete(HT[i]); is invalid because delete is used to free memory allocated with new
            HT[i] = -1;
            cout << "Value Found and deleted at index: " << i << endl;
        }
    }
}

int main() {
    insert(15);
    insert(25);
    insert(35);
    insert(5);
    insert(12);
    insert(42);
    insert(99);
    insert(63);
    
    display();
    searchAndDelete(12);
    searchAndDelete(99);
    display();
}
