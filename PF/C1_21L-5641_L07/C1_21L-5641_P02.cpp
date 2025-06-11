#include<iostream>
using namespace std;
bool isPrime(int n) {
	int j=0, k;
	for (k = 1;k <= n ;k++) {
		if (n % k == 0)
			j = j + 1;
	}
	if (j == 2)
		return true;
	else
		return false;

}
int main() {
	int n;
	cin >> n;
	if (isPrime(n)) {
		cout << "Yes it is Prime" << endl;
	}
	else {
		cout << "No it is not Prime" << endl;
	}
	int r;
	cin >> r;
	return 0;
}