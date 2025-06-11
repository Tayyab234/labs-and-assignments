#include<iostream>
using namespace std;
void swap(int a, int b) {
	int alpha, beta;
	alpha = b;
	beta = a;
	cout << alpha << endl << beta << endl;

}
int main() {
	int a, b;
	cin >> a >> b;
	swap(a, b);
	int r;
	cin >> r;
}