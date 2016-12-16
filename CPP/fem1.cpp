#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/LU>
#include <cmath>

Eigen::MatrixXd FormStiffness(int);
Eigen::VectorXd FormRHS(int);
double Integrate(double, double);
double f(double);

int main() {

	int m = 20;

	Eigen::MatrixXd K(m, m);
	K = FormStiffness(m);
//	std::cout << K << std::endl;


	Eigen::VectorXd b(m);
	b = FormRHS(m);
//	std::cout << b << std::endl;

	Eigen::VectorXd x(m);
	x = K.lu().solve(b);
	std::cout << x << std::endl;		
	

	
}

Eigen::VectorXd FormRHS(int m) {
	
	double h = 1.0/(m + 1);
	double x[m + 2];

	Eigen::VectorXd b(m);
	
	for (int i = 0; i < m + 2; i++) {
		x[i] = i * h;
	}
	
	for (int j = 0; j < m; j++) {
		if (j == 0) {
			b(j) = Integrate(0, 1);		
		} else if (j == m + 1) {
			b(j) = Integrate(m, m + 1);
		} else {
			b(j) = Integrate(j - 1, j) + Integrate(j, j + 1);
		}
	}

	return b;
}

Eigen::MatrixXd FormStiffness(int m) {
	
	double h = 1.0/(m + 1);

	Eigen::MatrixXd K(m, m);
	K.setZero(m, m);

	for (int i = 0; i < m; i++)
		K(i, i) = 2.0;
	for (int i = 0; i < m - 1; i++) {
		K(i, i + 1) = -1.0;
		K(i + 1, i) = -1.0;
	}

	K *= 1.0/h;

	return K;
}

double Integrate(double a, double b) {

	double w1 = 1.0;
	double w2 = 1.0;

	double q1 = -1.0/sqrt(3.0);
	double q2 =  1.0/sqrt(3.0);

	double Q1 = q1*(a - b)/2.0 + (a + b)/2.0;
	double Q2 = q2*(a - b)/2.0 + (a + b)/2.0;

	return ((b - a)/2.0)*(w1*f(Q1)*(Q1 - a)/(b - a) + w2*f(Q2)*(Q2 - a)/(b - a));	
}

double f(double x) {

	return sin(x);

}


				





