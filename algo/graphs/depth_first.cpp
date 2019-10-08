#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int v; // vertex
    list<int> *adj; // adjacency list
    
    public:
        Graph(int v);
        void add_edge(int src, int dest);
        void depth_first_search(int src);
        void print();
};

Graph::Graph(int v){
    this -> v = v;
    adj = new list<int>[this -> v];
}

void Graph::add_edge(int src, int dest){
    adj[src].push_back(dest);
}

void Graph::depth_first_search(int src){
    bool visited[this -> v];
    stack<int> stack;
    for (int i = 0; i < v; ++i){
        visited[i] = false;
    }
    stack.push(src);
    list<int>::iterator it;
    while(!stack.empty()){
        src = stack.top();
        stack.pop();
        cout << src << " ";
        visited[src] = true;
        for(it = adj[src].begin(); it != adj[src].end();it++){
            if(!visited[*it]){
                stack.push(*it);
            }
        }
    }
    cout << endl;
}

int main(){
    Graph g(5);  // Total 5 vertices in graph 
    g.add_edge(0, 3); 
    g.add_edge(0, 2); 
    g.add_edge(2, 1); 
    g.add_edge(3, 4); 
    g.add_edge(4, 0);
    g.add_edge(1, 0);

    cout << "Running DFS at 0" << endl;
    g.depth_first_search(0);
}