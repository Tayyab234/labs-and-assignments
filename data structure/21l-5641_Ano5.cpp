#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ofstream out("proseq");
ofstream ou("config");
template <class T>
class heapADT {
	T* arr;
	int count;
	int size;
 public:
	heapADT() {
		arr = new T[50];
		count = 0;
		size = 50;
	}
	heapADT(int s) {
		arr = new T[s];
		count = 0;
		size = s;
	}
	void insert(T n) {    
		arr[count] = n;
		int h = count;
		while (h > 0) {
			int k = (h - 1) / 2;
			if (arr[k] < arr[h])
				swap(arr[k], arr[h]);
			else
				break;
			h = k;

		}
		count++;
	}
	T get() {
		return arr[0];
	}
	void print() {
		int l = 0;
		while (l < count) {
			cout << arr[l];
			l++;
		}
		cout << endl;
	}
	T  remove() {  
		T h= arr[0];
        if (count > 0) {
		    count--;
			swap(arr[count], arr[0]);
			int n = 0;
			int right = 2;
			int left = 1;
			int l;
			while (left < count) {
				if (right < count) {
					if (arr[left] > arr[right])
						l = left;
					else
						l = right;
				}
				else
					l = left;
				if (arr[l] > arr[n])
					swap(arr[l], arr[n]);
				else
					break;
				n++;
				left = n * 2 + 1;
				right = n * 2 + 2;
			}
		
		}
		return h;
	}
	bool Isempty() {
		if (count == 0)
			return true;
		return false;
	}
	~heapADT() {
		delete[]arr;
	}
};
class program {
public:
	float programAge;
	int programNumber;
	int priority_level;
	bool operator<(program h) {
		if (programAge < h.programAge)
			return true;
		return false;
	}
	bool operator>(program h) {
		if (programAge > h.programAge)
			return true;
		return false;
	}
	friend ostream  &operator <<(ostream& out1,program & c) {
		out1 << "ProgramAge  :  " << c.programAge << "  programNumber : " << c.programNumber << "  priority_level : " << c.priority_level;
		out1 << endl;
		return out1;
	}
};
program getNextprogram(int i) {
	program h;
	float l;
	l = (rand() % 15) + 1.1;
	h.programAge = l;
	h.priority_level = rand() % 3;;
	h.programNumber = i;

	return h;
}
void infile(heapADT<program>&kl, string s) {
	program d;
	ou << endl << s << "  :  " << endl;
	while (kl.Isempty() == false) {
		d = kl.remove();
		ou << "              Program Age = " << d.programAge << "     Program Number = " << d.programNumber << endl;
	}
}
int main() {
	int newval = 0;
	heapADT<int>obj1;
	heapADT<char>obj2;
    obj1.insert(4);
	obj1.insert(1);
	obj1.insert(2);
	obj2.insert('3');
	obj1.insert(5);
	obj1.insert(4);
	for (int i = 0; i < 6; i++)
	{
		newval=obj1.remove();
		cout << newval<<"  ";
	}
	program k;
	heapADT<program>low;
	heapADT<program>mid, high;
	for (int i = 0;i < 6;i++) {//6 times process has been taken
		k = getNextprogram(i);
		if (k.priority_level == 0) {
			out << "LOW :  " << k.programAge << "    " << k.programNumber << endl;
			low.insert(k);
		}
		else if (k.priority_level == 1) {
			out << "MID :  " << k.programAge << "    " << k.programNumber << endl;
			mid.insert(k);
		}
		else {
			out << "HIGH :  " << k.programAge << "    " << k.programNumber << endl;
			high.insert(k);
		}
	}
	cout << endl<<"Low : \n";
	low.print();
	cout << endl << "Mid : \n";
	mid.print();
	cout << endl << "High : \n";
	high.print();

	string s;
	s = "High";
	infile(high, s);
	s = "Mid";
	infile(mid, s);
	s = "Low";
	infile(low, s);
	return 0;

}