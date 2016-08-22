#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "CreateBase.h"
#include "LLVMCreater.h"
using namespace std;
extern Node *Parse(string codes);
extern void ParseInit();
//����Ϊ������
CreateBase *cbr = new LLVMCreater();
int main(int argc, char **argv)
{
	cout << "Make Language ������(LLVM 0.1)" << endl;
	ParseInit();
	if (argc <= 1) {
		cout << "�������٣�";
		return 1;
	}
	ifstream *in = new ifstream(argv[1]); //һ���Զ�ȡ
	istreambuf_iterator<char> start(*in);
	istreambuf_iterator<char> end;
	string str(start, end);//��ȡ�����ַ���
	Node *tree = Parse(str);

	return 0;
}