#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* paren;
public:
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
		paren = NULL;
	}

};
void preorder(Node* temp) {
	if (temp != 0) {
		cout << temp->data << "  ";
		preorder(temp->right);
		preorder(temp->left);
	}
}
int height(Node* temp) {
	if (temp->paren != 0)
		return 1 + height(temp->paren);
	else 
		return 0;
}
bool iscousin(Node* temp1,Node*temp2) {
	if (temp1->paren == temp2->paren)
		return false;
	else if (height(temp1) != height(temp2))
		return false;
	return true;
}

int main()
{
	Node* root = NULL;
	root = new Node(6);
    root->left = new Node(3);
	root->left->paren = root;
	root->right = new Node(5);
	root->right->paren = root;
	root->left->left = new Node(7);
	root->left->left->paren = root->left;
	root->left->right = new Node(8);
	root->left->right->paren = root->left;
	root->right->left = new Node(1);
	root->right->left->paren = root->right;
	root->right->right = new Node(12);
	root->right->right->paren = root->right;
	cout << "\nPreorder  :   ";
	preorder(root);
	if (iscousin(root->left->left, root->right->right) == true)
		cout << "\nGiven nodes are cousins";
	else
		cout << "\nGiven nodes are not cousins";
	system("pause");
	return 0;
}
