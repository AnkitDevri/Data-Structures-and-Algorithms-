#include<bits/stdc++.h>
using namespace std;
class graphNode{
    public: 
    int data;
    unordered_map<graphNode*,int> adjList; // node address and  weight 
    graphNode(int val){
        this->data = val;
    }
    
};
class Graph {
    graphNode* sourceNode;
    unordered_map<int,graphNode*> visited;
    public:
        Graph(int n) {
            for(int i = 1; i <= n; i++){
                graphNode* temp = new graphNode(i);
                visited.insert({i,temp});
            }
        }
    
        void add_edge(int u, int v) {
            graphNode* u_node = visited[u];
            graphNode* v_node = visited[v];
            u_node->adjList.insert({v_node,6});
            v_node->adjList.insert({u_node,6});

        }
    
        vector<int> shortest_reach(int start) {
            this->sourceNode = visited[start];
            
           
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            //u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        //startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId-1) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}