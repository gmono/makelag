#pragma once
#include <string>
extern void PrintError(int id);
using namespace std;

//此函数第一个字符为转义字符 
char 处理转义字符(char c)
{
	switch (c)
	{
	case 'n':return '\n';
	case 't':return '\t';
		//目前只有两个
	default:
		PrintError(1);//一号:转义错误
	}
}