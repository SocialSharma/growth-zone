/*
 * File: bag.cpp
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

/*
 * TWO BIG ISSUES RIGHT NOW:
 * 1. How to return NULL values? boost::optional DONE
 * 2. How to put pair in unordered set? Hash function DONE
 *
 * ONE SMALL ISSUE
 * 1. Generic typing/template everything
 */

#include "bag.h"
#include <unordered_set>
#include <vector>
#include <boost/functional/hash.hpp>
#include <boost/optional.hpp>
#include <utility>
using namespace std;

Bag::Bag() {}

pair<boost::optional<int>, boost::optional<int> > Bag::pairFind(int elem)
{
	// check to see if an element is part of the set, and
	// return element or NULL

	pair<int, int> input = make_pair(elem, 0);
	pair<boost::optional<int>, boost::optional<int> > not_found =
			make_pair(null, null);

	unordered_set<pair<int, int>,
		boost::hash<pair<int, int> > >::iterator got = myset.find(input);

	if (got == myset.end()) {
		return not_found;
	} else {
		return *got;
	}
}

boost::optional<int> Bag::find(int elem)
{
	return pairFind(elem).first;
}

vector<int> Bag::findAll(int elem)
{
	// check to see if an element is part of the set, and return element times
	// it's value (aka number of duplicates) in a vector, or NULL

	int count = pairFind(elem).second;
	vector<int> myvec;

	if (count > 0) {
		for (int i = 0; i < count; i++) {
			myvec.push_back(elem);
		}
		return myvec;
	} else {
		return myvec;
	}

}

bool Bag::add(int elem)
{
	// check to see if an element is already a part of the set, add
	// (element, 1) it if it isn't, and increment its value if it is

	int count = pairFind(elem).second;

	if (count > 0) {
		pairFind(elem).second++;
		return true;
	} else {
		myset.insert(make_pair(elem, 1));
		return true;
	}

	return false;
}

boost::optional<int> Bag::remove(int elem)
{
	// check to see if an element is part of the set, and return it,
	// or return NULL if not found

	boost::optional<int> count = pairFind(elem).second;
	boost::optional<int> value = pairFind(elem).first;

	if (count > 1) {
		(pairFind(elem).second)--;
		return value;
	} else if (count == 1) {
		myset.erase(make_pair(value, null));
		return value;
	} else {
		return null;
	}
}
