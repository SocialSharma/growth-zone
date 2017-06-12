/*
 * File: list.h
 * -----------------------
 *
 * Created on: Jun 11, 2017
 *     Author: Abhi Sharma
 */

#ifndef LIST_H_
#define LIST_H_

class List
{
public:
	List();
	virtual ~List();

	void add(int x);
	int remove();
	bool isEmpty();
	int peek();
	int len();

protected:
	struct Node {
		int data;
		Node *next;
	};

	Node *head;
	int n; // size of list
};

#endif /* LIST_H_ */
