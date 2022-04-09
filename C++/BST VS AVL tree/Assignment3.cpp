// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "AVL.h"
#include "Bst.h"
int main()
{
	const int num = 3680;
	srand((unsigned)time(0));
	int arr[num];
	Avl t;
	BinarySearchTree bst;
	for (int i = 0; i < num; i++) {
		arr[i] = std::rand();
		
	}
/*	t.insert(arr[0]);
	t.print();*/
	clock_t tStart = clock();
	for (int i = 0; i < num; i++) {
		bst.insert(i);
		//t.insert(i);
	}
	cout << "this is avl perfomance test number of array is  " << num << endl;
	cout << "This the roughly limit of the avl in this program " << endl;
	cout << "Time Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;

	/*cout << "Bst " << endl;
	bst.printTree();*/
	

}

