#include <iostream>
#include <vector>
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

	int max_value;

	int fill_map(TreeNode* node, unordered_map<int, int>& sum_map)
	{
		if (node == NULL)
			return 0;

		int sum = node->val + fill_map(node->left, sum_map) + fill_map(node->right, sum_map);

		sum_map[sum]++;

		if (sum_map[sum] > max_value)
			max_value = sum_map[sum];

		return sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) 
	{
		max_value = 0;
		unordered_map<int, int> map;
		fill_map(root, map);

		vector<int> result;

		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			if (it->second == max_value)
				result.push_back(it->first);
		}

		return result;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(1);
	root->right = new TreeNode(-3);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(6);

	vector<int> res = s.findFrequentTreeSum(root);

	return 0;
}