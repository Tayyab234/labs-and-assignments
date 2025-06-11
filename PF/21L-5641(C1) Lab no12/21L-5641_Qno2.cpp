#include<iostream>
using namespace std;
bool isAutomorphic(int n) {
	int h, r, k = 0,l=1,j;
	h = n * n;
	r = n;
	while (r != 0) {
		r = r / 10;
		k = k + 1;
	}
	for (int i = 0;i < k;i++)
		l = l * 10;
	h = h % l;
	if (h == n)
		return true;
	else
		return false;

}
int main() {
	int n;
	cout << "enter the number : ";
	cin >> n;
	if (isAutomorphic(n))
		cout << "it is an automorphic number";
	else
		cout << "it is not an automorphic number";
}