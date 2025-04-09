#include<iostream>
#include<cstring>

using namespace std;

class Reversedata {

	public:
		int invert(int num)
		{
			int rev = 0;
			while(num > 0)
			{
				rev = rev * 10 + num % 10;
				num /= 10;
			}
			return rev;
		}


		char* invert (char* str)
		{
			int len = strlen(str);
			for(int i = 0; i < len / 2; i++)
			{
				swap(str[i], str[len - i - 1]);
			}
			return str;
		}

		void invert (int *arr, int size)
		{
			for(int i = 0; i < size/ 2; i++)
			{
				swap(arr[i], arr[size - i - 1]);
				
			}
		
		}
};


int main()
{

	Reversedata obj;

	int num;
	cout << "Enter an integer : ";
	cin >> num;

	cout << "Reversed Integer : " << obj.invert(num) << endl;

	char str[100];
	cout << "Enter a string : ";
	cin >> str;

	cout << "Reversed string : " << obj.invert(str) << endl;
	

	int size;

	cout << "Enter array size : ";
	cin >> size;
	int arr[size];

	cout << "Enter array element : ";
	for(int i = 0; i < size; i++)
	{
		cin>> arr[i];
	}

	obj.invert(arr, size);

	cout << "Reversed Array : ";
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		
	}
	cout << endl;


	return 0;
}
