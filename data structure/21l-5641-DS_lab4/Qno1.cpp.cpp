#include<iostream>
using namespace std;
template <class T>
class linklist1 {
public:
	struct node {
		T data;
		node* next;
	};
	node* head;
	node* tail;
	linklist1() {
		head = tail = 0;
	}
	void insert(T val) {
		node* temp = new node;
		temp->next = 0;
		temp->data = val;

		if (head == 0)
			tail = head = temp;
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	bool del1(int val) {
		node* prev = 0;
		node* temp = head;
		while (temp != 0) {
			if (temp->data == val)
				break;
			prev = temp;
			temp = temp->next;
		}
		if (temp == 0)
			return false;
		else {
			if (temp == head) {
				head = head->next;
				delete[]temp;
			}
			else if (temp == tail) {
				tail = prev;
				delete[]temp;
			}
			else {
				prev->next = temp->next;
				delete[]temp;
			}
		}
	}

	void printlink() {
		node* temp = head;
		cout << "\nLinkedlist :  ";
		while (temp != 0) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	~linklist1() {
		delete[]head;
		delete[]tail;
	}
	void reverce1(linklist1& a) {
		node* h = a.tail;
		while (h != a.head) {
			node* k = a.head;
			while (k->next != h) {
				k = k->next;
			}
			h->next = k;
			h = k;
		}
		a.head = a.tail;
		a.tail = h;
		a.tail->next = 0;
	}
	int ssize() {
		node* temp = head;
		int i = 0;
		while (temp != 0) {
			i++;
			temp = temp->next;
		}
		return i;
	}
	bool ispallindrom() {
		node* temp = head;
		int h = ssize();
		if (h % 2 != 0)
			return false;
		else {
			node* temp1 = head;
			h = h / 2;
			while (h > 0) {
				temp1 = temp1->next;
				h--;
			}
			node* k = temp1;
			while (temp1 != 0) {
				while (temp->next != k)
					temp = temp->next;
				if (temp1->data != temp->data)
					return false;
				temp1 = temp1->next;
				k = temp;
				temp = head;
			}
		}
		return true;
	}
	void recoderlinklist() {
		node* temp, * cur, * pr;
		node* h = 0;
		pr = head;
		int c = ssize();
		int i = c;
		int k = i;
		c = c / 2;
		while (c > 0) {
			temp = tail;
			cur = pr->next;
			pr->next = temp;
			temp->next = cur;
			pr = cur;
			h = head;
			while (i > 1) {
				i--;
				h = h->next;
			}
			cout << endl;
			tail = h;
			tail->next = 0;
			i = k;
			c--;
		}
	}
	void swapnodes(int n) {
		int i = ssize();
		i = i - n;
		node* r1 = head;
		node* r2 = head;
		node* tem1, * tem2;
		node* prev1 = 0, * prev2 = 0;
		while (n > 0) {
			prev1 = r1;
			r1 = r1->next;
			n--;
		}
		tem1 = r1->next;
		while (i > 1) {
			prev2 = r2;
			r2 = r2->next;
			i--;
		}
		tem2 = r2->next;

		prev1->next = r2;
		r2->next = tem1;
		prev2->next = r1;
		r1->next = tem2;
	}
};
int main() {
	int h;
	linklist1<int>k;
	linklist1<int>j;
	k.insert(1);
	k.insert(2);
	k.insert(3);
	k.insert(4);
	k.insert(5);
	k.insert(6);


	j.insert(1);
	j.insert(2);
	j.insert(2);
	j.insert(1);
	k.printlink();
	cout << "Enter element which you want to delete : ";
	cin >> h;
	k.del1(h);
	k.printlink();

	cout << "\n After reverse \n";
	k.reverce1(k);
	k.printlink();
	if (k.ispallindrom() == true)
		cout << "\nGiven linkedlist is pallindrom\n";
	else
		cout << "\nGiven linkedlist is not pallindrom\n";
	j.printlink();
	if (j.ispallindrom() == true)
		cout << "\nGiven linkedlist is pallindrom\n";
	else
		cout << "\nGiven linkedlist is not pallindrom\n";
	cout << "\n After recoderlist \n";
	k.recoderlinklist();
	k.printlink();

	k.printlink();
	cout << "\nPlease enter  swap number : ";
	cin >> h;
	k.swapnodes(h);
	cout << "\n after swapping : ";
	k.printlink();
	system("pause");
}