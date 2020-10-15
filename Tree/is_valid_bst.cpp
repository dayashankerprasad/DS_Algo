#include <iostream>
#include <vector>

using namespace std;

class BinaryTree
{
public:
	int32_t value;
	BinaryTree *left{nullptr};
	BinaryTree *right{nullptr};

	BinaryTree(int32_t valueArgs, BinaryTree *leftArgs=nullptr, BinaryTree *rightArgs=nullptr): value(valueArgs), left(leftArgs), right(rightArgs)
	{
	}
};

BinaryTree * insertBST(BinaryTree *root, int32_t data)
{
	if (root == nullptr)
		return new BinaryTree(data);;

	if (data < root->value)
		if (root->left != nullptr)
			root->left = insertBST(root->left, data);
	else if (data > root->value)
		if (root->right != nullptr)
			root->right = insertBST(root->right, data);
	
	return root;
}

int maxValue(BinaryTree *tree)
{
	int val = 0;
	for(; tree != nullptr; tree = tree->right)
		val = tree->value;
	return val;
}

int minValue(BinaryTree *tree)
{
	int val = 0;
	for(; tree != nullptr; tree = tree->left)
		val = tree->value;
	return val;
}

bool validateBst(BinaryTree *tree) 
{
	if (tree != nullptr)
	{
		bool flag = true;
		
		if (tree->right != nullptr)
			flag &= (minValue(tree->right) >= tree->value);
		if (tree->left != nullptr)
			flag &= (maxValue(tree->left) < tree->value);

		return flag && validateBst(tree->left) && validateBst(tree->right);
	}

  return true;
}

BinaryTree * createBST(vector<int> const values)
{
	BinaryTree *root = nullptr;
	for(auto const &v: values)
		root = insertBST(root, v);
	return root;
}

int32_t main()
{
	BinaryTree *tree1 = createBST({10, 15, 22, 13, 2, 5, 6, 1, 14});
	cout << "Valid: " << validateBst(tree1) << endl;

	BinaryTree *root = new BinaryTree(12);
	root->left = new BinaryTree(5);
	root->right = new BinaryTree(15);
	root->left->right = new BinaryTree(13);
	
	cout << "Valid: " << validateBst(root) << endl;
	
	return 0;
}

