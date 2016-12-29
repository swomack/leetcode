#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
	NestedInteger(int val)
	{
		integer = val;
		is_Integer = true;
	}

	NestedInteger(vector<NestedInteger>& list)
	{
		nested_list = list;
		is_Integer = false;
	}

	bool isInteger()
	{
		return is_Integer;
	} 
	
	int getInteger()
	{
		return integer;
	}

	

	vector<NestedInteger> &getList()
	{
		return nested_list;
	}

public:
	bool is_Integer;
	vector<NestedInteger> nested_list;
	int integer;
 };

class NestedIterator {
public:

	vector<int> modified_list;
	int index;

	NestedIterator(vector<NestedInteger> &nestedList) 
	{
		index = 0;
		modified_list.clear();

		fillList(nestedList, modified_list);
	}

	void fillList(vector<NestedInteger>& inpList, vector<int>& outList)
	{
		for (int i = 0; i < inpList.size(); i++)
		{
			if (inpList[i].isInteger())
			{
				outList.push_back(inpList[i].getInteger());
			}
			else
			{
				fillList(inpList[i].getList(), outList);
			}
		}
	}

	bool hasNext() 
	{
		if (index < modified_list.size())
			return true;

		return false;
	}

	int next() 
	{
		return modified_list[index++];
	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/

int main()
{
	

	NestedInteger a(8);
	NestedInteger b(4);
	//NestedInteger c(6);

	vector<NestedInteger> p1{ a };
	NestedInteger d(p1);

	vector<NestedInteger> p2{ d, b };
	NestedInteger e(p2);

	/*vector<NestedInteger> p3{ a,p2 };
	NestedInteger f(p3);*/
	
	vector<NestedInteger> param{ e };

	NestedIterator it(param);

	while (it.hasNext())
	{
		int n = it.next();
	}

	return 0;
}