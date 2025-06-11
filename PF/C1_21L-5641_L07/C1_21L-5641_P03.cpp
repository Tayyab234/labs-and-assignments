#include <iostream>
using namespace std;
int digitSum(int n) {
	int sum = 0, r;
	while (n != 0) {
		r = n % 10;
		cout << r << endl;
		sum = sum + r;
		n = n / 10;

	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	cout << digitSum(n) << endl;
	int d;
	cin >> d;
}