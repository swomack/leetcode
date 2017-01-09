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

		char* pch = strtok((char*)version.c_str(), ".");

		while (pch)
		{
			res.push_back(atoi(pch));
			pch = strtok(NULL, ".");
		}

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

		for (int index = 0; index < v1.size(); index++)
		{
			if (v1[index] == v2[index])
				continue;

			if (v1[index] > v2[index])
				return 1;
			else if (v1[index] < v2[index])
				return -1;
		}

		return 0;
	}
};

int main()
{
	Solution s;
	int res = s.compareVersion("1", "1.0");
	return 0;
}