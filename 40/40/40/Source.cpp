#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		return combinationSumHelper(candidates, target, 0, candidates.size() - 1);
	}

	vector<vector<int>> combinationSumHelper(vector<int>& candidates, int target, int st, int fn)
	{
		vector<vector<int>> results;

		if (target < 0)
			return results;

		for (int i = st; i <= fn; i++)
		{
			if (i > st && candidates[i] == candidates[i-1])
				continue;
			if (target - candidates[i] == 0)
			{
				vector<int> fin_res;
				fin_res.push_back(target);
				results.push_back(fin_res);
			}
			else
			{
				vector<vector<int>> child_res = combinationSumHelper(candidates, target - candidates[i], i + 1, fn);

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