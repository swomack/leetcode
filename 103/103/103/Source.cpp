#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int>> result;

		if (root == NULL)
			return result;

		stack<TreeNode*> nodes;
		queue<TreeNode*> helper;

		nodes.push(root);

		int turn = 0;

		while (!nodes.empty())
		{
			
			vector<int> row;
			

			while (!nodes.empty())
			{
				row.push_back(nodes.top()->val);
				helper.push(nodes.top());
				nodes.pop();
			}

			result.push_back(row);

			if (turn % 2)
			{
				while (!helper.empty())
				{
					if (helper.front()->right)
					{
						nodes.push(helper.front()->right);

					}
					if (helper.front()->left)
					{
						nodes.push(helper.front()->left);
					}
					helper.pop();
				}
			}
			else
			{
				while (!helper.empty())
				{
					if (helper.front()->left)
					{
						nodes.push(helper.front()->left);
						
					}
					if (helper.front()->right)
					{
						nodes.push(helper.front()->right);
					}
					helper.pop();
				}
			}

			turn++;
		}


		return result;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(15);
	root->left->right = new TreeNode(7);

	vector<vector<int>> result = s.zigzagLevelOrder(root);
	return 0;
}