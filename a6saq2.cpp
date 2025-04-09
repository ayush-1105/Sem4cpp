#include<iostream>


using namespace std;

class Shape {
	protected:
		double dim1, dim2;
	public:
		void getData(double a, double b = 0.0)
		{
			dim1 = a;
			dim2 = b;
		}


		virtual void displayArea() const = 0;

};


class Triangle: public Shape {
	public:
		void displayArea() const override {
			cout << "Area of Triangle : " << 0.5 * dim1 * dim2 << endl;
		}
};

class Rectangle : public Shape {
	public:
		void displayArea() const override {
			cout << "Area of circle : " << dim1 * dim2 << endl;
		}

};

class Circle: public Shape {
	public:
		void displayArea () const override {
			cout << "Area of circle : " << 3.14159 * dim1 * dim1 << endl;
		}

};

int main()
{
	double a,b;

	Triangle triangle;

	do{

		cout << "Enter base of the triangle : ";
		cin >> a;
		if(a <= 0)
			cout << "Please enter valid dimensions" << endl;
	}while(a <=0);

	do{

                cout << "Enter base of the triangle : ";
                cin >> b;
                if(b <= 0)
                        cout << "Please enter valid dimensions" << endl;
        }while(b <=0);

	triangle.getData(a,b);
	triangle.displayArea();

	Rectangle rectangle;
	

	do{

                cout << "Enter length of the rectangle : ";
                cin >> a;
                if(a <= 0)
                        cout << "Please enter valid dimensions" << endl;
        }while(a <=0);

        do{

                cout << "Enter breadth of the rectangle: ";
                cin >> b;
                if(b <= 0)
                        cout << "Please enter valid dimensions" << endl;
        }while(b <=0);
	
	rectangle.getData(a,b);
	rectangle.displayArea();

	Circle circle;

	do{

                cout << "Enter radius of the circle : ";
                cin >> a;
                if(a <= 0)
                        cout << "Please enter valid dimensions" << endl;
        }while(a <=0);


	circle.getData(a);
	circle.displayArea();


	return 0;







}
