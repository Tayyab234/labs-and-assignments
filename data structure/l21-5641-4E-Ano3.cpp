#include<iostream>
#include<string>
using namespace std;
template <class T>
class DLADT {
public:
	class node {
	public:
		T data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
	DLADT() {
		head = tail = 0;
	}
	DLADT(DLADT<T>& h) {//copy constructor
		node* temp = h.head;
		while (temp != 0) {
			insertattail(temp->data);
			temp = temp->next;
		}
	}
	void insert(T val) {
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
	int count() {
		node* temp = head;
		int i = 0;
		while (temp != 0) {
			i++;
			temp = temp->next;
		}
		return i;
	}
    int removefromPosition(int index) {  
		int a;
		node* temp=head;
		while (index > 0) {
			if (temp != 0)
				temp = temp->next;
			index--;
		}
		if (temp == head&&index>=0) {
			a = temp->data;
			temp = head->next;
			delete[]head;
			head = temp;
			head->prev = 0;
			return a;
		}
		else if (temp == tail && index >=0) {
			a = temp->data;
			temp = tail->prev;
			delete[]tail;
			tail = temp;
			tail->next = 0;
			return a;
		}
		else if (temp == 0) {
			return 0;
		}
		else {
			a = temp->data;
			node* cur=temp->prev;
			cur->next = temp->next;
			temp->next->prev = cur;
			delete[]temp;
			return a;
		}
	}
	bool remove(T a) {
		node* temp = head;
		while (temp!= 0) {
			if (temp->data == a)
				break;
			temp = temp->next;
		}
		if (temp == head) {
			temp = head->next;
			delete[]head;
			head = temp;
			head->prev = 0;
			return true;
		}
		else if (temp == tail ) {
			temp = tail->prev;
			delete[]tail;
			tail = temp;
			tail->next = 0;
			return true;
		}
		else if (temp == 0) {
			return false;
		}
		else {
			node* cur = temp->prev;
			cur->next = temp->next;
			temp->next->prev = cur;
			delete[]temp;
			return true;
		}
	}
	void printForeward() {
		node* temp = head;
		cout << "\nPrint foreward Linkedlist :  ";
		while (temp != 0) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	void printBackward() {
		node* temp = tail;
		cout << "\nPrint reversee Linkedlist :  ";
		while (temp != 0) {
			cout << temp->data << "  ";
			temp = temp->prev;
		}
		cout << endl;
	}
	int valAtCenterNode() {
		int h = count();
		h = h / 2;
		node* temp = head;
		while (h > 1) {
			temp = temp->next;
			h--;
		}
		return temp->data;
	}
	~DLADT() {
		delete[]head;
		delete[]tail;
	}

};

template <class T>
class DLRecordADT {    //new link list
public:
	class node {
	public:
		T data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
	DLRecordADT() {
		head = tail = 0;
	}
	void insert(T val) {
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
	bool searchrec(T a, int n) {
		node* temp = head;
		while (temp != 0) {
			if (n == 1) {

				if (temp->data.first == a.first && temp->data.last == a.last) {
					cout << temp->data.first << a.first << temp->data.last << a.last;
					break;
				}
			}
			else {
				if (temp->data.tel == a.tel )
					break;
			}
			temp = temp->next;
		}
		if (temp != 0)
			return true;
		else
			return false;
	}
	
	bool remove(T a,int n) {
		node* temp = head;
		while (temp != 0) {
			if (n == 1) {
				string s=temp->data.first;
				string s1 = temp->data.last;
			
				if (s == a.first && s1== a.last) {
					break;
				}
			}
			else {
				string s1 = temp->data.tel;
				if (s1 == a.tel)
					break;
			}
			temp = temp->next;
		}
		if (temp == head) {
			head = head->next;
			delete[]temp;
			return true;
		}
		else if (temp == tail) {
			tail = tail->prev;
			delete[]temp;
			tail->next = 0;
			return true;
		}
		else if (temp == 0) {
			return false;
		}
		else {
			node* cur = temp->prev;
			cur->next = temp->next;
			temp->next->prev = cur;
			delete[]temp;
			return true;
		}
	}
	void printrec() {
		node* temp = head;
		cout << "\n\n______________________________record______________________________\n\n";
		while (temp != 0) {
			cout << "Name : " << temp->data.first<<" "<<temp->data.last;
			cout << "\nRoll No : " << temp->data.rol_no;
			cout << "\nTelephone number : " << temp->data.tel;
			cout << "\n************************************************\n\n";
			temp = temp->next;

		}
		cout << "\n\n_________________________________________________________________\n\n";
	}
	
	~DLRecordADT() {
		delete[]head;
		delete[]tail;
	}

};
struct digitalTDire{     //digital telephone directory
	char first[20];
	char last[20];
	char tel[20];
	char rol_no[10];
};
int main() {
	/*DLADT<int> L;                //code  provide
	for (int i = 0; i< 10; i++)
		L.insert(i * 2);
	cout<<L.valAtCenterNode();
	cout<<"\nRemoving: "<<L.removefromPosition(6)<<endl;
	cout<<L.valAtCenterNode()<<endl;
	if (L.remove(12))
		cout<<"\nRemoved ";
	else
		cout<<"No Removed ";
	L.printBackward();*/

	//___________________________________________________________________________
	//menu
	int n=0;
	DLRecordADT<digitalTDire>k;
	digitalTDire h;
	do {
		cout << "\n\n_________________________Menu________________________________________\n\n";
		cout << "\n1.Enter a record \n2.Delete a record  \n3.Search a record  \n4.Print records \n5.Exit\n\nEnter input : ";
		cin >> n;
		cout << "\n\n_____________________________________________________________________\n\n";
		if (n == 1) {
			cout << "Please Enter user full name : ";
			cin>>h.first>>h.last;
			cout << "\nPlease Enter user Roll-no : ";
			cin >> h.rol_no;
			cout << "\nPlease Enter user telephone no : ";
			cin >> h.tel;
			k.insert(h);
			cout << "\nRecord Enter Sucessfully";

		}
		else if (n == 2) {
			int nh;
			cout << "\n1.By name \n2.by telephone no \nEnter input : ";
			cin >> nh;
			if (nh == 1) {
				cout << "Please Enter user full name whuch record you want to delete : ";
				cin >> h.first >> h.last;
				if (k.remove(h, 1)==true)
					cout << "\nremoved";
				else 
					cout << "\n no removed : the record might not exit or enter correct speling";
			}
			else if (nh == 2) {
				cout << "Please Enter user telephone no whuch record you want to delete : ";
				cin >> h.tel;
				if (k.remove(h, 0)==true)
					cout << "\nremoved";
				else
					cout << "\n no removed : the record might not exit or enter correct phone no";
			}
			
		}
		else if (n == 3) {
			int nh;
			cout << "\n1.By name \n2.by telephone no \nEnter input : ";
			cin >> nh;
			if (nh == 1) {
				cout << "Please Enter user full name whuch record you want to search : ";
				cin >> h.first >> h.last;
				if (k.remove(h, 1) == true)
					cout << "\nfount";
				else
					cout << "\n not found: the record might not exit or enter correct speling";
			}
			else if (nh == 2) {
				cout << "Please Enter user telephone no whuch record you want to delete : ";
				cin >> h.tel;
				if (k.remove(h, 0) == true)
					cout << "\nfound";
				else
					cout << "\n not found : the record might not exit or enter correct phone no";
			}

		}
		else if (n == 4) {
			k.printrec();
		}

	} while (n != 5);
	//______________________________________________________________________________
	system("pause");
	return 0;
}