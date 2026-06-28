// Max Heap
#include <iostream>
using namespace std;

const int n = 100;
int arr[n];
int capacity = n;
int heapSize = 0;

void upHeapify(int arr[] , int index){
    if(index == 0){
        return;
    }
    int parent = (index - 1) / 2;
    if(arr[parent] < arr[index]){
        swap(arr[parent] , arr[index]);
        upHeapify(arr , parent);    //why parent?
    }
}

void downHeapify(int arr[] ,int index ,int heapSize){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if(left >= heapSize){   // left is first one where value is inserted
        return;
    }
    int largest = index;
    if(arr[left] > arr[largest]){
        largest = left;
    }
    if(arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != index){   //means
        swap(arr[index] , arr[largest]);
        downHeapify(arr , largest , heapSize);
    }
}

void insert(int value){
    if(heapSize == n){
        cout << "Heap is full" << endl;
        return;
    }
    arr[heapSize] =  value;
    upHeapify(arr , heapSize);  //size is the index of the newly inserted element before incrementing.
    heapSize++;
}

void deleteRoot(){
    if(heapSize == 0){
        cout << "Heap is empty!" << endl;
        return;
    }
    swap(arr[0] , arr[heapSize - 1]);
    heapSize--;
    downHeapify(arr , 0 , heapSize);
}

bool search(int value){
    if(heapSize == 0){
        cout << "Heap is empty!" << endl;
        return false;
    }
    for(int i = 0 ; i < heapSize ; i++){
        if(arr[i] == value){
            cout << "Value found!" << endl;
            return true;
        }
    }
            return false;
}

void heapSort(){
    int tmp[n];
    int tmpSize = heapSize;
    for(int i = 0; i < heapSize ; i++){
        tmp[i] = arr[i];
    }
    
    for(int i =tmpSize - 1; i > 0 ; i--){
        swap(tmp[0] , tmp[i]);
        downHeapify(tmp , 0 , i);
    }
    
    cout << "Sorted:";
    for(int i = 0 ; i < tmpSize ; i++){
        cout << " " << tmp[i];
    }
    cout << endl;
}

void display(){
    for(int i = 0 ; i < heapSize ; i++){
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    insert(12);
    insert(7);
    insert(15);
    insert(32);
    insert(64);
    insert(82);
    insert(23);
    insert(28);
    insert(10);
    deleteRoot();
    
    display();
    
    heapSort();
}
