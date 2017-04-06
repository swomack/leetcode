#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:

	int countArrangement(int N) 
	{
		vector<bool> track(N, false);


		int result = 0;

		backtrack(N, 1, track, result);

		return result;
	}

	void backtrack(int N, int R, vector<bool>& track, int& result)
	{
		if (R > N)
		{
			result++;
			return;
		}

		for (int i = 1; i <= N; i++)
		{
			if ((i % R == 0 || R % i == 0) && track[i] == false)
			{
				track[i] = true;
				backtrack(N, R + 1, track, result);
				track[i] = false;
			}
		}
	}
};

int main()
{
	Solution s;
	int count = s.countArrangement(2);

	cout << count << endl;

	return 0;
}