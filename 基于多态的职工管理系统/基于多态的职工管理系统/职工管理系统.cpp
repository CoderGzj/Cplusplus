#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {

	WorkerManager wm;

	int choice = 0;
	while (true) {
		//展示菜单
		wm.ShowMenu();
		cout << "请选择您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			cout << "欢迎你下次使用" << endl;
			return 0;
		case 1: //添加职工
			wm.AddEmp();
			break;
		case 2: //显示职工
			wm.ShowEmp();
			break;
		case 3: //删除职工
			wm.DelEmp();
			break;
		case 4: //修改职工
			wm.ModEmp();
			break;
		case 5: //查找职工
			wm.FindEmp();
			break;
		case 6: //排序职工
			wm.SortEmp();
			break;
		case 7: //清空文件
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}