#include<iostream>
using namespace std;
template <class T>
class llqueue {
public:
	struct node {
		T data;
		node* next;
	};
	node* head;
	llqueue() {
		head = 0;
	}
    void enque(T val) {
		node* temp = new node;
		temp->next = 0;
		temp->data = val;

		if (head == 0)
			head = temp;
		else {
			node* cur = head;
			while (cur->next != 0)
				cur = cur->next;
			cur->next = temp;
			cur = temp;
		}
	}
	T deque() {
		T h;
		node* temp = head;
		h = temp->data;
		head = head->next;
		delete[]temp;
		return h;
	}
	bool isempty() {
		if (head == 0)
			return false;
		return true;
	}
	T front() {
		T h;
		h = head->data;
		return h;

	}
	T rare() {
		T h;
		node* temp = head;
		while (temp->next != 0)
			temp = temp->next;
		h = temp->data;
		return h;

	}

	bool consectivetriples(int k) {
		node* h;
		node* temp = head;
		int c=0;
		int s1 = 0,s2=0,s3=0;
		while (temp != 0) {
		   s1 = temp->data;
		   if (temp->next != 0) {
			   h = temp->next;
			   s2 = h->data;
		   }
		   else
			   return false;
		   if (h->next != 0)
			   s3 = h->next->data;
		   else
			   return false;
		   if (s2-s1 != s3-s2)
			   return false;
		   
		   c = k;
		   temp = h->next;
		   if (temp->next != 0) {
			   while (c > 0) {
				   if (temp->next != 0) {
					   temp = temp->next;
					   c--;
				   }
				   else
					   return false;
			   }
		   }
		   temp = temp->next;
		}
		return true;
	}
	int size1() {
		int i = 0;
		node* temp = head;
		while (temp != 0) {
			temp = temp->next;
			i++;
		}
		return i;
	}
	void show() {
		node* temp = head;
		cout << "\nQueue is :  ";
		while (temp != 0) {
			cout << temp->data << "   ";
			temp = temp->next;
		}
		cout << endl;
	}

};
int main() {
	int s;
	llqueue<int>k;
	llqueue<int>ll;
	k.enque(1);
	k.enque(2);
	k.enque(3);
	k.enque(4);
	k.enque(5);
	k.enque(11);
	k.enque(12);
	k.enque(13);
	k.show();
	s = 2;
	if (k.consectivetriples(s) == true)
		cout << "\nGiven queue is consective triple with k = " << s;
	else
		cout << "\nGiven queue is not consective triple with k = " << s;
	s = 3;
	if (k.consectivetriples(s) == true)
		cout << "\nGiven queue is consective triple with k = " << s;
	else
		cout << "\nGiven queue is not consective triple with k = " << s;

	k.show();
	cout << "\n After alternative manner : \n";

	//__________________________________________________________
	int d1, d2;
	int j = k.size1();
	int k1 = j / 2;
	j = j - k1;
	while (k1 > 0) {
		ll.enque(k.deque());
		k1--;
	}
	while (j > 0) {
		d1 = ll.deque();
		d2 = k.deque();
		k.enque(d1);
		k.enque(d2);
		j--;
	}

	//______________________________________________________________

	k.show();
	return 0;
}