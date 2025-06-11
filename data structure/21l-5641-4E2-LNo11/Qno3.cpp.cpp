#include<iostream>
using namespace std;
class heap1 {
	int* arr;
	int cap;
public:
	heap1() {
		arr = new int[9];
		cap = 0;
	}
	void insertion(int n) {
		arr[cap] = n;
		int h = cap;
		while (h  > 0) {
			int k = (h -1) / 2;
			if (arr[k] < arr[h])
				swap(arr[k], arr[h]);
			else
				break;
			h = k;
			
		}
		cap++;
	}
	void print() {
		cout << "\nmax heap : ";
		int l = 0;
		while (l < cap) {
			cout << arr[l] << "   ";
			l++;
		}
		cout << endl;
	}
	void extractmax() {
		int h = 0;
		cout << "\n " << arr[h] << " is extract " << endl;
		delete1(arr[h]);

	}
	int  getmax() {
		if(cap!=0)
		  return arr[0];
	}
	bool delete1(int val) {
		int h = 0;
		while (h < cap) {
			if (arr[h] == val)
				break;
			h++;
		}
		if (h == cap)
			return false;
		else {
			arr[h] = 0;
			int j = h + 1;
			while (j < cap) {
				arr[h] = arr[j];
				h++;
				j++;
			}
			cap--;
			h = 0;
			while (h < cap) {
				int k = (h - 1) / 2;
				if (k >=0) {
					if (arr[h] > arr[k])
						swap(arr[h], arr[k]);
				}
				h++;
			}
		
			return true;
		}
	}
};
int main() {
	heap1  obj;
	obj.insertion(8);
	obj.insertion(12);
	obj.insertion(5);
	obj.insertion(4);
	obj.insertion(9);
	obj.insertion(15);
	obj.print();
	cout << "\nmax value is : "<<obj.getmax();
	obj.extractmax();
	obj.print();
	int n;
	cout << "\nEnter value which you want to delete :  ";
	cin >> n;
	obj.delete1(n);
	cout << "\n After delete : ";
	obj.print();

	return 0;
}