#pragma once
#include "Worker.h"

//��ͨԱ��
class Employee : public Worker {
public:

	//���캯��
	Employee (int id, string name, int did);

	//��ʾ������Ϣ ���麯��
	virtual void ShowInfo ();

	//��ȡ��λ���� ���麯��
	virtual string GetDeptName ();

};