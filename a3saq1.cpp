#include<iostream>
using namespace std;

class TalkingInterface;

class Person
{
	private:
		string name;
	public:
		Person(string personN) : name(personN){}

		void display() {
			cout << "\nThis is person Class display " << name << endl;
		}

		friend class TalkingInterface;

};
class TalkingInterface 
{
	public:
		void Tables()
		{
			cout << "Display table from 1 to 10 " << endl;
			for(int i = 1; i <= 10; i++)
			{
				for(int j = 1; j <=10; j++)
				{
					cout << i << " x " << j << " = " << i * j << endl;
				}
				cout << endl;
			}
		}

		void Tables(int num)
		{
			cout << "Display table of 2 from 1 to 10 " << endl;
			for(int i = 1; i<=10;i++)
			
			{
				cout << num << " x " << i << " = " << num * i << endl;
			}
			cout << endl;
		}

		void Tables(int num, int start)
		{

			cout << "Display table of 2 from 3 to 10 " << endl;
		
			for(int i = start; i <= 10; i++)
			{
				cout << num << " x " << i << " = " << num * i << endl;
			}
			cout << endl;
		}

		void Tables(int num, int start, int end)
		{

			cout << " Displays table of 2 from 3 to 6 " << endl;
			for(int i = start; i <= end;i++)
			{
				cout << num << " x "<< i << " = " << num * i << endl;
			}
			cout << endl;
		}

		void personUse(Person & person)
		{
			person.display();
			cout << "\nAccessing Person class using friend function \n" << person.name << endl;
		}


		
};

int main()
{
	Person person("\nSending data from main() function to the Person class\n");


	TalkingInterface t;

	t.Tables();
	t.Tables(2);
	t.Tables(2,3);
	t.Tables(2,3,6);


	t.personUse(person);
	return 0;
}
