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
		//无需包含Q队列的指针，类对象调用时自带一个this指针
	};


	template<typename ElemType>
	Queue<ElemType>::Queue(int MAXSIZE)
	{
		Q = new SqQueue; //可以把这句话跟private里面的连在一起看，是一个非常常见的指针类声明方法
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
			throw runtime_error("队列已满");
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
			throw runtime_error("队列为空");
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
			throw runtime_error("队列为空");
		}
		else
		{
			return Q->data[(Q->front + 1) % Q->max];
		}
	}

	template<typename ElemType>
	int Queue<ElemType>::QueueLength()//注意头尾的相对位置
	{
		return Q->rear >= Q->front ? (Q->rear - Q->front) : (Q->max - Q->front + Q->rear);
	}

	template<typename ElemType>
	void Queue<ElemType>::ClearQueue()
	//这不是直接清除队列里的数据，认为当头尾指针同地点时队列为空，即使队列内部还有数据，都认为空
	{
		Q->front = Q->rear;
	}

	template<typename ElemType>
	bool Queue<ElemType>::isEmpty()
	{
		return Q->front == Q->rear;
	}
}

