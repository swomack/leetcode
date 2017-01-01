#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec 
{
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) 
	{
		string serialized;
		if (root == NULL)
			return serialized;

		stack<TreeNode*> stk;
		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* node = stk.top();
			stk.pop();
			if (node->right)
				stk.push(node->right);

			if (node->left)
				stk.push(node->left);

			serialized += to_string(node->val);
			serialized += ",";
		}

		return serialized;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
		stack<TreeNode*> stk;

		char* token;
		token = strtok((char*)(data.c_str()), ",");

		if (!token)
			return NULL;

		TreeNode* root = new TreeNode(stoi(token));
		stk.push(root);

		token = strtok(NULL, ",");
		while (token)
		{
			int value = stoi(token);

			if (value < stk.top()->val)
			{
				TreeNode* left = new TreeNode(value);
				stk.top()->left = left;
				stk.push(left);
			}
			else
			{
				TreeNode* parent = NULL;
				while (!stk.empty() && stk.top()->val < value)
				{
					parent = stk.top();
					stk.pop();
				}
					
				TreeNode* right = new TreeNode(value);
				parent->right = right;
				stk.push(right);
			}

			token = strtok(NULL, ",");
		}

		return root;
	}
};


int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	Codec c;

	TreeNode* res = c.deserialize(c.serialize(root));
	return 0;
}