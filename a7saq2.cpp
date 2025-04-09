#include<iostream>

#include<iomanip>

using namespace std;


int main()
{
	int n;

	do{
		cout << "Enter value of n : ";
		cin >> n;

		if(n <= 0)
			cout << "Invalid input Please try again ";
	}while(n <= 0);


	cout << "\n----------------------------\n";

	cout << setw(8) << "Number" << setw(10) << "Square" << setw(10) << "Cube" << endl;


	cout << "-----------------------------\n";


	for(int i = 1; i<= n; i++)
	{
		cout << setw(8) << i << setw(10) << (i * i) << setw(10) << (i * i * i) << endl;


	}

	cout << "--------------------------\n";

	return 0;

}
