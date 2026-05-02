//Insertion Sort
#include <iostream>
using namespace std;

void insertionSort(int arr[] , int size){
    for(int i = 1 ; i < size; i++){
        int sorted = arr[i];
        int j = i - 1;
            while(j>=0 && arr[j] > sorted){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = sorted;
    }
}

void display(int arr[] , int size){
    for(int i = 0;i < size; i++){
            cout << arr[i] << " " ;
    }
        cout << endl;
}

int main() {
    int arr[] = {8,5,10,4,6,2,1,0,3,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr , size);
    display(arr , size);
}
