#include <iostream>
#include <list>
using namespace std;

class Graph{
    int v; // vertex
    list<int> *adj; // adjacency list
    
    public:
        Graph(int v);
        void add_edge(int src, int dest);
        void breadth_first_search(int src);
        void print();
};

Graph::Graph(int v){
    this -> v = v;
    adj = new list<int>[this -> v];
}

void Graph::add_edge(int src, int dest){
    adj[src].push_back(dest);
}

void Graph::breadth_first_search(int src){
    bool visited[this -> v]; // for removing duplicate visits to a node
    list<int> queue; // for performing the BFS
    for (int i = 0; i < v; ++i){
        visited[i] = false;
    }
    visited[src] = true; // for the starting node
    queue.push_back(src);
    list<int>::iterator it;
    while(!queue.empty()){
        src = queue.front();
        cout << src << " ";
        queue.pop_front();
        for(it = adj[src].begin(); it != adj[src].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
    cout << endl;

}

// void Graph::print(){
//     for (int i = 0; i < v; ++i){
        
//     }
// }

int main(){
    Graph graph(4);
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);

    cout << "Running BFS at 2" << endl;
    graph.breadth_first_search(2);
}