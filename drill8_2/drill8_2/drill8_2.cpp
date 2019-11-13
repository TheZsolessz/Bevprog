#include <iostream>
#include "std_lib_facilities.h"

void swap_v(int a, int b) { //A felcserélt számok csak a függvényben élnek.
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//void swap_cr(const int& a, const int& b) { Nem mûködik, mert a konstans nem változtatható
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}

int main()
{
	int x = 7;
	int y = 9;
	swap_r(x, y);
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	//const int cx = 7; //Konstans nem változtatható
	//const int cy = 9;
	//swap_v(cx, cy);
	//swap_v(7, 9);
	//double dx = 7.7; //Double változóval nem mûködik egyik függvény sem.
	//double dy = 9.9;
	//swap_v(dx, dy);
	//swap_v(dx, dy);

}
