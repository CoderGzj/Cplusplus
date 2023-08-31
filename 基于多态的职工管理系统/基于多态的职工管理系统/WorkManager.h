#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>
#include <algorithm>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
#define FILENAME "empfile.txt"


//����������
class WorkerManager {
public://��Ա����
	
	//���캯��
	WorkerManager ();

	//չʾ�˵�
	void ShowMenu ();

	//����ְ��
	void AddEmp ();

	//�����ļ�
	void Save ();

	//ͳ���ļ�����
	int GetFileNum();

	//��ʼ��Ա��
	void InitEmp();

	//��ʾְ��
	void ShowEmp();

	//ɾ��Ա��
	void DelEmp();

	//�ж�Ա���Ƿ����
	int IsExist(int id);

	//�޸�ְ��
	void ModEmp();

	//����Ա��
	void FindEmp();

	//����Ա��
	void SortEmp();

	//����ļ�
	void CleanFile();

	//��������
	~WorkerManager ();

public://��Ա����
	
	//��¼�ļ��е�����
	int m_EmpNum;

	//Ա������ָ��
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};
