#pragma once
#include "Worker.h"

class Manager : public Worker {
public:

	//���캯��
	Manager(int id, string name, int did);

	//��ʾ������Ϣ ��д���麯��
	virtual void ShowInfo();

	//��ȡ��λ���� ��д���麯��
	virtual string GetDeptName();

};