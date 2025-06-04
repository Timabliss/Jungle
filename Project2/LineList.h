#pragma once
#include<iostream>
#include<string>

using namespace std;

namespace LINELIST
{
	template <typename ElemType>
	class LineList
	{
	private:
		struct SqList
		{
			ElemType* data; //ElemType data[长度];
			int length;
			int max;
		};
		SqList* L = new SqList;

	public:
		LineList(int);
		~LineList();
		//析构函数主函数不需要调用，C++在return 0 时自动调用
		void Insert(int, ElemType);
		void Delete(int);
		// 输入数组中的位置
		int PosGet(ElemType);
		// 位置不为负，因此返回-1表明没有需要查找的数据
		void PrintList();
	};

	template <typename ElemType>
	LineList<ElemType>::LineList(int Length_MAX)
	{
		L->data = new ElemType[Length_MAX];
		L->length = 0;
		L->max = Length_MAX;
	}
	

	template <typename ElemType>
	LineList<ElemType>::~LineList()
	{
		delete[] L->data;
		delete L;
		L = nullptr;//指针对空，防止野指针
	}


	template <typename ElemType>
	void LineList<ElemType>::Insert(int i, ElemType x)
	{
		if (i < 0 || i>L->length || L->length >= L->max)
		// 插入最远允许在尾结点后的第一个点，这个点是直接插入的
		{
			cout << "无法插入" << endl;
			return;
		}
		else
		{
			for (int j = L->length; j > i; j--)
			{
				L->data[j] = L->data[j-1];
			}
			L->data[i] = x;
			L->length++;
		}
	}

	template <typename ElemType>
	void LineList<ElemType>::Delete(int i)
	{
		if (i < 0 || i >= L->length || L->length == 0)
		{
			cout << "无法删除" << endl;
			return;
		}
		else
		{
			for (int j = i; j <= L->length-1; j++)//取等号以保证可以删除最后一个元素
			{
				L->data[j] = L->data[j + 1];
			}
			L->length--;
		}
	}

	template <typename ElemType>
	int LineList<ElemType>::PosGet(ElemType x)
	{
		for (int i = 0; i < L->length; i++)
		{
			if (L->data[i] == x)
				return i;
		}
		cout << "未找到" << endl;
		return -1;
	}

	template <typename ElemType>
	void LineList<ElemType>::PrintList()
	{
		for (int i = 0; i < L->length; i++)
			cout << L->data[i] << endl;
	}
}
