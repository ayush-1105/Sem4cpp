#include<iostream>
#include<cmath>

using namespace std;

class calculator{

	private:
		double operand1;
		double operand2;
		char operation;

	public:
		calculator(double op1 = 0.0,double op2 = 0.0, char op = '+') :
		operand1(op1),operand2(op2), operation(op)
		{}

		inline double add()
		{
			return operand1 + operand2;
		}

		inline double sub()
		{
			return operand1 - operand2;
		}

		inline double multi()
		{
			return operand1 * operand2;
		}

		inline double divide()
		{
			if(operand2 == 0)
			{
				cout << "Error : Division by zero is undefined \n";
				return NAN;
			}
			return operand1/operand2;
		}


		inline double sq()
		{
			if(operand1 < 0)
			{
				cout << "Square root of a negative number is undefined \n";
				return NAN;
			}

			return sqrt(operand1);
		}

		inline double reci()
		{
			if(operand1 == 0)
			{
				cout << "Reciprocal of the zero is undefined \n";
				return NAN;
			}

			return 1.0/ operand1;
		}


		void setoperand(double op1, double op2 = 0.0)
		{
			operand1 = op1;
			operand2 = op2;
		}	

		void display(char op)
		{
			switch(op)
			{
				case '+':
					cout << "Result of addition : " << add() << endl;
					break;
				case '-':
					cout << "Result of subtraction : " << sub() << endl;
					break;
				case '*':
					cout << "Result of multiplication : " << multi() << endl;
					break;
				case '/':
					cout << "Result of division : " << divide() << endl;
					break;
				case 's':
					cout << "Result of square root : " << sq() << endl;
					break;
				case 'r':
					cout << "Result of reciprocal : " << reci() << endl;
					break;
				default:
					cout << "Please try again  "  << endl;

			}
		}
};



int main()
{
	calculator calc;

	char choice;

	int flag ;

	do {
		double op1 = 0.0, op2 = 0.0;

		char operation;

		cout << "\nSimple calculator \n";
		cout << "Enter operation  ( + , - , * , / , s  for square root, r for reciprocal ) : ";

		cin >> operation;
		
		if(operation == 's' || operation == 'r')
		{
			cout << "Enter a number : ";
			cin >> op1;

			calc.setoperand(op1);
		} else if(operation == '+' || operation == '-' || operation == '*' || operation == '/'){
			cout << "Enter first operand : ";
			cin >> op1;
			cout << "Enter second operand : ";
			cin >> op2;

			calc.setoperand(op1,op2);
		}else{cout << "Invalid operation ";}
		calc.display(operation);

		cout << "\nDo you want to perform another calculation ? (y/n) : ";

		cin >> choice;
	}while(choice == 'y' || choice == 'Y');

	return 0;
}
