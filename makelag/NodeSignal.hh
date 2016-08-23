#pragma once
#pragma once
#include "Node.h"
//此类是标记类单词 例如 make of with 之类的单词
class NodeSignal :
	public Node
{
public:
	NodeSignal() {}
	~NodeSignal() {}
	

	Node *Make(string dc)
	{
		NodeSignal *ret = new NodeSignal();
		ret->type = dc;

		//调试用
		std::cout << dc << endl;
		//
		return ret;
	}
};
