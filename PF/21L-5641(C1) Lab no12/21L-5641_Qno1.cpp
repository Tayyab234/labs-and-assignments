#include<iostream>
using namespace std;
void modefinder(int a[], int s){
	int i, k[100],j=0,m=-99,c=0,mm=0;
	for (int aa = 0;aa < s;aa++) 
		k[aa] = 0;
	for (i = 0;i < s;i++) {
		for (int j = 0;j < s;j++) {
			if (a[i] == a[j])
				k[i] = k[i] + 1;
		}
    }
	for (int y = 0;y < s;y++) {
		if (k[y] > j)
			j = k[y];
	}
	
	for (int y = 0;y < s;y++) {
		if (k[y] != 1&&a[y]!=m) {
			if (k[y] == j) {
				if (mm == 0) {
					cout << "mode is :";
					mm = mm + 1;
				}
				m = a[y];
				cout << a[y] << " ";
			}

		}
		else
			c = c + 1;
	}
	if (c == s)
		cout << "mode does not exist";

}
int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,2};
	int size = 10;
	modefinder( a,  size);
	return 0;
}