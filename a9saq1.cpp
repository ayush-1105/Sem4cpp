#include<iostream>
using namespace std;

template<typename T>
T maxi(T a,T b){
	return (a>b) ? a:b;
}


int main()
{
	int int1,int2;

	while(true){
	cout<<"Enter the first integer:"<<endl;
	cin>>int1;

	if(cin.fail()){
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Invalid input!Please enter a valid number.\n";
	}else{
		break;
	}
	}

	while(true){
        cout<<"Enter the second integer:"<<endl;
        cin>>int2;

        if(cin.fail()){
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Invalid input!Please enter a valid number.\n";
        }else{
                break;
        }
        }

	cout<<"Max of "<<int1<<" and"<<int2<<" is "<<maxi<int>(int1,int2)<<endl;

	double double1,double2;
	cout<<"Enter the first double value:"<<endl;
	cin>>double1;

	cout<<"Enter the second double value:"<<endl;
	cin>>double2;
	cout<<"Max of "<<double1<<" and"<<double2<<" is "<<maxi<double>(double1,double2)<<endl;

	char char1,char2;
	cout<<"Enter the first character:"<<endl;
	cin>>char1;

	cout<<"Enter the second character:"<<endl;
	cin>>char2;

	cout<<"Max of "<<char1<<" and "<<char2<<" is "<<maxi<char>(char1,char2)<<endl;

	return 0;
}



