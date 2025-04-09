#include<iostream>
using namespace std;

class rectangle{

	private:
		int length;
		int width;
	public:
		void setlength(float l)
		{
			if(l > 0)
			{
				length = l;
			}
			else {
				cout << "Length must be positive .\n";
				
			}
		}
		void setWidth(float w)
		{
			if(w > 0)
				width = w;
			else
				cout << "Width must be positive \n";
				
		}


		float perimeter()
		{
			return 2 * (length + width);
		}

		float area()
		{
			return length * width;
		}

		void show()
		{
			cout << "Length : "<< length << ", Width : " << width << endl;
		}

};

int main()
{

	rectangle react1, react2;

	float length, width;

	cout << "Enter the length and width of Rectangle 1 : ";
	cin >> length >> width;
	if( length <=0 || width <= 0) 
	{
		cout << "Invalid dimension " ;
		return 0;
	}
	react1.setlength(length);
	react1.setWidth(width);

	cout << "Enter the length and width of Rectangle 2 : ";
	cin >> length >> width;
	if( length <=0 || width <= 0)
        {
                cout << "Invalid dimension " ;
                return 0;
        }
	react2.setlength(length);
	react2.setWidth(width);

	react1.show();
	cout << "Area : " << react1.area() << endl;
	cout << "Perimeter : " << react1.perimeter() << endl;
	
	cout << "\nReactangle 2 : \n";
	react2.show();
	cout << "Area : " << react2.area() << endl;
	cout <<	"Perimeter : "<<react2.perimeter() << endl;

	return 0;
}
