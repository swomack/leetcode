#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
public:
	int numberOfArithmeticSlices(vector<int>& A) 
	{
		if (A.size() < 3)
			return 0;

		int seq_length = 0;
		int end = 1;
		int total_seq = 0;

		while (++end < A.size())
		{
			if (A[end] - A[end - 1] == A[end - 1] - A[end - 2])
			{
				seq_length++;
				total_seq += seq_length; // triangular number
				continue;
			}
			
			seq_length = 0;

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