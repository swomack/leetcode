#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:

	void backtrackMinute(int number, int current_one, int total_one, int considered_bit, vector<string>& minutes)
	{
		if (current_one > total_one || number > 59)
			return;

		if (considered_bit < 0)
		{
			if (current_one == total_one)
			{
				string ss;

				ss.push_back((number / 10) + '0');
				ss.push_back((number % 10) + '0');

				minutes.push_back(ss);
			}
			

			return;
		}

		backtrackMinute(number, current_one, total_one, considered_bit - 1, minutes);
		backtrackMinute(number | (1 << considered_bit), current_one + 1, total_one, considered_bit - 1, minutes);
	}

	void backtrackHour(int number, int current_one, int total_one, int considered_bit, vector<string>& result)
	{
		if (current_one > total_one || number > 11)
			return;

		if (considered_bit < 0)
		{
			vector<string> minutes;

			backtrackMinute(0, 0, total_one - current_one, -1, minutes);

			for (int i = 5; i >= 0; i--)
			{
				int number = (1 << i);
				backtrackMinute(number, 1, total_one - current_one, i - 1, minutes);
			}
			

			string ss;
			if (number / 10)
				ss.push_back((number / 10) + '0');

			ss.push_back((number % 10) + '0');
			ss.push_back(':');

			for (int i = 0; i < minutes.size(); i++)
			{
				ss.push_back(minutes[i][0]);
				ss.push_back(minutes[i][1]);

				result.push_back(ss);

				ss.pop_back();
				ss.pop_back();
			}

			return;
		}
		
		backtrackHour(number, current_one, total_one, considered_bit - 1, result);
		backtrackHour(number | (1 << considered_bit), current_one + 1, total_one, considered_bit - 1, result);
	}

	vector<string> readBinaryWatch(int num) 
	{
		vector<string> result;

		if (num == 0)
		{
			result.push_back("0:00");
			return result;
		}

		backtrackHour(0, 0, num, -1, result);

		for (int i = 3; i >= 0; i--)
		{
			int number = (1 << i);
			backtrackHour(number, 1, num, i - 1, result);
		}
		

		return result;
	}
};

int main()
{
	Solution s;

	vector<string> res = s.readBinaryWatch(2);

	return 0;
}