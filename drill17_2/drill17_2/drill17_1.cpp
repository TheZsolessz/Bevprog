#include "std_lib_facilities.h"
#include <iostream>

using namespace std;

void print_array10(ostream& os, int* a) {
	for (int i = 0; i < 10; i++) {
		os << a[i] << '\n';
	}
}

void print_array(ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++) {
		os << a[i] << '\n';
	}
}

void print_vector(ostream& os, vector<int> vektor) {
	for (int i = 0; i < vektor.size(); i++) {
		os << vektor[i] << '\n';
	}
}

int main()
{
	cout << "Elso sor elemei: " << '\n';
	int* sor = new int[10];
	for (int i = 0; i < 10; i++)
		cout << sor[i] << '\n';
	delete[] sor;

	cout << "Masodik sor elemei: " << '\n';
	int* sor2 = new int[10];
	for (int i = 0; i < 10; i++)
		sor2[i] = i+100;
	print_array10(cout, sor2);
	delete[] sor2;

	cout << "Harmadik sor elemei: " << '\n';
	int* sor3 = new int[11];
	for (int i = 0; i < 11; i++)
		sor3[i] = i + 100;
	print_array(cout, sor3, 11);
	delete[] sor3;

	cout << "Negyedik sor elemei: " << '\n';
	int* sor4 = new int[20];
	for (int i = 0; i < 20; i++)
		sor4[i] = i + 100;
	print_array(cout, sor4, 20);

	cout << "Elso vektor elemei: " << '\n';
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(100 + i);
	print_vector(cout, vec1);

	cout << "Masodik vektor elemei: " << '\n';
	vector<int> vec2;
	for (int i = 0; i < 11; i++)
		vec2.push_back(100 + i);
	print_vector(cout, vec2);

	cout << "Harmadik vektor elemei: " << '\n';
	vector<int> vec3;
	for (int i = 0; i < 20; i++)
		vec3.push_back(100 + i);
	print_vector(cout, vec3);

 }
