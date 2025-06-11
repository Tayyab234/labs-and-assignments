#include<iostream>
#include <vector>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;
class heap {
public:
//____________________________________________________________
  class hufftree {
  public:
	  char ch;
	  hufftree* left;
	  hufftree* right;
	  hufftree* pare;
	  int data;
  };
  hufftree* root=nullptr;
  hufftree* h = nullptr;
  hufftree* ccreate() {
	  hufftree* temp = new hufftree;
	  temp->right = nullptr;
	  temp->left = nullptr;
	  temp->pare = nullptr;
	  temp->ch = 'NULL';
	  return temp;
  }
  hufftree* create(int l,int r,int s) {
	  hufftree* temp = ccreate();
	  temp->left = ccreate();
	  temp->right = ccreate();
	  temp->data = s;
	  temp->left->data = l;
	  temp->left->pare = temp;
	  temp->right->pare = temp;
	  temp->right->data = r;
	  return temp;
  }

  void sinsert(int l,int r,int s) {
	  if (root == nullptr) {
		  root = create(l, r, s);
	  }
	  else {
		  if (l == root->data) {
			  hufftree* temp = ccreate();
			  temp->right = ccreate();
			  temp->left = root;
			  temp->data = s;
			  root->pare = temp;
			  if (h == nullptr || h->data != r) {
				  temp->right->data = r;
				  temp->right->pare = temp;
			  }
			  else {
				  temp->right = h;
				  h->pare = temp;
				  h = nullptr;
			  }
			  root = temp;
			  root->pare = nullptr;
		  }
		  else if(r==root->data){
				  hufftree* temp = ccreate();
				  temp->left = ccreate();
				  temp->data = s;
				  temp->right = root;
				  root->pare = temp;
				  if (h == nullptr || h->data != l) {
					  temp->left->data = l;
					  temp->left->pare = temp;
				  }
				  else {
					  temp->left = h;
					  h->pare = temp;
					  h = nullptr;
				  }
				  root = temp;
				  root->pare = nullptr;
		  }
		  else {
			  h = create(l, r, s);
		  }
	  }
  }
  void postorder(hufftree* p) {
	  
	  if (p != nullptr) {
		  cout << p->data<<"   ";
		  if (p->ch != 'NULL')
			  cout << p->ch << "    ";
		  postorder(p->left);
		  postorder(p->right);
	  }
  }
  void inorder(hufftree* &p,int r,char c) {

	  if (p != nullptr) {
		  inorder(p->left,r,c);
		  if (p->data == r && p->ch!='NULL')
			  p->ch = c;
		  inorder(p->right,r,c);
	  }
  }
  void getchar(int ll,char k) {
	  hufftree* temp = root;
		  inorder(temp, ll, k);
  }
  void sshow() {
	  hufftree* temp = root;
	  cout << endl;
	  postorder(temp);
  }
//_____________________________________________________________


	int capacity;
	int c;
	int* arr;
	heap(int cap) {
		arr = new int[cap];
		c = cap;
		capacity = 1;
	}
	void insert(int da) {
		arr[capacity] = da;
		capacity++;
	}
	void mincheck() {
		int k;

		while (c != 2) {
			for (int n = c - 1;n >= 1;n--) {
				k = n / 2;
				if (k != 0) {
					if (arr[n] < arr[k])
						swap(n, k);
				}
			}
			add();
			show();
		}

	}
	void ddelete(int k) {
		int j = k+1;
		for (int i = k;i < c;i++) {
			arr[i] = arr[j];
			j++;
		}
		arr[c - 1] = 'NULL';
		c--;
	}
	void add() {
		int s;
		if (arr[2] < arr[3]) {
			s= arr[1] + arr[2];
			sinsert(arr[1], arr[2], s);
			arr[1] = arr[1] + arr[2];

			ddelete(2);
		}
		else {
			s = arr[1] + arr[3];
			sinsert(arr[1], arr[3], s);
			arr[1] = arr[1] + arr[3];
			ddelete(3);
		}
	}
	void swap(int n, int m) {
		int k = arr[n];
		arr[n] = arr[m];
		arr[m] = k;
	}
	void show() {
		cout << endl;
		for (int i = 1;i < c;i++) {
			cout << arr[i] <<"    ";
		}
	}
};
struct node {
	char data;
	int frequency;
};


void rfile(vector<node*>& v) {
	string text;

	ifstream file("huff.txt");
	while (getline(file, text))
	{
		cout << text;
	}
	cout << endl;
	file.close();
	int len = text.length();
	for (int i = 0;i < len;i++)
	{
		bool b = false;
		for (int a = 0;a < v.size();a++)
		{
			if (v[a]->data == text[i])
			{
				v[a]->frequency++;
				b = true;
			}
		}
		if (b == false)
		{
			node* temp = new node();
			temp->data = text[i];
			temp->frequency = 1;
			v.push_back(temp);
		}
	}
	for (int a = 0;a < v.size();a++)
	{
		cout << v[a]->data << "  ";
		cout << v[a]->frequency << "  ";
		cout << endl;
	}

}

int main()
{

	vector<node*> v;
	rfile(v);
	heap a(v.size() + 1);
	for (int k = 0;k < v.size();k++)
	{
		a.insert(v[k]->frequency);
	}
	a.mincheck();
	int kk;
	char hh;

	for (int k = 0;k < v.size();k++)
	{
		kk=v[k]->frequency;
		hh = v[k]->data;
		a.getchar(kk, hh);
	}
	
	a.sshow();
	Sleep(-1);
}








