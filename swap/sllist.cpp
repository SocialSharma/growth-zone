/*
 * File: sllist.cpp
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#include "sllist.h"

SLList::SLList()
{
	head = NULL;
	n = 0;
}

SLList::~SLList()
{
	Node *del = head;
	while (del != NULL) {
		del = head;
		head = head->next;
		delete del;
	}
}

void SLList::add(unsigned int x)
{
	Node *n_node = new Node(x);
	n_node->next = head;
	head = n_node;
	n++;
}

int SLList::remove(int i)
{
	if ((i > n - 1) || (i < 0)) {
		throw "Illegal remove call! Index out of bounds.";
	}

	if (head == NULL) {return -1;}

	if (i == 0) {
		Node *temp = head;
		int data = temp->data;
		head = temp->next;
		delete temp;

		return data;
	}

	Node *tracker = head;
	for (int it = 0; it < i - 1; ++it) {
		tracker = tracker->next;
	}

	Node *temp = tracker->next;
	int data = temp->data;
	tracker->next = tracker->next->next;
	delete temp;
	n--;

	return data;
}

void SLList::swap(int i, char flag)
{
	if (n < 3) {
		throw "Illegal swap call! Less than two items in list.";
	}

	if (flag == 'p') {
		swap(i - 1);
	} else if (flag == 'n') {
		if ((i > n - 2) || (i < 0)) {
			throw "Illegal swap call! Index out of bounds.";
		}

		Node *tracker = head;

		if (i == 0) {
			head = head-> next;
			tracker->next = tracker->next->next;
			head->next = tracker;
		}

		for (int it = 0; it < i - 1; ++it) {
			tracker = tracker->next;
		}

		Node *temp = tracker->next;
		tracker->next = temp->next;
		temp->next = temp->next->next;
		tracker->next->next = temp;
	} else {
		throw "Invalid flag! Select either [n]ext or [p]revious.";
	}
}















