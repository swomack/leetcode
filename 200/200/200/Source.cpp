#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:

	struct node
	{
		int i, j;

		node* parent;
		int rank;

		node(int a, int b) : i(a), j(b), parent(this), rank(0)
		{
		}
	};


	node* make_set(int i, int j)
	{
		node* n = new node(i, j);
		return n;
	}


	node* find(node* x)
	{
		if (x != x->parent)
			x->parent = find(x->parent);

		return x->parent;
	}

	bool link(node* a, node* b)
	{
		if (a == b)
			return false;

		if (a->rank > b->rank)
		{
			b->parent = a;
		}
		else
		{
			a->parent = b;

			if (a->rank == b->rank)
				a->rank++;
		}

		return true;
	}

	bool union_set(node* a, node* b)
	{
		return link(find(a), find(b));
	}

	int numIslands(vector<vector<char>>& grid) 
	{
		int islands = 0;
		

		int row = grid.size();

		if (row == 0)
			return islands;

		int col = grid[0].size();

		if (col == 0)
			return islands;


		unordered_map<int, node*> sets;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1')
				{
					int key = i * col + j;
					sets[key] = make_set(i, j);
					islands++;
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1')
				{
					int fragment_key = i * col + j;

					if (j + 1 < col && grid[i][j + 1] == '1')
					{
						int key = i * col + (j + 1);
						if (union_set(sets[fragment_key], sets[key]))
							islands--;
					}

					if (i + 1 < row && grid[i + 1][j] == '1')
					{
						int key = (i + 1) * col + j;
						if (union_set(sets[fragment_key], sets[key]))
							islands--;
					}

				}
			}
		}

		return islands;
	}
};

int main()
{
	Solution s;
	return 0;
}