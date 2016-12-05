#include <iostream>
#include <queue>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator 
{
private:
	queue<int> next_values;

	void initialize_next_values(TreeNode* root)
	{
		if (root == NULL)
			return;

		initialize_next_values(root->left);
		next_values.push(root->val);
		initialize_next_values(root->right);
	}

public:
	BSTIterator(TreeNode *root) 
	{
		initialize_next_values(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return next_values.empty() == false;
	}

	/** @return the next smallest number */
	int next() 
	{
		int next_value = next_values.front();
		next_values.pop();

		return next_value;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main()
{
	return 0;
}