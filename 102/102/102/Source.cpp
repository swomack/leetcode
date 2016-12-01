#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> result;
		if (root == NULL)
			return result;

		queue<TreeNode*> level_queue;
		level_queue.push(root);

		while (!level_queue.empty())
		{
			int row_size = level_queue.size();
			vector<int> row;

			while (row_size--)
			{
				TreeNode* node = level_queue.front();
				level_queue.pop();

				row.push_back(node->val);

				if (node->left)
					level_queue.push(node->left);

				if (node->right)
					level_queue.push(node->right);
			}

			result.push_back(row);
		}

		return result;
	}
};


int main()
{
	Solution s;
	return 0;
}