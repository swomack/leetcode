#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

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

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;

		if (root == NULL)
			return result;

		stack<TreeNode*> stck;
		unordered_map<TreeNode*, bool> visited;
		stck.push(root);

		while (!stck.empty())
		{
			TreeNode* top = stck.top();

			if (top->left && visited[top->left] == false)
			{
				stck.push(top->left);
				continue;
			}

			stck.pop();
			result.push_back(top->val);
			visited[top] = true;

			if (top->right)
				stck.push(top->right);
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}