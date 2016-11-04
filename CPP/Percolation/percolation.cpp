#include "percolation.h"
#include <iostream>

using namespace std;

percolation::percolation() { }

/**
 * creating n-by-n grid all full (false)
 **/
percolation::percolation(int n) {
	/** 
	 * this implementation works on C++11 where initilization of a 2-dimensional array
	 * is not easy in older version. compile with: -std=c++11 
	 **/
	grid = new bool*[n];
	for (int i = 0; i < n; ++i)
		grid[i] = new bool[n];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = false;
	
	qf = new WeightedQuickUnion(n * n + 2);
	
	size = n;

	top = 0;
	bottom = n * n + 1;
}

// destructor
percolation::~percolation() {
	delete grid;
	delete qf;
}

/**
 * open the unit (row, col)
 **/
void percolation::open(int row, int col) {
	grid[row][col] = true;
	if (row == 0) 
		qf->connect(getIndex(row, col), top);
	
	if (row == size - 1) 
		qf->connect(getIndex(row, col), bottom);
	
	if (row > 0 && isOpen(row - 1, col)) 
		qf->connect(getIndex(row, col), getIndex(row - 1, col));
	
	if (col > 0 && isOpen(row, col - 1))
		qf->connect(getIndex(row, col), getIndex(row, col - 1));		
	
	if (row < size - 1 && isOpen(row + 1, col))
		qf->connect(getIndex(row, col), getIndex(row + 1, col));

	if (col < size - 1 && isOpen(row, col + 1))
		qf->connect(getIndex(row, col), getIndex(row, col + 1));
}

bool percolation::isOpen(int row, int col) {
	return grid[row][col];
}

bool percolation::isFull(int row, int col) {
	if ( row >= 0 && size >= row && col >= 0 && size >= col) {
		return qf->find(top, getIndex(row, col));
	} else {
		cout << "Index out of bounds" << endl;
		return 0;
	}
}

/**
 * check if the grid percolates!
 **/
bool percolation::percolates() {
	return qf->find(top, bottom);
}

/**
 * Translating (row, col) to index number
 **/
int percolation::getIndex(int row, int col) {
	return size*row + col;
}
