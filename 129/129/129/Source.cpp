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
	void leafSum(TreeNode* node, string& path, int& sum)
	{
		if (node == NULL)
			return;

		if (node->left == NULL && node->right == NULL)
		{
			path.push_back('0' + node->val);
			sum += stoi(path);
			path.pop_back();
			return;
		}

		path.push_back('0' + node->val);
		leafSum(node->left, path, sum);
		leafSum(node->right, path, sum);
		path.pop_back();
	}

	int sumNumbers(TreeNode* root) 
	{
		string path;
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