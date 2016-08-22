#pragma once
#include <string>
//此为生成树基础类
using namespace std;
//每个node派生类都有个空构造函数用于构造空对象
//空对象用于Make
class Node
{
public:
	Node();
	virtual ~Node();

	virtual Node *Make(string dc)=0;
};

