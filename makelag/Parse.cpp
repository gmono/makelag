#include <iostream>
#include <string>
#include <stack>
#include "All.hh"
#include <map>
#include <vector>
#include <regex>
#include "ת���ַ�����.h"
extern void PrintError(int id);
using namespace std;
//����Ϊ��Ԫ������󼯺�
//ÿһ��Ԫ�඼��Make��������nodeָ��
map<string, Node *> nodes;
map<regex *, Node *> regnodes;//����������ʽ�� ��ʼ��ʱ������������node�Ķ�Ӧ��ϵ
void ParseInit()
{
	//nodes��ʼ��
	//�ַ���node��������
	//�������൥��
	vector<string> sigs{"make","of","with"};
	auto snode=new NodeSignal();
	for (string str : sigs)
	{
		nodes[str] = snode;//ȫ�����ó�Signal��������
	}

}

string line;//���Ǵ��� ��ʱ����Ϊline ��ʷ����
int nowptr = 0;//��ǰ����ָ��
//��һ���ַ��õ�һ��node
Node* ParseOne(string dc)
{
	//�˺�����������һ��ĵ��� �������ַ���
	//�������� �����������ʽ
	if (nodes.find(dc) != nodes.end())
	{
		Node *tempnode = nodes[dc];//�������������
		Node *node = tempnode->Make(dc);//���node����
		return node;
	}
	else
	{
		Node *tempnode = nullptr;
		for (auto v : regnodes)
		{
			regex *reg = v.first;
			if (regex_match(dc, *reg))
			{
				tempnode = v.second;
				break;//�ҵ�һ�����ϵ�node���˳�
			}
		}
		if (tempnode == nullptr)
			return nullptr;//���û���ҵ���Ӧ��node�ͷ���nullptr
		//�ҵ��˾͵õ�����
		Node *node = tempnode->Make(dc);//�õ�����
		return node;
	}
	return nullptr;//���ɶ��û�ҵ��ͷ���nullptr
}

#pragma region  �Ӵ����еõ�һ��line�����嵥Ԫ��
bool isinstring = false;
bool �Ƿ���ת�� = false;
vector<Node *> ParseLine()
{
	//�˺����������Ƿ���ÿһ�� �������ַ� �õ�ÿ����Ԫ �����ݸ��ض��Ľ�����
	vector<Node *> ret;
	string dc;
	for (int &i=nowptr; i < line.length(); ++i)
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
					//���ǽ����ַ���ʱ����� �����ַ���֮ǰ���ڵĵ��� ���� make��aaaa�� ��˴�����make
					Node *node = ParseOne(dc);//�õ�����
					if (node == nullptr) PrintError(0);//��Ϊprinterror��exit���Բ���Ҫelse
					//û���˳��ʹ���node��Ϊnode
					ret.push_back(node); //������뷵���б�
					dc.clear();
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
				//���������������Ŀո�ͻ���ʱ�õ�һ�����ʵĴ���
				Node *node = ParseOne(dc);//�õ�����
				if (node == nullptr) PrintError(0);//��Ϊprinterror��exit���Բ���Ҫelse
												   //û���˳��ʹ���node��Ϊnode
				ret.push_back(node); //������뷵���б�
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
#pragma endregion
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
			if (nowptr == codes.length()) return nullptr;
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