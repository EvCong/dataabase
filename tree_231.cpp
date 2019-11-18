#include "iostream";
using namespace std;
/*
ͨ�������������������,����111��ڵ�Ϊ��,��������������.
*/
struct Node_tree
{	
	Node_tree* right;
	Node_tree* left;
	int data;
};
Node_tree * create_tree() {
	Node_tree* p;
	int num;
	cin >> num;
	cout << "" << endl;
	if (num == 111) {
		p = nullptr;
	}
	else {
		p = new Node_tree;
		p->data = num;
		p->left = create_tree();
		p->right = create_tree();
	}
	return p;//�ʼ�Ľڵ�
}
void Traverse_Pre(Node_tree* root) {
	if (root) {
		cout << root->data << ' ';
		Traverse_Pre(root->left);
		Traverse_Pre(root->right);
	}
}
Node_tree* copy_tree(Node_tree * root) {
	Node_tree* root_copy;
	if (root == nullptr) {
		return nullptr;
	}
	else {
		root_copy = new Node_tree;
		root_copy->data = root->data;
		root_copy->left = copy_tree(root->left);
		root_copy->right = copy_tree(root->right);
		return root_copy;
	}
}
int Depth_tree(Node_tree * root) {
	if (root) {
		return Depth_tree(root->left) > Depth_tree(root->right)
			? Depth_tree(root->left) + 1 : Depth_tree(root->right) + 1;
	}
	else if (root == nullptr) {
		return 0;
	}
}
int Num_Leaf(Node_tree* root) {
	if (!root) {
		return 0;
	}else if ((root->left==nullptr)&&(root->right==nullptr)) {
		return 1;
	}
	else {
		return (Num_Leaf(root->left) + Num_Leaf(root->right));
	}
}
bool Identical_tree(Node_tree* tree_one, Node_tree* tree_two) {
	if (!tree_one || !tree_two) {
		return false;
	}
	if (!tree_one && !tree_two) {
		return true;
	}
	if (tree_one->data == tree_two->data) {
		return Identical_tree(tree_one->left,tree_two->left)&&Identical_tree(tree_one->right,tree_two->right);
	}
	else {
		return false;
	}
}
int main() {
	Node_tree* root = nullptr;
	Node_tree* root_copy = nullptr;
	Node_tree* root_two = nullptr;
	cout << "����һ��������" << endl;
	root = create_tree();
	cout << endl;
	cout << "����������" << endl;
	Traverse_Pre(root);
	cout << endl;
	cout << "���Ϊ:" << Depth_tree(root)<<endl;
	cout << "Ҷ����ĿΪ:" << Num_Leaf(root) << endl;
	cout << "���Ƹö�����" << endl;
	root_copy = copy_tree(root);
	Traverse_Pre(root_copy);
	cout << endl;
	cout << "������һ��������" << endl;
	root_two = create_tree();
	cout << "���Ϊ:" << Depth_tree(root_two) << endl;
	cout << "Ҷ����ĿΪ:" << Num_Leaf(root_two) << endl;
	cout << "��ǰ���Ƿ����" << " "<<Identical_tree(root_two, root);

	return 0;
}