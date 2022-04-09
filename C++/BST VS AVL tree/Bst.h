#pragma once
#include <iostream>

using namespace std;
class BinaryNode
{
public:
	int  element;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(int  theElement, BinaryNode* lt, BinaryNode* rt) { element = theElement; left = lt; right = rt; }
};

class BinarySearchTree
{
public:
	int Left_H;
	int Right_H;
	BinarySearchTree();
	~BinarySearchTree();
	int findMin();
	int findMax();
	int find(int  x);
	void  printTree();

	int  isEmpty();
	void  makeEmpty();

	void  insert(int  x);
	void  remove(int  x);

private:
	BinaryNode* root;
	int max(int,int);
	int elementAt(BinaryNode* t);
	int tree_height(BinaryNode* root);
	BinaryNode* findMin(BinaryNode* t);
	BinaryNode* findMax(BinaryNode* t);
	BinaryNode* find(int x, BinaryNode* t);
	void  printTree(BinaryNode* t, int);
	void  insert(int x, BinaryNode*& t);
	void  remove(int  x, BinaryNode*& t);

	void  makeEmpty(BinaryNode*& t);
};

