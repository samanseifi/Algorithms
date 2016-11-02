#include <iostream>
using namespace std;


class WeightedQuickUnion 
{

public:
	WeightedQuickUnion(int);	// constructor
	~WeightedQuickUnion();		// destructor

	int root(int);
	bool find(int, int);
	void connect(int, int);

private:
	int* id;	// For constructing array it has to be initilized with reference
	int* sz;	// For constructing array it has to be initilized with reference

};

int main()
{
	WeightedQuickUnion uf(10);

	return 0;
}

WeightedQuickUnion::WeightedQuickUnion(int N) {
	id = new int[N]; 	// constructing array of length N
	sz = new int[N];	// constructing array of length N

	for (int i = 0; i < N; i++) 
		id[i] = i;
	for (int j = 0; j < N; j++)
		sz[j] = 1;
	cout << "Size of the array is = " << N << endl;
}

WeightedQuickUnion::~WeightedQuickUnion() {
	delete id;
	delete sz;
}

int WeightedQuickUnion::root(int i) {
	while (i != id[i])
		i = id[i];
	return i;
}

bool WeightedQuickUnion::find(int p, int q) {
	if (root(p) == root(q))
		return true;
	else
		return false;
}

void WeightedQuickUnion::connect(int p, int q) {
	int i = root(p);
	int j = root(q);
	if (i == j) return;

	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i]; 
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
}
