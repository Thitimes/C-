#include "AVL.h"

Node::Node(int theElement, Node* lt, Node* rt, int h )
{
	element = theElement; left = lt; right = rt; heightNum = h;
	
}
//Node construct
////////////////////////////////////////////////////////////////////////////
Avl::Avl() {
	root = nullptr;
}

/* return the height of node t, or -1 , if NULL */
int Avl::height(Node* t)
{
	if (t == NULL)
		return (-1);
	else
		return(t->heightNum);

}
void Avl::insertNode(int x, Node*& t)
{
	if (t == NULL) {
		t = new Node(x, NULL, NULL);
		
	}
	else if (x < t->element) {
		insertNode(x, t->left);
	}
	else if (t->element < x) {
		insertNode(x, t->right);
	}

	balance(t);
}

void Avl::balance(Node*& t)
{
	if (t == NULL)
		return;

	if (height(t->left) - height(t->right) == 2) //left is higher than right
		if (height(t->left->left) >= height(t->left->right))

			rotateWithLeftChild(t);

		else

			doubleWithLeftChild(t);

			if (height(t->right) - height(t->left) == 2) //right is higher than left
				if (height(t->right->right) >= height(t->right->left))

					rotateWithRightChild(t);

				else

					doubleWithRightChild(t);

					t->heightNum = findMax(height(t->left), height(t->right)) + 1;
}

void Avl::rotateWithLeftChild(Node*& k2)
{
	Node* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->heightNum = findMax(height(k2->left), height(k2->right)) + 1;
	k1->heightNum = findMax(height(k1->left), k2->heightNum) + 1;
	k2 = k1;
}
//maybe wrong
void Avl::rotateWithRightChild(Node*& k2)
{
	Node* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->heightNum = findMax(height(k2->right), height(k2->left)) + 1;
	k1->heightNum = findMax(height(k1->right), k2->heightNum) + 1;
	k2 = k1;
}

void Avl::doubleWithLeftChild(Node*& k3)
{
	// Rotate between k1 and k2
	rotateWithRightChild(k3->left);
	// Rotate between k3 and k2
	rotateWithLeftChild(k3);
}
//maybe wrong
void Avl::doubleWithRightChild(Node*& k3)
{
	// Rotate between k1 and k2
	rotateWithLeftChild(k3->right);
	// Rotate between k3 and k2
	rotateWithRightChild(k3);
}
/* Internal method to remove item x from a subtree rooted at t */
void Avl::remove(int x, Node*& t)
{

	if (t == NULL)
		return; // item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);

	else if (t->left != NULL && t->right != NULL) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else // One child
	{
		Node* oldNode = t;
		t = (t->left != NULL) ? t->left : t = t->right;
		delete oldNode;
	}
	balance(t);

}
Node* Avl::findMin(Node*& t)
{

	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);

}
/* Internal method to find the largest item in a subtree t */
// non recursive version – method in public

int Avl::findMax(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void Avl::printTree(Node* ptr, int level) {
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
void Avl::print() {
	printTree(root, height(root));
}
void Avl::insert(int x) {
	insertNode(x, root);
}