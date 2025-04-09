#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;

void replaceWordInFile(const char * filename, const char *oldWord, const char *newWord)
{
	ifstream file(filename);
	if(!file)
	{
		cout << "Error opening file \n";
		return;
	}

	string content,line;
	
	bool found = false;
	while(getline(file,line))
	{
		size_t pos = 0;
		while((pos = line.find(oldWord, pos)) !=string::npos)
		{
			found = true;
			line.replace(pos, strlen(oldWord),newWord);
			pos += strlen(newWord);
		}
		content += line + "\n";

	}


	file.close();
	
	if(!found)
	{
		cout << "Word '" << oldWord  << " not found in the file !\n";
		return;
	}

	ofstream outFile(filename);
	if(!outFile)
	{
		cout << "Error writing to file !\n";
		return;
	}
	outFile << content;
	outFile.close();

	cout << "Replacement complete !\n";
}


int main(int argc, char * argv[])
{
	if(argc != 4)
	{
		cout << "Usage : " << argv[0] << "<old word> <new word> <file name >\n";
		return 1;
	}
	replaceWordInFile(argv[3],argv[1],argv[2]);
	return 0;
}
