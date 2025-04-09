#include<iostream>


using namespace std;


class car {

	private:
		string company;
		string model;
		int year;
	public:
		void setDetails(string c, string m, int y)
		{
			company = c;
			model = m;
			year = y;
		}

		void display()
		{
			cout << "Details of the car : " << endl;
			cout << "Car company : " << company << endl;
			cout << "Car model : " << model << endl;
			cout << "Car year : " << year << endl;
		}



};

int main()
{

	string company, model;
	int year;

	car car1;

	cout << "Enter the details of the car " << endl;
	cout << "Enter the complay of the car : " ;
	cin.ignore();
	getline(cin,company);
	
	cout << "Enter the model of the car : ";
	cin.ignore();

	getline(cin,model);

	cout << "Enter the year of the car : ";
	cin >> year;

	if( year <= 0) 
	{
	
		cout << "Year value cannot be 0 or negative " << endl;
		cout << "Please enter the valid detials " << endl;
		return 0;
	}

	car1.setDetails(company,model,year);
	car1.display();



	return 0;

}
