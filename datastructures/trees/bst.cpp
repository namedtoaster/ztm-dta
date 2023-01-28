#include <iostream>

class BinarySearchTree {
public:
  BinarySearchTree() {}
  BinarySearchTree(int val) {
    root = new Node(val);
  }
  ~BinarySearchTree() {}

  class Node {
    friend class BinarySearchTree;
  public:
    Node() {}
    Node(int val) : value(val) {}
    const int getValue() const { return value; }
    const Node* getL() const { return left; }
    const Node* getR() const { return right; }
  private:
    Node* left = nullptr;
    Node* right = nullptr;
    int value;
  };

  void insert(int val) {
    Node* newNode = new Node(val);
    
    if (root == nullptr) {
      root = newNode;
    }
    else {
      Node* curr = root;

      while (curr != nullptr) {
	if (val < curr->value) {
	  if (curr->left == nullptr) {
	    curr->left = newNode;
	    return;
	  }
	  else {
	    curr = curr->left;
	  }
	}
	else if (val > curr->value) {
	  if (curr->right == nullptr) {
	    curr->right = newNode;
	    return;
	  }
	  else {
	    curr = curr->right;
	  }
	}
	else {
	  std::cout << "Value already exists" << std::endl;
	  return;
	}
      }
    }
  }
  void lookup(int val) {
  }

  const Node* getRoot() const {
    return root;
  }
  
private:
  Node* root = nullptr;
};


void printBST(const std::string& prefix,
	      const BinarySearchTree::Node* node,
	      bool isLeft) {
  if( node != nullptr ) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──" );

    // print the value of the node
    std::cout << node->getValue() << std::endl;

    // enter the next tree level - left and right branch
    printBST( prefix + (isLeft ? "│   " : "    "), node->getL(), true);
    printBST( prefix + (isLeft ? "│   " : "    "), node->getR(), false);
  }
}

void printBST(const BinarySearchTree& bst) {
  if (bst.getRoot() != nullptr)
    printBST("", bst.getRoot(), false);
  else
    std::cout << "BST is empty" << std::endl;
}

// create a BST that looks like this:
//      9
//   4     20
// 1  6  15  170

int main() {
  BinarySearchTree bst;
  bst.insert(9);
  bst.insert(4);
  bst.insert(6);
  bst.insert(20);
  bst.insert(170);
  bst.insert(15);
  bst.insert(1);
  printBST(bst);
  return 0;
}
