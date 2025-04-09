#include<iostream>

using namespace std;

class Rectangle
{
	private:
	double length;
	double width;

	public:
	Rectangle () : length(1.0), width(1.0) {
		cout << "Default constructor " << endl;
	}

	Rectangle(double l, double w){
	
		length = l;
		width = w;

	}

	void display(){
		cout << "Length : " << length << endl << "Width : " << width;
       	}
	~Rectangle() { 
		cout << "\nDestructor is called "<< endl;
	}


};


int main()
{
	
	double length, width;

	do {
		cout << "Enter the length for the Rectangle : ";
		cin >> length;

		if(length <= 0)
			cout << "Please enter length above 0 " << endl;
	}while(length <= 0);

	do {
		cout << "Enter the width for the Rectangle : ";
		cin >> width;

		if(width <= 0)
			cout << "Please enter widht above 0 " << endl;
	}while(width <= 0);

	Rectangle r1(length,width);

	r1.display();

	return 0;
}
