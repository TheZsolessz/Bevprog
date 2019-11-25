#include <iostream>
#include "std_lib_facilities.h"

vector<int> gv{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int> v) {
	vector<int> lv(10);
	lv = v;
	for (int i = 0; i < v.size(); i++)
		cout << lv[i]<<" ";
	cout << endl;
	vector<int> lv2 = v;
	for (int i = 0; i < v.size(); i++)
		cout << lv2[i] << " ";
	cout << endl;
}

int factorial(int n) {
	int eredmeny = 1;
	for (int i = 1; i <= n; i++)
		eredmeny *= i;
	return eredmeny;
}

int main() {
	f(gv);
	vector<int> vv(10);
	for (int i = 0; i < vv.size(); i++)
		vv[i] = factorial(i + 1);
	f(vv);
}