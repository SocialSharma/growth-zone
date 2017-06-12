/*
 * File: minstack.cpp
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#include "minstack.h"

void MinStack::updateMin(char flag, int x)
{
	if (flag == 'a') {
		if (m.isEmpty() || (x == m.peek()) || (x == v)) {
				m.add(x);
		}
	} else if (flag == 'r') {
		if (s.peek() == m.peek()) {
			m.remove();
		}
	}
}

void MinStack::push(unsigned int x)
{
	if (s.isEmpty()) {v = x;}
	if (x <= v) {
		v = x;
		updateMin('a', x);
	};
	s.add(x);
}

int MinStack::pop()
{
	updateMin('r');
	return s.remove();
}

int MinStack::size()
{
	return s.len();
}

int MinStack::min()
{
	return m.peek();
}
