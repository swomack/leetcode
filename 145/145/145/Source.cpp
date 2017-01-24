#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>


using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> result;

		if (root == NULL)
			return result;

		stack<TreeNode*> nodes;
		unordered_map<TreeNode*, bool> map;
		map[NULL] = true;

		nodes.push(root);

		while (!nodes.empty())
		{
			TreeNode* n = nodes.top();

			if (map[n->left] && map[n->right])
			{
				map[n] = true;
				result.push_back(n->val);
				nodes.pop();
				continue;
			}

			if (n->right)
				nodes.push(n->right);

			if (n->left)
				nodes.push(n->left);
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}