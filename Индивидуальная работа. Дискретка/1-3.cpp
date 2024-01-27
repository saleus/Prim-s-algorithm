#include <iostream>
#include <set>
#include <algorithm>
#include<string>
#include<windows.h>
#include<iterator>
#include <sstream>
#include<fstream>
using namespace std;

void input(set<string>& m, ifstream& f1)
{
	
	string str;
	getline(f1, str);
	stringstream ss(str);
	string word;
	while (ss >> word) {
		m.insert(word);
		cout << word << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<string>m1, m2, m3;
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	
	input(m1, f1);
	string str;
	getline(f1, str);
	input(m2, f1);
	
	set_symmetric_difference(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m3, m3.end()));
	
	copy(m3.begin(), m3.end(), ostream_iterator<string>(f2, " "));
	return 0;
}
