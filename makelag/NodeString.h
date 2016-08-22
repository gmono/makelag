#pragma once
#include "Node.h"
class NodeString :
	public Node
{
public:
	NodeString() {}
	~NodeString() {}
	string value;

	Node *Make(string dc)
	{
		NodeString *ret = new NodeString();
		ret->type = "string";
		ret->value = dc;
		//µ÷ÊÔÓÃ
		string test;
		for (char c : dc)
		{
			if (c == '\n') test.append("\\n");
			else test.push_back(c);
		}
		std::cout << "string:"<<test<<endl;
		//
		return ret;
	}
};

