#include <iostream>
#include <unordered_map>
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
	vector<int> findMode(TreeNode* root) 
	{
		unordered_map<int, int> count;
		vector<int> result;

		
		find_mode(root, count);

		int freq = 0;
		for_each(count.begin(), count.end(), [&result, &freq](pair<int,int> cnt) {
			if (cnt.second == freq)
			{
				result.push_back(cnt.first);
			}
			else if (cnt.second > freq)
			{
				result.clear();
				result.push_back(cnt.first);
				freq = cnt.second;
			}
		});

		return result;

	}


	void find_mode(TreeNode* root, unordered_map<int, int>& count)
	{
		if (root == NULL)
			return;

		count[root->val]++;

		find_mode(root->left, count);
		find_mode(root->right, count);
	}
};

int main()
{
	Solution s;
	return 0;
}