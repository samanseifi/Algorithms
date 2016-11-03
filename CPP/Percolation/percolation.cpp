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
	 * is not easy in older vrsion. compile with: g++-4 -std=c++11 ... 
	 **/
	grid = new bool*[n];
	for (int i = 0; i < n; ++i)
		grid[i] = new bool[n];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = false;

	qf = new WeightedQuickUnion(n*n + 2);
}

percolation::~percolation() {
	delete grid;
	delete qf;
}


void percolation::open(int row, int col) {

}

bool percolation::isOpen(int row, int col) {

}

bool percolation::isFull(int row, int col) {

}

bool percolation::percolates() {

}
