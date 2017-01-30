#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



class Solution 
{
private:
	struct element
	{
		int value;
		int rank;
		int total_element;
		element* parent;

		element(int val) : value(val), parent(this), rank(0), total_element(1)
		{
		}
	};
public:

	element* make_set(int value)
	{
		element* elem = new element(value);
		return elem;
	}

	element* find_set(element* x)
	{
		if (x->parent != x)
			x->parent = find_set(x->parent);

		return x->parent;
	}

	int union_set(element* x, element* y)
	{
		return link_set(find_set(x), find_set(y));
	}

	int link_set(element* x, element* y)
	{
		if (x == y)
			return x->total_element;
		if (x->rank > y->rank)
		{
			y->parent = x;
			x->total_element += y->total_element;
			return x->total_element;
		}
		else
		{
			x->parent = y;
			y->total_element += x->total_element;

			if (x->rank == y->rank)
				y->rank++;

			return y->total_element;
		}
	}

	int longestConsecutive(vector<int>& nums) 
	{
		if (nums.size() <= 0)
			return 0;

		int length = 1;
		unordered_map<int, element*> map;

		for (int i = 0; i < nums.size(); i++)
		{
			if (map[nums[i]] == NULL)
				map[nums[i]] = make_set(nums[i]);

			if(map[nums[i] - 1] != NULL)
				length = max(length, union_set(map[nums[i]], map[nums[i] - 1]));

			if (map[nums[i] + 1] != NULL)
				length = max(length, union_set(map[nums[i]], map[nums[i] + 1]));
		}

		return length;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 100,4,200,1,3,2 };
	int val = s.longestConsecutive(param);
	return 0;
}