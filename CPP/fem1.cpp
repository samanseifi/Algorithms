#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/LU>
#include <cmath>

Eigen::MatrixXd FormStiffness(int);
Eigen::VectorXd FormRHS(int);
double Integrate_hat1(double, double, double);
double Integrate_hat2(double, double, double);
double f(double);



int main(int argc, char* argv[]) {
	
	argc = 1;
	int m = atoi(argv[1]);	// Number of nodes
	
	Eigen::MatrixXd K(m, m);
	K = FormStiffness(m);
	
	Eigen::VectorXd b(m);
	b = FormRHS(m);

	Eigen::VectorXd x(m);
	x = K.lu().solve(b);
	std::cout << x << std::endl;		
	
	return 0;
	
}

Eigen::VectorXd FormRHS(int m) {
	
	double h = 1.0/(m - 1);
	double  x[m];

	Eigen::VectorXd b(m);	

	for (int i = 0; i < m; i++) {
		x[i] = i * h;
	}
	
	b(0) 	 = 0.0; // Account for BC start
	b(m - 1) = 0.0; // Account for BC end

	for (int j = 1; j < m - 1; j++) {
		b(j) = Integrate_hat1(x[j - 1], x[j], h) + Integrate_hat2(x[j], x[j + 1], h);
	}
	
	std::cout << b << std::endl;	

	return b;
}

Eigen::MatrixXd FormStiffness(int m) {
	
	double h = 1.0/(m - 1);

	Eigen::MatrixXd K(m, m );
	K.setZero(m, m);

	for (int i = 1; i < m - 1; i++)
		K(i, i) = 2.0;
	for (int i = 1; i < m - 2; i++) {
		K(i, i + 1) = -1.0;
		K(i + 1, i) = -1.0;
	}
	
	K(0, 0) 	= 1.0; // Account for BC start
	K(m - 1, m - 1) = 1.0; // Account for BC end
	
	std::cout << K << std::endl;
	K *= 1.0/h;

	return K;
}

double Integrate_hat1(double a, double b, double h) {
	
	double c = (a + b)/2.0;                                                                                                    

	return ((b - a)/6.0)*(f(a)*((a - a)/h) + 4*f(c)*((c - a)/h) + f(b)*((b - a)/h));	
}

double Integrate_hat2(double a, double b, double h) {
	
	double c = (a + b)/2.0;

	return ((b - a)/6.0)*(f(a)*((b - a)/h) + 4*f(c)*((b - c)/h) + f(b)*((b - b)/h));
}

double f(double x) {

	return 1;

}



				



