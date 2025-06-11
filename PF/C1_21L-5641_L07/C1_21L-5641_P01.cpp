#include<iostream>
#include<string>
using namespace std;
string isEven(int number) {
	string s1, s2;
	s1 = "True";
	s2 = "False";
	if (number % 2 == 0)
		return s1;
	else
		return s2;

}
int main() {
	int n;
	cin >> n;
	cout << isEven(n) << endl;
	return 0;
}