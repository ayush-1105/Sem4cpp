#include<iostream>

using namespace std;


class student{

	private : 
		int rollno;
		string name;
		string studentClass;
		float marks;
		char grade;
	
	void calculateGrade()
	{
		if(marks >= 90)
		{
			grade = 'A';
		}else if(marks >= 75)
		{
			grade = 'B';
		}else if(marks >= 50){
			grade = 'C';
		}else if(marks >= 35){
			grade = 'D';
		
		
		}
		else{
			grade = 'F';
		}

	}


	public:
		void setDetails(int r, string n,string c, float m){
			rollno = r;
			name = n;
			studentClass = c;
			marks = m;
			calculateGrade();
		}
		void displayDetails()
		{
			
			cout << "\nStudent Details: "<< endl;
			cout << "Roll no : " << rollno << endl;
			cout << "Name : "<< name << endl;
			cout << "Class : "<< studentClass << endl;
			cout << "Marks : " << marks << endl;
			cout << "Grade : " << grade << endl;
		}

			

};


int main()
{
	int n;

	cout << "Enter the number of students data to enter : ";
	cin >> n;

	student students[10];

	for(int i = 0; i < n; i++)
	{

		int rollno;
		string name,studentClass;
		float marks;

		cout << "\nEnter details for student : " << i + 1 << " :  "<< endl;
		cout << "Roll no : ";
		cin >> rollno;
		if(rollno <= 0)
		{
			cout << "Invalid roll number : ";
			return 0;
		}
		cin.ignore();
		cout << "Name : ";
		getline(cin, name);

		cout << "Marks : ";
		
		cin >> marks;
		if(marks <0)
		{
			cout << "Marks cannot be negative : ";
			return 0;
		}
		if(marks > 100) {cout << "Marks cannot be above 100 " ; return 0;}
		students[i].setDetails(rollno, name, studentClass, marks);
	}

	cout << "\n--- student Details ---"<< endl;
	for(int i = 0; i < n;i++)
	{
		students[i].displayDetails();
	}

	return 0;
}

