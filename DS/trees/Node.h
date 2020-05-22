
class Node {
    // This is the Node class for every entry.
    public:
	int data; // value
	Node* left; // ptr to left child
	Node* right; // ptr to right child

	Node(int val) {
	    this -> data = val;
	    this -> left = NULL;
	    this -> right = NULL;
	}

};
