#include<iostream>
using namespace std;
void copy(int l, int h, int* ar, int* arr) {
	for (int i = 0;i < h - l;i++) 
		ar[i] = arr[l + i];
}
void merge(int l1, int h1, int l2, int h2, int* arr) {
	int* a1 = new int[(h1-l1) + 1];
	int* a2 = new int[(h2-l2) + 1];

	copy(l1, h1 + 1, a1, arr);
	copy(l2, h2 + 1, a2, arr);

	a1[(h1 - l1) + 1] = arr[h1] + arr[h2];  // to store infinite value at the end with respect to array
	a2[(h2 - l2) + 1] = a1[(h1-l1) + 1];

	int i = 0, j = 0;
	while (h2-l1>=0) {
		if (a1[i] < a2[j]) {
			arr[l1] = a1[i];
			i++;
		}
		else if (a2[j] < a1[i]) {
			arr[l1] = a2[j];
			j++;
		}
		l1++;
	}
}
void seperator(int l, int h, int* arr) {
	if (l >= h)
		return;

	int m = (l + h) / 2;
	seperator(l, m, arr);
	seperator(m + 1, h, arr);
	merge(l, m, m + 1, h, arr);
}
int main() {
	int* arr = new int[9];
	arr[0] = 3;
	arr[1] = 9;
	arr[2] = 1;
	arr[3] = 0;
	arr[4] = 8;
	arr[5] = 7;
	arr[6] = 6;
	arr[7] = 12;
	arr[8] = 15;
	arr[9] = 13;
	seperator(0, 9, arr);
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << "   ";
	}
	return 0;
}