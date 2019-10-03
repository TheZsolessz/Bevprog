#include <iostream>
#include "std_lib_facilities.h"

int main()
{
	/*double a, b;
	double x = 1.0 / 100;
	while (cin >> a >> b) {
		if (a < b) {
			cout << "The smaller value is: " << a << "\n";
			cout << "The larger value is: " << b << "\n";
		}
		else if (a > b) {
			cout << "The smaller value is: " << b << "\n";
			cout << "The larger value is: " << a << "\n";
		}
		else
			cout << "The numbers are equal \n";
		if ((a - b) < x )
			cout << "The numbers are almost equal \n";
	}



	double nagy = 0;
	double kicsi = 0;
	double a;
	vector<double> numbers;
	while (cin >> a) {
		cout << "The number is: " << a<<"\n";

		if (numbers.size() == 0)
			numbers.push_back(a);

		else {
			if (a < numbers[0])
				cout << "The smallest so far \n";
			else if (a > numbers[numbers.size() - 1])
				cout << "The largest so far \n";
			
			numbers.push_back(a);
		}
		sort(numbers);
	}*/
	



	string mertek;
	double sum = 0;
	double nagy = 0;
	double kicsi = 0;
	double db = 0;
	bool k = true;
	vector<double> v;
	double x;
	cout << "Enter a value with a unit: \n";

	while (cin >> x >> mertek) {
		if (mertek == "cm") {
			x = x / 100;
			sum += x;
			db++;
		}

		else if (mertek == "in") {
			x = (x / 100) * 2.54;
			sum += x;
			db++;
		}

		else if (mertek == "ft") {
			x = (x / 100) * 2.54 * 12;
			sum += x;
			db++;
		}

		else if (mertek == "m") {
			sum += x;
			db++;
		}

		else
			cout << "Wrong unit! \n";

		v.push_back(x);

		if (k) {
			nagy = x;
			kicsi = x;
			k = false;
		}
		else if (x < kicsi) {
			cout << "The smallest so far \n";
			kicsi = x;
		}
		else if (x > nagy) {
			cout << "The largest so far \n";
			nagy = x;
		}

	}

	cout << "Legnagyobb: " << nagy<<'\n';
	cout << "Legkisebb: " << kicsi << '\n';
	cout << "Összeg: " << sum << "m \n";
	cout << "Darab: " << db << '\n';

	sort(v);
	for (int i = 0; i < v.size()-1; i++)
		cout << v[i] << "\n";
}
