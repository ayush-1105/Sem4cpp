#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct wordCount{
	 char word[50];
	 int count;
};
int findWord(wordCount words [] ,int size , const char *word)
{
	for(int  i=0 ; i< size;i++)
	{
		if(strcmp(words[i].word, word)== 0)
		{
			return i;
		}
	}
	return -1;
}

void countWordFrequency( const char *filename,const char *outputFile)
{
	ifstream file(filename);

	if (!file)
	{
		cout << "Error opening file !\n";
		return;
	}
	wordCount  words[500];
	int size = 0;
	char word[50];

	while(file >> word)
	{
		int index = findWord(words, size, word);
		if(index != -1)
		{
			words[index].count++;
			
		}else{
			strcpy(words[size].word, word);
			words[size].count = 1;
			size++;
		}
	}

	file.close();

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i -1; j++)
		{
			if(words[j].count < words[j + 1].count)
			{
				swap(words[j], words[j + 1]);
			}
		}
	}


	ofstream outFile(outputFile);

	for(int i = 0; i  < size ; i++)
	{

		outFile << words[i].word << ": " << words[i].count << endl;
	}

	outFile.close();


	cout << "Word frequency stored in  " << outputFile << endl;
}


int main()
{

	char filename[50], outputFile[50];
	cout << "Enter input file name : ";

	cin >> filename;
	cout << "Enter output file name : ";
	cin >> outputFile;

	countWordFrequency(filename, outputFile);

	return 0;
}

