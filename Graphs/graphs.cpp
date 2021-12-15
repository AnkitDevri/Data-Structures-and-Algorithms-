using namespace std;
#include <bits/stdc++.h>
class node{
    public:
    int data;
    vector<node*> adjNode;
    node(){
        this->data = 0;
    }
};
class graph{
    public:
    node* start;
    int vertices;
    int edges;
    graph(){
        start = new node();
        vertices = 0;
        edges = 0;
    }
    // if need adjacent matrix
    //vector<vector<int>> adjMat;
    void bfs(node* start,vector<int>& bfs){
        
    }
    void insert(node* start,node* toInsert){

    }

};

int main(){
    graph a;
    
    getchar();
    return 0;
}