#include <iostream>
#include "std_lib_facilities.h";
using namespace std;

int main()
{	
	//1.
	cout << "Enter the name of the person you want to write to: ";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << "\n";
	
	//2.
	cout << "How are you? I'm fine. I miss you. Do you like your university? Tell me something about that.\n";
	
	//3.
	cout << "Enter your friends name: ";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	
	//4.
	char friend_sex = '0';
	cout << "Enter an 'm' if the friend is male and an 'f' if the friend is female: ";
	cin >> friend_sex;
	if(friend_sex == 'm'){
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	}
	else if (friend_sex == 'f') {
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	}

	//5.
	int age;
	cout << "Enter the age of the recipient: ";
	cin >> age;
	if (age <= 0 || age >= 110) {
		simple_error("you're kidding!");
	}
	else
		cout << "I hear you just had a birthday and you are " << age << " years old.\n";

	//6.
	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age > 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "\n";
	cout << "\n";
	cout << "Yours sincerely, Zsolt";
}
