#include "MyArray.hpp"
#include <string>

void print(MyArray<int> &arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "array1��ӡ�����" << endl;
	print(arr1);
	cout << "array1�Ĵ�С��" << arr1.GetSize() << endl;
	cout << "array1��������" << arr1.GetCapacity() << endl;

	arr1.Push_Back(5);
	cout << "array1��ӡ�����" << endl;
	print(arr1);
	cout << "array1�Ĵ�С��" << arr1.GetSize() << endl;
	cout << "array1��������" << arr1.GetCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "array2��ӡ�����" << endl;
	print(arr2);
	cout << "array2�Ĵ�С��" << arr2.GetSize() << endl;
	cout << "array2��������" << arr2.GetCapacity() << endl;
}

//�����Զ�����������
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr) {
	for (int i = 0; i < personArr.GetSize(); i++) {
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}
}

void test02() {
	//��������
	MyArray<Person> pArray(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//��������
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	printPersonArray(pArray);

	cout << "pArray�Ĵ�С��" << pArray.GetSize() << endl;
	cout << "pArray��������" << pArray.GetCapacity() << endl;

}

int main() {
	test01();

	test02();

	return 0;
}