#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int weight = 0;

int search_min(int**mas, bool* involved, int n, int i, int& poz_nez) {
	int mn = 2147483647;
	for (int j = 0; j < n; j++)
		if (mas[i][j] < mn && mas[i][j] > 0 && !involved[j]) { mn = mas[i][j]; poz_nez = j; }

	return mn;
}

int search_edge(int** mas, bool* involved, int n, int& poz_zan) {
	int mn = 2147483647, poz_nez = 0, tec, poz_nez_nez;
	
	for (int i = 0; i < n; i++) {
		if (involved[i]) {
			tec = search_min(mas, involved, n, i, poz_nez);
			if (mn > tec && !involved[poz_nez]) {
				mn = tec;
				poz_zan = i;
				poz_nez_nez = poz_nez;
			}
		}
	}
	weight += mn;
	//cout << mn << ' ';
	involved[poz_nez_nez] = true;
	return poz_nez_nez;
}

int chislo(string s) {
	int k = s[0] - 48;
	for (int i = 1; i < s.size(); i++)
		k = k*10 + (s[i]-48);
	return k;
}

int main()
{
	int n, poz_zan = 0;
	string a;
	ifstream open;
	ofstream close;

	open.open("input.txt");
	close.open("output.txt");

	open >> n;
	bool* involved = new bool[n];
	for (int i = 0; i < n; i++)
		involved[i] = false;

	string* answer = new string[n];

	int** mas = new int *[n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[n];


	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			open >> a;
			//close << a << endl;
			if (a[0] != '`') mas[i][j] = chislo(a);
			else mas[i][j] = -1;
		}

	involved[0] = true;

	for (int i = 0; i < n - 1; i++) {
		int p = search_edge(mas, involved, n, poz_zan) + 1;
		answer[i] = answer[i] + to_string(poz_zan + 1) + ' ' + to_string(p);
		
		//close  << poz_zan + 1 <<' ' << p << endl;
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			close << mas[i][j] << ' ';
		close << endl;
	}*/
	close << weight << endl;
	for (int i = 0; i < n-1; i++)
		close << answer[i] << endl;
	return 0;
}
