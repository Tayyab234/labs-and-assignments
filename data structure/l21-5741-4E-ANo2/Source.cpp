#include<iostream>
#include<fstream>
using namespace std;
ofstream out("proseq");
ofstream ou("config");
template <class T>
class queueADT {
	T* arr;
	int index, size;
public:
	queueADT() {
		arr = new T[10];
		index = 0;
		size = 10;
	}
	queueADT(int s) {
		arr = new T[s];
		index = 0;
		size = s;
	}
	bool Enque(T a) {
		if (index < size) {
			arr[index] = a;
			index++;
			return true;
		}
		return false;
	}
	bool Deque(T& val) {
		if (index > 0) {
			val = arr[0];
			index--;
			for (int i = 0;i < index;i++) {
				arr[i] = arr[i + 1];
			}
			return true;
		}
		return false;
	}
	bool IsEmpty() {
		if (index == 0)
			return true;
		else
			return false;

	}
	bool IsFull() {
		if (index == size)
			return true;
		else
			return false;

	}
	T view() {
		if (index != 0) {//view top element of queue
			return arr[0];
		}
	}
};
class program {
public:
	float programAge;
	int programNumber;
	int priority_level;
};
program getNextprogram(int i) {
	program h;
	float l;
	l = (rand() % 15)+1.1;
	h.programAge = l;
	h.priority_level = rand() % 3;;
	h.programNumber = i;

	return h;
}
void checkperiorty(queueADT<program>&kl,program d) {
	queueADT<program>cl;
	program h;
	program c;
	h= kl.view();
	if (h.programAge < d.programAge && kl.IsEmpty() == false) {
		kl.Deque(h);
		while (kl.IsEmpty() == false) {
			kl.Deque(c);
			cl.Enque(c);
		}
		kl.Enque(d);
		kl.Enque(h);
		while (cl.IsEmpty() == false) {
			cl.Deque(c);
			kl.Enque(c);
		}
	}
	else
		kl.Enque(d);
}
void infile(queueADT<program>kl,string s) {
	program d;
	ou << endl<<s << "  :  "<<endl;
	while (kl.IsEmpty() == false) {
		kl.Deque(d);
		ou << "              Program Age = " << d.programAge << "     Program Number = " << d.programNumber<<endl;
	}
}
int main() {
	/*int newval = 0;
	queueADT<int>obj1;
	queueADT<char>obj2;
	cout << obj1.Enque(newval);
	obj1.Enque(1);
	obj1.Enque(2);
	obj2.Enque('3');
	obj1.Enque(5);
	if (!obj1.IsFull())
		obj1.Enque(4);
	for (int i = 0; i < 6; i++)
	{
		obj1.Deque(newval);
		cout << newval;
	}*/
	program k;
	queueADT<program>low;
	queueADT<program>mid,high;
	for (int i = 0;i < 6;i++) {//6 times process has been taken
		k = getNextprogram(i);
		if (k.priority_level == 0) {
			out <<"LOW :  "<< k.programAge << "    " << k.programNumber << endl;
			checkperiorty(low, k);
		}
		else if (k.priority_level == 1) {
			out << "MID :  " << k.programAge << "    " << k.programNumber << endl;
			checkperiorty(mid, k);
		}
		else {
			out << "HIGH :  " << k.programAge << "    " << k.programNumber << endl;
			checkperiorty(high, k);
		}
	}
	string s;
	s = "High";
	infile(high, s);
	s = "Mid";
	infile(mid, s);
	s = "Low";
	infile(low, s);
	return 0;

}