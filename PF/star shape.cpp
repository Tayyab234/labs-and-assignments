#include<iostream>
using namespace std;
int main() {
	int n, t = 1, h = 1,cc=0;
	cin >> n;
	for (int i = 0;i <= n;i++)
		cc = cc + 2;
	cc = cc - 1;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= cc-i;j++)
			cout << " ";
		if (i == 0)
			cout << "*";
		else {
			cout << "*";
			for (int k = 0;k < t;k++)
				cout << "*";
			cout << "*";
			t = t + 2;
		}
		cout << endl;
	}
	int u = 0;
	for (int i = 0;i <= n+3+t+n;i++)
		cout << "*";
	cout << endl;
	for (int k = 0;k < n-1;k++) {
		for (int i = 0;i <= k;i++)
			cout << " ";
		cout << "*";
		for (int j = 1;j <= t + n + n  - u;j++)
			cout << "*";
		cout << "*";
		cout << endl;
		u = u + 2;
	}
	for (int i = 0;i <= n-1;i++)
		cout << " ";
	cout << "*";
	for (int i = 0;i < n+2;i++)
		cout << "*";
	cout << "*";
	for (int i = 0;i < n;i++)
		cout << "*";
	cout << "*" << endl;
	for (int a = 0;a <= n;a++) {
		for (int k = 1;k <= n - a;k++)
			cout << " ";
		cout << "*";
		if (a != n) {
			for (int k = 1;k <= n - a;k++)
				cout << "*";
			cout << "*";
			for (int k = 1;k <= h;k++)
				cout << " ";
			cout << "*";
			h = h + 4;
			for (int k = 1;k <= n - a;k++)
				cout << "*";
			cout << "*";
		}
		else {
			for (int j = 1;j <= t + n + n + 2;j++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
