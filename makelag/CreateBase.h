#pragma once

class Node;
///��Ϊ�����������
class CreateBase
{
public:
	CreateBase();
	virtual ~CreateBase();

	virtual void Use(Node *)=0;
};

