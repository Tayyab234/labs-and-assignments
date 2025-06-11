#include<iostream>
using namespace std;
int sum_digit(int dig) {
	int sum=0;
	if (dig % 10 > 0) {
		sum = dig % 10;
		return sum + sum_digit(dig /10);
	}
	else
		return dig;
}
void recursum(int a) {
	if (a >= 10) {
		cout << "\nThe sum_digit  " << a << "  is : ";
		a = sum_digit(a);
		cout << a;
		recursum(a);
	}
}
int main() {
	
	int a;
	cout << "\nEnter the digit : ";
	cin >> a;
	recursum(a);
}