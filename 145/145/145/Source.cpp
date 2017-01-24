#include <iostream>
#include <stack>
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
		nodes.push(root);

		while (!nodes.empty())
		{
			TreeNode* n = nodes.top();
			nodes.pop();

			result.push_back(n->val);
			
			if (n->left)
				nodes.push(n->left);

			if (n->right)
				nodes.push(n->right);
		}

		reverse(result.rbegin(), result.rend());

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}