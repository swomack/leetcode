#include <iostream>


using namespace std;


struct TreeLinkNode 
{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) 
	{
		if (root == NULL)
			return;

		connect(root->left, root->right);
	}

	void connect(TreeLinkNode* a, TreeLinkNode* b)
	{
		if (!a || !b)
			return;

		a->next = b;

		
		connect_middle(a->right, b->left);
		connect(a->left, a->right);
		connect(b->left, b->right);
	}

	void connect_middle(TreeLinkNode* a, TreeLinkNode* b)
	{
		if (!a || !b)
			return;

		a->next = b;

		connect_middle(a->right, b->left);
	}
};


int main()
{
	Solution s;
	return 0;
}