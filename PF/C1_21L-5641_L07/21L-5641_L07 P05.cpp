#include<iostream>
using namespace std;
int main() {
	float a[7], ave;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
	ave = (a[0]  + a[3] +  a[6]) / 3;
	if (a[0] >= a[3] && a[0] >= a[6])
		cout << "Maximum :" << a[0] << endl;
	else if (a[3] >= a[0] &&  a[3] >= a[6])
		cout << "Maximum :" << a[3] << endl;
	else {
		if (a[6] >= a[0] && a[6] >= a[3])
			cout << "Maximum :" << a[6] << endl;
	}
	if (a[0] <= a[3] && a[0] <= a[6])
		cout << "Minimum : " << a[0];
	else if ( a[3] <= a[0] && a[3] <= a[6])
		cout << "Minimum : " << a[3];
	else {
		if (a[6] <= a[3] && a[6] <= a[0])
			cout << "Minimum : " << a[6];
	}
	cout << endl << "Average : " << ave;
	return 0;
}