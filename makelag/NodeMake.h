#pragma once
#pragma once
#include "Node.h"
class NodeMake :
	public Node
{
public:
	NodeMake() {}
	~NodeMake() {}
	

	Node *Make(string dc)
	{
		NodeMake *ret = new NodeMake();
		ret->type = "make";

		//������
		std::cout << "make" << endl;
		//
		return ret;
	}
};
