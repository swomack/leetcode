#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> countBits(int num) 
	{
		vector<int> results;

		for (int i = 0; i <= num; i++)
		{
			// check hamming wieght and built-in pop count
			results.push_back(__builtin_popcountll(i));
		}

		return results;
	}
};

int main()
{
	Solution s;
	vector<int> bits = s.countBits(15);

	for_each(bits.begin(), bits.end(), [](int& element) {
		cout << element << endl;
	});

	getchar();
	return 0;
}