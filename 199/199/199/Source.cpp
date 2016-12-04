#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> result;

		if (root == NULL)
			return result;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();

			TreeNode* last_element;

			while (size--)
			{
				last_element = q.front();
				q.pop();

				if (last_element->left)
					q.push(last_element->left);

				if (last_element->right)
					q.push(last_element->right);
			}
			

				result.push_back(last_element->val);
		}

		return result;
	}
};


int main()
{
	Solution s;
	return 0;
}