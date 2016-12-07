#include <iostream>
#include <vector>

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
private:
	int treeSize;
public:

	int find_inorder_index(vector<int>& inorder, int data, int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == data)
				return i;
		}

		return -1;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int start, int end)
	{
		if (start > end)
			return NULL;

		int node_index = find_inorder_index(inorder, preorder[treeSize], start, end);
		if (node_index == -1)
			return NULL;

		TreeNode* node = new TreeNode(preorder[treeSize++]);
		node->left = buildTree(inorder, preorder, start, node_index - 1);
		node->right = buildTree(inorder, preorder, node_index + 1, end);
		
		return node;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		treeSize = 0;
		return buildTree(inorder, preorder, 0, preorder.size() - 1);
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);

	vector<int> param1{ 2,1,3,4 };
	vector<int> param2{ 2,4,3,1 };

	TreeNode* res = s.buildTree(param1, param2);

	return 0;
}