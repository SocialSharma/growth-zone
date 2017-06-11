/*
 * File: dllist.cpp
 * -----------------------
 *
 * Created on: Jun 10, 2017
 *     Author: Abhi Sharma
 */

#include "dllist.h"

DLList::DLList()
{
	dummy.data = 0;
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

DLList::~DLList()
{
	Node *temp = dummy.next;
	while (n > 0) {
		temp = dummy.next;
		dummy.next = dummy.next->next;
		delete temp;
		n--;
	}
}

DLList::Node* DLList::getNode(int i)
{
	Node *target = &dummy;
	if (i <= n / 2) {
		while (i >= 0) {
			target = target->next;
			i--;
		}
	} else {
		int ri = n - i - 1;
		while (ri >= 0) {
			target = target->prev;
			ri--;
		}
	}

	return target;
}

void DLList::push(unsigned int x)
{
	Node *n_node = new Node;
	n_node->data = x;

	n_node->next = dummy.next;
	dummy.next = n_node;
	n_node->prev = &dummy;
	n_node->next->prev = n_node;
	n++;
}

int DLList::pop()
{
	if (n == 0) {return -1;}

	Node *temp = dummy.next;
	int data = temp->data;

	dummy.next = temp->next;
	temp->next->prev = &dummy;
	delete temp;
	n--;

	return data;
}

void DLList::swap(int i, char flag)
{
	if (n < 2){
		throw "Invalid swap call! Less than two items in list.";
	}

	if (flag == 'p') {
		swap(i - 1);
	} else if (flag == 'n') {
		if ((i > n - 2) || (i < 0)){
			throw "Invalid swap call! Index out of bounds.";
		}
		Node *A, *B, *C, *D;
		B = getNode(i);
		A = B->prev;
		C = B->next;
		D = B->next->next;

		A->next = B->next;
		B->next = C->next;
		D->prev = C->prev;
		C->prev = B->prev;
		B->prev = A->next;
		C->next = D->prev;
	} else {
		throw "Invalid swap call! Select either [n]ext or [p]revious.";
	}
}






