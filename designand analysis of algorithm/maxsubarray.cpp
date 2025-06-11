#include<iostream>
using namespace std;
int maxsubarray(int left, int right, int* arr, int sum) {
	if (left >= right)
		return arr[right];
	int m = (left + right) / 2;
	int value1 = maxsubarray(left, m, arr, sum);
	int value2= maxsubarray(m+1,right, arr, sum);
	if (sum > sum + value1 && sum > sum + value1 + value2)
			return sum;
	else if (value1 > sum + value1 && value1 > sum + value1 + value2)
		return value1;
	else if (value2 > sum + value1 && value1 > sum + value1 + value2)
		return sum;
    else if (sum < sum + value1 + value2)
			return sum + value1 + value2;
    else if (sum + value1 > sum)
			return sum + value1;
    else 
			return sum + value2;
}
int main() {
	int* arr = new int[9];
	arr[0] = 3;
	arr[1] = -9;
	arr[2] = -1;
	arr[3] = -4;
	arr[4] = -8;
	arr[5] = 7;
	arr[6] = -6;
	arr[7] = -12;
	arr[8] = -15;
	arr[9] = 13;
	int sum = 0;
	int k=maxsubarray(0, 9, arr, sum);
	cout << "The maximum sum of sub array is : " << k;
}