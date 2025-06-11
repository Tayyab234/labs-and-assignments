#include<iostream>
#include<string>
using namespace std;

int stringCompare1(string string1, string string2,int i,int j) {
	int a;
	if (i < j) {
		if (string1[i] != string2[i]) {
			if (string1[i] > string2[i])
				return 1;
			else
				return -1;
		}
		a=stringCompare1(string1,string2,i+1, j);
		return a;
	}
	else
		return 0;

}

int main() {
	string h1,h2;
	int j;

	int a;
	h1 = "Hello world";
	h2 = "Hello World";
	if (h1.length() >= h2.length())
		j = h1.length();
	else
		j = h2.length();
	a = stringCompare1(h1, h2,0,j);
	if ( a == 0)
		cout << "\n Given strings are equal";
	else if (a == 1)
		cout << "\n Given strings are not equal and first string ascii character is greater where first mismatch occured";
	else
		cout << "\n Given strings are not equal";
	return 0;
}