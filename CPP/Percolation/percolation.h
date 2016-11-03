#ifndef PERCOLATION_H_
#define PERCOLATION_H_

#include "WeightedQuickUnion.h"

class percolation {

public:
	percolation();
	percolation(int);
	virtual ~percolation();

	void open(int, int);
	bool isOpen(int, int);
	bool isFull(int, int);
	bool percolates();


private:

	// translate the coordinates (row, col) to index
	int getIndex(int, int);		

	bool** grid;	// 2-dimensional array is initilized for C++11
	int top;
	int bottom;
	int size;

	WeightedQuickUnion* qf;
			
};

#endif