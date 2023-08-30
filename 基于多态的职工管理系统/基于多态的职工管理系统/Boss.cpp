#include "Boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息 
void Boss::ShowInfo() {
	cout << "职工编号： " << this->m_Id;
	cout << "\t职工姓名： " << this->m_Name;
	cout << "\t岗位：" << this->GetDeptName();
	cout << "\t岗位职责：管理公司所有事物" << endl;
}

//获取岗位名称 
string Boss::GetDeptName() {
	return string("总裁");
}