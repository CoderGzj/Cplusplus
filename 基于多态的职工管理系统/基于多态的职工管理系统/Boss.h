#pragma once
#include "Worker.h"

class Boss : public Worker {
public:

	//���캯��
	Boss(int id, string name, int did);

	//��ʾ������Ϣ ���麯��
	virtual void ShowInfo();

	//��ȡ��λ���� ���麯��
	virtual string GetDeptName();

};