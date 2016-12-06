#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>
#include <stack>

using namespace std;

class Solution 
{
public:

	void split(const string &s, char delim, stack<string> &elems) 
	{
		stringstream ss;
		ss.str(s);
		string item;
		while (getline(ss, item, delim)) 
		{
			elems.push(item);
		}
	}


	stack<string> split(const string &s, char delim) 
	{
		stack<string> elems;
		split(s, delim, elems);
		return elems;
	}

	bool isValidSerialization(string preorder) 
	{
		stack<string> nodes = split(preorder, ',');
		
		if (nodes.size() == 0)
			return false;

		while (!nodes.empty())
		{
			if (nodes.top() != "#")
				return false;

			nodes.pop();

			if (nodes.empty() || nodes.top() != "#")
				return false;

			nodes.pop();
		}
	}
};

int main()
{
	Solution s;
	bool isBT = s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
	return 0;
}