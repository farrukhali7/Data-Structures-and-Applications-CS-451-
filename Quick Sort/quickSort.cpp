// quick SOrt
#include <iostream>
using namespace std;

int quickSort(int arr[], int f , int l){
    int pivot = arr[l];
    int i = f - 1;   //before the first element, nothing is in the “smaller than pivot” group yet.
    
    for(int j = f; j < l ; j++){
        if(arr[j] <= pivot){
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    
    int tmp = arr[i + 1];
    arr[i + 1] = arr[l];
    arr[l] = tmp;
        
    return i + 1;
}

void qq(int arr[] ,int f , int l){
    if(f < l){
        int pi = quickSort(arr ,f , l);
        qq(arr ,f , pi - 1); //-1 denotes stop before pivot       //sort right half    //uses recursive functions
        qq(arr ,pi + 1 , l);        //sort left half
    }
}

void display(int arr[] , int size){
    for(int i = 0 ; i< size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {8,5,10,4,6,2,1,0,3,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    qq(arr ,0 , size - 1);
    display(arr,size);
}
