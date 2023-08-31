#pragma once
#include "Worker.h"

class Manager : public Worker {
public:

	//构造函数
	Manager(int id, string name, int did);

	//显示个人信息 重写纯虚函数
	virtual void ShowInfo();

	//获取岗位名称 重写纯虚函数
	virtual string GetDeptName();

};