#include<iostream>
using namespace std;
int main() {
	string text = "Hello everyone, this is the final lab task";
	int length = 42,HashSalt=10,j,k=3,u;
	j = length - 1;
	for (int i = 0;i < length/2;i++) {
		if (k % 2 != 0) {
			u = text[i];
			text[i] = text[j];
			text[j] = u;
			
			j = j - 2;
		}
		else 
			text[i] = text[i];
		k = k + 1;
	}
	for (int i = 0;i < length;i++) {
		text[i] = text[i] +HashSalt ;
		cout << text[i];
	}
	return 0;
}
