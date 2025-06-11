#include <iostream>
using namespace std;
int joking(int n) {
	int sum = 10, r;
	while(sum>=10) {
		if (n == 0)
			n = sum;
                sum=0;
		while (n != 0) {
			
			r = n % 10;
			sum = sum + r;
			n = n / 10;
		}

	}
	return sum;
		                                                                                                                                                                                                                                                                                                                                                                                           
   
}
int main() {
	int n;
	cin >> n;
	cout << joking(n) << endl;
	int d;
	cin >> d;
}