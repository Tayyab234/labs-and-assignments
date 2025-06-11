#include<iostream>
using namespace std;
void specialsquare(int x) {
	int y, z, h;
	for (y = 1;y <= x;y++) {
		for (z = 1;z <= y;z++)
			cout << "O";
		for (h = 1;h <= x - y;h++)
			cout << "C";
		cout << endl;
	}
}
int main() {
	int x;
	cin >> x;
	specialsquare(x);
}