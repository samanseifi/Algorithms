#ifndef WEIGHTEDQUICKUNION_H_
#define WEIGHTEDQUICKUNION_H_

class WeightedQuickUnion 
{

public:
	WeightedQuickUnion();
	WeightedQuickUnion(int);			// constructor
	virtual ~WeightedQuickUnion();		// destructor

	int root(int);
	bool find(int, int);
	void connect(int, int);
	void testing();

private:
	int* id;	// For constructing array it has to be initilized with reference
	int* sz;	// For constructing array it has to be initilized with reference

};

#endif