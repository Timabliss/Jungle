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
			ElemType* data; //ElemType data[����];
			int length;
			int max;
		};
		SqList* L = new SqList;

	public:
		LineList(int);
		~LineList();
		//������������������Ҫ���ã�C++��return 0 ʱ�Զ�����
		void Insert(int, ElemType);
		void Delete(int);
		// ���������е�λ��
		int PosGet(ElemType);
		// λ�ò�Ϊ������˷���-1����û����Ҫ���ҵ�����
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
		L = nullptr;//ָ��Կգ���ֹҰָ��
	}


	template <typename ElemType>
	void LineList<ElemType>::Insert(int i, ElemType x)
	{
		if (i < 0 || i>L->length || L->length >= L->max)
		// ������Զ������β����ĵ�һ���㣬�������ֱ�Ӳ����
		{
			cout << "�޷�����" << endl;
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
			cout << "�޷�ɾ��" << endl;
			return;
		}
		else
		{
			for (int j = i; j <= L->length-1; j++)//ȡ�Ⱥ��Ա�֤����ɾ�����һ��Ԫ��
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
		cout << "δ�ҵ�" << endl;
		return -1;
	}

	template <typename ElemType>
	void LineList<ElemType>::PrintList()
	{
		for (int i = 0; i < L->length; i++)
			cout << L->data[i] << endl;
	}
}
