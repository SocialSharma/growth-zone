/*
 * File: list.cpp
 * -----------------------
 *
 * Created on: Jun 11, 2017
 *     Author: Abhi Sharma
 */

#include "list.h"
#include <cstddef>

List::List()
{
	head = NULL;
	n = 0;
}

List::~List()
{
	Node *temp = head;
	while (n > 0) {
		head = head->next;
		delete temp;
		temp = head;
		n--;
	}
}

void List::add(int x)
{
	Node *n_node = new Node;
	n_node->data = x;
	n_node->next = head;
	head = n_node;
	n++;
}

int List::remove()
{
	if (isEmpty()) {return -1;}

	Node *temp = head;
	int data = temp->data;
	head = temp-> next;
	delete temp;
	n--;

	return data;
}

bool List::isEmpty()
{
	return n == 0;
}

int List::peek()
{
	if (isEmpty()) {return -1;}
	return head->data;
}

int List::len()
{
	return n;
}

