//Adjacency matrix = directed , weighted with BFS
#include <iostream>
using namespace std;

const int n = 5;
int matrix[n][n];
int vertices[n];
int countVertex = 0;

void insertVertex(int value){
    if(countVertex >= n){
        cout << "Limit cannot exceed!";
        return;
    }else{
        vertices[countVertex] = value;
        countVertex++;
    }
}

int findIndex(int value){
    for(int i = 0;i < countVertex ; i++){
        if(vertices[i] == value){
            return i;
        }
    }
        return -1;
}

void insertEdge(int source , int dest , int distance){
    int i = findIndex(source);
    int j = findIndex(dest);
    
     if(i == -1 || j == -1){
         cout << "Vertex not found!" << endl;
         return;
     }
     matrix[i][j] = distance;
     cout << "Edge created from: " << source << " to " << dest << " with a distance of: " << distance << endl;
}

void display(){
    for(int i =0;i < n; i++){
        for(int j =0;j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Node and Queue is used for BFS
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

int deQueue(){
    if(front == NULL){
        cout << "Queue Underflow" << endl;
        return -1;
    }else{
        Node* tmp = front;
        int val = front->data;
        front = front->next;
        delete tmp;
        cout << val << " dequeued" << endl;
        return val;
    }
}
};


void BFS(int start){
    
    bool visited[n] = {false};
    Queue q;
    q.enQueue(start);
    visited[start] = true;
    
    while(q.front != NULL){
        int v = q.front->data;
        q.deQueue();
        cout << vertices[v] << " ";
        
        for(int j = 0;j <countVertex; j++){
            if(matrix[v][j] !=0 && !visited[j]){    //if there's an edge from v to j and the neighbour is not visited 
                q.enQueue(j);
                visited[j] = true;
            }
        }
    }
}


int main(){
    insertVertex(1);
    insertVertex(2);
    insertVertex(3);
    insertVertex(4);
    insertVertex(5);

    insertEdge(1,4 ,6);     //Row 1 -> column 4 = 0 10 0 6 0 
    insertEdge(1 ,2 ,10);    
    insertEdge(2, 3, 22);    
    insertEdge(4,5,2);       
    insertEdge(5,1,9);       
    insertEdge(5, 3,6);      
    insertEdge(3,1,4);      
    display();
    
    BFS(0);
}
