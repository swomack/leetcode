#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>

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

		if (nodes.size() <= 0)
			return true;

		if (nodes.size() > 1 && nodes[0] == "#")
			return false;


		bool found = true;

		while (found)
		{
			found = false;
			// check if there is two ocnsecutive #, if there is then remove those and make 
			//for(int i = 0; i < )
		}

	}
};

int main()
{
	Solution s;
	return 0;
}