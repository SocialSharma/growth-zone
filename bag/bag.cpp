/*
 * File: bag.cpp
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

// TODO: raise if anything but positive numbers supplied

#include "bag.h"
#include <iostream>

using namespace std;

Bag::Bag()
{
	f_value = -1;
	f_count = -1;
}

void Bag::debug_out()
{
	cout << "\n";
	cout << "***My bag contains: ";
	for (auto it = myset.begin(); it != myset.end(); ++it) {
		int value = it->first, count = it->second;
		cout << " " << "(" << value << "," << count << ")";
	}
}

void Bag::finder(int elem, bool add = false, bool remove = false)
{
	// check to see if an element is part of the set, and
	// update found value and count

	bool found = false;
	for (auto it = myset.begin(); it != myset.end(); ++it) {
		int value = it->first, count = it->second;
		if (value == elem) {
			f_value = value, f_count = count;
			found = true;
			if (add) {
				myset.erase(make_pair(elem, count));
				myset.insert(make_pair(elem, ++count));
			}
			if (remove) {
				myset.erase(make_pair(elem, count));
				myset.insert(make_pair(elem, --count));
				if (it->second == 0) {
					myset.erase(make_pair(elem, 0));
				}
			}
		}
	}

	if (!found) { // reset null values if elem not found
		f_value = -1, f_count = -1;
		if (add) {
			myset.insert(make_pair(elem, 1));
		}
	}
}

int Bag::find(int elem)
{
	finder(elem);
	return f_value;
}

vector<int> Bag::findAll(int elem)
{
	// check to see if an element is part of the set, and return element times
	// its value (aka number of duplicates) in a vector, or NULL

	finder(elem);
	vector<int> myvec;

	if (f_count > 0) {
		for (int i = 0; i < f_count; ++i) {
			myvec.push_back(elem);
		}
		return myvec;
	} else {
		return myvec;
	}

}

bool Bag::add(unsigned int elem)
{
	// check to see if an element is already a part of the set, add
	// (element, 1) it if it isn't, and increment its value if it is

	finder(elem, true, false);
	debug_out();
	return true;
}

int Bag::remove(int elem)
{
	// check to see if an element is part of the set, and return it,
	// or return NULL if not found

	finder(elem, false, true);
	debug_out();
	if (f_count == -1) {
		return f_count;
	} else {
		return elem;
	}
}
