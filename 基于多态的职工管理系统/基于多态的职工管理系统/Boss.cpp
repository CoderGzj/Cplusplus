#include "Boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ 
void Boss::ShowInfo() {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_Name;
	cout << "\t��λ��" << this->GetDeptName();
	cout << "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ���� 
string Boss::GetDeptName() {
	return string("�ܲ�");
}