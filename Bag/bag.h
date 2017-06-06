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
#include <utility>
#include <boost/optional.hpp>
using namespace std;

class Bag
{
public:
	Bag();

	bool add(int elem);
	boost::optional<int> remove(int elem);
	boost::optional<int> find(int elem);
	vector<int> findAll(int elem);

private:
	boost::optional<int> null;
	pair<boost::optional<int>, boost::optional<int> > pairFind(int elem);
	unordered_set<pair<int, int>, boost::hash<pair<int, int> > > myset;
};

#endif /* BAG_H_ */
