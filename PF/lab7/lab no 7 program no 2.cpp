#include<iostream>
using namespace std;
void rectangle1(int z, int y) {
	int x, h;
		for (x = 1;x <= z;x++) {
			for (h = 1;h <= y;h++)
				cout << "o";
			cout << endl;
		}

}

int main() {
	int l, r;
	cin >> l;
	cin >> r;
	if (l> 0 && r> 0) 
       rectangle1(l, r);
	else
	   cout << "rectangle printing is not possible" << endl;

}