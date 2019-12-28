#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
}TreeNode;

class Traversal {
public:
    TreeNode* makeTree(int* values);
    vector<int> preorderTraversal(TreeNode* root);
};

TreeNode* Traversal::makeTree(int* values){
    
}

int main(){

}
