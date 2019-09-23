#include <iostream>

using namespace std;

int main()
{
    //változók cseréje különbséggel
    int a;
    int b;
    cout <<"Adjon meg két számot: \n";
    cin >> a >> b;
    
    cout << a <<" "<< b <<"\n";
    a = a+b;
    b = a-b;
    a = a-b;
    cout <<"KIVONÁS: "<< a <<" "<< b <<"\n";
    
    //változók cseréje XOR-ral
    if (a != b)
  {
    a ^= b;
    //cout << a <<"\n";
    b ^= a;
    //cout << b <<"\n";
    a ^= b;
  }
    cout <<"XOR: "<< a << " "<< b <<"\n";
    
    //változók cseréje szorzással
    a = a*b;
    b = a/b;
    a = a/b;
    cout <<"SZORZÁS: "<< a <<" "<< b <<"\n";
    return 0;
}

