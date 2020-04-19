#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int N, source, destination;
    cout << "Enter number of Nodes: \n";
    cin >>  N;
    vector<int> adj_list[N+1]; // since graph is numbered from 1
    ifstream input("graph.txt");

    while(input >> source >> destination) {
	adj_list[source].push_back(destination);
    }
    // print the graph
    for(int i=0; i<=N; ++i){
	cout << "Node " << i << " --> ";
	for(int edge:adj_list[i]){
	    cout << edge << " ";
	}
	cout << "\n";
    }

}
