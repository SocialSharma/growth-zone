/*
 * File: bag.h
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

#ifndef BAG_H_
#define BAG_H_

#include <vector>
#include <unordered_set>
#include <utility>
#include <boost/functional/hash.hpp>
using namespace std;

class Bag
{
public:
	Bag();

	bool add(int elem);
	int remove(int elem);
	int find(int elem);
	vector<int> findAll(int elem);

private:
	int f_value, f_count;
	unordered_set<pair<int, int>, boost::hash<pair<int, int> > > myset;

	void finder(int elem, bool add, bool remove);
	void debug_out();
};

#endif /* BAG_H_ */
