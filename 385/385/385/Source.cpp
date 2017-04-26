#include <iostream>
#include <vector>
#include <stack>

using namespace std;


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
	   NestedInteger()
	   {

		 }

     // Constructor initializes a single integer.
	   NestedInteger(int value)
	   {

	 }

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
	   bool isInteger() const
	   {
		   return true;
	 }

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
	   int getInteger() const
	   {
		   return bb;
	 }

     // Set this NestedInteger to hold a single integer.
	   void setInteger(int value)
	   {
		   bb = value;
	 }

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
	   void add(const NestedInteger &ni)
	   {
		   aa.push_back(ni);
	 }

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
	   const vector<NestedInteger> &getList() const
	   {
		   return aa;
	 }

	 vector<NestedInteger> aa;
	 int bb;
 };

class Solution {
public:
	NestedInteger deserialize(string s) {
		NestedInteger top;

		stack<NestedInteger> track;
		track.push(top);


		int running_value = 0;
		int is_neg = false;

		for (int i = 0; i < s.length(); i++)
		{
			if (isalnum(s[i]))
			{
				running_value *= 10;
				running_value += (s[i] - '0');
			}
			else if (s[i] == '-')
			{
				is_neg = true;
			}
			else if (s[i] == ',')
			{
				track.top().setInteger(running_value * (is_neg ? -1 : 1));
				running_value = 0;
				is_neg = false;
			}
			else if (s[i] == '[')
			{
				track.push(NestedInteger());
			}
			else
			{
				if (running_value != 0)
					track.top().setInteger(running_value * (is_neg ? -1 : 1));
				running_value = 0;
				is_neg = false;

				NestedInteger& n = track.top();
				track.pop();

				track.top().add(n);
			}
		}

		if (running_value != 0)
			track.top().setInteger(running_value * (is_neg ? -1 : 1));

		return track.top();
	}
};

int main()
{
	Solution s;

	NestedInteger n = s.deserialize("-3");

	return 0;
}

