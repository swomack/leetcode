#include <iostream>
#include <queue>
#include<vector>

using namespace std;

struct TreeLinkNode {
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

		queue<TreeLinkNode*> bfs;
		bfs.push(root);

		while (!bfs.empty())
		{
			vector<TreeLinkNode*> collect;

			while (bfs.size() > 1)
			{
				TreeLinkNode* top = bfs.front();
				bfs.pop();

				collect.push_back(top);

				top->next = bfs.front();
			}

			collect.push_back(bfs.front());
			bfs.pop();


			for (int i = 0; i < collect.size(); i++)
			{
				if (collect[i]->left)
					bfs.push(collect[i]->left);

				if (collect[i]->right)
					bfs.push(collect[i]->right);
			}
		}
	}
};

int main()
{
	Solution s;
	return 0;
}