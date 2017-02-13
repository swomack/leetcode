#include <iostream>
#include <queue>

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
	vector<int> largestValues(TreeNode* root) 
	{
		vector<int> res;

		if (root == NULL)
			return res;

		queue<TreeNode*> levels;

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}