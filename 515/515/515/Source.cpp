#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

	int find_max(vector<int>&& arr)
	{
		int m = arr[0];

		for (int i = 1; i < arr.size(); i++)
			m = max(m, arr[i]);

		return m;
	}

	vector<int> largestValues(TreeNode* root) 
	{
		vector<int> res;

		if (root == NULL)
			return res;

		queue<TreeNode*> levels;
		levels.push(root);

		while (!levels.empty())
		{
			vector<int> values;

			int level_size = levels.size();

			while (level_size--)
			{
				TreeNode* top = levels.front();
				levels.pop();

				values.push_back(top->val);

				if (top->left)
					levels.push(top->left);

				if (top->right)
					levels.push(top->right);
			}

			res.push_back(find_max(move(values)));
		}

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}