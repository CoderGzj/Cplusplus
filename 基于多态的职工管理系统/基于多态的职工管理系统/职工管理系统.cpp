#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	//���Զ�̬
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//delete worker;

	WorkerManager wm;

	int choice = 0;
	while (true) {
		//չʾ�˵�
		wm.Show_Menu();
		cout << "��ѡ������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			cout << "��ӭ���´�ʹ��" << endl;
			return 0;
		case 1: //���ְ��

			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}