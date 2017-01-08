#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:

	vector<int> build_version(string& version)
	{
		vector<int> res;

		int index = 0;
		int cumul = 0;
		while (index < version.length())
		{
			if (version[index] == '.')
			{
				res.push_back(cumul);
				cumul = 0;
			}
			else
			{
				cumul *= 10;
				cumul += (version[index] - '0');
			}

			index++;
		}

		if (version[index - 1] != '.')
			res.push_back(cumul);

		
		return res;

	}

	int compareVersion(string version1, string version2) 
	{
		vector<int> v1 = build_version(version1);
		vector<int> v2 = build_version(version2);

		if (v1.size() > v2.size())
			v2.resize(v1.size());
		else
			v1.resize(v2.size());

		int index1 = 0;
		int index2 = 0;

		while (index1 < v1.size() && index2 < v2.size())
		{
			if (v1[index1] > v2[index2])
				return 1;
			else if (v1[index1] < v2[index2])
				return -1;

			index1++;
			index2++;
		}

		if (v1.size() == v2.size())
			return 0;
		else if (v1.size() > v2.size())
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	Solution s;
	int res = s.compareVersion("1", "1.0");
	return 0;
}