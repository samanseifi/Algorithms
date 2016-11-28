#include <iostream>
#include <armadillo>

int main() {
	arma::Mat<double> D(4, 4, arma::fill::ones);
	
	arma::Mat<double> B(4, 4, arma::fill::randu);
	
	arma::Mat<double> E;
	E = B * D;
	
	std::cout << E << std::endl;

	return 0;
}

