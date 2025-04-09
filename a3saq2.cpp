#include<iostream>
#include<cstring>

using namespace std;

class Time24;
class Time12
{
	int hour, minutes, seconds;
	string a;

	public:

	Time12()
	{
		 hour = 12;
		 minutes = 0;
		 seconds = 0;
		a = "am";


	}

	void mutator(int h, int m, int s, string ar)
	{
		hour = h;
		minutes = m;
		seconds = s;
		a = ar;
	}

	inline void accessor()
	{
		cout << "\nTime in 12 hour format : ";
		cout << hour << ":" << minutes << ":" << seconds << " " << a << endl;
	}

	friend int convert24(Time12 t1);
	friend void compare(Time12 t1, Time24 t2);
};


class Time24
{
        int hh, mm, ss;
        

        public:

        Time24()
        {
		hh = 0;
		mm = 0;
		ss = 0;

        }

        void mutator(int hr, int min, int sec)
	{
		hh = hr;
		mm = min;
		ss = sec;
	}

	inline void accessor()
	{
		cout << "\nTime in 24 hour format : ";
		cout << hh << ":" << mm << ":" << ss << endl;
	}

	friend void convert12(Time24 t2);
	friend void compare(Time12 t1, Time24 t2);
};



void convert12(Time24 t2)
{
	int hour;
	string period;

	if(t2.hh == 0)
	{
		hour = 12;
		period = "am";
	}

	else if(t2.hh >> 12)
	{
		hour = t2.hh - 12;
		period = "pm";
	}

	else
	{
		period = "am";
		hour = t2.hh;
	}


	cout << "\nConverting 24 hour format in 12 hour format : ";
	cout << "\nTime in 24 hour format : " << t2.hh << ":" << t2.mm << ":" << t2.ss;
	cout << "\nTime in 12 hour format : " << hour << ":" << t2.mm << ":" << t2.ss << period  << endl;
}

int convert24(Time12 t1)
{
	int hr;
	if(t1.a == "pm")
	{
		if(t1.hour == 12)
			hr = 12;
		else 
			hr = t1.hour + 12;

	}
	else 
	{
		if(t1.hour == 12)
			hr = 0;
		else 
			hr = t1.hour;
	}

	cout << "\nConverting 12 hour format into 24 hr format : ";
	cout << "\nTime in 12 hour format : " << t1.hour << ":" << t1.minutes << ":" << t1.seconds << t1.a;
	cout << "\nTime in 24 hour format : " << hr << ":" << t1.minutes << ":" << t1.seconds << endl;
	return hr;
}




void compare(Time12 t1, Time24 t2)
{
	int h = convert24(t1);

	if(h == 0 && t2.hh == 24)
	{
		if((t1.minutes == t2.mm)  && (t1.seconds == t2.ss))
		{
			cout << "\nTime in both the formats are same " << endl;
		}
	}


	else if(h == t2.hh)
	{
		if((t1.minutes == t2.mm ) && (t1.seconds == t2.ss))
			cout << "\nTime in both the formats are same " << endl;
		else
			cout << "\nTime in both the formats are not same " << endl;
	}

	else
		cout << "\nTime in both the formats are not same " << endl;
}



int main()

{

	int hour, minute, second;
	string z;


	do{
		cout << "\nEnter time in 12 hour format (hh min sec) : ";
		cin >> hour >> minute >> second;

		if(hour > 12 || hour < 1 || minute > 60 || minute < 0 || second > 60 || second < 0)
			cout << "\nInvalid input of time ";
	}while(hour > 12 || hour < 1 || minute > 60 || minute < 0 || second > 60 || second < 0 );


	do{
		cout << "\am / pm : ";

		cin >> z;


		if(z != "am" && z != "pm")
			cout << "\nInvalid input.Please re enter the am/pm ";
	}while (z != "am" && z != "pm");

	Time12 t;
	t.mutator(hour,minute,second,z);
	t.accessor();


	do
	{
		cout << "\nEnter time in 24 hour format (hr min sec) : ";
		cin >> hour >> minute >> second;

		if(hour > 24 || hour < 0 || minute > 60 || minute < 0 || second > 60 || second < 0)
			cout << "\nInvalid input of time ";
	}while(hour > 24 || hour < 0 || minute > 60 || minute < 0 || second > 60 || second < 0);


	Time24 c;
	c.mutator(hour, minute, second);
	c.accessor();

	compare(t,c);
	return 0;
}







