#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int32_t value;
	TreeNode *left{nullptr};
	TreeNode *right{nullptr};

	TreeNode(int32_t valueArgs, TreeNode *leftArgs=nullptr, TreeNode *rightArgs=nullptr)
		: value{valueArgs}, left{leftArgs}, right{rightArgs}
	{
	}
};

void printDLL(TreeNode *root)
{
	TreeNode *lastNode = nullptr;
	for (TreeNode *cur = root; cur != nullptr; lastNode = cur, cur = cur->right)
		cout << cur->value << " ";

	cout << "\n";

	for (; lastNode != nullptr; lastNode = lastNode->left)
		cout << lastNode->value << " ";
}

void inorder(TreeNode *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}
}

namespace approach1
{

TreeNode * flatten2DLL(TreeNode *root)
{
	if (root == nullptr)
		return nullptr;

	if (root->left == nullptr && root->right == nullptr)
		return root;

	TreeNode *leftTree = flatten2DLL(root->left);
	TreeNode *rightTree = flatten2DLL(root->right);

	root->left = nullptr;

	if (leftTree != nullptr)
	{
		root->right = leftTree;
		leftTree->left = root;

		for (; leftTree->right != nullptr; leftTree = leftTree->right);
		leftTree->right = rightTree;
	}

	if (rightTree != nullptr)
	{
		rightTree->left = (leftTree == nullptr ? root : leftTree);
		for (; rightTree->right != nullptr; rightTree = rightTree->right);
		rightTree->right = nullptr;
	}

	return root;
}

}

namespace approach2
{

void flatten2DLL(TreeNode* root)
{
	if(root == nullptr)
		return;

	stack<TreeNode*> stack;

	if(root->right)
		stack.push(root->right);

	if(root->left)
		stack.push(root->left);

	TreeNode *node = root;
	node->left = nullptr;

	while(!stack.empty())
	{
		TreeNode *curr = stack.top();
		stack.pop();

		node->right = curr;

		if(curr->right)
			stack.push(curr->right);

		if(curr->left)
			stack.push(curr->left);

		curr->left = node;
		node = node->right;
	}
}

}

int32_t main()
{
	/*
	 *       1
	 *     /   \
	 *   2       5
	 *  / \       \
	 * 3   4       6
	 * 
	 * DLL => 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
	 */
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);

	inorder(root);
	cout << "\n";

	approach2::flatten2DLL(root); //approach1::flatten2DLL(root); both result the same
	printDLL(root);

	cout << endl;
	return 0;
}
