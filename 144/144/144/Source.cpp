#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;

		if (root == NULL)
			return result;

		stack<TreeNode*> stck;
		stck.push(root);

		while (!stck.empty())
		{
			TreeNode* temp = stck.top();
			stck.pop();

			result.push_back(temp->val);

			if (temp->right)
				stck.push(temp->right);

			if (temp->left)
				stck.push(temp->left);
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}