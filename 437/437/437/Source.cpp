#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


	int addValue(vector<int>& path, int sum)
	{
		int local_sum = 0;
		int count = 0;

		for (int i = path.size() - 1; i >= 0; i--)
		{
			local_sum += path[i];

			if (local_sum == sum)
				count++;
		}

		return count;
	}

	void pathSum(TreeNode* node, vector<int>& path, int& count, int sum)
	{
		if (node == NULL)
			return;

		path.push_back(node->val);

		count += addValue(path, sum);

		pathSum(node->left, path, count, sum);
		pathSum(node->right, path, count, sum);
		path.pop_back();
	}

	int pathSum(TreeNode* root, int sum) {
		int count = 0;
		vector<int> path;

		pathSum(root, path, count, sum);

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}