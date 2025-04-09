#include<iostream>
#include<cmath>

using namespace std;

int power(int base, int exp)
{
	return pow(base,exp);
}

float power(float base, int exp)
{
	return pow(base,exp);
}


int main()
{
	int baseInt, expInt;
	float baseFloat;
	int expFint;


	cout << "Enter an intergerbase and exponent : ";
	cin >> baseInt >> expInt;

	cout << " Power (int ):  " << power(baseInt, expInt) << endl;


	cout << "Enter a floating point base and int exponent : " ;

	cin>> baseFloat >> expFint;
	cout << "Power (float) : " << power(baseFloat, expFint) << endl;


	return 0;
}
