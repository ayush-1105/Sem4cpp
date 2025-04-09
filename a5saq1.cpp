#include<iostream>

using namespace std;

class Float {

	private:
		float value;

	public:
		Float (float v = 0.0) : value(v) {}

		Float operator+ (const Float & other) 
		{
			return Float(value + other.value);
		}

		Float operator -(const Float& other) 
		{
			return Float(value - other.value);
		}

		Float operator* (const Float &other) 
		{
			return Float(value * other.value);
		}

		Float operator/(const Float &other) 
		{
			if(other.value == 0)
			{
				cout << "Error : Division by zero " << endl;
				return Float(0);
			}

			return Float(value / other.value);
		}


		friend ostream& operator << (ostream& out ,const Float& f) {
			out << f.value;
			return out;
		}

		friend istream& operator >> (istream& in, Float & f) {
			in >> f.value;
			return in;
		}
};


int main()
{

	Float f1, f2,result;

	cout << "Enter first float number : ";
	cin >> f1;
	
	cout << "Enter second float number : ";
	cin >> f2;

	result = f1 + f2;

	cout << "Addition : " << result << endl;

	result = f1 - f2;
	cout << "Subtraction : " << result << endl;

	result = f1  * f2;
	cout << "Multiplication : " << result << endl;

	result = f1 / f2;
	cout << "Division : " << result << endl;

	return 0;
}
