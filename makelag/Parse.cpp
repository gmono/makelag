#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
//状态

Node *ParseOne(string one)
{

}
///解析器
Node *Parse(istream &data)
{
	string line;
	while (!data.eof())
	{
		getline(data, line);//得到一行
		string one;
		for (char c : line)
		{
			if (c == ' ')
			{
				if (one == "") continue;
				ParseOne(one);//如果目前单词不为空就自己解析单词
			}
		}
		//这里一行解析完
		//得到一系列Node *
		//这一系列node 必须是一个完整的操作
	}
}