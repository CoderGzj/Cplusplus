//自己的通用数组类
#pragma once
#include <iostream>

using namespace std;

class MyArray
{

private:

	T* pAddress;  //指向一个堆空间，这个空间存储真正的数据
	int m_Capacity; //容量
	int m_Size;   // 大小
};