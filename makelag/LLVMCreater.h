#pragma once
#include "CreateBase.h"
class LLVMCreater :
	public CreateBase
{
public:
	LLVMCreater();
	~LLVMCreater();

	void Use(Node *);
};

