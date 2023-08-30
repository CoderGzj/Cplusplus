#pragma once
#include "Worker.h"

class Boss : public Worker {
public:

	//构造函数
	Boss(int id, string name, int did);

	//显示个人信息 纯虚函数
	virtual void ShowInfo();

	//获取岗位名称 纯虚函数
	virtual string GetDeptName();

};