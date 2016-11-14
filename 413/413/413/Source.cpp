#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
public:
	int numberOfArithmeticSlices(vector<int>& A) 
	{
		if (A.size() == 0)
			return 0;

		int start = 0;
		int end = 1;

		int diff = A[end] - A[start];
		int total_seq = 0;

		while (true)
		{
			end++;

			if (end >= A.size())
				break;

			if (A[end] - A[end - 1] == diff)
			{
				continue;
			}
			else
			{
				int length = end - 1 - start;
				length -= 1;
				if (length >= 1)
				{
					total_seq += ((length * (length + 1)) / 2);
				}
				
				start = end - 1;
				diff = A[end] - A[start];
			}
		}

		int length = end - start;
		length -= 2;
		if (length >= 1)
		{
			total_seq += ((length * (length + 1)) / 2);
		}

		return total_seq;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.push_back(9);
	int total_seq = s.numberOfArithmeticSlices(v);
	cout << total_seq;
	getchar();
}