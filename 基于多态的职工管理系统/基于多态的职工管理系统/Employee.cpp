#include "Employee.h"

Employee::Employee (int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息 
void Employee::ShowInfo () {
	cout << "职工编号： " << this->m_Id;
	cout << "\t职工姓名： " << this->m_Name;
	cout << "\t岗位：" << this->GetDeptName();
	cout << "\t岗位职责：完成经理交给的任务" << endl;
}

//获取岗位名称 
string Employee::GetDeptName () {
	return string("员工");
}