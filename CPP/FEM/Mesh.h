#ifndef MESH_H_
#define MESH_H_

#include <armadillo>

using namespace arma;

class Mesh {

public:
  Mesh(int, int, double, double);
  virtual ~Mesh();
  int num_nodes();
  int num_elements();

  mat nodes_set;
  mat conns_set;

  double l_x, l_y;
  double h_x, h_y;

private:
  int nx;
  int ny;
};

#endif
