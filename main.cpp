#include <iostream>
#include <fstream>
#include <cstring>
#include<ctime>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int createFiles(int, string);
int randomNum();

string enterFolder();
int enterAmount();

int main()
{
	srand(time(NULL));
	string folderName = enterFolder();
	int filesAmount = enterAmount();
	cout<<filesAmount<<endl;
	int amount = 0;
	while(amount++ < filesAmount)
	{
		createFiles(randomNum(), folderName);
	}
	cout<<"All .txt files were created."<<endl;
	return 0;
}

int createFiles(int number, string outFolder)
{
	fstream fs;
	string filename = outFolder + "/" + to_string(number) + ".txt";
	fs.open(filename, fstream::out);
	fs.close();
	return 1;
}

int randomNum()
{
	return 23 + rand() % 12000000;
}

string enterFolder()
{
	string outFolder;
	do
	{
		cout<<"Enter folder to create empty files: ";
		cin>>outFolder;
	} while (cin.fail());
	return outFolder;
}

int enterAmount()
{
	int amount;
	cout<<"How much files do you want? (Max amount is 2000) ";
	cin>>amount;
	while(cin.fail() || amount > 2000)
	{
		cout<<"How much files do you want? (Max amount is 2000)";
		cin.clear();
		cin.ignore(256,'\n');
		cin>>amount;
	}
	return amount;
}