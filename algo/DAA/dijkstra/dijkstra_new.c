#include <stdio.h>
#include <stdlib.h>
/* The graph vertices are labeled as 1,2,3,4,5 but represented as 0,1,2,3,4 */
typedef struct ListNode{
	int vertex_number;
	int weight;
	struct ListNode* next;
}Node;

typedef struct Graph {
    int no_vertices;
    int source;
    int total_weight;
    Node* list;

}Graph;

Graph* initialize_graph(FILE *fnodes, Graph *graph) {
    int total_vertex, source;
	fscanf(fnodes, "%d,%d", &total_vertex, &source);
    graph -> no_vertices = total_vertex;
    graph -> source = source;
    graph -> list = (Node*)malloc(sizeof(Node) * (graph->no_vertices));

    return graph;
}

Node* adjacency_list(FILE *fnodes, Graph * graph) {
	int total_weight=0, start, end, weight;
	Node *temp;
	Node *trav = graph -> list;
	// Preprocessing of the adjacency list
	for (int i = 0; i < graph->no_vertices; ++i)
	{
		graph -> list[i].vertex_number = i; // to represent each vertex
		graph -> list[i].next = NULL;
	}
	
	
	while(fscanf(fnodes, "%d,%d,%d", &start, &end, &weight) == 3) {
	    temp = (Node *)malloc(sizeof(Node));
		temp -> vertex_number = end;
		temp -> next = NULL;
		temp -> weight = weight;
	    trav  = &(graph -> list[start - 1]);
	    while(trav -> next != NULL) {
			trav = trav -> next;
		}
	    trav -> next = temp;
	    total_weight += weight;
	}
	graph -> total_weight = total_weight;
    return graph -> list;
}

void print(Graph *graph) {
    Node* trav = graph -> list;
	for (int i = 0; i < graph -> no_vertices; ++i)
	{
		trav = &(graph -> list[i]);
		printf("V no. : %d ", graph -> list[i].vertex_number);
		while (trav -> next != NULL) {
			printf("DEST : %d \n", trav -> next -> vertex_number);
			trav = trav -> next;
		}
	}
	printf("\n");
}


int main() {
	FILE *fnodes = fopen("nodes.txt", "r");
    Graph *graph;
	graph = initialize_graph(fnodes, graph);
	printf("%d %d %p\n", graph->no_vertices, graph->source, graph->list);
	graph -> list = adjacency_list(fnodes, graph);
	print(graph);
}