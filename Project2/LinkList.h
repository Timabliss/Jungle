#pragma once
#include<iostream>
#include<string>

using namespace std;

namespace LINKLIST
{
	template<typename ElemType>
	struct Node
	{
		ElemType data;//������
		Node* next;//ָ����

		Node():next(nullptr){}
	};//������������ѽ��Ķ����������ⲿ�������δ������

	template<typename ElemType>
	class LinkList
	{
	public:
		void InsertNode(Node<ElemType>* head, ElemType x, int i);
		//���뵽ĳ�������ұ߾ͺ�����뵽�����ڵ�����
		void HeadInsertNode(Node<ElemType>* head, ElemType x);//ͷ�巨
		void TailInsertNode(Node<ElemType>* head, ElemType x);//β�巨
		int LengthNodeList(Node<ElemType>* head);

		void DestoryNode(Node<ElemType>* head);
		void DeleteNode(Node<ElemType>* head, int i);

		void PrintNodeList(Node<ElemType>* head);
		Node<ElemType>* SearchNode(Node<ElemType>* head, ElemType x);

		void ReverseBy2Ptr(Node<ElemType>* head);//�͵����ã�������ͷ�巨
		void ReverseBy3Ptr(Node<ElemType>* head);//�͵����ã�ͨ���ı�����˳��
	};


	template<typename ElemType>
	int LinkList<ElemType>::LengthNodeList(Node<ElemType>* head)
	//����ͷ���
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
			cout << "����ʧ��" << endl;
		else
		{
			for (int j = 0; j < i; j++)//���ƴ���
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
			cout << "����ʧ��" << endl;
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
	// ��Ȼ����ɾȥͷ�ڵ㣬����i����Ϊ0
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
			cout << "�Ҳ���ɾ����" << endl;
		else
		{
			q = p->next;
			p->next = q->next;
		}
		delete q;
	}

	template<typename ElemType>
	Node<ElemType>* LinkList<ElemType>::SearchNode(Node<ElemType>* head, ElemType x)
	// һ���Ƿ���λ������������λ�õ�ַ��������
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
			cout << "����ʧ��" << endl;
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
	void LinkList<ElemType>::ReverseBy2Ptr(Node<ElemType>* head)//�͵����ã�������ͷ�巨
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
	void LinkList<ElemType>::ReverseBy3Ptr(Node<ElemType>* head)//�͵����ã���ͨ���ı�����˳���γ�ѭ���б�Ȼ��Ͽ�
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
				n3 = n3->next;//���n1ͣ����β�ˣ�n2��n3ͣ����NULLָ��
		}
		head->next = n1;
		while (n1->next != head)
			n1 = n1->next;
		n1->next = nullptr;
	}
}
