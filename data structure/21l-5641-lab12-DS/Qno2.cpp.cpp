#include<iostream>
using namespace std;
class heap1 {
	int* arr;
	int cap;
public:
	heap1() {
		arr = new int[15];
		cap = 0;
	}
	void insertionmax(int n) {    //insertion for max heap
		arr[cap] = n;
		int h = cap;
		while (h > 0) {
			int k = (h - 1) / 2;
			if (arr[k] < arr[h])
				swap(arr[k], arr[h]);
			else
				break;
			h = k;

		}
		cap++;
	}
	void insertionmin(int n) {//insertion for min heap
		arr[cap] = n;
		int h = cap;
		while (h > 0) {
			int k = (h - 1) / 2;
			if (arr[k] > arr[h])
				swap(arr[k], arr[h]);
			else
				break;
			h = k;

		}
		cap++;
	}
	void print() {
		int l = 0;
		while (l < cap) {
			cout << arr[l] << "   ";
			l++;
		}
		cout << endl;
	}
	int  Get() {
		if (cap != 0)
			return arr[0];
	}
	int  delete1() {  //deletion for max heap
		int h = 0;

		if (cap > 0) {
			h = arr[0];
			cap--;
			swap(arr[cap], arr[0]);
			int n = 0;
			int right = 2;
			int left = 1;
			int l;
			while (left < cap) {
				if (right < cap) {
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
	bool search(int n) {
		int h = 0;
		while (h < cap) {
			if (n == arr[h])
				return true;
			h++;
		}
		return false;
	}
	int  delete2() {//deletion for min heap
		int h = 0;

		if (cap > 0) {
			h = arr[0];
			cap--;
			swap(arr[cap], arr[0]);
			int n = 0;
			int right = 2;
			int left = 1;
			int l;
			while (left < cap) {
				if (right < cap) {
					if (arr[left] < arr[right])
						l = left;
					else
						l = right;
				}
				else
					l = left;
				if (arr[l] < arr[n])
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
};
int main() {
	heap1  obj;
	heap1 obj1;
	int* arr;
	int n;
	cout << "\nPlease enter the size of array : ";
	cin >> n;
	arr = new int[n];
	cout << "\nEnter values of array : \n";
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		obj.insertionmin(arr[i]);
		obj1.insertionmax(arr[i]);
	}
	cout << "\nMax Heap : ";
	obj1.print();
	cout << "\nMin Heap : ";
	obj.print();

	//__________________sortion of min heap_________________________
	for (int i = 0;i < n;i++) {
		int k = obj.delete2();
		arr[i] = k;
	}
	//___________________________________________________________
	//___________________________sortion of max heap________________
	int h = n;
	h--;
	while(h>=0) {
		int k = obj1.delete1();
		arr[h] = k;
		h--;
	}

	//_________________________________________________
	cout << "\nAfter heap sorting of min heap array is : ";
	for (int i = 0;i < n;i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n\n";

	return 0;
}