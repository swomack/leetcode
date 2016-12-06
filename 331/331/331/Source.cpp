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

	bool isValidSerialization(string preorder) 
	{
		stack<string> nodes;
		stringstream ss;
		ss.str(preorder);
		string item;
		if(getline(ss, item, ','))
			nodes.push(item);
		while (getline(ss, item, ','))
		{
			if (item != "#")
			{
				nodes.push(item);
			}
			else if(!nodes.empty())
			{
				if (nodes.top() != "#")
					nodes.push(item);
				else
				{
					while (!nodes.empty() && nodes.top() == "#")
					{
						nodes.pop();

						if (nodes.empty() || nodes.top() == "#")
							return false;

						nodes.pop();
					}

					nodes.push(item);
				}
				
			}
			else
			{
				return false;
			}
		}

		return nodes.size() == 1 && nodes.top() == "#";
	}
};

int main()
{
	Solution s;
	bool isBT = s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
	return 0;
}