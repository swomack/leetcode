#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<int> param{ 1,2,3,4,5,6,7,8,9 };
		return combinationSumHelper(param, n, 0, 9, k);
	}

	vector<vector<int>> combinationSumHelper(vector<int>& candidates, int target, int st, int fn, int k)
	{
		vector<vector<int>> results;

		if (k == 0)
			return results;

		if (target < 0)
			return results;

		for (int i = st; i <= fn; i++)
		{
			if (target - candidates[i] == 0)
			{
				if (k == 1)
				{
					vector<int> fin_res;
					fin_res.push_back(target);
					results.push_back(fin_res);
				}
			}
			else
			{
				vector<vector<int>> child_res = combinationSumHelper(candidates, target - candidates[i], i + 1, fn, k - 1);

				int n = candidates[i];

				for_each(child_res.begin(), child_res.end(), [&results, &n](vector<int> elem) {

					if (elem.size() > 0)
					{
						elem.push_back(n);
						results.push_back(elem);
					}

				});
			}

		}

		return results;
	}
};

int main()
{
	Solution s;
	return 0;
}