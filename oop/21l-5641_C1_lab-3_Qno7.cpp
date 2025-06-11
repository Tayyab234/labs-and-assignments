#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
void Election( char** canidates,  int* Votes) {
	int k=0,l;
	float s=0, p[5];
	for (int i = 0;i < 5;i++) {
		s = s + Votes[i];
		if (k <= Votes[i]) {
			k = Votes[i];
			l = i;
		}
	}
	for (int i = 0;i < 5;i++)
		p[i] = Votes[i] / s * 100;
	cout << "Candidates and their votes and percentages are given below :\n";
	int t = 0;
	while (t < 5) {
		for (int i = 0;i < 10;i++) {
			if (canidates[t][i] >= 65 && canidates[t][i] <= 90 || canidates[t][i] >= 97 && canidates[t][i] <= 122)
				cout << canidates[t][i];
		}
		cout << "   " << Votes[t] <<"   " << p[t] << endl;
		t = t + 1;
	}
	cout << "THe winner of the election  is : ";
	for (int i = 0;i < 10;i++) {
		if (canidates[l][i] >= 65 && canidates[l][i] <= 90 || canidates[l][i] >= 97 && canidates[l][i] <= 122)
			cout << canidates[l][i];
	}
}
int main() {
	int* s;
	s = new int[5];
	char** a;
	a = new char* [5];
    for (int i = 0;i < 5;i++) {
		a[i] = new char[10];
	}
	int i = 0;
	int* r;
	r = new int[5];
	cout << "Please enter the  " << 1 << " candidate name : ";
	cin.getline(a[0], 10);
	cout << endl;
	cout << "Please enter the  " << 2 << " candidate name : ";
	cin.getline(a[1], 10);
	cout << endl;
	cout << "Please enter the  " << 3<< " candidate name : ";
	cin.getline(a[2], 10);
	cout << endl;
	cout << "Please enter the  " << 4 << " candidate name : ";
	cin.getline(a[3], 10);
	cout << endl;
	cout << "Please enter the  " << 5 << " candidate name : ";
		cin.getline(a[4], 10);
		cout << endl;
	while (i < 5) {
		
		
		cout << "Please enter the votes of  " << i+1 << " candidate : ";
		cin >> r[i];
		cout << endl;
		i = i + 1;
	}
	Election(a, r);

	


	return 0;
}