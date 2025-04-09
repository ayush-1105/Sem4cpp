#include<iostream>

using namespace std;

class Date{


	private:
		int year , month, day;

		bool isleapyear(int y)
		{
			return(y % 4 == 0&& y % 100 != 0) || (y %400 == 0);
		}

		int getmonth(int m, int y)
		{
			if(m == 2)
			{

				return isleapyear(y) ? 29 : 28;
			}
			else if(m == 4 || m == 6 || m == 9 || m == 11)
			{
				return 30;
			}

			else{
				return 31;
			}
		}

	public:
		void getDate(int y , int m, int d)
		{
			while(true)
			{

			cout << "Enter the year : "<< endl;
			cin >> y;
			if(y < 0)
			{
				cout<<"Please enter valid year ";
				return;
			}
			cout << "Enter the month : " << endl;
			cin >> m;
			if(m < 1 || m > 12)
			{
				cout << "Invalid month. Please enter a value between 1 to 12 : "<< endl;
				continue;
			}
			cout << "Enter the date : " << endl;
			cin >> d;
			int max = getmonth(m,y);
			if(d < 1|| d > max)
			
			{
				cout << "Invalid day. Please enter a value between 1 and " <<max<< " for month "<<m << "." << endl;
				continue;
			}


			year = y;
			month = m;
			day = d;
			break;
			}
		}

		void showDate()
		{

			if(year == 0|| month == 0 || day == 0)
			{

				cout << "NO valid date Please enter the valid date : "<< endl;
				return;
			}
			cout << "Date : "<< day << "/" << month << "/" << year << endl;
		}



};

int main(){

	Date date1;

	int year, month, day;


	date1.getDate(year,month,day);
	date1.showDate();
	return 0;
}
