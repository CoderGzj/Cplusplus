#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	//测试多态
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->ShowInfo();
	//delete worker;

	WorkerManager wm;

	int choice = 0;
	while (true) {
		//展示菜单
		wm.Show_Menu();
		cout << "请选择您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			cout << "欢迎你下次使用" << endl;
			return 0;
		case 1: //添加职工

			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}