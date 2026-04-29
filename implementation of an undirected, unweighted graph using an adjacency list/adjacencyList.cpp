#include <iostream>
using namespace std;

struct Edge;
struct Vertex{
    int data;
    Vertex* next;
    Edge* edgeList;
};

struct Edge{
    Vertex* V;      
    Edge* next;
    Edge* prev;
};

Vertex* list = NULL;
void insertVertices(int value){
    Vertex* tmp = new Vertex();
    tmp->data = value;
    tmp->next = NULL;
    tmp->edgeList = NULL;
    
    if(list == NULL){
        list = tmp;
    }else{
        Vertex* cur = list;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = tmp;
    }
        cout << "Vertex: " << value << " is added!" << endl;
}



void insertEdgeList(int vertex ,int value){
    Vertex* cur = list;
    //source <->destination 
    while(cur !=NULL && cur->data != vertex){
        cur = cur->next;
    }if(cur == NULL){
        cout << "vertex not found!" << endl;
        return;
    }
    
    Vertex* dest = list;
    while(dest != NULL && dest->data != value){
        dest = dest->next;
    }if(dest == NULL){
        cout << "Vertex not found!" << endl;
        return;
    }
    
    Edge* tmp = new Edge();
    tmp->V = dest;  //pointer for destination vertex
    tmp->next = NULL;
    tmp->prev = NULL;
    
    if(cur->edgeList == NULL){
        cur->edgeList = tmp;
    }else{
        Edge* ecur = cur->edgeList;
        while(ecur->next != NULL){
            ecur = ecur->next;
        }
        ecur->next = tmp;
        tmp->prev = ecur;
    }
    cout << "Edge created from " << vertex << " to " << value << endl;
}


void addEdge(int u , int v){
    insertEdgeList(u , v);
    insertEdgeList(v , u);
}



void display(){
    Vertex* cur = list;
    while(cur != NULL){
        cout << cur->data << " -> " ;
        Edge* ecur = cur->edgeList;
        while(ecur != NULL){
            cout << ecur->V->data << " -> ";
            ecur = ecur->next;
        }
        cout << endl;
        cur = cur->next;
    }
}

int main(){
    insertVertices(1);
    insertVertices(2);
    insertVertices(3);
    insertVertices(4);
    insertVertices(5);
    display();
    
    addEdge(1,4);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(4,5);
    addEdge(5,1);
    addEdge(5,3);
    addEdge(3,1);
    display();
}
