#include<iostream>
#include<fstream>
using namespace std;
template <class T>
class stackADT {
	T* arr;
	int index, size;
public:
	stackADT() {
		arr = new T[10];
		index = 0;
		size = 10;
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
	bool  pop(T&value) {
		if (index > 0) {
			index--;
			value = arr[index];
			return true;
		}
		else
			return false;
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
};
struct coordinate {
	int x, y;
};
char** file(int&r,int&c) {
	ifstream in("maze.txt");
	in >> r >> c;
	char** h;
	h = new char* [r];
	for (int i = 0;i < r;i++)
		h[i] = new char[c];
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			in >> h[i][j];
		}
	}
	return h;
}
void penter(stackADT<coordinate>&stack1, coordinate &k,int p,int l) {
	k.x= p;
	k.y = l;
	stack1.push(k);
}
bool mazesolution(char** ma, int r, int c,int p,int l) {
	stackADT<coordinate>stack1;
	coordinate k;
	int**arr;
	int u = p, v = l;
	k.x = p;
	k.y = l;
	stack1.push(k);
	arr = new int* [r];
	for (int i = 0;i < r;i++)
		arr[i] = new int[c];
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			arr[i][j] = 0;
	}
	arr[p][l] = 1;
	while (stack1.isempty()==false) {
		stack1.pop(k);
		p = k.x;
		l = k.y;
		if (p + 1 < r) {
			if (ma[p + 1][l] == 45&&arr[p+1][l]==0) {
				arr[p + 1][l] = 1;
				penter(stack1, k, p+1, l);
			}
		}
		if (p -1 >= 0) {
			if (ma[p - 1][l] == 45 && arr[p - 1][l] == 0) {
				arr[p - 1][l] = 1;
				penter(stack1, k, p-1, l);
			}
		}
		if (l - 1 >= 0) {
			if (ma[p ][l-1] == 45 && arr[p ][l-1] == 0) {
				arr[p ][l-1] = 1;
				penter(stack1, k, p, l-1);
			}
		}
		if (l +1 < c) {
			if (ma[p][l + 1] == 45 && arr[p][l +1] == 0) {
				arr[p][l + 1] = 1;
				penter(stack1, k, p, l + 1);
			}
		}
		cout << p << " " << l << " ";
		if (p != u||l!=v) {
			if (p == 0)
				return true;
			else if (p == r)
				return true;
			if (l == 0)
				return true;
			else if (l == r)
				return true;
		}
	}
	return false;
}
int main() {
	/*int newval;
	stackADT<int> obj1;
	stackADT<char> obj2;
	cout<<obj1.pop(newval);
	obj1.push(1);
	obj1.push(2);
	obj2.push('3');
	obj1.push(5);
	if (!obj1.isfull())
		obj1.push(4);
	for (int i = 0; i<6; i++)
	{
		obj1.pop(newval);
		cout<<newval<<"   ";
	}*/
	char** maze;
	int count = 0;
	int r, c;
	maze=file(r, c);
	//maze opening
	for (int i = 0;i < c;i++) {
		if (maze[r-1][i] == 45) {
			if (mazesolution(maze, r,c,r-1, i) == true) {
				cout << "\nthere is way out";
				break;
			}
			else {
				cout << "\nthere is not way out";
				break;
			}
		}
	
	}
	for (int i = 0;i < r;i++) {
		if (maze[i][0] == 45) {
			if (mazesolution(maze, r, c, i, 0) == true) {
				cout << "\nthere is way out";
				break;
			}
			else {
				cout << "\nthere is not way out";
				break;
			}
		}
		else if (maze[i][c-1] == 45) {
			if (mazesolution(maze, r, c, i, c-1) == true) {
				cout << "\nthere is way out";
				break;
			}
			else {
				cout << "\nthere is not way out";
				break;
			}
		}
	}
	return 0;
}