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

	int fill_map(TreeNode* node, unordered_map<int, int>& sum_map, vector<int>& result, int& max_value)
	{
		if (node == NULL)
			return 0;

		int sum = node->val + fill_map(node->left, sum_map, result, max_value) + fill_map(node->right, sum_map, result, max_value);

		sum_map[sum]++;

		if (sum_map[sum] == max_value)
		{
			result.push_back(sum);
		}
		else if (sum_map[sum] > max_value)
		{
			result.clear();
			result.push_back(sum);
			max_value = sum_map[sum];
		}

		return sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) 
	{
		int max_value = 0;
		unordered_map<int, int> map;
		vector<int> result;
		fill_map(root, map, result, max_value);
		return result;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(2);
	/*root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(1);*/
	root->right = new TreeNode(-3);
	/*root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(6);*/

	vector<int> res = s.findFrequentTreeSum(root);

	return 0;
}