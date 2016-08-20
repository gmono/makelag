#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "CreateBase.h"
#include "LLVMCreater.h"
using namespace std;
Node *Parse(istream &data);
//����Ϊ������
CreateBase *cbr = new LLVMCreater();
int main(int argc, char **argv)
{
	cout << "Make Language ������(LLVM 0.1)" << endl;
	if (argc <= 1) {
		cout << "�������٣�";
		return 1;
	}
	ifstream *in = new ifstream(argv[1]); //����һ���Զ�ȡ
	Node *tree = Parse(*in);

	return 0;
}