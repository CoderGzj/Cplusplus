//自己的通用数组类
#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		//将arr中的数据拷贝过来
		for (int i = 0; i < arr.m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//重载[] 操作符
	T& operator[] (int index) {
		return this->pAddress[index];
	}
	
	//扩容
	void Add_Capacity() {
		this->m_Capacity++;
		T* temp = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			temp[i] = this->pAddress[i];
		}
		delete[] this->pAddress;
		this->pAddress = temp;
		temp = NULL;
	}

	//尾插
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			this->Add_Capacity();
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删
	void Pop_Back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//获取数组容量
	int GetCapacity() {
		return this->m_Capacity;
	}

	//获取数组大小
	int GetSize() {
		return this->m_Size;
	}

	//析构
	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;  //指向一个堆空间，这个空间存储真正的数据
	int m_Capacity; //容量
	int m_Size;   // 大小
};