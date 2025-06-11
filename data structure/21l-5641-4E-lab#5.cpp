#include<iostream>
using namespace std;
template <class T>
class linklist1 {
public:
	struct node {
		T data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
	linklist1() {
		head = tail = 0;
	}
	linklist1(linklist1<T>& h) {//copy constructor
		node* temp = h.head;
		while (temp != 0) {
			insertattail(temp->data);
			temp = temp->next;
		}
	}
	void insertattail(T val) {
		node* temp = new node;
		temp->next = 0;
		temp->prev = 0;
		temp->data = val;

		if (head == 0)
			tail = head = temp;
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
		}
	}
	void insertathead(T val) {
		node* temp = new node;
		temp->data = val;
		temp->prev = 0;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	void delH() {   //delete from head
		node* temp = head->next;
		delete[]head;
		head = temp;
		head->prev = 0;
	}
	void delT() {   //delete from tail
		node* temp = tail->prev;
		delete[]tail;
		tail = temp;
		tail->next = 0;
	}
	void printforeward() {
		node* temp = head;
		cout << "\nPrint foreward Linkedlist :  ";
		while (temp != 0) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	void printreverse() {
		node* temp = tail;
		cout << "\nPrint reversee Linkedlist :  ";
		while (temp != 0) {
			cout << temp->data << "  ";
			temp = temp->prev;
		}
		cout << endl;
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
	int returnmid() {
		int h = ssize();
		h = h / 2;
		node* temp = head;
		while (h > 1) {
			temp = temp->next;
			h--;
		}
		return temp->data;
	}
	bool isempty() {
		if (head == 0)
			return true;
		return false;
	}

	void insertAfter(T val, T key) {
		node* temp = new node;
		temp->next = 0;
		temp->prev = 0;
		temp->data = key;

		node* cur = head;
		while (cur != 0) {
			if (cur->data == val)
				break;
			cur = cur->next;
		}
		if (cur != 0) {
			node* h;
			if (cur->next != 0) {
				h = cur->next;
				h->prev = temp;
			}
			else
				h = 0;
			temp->prev = cur;
			cur->next = temp;
			temp->next = h;
		}
		else {
			if (head == 0)
				head = tail = temp;
			else {
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}

		}

	}
	void insertBefore(T val, T key) {
		node* temp = new node;
		temp->next = 0;
		temp->prev = 0;
		temp->data = key;

		node* cur = head;
		while (cur != 0) {
			if (cur->data == val)
				break;
			cur = cur->next;
		}
		if (cur != 0) {
			if (cur->prev != 0) {
				node* h = cur->prev;
				cur->prev = temp;
				temp->next = cur;
				temp->prev = h;
				h->next = temp;
			}
			else
				insertathead(key);
		}
		else {
			if (head == 0)
				head = tail = temp;
			else {
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}

		}

	}

	int findmax() {
		node* temp = head;
		int h = 0;
		while (temp != 0) {
			if (h < temp->data) {
				h = temp->data;
			}
			temp = temp->next;
		}
		return h;
	}

	void swapnodes(int il, int ir) {
		node* temp = head;
		node* cur = head;

		while (il > 0) {
			if (temp != 0)
				temp = temp->next;
			il--;
		}
		while (ir > 0) {
			if (cur != 0)
				cur = cur->next;
			ir--;
		}
		simpleswap(cur, temp);
	}
	void merge1(linklist1<T>& h1, linklist1<T>& h2) {
		int k1 = h1.ssize();//first half
		int k2 = h2.ssize();//second half
		k2 = k2 / 2;
		k1 = k1 / 2;
		node* temp = h2.head;
		node* cur = h1.head;
		while (k2 > 0) {
			temp = temp->next;
			k2--;
		}
		while (k1 > 0) {
			insertattail(cur->data);
			cur = cur->next;
			k1--;
		}
		while (temp != 0) {
			insertattail(temp->data);
			temp = temp->next;
		}
	}
	void simpleswap(node*& temp, node*& cur) {
		node* n1 = temp->prev;
		node* n2 = cur->prev;
		node* h1 = temp->next;
		node* h2 = cur->next;
		if (n1 != 0) {  //temp->prev
			n1->next = cur;
			cur->prev = n1;
			if (h1 == 0)
				cur->next = 0;
		}
		if (n2 != 0) {       //cur->prev
			n2->next = temp;
			temp->prev = n2;
			if (h2 == 0)
				temp->next = 0;
		}
		if (h1 != 0) {   //temp->next
			h1->prev = cur;
			cur->next = h1;
			if (n1 == 0)
				cur->prev = 0;
		}
		if (h2 != 0) {    //cur->next
			h2->prev = temp;
			temp->next = h2;
			if (n2 == 0)
				temp->prev = 0;
		}
	}
	void insertsorted(int val) {
		int t;
		node* temp = new node;
		temp->next = 0;
		temp->prev = 0;
		temp->data = val;
		int l = 1;
		if (head == 0)
			tail = head = temp;
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
			//sorting
			while (l == 1) {
				l = 0;
				node* cur = head;
				while (cur->next != 0) {
					if (cur->data > cur->next->data) {
						t = cur->data;
						cur->data = cur->next->data;
						cur->next->data = t;
						l = 1;
					}
					 cur = cur->next;
				}
			}
		}
	}
	void deleteduplicate() {
		node* temp1 = head;
		node* n1;
		node* n2;
		int l = 1;
		while (temp1!=0) {
			node*temp = temp1->next;
			l = 0;
			while (temp != nullptr) {
				n2 = 0;
				if (temp1->data == temp->data) {
					n1 = temp->next;
					n2 = temp->prev;
					delete[]temp;
					n2->next = n1;
					n1->prev = n2;
					temp = n2;
				}
				temp = temp->next;
			}
			temp1 = temp1->next;
		}
	}
	~linklist1() {
		delete[]head;
		delete[]tail;
	}



};
int main() {
	linklist1<int>k1;
	k1.insertattail(7);
	k1.insertattail(5);
	k1.insertattail(9);
	k1.insertattail(10);
	k1.insertattail(11);
	cout << "After insertion : \n";
	k1.printforeward();
	k1.printreverse();
	cout << "\n_____________________________________________";
	k1.insertathead(21);
	cout << "\nAfter insertion at head : ";
	k1.printforeward();
	k1.printreverse();
	k1.insertattail(21);
	cout << "\n_____________________________________________";
	cout << "\nAfter insertion at tail : ";
	k1.printforeward();
	k1.printreverse();
	//copy constructor
	linklist1<int>k2(k1);
	cout << "\n_____________________________________________";
	cout << "\nAfter copy constructor : ";
	k2.printforeward();
	//delete operation
	cout << "\n_____________________________________________";
	cout << "\nAfter delete at head : ";
	k2.delH();
	k2.printforeward();
	cout << "\n_____________________________________________";
	cout << "\nAfter delete at tail : ";
	k2.delT();
	k2.printforeward();
	// size mid element
	cout << "\n_____________________________________________";
	cout << "\nsize is : " << k2.ssize();
	cout << "\nmid is : " << k2.returnmid();

	//find empty  find max
	cout << "\n_____________________________________________";
	if (k2.isempty() == true)
		cout << "\nGiven linked list is  empty ";
	else
		cout << "\nGiven linked list is not empty ";
	cout << "\nmax  is : " << k2.findmax();

	//insert after insert before
	cout << "\n_____________________________________________";
	int h;
	cout << "\nEnter val after which you want to insert key(31) : ";
	cin >> h;
	k2.insertAfter(h, 31);
	k2.printforeward();
	cout << "\nEnter val before which you want to insert key(24) : ";
	cin >> h;
	k2.insertBefore(h, 24);
	k2.printforeward();

	//swapping
	cout << "\n_____________________________________________";
	k2.printforeward();
	cout << "\nAfter swapping index 1 and 3";
	k2.swapnodes(1, 3);
	k2.printforeward();
	k2.printreverse();

	//combine linklist
	cout << "\n_____________________________________________";
	k1.insertathead(41);
	k1.insertathead(1);
	k1.insertathead(2);
	cout << "\n1st link list : ";
	k1.printforeward();
	cout << "\n2nd link list : ";
	k2.printforeward();

	cout << "\nAfter combine 1(first half) and 2(second hail) linklist : ";
	linklist1<int>k3;
	k3.merge1(k1, k2);
	k3.printforeward();
	cout << "\n_____________________________________________\n";
	//insertsorted
	linklist1<int>k4;
	int j;
	cout << "Enter five elemnts to test insert sorted : ";
	for (int i = 0;i < 5;i++) {
		cin >> j;
		k4.insertsorted(j);
	}
	k4.printforeward();
	k4.printreverse();
	cout << "\n_____________________________________________\n";
	linklist1<int>k5;
	k5.insertattail(19);
	k5.insertattail(16);
	k5.insertattail(22);
	k5.insertattail(19);
	k5.insertattail(16);
	k5.insertattail(25);
	k5.printforeward();
	cout << "\nAfter delete duplicates : ";
	k5.deleteduplicate();
	k5.printforeward();
	cout << "\n_____________________________________________\n";

}