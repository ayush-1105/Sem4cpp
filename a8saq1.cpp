#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

bool isAlphabetOnly(const string& str)
{
                for(char ch : str)
                {
                        if(!isalpha(ch)){
                                return false;
                        }
                }
                return true;
}


class Person{
	public:
		char name[50];
		char city[50];

		void getData(){
			int flag=0;

		do{
                 flag=0;

         cout<<"Enter  name:";
	 cin.ignore();
         cin>>name;

         if(!(isAlphabetOnly(name))){
                 cout<<"Enter valid name"<<endl;
                 flag++;}
         }while(flag>0);

					         do{
                 flag=0;

         cout<<"Enter  city:";
	 cin.ignore();
         cin>>city;

         if(!(isAlphabetOnly(city))){
                 cout<<"Enter valid city"<<endl;
                 flag++;}
         }while(flag>0);
		}


		

		void displayData(){
			cout<<name<<" "<<city<<endl;
		}
};


void writeToFile(Person people[],int count,const string &filename){
	ofstream file(filename);
	if(!file){
		cout<<"Error opening file\n";
		return;
	}

	for(int i=0;i<count;i++)
	{
		file<<people[i].name<<" "<<people[i].city<<endl;
	}
	file.close();
}

int readFromFile(Person people[],const string &filename)
{
	ifstream file(filename);
	if(!file){
		cout<<"Error opening file!\n";
		return 0;
	}
	int count=0;
	while(file>>people[count].name>>people[count].city){
		count++;
	}

	file.close();
	return count;
}

void findCityByName(Person people[],int count,const string &name)
{
	for(int i=0;i<count;i++)
	{
		if(name==people[i].name){
			cout<<"City:"<<people[i].city<<endl;
			return;
		}
	}
	cout<<"Name not found!\n";
}

void findNameByCity(Person people[],int count,const string &city)
{
	for(int i=0;i<count;i++)
	{
		if(city==people[i].city){
			cout<<"Name:"<<people[i].name<<endl;
			return;
		}
	}
	cout<<"City not found!\n";

}

void updateCity(Person people[],int count,const string &name,const string &newCity)
{
	for(int i=0;i<count;i++)
	{
		if(name==people[i].name){
			strcpy(people[i].city,newCity.c_str());
			cout<<"City updated successfully!\n";

			return;
		}
	}
	cout<<"Name not found!\n";
}

int main()
{
	Person people[100];
	string filename="data.txt";
	int count=0,choice;
	string name,city;

	while(true){
		cout<<"\n1.Add Data\n2.Find City by Name\n3.Find Name by City\n4.Update City\n5.Display Data\n6.Exit\nEnter choice:";
		cin>>choice;

		switch(choice){
			case 1:
				people[count].getData();
				count++;
				writeToFile(people,count,filename);
				break;
			case 2:
				cout<<"Enter Name:";
				cin>>name;
				count=readFromFile(people,filename);
				findCityByName(people,count,name);

				break;
			case 3:
				cout<<"Enter City:";
				cin>>city;
				count=readFromFile(people,filename);
				findNameByCity(people,count,city);
				break;
			case 4:
				cout<<"Enter Name:";
				cin>>name;
				cout<<"Enter New City:";
				cin>>city;
				count=readFromFile(people,filename);
				updateCity(people,count,name,city);
				writeToFile(people,count,filename);
				break;

			case 5:
				count=readFromFile(people,filename);
				for(int i=0;i<count;i++)
				{
					people[i].displayData();
				}
				break;
			case 6:
				return 0;
			default:
				cout<<"Invalid Choice!\n";
		}
	}
}
