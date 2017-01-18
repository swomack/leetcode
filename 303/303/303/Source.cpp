#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NumArray {
public:

	vector<int> sum;

	NumArray(vector<int> &nums) 
	{
		sum.resize(nums.size() + 1);

		sum[0] = 0;

		for (int i = 0; i < nums.size(); i++)
			sum[i + 1] = sum[i] + nums[i];
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};

int main()
{
	vector<int> param{ -2, 0, 3, -5, 2, -1 };
	NumArray n(param);

	int r = n.sumRange(0, 1);
	r = n.sumRange(0, 2);
	r = n.sumRange(0, 3);
	r = n.sumRange(0, 4);
	r = n.sumRange(0, 5);
	r = n.sumRange(1, 2);
	r = n.sumRange(1, 3);
	r = n.sumRange(1, 5);
	r = n.sumRange(2, 4);
	r = n.sumRange(5, 5);
	r = n.sumRange(4, 5);
	
	return 0;
}