/* This program perform T times statistics on percolation problem for a n-by-n grid
 * sample test: ./prog 20 100
 * n = 20
 * T = 100
 */

#include "percolation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);	// size of the grid (n-by-n)
	int T = atoi(argv[2]);	// number of experiments

	float mean = 0.0;
	float expNum[10000];
	float std = 0.0;

	srand (time(NULL));

	// doing experiment T times!
	for (int i = 0; i < T; i++) {
		int numOpenUnits = 0;
		percolation pr(n);
		while (pr.percolates() != true) {
			int randomOpenIndex = rand() % (n*n);
			int row = (randomOpenIndex / n);
			int col =  randomOpenIndex - (n * row);
			if (!pr.isOpen(row, col)) {
				pr.open(row, col);
				numOpenUnits = numOpenUnits + 1;
			}
		}
		expNum[i] = numOpenUnits/float(n*n);
		mean = mean + expNum[i];
	}
	mean = mean/float(T);

	for (int j = 0; j < T; j++) {
		std = std + (expNum[j] - mean) * (expNum[j] - mean);
	}
	std = sqrt(std/float(T-1));

	// output the result
	cout << "After " << T << " experiments:" << endl;
	cout << "mean\t\t\t = " << mean << endl;
	cout << "stddev\t\t\t = " << std << endl;
	cout << "95% confidence interval\t = " << "(" << mean - (1.96*std)/sqrt(float(T)) << ", " << mean + ((1.96*std)/sqrt(float(T))) << ")" << endl;
	return 0;
}


