#include<iostream>
using namespace std;
int findnthdigit(int n) {
	int r, h, j, t;
	cin >> h;
	for (r = 0;r <= h;r++) {
		t = n % 10;
		j = t;
		n = n / 10;
	}
	return j;
}
int main() {
	int n;
	cin >> n;
	cout << findnthdigit(n) << endl;
	int y;
	cin >> y;
	return 0;
}