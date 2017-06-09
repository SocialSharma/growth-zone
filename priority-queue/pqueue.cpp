/*
 * File: pqueue.cpp
 * -----------------------
 *
 * Created on: Jun 9, 2017
 *     Author: Abhi Sharma
 */

#include "pqueue.h"

PQueue::PQueue() {
	n = 0;
	head = tail = NULL;
}

PQueue::~PQueue() {} // TODO: Implement destructor

bool PQueue::add(int x) {
	// use temporary pointer to traverse the list
	// while the next node's data is smaller than current element, keep going
	// have current element point to next node
	// have current node point to element
	// if you reach the end:
	//     have current element point to NULL
	//     have current node point to element
	// increment size
	return true;
}

int PQueue::deleteMin() {
	// use temporary pointer to keep track of first element
	// use temporary int to track first element.data
	// have head point to element.next
	// delete temp pointer
	// decrement size
	// return temp data
	return 0;
}

int PQueue::size() {
	// return size of pqueue
	return n;
}
