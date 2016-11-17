#ifndef MESH_H_
#define MESH_H_

#include <armadillo>

using namespace arma;

class Mesh {

public:
	Mesh(int, int, float, float);
	virtual ~Mesh();
	int num_nodes();
	int num_elements();

	mat nodes_set;
	mat conns_set;
private:

	int nx;
	int ny;

};

#endif