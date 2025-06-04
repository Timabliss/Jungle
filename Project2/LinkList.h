#pragma once
#include<iostream>
#include<string>

using namespace std;

namespace LINKLIST
{
	template<typename ElemType>
	struct Node
	{
		ElemType data;//数据域
		Node* next;//指针域

		Node():next(nullptr){}
	};//单向单链表。这里把结点的定义放在类的外部，方便多次创建结点

	template<typename ElemType>
	class LinkList
	{
	public:
		void InsertNode(Node<ElemType>* head, ElemType x, int i);
		//插入到某个结点的右边就好像插入到它父节点的左边
		void HeadInsertNode(Node<ElemType>* head, ElemType x);//头插法
		void TailInsertNode(Node<ElemType>* head, ElemType x);//尾插法
		int LengthNodeList(Node<ElemType>* head);

		void DestoryNode(Node<ElemType>* head);
		void DeleteNode(Node<ElemType>* head, int i);

		void PrintNodeList(Node<ElemType>* head);
		Node<ElemType>* SearchNode(Node<ElemType>* head, ElemType x);

		void ReverseBy2Ptr(Node<ElemType>* head);//就地逆置，类似于头插法
		void ReverseBy3Ptr(Node<ElemType>* head);//就地逆置，通过改变链接顺序
	};


	template<typename ElemType>
	int LinkList<ElemType>::LengthNodeList(Node<ElemType>* head)
	//包含头结点
	{
		int i = 0;
		Node<ElemType>* p = head;
		while (p != nullptr)
		{
			i++;
			p = p->next;
		}
		return i;
	}

	template<typename ElemType>
	void LinkList<ElemType>::InsertNode(Node<ElemType>* head, ElemType x, int i)
	{
		Node<ElemType>* insert = new Node<ElemType>;
		insert->data = x;
		Node<ElemType>* p = head;
		if (i<0 || i>LengthNodeList(head))
			cout << "插入失败" << endl;
		else
		{
			for (int j = 0; j < i; j++)//后移次数
			{
				p = p->next;
			}
			insert->next = p->next;
			p->next = insert;
		}
	}

	template<typename ElemType>
	void LinkList<ElemType>::HeadInsertNode(Node<ElemType>* head, ElemType x)
	{
		Node<ElemType>* insert = new Node<ElemType>;
		insert->data = x;
		Node<ElemType>* p = head;
		if (head==nullptr)
		{
			cout << "插入失败" << endl;
			return;
		}
		else
		{
			insert->next = head->next;
			head->next = insert;
		}
	}

	template<typename ElemType>
	void LinkList<ElemType>::TailInsertNode(Node<ElemType>* head, ElemType x)
	{
		Node<ElemType>* insert = new Node<ElemType>;
		insert->data = x;
		Node<ElemType>* p = head;
		while (p->next != nullptr)
			p = p->next;
		p->next = insert;
	}


	template<typename ElemType>
	void LinkList<ElemType>::DeleteNode(Node<ElemType>* head, int i)
	// 显然不能删去头节点，所以i不能为0
	{
		Node<ElemType>* p = head;
		Node<ElemType>* q;
		int j = 0;
		while (p != nullptr)
		{
			p = p->next;
			j++;
			if (j == i - 1)
				break;
		}
		if (j < i - 1)
			cout << "找不到删除点" << endl;
		else
		{
			q = p->next;
			p->next = q->next;
		}
		delete q;
	}

	template<typename ElemType>
	Node<ElemType>* LinkList<ElemType>::SearchNode(Node<ElemType>* head, ElemType x)
	// 一般是返回位置索引，返回位置地址倒不常见
	{
		Node<ElemType>* p = head;
		int j = 0;
		while (p != nullptr)
		{
			p = p->next;
			if (p->data == x)
			{
				j = 1;
				break;
			}
		}
		if (j == 0)
		{
			cout << "查找失败" << endl;
			return NULL;
		}
		else
			return p;
	}

	template<typename ElemType>
	void LinkList<ElemType>::DestoryNode(Node<ElemType>* head)
	{
		Node<ElemType>* p = head;
		while (p != nullptr)
		{
			Node<ElemType>* q =p;
			p = p->next;
			delete q;
		}
	}

	template<typename ElemType>
	void LinkList<ElemType>::PrintNodeList(Node<ElemType>* head)
	{
		Node<ElemType>* p = head;
		while (p != nullptr&&p->next!=nullptr)
		{
			p = p->next;
			cout << p->data << endl;
		}
	}

	template<typename ElemType>
	void LinkList<ElemType>::ReverseBy2Ptr(Node<ElemType>* head)//就地逆置，类似于头插法
	{
		Node<ElemType>* n1; Node<ElemType>* n2;
		n1 = head->next;
		head->next = nullptr;
		while (n1 != nullptr)
		{
			n2 = n1;
			n1 = n1->next;
			n2->next = head->next;
			head->next = n2;
		}
	}

	template<typename ElemType>
	void LinkList<ElemType>::ReverseBy3Ptr(Node<ElemType>* head)//就地逆置，先通过改变链接顺序，形成循环列表，然后断开
	{
		int i = LengthNodeList(head);
		Node<ElemType>* n1 = nullptr;
		Node<ElemType>* n2 = head;
		Node<ElemType>* n3 = head->next;
		for (int j = 0; j < i; j++)
		{
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3 != nullptr)
				n3 = n3->next;//最后n1停泊在尾端，n2、n3停泊在NULL指针
		}
		head->next = n1;
		while (n1->next != head)
			n1 = n1->next;
		n1->next = nullptr;
	}
}
