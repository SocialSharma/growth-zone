/*
 * File: sllist.h
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#ifndef SLLIST_H_
#define SLLIST_H_

#include <cstddef>

using namespace std;

class SLList
{
public:
	SLList();
	virtual ~SLList();

	void add(unsigned int x);
	int remove(int i = 0);
	void swap(int i, char flag = 'n'); // swap with [p]revious or [n]ext

protected:
	class Node
	{
	public:
		Node(int x = 0) {
			data = x;
			next = NULL;
		};

		int data;
		Node *next;
	};

	Node *head;
	int n; // size of list
};

#endif /* SLLIST_H_ */
