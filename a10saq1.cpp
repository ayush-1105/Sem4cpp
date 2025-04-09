#include<iostream>

using namespace std;

double getPositiveNumber()
{
	double num;
	
	cin >> num;
	if(num < 0)
	{
		throw "Number not positive ";
	}
	
	return num;
}


int main()
{
	try
	{
		double num1, num2;

		cout << "Enter the first positive number : ";
		num1 = getPositiveNumber();


		cout << "Enter the second positive number : ";
		num2 = getPositiveNumber();

		if(num2 == 0)
		{
			throw "Divide by zero error ";
			
		}

		double result = num1 / num2;
		cout << "Result : " << result  << endl;
	}
	catch(const char *msg)
	{
		cout << "Exception : " << msg << endl;
	}

	return 0;
}
