/*
 * File: minstack.h
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_

#include "list.h"

class MinStack: protected List
{
public:
	void push(unsigned int x);
	int pop();
	int size();
	int min();

protected:
	// [a]dd or [r]emove from min list

	void updateMin(char flag, int x = -1);

	List s; // list to hold elements in stack
	List m; // list to track min values
	int v; // current min value
};



#endif /* MINSTACK_H_ */
