#include "percolation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int n = 8;
	percolation pr(n);
	//while (pr.percolates != true) {


	//}
	srand (time(NULL));
	for (int i = 0; i < 10; i++) {
		int randomOpenIndex = rand() % (n*n);
		int row = (randomOpenIndex / n);
		int col =  randomOpenIndex - (n * row);
		pr.open(row, col);
	}

	//for (int i = 0; i < 100; i++)
	//	cout << rand() % 100 + 1 << endl;
	//WeightedQuickUnion qf(20);
	//qf.testing();
	return 0;
}


