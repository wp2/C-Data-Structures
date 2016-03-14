#include <iostream>
#include <string>
using namespace std;


class Data 
{
	// Data Class put here what you need
	string A;
public:
	Data()
	{

	}
	Data(string tmp)
	{
		A = tmp;
	}
	string GetA() 
	{
		return A;
	}
};
class Node
{
	
	Node *prev;
	Data *dat;
	friend class Stack;
};

class Stack
{
	int Size = 0;
	Node *Top;
	Data GetTop()
	{
		return *Top->dat;
	}
public:
	void pop()
	{
		if (Size > 0)
		{
			Node *Tmp = Top->prev;
			delete Top;
			Top = Tmp;
			Size--;

		}
		if (Size == 0)
		{
			//Delete Stack
		}
	}
	void push(Data *data)
	{
		Node *node = new Node();
		node->dat = data;
		if (Size == 0)
		{
			node->prev = NULL;
			Size++;
		}
		else
		{
			node->prev = Top;
			Size++;
		}
		
		Top = node;
		
	}
	void List()
	{
		cout << "##### STACK LIST FROM TOP #####" << endl;
		Node *Traversal = Top;
		while (true)
		{
			cout << "**************" << endl;
			cout << "Stack Data : " << Traversal->dat->GetA() << endl;
			cout << "**************" << endl;
			if (Traversal->prev == NULL)
			{
				break; // Last Element Break Traversal
			}
			Traversal = Traversal->prev;
			
		}
		cout << "################### LIST BREAK ###################" << endl << endl;
	}
};

int main()
{

	Stack stack;
	stack.push(new Data("first"));
	stack.push(new Data("second"));
	stack.push(new Data("third"));
	stack.push(new Data("fourth"));
	stack.List();
	stack.pop();
	stack.pop();
	stack.List();
	system("PAUSE");
	return 0;
}