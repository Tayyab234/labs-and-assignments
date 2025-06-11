#include<iostream>
using namespace std;
void palindomicstriangle(int x) {
	int y, z, h;
	cin >> x;
	for (y = 1;y <= x;y++) {
		for (z = 1;z <= y;z++)
			cout << z;
		for (h = 1;h <= y - 1;h++)
			cout << h;
		cout << endl;
	}
}
int main() {
	int x;
	cin >> x;
	palindomicstriangle(x); 

}