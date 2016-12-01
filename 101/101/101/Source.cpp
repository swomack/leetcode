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

		queue<TreeNode*> left_queue;
		queue<TreeNode*> right_queue;
		left_queue.push(root->left);
		right_queue.push(root->right);

		while (!left_queue.empty() && !right_queue.empty())
		{
			int left_size = left_queue.size();
			int right_size = right_queue.size();
			
			if (left_size != right_size)
			{
				result = false;
				break;
			}

			while (left_size--)
			{
				TreeNode* left_node = left_queue.front();
				left_queue.pop();

				TreeNode* right_node = right_queue.front();
				right_queue.pop();

				if (!left_node && !right_node)
					continue;

				if ((left_node && !right_node) || (!left_node && right_node))
				{
					result = false;
					break;
				}

				if (left_node->val != right_node->val)
				{
					result = false;
					break;
				}

				left_queue.push(left_node->left);
				left_queue.push(right_node->left);
				right_queue.push(right_node->right);
				right_queue.push(left_node->right);
			}

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