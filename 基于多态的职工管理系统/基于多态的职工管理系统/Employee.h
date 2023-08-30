#pragma once
#include "Worker.h"

//普通员工
class Employee : public Worker {
public:

	//构造函数
	Employee (int id, string name, int did);

	//显示个人信息 纯虚函数
	virtual void ShowInfo ();

	//获取岗位名称 纯虚函数
	virtual string GetDeptName ();

};