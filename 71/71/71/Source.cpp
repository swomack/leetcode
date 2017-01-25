#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string simplifyPath(string path) 
	{
		stack<char*> paths;

		char* pch = strtok((char*) path.c_str(), "/");

		while (pch)
		{
			if (strcmp(pch, "..") == 0)
			{
				if(!paths.empty())
					paths.pop();
			}
			else if (strcmp(pch, ".") != 0)
			{
				paths.push(pch);
			}

			pch = strtok(NULL, "/");
		}


		string res;

		while (!paths.empty())
		{
			res = "/" + string(paths.top()) + res;
			paths.pop();
		}

		if (res.length() <= 0)
			res = "/";

		return res;
	}
};

int main()
{
	Solution s;

	string res = s.simplifyPath("/...");

	return 0;
}