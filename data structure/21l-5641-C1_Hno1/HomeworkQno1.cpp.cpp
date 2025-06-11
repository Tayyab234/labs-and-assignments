#include<iostream>
using namespace std;
class set {
	int* data;
	int noofelements;
	int capacity;
public:
	set(int cap = 0) {
		capacity = cap;
		data = new int[cap+1];
		noofelements = cap;
	}
	//deep copy
	set(const set& ref) {
		this->capacity = ref.capacity;
		this->data = new int[this->capacity];
		for (int i = 0;i <this-> capacity;i++) {
			this->data[i] = ref.data[i];
		}
	}
	~set() {
		delete[]data;
	}
	void input() {
		for (int i = 0;i < capacity;i++) {
			cout << "Enter " << i + 1 << " element : ";
			cin >> data[i];
			cout << endl;
		}
	}
	void insert(int element) {
		data[capacity+1] = element;
    }
	void remove() {
		int j = 0;
		for (int i = 0;i < capacity;i++) {
			if (data[i] != 0)
				j = j + 1;
		}
		if (j <= capacity / 2) {
			int k = capacity / 3;
			data = new int[k];
			capacity = k;
			cout << "\nNew capacity of data element array is : " << k << endl;
		}

	}
	int getCardinality()const {
		int j = 0;
		for (int i = 0;i < capacity;i++) {
			if (data[i] != 0)
				j = j + 1;
		}
		return j;
	}
	set calcUnion(const set& s2) {
		int j = this->getCardinality();
		int k = s2.getCardinality();
		int y = j + k;
		set s3(y);
		int o = 0;
		for (int i = 0;i < j;i++) {
			s3.data[o] = this->data[i];
			o = o + 1;
		}
		for (int i = 0;i < k;i++) {
			s3.data[o] = s2.data[i];
			o = o + 1;
		}
		for (int i = 0;i < o;i++) {
			for (int l = i + 1;l < o;l++) {
				int temp;
				if (s3.data[i] >s3.data[l]) {
					temp = s3.data[i];
					s3.data[i] = s3.data[l];
					s3.data[l] = temp;
				}
				
			}
		}
		for (int i = 0;i < o;i++) {
			for (int l = i + 1;l < o;l++) {
				if (s3.data[i] == s3.data[l]) {
					for (int oo = l;oo < o;oo++) {
						if (oo + 1 != o) {
							s3.data[oo] = s3.data[oo + 1];
						}
					}
				}
				
			}
		}
		s3.capacity = s3.getCardinality();
		return s3;

	}
	set calcDifferrence(const set& s2)const {
		int y,s,r;
		if (this->getCardinality() >= s2.getCardinality()) {
			y = this->getCardinality();
		}
		else {
			y = s2.getCardinality();
		}
		s = this->getCardinality();
		r = s2.getCardinality();
		set s3(y);
		int u = 0;
		for(int i = 0;i < s;i++) {
			for (int zz = 0;zz < r;zz++) {
				if (this->data[i] == s2.data[zz]) {
					s3.data[u] = this->data[i];
					u = u + 1;
					break;
				}
			}
		}
		s3.capacity = u;
		return s3;
	}
	set calcSymmetricDifference(const set& s2) {
		set s4=this->calcUnion(s2);
		set s5 = this->calcDifferrence(s2);
		int o = s4.getCardinality();
		int y = s5.getCardinality();
		set s3(o);
		int u = 0;
		bool p;
		for (int i = 0;i < o;i++) {
			for (int l = 0;l < y;l++) {
				if (s4.data[i] != s5.data[l]) {
					p = true;
				}
				else {
					p = false;
					break;
				}
			}
			if (p == true) {
				s3.data[u] = s4.data[i];
				u = u + 1;
			}
		}
		s3.capacity = u ;
		return s3;
	}
	int ismember(int val)const {
		int j = getCardinality();
		for (int i = 0;i < j;i++) {
			if (data[i] == val) {
				return 1;
				break;
			}
		}
    }
	int issubset(const set& s2)const {
		bool j;
		int o;
		if (s2.getCardinality() == this->getCardinality()) {
			o = s2.getCardinality();
			for (int i = 0;i < o;i++) {
				for (int w = 0;w < o;w++) {
					if (data[i] != s2.data[w]) {
						j = false;
					}
					else {
						j = true;
						break;
					}
				}
				if (j == false)
					break;
			}
			if (j == true)
				return 2;
			else
				return 0;
		}
		else if(s2.getCardinality() < this->getCardinality()) {
			o = s2.getCardinality();
			int z= getCardinality();
			for (int i = 0;i < z;i++) {
				for (int w = 0;w < o;w++) {
					if (data[i] != s2.data[w]) {
						j = false;
					}
					else {
						j = true;
						break;
					}
				}
				if (j == false)
					break;
			}
			if (j == true)
				return 1;
			else
				return 0;
		}
	}
	void update(int prval, int curval) {
		int y = getCardinality();
		bool n;
		for (int i = 0;i < y;i++) {
			if (data[i] == prval) {
				n = true;
				break;
			}
			else
				n = false;
		}
		if (n == false)
			cout << "\nTarget Value not found \n";
		else if (n == true) {
			for (int i = 0;i < y;i++) {
				if (data[i] == curval) {
					n = false;
					break;
				}
				else
					n = true;
			}
		}
		if (n == false)
			cout << "\nViolation set property Cannot Modify the data \n";
		else {
			for (int i = 0;i < y;i++) {
				if (data[i] == prval) {
					data[i] = curval;
					cout << "\nData updated succesfully\n";
					break;
				}
			}
		}
	}
	void show()const {
		int y = capacity;
		cout << endl<<"Set ARE Given below :-"<<endl;
		for (int i = 0;i < y;i++) {
			cout << data[i]<<"  ";
		}
		cout << endl;
	}

};
int main() {
	int p;
	cout << "\nEnter capacity of set 1 :";
	cin >> p;
	set a(p);
	a.input();
	set h(a);
	cout << "\n after copy constructor";
	h.show();
	cout << endl << "No of elements in set a is : " << a.getCardinality();
	int pp;
	cout << "\nEnter capacity of set 2 :";
	cin >> pp;
    set s(pp);
	s.input();
	set s3=s.calcUnion(a);
	cout << "\nAfter union function of Set 1 and set 2 \n";
	s3.show();
	set s4 = s.calcDifferrence(a);
	cout << "\nAfter intersection function of Set 1 and set 2 \n";
	s4.show();
	set s5 = s.calcSymmetricDifference(a);
	cout << "\nAfter symmetric difference function of Set 1 and set 2 \n";
	s5.show();
	int g;
	cout << endl << "\nEnter element which you want to check : ";
	cin >> g;
	if (a.ismember(g) == 1)
		cout << "\nthe given number is a member of set 1 ";
	else
		cout << "\nthe given number is not a member of set 1 ";
	if (s.ismember(g) == 1)
		cout << "\nthe given number is a member of set 2 ";
	else
		cout << "\nthe given number is not a member of set 2 ";
	cout << "\nEnter set 3 of capacity 4 : \n";
	set d(4);
	d.input();
	if (a.issubset(d) == 0)
		cout << "\nset 4 is not a subset of set 1";
	else if (a.issubset(d) == 1)
		cout << "\nset 4 is a proper subset of set 1";
	else if (a.issubset(d) == 2)
		cout << "\nset 4 is an improper subset of set 1";
	int rr,zz;
	cout << "\nEnter element which you want to update in set 1 : ";
	cin >> rr;
	cout << "\nEnter element instead of which number you want to update in set 1 : ";
	cin >> zz;
	a.update(zz, rr);
	a.show();
	return 0;
}