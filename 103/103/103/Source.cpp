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

		queue<TreeNode*> nodes;
		nodes.push(root);

		int turn = 0;

		while (!nodes.empty())
		{
			turn++;
			int size = nodes.size();
			vector<int> row(size);
			
			bool increment = turn % 2 ? true : false;
			int index = increment ? 0 : size - 1;
			
			while (size--)
			{
				TreeNode* temp = nodes.front();
				row[index] = temp->val;
				nodes.pop();

				if (temp->left)
					nodes.push(temp->left);

				if (temp->right)
					nodes.push(temp->right);

				increment ? index++ : index--;
			}

			result.push_back(row);
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