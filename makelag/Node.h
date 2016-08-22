#pragma once
#include <string>
#include <vector>
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
	string type;//node类型字符串
	vector<Node *> childs;//直接子节点
	Node *parent = nullptr; //父节点
};

