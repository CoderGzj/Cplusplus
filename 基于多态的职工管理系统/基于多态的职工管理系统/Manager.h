#pragma once
#include "Worker.h"

class Manager : public Worker {
public:

	//���캯��
	Manager(int id, string name, int did);

	//��ʾ������Ϣ ���麯��
	virtual void ShowInfo();

	//��ȡ��λ���� ���麯��
	virtual string GetDeptName();

};