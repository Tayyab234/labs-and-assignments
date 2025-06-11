#include<iostream>
#include<fstream>
using namespace std;
ofstream COUT("D:/STUDENT.DAT");
ofstream out("D:/MARKS.DAT ");
int magic_number;
int main() {
	int ID[50], total, i, a;
	cout << "Please enter magic number : ";
	cin >> magic_number;
	COUT << magic_number << endl;
	out << magic_number << endl;
	cout << "please enter total number of students   :";
	cin >> total;
	COUT << total << endl;
	cout << "please enter this session code : ";
	cin >> a;
	for (i = 0;i < total;i++) {
			ID[i] = a;
			a = a + 1;
			cout << endl;
			COUT << ID[i] << endl;
	
		
	}

   return 0;
}


