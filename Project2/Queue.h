#pragma once
#include<iostream>
#include<string>

using namespace std;

namespace QUEUE
{
	template<typename ElemType>
	class Queue
	{
	private:
		struct SqQueue
		{
			ElemType* data;
			int front;
			int rear;
			int max;
		};
		SqQueue* Q;

	public:
		Queue(int MAXSIZE);
		~Queue();

		void EnQueue(ElemType x);
		void OutQueue();
		ElemType& GetHeadElem();
		int QueueLength();
		void ClearQueue();
		bool isEmpty();
		//�������Q���е�ָ�룬��������ʱ�Դ�һ��thisָ��
	};


	template<typename ElemType>
	Queue<ElemType>::Queue(int MAXSIZE)
	{
		Q = new SqQueue; //���԰���仰��private���������һ�𿴣���һ���ǳ�������ָ������������
		Q->data = new ElemType[MAXSIZE]{};
		Q->front = Q->rear = 0;
		Q->max = MAXSIZE;
	}

	template<typename ElemType>
	Queue<ElemType>::~Queue()
	{
		if constexpr (is_pointer_v<ElemType>)
		{
			for (int i = 0; i < Q->max; i++)
				delete Q->data[i];
		}
		delete[] Q->data;
		delete Q;
		Q = nullptr;
	}

	template<typename ElemType>
	void  Queue<ElemType>::EnQueue(ElemType x)
	{
		if ((Q->rear + 1) % Q->max == Q->front)
		{
			throw runtime_error("��������");
		}
		else
		{
			Q->rear = (Q->rear + 1) % Q->max;
			Q->data[Q->rear] = x;
		}
	}

	template<typename ElemType>
	void Queue<ElemType>::OutQueue()
	{
		if (Q->front == Q->rear)
		{
			throw runtime_error("����Ϊ��");
		}
		else
		{
			Q->front = (Q->front + 1) % Q->max;
		}
	}

	template<typename ElemType>
	ElemType& Queue<ElemType>::GetHeadElem()
	{
		if (Q->front==Q->rear)
		{
			throw runtime_error("����Ϊ��");
		}
		else
		{
			return Q->data[(Q->front + 1) % Q->max];
		}
	}

	template<typename ElemType>
	int Queue<ElemType>::QueueLength()//ע��ͷβ�����λ��
	{
		return Q->rear >= Q->front ? (Q->rear - Q->front) : (Q->max - Q->front + Q->rear);
	}

	template<typename ElemType>
	void Queue<ElemType>::ClearQueue()
	//�ⲻ��ֱ���������������ݣ���Ϊ��ͷβָ��ͬ�ص�ʱ����Ϊ�գ���ʹ�����ڲ��������ݣ�����Ϊ��
	{
		Q->front = Q->rear;
	}

	template<typename ElemType>
	bool Queue<ElemType>::isEmpty()
	{
		return Q->front == Q->rear;
	}
}

