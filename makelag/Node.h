#pragma once
#include <string>
#include <vector>
//��Ϊ������������
using namespace std;
//ÿ��node�����඼�и��չ��캯�����ڹ���ն���
//�ն�������Make
class Node
{
public:
	Node();
	virtual ~Node();

	virtual Node *Make(string dc)=0;
	string type;//node�����ַ���
	vector<Node *> childs;//ֱ���ӽڵ�
	Node *parent = nullptr; //���ڵ�
};

