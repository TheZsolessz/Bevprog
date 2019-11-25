#include <iostream>
#include "std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int array[], int n) {
	int la[10];

	for (int i = 0; i < n; i++) {
		la[i] = array[i];
		cout << la[i] <<" ";
	}
	cout << endl;

	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = array[i];
		cout << p[i] << " ";
	}
	cout << endl;

	delete[] p;
}

int factorial(int n) {
	int eredmeny = 1;
	for (int i = 1; i <= n; i++)
		eredmeny *= i;
	return eredmeny;
}

int main()
{
	int aa[10];
	for (int i = 0; i < 10; i++) 
		aa[i] = factorial(i + 1);

	f(aa, 10);
}

