#include<iostream>
#include<iomanip>

using namespace std;

struct Student
{
	string name, sname;
	int seatNumber;

	float gradePoints[6];


};




float calculateSGPA(float gradePoints[], int numSubjects)
{
	float totalGradePoints = 0;
	for(int i = 0; i < numSubjects; i++)
	{
		totalGradePoints += gradePoints[i];
	}
	return totalGradePoints / numSubjects;
}

bool isAlphabet(const string&  s)
{
	for(char ch : s)
	{
		if(!isalpha(ch))
		{
			return false;
		}
		
	}
	return true;
}

void displayMarksheet(Student s, float sgpa)
{

	cout << "\n-----------------------------------\n";

	cout << "             STUDENT MARKSHEET        \n";

	cout << "---------------------------------------\n";

	cout << "Name           : " << s.name << " " << s.name << endl;

	cout << "Seat Number    : " << s.seatNumber << endl;

	cout << "--------------------------------------\n";

	cout << setw(10) << "Subject" << setw(15) << "Grade Points\n";

	cout << "--------------------------------------\n";

	for(int i = 0; i < 6; i++)
	{
		cout << setw(7) << (i + 1) << setw(15) << s.gradePoints[i] << endl;


	}

	cout << "----------------------------------------\n";
	cout << "SGPA       : " << fixed << setprecision(2) << sgpa << endl;
	cout << "----------------------------------------\n";
}




int main()
{
	Student s;
	do {
			cout << "Enter the first name  of the student : ";
			cin >> s.name;

			if(!(isAlphabet(s.name)))
			
			{
				cout << "Please enter name in alphabet only ";
			}

		}while(!(isAlphabet(s.name)));
	
	do {
			cout << "Enter the Surname of the student : ";
			cin >> s.sname;

			if(!(isAlphabet(s.sname)))
			
			{
				cout << "Please enter name in alphabet only ";
			}

		}while(!(isAlphabet(s.sname)));

	do{
		cout << "Enter Exam Seat Number : ";
		cin >> s.seatNumber;

		if(s.seatNumber <= 0)
			cout << "Invalid Seat Number Please Enter valid Exam Seat Number \n ";
	}while(s.seatNumber <=0);


	for(int i = 0; i < 6; i++)
	{
		do{
                cout << "Enter Grade Points for 6 subjects : \n";
                cin >> s.gradePoints[i];

                if(s.gradePoints[i] <= 0 || s.gradePoints[i] > 10 )
                        cout << "Invalid input Please enter the valid grade points  \n ";
        }while(s.gradePoints[i] <= 0 || s.gradePoints[i] > 10 );
	}



	float sgpa = calculateSGPA(s.gradePoints,6);
	displayMarksheet(s,sgpa);

	return 0;
}
