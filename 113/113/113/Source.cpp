#include <iostream>
#include <vector>
#include <algorithm>

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

	vector<vector<int>> pathSumHelper(TreeNode* root, int sum)
	{
		vector<vector<int>> result;

		if (root == NULL)
			return result;

		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->val)
			{
				vector<int> res;
				res.push_back(root->val);
				result.push_back(res);
			}

			return result;
		}

		vector<vector<int>> left_result = pathSumHelper(root->left, sum - root->val);
		vector<vector<int>> right_result = pathSumHelper(root->right, sum - root->val);

		for (int i = 0; i < left_result.size(); i++)
		{
			vector<int> path = left_result[i];
			path.push_back(root->val);
			result.push_back(path);
		}
		left_result.clear();

		for (int i = 0; i < right_result.size(); i++)
		{
			vector<int> path = right_result[i];
			path.push_back(root->val);
			result.push_back(path);
		}

		right_result.clear();
		
		return result;
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> result = pathSumHelper(root, sum);

		for (int i = 0; i < result.size(); i++)
		{
			reverse(result[i].begin(), result[i].end());
		}

		return result;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	vector<vector<int>> result = s.pathSum(root, 22);

	getchar();
	return 0;
}