#include <iostream>
#include <queue>

using namespace std;

class Stack 
{
public:
	queue<int> q;
public:
	// Push element x onto stack.
	void push(int x) 
	{
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		queue<int> temp;

		while (q.size() > 1)
		{
			temp.push(q.front());
			q.pop();
		}

		q.pop();

		while (temp.size())
		{
			q.push(temp.front());
			temp.pop();
		}
	}

	// Get the top element.
	int top() 
	{
		if (q.size() <= 0)
			return NULL;

		queue<int> temp;

		while (q.size() > 1)
		{
			temp.push(q.front());
			q.pop();
		}

		int ret = q.front();
		temp.push(q.front());
		q.pop();

		while (temp.size())
		{
			q.push(temp.front());
			temp.pop();
		}

		return ret;
	}

	// Return whether the stack is empty.
	bool empty() 
	{
		return q.size() == 0;
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);

	bool empty = s.empty();

	int top = s.top();

	s.pop();

	s.push(14);

	top = s.top();

	s.pop();
	s.pop();
	s.pop();
	s.pop();

	empty = s.empty();

	return 0;
}