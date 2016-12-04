#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
	stack<int> s;
public:
	// Push element x onto stack.
	void push(int x)
	{
		stack<int> temp;

		while (s.size() > 0)
		{
			temp.push(s.top());
			s.pop();
		}

		s.push(x);

		while (temp.size())
		{
			s.push(temp.top());
			temp.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop()
	{
		s.pop();
	}

	// Get the top element.
	int peek()
	{
		return s.top();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return s.size() == 0;
	}
};

int main()
{
	Queue s;
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);

	bool empty = s.empty();

	int top = s.peek();

	s.pop();

	s.push(14);

	top = s.peek();

	s.pop();
	s.pop();
	s.pop();
	s.pop();

	empty = s.empty();

	return 0;
}