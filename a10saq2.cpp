#include<iostream>
#include<string>


using namespace std;

class InvalidUser
{
	string message;

	public:

	InvalidUser(string msg)
	{
		message = msg;
	}
	string what()
	{
		return message;
	}
};


void validateUser(int age, double income, string city)
{
	if(age < 18 || age > 45)
	{
		throw InvalidUser("Invalid Age ! Age must be between 18 to 45 . ");
	}
	if(income < 75000 || income > 150000)
	{
		throw InvalidUser("Invalid Income ! Income must be between Rs. 75,000 - Rs. 1,50,000 per month.");


	}
	if(city !="Pune" && city != "Mumbai" && city != "Bangalore" && city !="Chennai")
	{
		throw InvalidUser("Invalid City! User must stay in Pune, Bangalore, or Chennai. ");
	}
}

int main()
{
	try{
		int age;
		double income;
		string city;

		cout <<"Enter age : ";
		cin >> age;

		cout << "Enter monthly income in Rs : ";
		cin >> income;


		cout << "Enter city : ";
		cin >> ws;

		getline(cin, city);

		validateUser(age,income, city);

		cout << "User details are valid !" << endl;
	}catch(InvalidUser &e){
		cout << "Exception : " << e.what() << endl;
	}

	return 0;
}

