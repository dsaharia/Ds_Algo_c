#include <stdio.h>

/*Program for a Singly Linked List.
    Printing Data, Number of Nodes*/

struct NODE *head;
typedef struct NODE{
    int x;
    struct NODE *next;

}node;


main() 
{
    node n1,n2,n3;
    int len;
    void print();
    int length();

    printf("---LINKED LIST---\n");
    n1.x = 1;
    n2.x = 2;
    n3.x = 3;

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    print(); //For Printing all the data in the NODES
    len = length(); // For calculating the Number of NODES
    printf("Number of NODES : %d\n",len);
}

void print(){
    node* trav;
    trav = head;
    while (trav != NULL){
        printf("Value at Nodes: %d\n",trav -> x);
        trav = trav -> next;
    }
}

int length(){
    node* trav;
    int counter=0;
    trav = head;
    while(trav != NULL){
        counter++;
        trav = trav -> next;
    }
    return counter;
}
