#pragma once
#include<iostream>
#include<vector>
#include<stdexcept>

namespace STACK
{
	template<typename ElemType>
	class Stack
	{
		std::vector<ElemType> data;
		int max;

	public:
		explicit Stack(int MAXSIZE);
		~Stack();

		void PushStack(const ElemType&);
		void PopStack();
		void PopStack(ElemType&);
		void GetTopStack(ElemType&) const;
		bool isEmpty() const;
		size_t LengthStack() const;
	};

	template<typename ElemType>
	Stack<ElemType>::Stack(int MAXSIZE)
		:data(),max(MAXSIZE)
	{
		data.reserve(MAXSIZE);
		std::cout << "A " << max << " lengths stack has been constructed" << std::endl;
	}

	template<typename ElemType>
	Stack<ElemType>::~Stack()
	{
		std::cout << "A " << max << " lengths stack has been destoryed" << std::endl;
	}

	template<typename ElemType>
	void Stack<ElemType>::PushStack(const ElemType& x)
	{
		if (data.size() == max)
			throw std::overflow_error("Stack overflow");
		else
		{
			data.push_back(x);
		}
	}

	template<typename ElemType>
	void Stack<ElemType>::PopStack()// LIFO,弹出最后一个元素,
	{
		if (data.size())
		{
			data.pop_back();
		}
		else
			throw std::underflow_error("Stack underflow");
	}

	template<typename ElemType>
	void Stack<ElemType>::PopStack(ElemType& x)//LIFO,弹出最后一个元素,并且提供被弹出的值
	{
		if (data.size())
		{
			x = data[data.size()-1];
			data.pop_back();
		}
		else
			throw std::underflow_error("Stack underflow");
	}
	template<typename ElemType>
	void Stack<ElemType>::GetTopStack(ElemType& x) const
	{
		if (data.size()>0)
		{
			x = data[data.size()-1];
		}
		else
			throw std::underflow_error("Stack is empty");
	}

	template<typename ElemType>
	size_t Stack<ElemType>::LengthStack() const 
	{
		return data.size();
	}

	template<typename ElemType>
	bool Stack<ElemType>::isEmpty() const 
	{
		return data.empty();
	}
}


