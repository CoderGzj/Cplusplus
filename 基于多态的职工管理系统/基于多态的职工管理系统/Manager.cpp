#include "Manager.h"

//���캯��
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ ��д���麯��
void Manager::ShowInfo() {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_Name;
	cout << "\t��λ��" << this->GetDeptName();
	cout << "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

//��ȡ��λ���� ��д���麯��
string Manager::GetDeptName() {
	return string("����");
}