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
	head = NULL;
}

PQueue::~PQueue() {
	Node *t_node = head;
	while (t_node != NULL) {
		head = head->next;
		delete t_node;
		t_node = head;
	}
}

void PQueue::add(int x) {
	Node *n_node = new Node(x);
	if (n == 0) {head = n_node;}

	Node *t_node = head;
	while (n_node->data > t_node->next->data) {
		if (t_node->next == NULL) {break;}
		t_node = t_node->next;
	}

	n_node->next = t_node->next;
	t_node->next = n_node;
	n++;
}

int PQueue::deleteMin() {
	if (n == 0) {return NULL;}

	Node *t_node = head;
	int t_data = head->data;
	head = head->next;
	delete t_node;
	n--;

	return t_data;
}

int PQueue::size() {
	return n;
}
