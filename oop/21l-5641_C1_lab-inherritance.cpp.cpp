#include<iostream>
#include<string>
using namespace std;
class person {
	char * first_name,* last_name;
protected:
	int age;
public:
	person(char* n, char* f, int *a) {
		cout << "\nperson() called\n";
		first_name = n;
		last_name = f;
		age = *a;
    }
	void information() {
		cout  <<endl<< first_name << " " << last_name<<" and his age is  "<<age;
	}
    void nset(char* n,char*l) {
		first_name = n;
			last_name = l;
	}
	void aset(int a) {
		age = a;
	}
	char* fname() {
		return first_name;
	}
	char* lname() {
		return last_name;
	}
	int age1() {
		return age;
	}
	~person() {
		cout << "\n~person() called\n";
	}
};
class student : public person {
	double cgpa;
public:
	student(double a,char*s,char*g,int* h): person(s,g,h){
		cgpa = a;
	}
	void cpset(double a) {
		cgpa = a;
	}
	void info() {
		information();
	}
	double cpget() {
		return cgpa;
	}
};
class graduate: public person{
	char* fyp_name;
public:
	graduate(char* s, char* n, char* f, int* a) :person(n, f, a) {
		cout << "\ngraduate() called \n";
		fyp_name = s;
    }
	void fypset(char* k) {
		fyp_name = k;
	}
	char* fpset() {
		return fyp_name;
	}
	~graduate() {
		cout << "\n~graduate() called\n";
	}
};
class undergraduate : public person {
	char* thesis_topic;
public:
	undergraduate(char* s,char* n, char* f, int* a) :person(n, f, a) {
		cout << "\nundergraduate() called\n";
	       thesis_topic = s;
	}
	void thset(char* y) {
		thesis_topic = y;
	}
	char* thesset() {
		return thesis_topic;
	}
	~undergraduate() {
		cout << "\n~undergraduate() called\n";
	}
};
class faculty : public person {
	int count;
	int t_e;
public:
	faculty(int c, int t, char* s, char* r, int *a) :person(s, r, a) {
		cout << "\nfaculty() called ";
		count = c;
		t_e = t;
	}
	void fset(int a) {
		count = a;
	}
	void info() {
		information();
	}
	void feset( int b) {
		t_e = b;
	}
	int coget() {
		return count;
	}
	int feget() {
		return t_e;
	}
	~faculty(){
		cout << "\n~faculty() called";
	}
};
int main() {
	char *l,*y,*u,*i,*q ;
	l = new char[15];
	y = new char[15];
	u = new char[15];
	i = new char[15];
	q = new char[15];
    cout << "Enter undergraduate student first name : ";
	cin >> l;
	cin.ignore();
	cout << "\nEnter undergraduate student last name : ";
	cin >> y;
	int* o = new int;
	cout << "\nEnter undergraduate student age : ";
	cin >> *o;
	student a(3.14,l,y,o);
	cout << "Enter faculty member first name : ";
	cin >> u;
	cout << "\nEnter faculty member last name : ";
	cin >> i;
	cout << "\n enter faculty member age : ";
	int* aa = new int;
	cin >> *aa;
	faculty f(2, 420,u, i, o);
	cout << "\n______________________________________________________________\n";
	cout << "\nfaculty member :  ";
	f.info();
	cout << "\n______________________________________________________________\n";
	cout << "\nundergraduate student : ";
	a.info();
	cout << " and his cgpa is " << a.cpget();
	cout << "\n______________________________________________________________\n";
	cout << "\nfaculty member :  ";
	f.info();
	char*pp;
	pp = new char[15];
	cout << " and his no of courses is : " << f.coget() << " and his extension number is : " << f.feget();
	cout << "\n______________________________________________________________\n";
	cout << "\nEnter undergraduate student thesis topic : ";
	cin >> q;
	cout << "\nEnter Graduate student final year project name : ";
	cin >> pp;
	undergraduate h(q, u, i, o);
	graduate hh(pp, u, i, o);
	cout << "\n______________________________________________________________\n";
	cout << "\nundergraduate student : ";
	a.info();
	cout << " and his cgpa is " << a.cpget()<<" and his thesis topic is :"<<h.thesset();
	cout << "\n_______________________________________________________________\n";
	cout << "\nGraduate student : ";
	a.info();
	cout << " and his cgpa is " << a.cpget() << " and his final year project name is :" << hh.fpset();
	cout << "\n______________________________________________________________\n";
	return 0;
}