#include <iostream>
using namespace std;

int binarySearch(int arr[] , int value , int length){
    for(int i = 0; i <= length ; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int value = 6;
    int length = sizeof(arr) / sizeof(arr[0]);
    
    int result = binarySearch(arr ,value , length);
    if(result = -1){
        cout << "Value Not Found" ; 
    }else {
        cout << "Value Found at : " ;
    }
    
}



