#include <iostream>
using namespace std;

void BinarySearch(int arr[] , int length ,int value){
    // for(int i = 0 ; i < length ; i++){
    //     cout << arr[i] << " ";     //sorted array is received
    // }
    
    int low = 0;
    int high = length - 1;      // it means 9
    
    while(low <= high){
    int mid = (high+low) / 2;
        
    if( arr[mid] == value ){
        cout << "Value " << value << " is Found";
        return;
    }else if(arr[mid] < value){
        low = mid + 1;
    }else{
        high = mid -1;
    }
    }
    cout << "Value Not Found!" << endl;
}

void bubbleSort(int arr[] , int length){
    int tmp = 0;
    for(int i = 0 ; i < length-1 ; i++){        //outer loop used for looping through elements in array
        for(int j = 0 ; j < length -i -1; j++){     //inner loop used for comparison
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1] ;
                arr[j + 1] = tmp;
            }
        }
    }
    for(int index = 0; index < length ; index ++){
        cout << arr[index] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4,1,7,2,8,3,9,5,10,6};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr , length);
    int value = 14;
    BinarySearch(arr , length , value);
    value = 7;
    BinarySearch(arr , length , value);
}

