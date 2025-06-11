#include<iostream>
#include<fstream>
using namespace std;
template <class T>
class stackADT {
	T* arr;
	int index, size;
public:
	stackADT() {
		arr = new T[40];
		index = 0;
		size = 40;
	}
	stackADT(int s) {
		arr = new T[s];
		index = 0;
		size = s;
	}
	bool push(T a) {
		if (index < size) {
			arr[index] = a;
			index++;
			return true;
		}
		else
			return false;
	}
	bool top(T& val) {
		if (index < size) {
			val = arr[index - 1];
			return true;
		}
		return false;
	}
	int tsize() {
		return index;
	}
	void  pop() {
		gettopelement();
	}
	bool isempty() {
		if (index == 0)
			return true;
		else
			return false;

	}
	bool isfull() {
		if (index == size)
			return true;
		else
			return false;

	}
	T gettopelement() {
		if (index < size) {
			index--;
			return arr[index];
		}
	}
};
bool isbalanced(char*& exp, const int& size) {
	stackADT<char>k;
	char h;
	for (int i = 0;i < size;i++) {
		if (exp[i] == 40 || exp[i] == 91 || exp[i] == 123)
			k.push(exp[i]);
		else {
			h = k.gettopelement();
			if (h == 40 && exp[i] != 41)
				return false;
			else if (h == 91 && exp[i] != 93)
				return false;
			else if (h == 123 && exp[i] != 125)
				return false;
		}
    }
  return true;
}
void infix2postfix(char exp[]) {
	cout << endl;
	int i = 0;
	int c = 0;
	char f;
	stackADT<char>k;
	char* h = new char[30];
	int j = 0;
	while (exp[j] != '0') {
		if (exp[j] >= 65 && exp[j] <= 90 || exp[j] >= 97 && exp[j] <= 122) {
			h[i] = exp[j];
			i++;
		}
		else if (exp[j] == 42 || exp[j] == 43 || exp[j] == 45 || exp[j] == 47) {
			if (exp[j] == 45 || exp[j] == 43) {//+ -
				do {
					k.top(f);
					c = 0;
					if (f == 43 || f == 45 || f == 47 || f == 42) {
						h[i] = k.gettopelement();
						i++;
						c = 1;
					}

				} while (c != 0);
				k.push(exp[j]);
			}
			else if (exp[j] == 42 || exp[j] == 47) {//*
				do {
					k.top(f);
					c = 0;
					if (f == 47 || f == 42) {
						h[i] = k.gettopelement();
						i++;
						c = 1;
					}
				} while (c != 0);
				k.push(exp[j]);
			}
		}
		else if (exp[j] == 41) {
			char c = k.top(c);
			while (c != 40) {
				c = k.gettopelement();
				if (c == 42 || c == 43 || c == 45 || c == 47) {
					h[i] = c;
					i++;
				}
			}
		}
		else {
			k.push(exp[j]);
		}
		j++;
	}
	while (k.isempty() == false) {
		char m = k.gettopelement();
		if (m == 42 || m == 43 || m == 45 || m == 47) {
			h[i] = m;
			i++;
		}

	}
	for (int j = 0;j < i;j++) {
		cout << h[j];
	}
}
int main() {
	char* a;
	int size = 12;
	a = new char[12];
	a[0] = '{';
	a[1] = '[';
	a[2] = ')';
	a[3] = ']';
	a[4] = '}';
//	a[5] = ')';
//	a[6] = ']';
//	a[7] = '}';
	if (isbalanced(a, 5))
		cout << "Given parenthises is balanced";
	else
		cout << "Given parenthises is not balanced";

	char exp[30] = "(AX*(BX*(((CY+AY)+BY)*CX)))0";
	 infix2postfix(exp);
	
	return 0;
}