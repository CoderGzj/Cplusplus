#include "Employee.h"

Employee::Employee (int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ 
void Employee::ShowInfo () {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_Name;
	cout << "\t��λ��" << this->GetDeptName();
	cout << "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ���� 
string Employee::GetDeptName () {
	return string("Ա��");
}