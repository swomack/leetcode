#include <iostream>
#include <vector>


using namespace std;

struct TreeNode
{
	int val;
	int total_left_element;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), total_left_element(0), left(NULL), right(NULL) {}

	void insertLeft(int value)
	{
		this->left = new TreeNode(value);
		total_left_element++;
	}

	void insertRight(int value)
	{
		this->right = new TreeNode(value);
	}
};

class Solution 
{
public:


	int kthSmallest(TreeNode* root, int k) 
	{
		if (root->total_left_element == k - 1)
			return root->val;

		if (root->total_left_element > k - 1)
			return kthSmallest(root->left, k);
		else
			return kthSmallest(root->right, k - root->total_left_element + 1);
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);

	int val = s.kthSmallest(root, 1);

	return 0;
}