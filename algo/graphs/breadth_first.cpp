#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    int v; // vertex
    vector<vector<int>> adj; // adjacency list
    
    public:
        Graph(int v);
        void add_edge(int src, int dest);
        void breadth_first_search(int src);
        void print();
};

Graph::Graph(int v){
    this -> v = v;
    adj.resize(this -> v);
}

void Graph::add_edge(int src, int dest){
    adj[src].push_back(dest);
}

void Graph::breadth_first_search(int src){
    queue<int> q;
    bool visited[this -> v];
    int distance[this -> v];
    int to_explore;
    q.push(src);
    visited[src] = true; // visited the source
    distance[src] = 0;
    while(!q.empty()){
	to_explore = q.front();
	//cout << to_explore << "\n";
	q.pop();
	for(int i:adj[to_explore]){
	    if(visited[i] == false) {
		cout << i << "\n";
		q.push(i);
		visited[i] = true;
		distance[i] = distance[to_explore] + 1;
	    }
	}


    }


}
/*void Graph::breadth_first_search(int src){
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

}*/


void Graph::print(){
    for(auto i:adj){
	for(auto j: i){
	    cout << j << " ";
	}
	cout << "\n";
    }
}

int main(){
    Graph graph(6);
    graph.add_edge(0, 3);
    graph.add_edge(0, 1);
    graph.add_edge(1, 0);
    graph.add_edge(1, 4);
    graph.add_edge(1, 2);
    graph.add_edge(2, 1);
    graph.add_edge(2, 5);
    graph.add_edge(3, 0);
    graph.add_edge(4, 1);
    graph.add_edge(4, 5);
    graph.add_edge(5, 2);
    graph.add_edge(5, 4);

    cout << "Running BFS at Node 0" << endl;
    graph.breadth_first_search(0);
    //graph.print();
}
