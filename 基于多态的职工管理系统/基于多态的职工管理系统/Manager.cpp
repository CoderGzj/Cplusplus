#include "Manager.h"

//构造函数
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息 纯虚函数
void Manager::ShowInfo() {
	cout << "职工编号： " << this->m_Id;
	cout << "\t职工姓名： " << this->m_Name;
	cout << "\t岗位：" << this->GetDeptName();
	cout << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

//获取岗位名称 纯虚函数
string Manager::GetDeptName() {
	return string("经理");
}