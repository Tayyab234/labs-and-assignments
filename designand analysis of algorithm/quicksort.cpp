#include<iostream>
using namespace std;
void exchange(int &l, int &r) {
	int temp = r;
	r = l;
	l = temp;
}
void quicksort(int left,int right,int*arr) {
	if (left >= right)
		return;
	int l = left;
	int r = right;
	int m = (l + r) / 2;
	
	exchange(arr[m], arr[r]);
	r--;
	while (l < r) {
		while (l < r && arr[l] < arr[right])
			l++;
		while (l < r && arr[r] > arr[right])
			r--;
		if (l<r) 
			exchange(arr[l], arr[r]);
	}
	if ( arr[l] > arr[right])
		exchange(arr[l], arr[right]);
	    
    quicksort(left, r - 1,arr);
    quicksort(l + 1, right,arr);
	
}
int findKthsmallest(int*arr, int s, int e, int k) {
	quicksort(s, e, arr);
	k--;//to neglect 0 index
	return arr[k];
}
int main() {
	int* arr = new int[9];
	arr[0] = 3;
	arr[1] = 9;
	arr[2] = 1;
	arr[3] = 0;
	arr[4] = 8;
	arr[5] = 7;
	arr[6] = -6;
	arr[7] = 12;
	arr[8] = -15;
	arr[9] = 13;
	
	cout << "Array is given : ";
	for (int i = 0;i < 9;i++) {
		cout << arr[i] << "   ";
	}
	int k;
	cout << "\nPlease enter the value of K : ";
	cin >> k;
	int h=findKthsmallest(arr, 0, 9, k);

	cout << "The " << k << " Smallest value of array is : " << h;
	return 0;
}