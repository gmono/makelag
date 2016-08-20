#pragma once

class Node;
///此为生成器类基类
class CreateBase
{
public:
	CreateBase();
	virtual ~CreateBase();

	virtual void Use(Node *)=0;
};

