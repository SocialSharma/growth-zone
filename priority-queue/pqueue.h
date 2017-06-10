/*
 * File: pqueue.h
 * -----------------------
 *
 * Created on: Jun 9, 2017
 *     Author: Abhi Sharma
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <cstddef>

using namespace std;

class PQueue
{
public:
	PQueue();
	virtual ~PQueue();

	void add(int x);
	int deleteMin();
	int size();

protected:
	class Node
	{
	public:
		Node(int x) {
			data = x;
			next = NULL;
		};

		int data;
		Node *next;
	};

	int n; // size of PQueue
	Node *head;
};

#endif /* PQUEUE_H_ */
