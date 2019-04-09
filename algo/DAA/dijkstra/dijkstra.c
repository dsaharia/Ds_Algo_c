#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes {
	int vertex;
	int weight;
	struct Nodes* next;

}node;



int main()
{
	FILE *fnodes;
	int source, destination, weight, total_v, src;
	int total_weight = 0, i;
	fnodes = fopen("nodes.txt", "r");
	fscanf(fnodes, "%d,%d", &total_v, &src);
	node *list[total_v];
	while(fscanf(fnodes,"%d,%d,%d", &source, &destination, &weight) == 3) {
		node **trav; // traversing the list
		trav = &list[source - 1];
		(*trav) = (node*)malloc(sizeof(node));
		(*trav)->vertex = destination;
		(*trav)->weight = weight;
		(*trav)->next = NULL;
		printf("%d %d %d\n", source,(*trav)->vertex ,(*trav)->weight);
		total_weight += weight;
	}
	printf("Total Weight : %d\n", total_weight);
	int distance_array[total_v];
	for(i=0;i<total_v; i++) {
		distance_array[i] = total_weight + 10; // distance of every other vertices is large.
	}
	distance_array[src-1] = 0; // distance of source is 0

}
