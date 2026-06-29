//Adjacency matrix = directed , weighted with DFS
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

// Node Stack is used for DFS
struct Node{
    int data;
    Node* next;
};

struct Stack{   //LIFO
    Node* top = NULL;
    
    void push(int value){
        Node* tmp = new Node();
        tmp->data = value;
        tmp->next = top;
        top = tmp;
    }
    
    int pop(){
        if(top == NULL){
            cout << "Stack Underflow" << endl;
            return -1;
        }else{
            Node* cur = top;
            int val = cur->data;
            top = top->next;
            delete cur;
            return val;
        }
    }
};

void DFS(int start){
    bool visited[n] = {false};
    Stack s;
    s.push(start);
    
    while(s.top != NULL){
        int v = s.pop();
        if(!visited[v]){
            visited[v] = true;
            cout << vertices[v] << " ";
            
            for(int j = countVertex -1; j >=0 ; j--){   //DFS uses a stack (LIFO). If you push neighbors in reverse order, they’ll be popped in the correct left‑to‑right order when visited.
                if(matrix[v][j] && !visited[j]){
                    s.push(j);
                }
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
    // display();
    
    DFS(0);
}
