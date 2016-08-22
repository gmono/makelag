#include <iostream>
#include <string>
#include <stack>
#include "All.h"
#include <map>
#include <vector>
#include "转义字符处理.h"
extern void PrintError(int id);
using namespace std;
//以下为词元处理对象集合
//每一词元类都有Make函数返回node指针
map<string, Node *> nodes;
void ParseInit()
{
	//nodes初始化
	//字符串node不在其中
	nodes["make"] = new NodeMake();
}

string line;//这是代码 暂时命名为line 历史遗留

bool isinstring = false;
bool 是否无转义 = false;
vector<Node *> ParseLine()
{
	//此函数的作用是分析每一行 跳过空字符 得到每个词元 并传递给特定的解析器
	vector<Node *> ret;
	string dc;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '@')
		{
			if (line[i + 1] == '\"') 是否无转义 = true;//设置无转义
			else PrintError(0);//不可预知的单词
		}
		//处理字符串标志双引号
		if (line[i] == '\"')
		{
			//如果遇到引号就改变是否instring状态
			isinstring = !isinstring;
			if (dc != "")
			{
				//此处为进入字符串时或者字符串结束时的情况
				//调用对应的make函数
				if (isinstring)
				{
					if(nodes.find(dc) == nodes.end())
						PrintError(0); //单词不可预知 0号错误
					else
					{
						Node *tempnode = nodes[dc];//获得生成器对象
						Node *node = tempnode->Make(dc);//获得node对象
						ret.push_back(node);//将对象加入返回列表
						dc.clear();
					}
				}
				else
				{
					//这里字符串结束了 其中不包括双引号
					//dc为字符串内容
					Node *str = new NodeString();
					Node *stri = str->Make(dc);
					//结束了就构建一个字符串节点 
					//加入列表中
					ret.push_back(stri);
					dc.clear();//清空当前单词
					是否无转义 = false;//复位无转义标志
				}
			}
			//双引号处理完毕 
			continue;
		}
		//此处处理转义字符
		if (line[i] == '\\'&&isinstring&&是否无转义==false) //如果遇到转义标志而且正在读取字符串并且无转义标志为假
		{
			char c = 处理转义字符(line[++i]); //同时跳过转移字符 
			dc.push_back(c);//转义后加入dc中
			continue;
		}
		//判断空格
		//以空格和换行为分词符
		if (line[i] == ' ' || line[i] == '\n')
		{
			if (isinstring)
			{
				dc.push_back(line[i]);//加入单词
				continue; //如果在读取字符串中就直接继续读取 这表明换行符并不能截断字符串
			}
			else
			if (dc != "")
			{
				//调用对应的make函数
				if (nodes.find(dc) == nodes.end())
				{
					PrintError(0);//0号错误 单词不可预知
				}
				Node *tempnode = nodes[dc];//获得生成器对象
				Node *node = tempnode->Make(dc);//获得node对象
				ret.push_back(node);//将对象加入返回列表
				dc.clear();
			}
			if (line[i] == '\n') return ret;//如果此处是换行 就返回一个line
		}
		else
		{
			dc.push_back(line[i]);//加入单词
		}

	}
	throw 0;
}
extern Node *root;
extern void ParseLang(vector<Node *> ns);
///解析器
Node *Parse(string codes)
{
	//此函数的任务是调用ParseLine得到每一个单独的line 直到结束
	//每一个line都要传给语法分析器
	line = codes;
	for (;;)
	{
		try
		{
			auto list=ParseLine();
			ParseLang(list);
		}
		catch (int a)
		{
			if (a == 0) return root;
			else PrintError(INT_MAX);//此错误为未知错误
		}
	}

}