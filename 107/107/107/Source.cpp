#include <iostream>
#include <vector>
#include <list>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) 
	{
		vector<vector<int>> result;

		if (root == NULL)
			return result;

		queue<TreeNode*> level_queue;

		level_queue.push(root);

		while (!level_queue.empty())
		{
			int level_size = level_queue.size();

			vector<int> this_level;

			while (level_size--)
			{
				TreeNode* level_element = level_queue.front();
				level_queue.pop();

				this_level.push_back(level_element->val);

				if (level_element->left)
					level_queue.push(level_element->left);

				if (level_element->right)
					level_queue.push(level_element->right);
			}

			result.push_back(this_level);
		}

		reverse(result.begin(), result.end());

		return result;

	}
};

int main()
{
	Solution s;
	return 0;
}