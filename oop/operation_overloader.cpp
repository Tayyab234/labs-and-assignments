#include<iostream>
#include<Windows.h>
using namespace std;
class Polynomial
{
private:
	int totalterms;
	int* coeff;
	int* exp;
public:
	Polynomial(int s = 0) {
		totalterms = s;
		coeff = new int[s];
		exp = new int[s];
	}
	void input() {
		for (int i = 0; i < totalterms; i++) {
			cout << "\n Enter " << i + 1 << " coefficients : ";
			cin >> coeff[i];
		}
		for (int i = 0; i < totalterms; i++) {
			cout << "\n Enter " << i + 1 << " exponents : ";
			cin >> exp[i];
		}
	}
	Polynomial operator-(Polynomial& s) {
		Polynomial r;
		for (int i = 0; i < totalterms; i++) {
			r.coeff[i] = this->coeff[i] - s.coeff[i];
			cout<<r.coeff[i]<<"  ";
			r.exp[i] = this->exp[i]-s.exp[i];
			cout<<r.exp[i]<<endl;
		}
		return r;
	}
	void output() {
		cout << "\nPolynomial expression is : p(x)=  ";
		for (int i = 0; i < totalterms; i++) {
			cout << coeff[i] << "x^" << exp[i];
			if (i != totalterms - 1)
				cout << " + ";
		}

	}
	void operator+=(Polynomial& y) {
		for (int i = 0; i < totalterms; i++) {
			this->coeff[i] = this->coeff[i] + y.coeff[i];
		}
	}
};
int main() {
	int j;
	cout << "enter the total number of terms :  ";
	cin >> j;
	Polynomial s(j),k(j),u(j),y(j);
	s.input();
	k.input();
	u.input();
	y = k- s;
	u += y;
	u.output();
	s.output();
	y.output();
	Sleep(-1);
	return 0;
	
}

