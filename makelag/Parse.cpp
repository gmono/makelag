#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
//״̬

Node *ParseOne(string one)
{

}
///������
Node *Parse(istream &data)
{
	string line;
	while (!data.eof())
	{
		getline(data, line);//�õ�һ��
		string one;
		for (char c : line)
		{
			if (c == ' ')
			{
				if (one == "") continue;
				ParseOne(one);//���Ŀǰ���ʲ�Ϊ�վ��Լ���������
			}
		}
		//����һ�н�����
		//�õ�һϵ��Node *
		//��һϵ��node ������һ�������Ĳ���
	}
}