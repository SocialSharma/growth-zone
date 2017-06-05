/*
 * File: bag.h
 * -----------------------
 *
 * Created on: Jun 5, 2017
 *     Author: Abhi Sharma
 */

#ifndef BAG_H_
#define BAG_H_

#include <string>

class Bag
{
public:
	Bag();
	~Bag();

	void add();
	void remove();
	void find();
	string findAll();
};

#endif /* BAG_H_ */
