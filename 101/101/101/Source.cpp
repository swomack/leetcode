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
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return true;

		if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
			return false;

		if (root->left->val != root->right->val)
			return false;

		queue<TreeNode*> left_queue;
		queue<TreeNode*> right_queue;
		left_queue.push(root->left);
		right_queue.push(root->right);

		while (!left_queue.empty() && !right_queue.empty())
		{
			
			TreeNode* left_node = left_queue.front();
			left_queue.pop();

			TreeNode* right_node = right_queue.front();
			right_queue.pop();

			if (!left_node && !right_node)
				continue;

			if ((left_node && !right_node) || (!left_node && right_node))
				return false;

			if (left_node->val != right_node->val)
				return false;

			// first we will check from the middle to wide
			// this improve performance because of dataset
			left_queue.push(right_node->left);
			left_queue.push(left_node->left);
			right_queue.push(left_node->right);
			right_queue.push(right_node->right);
			
		}

		return true;
	}
};


int main()
{
	Solution s;
	return 0;
}