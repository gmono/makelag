#include <iostream>
#include <string>
#include <stack>
#include "Node.h"
#include <map>
#include <vector>
using namespace std;
//以下为词元处理对象集合
//每一词元类都有Make函数返回node指针
map<string, Node *> nodes;
//状态

string line;//这是一行
vector<Node *> ParseLine()
{
	//此函数的作用是分析每一行 跳过空字符 得到每个词元 并传递给特定的解析器
	vector<Node *> ret;
	string dc;
	for (int i = 0; i < line.length(); ++i)
	{
		//判断空格
		//以空格和换行为分词符
		if (line[i] == ' ' || line[i] == '\n')
		{
			if (dc != "")
			{
				//调用对应的make函数
				if (nodes.find(dc) == nodes.end())
				{
					exit(1);
				}
				Node *tempnode = nodes[dc];//获得生成器对象
				Node *node = tempnode->Make(dc);//获得node对象
				ret.push_back(node);//将对象加入返回列表
				dc.clear();
				continue;
			}
		}
		else
		{
			dc.push_back(line[i]);//加入单词
		}

	}
}

///解析器
Node *Parse(istream &data)
{
	//此函数的任务是得到每一行的文本并提交给词法分析器 得到一系列Node * 并提交给语法解析器处理
	while (!data.eof)
	{
		getline(data,line);
		//特情处理部分(非分行） 目前没有
		ParseLine();//解析一行
		
	}
}