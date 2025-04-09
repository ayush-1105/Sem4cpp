#include<iostream>

using namespace std;

class Rectangle;

float calculate(const Rectangle &rect);


class Rectangle
{

	private:
		float width;
		float length;

	public:
		Rectangle (float l = 1.0, float w = 1.0): length(l) , width(w){}

		void setDimensions(float l, float w)
		{
			if(l > 0 && w > 0)
			{
				length = l;
				width = w;
			}
			else{
				cout << "Invalid dimentations using default values \n";
				length = 1.0;
				width = 1.0;
			}
		}

		void display()
		{
			cout << " Length : " << length << ", Width : " << width << endl;
		}

		friend float calculate(const Rectangle &rect);
};


float calculate(const Rectangle &rect)

{

	return rect.length * rect.width;
}



int main()
{

	Rectangle rect1;

	cout << "Rectangle first using default arguments \n ";
	rect1.setDimensions(-3,-4);
	rect1.display();
	cout << "Area : " << calculate(rect1) << endl;


	float l, w;
	cout << "Enter length and width of the rectangle : ";
	cin >> l >> w;
	

	Rectangle rect2;

	rect2.setDimensions(l,w);
	cout << "Area : " << calculate(rect2) << endl;
}
 
