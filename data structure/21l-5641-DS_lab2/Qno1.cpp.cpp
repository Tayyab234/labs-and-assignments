#include<iostream>
using namespace std;
class cube {
	int* arr;
	int i;
public:
	cube() {
		arr = new int[27]; 
		for (int j = 0;j < 27;j++) {//initialize elements by zero
			arr[j] = 0; 
		}
		i = 0;//work as a 3-d index 
	}
	cube(cube* h) {    //copy constructor
		i = h->i;
		arr = new int[i];
		for (int j = 0;j < i;j++) {
			arr[j] = h->arr[j];
		}
	}
	void set1(int l, int p, int o, int num) {
		i = l * 3 * 3 + p * 3 + o;  //find index in 1 d array
		arr[i] = num;
	}
	int get1(int l, int p, int o) {
		i= l * 3 * 3 + p * 3 + o;//find index in 1 d array
		return arr[i];
	}
	void linear() {//print element of array in linear form
		cout << "In linear form : ";
		for (int i = 0;i < 27;i++) {
			cout << arr[i] << "  ";
		}
	}
	void print() {//print element of array in dimentions
		cout << "\narray 1 dimention is :\n ";
		int index = 0;
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				cout << arr[index] << " ";   //print element in linear form
				index = index + 1;
			}
			cout << endl;
		}
		cout << "\narray 2 dimention is : \n";
		index = 9;
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				cout << arr[index] << " ";   //print element in linear form
				index = index + 1;
			}
			cout << endl;
		}
		cout << "\narray 3 dimention is : \n";
		index = 18;
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				cout << arr[index] << " ";   //print element in linear form
				index = index + 1;
			}
			cout << endl;
		}
	}
	void transpose1() {
		int c;//manage column index
		int r;//manage row index
		int temp;//help inswap row and column number in transpose
		int ar[9];
		for (int k = 0;k < 9;k++)
			ar[k] = k;
		for (int j = 0;j < 3;j++) {
			c = j;
			for (int k = 0;k < 3;k++) {
				r = (j*3)+k;
				if (ar[c] < ar[r]) {
					temp = arr[c];
					arr[c] = arr[r];
					arr[r] = temp;
					//ar is use to check if swap is allowed or not
					temp = ar[c];
					ar[c] = ar[r];
					ar[r] = temp;
				}
				c = c + 3;
			}
		}
	}
	void rotatetop() {
		transpose1();
	}
	bool searchelement(int n) {//search element from array
		for (int j = 0;j < 27;j++) {
			if (arr[j] == n)
				return true;
		}
		return false;
	}
	void delelement(int n) {//delete element from array
		for (int j = 0;j < 27;j++) {
			if (arr[j] == n) {
				arr[j] = 0;
				break;
			}
		}
	}
};
int main() {
	cube a;
	//element are enter in 3d array style
	a.set1(0, 1, 1, 1);
	a.set1(0, 2, 0, 7);
	a.set1(0, 0, 2, 9);
	a.set1(0, 2, 2, 12);
	a.set1(0, 0, 0, 17);
	a.set1(0, 1, 2, 20);
	a.set1(1, 0, 0, 10);
	a.set1(2, 0, 0, 6);
	a.set1(0, 2, 0, 1);
	a.set1(1, 2, 0, 2);
	a.set1(2, 2, 0, 3);
	cout << "\n____________________________________________________________\n";
	a.linear();
	cout << "\n____________________________________________________________\n";
	a.print();
	cout << "\n____________________________________________________________\n";
	int p;
	cout << "\n enter the element which you want to search in 3-D array : ";
	cin >> p;
	if (a.searchelement(p) == true) {
		cout << "\nSearch element is available in array ";
	}
	else
		cout << "\nSearch element is not available in array ";
	cout << "\n____________________________________________________________\n";
	cout << "\n enter the element which you want to delete in 3-D array : ";
	cin >> p;
	a.delelement(p);
	cout << "\nAfter delete elemnt : ";
	a.print();
	cout << "\n____________________________________________________________\n";
	cout << "\nAfter rotatetop : ";
	a.rotatetop();
	a.print();
	cout << "\n____________________________________________________________\n";
	return 0;
}