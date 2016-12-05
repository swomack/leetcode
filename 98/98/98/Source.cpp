#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution
{
public:

	void inOrderTraverse(TreeNode* node, vector<int>& result)
	{
		if (node == NULL)
			return;

		inOrderTraverse(node->left, result);
		result.push_back(node->val);
		inOrderTraverse(node->right, result);
	}

	bool isValidBST(TreeNode* root)
	{
		if (root == NULL)
			return true;

		vector<int> in_order;
		inOrderTraverse(root, in_order);

		for (int i = 0; i < in_order.size() - 1; i++)
		{
			if (in_order[i + 1] <= in_order[i])
				return false;
		}

		return true;
	}
};





int main()
{
	Solution s;
	return 0;
}