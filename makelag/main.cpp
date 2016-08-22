#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "CreateBase.h"
#include "LLVMCreater.h"
using namespace std;
extern Node *Parse(string codes);
extern void ParseInit();
//以下为主程序
CreateBase *cbr = new LLVMCreater();
int main(int argc, char **argv)
{
	cout << "Make Language 编译器(LLVM 0.1)" << endl;
	ParseInit();
	if (argc <= 1) {
		cout << "参数过少！";
		return 1;
	}
	ifstream *in = new ifstream(argv[1]); //一次性读取
	istreambuf_iterator<char> start(*in);
	istreambuf_iterator<char> end;
	string str(start, end);//读取所有字符串
	Node *tree = Parse(str);

	return 0;
}