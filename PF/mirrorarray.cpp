#include<iostream>
using namespace std;
bool Mirror_TwoD(int a[100][100], int columns, int rows) {
	int i, j = 0, h = 0, A = 1, k = 0, t,m=0,u=0;
	if (columns != rows)
		return false;
	else {
		for (i = 0;i < rows - 1;i++) {
			if (a[i][i] == a[i + 1][i + 1])
				j = j + 1;
		}
		if (i != j)
			return false;
		else {
			for (int j = 1;j < columns;j++)
				m = m + j;
			for (t = 0;t < m;t++) {
				if (h < columns) {
					h = h + 1;
					if (a[u][h ] == a[h ][u])
						k = k + 1;
					
				}
				else {
					h = h - columns + A;
					A = A + 1;
					u = u + 1;
					t--;
				}

			}
		    
			if (k == t)
				return true;
			else
			    return false;
		}
	}
}
int main() {
	int n[100][100], m, l;
	cout << "Please enter number of rows : ";
	cin >> l;
	cout <<endl<< "Please enter number of columns : ";
	cin >> m;
	for (int i = 0;i < l;i++) {
		for (int j = 0;j < m;j++)
			cin >> n[i][j];
	}
	cout << endl << "Matrix are : " << endl;
	for (int i = 0;i < l;i++) {
		for (int j = 0;j < m;j++)
			cout<< n[i][j]<<"  ";
		cout << endl;
	}
	if (Mirror_TwoD(n, m, l))
		cout << endl << "Given matrix is Mirror_TwoD Marix ";
	else
		cout << endl << "Given matrix is not Mirror_TwoD Marix ";

	return 0;
}
