#include "Bst.h"
BinarySearchTree::BinarySearchTree(){
	root = nullptr;

}

void BinarySearchTree::insert(int x) {
	insert(x, root);
}

int BinarySearchTree::find(int  x)
{
	return elementAt(find(x, root));
}

int BinarySearchTree::elementAt(BinaryNode* t)
{
	if (t == NULL)
		return (-1);
	else
		return  (t->element);
}

BinaryNode* BinarySearchTree::find(int  x, BinaryNode* t)
{
	if (t == NULL)
		return NULL;
	else if (x < t->element)
		return find(x, t->left);
	else if (t->element < x)
		return find(x, t->right);
	else
		return  t;		      // match
}

BinaryNode* BinarySearchTree::findMin(BinaryNode* t)
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);

}

BinaryNode* BinarySearchTree::findMax(BinaryNode* t)
{
	if (t != NULL)
		while (t->right != NULL)
			t = t->right;
	return t;

}

void  BinarySearchTree::insert(int x, BinaryNode*& t)
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else;				// duplicate; do nothing
}

void  BinarySearchTree::remove(int x, BinaryNode*& t)
{
	if (t == NULL)
		return;    			// item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);

	// Two children	
	else  if (t->left != NULL && t->right != NULL)
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode* oldNode = t;
		if (t->left != NULL) 		// only left child
			t = t->left;
		else				// only right child
			t = t->right;
		delete oldNode;
	}
}	// end remove

void BinarySearchTree::printTree(BinaryNode* ptr,int level)
{
	/*if (tree != NULL) {
		printTree(tree->left);	      // traverse left subtree
		cout << tree->element << " ";    // visit root
		printTree(tree->right);                // traverse right subtree
	}*/
	int i;

	if (ptr != NULL) {
		printTree(ptr->right, level + 1);
		printf("\n");
		if (ptr == root) {
			cout << "Root->";
		}
		for (i = 0; i < level && ptr != root; i++) {
			cout << "		";
		}
		cout << ptr->element;
		printTree(ptr->left, level + 1);
	}

}
void BinarySearchTree::printTree() {
	printTree(root,tree_height(root));
}
void BinarySearchTree::makeEmpty(BinaryNode*& t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}
// Find height of a tree, defined by the root node
int BinarySearchTree::tree_height(BinaryNode* root) {
	if (root == NULL)
		return 0;
	else {
		// Find the height of left, right subtrees
		Left_H = tree_height(root->left);
		Right_H = tree_height(root->right);

		// Find max(subtree_height) + 1 to get the height of the tree
		return max(Left_H, Right_H) + 1;
	}
}
int BinarySearchTree::max(int left, int right) {
	if (left > right) {
		return left;
	}
	return right;
}
BinarySearchTree :: ~BinarySearchTree()
{
	makeEmpty(root);
}