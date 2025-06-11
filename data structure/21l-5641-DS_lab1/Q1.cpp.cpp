#include<iostream>
using namespace std;
class myvector {
	int* arr;
	int size,cap;
public:
	myvector() {//dafault constructor
		arr = new int[2];
		cap = 2;
		size = 0;
	}
	myvector(int n) {//parameterized constructor
		arr = new int[n];
		cap = n;
		size = 0;
		for (int i = 0;i < n;i++)//initialize whole array to zero
			arr[i] = 0;
	}
	myvector(myvector &h) {//copy constructor  deep copy
		size = h.size;
		cap = h.cap;
		arr = new int[cap];
		for (int i = 0;i < size;i++)
			arr[i] = h.arr[i];
	}
	~myvector() {//destructor
		delete[]arr;//deallocation dynamic array
	}
	int getcap1() {//return capacity of array
		return cap;
	}
	void operator+(int da) {//add element in array and increase current size
		if (size < cap) {
			arr[size] = da;
			size++;
		}
		else {
			int* ar = new int[cap * 2];
			for (int i = 0;i < size;i++)
				ar[i] = arr[i];
			delete[]arr;
			arr = ar;
			arr[size] = da;
			size++;
			cap = cap * 2;
		}
	}
	void sortelement() { //insertion sort tecnique
		int temp;
		for (int i = 0;i < size;i++) {
			temp = 0;
			for (int j = 0;j < i;j++) {
				if (arr[j] > arr[i]) {
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}
    int searchelement(int n) {//binary search technique
		int low = 0;
		int high = size - 1;
		int mid;
		while (low != high) {
			mid = (low + high) / 2;
			if (arr[mid] == n)
				return mid;
			else if (arr[mid] > n)
				high = mid - 1;
			else
				low = mid + 1;
        }
		return -1;
	}
	void deletefirstelement() {    //delete first element of array
		for (int i = 0;i < size;i++) {
			if (i + 1 < size)
				arr[i] = arr[i + 1];
			else {
				arr[i] = NULL;
				size--;
			}
		}
	}
	void shuffle(int a,int b) {
		if (a < size && b < size) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
	}
	void operator-(int n){//delete the last element of array and decrese size
		arr[size - 1] = NULL;
		size--;
	}
	friend void operator >>(istream& in,myvector &k) {//input operator of array
		if (k.size < k.cap) {
			in >> k.arr[k.size];
			k.size++;
		}
		else {
			int* ar = new int[k.cap * 2];
			for (int i = 0;i < k.size;i++)
				ar[i] = k.arr[i];
			delete[]k.arr;
			k.arr = ar;
			in>>k.arr[k.size];
			k.size++;
			k.cap = k.cap * 2;
		}
	}
	friend void operator<<(ostream& out, myvector& j) {
		cout << "\n________________________________________________________\nelements of array are :   ";
		for (int i = 0;i < j.size;i++) {
			out << j.arr[i] << "    ";
		}
		cout <<  "\n________________________________________________________\n";
	}

};
int main() {
	int k, l;
	myvector h;
	//elements insertion
	h + 7;
	h + 6;
	h + 1;
	h + 2;
	h + 12;
	h + 11;
	h + 4;
	cout << h;
	cout << "Capacity of array is : "<< h.getcap1();
	cout<< "\n________________________________________________________\n";
	cout << "       After insertion sorting ";
	h.sortelement();
	cout << h;
	cout << "         After delete fisrt element  ";
	h.deletefirstelement();
	cout << h;
	cout << "         After delete last element ";
	h-1;
	cout << h;
	cout << "\n Please enter element you want to search in array : ";
	cin >> k;
	l = h.searchelement(k);
	if (l != -1) {
		cout << "\nGiven element you enter is present in array at index " << l;
	}
	else
		cout << "\nGiven element you enter is not present in array  ";
	cout << "\n________________________________________________________\n";
	cout << "\nPlease enter two indexes to swap their elements of array : ";
	cin >> k >> l;
	h.shuffle(k,l);
	cout << h;
	cout << "\n Please enter element you want to search in array : ";
	cin >> k;
	l = h.searchelement(k);
	if (l!=-1) {
		cout << "\nGiven element you enter is present in array at index "<<l;
	}
	else
		cout << "\nGiven element you enter is not present in array  " ;
	cout << "\n\nPlease enter element for insertion in array : ";
	cin >> h;
	cout << "\n           After insertion  ";
	cout << h;
	system("pause");
	return 0;
}