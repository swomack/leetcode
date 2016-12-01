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
	bool isSymmetric(TreeNode* root)
	{
		bool result = true;
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return result;

		queue<TreeNode*> level_queue;
		level_queue.push(root->left);
		level_queue.push(root->right);

		while (!level_queue.empty())
		{
			int row_size = level_queue.size();
			vector<TreeNode*> row;

			while (row_size--)
			{
				TreeNode* node = level_queue.front();
				level_queue.pop();

				row.push_back(node);

				if (node)
				{
					level_queue.push(node->left);
					level_queue.push(node->right);
				}
			}

			if (row.size() % 2)
			{
				result = false;
				break;
			}

			bool symmetric = true;
			for (int i = 0, j = row.size() - 1; i < j; i++, j--)
			{
				if (row[i] && row[j])
				{
					if (row[i]->val == row[j]->val)
						continue;

					symmetric = false;
					break;
				}
				else
				{
					if (row[i] == NULL && row[j] == NULL)
						continue;

					symmetric = false;
					break;
				}
			}

			result = symmetric;

			if (!result)
				break;
		}

		return result;
	}
};


int main()
{
	Solution s;
	return 0;
}