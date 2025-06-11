#include<iostream>
#include<windows.h>
using namespace std;
void show(int* a, int s) {
	cout << endl<<"Content of sorted 1D-array are : ";
	for (int i = 0;i < s;i++)
		cout << a[i] << "  ";
}
void sort(int* a, int s) {
	int t;
	for (int i = 0;i < s;i++) {
		for (int j = i+1;j < s;j++) {
			if (a[j] <= a[i]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	show(a, s);
}
void one_D_array(int** a, int r,int s) {
	int* d = new int[s];
	int h = 0;
	for (int i = 0;i < r;i++) {
		for (int j = 1;j <=a[i][0];j++) {
			d[h] = a[i][j];
			h = h + 1;
		}
	}
	sort(d, s);
}
void fillarray(int** a,int r) {
	cout << "PLease input the array  : \n";
	for (int i = 0;i < r;i++) {
		for (int j = 1;j <= a[i][0];j++)
			cin >> a[i][j];
	}

}
int main() {
	int r,c,s=0;
	cout << "Please enter row of 2D-array : ";
	cin >> r;
	int**arr = new int*[r];
	for (int i = 0;i < r;i++) {
		cout <<endl<< "please enter columns number of Row-" << i << "  :";
		cin >> c;
		s = s + c;
		arr[i] = new int[c+1];
		arr[i][0] = c;
	}
	fillarray(arr, r);
	one_D_array(arr, r, s);
	Sleep(-1);
	return 0;
}