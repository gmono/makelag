#include <iostream>
#include <string>
#include <stack>
#include "All.h"
#include <map>
#include <vector>
#include "ת���ַ�����.h"
extern void PrintError(int id);
using namespace std;
//����Ϊ��Ԫ������󼯺�
//ÿһ��Ԫ�඼��Make��������nodeָ��
map<string, Node *> nodes;
void ParseInit()
{
	//nodes��ʼ��
	//�ַ���node��������
	nodes["make"] = new NodeMake();
}

string line;//���Ǵ��� ��ʱ����Ϊline ��ʷ����

bool isinstring = false;
bool �Ƿ���ת�� = false;
vector<Node *> ParseLine()
{
	//�˺����������Ƿ���ÿһ�� �������ַ� �õ�ÿ����Ԫ �����ݸ��ض��Ľ�����
	vector<Node *> ret;
	string dc;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '@')
		{
			if (line[i + 1] == '\"') �Ƿ���ת�� = true;//������ת��
			else PrintError(0);//����Ԥ֪�ĵ���
		}
		//�����ַ�����־˫����
		if (line[i] == '\"')
		{
			//����������ž͸ı��Ƿ�instring״̬
			isinstring = !isinstring;
			if (dc != "")
			{
				//�˴�Ϊ�����ַ���ʱ�����ַ�������ʱ�����
				//���ö�Ӧ��make����
				if (isinstring)
				{
					if(nodes.find(dc) == nodes.end())
						PrintError(0); //���ʲ���Ԥ֪ 0�Ŵ���
					else
					{
						Node *tempnode = nodes[dc];//�������������
						Node *node = tempnode->Make(dc);//���node����
						ret.push_back(node);//��������뷵���б�
						dc.clear();
					}
				}
				else
				{
					//�����ַ��������� ���в�����˫����
					//dcΪ�ַ�������
					Node *str = new NodeString();
					Node *stri = str->Make(dc);
					//�����˾͹���һ���ַ����ڵ� 
					//�����б���
					ret.push_back(stri);
					dc.clear();//��յ�ǰ����
					�Ƿ���ת�� = false;//��λ��ת���־
				}
			}
			//˫���Ŵ������ 
			continue;
		}
		//�˴�����ת���ַ�
		if (line[i] == '\\'&&isinstring&&�Ƿ���ת��==false) //�������ת���־�������ڶ�ȡ�ַ���������ת���־Ϊ��
		{
			char c = ����ת���ַ�(line[++i]); //ͬʱ����ת���ַ� 
			dc.push_back(c);//ת������dc��
			continue;
		}
		//�жϿո�
		//�Կո�ͻ���Ϊ�ִʷ�
		if (line[i] == ' ' || line[i] == '\n')
		{
			if (isinstring)
			{
				dc.push_back(line[i]);//���뵥��
				continue; //����ڶ�ȡ�ַ����о�ֱ�Ӽ�����ȡ ��������з������ܽض��ַ���
			}
			else
			if (dc != "")
			{
				//���ö�Ӧ��make����
				if (nodes.find(dc) == nodes.end())
				{
					PrintError(0);//0�Ŵ��� ���ʲ���Ԥ֪
				}
				Node *tempnode = nodes[dc];//�������������
				Node *node = tempnode->Make(dc);//���node����
				ret.push_back(node);//��������뷵���б�
				dc.clear();
			}
			if (line[i] == '\n') return ret;//����˴��ǻ��� �ͷ���һ��line
		}
		else
		{
			dc.push_back(line[i]);//���뵥��
		}

	}
	throw 0;
}
extern Node *root;
extern void ParseLang(vector<Node *> ns);
///������
Node *Parse(string codes)
{
	//�˺����������ǵ���ParseLine�õ�ÿһ��������line ֱ������
	//ÿһ��line��Ҫ�����﷨������
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
			else PrintError(INT_MAX);//�˴���Ϊδ֪����
		}
	}

}