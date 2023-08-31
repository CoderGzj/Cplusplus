#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {

	WorkerManager wm;

	int choice = 0;
	while (true) {
		//չʾ�˵�
		wm.ShowMenu();
		cout << "��ѡ������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			cout << "��ӭ���´�ʹ��" << endl;
			return 0;
		case 1: //���ְ��
			wm.AddEmp();
			break;
		case 2: //��ʾְ��
			wm.ShowEmp();
			break;
		case 3: //ɾ��ְ��
			wm.DelEmp();
			break;
		case 4: //�޸�ְ��
			wm.ModEmp();
			break;
		case 5: //����ְ��
			wm.FindEmp();
			break;
		case 6: //����ְ��
			wm.SortEmp();
			break;
		case 7: //����ļ�
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}