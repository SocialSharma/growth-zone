/*
 * File: bag_test.cpp
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

#include "bag.h"
#include <iostream>
#include <boost/optional/optional_io.hpp>

using namespace std;

int main() {
	Bag mybag;

	cout << "***Test 1: Adding to the bag***\n";
	cout << "-------------------------------\n";
	bool test_1a = mybag.add(2);
	bool test_1b = mybag.add(5);
	bool test_1c = mybag.add(2);
	cout << "Added 2? " << test_1a << "\n";
	cout << "Added 5? " << test_1b << "\n";
	cout << "Added 2? " << test_1c << "\n";

	cout << "\n";

	cout << "***Test 2: Searching the bag***\n";
	cout << "-------------------- ----------\n";
	boost::optional<int> test_2a = mybag.find(2);
	boost::optional<int> test_2b = mybag.find(5);
	boost::optional<int> test_2c = mybag.find(9);
	cout << "Found 2? " << test_2a << "\n";
	cout << "Found 5? " << test_2b << "\n";
	cout << "Found 9? " << test_2c << "\n";


	return 0;
}


