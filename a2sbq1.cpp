#include<iostream>

using namespace std;

class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		int gcd(int a, int b)
		{
			while(b != 0)
			{
				int temp = b;
				b = a% b;
				a = temp;
			}
			return a;
		}

		void reduce()
		{
			int divisor = gcd(numerator,denominator);
			numerator /= divisor;

			denominator /= divisor;

			if(denominator < 0)
			{
				numerator = -numerator;
				denominator = -denominator;
			}
			
		}

		public:
		Fraction() : numerator(0), denominator(1) {}

		Fraction (int num, int deno) : numerator(num),denominator(deno) { 
			if(deno == 0)
			{
				cout << "Denominator cannot be 0 " ;
				denominator = 1;
			}

			reduce();
	

		}

		void input ()
		{
		
			do{
                                cout << "Enter numerator : ";
                                cin >> numerator;

                                if(numerator == 0)
                                        cout << "Denominator cannot be 0 ";
                        }while (numerator == 0);


			do{
				cout << "Enter denominator : ";
				cin >> denominator;

				if(denominator == 0)
					cout << "Denominator cannot be 0 ";
			}while (denominator == 0);
			
			reduce();
		}

		static Fraction add(Fraction &f1, Fraction &f2)
		{
			int num = (f1.numerator * f2.denominator) +( f2.numerator * f1.denominator);
			int deno = f1.denominator * f2.denominator;

			return Fraction(num, deno);
		}


		static Fraction sub(Fraction &f1, Fraction &f2)
		{
			int num = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
			int deno = f1.denominator * f2.denominator;
			return Fraction(num,deno);


		}

		static Fraction multi(Fraction &f1, Fraction &f2)
		{
			int num = f1.numerator * f2.numerator;
			int deno = f1.denominator * f2.denominator;
			return Fraction(num, deno);
		}

		static Fraction divide(Fraction &f1, Fraction &f2)
		{
			if(f2.numerator == 0)
			{
				cout << "Division by zero is not defined : " << endl;
				return Fraction(0,1);
			}

			int num = f1.numerator * f2.denominator;
			int deno = f1.denominator * f2.numerator;

			return Fraction(num, deno);
		}


		void display() {
			if(denominator == 1)
			{
				cout << numerator << endl;
			}
			else {
				cout << numerator  << "/" << denominator << endl;
			}
		}


		
};

int main()

{


	Fraction f1, f2;

	cout << " \nEnter the first fraction : \n" ;
	f1.input();
	cout <<endl;


	cout << "The simplified fraction 1 : " <<endl;	
	f1.display();


	cout << "\nEnter the second fraction : \n " ;
	f2.input();

	cout << "The simplified fraction 2 : " <<endl;
        f2.display();

	Fraction sum = Fraction::add(f1,f2);
	cout << "\nSum : ";
	sum.display();

	Fraction sub = Fraction::sub(f1,f2);
	cout << "\nSub : ";
	sub.display();

	Fraction multiply = Fraction::multi(f1,f2);
	cout << "\nMulti : ";
	multiply.display();

	Fraction divide = Fraction::divide(f1,f2);
	cout << "\nDivide : ";
	divide.display();

	return 0;

	
}
