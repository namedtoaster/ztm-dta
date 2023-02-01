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
  Node* lookup(int val) {
    if (root == nullptr) {
      return nullptr;
    }
    Node* curr = root;
    
    while (curr != nullptr) {
      if (val < curr->value) {
	curr = curr->left;
      }
      else if (val > curr->value) {
	curr = curr->right;
      }
      else return curr;
    }

    return nullptr;
  }

  void remove(int val) {
    if (root == nullptr) return;

    Node* curr = root;
    Node* prnt = nullptr;

    while (curr) {
      if (val < curr->value) {
	prnt = curr;
	curr = prnt->left;
      }
      else if (val > curr->value) {
	prnt = curr;
	curr = prnt->right;
      }
      else {
	// option 1, no right child
	if (curr->right == nullptr) {
	  if (prnt == nullptr) {
	    root = curr->left;
	  } else {
	    // if parent > curr value, make curr left
	    // a child of parent
	    if (curr->value < prnt->value) {
	      prnt->left = curr->left;
	    }
	    // if parent < curr value, make curr left
	    // child of right child of parent
	    else if (curr->value > prnt->value) {
	      prnt->right = curr->left;
	    }
	  }
	}
	// option 2, right child but it doesn't
	// have left child
	else if (curr->right->left == nullptr) {
	  if (prnt == nullptr) {
	    root = curr->left;
	  }
	  else {
	    curr->right->left = curr->left;

	    // if parent > curr, make right child
	    // left of the parent
	    if (curr->value < prnt->value) {
	      prnt->left = curr->right;
	    }
	    // if parent < curr, make right child
	    // right of the parent
	    else if (curr->value > prnt->value) {
	      prnt->right = curr->right;
	    }
	  }
	}
	// option 3, right child that has
	// a left child
	else {
	  // find the right child's left most child
	  Node* leftmost = curr->right->left;
	  Node* leftmostPrnt = curr->right;
	  while (leftmost->left != nullptr) {
	    leftmostPrnt = leftmost;
	    leftmost = leftmostPrnt->left;
	  }

	  // parent's left subtree is now
	  // leftmost's right subtree
	  leftmostPrnt->left = leftmost->right;
	  leftmost->left = curr->left;
	  leftmost->right = curr->right;

	  if (prnt == nullptr) {
	    root = leftmost;
	  }
	  else {
	    if (curr->value < prnt->value) {
	      prnt->left = leftmost;
	    } else if (curr->value > prnt->value) {
	      prnt->right = leftmost;
	    }
	  }
	}
	return;
      }
    }
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

  bst.remove(1);
  printBST(bst);
  
  return 0;
}
