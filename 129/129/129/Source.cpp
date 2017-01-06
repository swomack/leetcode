#include <iostream>
#include <string>

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
	void leafSum(TreeNode* node, int& path, int& sum)
	{
		if (node == NULL)
			return;

		if (node->left == NULL && node->right == NULL)
		{
			path *= 10;
			path += node->val;
			sum += path;
			path /= 10;
			return;
		}

		path *= 10;
		path += node->val;
		leafSum(node->left, path, sum);
		leafSum(node->right, path, sum);
		path /= 10;
	}

	int sumNumbers(TreeNode* root) 
	{
		int path = 0;
		int result = 0;
		leafSum(root, path, result);
		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}