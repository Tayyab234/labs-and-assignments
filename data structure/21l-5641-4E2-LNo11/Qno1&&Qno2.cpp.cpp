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
	
	bool del_iterative(T n) {
		node* temp = root;
		node* prev = 0;
		while (temp != 0) {
			if (temp->data == n)
				break;
			prev = temp;
			if (temp->data > n)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if (temp == 0)
			return false;
		else {
			if (temp->left == 0 && temp->right == 0) {//no child case
				if (prev == 0) {
					delete root;
					root = 0;
					return true;
				}

				if (prev->left == temp)
					prev->left = 0;
				else
					prev->right = 0;
				delete[]temp;
				return true;
			}
			else if (temp->left != 0 && temp->right != 0) {//two child case
				node* cur = temp;
				prev = temp;
				cur = cur->left;
				while (cur->right != 0) {
					prev = cur;
					cur = cur->right;
				}
				if (prev->left == cur)
					prev->left = cur->left;
				else
				    prev->right = cur->left;
				temp->data = cur->data;
				delete[]cur;
				return true;
			}
			else {//one child case
				if (prev == 0) {
					node* cur;
					if (temp->left != 0)
						cur = temp->left;
					else
						cur = temp->right;
					delete[]temp;
					root = cur;
				}
				else {
					if (prev->left == temp) {
						if (temp->left != 0)
							prev->left = temp->left;
						else
							prev->left = temp->right;
					}
					else {
						if (temp->left != 0)
							prev->right = temp->left;
						else
							prev->right = temp->right;
					}
                                      delete temp;
				}
				return true;
			}
			
		}
	}

	//_______________________________________________________________________________________
	//____________________________________________________display function_________________
	void display() {
		cout << endl;
		print1(root);
	}
	void print1(node* temp) {
		if (temp == 0)
			return;
		cout << temp->data << "   ";
		print1(temp->left);
		print1(temp->right);

	}
	//________________________________________________________________
	void swap() {
		node* temp = root->left;
		int n = root->data;
		root->data = temp->data;
		temp->data = n;
	}
	
	void correct() {
		correct1(root);
	}
	void correct1(node* temp) {
		if (temp == 0)
			return;
		if (temp->left != 0) {
			node* cur = temp->left;
			if (cur->data > temp->data) {
				int n = cur->data;
				cur->data = temp->data;
				temp->data = n;
			}
				
		}
		if (temp->right != 0) {
			node* cur = temp->right;
			if (cur->data < temp->data) {
				int n = cur->data;
				cur->data = temp->data;
				temp->data = n;
			}

		}
		correct1(temp->left);
		correct1(temp->right);
	}
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
};

int main() {
	BST<int>obj;
	cout << "\nAfter insertion (iterative and recursive) \n";
	obj.insert(15);
	
	obj.insert(13);
	obj.insert(16);
	
	obj.insert(14);
	obj.insert(9);
	obj.insert(8);
	obj.display();
	cout << "\n delete root (15):two child case : ";
	obj.del_iterative(15);
	obj.display();
	cout << "\nAfter delete root (9):one child case : ";
	obj.del_iterative(9);
	obj.display();
	cout << "\nAfter delete root (8):no child case : ";
	obj.del_iterative(8);
	obj.display();
	obj.swap();
	obj.display();
	obj.correct();
	cout << "\nAfter correction : ";
	obj.display();
	return 0;

}





