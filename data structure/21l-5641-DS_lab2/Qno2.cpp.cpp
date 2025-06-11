#include<iostream>
using namespace std;
class pattren {
	int a, b;
public:
	void menu() {
		b = 0;
		do {
			cout << "1.triangle\n";
			cout << "2.rectangle\n";
			cin >> b;
		} while (b != 1 && b != 2);
		if (b == 1) {
			cout << "\nPlease enter total no of rows : ";
			cin >> a;
			if (a >= 2) 
			triangle(0);
		}
		else {
			cout << "\nPlease enter total no of rows : ";
			cin >> a;
			if (a >= 2) 
			rectangle(a);
		}
	}
	void triangle1(int h,int o,int p) {//helping recursive function of equiliteral triangle 
		//initially h= row no  o=0  p=0
		int k = 1 + (h * 2); //arithmetic formula a+(n-1)d help to find no of stars print per row
		if (o < a - 1) {  //manage no of spaces of equilitral traingle by recursive way
			cout << " ";
			o++;
			triangle1(h, o, p);
		}
		else if (p < k) {  //manage no of * of equilitral traingle by recursive way
			cout << "*";
			p++;
			triangle1(h, o, p);
		}
	}
	void rectangle1(int h, int k) { //helping recursive function of rectangle
		if (k < h) {//print no of * per row
			cout << "*";
			k++;
			rectangle1(h, k);
		}
	}
	void triangle(int h) {//recursive funtion of triangle
		if (a > 0) {           //manage no of rows
			triangle1(h,0,0);
			cout << endl;
			a--;
			triangle(h+1);
		}
	}
	void rectangle(int k) {// recursive funtion of rectangle
		if (a > 0) { //manage no of rows
			rectangle1(k+ 1,0);
			cout << endl;
			a--;
			rectangle(k);
		}
	}

};
int main() {
	pattren k;
	k.menu();
	return 0;
}