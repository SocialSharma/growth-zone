/*
 * File: dqstack.h
 * -----------------------
 *
 * Created on: Jun 9, 2017
 *     Author: Abhi Sharma
 */

#ifndef DQSTACK_H_
#define DQSTACK_H_

#include <cstddef>

using namespace std;

class DQStack
{
public:
	DQStack();
	virtual ~DQStack();

	void push(int x);
	int pop();

protected:
	struct queue {
		queue(int len) {
			length = len;
			q = new int[len];
			n = 0;
			s = 0;
			off = NULL;
		};

		int length; // size of queue
		int *q; // pointer to queue
		int n; // number of elements in queue
		int s; // index of starting element
		queue *off; // pointer to inactive queue
	};

	void resize(queue q);
	queue *on; // pointer to active queue
};

#endif /* DQSTACK_H_ */
