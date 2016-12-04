#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> result;

		if (root == NULL)
			return result;

		vector<string> left_path = binaryTreePaths(root->left);
		vector<string> right_path = binaryTreePaths(root->right);

		for_each(left_path.begin(), left_path.end(), [&root, &result](string element) {
		
			string path = to_string(root->val) + "->" + element;
			result.push_back(path);
		});

		for_each(right_path.begin(), right_path.end(), [&root, &result](string element) {

			string path = to_string(root->val) + "->" + element;
			result.push_back(path);
		});

		if (result.empty())
			result.push_back(to_string(root->val));

		return result;
	}
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);


	vector<string> result = s.binaryTreePaths(root);

	return 0;
}

