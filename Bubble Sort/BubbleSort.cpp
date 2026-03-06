#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int length){
    int tmp;
    for(int i = 0 ; i < length - 1; i++){
        for(int j =0 ; j < length - i -1 ; j++){
            if(arr[j] > arr[j + 1]){
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            }
        }
    }
}

int main(){
    int arr[] = {8,5,2,83,74,82,25,75,35,79,62,1,93};;
    int length = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr , length);
    for(int i =0 ; i< length ;i++){
        cout << arr[i] << " ";
    }
}
