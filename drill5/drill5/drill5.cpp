#include "std_lib_facilities.h"

int main()
{
	try {
		/*
		cout << "Success!\n"; // ;
		cout << "Success!\n"; // "
		cout << "Success!" << "\n"; // " ;
		String success = "Success!";
		cout << success<< '\n'; 

		int res =7; // string res => int res
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";
		vector<int> v(10);
		v[5] = 7; // v(5) = v[5] *
		if (v[5] == 7) cout << "Success!\n"; // "; != 7 => == 7 v(5) => v[5]


		bool cond = true;
		if (cond) cout << "Success!\n";
		else cout << "Fail!\n"; // cond = true
		bool c = true;  // false => true
		if (c) cout << "Success!\n";
		else cout << "Fail!\n";
		string s = "ape";
		bool c = "fool"; // boo => bool
		s = c;
		if (c) cout << " Success!\n ";

		string s = "ape";
		if (s != "fool")
			cout << "Success!\n"; // if(s == "fool") => if(s != "fool")

		string s = "ape";
		if (s != "fool")
			cout << "Success!\n"; // if(s=="fool") => if(s!="fool") , cout < => cout <<

		string s = "ape";
		if (s != "fool")  // s+"fool" => s != "fool"
			cout << "Success!\n"; // cout < => cout << (2x <)

		vector<char> v(5);
		for (int i = 0; i < v.size(); ++i); cout << "Success!\n"; // 0 < v.size() => i < v.size();
		vector<char> v(5);
		for (int i = 0; i < v.size(); ++i); cout << "Success!\n"; // i<=v.size() => i<v.size()

		string s = "Success!\n";
		for (int i = 0; i < s.length(); ++i) cout << s[i]; // i<6 => i<s.length()
		if (true) cout << "Success!\n"; // then => *removed*
		else cout << "Fail!\n";

		int x = 2000;
		char c = x;
		if (c == -48) cout << "Success!\n"; //  c becomes -24 (on some machines) when x = 1000, so if x = 2000 , I assume c becomes twice (-24 * 2 = -48) => correct
		string s = "Success!\n"; for (int i = 0; i < s.length(); ++i) cout << s[i]; // i<10 => i<s.length()
		vector<int> v(5); // vector v(5) => vector<T> v(5)
		for (int i = 0; i < v.size(); ++i); cout << "Success!\n"; // i<= v.size() => i<v.size()

		int i = 0;
		int j = 9;
		while (i < 10) // removed ;
		{
			i++;
		}
		if (j < i) cout << "Success!\n";
		int x = 1; // 2 = >
		double d = 5.0 / (x * 2);  // (x - 2) => (x * 2)
		if (d == 2 * x + 0.5) cout << "Success!\n";

		string s = "Success!\n"; // string<char> => string
		for (int i = 0; i < s.length(); ++i) cout << s[i]; // i<= 10 => i < s.length()

		int i = 0;
		int j = 0;
		while (i < 10)
		{
			++i; // j++ => i++
		}
		if (j < i) cout << "Success!\n";

		int x = 4;
		double d = 5.0 / (x - 2); // invalid character `–` => -, 5 => 5.0
		if (d = 2 * x + 0.5) cout << "Success!\n";
*/
		cout << "Success!\n"; // cin(beolvasás) => cout(kiírás)

		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}