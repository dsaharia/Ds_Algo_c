#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode {
    int data;
    struct bstNode *left;
    struct bstNode *right;

}bstnode;

bstnode* createNode(int data)
{
    bstnode *new; // Pointer to New Node
    new = (bstnode *) malloc(sizeof(bstnode));
    new -> data = data;
    new -> left = new -> right = NULL;
    return new;
}

bstnode* insert(bstnode* root,int data)
{
   if (root == NULL) 
   {
	root = createNode(data);
   }

   else if (data <= root -> data)
   {
	root -> left = insert(root -> left,data);
   }

   else if (data >= root -> data)
   {
	root -> right = insert(root -> right,data);
   }

   return root;

}

void display(bstnode* root)
{
    if(root == NULL)
    {
	return;
    }
    display(root -> left);
    printf("Data is: %d\n", root-> data);
    display(root -> right);
}

int main()
{
    bstnode *root = NULL; // Pointer to the root of tree
    root = insert(root,6);
    root = insert(root,8);
    root = insert(root,10);
    root = insert(root,24);
    root = insert(root,26);
    display(root);

}
