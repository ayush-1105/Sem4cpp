#include<iostream>
using namespace std;

class Book {
	private:
		int bookID;
		string title;
		string author;
		string genre;
	public:
		void set(int id, string t, string a, string g)
		{
			bookID = id;
			title = t;
			author = a;
			genre = g;

		}

		void displayBook()
		{
			cout << "ID : " << bookID
				<< ", Title : " << title
				<< ", Author : " << author 
				<< ", genre : " << genre << endl;
		}


};


int main()
{
	Book book;

	int id;
	string title, author, genre;


	cout << "Enter the book id : " ;
	cin >> id;
	if(id <= 0) {
		cout << "Id cannot be 0 or negative ";
		return 0;
	}
	cin.ignore();	
	cout << "Enter the title : " ;
	getline(cin,title);

	cout << "Enter the author : ";
	getline(cin,author);

	cout << "Enter the genre : ";
	getline(cin, genre);


	book.set(id,title,author,genre);

	book.displayBook();
	return 0;

	

}
