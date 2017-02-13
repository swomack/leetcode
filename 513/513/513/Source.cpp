#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) 
	{
		pair<int, int> res = get_height_value(root);
		return res.second;
	}

	pair<int, int> get_height_value(TreeNode* node)
	{
		if (node->left == NULL && node->right == NULL)
			return { 1, node->val };


		pair<int, int> left_val;
		pair<int, int> right_val;

		if (node->right == NULL)
		{
			left_val = get_height_value(node->left);
			return{ left_val.first + 1, left_val.second };
		}
			
		if (node->left == NULL)
		{
			right_val = get_height_value(node->right);
			return{ right_val.first + 1, right_val.second };
		}

		left_val = get_height_value(node->left);
		right_val = get_height_value(node->right);

		if (right_val.first > left_val.first)
			return{ right_val.first + 1, right_val.second };

		return{ left_val.first + 1, left_val.second };
	}
};

int main()
{
	Solution s;
	return 0;
}