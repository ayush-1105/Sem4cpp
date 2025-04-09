#include<iostream>
using namespace std;




class TalkingInterface 
{
	private:
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
		friend class Person;
		


		
};


class Person
{
	public:
	void display(TalkingInterface &t)
	{
		t.Tables();
		t.Tables(2);
		t.Tables(2,3);
		t.Tables(2,3,6);	
	}

};

int main()
{
	Person p;


	TalkingInterface t;

	


	p.display(t);
	return 0;
}
