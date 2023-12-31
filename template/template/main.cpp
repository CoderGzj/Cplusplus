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
	cout << "array1打印输出：" << endl;
	print(arr1);
	cout << "array1的大小：" << arr1.GetSize() << endl;
	cout << "array1的容量：" << arr1.GetCapacity() << endl;

	arr1.Push_Back(5);
	cout << "array1打印输出：" << endl;
	print(arr1);
	cout << "array1的大小：" << arr1.GetSize() << endl;
	cout << "array1的容量：" << arr1.GetCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "array2打印输出：" << endl;
	print(arr2);
	cout << "array2的大小：" << arr2.GetSize() << endl;
	cout << "array2的容量：" << arr2.GetCapacity() << endl;
}

//测试自定义数据类型
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
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}

void test02() {
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.GetSize() << endl;
	cout << "pArray的容量：" << pArray.GetCapacity() << endl;

}

int main() {
	test01();

	test02();

	return 0;
}