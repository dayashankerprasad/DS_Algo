/**
 * Write a function that takes in a binrary tree and returns a list of its branch sums ordered
 * from letfmost branch to rightmost branch sum
 *            1
 *           / \
 *          /   \
 *         /     \
 *        /       \
 *       /         \
 *      2           3
 *     / \         / \
 *    4   5       6   7
 *   / \   \
 *  8   9   10
 *
 * sum = [1+2+4+8, 1+2+4+9, 1+2+5+10, 1+3+6, 1+3+7] = [15, 16, 18, 10, 11]
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &obj)
{
	for(T const &val: obj)
		out << val << " ";
	return out;
}

class BinaryTree
{
public:
	int32_t value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int32_t valueArgs, BinaryTree *leftArgs=nullptr, BinaryTree *rightArgs=nullptr): value(valueArgs), left(leftArgs), right(rightArgs)
	{
	}
};

void preorder(BinaryTree *root, vector<int> &sums, int currentSum=0)
{
	if (root == nullptr)
		return;

	currentSum += root->value;

	if (root->left == nullptr && root->right == nullptr)
		sums.push_back(currentSum);

	preorder(root->left, sums, currentSum);
	preorder(root->right, sums, currentSum);
}

vector<int> branchSums(BinaryTree *root)
{
	vector<int> sums;

	preorder(root, sums);

	return sums;
}

BinaryTree * createTree()
{
	BinaryTree *root = new BinaryTree(1);
	root->left = new BinaryTree(2);
	root->right = new BinaryTree(3);

	root->left->left = new BinaryTree(4);
	root->left->right = new BinaryTree(5);

	root->left->left->left = new BinaryTree(8);
	root->left->left->right = new BinaryTree(9);

	root->left->right->left = new BinaryTree(10);

	root->right->left = new BinaryTree(6);
	root->right->right = new BinaryTree(7);

	return root;
}

int main()
{
	BinaryTree *root = createTree();
	cout << "Branch sum = " << branchSums(root);
	cout << "\nTerminating main()..." << endl;

	return 0;
}

