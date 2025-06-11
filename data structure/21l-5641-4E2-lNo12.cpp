#include<iostream>
using namespace std;
class stack {
public:
	int size;
	int cap;
	int* data;
	stack(int s) {
		size = s;
		data = new int[s];
		cap = 0;
	}
	void push(int d) {
		data[cap] = d;
		cap++;
	}
	int pop() {
		if (cap > 0) {
			cap--;
			return data[cap];
		}
	}
	bool kcheck(int n) {
		bool t = false;
		for (int i = 0;i < cap;i++) {
			if (data[i] == n) {
				t = true;
				break;
			}
		}
		return t;
	}
	bool isempty() {
		if (cap == 0)
			return true;
		return false;
	}
};
class node {
public:
	node* next;
	int da;
};
class lldt {
public:
	node* head;
	node* tail;
	lldt() {
		head = tail = 0;
	}
	void insert(int n) {
		node* temp = new node;
		temp->next = 0;
		temp->da = n;
		if (head == 0)
			head = tail = temp;
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	void print() {
		node* temp = head;
		while (temp != 0) {
			cout << temp->da << "   ";
			temp = temp->next;
		}
		cout << endl;
	}
	node* get() {
		return head;
	}

};
class graph {
public:
	lldt obj[5];
	void TakeInput(int n, int d) {
		obj[n].insert(d);
	}
	void Print() {
		for (int i = 0;i < 5;i++) {
			cout << i << " -> ";
			obj[i].print();
		}

	}
	void explore(int h) {
		int j = 0;
		stack ob(5);
		int varr[5];        //visited array
		ob.push(h);
		while (ob.isempty() == false) {
			h = ob.pop();
			varr[j] = h;
			node* temp = obj[h].get();
			j++;
			while (temp != 0) {
				if (ob.kcheck(temp->da) != true) {
					bool u = false;
					for (int i = 0;i < j;i++) {
						if (varr[i] == temp->da)
							u = true;
					}
					if (u == false)
						ob.push(temp->da);
				}
				temp = temp->next;
			}

		}
		for (int i = 0;i < j;i++) {
			cout << varr[i] << "   ";
		}


	}
	~graph() {
		for (int i = 0;i < 5;i++) {
			node* temp = obj[i].get();
			while (temp != 0) {
				node* cur = temp;
				temp = temp->next;
				delete cur;
			}
		}

	}
};
int main() {
	graph g;
	g.TakeInput(0, 1);
	g.TakeInput(0, 2);

	g.TakeInput(1, 2);
	g.TakeInput(2, 0);
	g.TakeInput(2, 3);
	g.TakeInput(3, 4);
	g.TakeInput(4, 0);
	g.TakeInput(4, 3);
	g.Print();
	cout << "\n___________________________________________________________\n";
	g.explore(0);

	return 0;
}