#include<iostream>
#include<string>
using namespace std;
class teacher {
	string name,address,con_inf,email_add,insti,depart,design,qualifi;
	char type;
	string al[5];
	int cr[5],salary,pub,exp;
public:
	teacher() {
		name = " "; address = " ";con_inf = " "; email_add = " "; insti = " "; depart = " ";
		design = " "; qualifi = " ";
		type = 0;
		salary = 0;

	}
	void nset() {
		cout << "Please enter the name of the teacher : ";
		cin.ignore();
		getline(cin, name);
	}
	void aset() {
		cout << "\nPlease enter the address of the teacher house : ";
		getline(cin, address);
	}
	void cset() {
		cout << "\nPlease enter the contact no : ";
		getline(cin, con_inf);
	}
	void eset() {
		cout << "\nPlease enter the email address : ";
		getline(cin, email_add);
	}
	void diset() {
		int r;
		cout << "\nPlease enter the designation : For this select one of the given number \n";
		cout << "1. Lecturer 2. Assistant Professor 3.Associate Professor 4.Professor\nEnter : ";
		cin >> r;
		if (r == 1)
			design = "Lecturer";
		if (r == 2)
			design = "Assistant Professor";
		if (r == 3)
			design = "Associate Professor";
		if (r == 4)
			design = "Professor";
	}
	void iset() {
		cout << "\nPlease enter the institution name : ";
		getline(cin, insti);
	}
	void dset() {
		cout << "\nPlease enter the department : ";
		getline(cin, depart);
	}
	void qset() {
		int u;
		cout << "\nPlease enter the qualification : for this enter one of the  given ";
		cout << "\n1.Masters  2.Doctorate    3.post-doctorate \nEnter :  " ;
		cin >> u;
		if (u == 1)
			qualifi = "Masters";
		if (u == 2)
			qualifi = "Doctorate";
		if (u == 3)
			qualifi = "Post-doctorate";
	}
	void tset() {
		int b;
		cout << "\n Please enter 1. if the teacher is permanent or Enter 2. if the teacher is  visitor : ";
		cin >> b;
		if(b==1)
		  type='P';
		if (b == 2)
			type = 'V';
		else
			type = 'V';
	}
	void cuset(int s) {
		for (int i = 0;i < s;i++) {
			cout << "\nPLease enter the name  " << i+1 << " allocate subject : ";
			cin.ignore();
			getline(cin, al[i]);
		}
	}
	void ccset(int s) {
		cout << "\nPlease enter the credit hours of the subjects :";
		for (int i = 0;i < s;i++) {
			cout << "\nPlease enter " << al[i] << " total hours : ";
			cin >> cr[i];
		}
	}
	void eeset() {
		cout << "\nPlease enter experience(0-4) : ";
		cin >> exp;
	}
	void ppset() {
		cout << "\nPlease enter the publication : ";
		cin >> pub;
	}
	string nnget() {
		return name;
	}
	void update() {
		int y;
		do {
			cout << "\nEnter 1 to update qualification\nEnter 2 to update contact\nEnter 3 to update institution\nenter four for exit";
			cout << "\nEnter : ";
			cin >> y;
			if (y == 1) {
				cout << "\nEnter : ";
				cin.ignore();
				getline(cin,qualifi);
			 }
			if (y == 2) {
				cout << "\nEnter : ";
				cin >> con_inf;
			}
			if (y == 3) {
				cout << "\nEnter : ";
				cin.ignore();
				getline(cin, insti);
			}
		
		} while (y != 4);
	}
	void display(int s) {
		cout << "\n"<<name << "\n"<<address << "\n"<<con_inf << "\n"<<email_add << "\n"<<insti <<"\n"<< depart << "\n"<<type<<"\n"<<design;
		cout << "\n";
		for (int i = 0;i < s;i++) {
			cout << al[i] ;
			if (i != s-1)
				cout << " , ";
		}
		cout << "\n";
		for (int i = 0;i < s;i++) {
			cout << cr[i];
			if (i != s - 1)
				cout << " , ";
		}
		cout << "\n" << salary << "\n" << pub << "\n" << exp << "\n" << qualifi<<"\n";
	}
	void salaryset(int s) {
		if (type == 'P') {
			if (design == "Lecturer")
				salary = 100000;
			else if (design == "Professor")
				salary = 325000;
			else if (design == "Assistant Professor")
				salary = 175000;
			else if (design == "Associate Professor")
				salary = 250000;

		}
		else if (type == 'V') {
			if (design == "Lecturer")
				salary = 2000;
			else if (design == "Professor")
				salary = 9000;
			else if (design == "Assistant Professor")
				salary = 4000;
			else if (design == "Associate Professor")
				salary = 7000;
		}

	}
};
void menu() {
	cout << "\n1.Input data\n2.updateRecord\n3.displaydata\n4.exist";
}
int main() {
	int n,o=0;
	teacher s[5];
	int k,f;
	
	do {
		menu();
		cout << "\nPlease enter number : ";
		cin >> n;
		if (n == 1) {
			s[o].nset();
			s[o].aset();
			s[o].cset();
			s[o].eset();
			s[o].iset();
			s[o].dset();
			s[o].tset();
			s[o].diset();
			cout << "\nPlease enter total number of allocated subject : ";
			cin >> f;
			s[o].cuset(f);
			s[o].ccset(f);
			s[o].eeset();
			s[o].ppset();
			cin.ignore();
			s[o].qset();
			s[o].salaryset(f);
			o = o + 1;
		}
		if (n == 2) {
			if (o > 1) {
				cout << "\nPlease enter which record you want to update :  ";
				for (int i = 0;i < o;i++) {
					cout << i + 1 << " ." << s[i].nnget() << "   ";
				}
				cout << "\nEnter : ";
				cin >> k;

				s[k - 1].update();
			}
			if (o == 1) {
				cout << "IN " << s[0].nnget() << " the things which can be update are given below : ";
				s[0].update();
			}
			else
				cout << "\nPlease first input data ";
			if(o!=0)
			    cout << "\nData has been updated succesfully\n";
		}
		if (n == 3) {
			int b ;
			if (o > 1) {
				cout << "\nPlease enter which record you want to display :  ";
				for (int i = 0;i < o;i++) {
					cout << i + 1 << " ." << s[i].nnget() << "   ";
				}
				cin >> b;
				s[b - 1].display(f);
			}
			if (o == 1) {
				cout << "\nData are given below : \n";
				s[0].display(f);
			}
		}
	} while (n < 4);
	return 0;
}