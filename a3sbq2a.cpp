#include<iostream>

using namespace std;

class Time24;

class Time12
{
	private : 
		int hour;
		int minute;
		int second;
		string ampm;

	public :
		Time12(int h=12, int m=0, int s=0, string ap = "AM")
		{
			hour=h;
			minute=m;
			second=s;
			ampm=ap;

		}

		int getHour() const { return hour; }
		int getMinute() const { return minute;}
		int getSecond() const {return second;}
		string getAMPM() const {return ampm;}

		void display() const
		{
			cout << hour << ":" << minute << ":" << second << ":" << " " << ampm << endl;
		}


		friend bool compareTime(const Time12 &t12, const Time24 &t24);
		friend Time24 convert12to24(const Time12 &t12);
};

class Time24
{
	private : 
		int hour;
		int minute;
		int second;

	public :
		Time24(int h=0, int m=0, int s=0)
		{
			hour=h;
			minute=m;
			second=s;
		}

		int getHour() const {return hour;}
		int getMinute() const {return minute;}
		int getSecond() const {return second;}

		void display() const 
		{
			cout << hour << ":" << minute << ":" << second << endl;
		}

		friend Time12 convert24to12(const Time24 &t24);
};

Time24 convert12to24(const Time12 &t12)
{
	int h=t12.hour;
	if(t12.ampm == "PM" && h!=12)
	{
		h += 12;
	}
	else if(t12.ampm == "AM" && h==12)
	{
		h=0;
	}
	return Time24(h, t12.minute, t12.second);
}


Time12 convert24to12(const Time24 &t24)
{
	int h = t24.hour;
	string ap;
	if(h<12)
	{
		ap = "AM";
		if(h == 0)
		{
			h=12;     
		}
	}
	else
	{
		ap = "PM";
		if(h!=12)
		{
			h -= 12;  // convert to 12 hr format
		}
	}
	return Time12(h, t24.minute, t24.second, ap);
}

// compare Time12 and Time 24
bool compareTime(const Time12 &t12, const Time24 &t24)
{
	Time24 converted = convert12to24(t12);
	return(converted.getHour() == t24.getHour()
			&& converted.getMinute() == t24.getMinute()
			&& converted.getSecond() == t24.getSecond());
}


int main()
{
	Time12 t12(3,45,30, "PM");
	Time24 t24(15,45,30);

	cout << "Time12 : ";
	t12.display();
	
	cout << "Time24 : ";
	t24.display();


	// compare times
	if(compareTime(t12, t24))
	{
		cout << "Times are equal: " << endl;
	}
	else
	{
		cout << "Times are not equal " << endl;
	}


	// convert time12 to time24
	Time24 converted24 = convert12to24(t12);
	cout << "Converted Time12 to Time24 : ";
	converted24.display();

	//convert time24 to time12
	Time12 converted12 = convert24to12(t24);
	cout << "converted Time24 to Time12 : ";
	converted12.display();

	return 0;
}

