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

	void split(const string &s, char delim, vector<string> &elems) 
	{
		stringstream ss;
		ss.str(s);
		string item;
		while (getline(ss, item, delim)) 
		{
			elems.push_back(item);
		}
	}


	vector<string> split(const string &s, char delim) 
	{
		vector<string> elems;
		split(s, delim, elems);
		return elems;
	}

	bool isValidSerialization(string preorder) 
	{
		vector<string> nodes = split(preorder, ',');
		
		if (nodes.size() == 0)
			return false;

		if (nodes[0] == "#" && nodes.size() > 1)
			return false;
		else if (nodes[0] == "#" && nodes.size() == 1)
			return true;


		stack<string> ss;
		ss.push(nodes[0]);

		for (int i = 1; i < nodes.size(); i++)
		{
			if (ss.empty())
				return false;

			if (nodes[i] != "#")
				ss.push(nodes[i]);
			else
			{
				if (ss.top() != "#")
				{
					ss.push(nodes[i]);
				}
				else
				{
					if (ss.size() < 2)
						return false;

					ss.pop();
					ss.pop();
					ss.push(nodes[i]);
				}
			}
		}

		return ss.size() == 1 && ss.top() == "#";

	}
};

int main()
{
	Solution s;
	return 0;
}