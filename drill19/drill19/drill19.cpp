#include <iostream>
#include "std_lib_facilities.h"

template<class T> struct S
{
private:
	T val;
public:
	S(T val) {
		this->val = val;
	}

	T get();
	void set(T&);
	void operator=(T&);
	void operator=(const T&)
};

template<class T>
T S<T>::get() {
	return this->val;
}

template<class T>
void S<T>::set( T& a) {
	val = a;
}

template<class T>
void read_val(T& v) {
	std::cin >> v;
}

template<class T>
void S<T>::operator=(T& a) {
	val = a;
}

template<class T>
void S<T>::operator=(const T& a) {
	val = a;
}

int main()
{
	S<int> num(16);
	S<char> ch('a');
	S<double> d(16.23);
	S<string> s("szoveg");
	S<vector<int>> v(vector<int>{1, 2, 3});

	cout << num.get()<< endl;
	cout << ch.get()<< endl;
	cout << d.get()<< endl;
	cout << s.get()<< endl;

	for (int elem : v.get())
		cout << elem << " ";
	cout << endl;

	cout << "Int: " << endl;
	int be_Int;
	read_val(be_Int);
	num.set(be_Int);

	cout << "Char: " << endl;
	char be_Ch;
	read_val(be_Ch);
	ch.set(be_Ch);

	cout << "Double: " << endl;
	double be_D;
	read_val(be_D);
	d.set(be_D);

	cout << "String: " << endl;
	String be_Str;
	read_val(be_Str);
	s.set(be_Str);

}

