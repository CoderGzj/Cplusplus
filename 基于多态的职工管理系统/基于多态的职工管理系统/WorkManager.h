#pragma once //防止头文件重复包含
#include <iostream>
#include <algorithm>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
#define FILENAME "empfile.txt"


//创建管理类
class WorkerManager {
public://成员函数
	
	//构造函数
	WorkerManager ();

	//展示菜单
	void ShowMenu ();

	//增加职工
	void AddEmp ();

	//保存文件
	void Save ();

	//统计文件人数
	int GetFileNum();

	//初始化员工
	void InitEmp();

	//显示职工
	void ShowEmp();

	//删除员工
	void DelEmp();

	//判断员工是否存在
	int IsExist(int id);

	//修改职工
	void ModEmp();

	//查找员工
	void FindEmp();

	//排序员工
	void SortEmp();

	//清空文件
	void CleanFile();

	//析构函数
	~WorkerManager ();

public://成员变量
	
	//记录文件中的人数
	int m_EmpNum;

	//员工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;
};
