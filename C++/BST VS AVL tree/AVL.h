#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
	Node* left;
	Node* right;
	int heightNum;
	int element;
	Node(int theElement, Node* lt, Node* rt, int h = 0);
};
class Avl
{
public:

	Avl();
	void insert(int);
	Node* findMin(Node*& t);
	int findMax(int,int);
	void print();
private:
	int height(Node* t);
	void insertNode(int x, Node*& t);
	void printTree(Node*, int);
	void balance(Node*& t);
	void rotateWithLeftChild(Node*& k2);
	void doubleWithLeftChild(Node*& k3);
	void remove(int x, Node*& t);
	void rotateWithRightChild(Node*& k2);
	void doubleWithRightChild(Node*& k3);
	Node* root;
};