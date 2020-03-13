#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void TestFstream() {

	fstream fs("ITSTEP.txt", ios::in | ios::out);
	if (!fs) {
		cout << "Error opening file" << endl;
	}
	else {
		cout << "Content file: " << endl;
		cout << fs.rdbuf() << endl; // читаємо весь зміст

		fs.seekg(0);
		
		char s = 0;
		while (!fs.eof()) {
			fs.get(s);
			if (s >= 48 && s <= 57) {
				fs.seekg(-1, ios::cur);
				fs << '*';
				fs.seekg(fs.tellg(), ios::beg);
			}
		}
	}
}


int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	/*ofstream fout;

	fout.open("ITSTEP.txt", fstream::app);

	if (!fout.is_open()) {

		cout << "Error opening file" << endl;

	}
	else {
		fout << "Hello world!" << endl;

	}

	ifstream fin("ITSTEP.txt");

	char str[250];

	if (!fin) {
		cout << "Error opening file" << endl;

	}
	else {
		fin.getline(str, 100);
		cout << "U read: " << str << " from file" << endl;
	}*/

	//TestFstream();

	/*ofstream fout;
	string fileName = "randomNumbers.txt";
	fout.open(fileName);

	bool is_open = fout.is_open();
	if (is_open == false) {
		cout << "Error: file not open" << endl;
	}
	else {
		int number;
		for (int i = 0; i < 10; i++)
		{
			number = rand() % 9 + 1;
			fout << number << endl;
		}
	}
	fout.close();*/

	/*ifstream fin;
	fin.open(fileName);

	bool is_open1 = fin.is_open();
	if (is_open1 == false) {
		cout << "Error: File not open" << endl;

	}
	else
	{
		

		int numb;
		int max_number;
		int min_number;
		int i = 0;
		while (!fin.eof())
		{
			fin >> numb;
			if (i == 0) {
				max_number = numb;
				min_number = numb;
				i++;
			}
			else {
				if (max_number < numb) {
					max_number = numb;
				}
				if (min_number > numb) {
					min_number = numb;
				}
			}
			
			
		}
		cout << "Max number in file:" << max_number << endl;
		cout << "Min number in file:" << min_number << endl;


	}
*/

	ifstream fin;
	fstream fin1;

	fin.open("words.txt");
	fin1.open("prog.cs");
	bool is_open = fin.is_open();
	if (is_open == false) {
		cout << "Error: File not open" << endl;

	}
	else
	{
		string word = "";
		string word1 = "";
		int size;
		while (!fin.eof()) {
			fin >> word;
			size = word.length();
			while (!fin1.eof()) {
				fin1 >> word1;
				if (word1==word) {
					fin1.seekg(-size, ios::cur);
					fin1 << "OK";
					fin1.seekg((int)fin1.tellg() + size -2, ios::beg);
				}
			}
		}
	}
	system("pause");
	return 0;
}