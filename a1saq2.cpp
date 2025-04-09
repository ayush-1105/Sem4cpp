#include<iostream>
#include<string>

using namespace std;


class bankaccount {
	private: 
		int accountNo;
		string accountHol;
		string accountType;
		double balance;
	public:
		void initialize(int accN, string name, string type, double initialBalance)
		{
			accountNo = accN;
			accountHol = name;
			accountType = type;
			balance = initialBalance;


		}

		void deposit(double amount)
		{
			if(amount > 0)
			{
				balance += amount;
				cout << "Amount deposited successfully . Current balance :  " << balance << endl;

			}else
			{
				cout << "Invalid amount . Deposite failed. "<<endl;
			}
		}

		void withdraw(double amount)
		{
			if(amount > 0 && amount <= balance)
			{
				balance -= amount;
				cout << "Amount withdrawn successfully . Current balance : "<< balance << endl;

			}else if(amount > balance)
			{
				cout << "Insufficient balance. Withdrawal failed. "<<endl;

			}
			else{
				cout << "Invalid amount. Withdrawal failed. "<<endl;
			}
		}


		void display()
		{
			cout << "\nAccount Information: "<<endl;
			cout << "Account number : "<< accountNo <<endl;
			cout << "Account Holdername : "<< accountHol << endl;
			cout << "Account Type : "<<accountType << endl;
			cout << "Balance : " << balance << endl;
		}

};


int main()
{
	bankaccount account;
	int choice, accountNo;
	string accountHol, accountType;
	double initialBalance,amount;

	cout << "Enter account number : ";
	cin >> accountNo;
	if(accountNo <= 0){cout<<"Please enter account number greater than 0"; return 0;}
	cin.ignore();
	cout <<"Enter account holder name : ";
	getline(cin, accountHol);

	cout << "Enter account type (Saving / Current ): ";
	cin >> accountType;

	cout <<"Enter initital balance : ";
	cin >> initialBalance;
	if(initialBalance < 0)
	{ cout << "Please enter initial Balance as 0 or positive ."; return 0;}

	account.initialize(accountNo, accountHol, accountType, initialBalance);

	do{
		cout << "\nMenu: ";
		cout <<"\n1. Deposit ";
		cout << "\n2. Withdraw";
		cout << "\n3. Display Account Information";
		cout << "\n4. Exit";
		cout << "\nEnter your choice : ";
		cin >> choice;

		switch(choice)
		{

			case 1:
				cout << "Enter amount to deposit : ";
				cin >> amount;
				account.deposit(amount);
				break;
			case 2:
				cout << "Enter amount to withdraw : ";
				cin >> amount;
				account.withdraw(amount);
				break;
			case 3:
				account.display();
				break;
			case 4:
				cout << "Exiting program. "<<endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
		
	}while(choice != 4);
	return 0;
}
