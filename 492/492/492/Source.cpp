#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> constructRectangle(int area) 
	{
		int l = 0, w = 0;

		w = sqrt(area);

		while (area % w)
			w--;

		l = area / w;

		vector<int> result;
		result.push_back(l);
		result.push_back(w);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}