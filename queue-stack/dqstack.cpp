/*
 * File: dqstack.cpp
 * -----------------------
 *
 * Created on: Jun 9, 2017
 *     Author: Abhi Sharma
 */

#include "dqstack.h"

DQStack::DQStack()
{
	queue alpha(1), beta(1);
	on = &alpha;
	alpha.off = &beta;
}

DQStack::~DQStack()
{
	delete[] on->q;
	delete[] on->off->q;
}

void DQStack::resize(queue nofit)
{
	// if the queue has the same n as len, copy the array into a size double
	// that and delete the original
	// if the queue has len more than three times its n, copy the array into
	// another that is half the size

	int &len = nofit.length;
	int n = nofit.n;
	int *q = nofit.q;

	if (len == n) {
		int *new_q = new int[2 * len];
		for (int i = 0; i < n; ++i) {
			new_q[i] = q[i];
		}
		len *= 2;
		delete[] q;
		q = new_q;
	}

	if (len > (3 * n)) {
		int *new_q = new int[len / 2];
		for (int i = 0; i < n; ++i) {
			new_q[i] = q[i];
		}
		len /= 2;
		delete[] q;
		q = new_q;
	}
}

void DQStack::push(int x)
{
	// if the number of elements is equal to the size of alpha,
	// resize alpha and beta, then push number into whichever queue has items

	queue &active = *on;
	int &s = active.s;
	int &n = active.n;
	int len = active.length;
	int *q = active.q;

	int i = (s + n) % len;
	q[i] = x;
	n++;

	if (len == n) {
		resize(active);
		resize(*active.off);
	}
}

int DQStack::pop()
{
	// take whichever queue has items, and copy items into the second queue from
	// the end until there is just one item left in the first queue

	queue &active = *on;
	int &s = active.s;
	int &n = active.n;
	int *q = active.q;

	queue &inactive = *(on->off);
	int &in_n = inactive.n;
	int in_len = inactive.length;
	int *in_q = inactive.q;
	int i = in_n % in_len;

	while (n > 1) {
		in_q[i] = q[s];
		in_n++;
		n--;
		s++;
	}

	int out = q[s];
	s = 0;
	n = 0;

	queue *temp = on;
	on = active.off;
	on->off = temp;

	if (in_len > (3 * in_n)) {
		resize(active);
		resize(*active.off);
	}

	return out;
}
