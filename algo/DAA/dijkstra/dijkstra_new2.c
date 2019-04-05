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

typedef struct Heap {
	int vertex;
	int score;
}Heap;

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
		printf("Vertex no. : %d ", graph -> list[i].vertex_number);
		while (trav -> next != NULL) {
			printf("DEST : %d \n", trav -> next -> vertex_number);
			trav = trav -> next;
		}
	}
	printf("\n");
}

void create_heap(Graph *graph, int *distance_array, Heap *heap) {
	int eff_nodes = graph -> no_vertices,k=0, j=1; // number of nodes except source
	Node *trav = &(graph -> list[graph -> source - 1]);
	heap = (Heap *)malloc((sizeof(Heap) * (eff_nodes)) - 1);
	for (int i = 0; i < eff_nodes-1; ++i)
	{
		heap[i].vertex = j;
		heap[i].score = (graph -> total_weight) + 15;
		j++;
	}
        while (trav -> next != NULL) {
        	for (int i = 0; i < eff_nodes - 1; ++i)
        	{
	        	if ((trav -> next -> vertex_number ) == heap[i].vertex) {
	            heap[i].vertex = trav -> next -> vertex_number;
	            heap[i].score = trav -> next -> weight;
        	}
        }
        	trav = trav -> next;
        }
        printf("--INITIAL HEAP--\n");
	for (int i = 0; i < eff_nodes - 1; ++i)
	{
		printf("Vertex and Weight: %d %d\n", heap[i].vertex, heap[i].score);
	}
	printf("\n");
}

int main() {
	FILE *fnodes = fopen("nodes.txt", "r");
    Graph *graph;
    Heap *heap;
    graph = (Graph *)malloc(sizeof(Graph));
    heap = (Heap *)malloc(sizeof(Heap));
	graph = initialize_graph(fnodes, graph);
	printf("Details of graph, Nodes and Source: %d %d\n", graph->no_vertices, graph->source);
	printf("--Adjacency List--(Started from Vertex number 0)\n");
	graph -> list = adjacency_list(fnodes, graph);
	printf("Total Weight: %d\n", graph -> total_weight);
	print(graph);
	int *distance_array; //distance array
    distance_array = (int *)malloc(sizeof(int) * (graph -> no_vertices));
    if (distance_array == NULL) {
    	printf("NO MEMORY\n");
    }
    for (int i = 0; i < (graph -> no_vertices); i++)
    {
    	distance_array[i] = (graph -> total_weight) + 15;
    }
    distance_array[(graph -> source) - 1] = 0; //Initial distance is 0 for source.
    // for (int i = 0; i < (graph -> no_vertices); i++)
    // {
    // 	printf("%d ", distance_array[i]);
    // }
    create_heap(graph, distance_array, heap);
}