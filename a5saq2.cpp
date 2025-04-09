#include<iostream>
#include<cstring>


using namespace std;

class String
{

	private:
		char *str;
		int length;

	public:
		String(const char* s = "")
		{
			length = strlen(s);
			str = new char[length + 1];

			strcpy(str, s);
		}

		String(const String& other)
		{
			length = other.length;
		        str = new char[length + 1];
			strcpy(str,other.str);	
		}

		~String()
		{
			delete[] str;
			cout << "\nThis is destructor " <<endl;
		}



		String & operator = (const String& other)
		{
			if(this ==&other)
				return *this;

			delete[] str;
			length = other.length;

			str = new char[length + 1];
			strcpy (str,other.str);
			return *this;
			// old memory free kar rhe
		}

		String operator + (const String & other) const {
			int newLength = length  + other.length;

			char* newStr = new char[newLength + 1];

			strcpy(newStr, str);
			strcat(newStr, other.str);

			String result(newStr);
			delete[] newStr;

			return result;
		}

		bool operator <=(const String &other) const {
			return strcmp(str,other.str) <= 0;
		}

		bool operator >= (const String &other) const {
			return strcmp(str,other.str) >= 0;
		}

		bool operator == (const String &other) const {
			return strcmp(str, other.str) == 0;
		}

		friend ostream &operator << (ostream &out, const String &s){
			out << s.str;
			return out;
		}

		friend istream &operator >> (istream &in,  String &s)
		{
			char temp[100];
			in >> temp;
			s = String(temp);
			return in;
		}
};

int main()
{
	String s1, s2, result;

	cout << "Enter first string : ";
	cin >> s1;

	cout << "Enter second string : ";
	cin >> s2;

	result = s1 + s2;

	cout << "Concatenated String : " << result << endl;


	if(s1 == s2)
	{
	
		cout << "\nBoth strings are equal \n";
	}

	else if(s1 <= s2)
	{
		cout << "\nFirst string is smaller or equal to the second string ";
	}

	else if(s1 >= s2)
	{
		cout << "\nFirst string is greater or equal to the second string ";
	}

	return 0;
}

