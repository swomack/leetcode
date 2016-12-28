#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
	NestedInteger(int val)
	{
		integer = val;
	}
	bool isInteger()
	{
		return true;
	} 
	
	int getInteger()
	{
		return integer;
	}

     
	vector<NestedInteger> &getList()
	{
		return list;
	}

public:
	bool is_Integer;
	vector<NestedInteger> list;
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
			if (isEmptyList(nest.getList()[i]))
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

		int new_index = 0;
		current_lists.push(nested_list[nested_list_index]);
		current_indices.push(new_index);


		return buildStack(new_index, nested_list[nested_list_index++].getList());
	}

	bool buildStack(int index, vector<NestedInteger>& list)
	{
		while (index < list.size() && isEmptyList(list[index]))
			index++;

		if (index >= list.size())
			return false;


		if (list[index].isInteger())
		{
			next_value = list[index].getInteger();
			return true;
		}

		int new_index = 0;
		current_lists.push(list[index]);
		current_indices.push(new_index);

		return buildStack(new_index, list[index].getList());
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
	

	NestedInteger a(1);
	NestedInteger b(2);
	NestedInteger c(3);

	vector<NestedInteger> param{a,b,c};

	NestedIterator it(param);

	while (it.hasNext())
	{
		int n = it.next();
	}

	return 0;
}