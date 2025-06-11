#include<iostream>
using namespace std;
bool ismember(int* arr, int s, int x) {
	int k,h;
    s--;
	if (s >=0) {
		if (arr[s] == x)
			return 0;
		h = ismember(arr, s, x);
	}
	else
		return -1;
	if (h == 0)
		return 0;
	else
		return -1;
}
int main() {
	int* ar;
	int a;
	ar = new int[6];
	for (int i = 0;i < 6;i++)
		ar[i] = i + 2;
	cout << "\narray is : ";
	for (int i = 0;i < 6;i++)
		cout << ar[i] << "   ";
	cout << "\nEnter number to test : ";
	cin >> a;

	if (ismember(ar, 6, a) == 0)
		cout << "given number is the member of array";
	else
		cout << "given number is not the member of array";

	return 0;
}