#include <iostream>
#include <armadillo>
#include <cmath>

#include "Mesh.h"

using namespace std;
using namespace std;

vec shape(vec);
vec gradshape(vec);

int main() {

	// Create a uniform mesh
	Mesh mesh(4, 2 ,4 ,2);


	// Plane-strain material tangent
	const float E = 100.0;
	const float nu = 0.29;

	mat D(3, 3, fill::zeros);
	D(0, 0) = D(1, 1) = 1.0 - nu; 
	D(0, 1) = D(1, 0) = nu;
	D(2, 2) = 0.5 - nu;
	D *= E/(1.0 + nu)/(1.0 - 2.0*nu);

	// Constructing the stiffness matrix
	mat K(2*mesh.num_nodes(), 2*mesh.num_nodes(), fill::zeros);
	mat q4(4, 2);
	q4(0, 0) = q4(0, 1) = q4(1, 1) = q4(2, 0) = -1.0;
	q4(1, 0) = q4(2, 1) = q4(3, 0) = q4(3, 1) =  1.0;
	q4 *= 1.0/sqrt(3.0);

	cout << "Assembling stifness matrix..." << endl;

	// initilizing the B matrix
	mat B(3, 8, fill::zeros); 

	// loop over elements
	for (int i = 0; i < mesh.num_elements(); i++) {
		mat xIe(4, 2, fill::zeros);
		mat curr_elem = mesh.conns_set.row(i);
		int j = 0;

		// loop over current element nodes number (Implementation: C++11)
		for (const auto& val : curr_elem) {
			xIe.row(j) = mesh.nodes_set.row(val);
			j++;
		}

		// initializing the stiffness matrix of current element
		mat Ke(8, 8, fill::zeros);
		for (int i = 0; i < q4.n_rows; i++) {
			vec q = trans(q4.row(i));  // has to be transposed!!
			vec dN = gradshape(q);

		}
	}
	
	return 0;
}


/*
** Shape function for a 4-node, isoparametric element!
*/
vec shape(vec xi) {
	float x = xi(0);
	float y = xi(1);

	// C++11
	vec N = {{(1.0 - x)*(1.0 - y), (1.0+x)*(1.0-y), (1.0+x)*(1.0+y), (1.0-x)*(1.0+y)}};
	N *= 0.25;

	return N;
}	

/*
**	Gradient of the shape function for a 4-node, isoparametric element!
*/
vec gradshape(vec xi) {
	float x = xi(0);
	float y = xi(1);

	// C++11
	vec dN = {	{-(1.0 - y),  (1.0 - y), (1.0 + y), -(1.0 + y),
				 -(1.0 - x), -(1.0 + x), (1.0 + x),  (1.0 - x)}	}; 
	dN *= 0.25;

	return dN;
}