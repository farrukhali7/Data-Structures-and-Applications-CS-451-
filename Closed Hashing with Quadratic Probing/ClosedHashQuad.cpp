//closed hasing using quadtratic probing
#include <iostream>
using namespace std;

const int table_size = 10;
int HT[table_size] = {-1 ,-1 , -1 , -1 , -1 ,-1,-1,-1,-1,-1};       //initializing value for all array elements or you can create a loop and assign all values with -1

void insert(int value){
    int ind = value % table_size;
    int quadraticNums = 1;
    
    while(HT[ind] != -1){
        ind = (ind + (quadraticNums * quadraticNums)) % table_size;
        quadraticNums = quadraticNums + 1;
        
        if(quadraticNums > table_size){
            cout << "Hashtable is full" << endl;
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

void Delete(int value){
    int ind = value % table_size;
    int quadraticNums = 1;
    
    while(HT[ind] != -1){
        if(value == HT[ind]){
            HT[ind] = -2;   //-2 as a sign of deleted value
            cout << "Value deleted at index: " << ind << endl;
            return;
        }else{
            ind = (ind + quadraticNums * quadraticNums) % table_size;
        quadraticNums = quadraticNums + 1;
        if(quadraticNums > table_size){
            break;
        }
        }
    }
        cout << "Value Not found!" << endl;
}

void search(int value){
    int ind = value % table_size;
    int quadraticNums = 1;
    
    while(HT[ind] != -1){
        if(value == HT[ind]){
            cout << "Value Found at index: " << ind << endl;
            return;
        }
        ind = (ind + quadraticNums * quadraticNums) % table_size;
        quadraticNums++;
        if(quadraticNums > table_size) break;
    }
    cout << "Value not Found!" << endl;
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
    search(12);
    Delete(99);
    display();
}
