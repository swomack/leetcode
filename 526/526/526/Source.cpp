#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:

	int countArrangement(int N) 
	{
		vector<bool> track(N, false);

		vector<vector<int>> position(16);

		position[1] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		position[2] = { 1,2,4,6,8,10,12,14 };
		position[3] = { 1,3,6,9,12,15 };
		position[4] = { 1,2,4,8,12 };
		position[5] = { 1,5,10,15 };
		position[6] = { 1,2,3,6,12 };
		position[7] = { 1,7,14 };
		position[8] = { 1,2,4,8 };
		position[9] = { 1,3,9 };
		position[10] = { 1,2,5,10 };
		position[11] = { 1,11 };
		position[12] = { 1,2,3,4,6,12 };
		position[13] = { 1,13 };
		position[14] = { 1,2,7,14 };
		position[15] = { 1,3,5,15 };

		int result = 0;

		backtrack(N, 1, track, position, result);

		return result;
	}

	void backtrack(int N, int R, vector<bool>& track, vector<vector<int>>& pos, int& result)
	{
		if (R > N)
		{
			result++;
			return;
		}

		for (int i = 0; i < pos[R].size() && pos[R][i] <= N; i++)
		{
			if (track[pos[R][i]] == false)
			{
				track[pos[R][i]] = true;
				backtrack(N, R + 1, track, pos, result);
				track[pos[R][i]] = false;
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