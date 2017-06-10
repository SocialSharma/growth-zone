/*
 * File: bag_test.cpp
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

#include "bag.h"
#include <iostream>
#include <string>

void ClearScreen()
{
	cout << string(100, '\n');
}


using namespace std;

int main()
{
	Bag mybag;

	cout << "Bag Manipulation Tests\n";
	cout << "----------------------\n";
	cout << "\nAdding 2: ";
	mybag.add(2);
	cout << "\n";
	cout << "\nAdding 5: ";
	mybag.add(5);
	cout << "\n";
	cout << "\nAdding 2: ";
	mybag.add(2);
	cout << "\n";
	cout << "\nAdding 2: ";
	mybag.add(2);
	cout << "\n";
	cout << "\nAdding 5: ";
	mybag.add(5);
	cout << "\n";

	int outcome;

	cout << "\nRemoving 5: ";
	outcome = mybag.remove(5);
	cout << "\nOutcome: " << outcome;
	cout << "\n";
	cout << "\nRemoving 9: ";
	outcome = mybag.remove(9);
	cout << "\nOutcome: " << outcome;
	cout << "\n";

	cout << "\nFinding 2: ";
	outcome = mybag.find(2);
	cout << "\nOutcome: " << outcome;
	cout << "\n";
	cout << "\nFinding 5: ";
	outcome = mybag.find(5);
	cout << "\nOutcome: " << outcome;
	cout << "\n";

	vector<int> myvec;

	cout << "\nFinding all 2s: ";
	myvec = mybag.findAll(2);
	cout << "\n";
	for (auto it = myvec.begin(); it != myvec.end(); ++it) {
		cout << " " << *it;
	}

	return 0;
}


