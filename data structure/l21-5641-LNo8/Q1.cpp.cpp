#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}

};
void preorder(Node* temp) {
	if (temp != 0) {
		cout << temp->data << "  ";
		preorder(temp->right);
		preorder(temp->left);
	}
}
void inorder(Node* temp) {
	if (temp != 0) {
		inorder(temp->left);
		cout << temp->data << "  ";
		inorder(temp->right);
	}
}

void postorder(Node* temp) {
	if (temp != 0) {
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << "  ";
	}
}
void getdeep(Node* temp,Node*& cur,Node*&c1) {
	if (temp->left != 0 || temp->right != 0) {
		getdeep(temp->left, cur,temp);
		getdeep(temp->right, cur,temp);
	}
	else {
		cur = temp;
	}
}
int deletenode(Node* temp, int n) {
	if (temp != 0) {
		if (temp->data == n) {
			Node* k;
			Node* k1;
			getdeep(temp,k,k1);
			cout << k->data;
			temp->data = k->data;
			delete[]k;
			return 1;
		}
	    else if (temp->left != 0) {
			if (temp->left->data == n) {
				Node* k = temp->left->right;
				Node* cur = temp->left;
				temp->left = cur->left;
				delete[]cur;
				temp->left->right = k;
				return 1;
			}
		}
		else if (temp->right != 0) {
			if (temp->right->data == n) {
				Node* k = temp->right->left;
				Node* cur = temp->right;
				temp->right = cur->right;
				delete[]cur;
				temp->right->left = k;
				return 1;
			}
		}
		int l=deletenode(temp->left, n);
		if(l!=1)
		  deletenode(temp->right, n);
	}
}
bool searchnode(Node* temp, int n) {
	if (temp != 0) {
		if (temp->data == n)
			return true;
		bool t = searchnode(temp->left, n);
		if (t != true)
			t = searchnode(temp->right, n);
		return t;
	}
	else
		return false;

}
int levelorder(Node* temp) {
	if (temp != 0) {
		int i = 0, j = 0;
		i = i + levelorder(temp->left);
		j = j + levelorder(temp->right);
		if (i > j)
			return i;
		else
			return j;
	}
	else
		return 1;
}
int main()
{
	Node* k;
	Node* root = NULL;
	root = new Node(6);
	root->left = new Node(3);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(1);
	root->right->right = new Node(12);
	cout << "\nPreorder  :   ";
	preorder(root);
	cout << "\nPostorder  :   ";
	postorder(root);
	cout << "\ninorder  :   ";
	inorder(root);
	int h;
	cout << "\nEnter number you want to search in tree : ";
	cin >> h;
	if (searchnode(root, h) == true)
		cout << "\nNumber is found ";
	else
		cout << "\nNumber is not found ";
	cout << "\nEnter number you want to delete in tree : ";
	cin >> h;
//	deletenode(root, h);
	cout << "\n node is deleted";
	cout << "\nAfter delete inorder : ";
	inorder(root);
	h = levelorder(root);
	cout << "\n Level order traversal of given  tree node is  : " << h;
	cout << endl;
	system("pause");
	return 0;
}
