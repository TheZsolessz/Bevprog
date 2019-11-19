#include "std_lib_facilities.h"
#include <iostream>

using namespace std;

void print_array(ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++) {
		os << a[i] << '\n';
	}
}
int main()
{
	int p = 7;
	int* p1 = &p;

	cout << p1 << '\n';
	cout << *p1 << '\n';

	int* sor = new int[7];
	for (int i = 0; i < 7; i++)
		sor[i] = pow(2, i); //2 i-edik hatványa.
	print_array(cout, sor, 7);

	int* p2 = sor;
	
	cout <<"p2 erteke:"<< p2<<'\n';
	cout << "p2 sor: \n";
	print_array(cout, p2, 7);

	int* p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << "p1: " << p1<<'\n';
	cout << "p1 sor: \n";
	print_array(cout, p1, 7);

	cout << "p2: " << p2<<'\n';
	cout << "p2 sor: \n";
	print_array(cout, p2, 7);

	////9.				Ennél a résznél valamiért exceptiont dob a program.
	//delete[] p1;
	//delete [] sor;
	//delete [] p2;
	//delete [] p3;

	int* ten = new int[10];
	for (int i = 0; i < 10; i++)
		ten[i] = pow(2, i); 
	print_array(cout, ten, 10);

	p1 = ten;

	int* ten2 = new int[10];
	for (int i = 0; i < 10; i++)
		ten2[i] = pow(2, i);
	print_array(cout, ten2, 10);

	p2 = ten2;

	vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(pow(2,i));

	//p1 = vec1;

	vector<int> vec2;
	for (int i = 0; i < 10; i++)
		vec2.push_back(pow(2, i));

	//p2 = vec2;

}

