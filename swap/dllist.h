/*
 * File: dllist.h
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#ifndef DLLIST_H_
#define DLLIST_H_

#include <cstddef>

using namespace std;

class DLList
{
public:
	DLList();
	virtual ~DLList();

	void push(unsigned int x);
	int pop();
	void swap(int i, char flag = 'n'); // swap with [n]ext or [p]revious

private:
	struct Node {
		int data;
		Node *next, *prev;
	};

	Node* getNode(int i);

	int n; // size of list
	Node dummy;
};



#endif /* DLLIST_H_ */
