#pragma once
#pragma once
#include "Node.h"
//�����Ǳ���൥�� ���� make of with ֮��ĵ���
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

		//������
		std::cout << dc << endl;
		//
		return ret;
	}
};
