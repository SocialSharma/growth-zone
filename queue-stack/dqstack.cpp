/*
 * File: dqstack.cpp
 * -----------------------
 *
 * Created on: Jun 9, 2017
 *     Author: Abhi Sharma
 */

#include "dqstack.h"

DQStack::DQStack() {
	queue alpha(1), beta(1);
	*on = alpha;
	*(alpha.off) = beta;
}

DQStack::~DQStack() {} // TODO: Implement destructor

void DQStack::resize(queue q) {} // TODO: Implement resize

void DQStack::push(int x) {
	// if the number of elements is equal to the size of alpha,
	// resize alpha and beta, then push number into whichever queue has items

	queue &active = *on;
	int &s = active.s;
	int &n = active.n;
	int len = active.length;

	if (n == len) {
		resize(active);
		resize(*active.off);
	}

	int index = (s + n) % len;
	active[index] = x;
	n++;
}

int DQStack::pop() { // TODO: Implement pop
	// take whichever queue has items, and copy items into the second queue from
	// the end until there is just one item left in the first queue
	queue &active = *on;
	int &s = active.s;
	int &n = active.n;

	queue &inactive = *(on->off);
	int &in_n = inactive.n;
	int in_len = inactive.length;
	int index = in_n % in_len;

	while (n > 1) {
		inactive[index] = active[s];
		in_n++;
		n--;
		s++;
	}

	int out = active[s];
	s = 0;
	n = 0;

	queue *temp = on;
	on = active.off;
	on->off = temp;

	return out;
}
