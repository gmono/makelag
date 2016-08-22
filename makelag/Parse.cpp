#include <iostream>
#include <string>
#include <stack>
#include "Node.h"
#include <map>
#include <vector>
using namespace std;
//����Ϊ��Ԫ������󼯺�
//ÿһ��Ԫ�඼��Make��������nodeָ��
map<string, Node *> nodes;
//״̬

string line;//����һ��
vector<Node *> ParseLine()
{
	//�˺����������Ƿ���ÿһ�� �������ַ� �õ�ÿ����Ԫ �����ݸ��ض��Ľ�����
	vector<Node *> ret;
	string dc;
	for (int i = 0; i < line.length(); ++i)
	{
		//�жϿո�
		//�Կո�ͻ���Ϊ�ִʷ�
		if (line[i] == ' ' || line[i] == '\n')
		{
			if (dc != "")
			{
				//���ö�Ӧ��make����
				if (nodes.find(dc) == nodes.end())
				{
					exit(1);
				}
				Node *tempnode = nodes[dc];//�������������
				Node *node = tempnode->Make(dc);//���node����
				ret.push_back(node);//��������뷵���б�
				dc.clear();
				continue;
			}
		}
		else
		{
			dc.push_back(line[i]);//���뵥��
		}

	}
}

///������
Node *Parse(istream &data)
{
	//�˺����������ǵõ�ÿһ�е��ı����ύ���ʷ������� �õ�һϵ��Node * ���ύ���﷨����������
	while (!data.eof)
	{
		getline(data,line);
		//���鴦����(�Ƿ��У� Ŀǰû��
		ParseLine();//����һ��
		
	}
}