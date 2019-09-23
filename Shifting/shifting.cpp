#include "std_lib_facilities.h"

int main()
{
	int i = 30;
	int hossz = 0;

	while (i != 0) {
		i = i << 1;
		hossz++;
	}

	cout << hossz;
	return 0;
}