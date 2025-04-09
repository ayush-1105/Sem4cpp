#include<iostream>

using namespace std;

class Complex
{
	private:
		double real;
		double imag;

	public:
		Complex(double r = 1.0, double i = 1.0)
		{
			real = r;
			imag = i;

		}

		void display()
		{
		
			cout <<  real   << " + "  <<"(" << imag << "i" << ")" << endl;
		}

		Complex add(Complex &c)
		{
			return Complex(real + c.real,  imag + c.imag);
		}

		Complex sub(Complex &c)
		{
			return Complex(real - c.real, imag - c.imag);
		}

		Complex multi(Complex &c)
		{
			return Complex((real * c.real - imag * c.imag),
					(real * c.imag + imag * c.real));
		}

};


int main()
{
	

	double real, imag;
	double a1,b1,a2,b2;
	cout << "Enter the real and imaginary part (a1 + b1i) : ";
	cin >> real >> imag;
	a1 = real;
	b1 = imag;
	Complex complex1(real, imag);

	cout << "Enter the real and imaginary part (a2 + b2i) : ";
        cin >> real >> imag;
	a2 = real;
	b2 = imag; 
        Complex complex2(real, imag);


	cout << "\nFirst complex Number : ";
	complex1.display();

	cout << "\nSecond complex Number : ";
	complex2.display();

	Complex sum = complex1.add(complex2);
	cout << "\nAddition :  " << "(" << a1  << " + " << "(" << b1 << "i" <<"))" << " + " 
	<< "(" << a2  << " + " << "(" << b2 << "i" <<"))";
	cout << endl;
	sum.display();

	Complex sub = complex1.sub(complex2);
	cout << "\nSubtraction : " << "(" << a1  << " + " << "(" << b1 << "i" <<"))" << " - "
        << "(" << a2  << " + " << "(" << b2 << "i" <<")";
	cout << endl;
	sub.display();

	Complex prod = complex1.multi(complex2);
	cout << "\nMultiplication : " << "(" << a1  << " + " << "(" << b1 << "i" <<")" << " * "
        << "(" << a2  << " + " << "(" << b2 << "i" <<"))" ;
	cout << endl;
	prod.display();
	


	return 0;

}
