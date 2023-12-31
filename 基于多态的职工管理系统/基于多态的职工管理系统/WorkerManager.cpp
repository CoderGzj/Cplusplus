#include "WorkManager.h"

//cmp1升序
bool cmp1(Worker* x, Worker* y) {
	return x->m_Id < y->m_Id;
}

//cmp2降序
bool cmp2(Worker* x, Worker* y) {
	return x->m_Id > y->m_Id;
}


//构造函数
WorkerManager::WorkerManager () {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.文件不存在情况
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0; //初始化人数
		this->m_EmpArray = NULL; //初始化数组
		this->m_FileIsEmpty = true; //文件为空标志
		ifs.close(); //关闭文件
		return;
	}

	//2.文件存在，且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空！" << endl;
		this->m_EmpNum = 0; 
		this->m_EmpArray = NULL; 
		this->m_FileIsEmpty = true;
		ifs.close(); 
		return;
	}

	//3.文件存在，且有记录
	int num = this->GetFileNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num; //更新成员属性
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->InitEmp();
}

//显示菜单
void WorkerManager::ShowMenu () {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//增加职工
void WorkerManager::AddEmp () {

	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放在新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelcet;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelcet;

			Worker* worker = NULL;
			switch (dSelcet) {
			case 1: //普通职工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3: //老板
				worker = new Boss(id, name, 3);
				break;
			default :
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}


		//更新新的个数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//保存到文件
		this->Save();
	}
	else {
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}
}

//保存文件
void WorkerManager::Save () {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//统计文件人数
int WorkerManager::GetFileNum () {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::InitEmp () {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker;
		//根据不同的部门Id创建不同对象
		if (did == 1) { //1 普通员工
			worker = new Employee(id, name, did);
		}
		else if (did == 2) { //2 经理
			worker = new Manager(id, name, did);
		}
		else { //3 总裁
			worker = new Boss(id, name, did);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示员工
void WorkerManager::ShowEmp () {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多态调用接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除员工
void WorkerManager::DelEmp() {

	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		//按职工编号删除
		cout << "请输入你要删除的职工号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			if (this->m_EmpNum == 0) {
				this->m_FileIsEmpty = true;
			}
			this->Save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断员工是否存在
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}	
	}
	return index;
}

//修改员工
void WorkerManager::ModEmp() {

	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更改数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->Save();
		}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

//查找员工
void WorkerManager::FindEmp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1. 按职工编号查找" << endl;
		cout << "2. 按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) { //按职工号查找
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			
			int ret = this->IsExist(id);
			if (ret != -1) {
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}

		else if (select == 2) { //按姓名查找
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查找成功，职工信息为：" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			
			if (flag == false) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序员工
void WorkerManager::SortEmp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或未记录" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) { //升序
			sort(this->m_EmpArray, this->m_EmpArray + this->m_EmpNum, cmp1);
		}
		else { //降序
			sort(this->m_EmpArray, this->m_EmpArray + this->m_EmpNum, cmp2);
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->Save();
		this->ShowEmp();
	}
}

//清空文件
void WorkerManager::CleanFile() {

	cout << "确定清空？" << endl;
	cout << "1. 确定" << endl;
	cout << "2. 返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL) {
			//删除堆区每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

//析构
WorkerManager::~WorkerManager () {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}
