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

	vector<NestedInteger> nested_list;
	stack<NestedInteger> current_lists;
	stack<int> current_indices;
	int nested_list_index;

	int next_value;

	NestedIterator(vector<NestedInteger> &nestedList) {
		nested_list = nestedList;
		nested_list_index = 0;
	}

	bool isEmptyList(NestedInteger& nest)
	{
		if (nest.isInteger())
			return false;

		for (int i = 0; i < nest.getList().size(); i++)
		{
			if (!isEmptyList(nest.getList()[i]))
				return false;
		}

		return true;
	}

	bool findInStack()
	{
		while (!current_lists.empty())
		{
			NestedInteger top_list = current_lists.top();
			int top_index = current_indices.top();

			while (top_index < top_list.getList().size() && isEmptyList(top_list.getList()[top_index]))
				top_index++;

			if (top_index >= top_list.getList().size())
			{
				current_lists.pop();
				current_indices.pop();
				continue;
			}
		

			if (top_list.getList()[top_index].isInteger())
			{
				next_value = top_list.getList()[top_index].getInteger();
				current_indices.pop();
				current_indices.push(top_index + 1);
				return true;
			}

			current_lists.push(top_list.getList()[top_index]);
			current_indices.pop();
			current_indices.push(top_index + 1);
			current_indices.push(0);
		}

		return false;
	}


	bool buildStackMain()
	{
		while (nested_list_index < nested_list.size() && isEmptyList(nested_list[nested_list_index]))
			nested_list_index++;

		if (nested_list_index >= nested_list.size())
			return false;


		if (nested_list[nested_list_index].isInteger())
		{
			next_value = nested_list[nested_list_index].getInteger();
			nested_list_index++;
			return true;
		}

		current_lists.push(nested_list[nested_list_index]);
		current_indices.push(0);
		nested_list_index++;


		return buildStack();
	}

	bool buildStack()
	{
		int index = current_indices.top();
		vector<NestedInteger>& list = current_lists.top().getList();
		while (index < list.size() && isEmptyList(list[index]))
			index++;

		if (index >= list.size())
		{
			return false;
		}
			


		if (list[index].isInteger())
		{
			next_value = list[index].getInteger();
			index++;
			current_indices.pop();
			current_indices.push(index);
			return true;
		}

		
		current_lists.push(list[index]);

		index++;
		current_indices.pop();
		current_indices.push(index);

		current_indices.push(0);

		

		return buildStack();
	}

	bool hasNext() 
	{
		return findInStack() || buildStackMain();
	}

	int next() 
	{
		return next_value;
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