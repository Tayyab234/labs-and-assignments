#include<iostream>
using namespace std;
template<class T>
class BST {
public:
	class node {
	public:
		T data;
		node* left;
		node* right;
	};
	node* root;
    BST() {                     //constructor
		root = nullptr;
	}
	//_____________________________deep copy constructor
	BST(const BST& obj) {
		root = 0;
		rc1(obj.root);
	}
	void rc1(node* temp) {
		if (temp != 0) {
			insert(temp->data);
			rc1(temp->left);
			rc1(temp->right);
		}
	}
	//_____________________________________________________
	//__________________________________________insert iterative way__________________
	void insert(T n) {  
		node* temp = new node;
		temp->left = 0;
		temp->right = 0;
		temp->data = n;
		if (root == 0)
			root = temp;
		else {
			node* cur = root;
			node* prev = 0;
			while (cur != 0) {
				prev = cur;
				if (cur->data > n)
					cur = cur->left;
				else
					cur = cur->right;

			}
			if (prev->data > n)
				prev->left = temp;
			else
				prev->right = temp;
		}
	}
	//_________________________________________________________________________
	//_____________________________find value in tree_____________________________
	bool find(T val) {
		return rfind(val, root);
	}
	bool rfind(int n, node* temp) {
		if (temp==0)
			return false;
		if (temp->data == n)
			return true;
		if (temp->data > n)
			return rfind(n,temp->left);
		else
			return rfind(n, temp->right);
	}
	//_____________________________________________________________________________
	//________________________delete node iterative way(leaf nodes handling)_____________________________
	bool del_iterative(T n) {
		node* temp = root;
		node* prev = 0;
		while (temp != 0) {
			if (temp->data == n)
				break;
			prev = temp;
			if (temp->data > n)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if (temp == 0)
			return false;
		else {
			if (temp->left == 0 && temp->right == 0) {
				if (prev->left == temp)
					prev->left = 0;
				else
					prev->right = 0;
				delete[]temp;
				return true;
			}
			else
				return false;
		}
	}
	//________________________________________________________________________________
	//_________________________________insert recursively________________________________
	void insert_r(T val) {
		insert_recursive(val, root);
	}
	void insert_recursive(T val, node* temp) {
		if (temp->left == 0||temp->right==0) {
		  node* h = new node;
		  h->left = 0;
	          h->right = 0;
		  h->data = val;
		  if (temp->data > val&&temp->left == 0 )
			temp->left = h;
		  else if(temp->right == 0 && temp->data < val)
			temp->right = h;
		return;			
		}
		if (temp->data > val)
			insert_recursive(val, temp->left);
		else
			insert_recursive(val, temp->right);
	}
	//_____________________________________________________________________________
	//__________________________________delete recursively____________________________
	bool delete_recursive(T val) {
		node* temp = 0;
		return del(root, temp, val);

	}
	bool del(node* temp, node* prev,T n) {
		if (temp == 0)
			return false;
		if (temp->data == n) {
			if (temp->left == 0 && temp->right == 0) {
				if (prev != 0) {
					if (prev->left == temp)
						prev->left = 0;
					else
						prev->right = 0;
				}
				delete temp;
			}
			else if (prev != 0) {
				if (prev->data > temp->data) {
					prev->left = temp->left;
					delete temp;
				}
				else {
					prev->right = temp->right;
					delete temp;
				}
			}
			return true;
		}
		if (temp->data > n)
			return del(temp->left, temp,n);
		else
			return del(temp->right,temp,n);
	}
	
	//_______________________________________________________________________________________
	//____________________________________________________display function_________________
	void display() {
		cout << endl;
		print1(root);
	}
	void print1(node*temp) {
		if (temp == 0)
			return;
	    cout << temp->data << "   ";
		print1(temp->left);
		print1(temp->right);
		
	}
	//_______________________________________________________________________________________
	//___________________________total sum of leaf nodes________________________________
	void leafsum() {
		int h = 0;
		leafsum1(root, h);
		cout << "\nTotal leaf nodes are : " << h;
	}
	void leafsum1(node*temp,int&sum) {
		if (temp == 0) {
			return;
		}
		else if (temp->left == 0 && temp->right == 0)
			sum++;
		leafsum1(temp->left,sum);
		leafsum1(temp->right,sum);
		
	}
	//____________________________________________________________________________
	//_________________________________destructor___________________________ 
	void cdel(node* temp) {//delete every node of tree
		if (temp == 0)
			return;
		cdel(temp->left);
		cdel(temp->right);
		delete temp;
	}
	~BST() {
		cdel(root);
	}
	//____________________________________________________________________
	//__________________________________________task 2______________________________________________sibling
	bool height(node* temp, node*&prev, int n, int& l) {  //send height of node and tell if it present in tree or not
		if (temp == 0)
			return false;
		if (temp->data == n)
			return true;
		prev = temp;
		if (temp->data > n) {
			l++;
			return height(temp->left,  prev, n, l);
		}
		else {
			l++;
			return height(temp->right, prev, n, l);
		}
	}

    bool sibling(int h,int k) {
		int l1=0;
		int l2 = 0;
		node* prev=0;
		if (height(root,prev, h, l1) == true && height(root,prev, k, l2) == true) {
			if (l1 != l2 || prev == 0)
				return false;
			else if (prev->left->data == h && prev->right->data == k || prev->right->data == h && prev->left->data == k)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	//_______________________________________________________________________________________________
};

int main() {
	BST<int>obj;
	cout << "\nAfter insertion (iterative and recursive) \n";
	obj.insert(7);
	obj.insert_r(3);      //insert recursively
	obj.insert(2);
	obj.insert(4);
	obj.insert_r(10);
	obj.insert(9);
	obj.insert_r(11);
    obj.display();
	cout << "\nAfter deletion (iterative and recursive) \n";
	obj.del_iterative(11);//delete iterative
	obj.delete_recursive(2);//delete recursive
	obj.display();

	cout << "\nAfter deep copy of obj \n";
	BST<int>obj1(obj);
	obj1.display();

	obj1.leafsum();
	cout << "\n__________________________________________________\n";
	int n;
	cout << "\nPlease Enter value which you want to search in tree :  ";
	cin >> n;
	if (obj1.find(n) == true)
		cout << "\nGiven value is present in tree";
	else
		cout << "\nGiven value is not present in tree";

	cout << "\n__________________________________________________\n";//for task two
	BST<int>obj3;
	obj3.insert(6);
	obj3.insert_r(7);
	obj3.insert(5);
	obj3.insert_r(2);
	obj3.insert(4);
	obj3.insert_r(3);
	obj3.insert(10);
	obj3.insert_r(9);
	obj3.insert(11);
	cout << "tree is GIven in pre-order :  ";
	obj3.display();
	int k, l;
	cout << "\nPlease enter two values for sibling test :  ";
	cin >> k >> l;
	if (obj3.sibling(k, l) == true)
		cout << "\nGiven values are sibling ";
	else
		cout << "\nGiven values are not sibling ";
	cout << endl << endl;
	return 0;

}





