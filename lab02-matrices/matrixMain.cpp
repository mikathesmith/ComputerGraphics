/* 
   MacOS / Linux shell command for compilation that worked for us:
   c++ Vector.cpp Matrix.cpp matrixMain.cpp -o matrixMain

   Then you can run the resulting executable:
   ./matrixMain
 */


#include "Matrix.h"
#include "Vector.h"

#include <iostream>

Vector make3Vector(int a, int b, int c){
	Vector v(3);
	v(0)=a;
	v(1)=b;
	v(2)=c;
	return v;
}

Matrix make2by2Matrix(int a, int b, int c, int d){
	Matrix M(2,2);
	M(0,0)=a;
	M(0,1)=b;
	M(1,0)=c;
	M(1,1)=d;
	return M;
}

Matrix make3by2Matrix(int a, int b, int c, int d, int e, int f){
	Matrix M(2,3);
	M(0,0)=a;
	M(0,1)=b;
	M(0,2)=c;
	M(1,0)=d;
	M(1,1)=e;
	M(1,2)=f; 
	return M;
}

int main () {

	
	Vector v = make3Vector(3,2,0);
	Vector u = make3Vector(1,-3,2); 
	
	/*Matrix A(3,3);
	A(0,0) = 1;
	A(0,1) = 0;
	A(0,2) = 0;
	A(1,0) = 0;
	A(1,1) = 0.5;
	A(1,2) = -1;
	A(2,0) = 2;
	A(2,1) = 2;
	A(2,2) = 0;

	std::cout << "The Matrix A is:" << std::endl;
	std::cout << A << std::endl; 
	
	Vector t(3);
	t = A*v;
	std::cout << "t = A*v is:" << std::endl;
	std::cout << t << std::endl;
	
	std::cout <<"Hello!" <<std::endl;
	*/

	std::cout << "The Vector v is:" << std::endl;
	std::cout << v << std::endl;
	

	std::cout << "The Vector u is:" << std::endl;
	std::cout << u << std::endl;
	
	
	Vector t(3);
	t = 2*u;
	std::cout << "4.1.1: t = 2*u is:" << std::endl;
	std::cout << t << std::endl;
	
	t = u+v;
	std::cout << "4.1.2: t = u + v is:" << std::endl;
	std::cout << t << std::endl;
	
	t = u-v;
	std::cout << "4.1.3: t = u - v is:" << std::endl;
	std::cout << t << std::endl;
	
	t = (2*u)-(3*v);
	std::cout << "4.1.4: t = 2u - 3v is:" << std::endl;
	std::cout << t << std::endl;
	
	
	Vector a = make3Vector(1,2,-2);
	Vector b = make3Vector(-2,2,1); 
	Vector c = make3Vector(2,3,1);
	
	int dot = a.dot(a);
	std::cout << "4.2.1: dot = (1,2,-2).(1,2,-2) is:" << std::endl;
	std::cout << dot << std::endl;
	
	dot = a.dot(b);
	std::cout << "4.2.2: dot = (1,2,-2).(-2,2,1) is:" << std::endl;
	std::cout << dot << std::endl;

	dot = a.dot(c);
	std::cout << "4.2.3: dot = (1,2,-2).(2,3,1) is:" << std::endl;
	std::cout << dot << std::endl;
	
	Vector cross = a.cross(b);
	std::cout << "4.2.2.1: cross = (1,2,-2)x(-2,2,1) is:" << std::endl;
	std::cout << cross << std::endl;
	
	Vector d = make3Vector(-2,-4,4);
	cross = a.cross(d);
	std::cout << "4.2.2.2: cross = (1,2,-2)x(-2,-4,4) is:" << std::endl;
	std::cout << cross << std::endl;
	
	dot = a.dot(a.cross(b));
	std::cout << "4.2.2.3: cross = (1,2,-2).((1,2,-2)x (-2,2,1)) is:" << std::endl;
	std::cout << dot << std::endl;
	
	
	Matrix A= make2by2Matrix(1,-2,3,4); 
	Matrix B= make2by2Matrix(3,2,4,1);
	Matrix C(2,2);
	C= (2*A)-B; 
	std::cout << "4.3.1: 2A - B:" << std::endl;
	std::cout << C << std::endl; 
	
	A= make2by2Matrix(2,1,2,2);
	B=make2by2Matrix(1,-2,-4,1);
	C= A*B;
	std::cout << "4.3.2: AB:" << std::endl;
	std::cout << C << std::endl; 
	
	C= B*A;
	std::cout << "4.3.3: BA:" << std::endl;
	std::cout << C << std::endl; 
	
	
	Matrix X(2,3);
	X = make3by2Matrix(1,1,0,0,1,2);
	
	Matrix Y(2,3);
	Y= X * a;
    std::cout << "4.4.1: Xa" << std::endl;
	std::cout << Y << std::endl; 
	
	Y= a * a.transpose();
	std::cout << "4.4.2: aatranspose" << std::endl;
	std::cout << Y << std::endl; 
	
	Y= a.transpose() * b;
	std::cout << "4.4.3: atranspose x b" << std::endl;
	std::cout << Y << std::endl;
	
	
	return 0;
}

