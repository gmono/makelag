#pragma once
#include <string>
extern void PrintError(int id);
using namespace std;

//�˺�����һ���ַ�Ϊת���ַ� 
char ����ת���ַ�(char c)
{
	switch (c)
	{
	case 'n':return '\n';
	case 't':return '\t';
		//Ŀǰֻ������
	default:
		PrintError(1);//һ��:ת�����
	}
}