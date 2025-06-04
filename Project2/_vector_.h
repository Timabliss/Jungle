#pragma once
#include<iostream>
#include<initializer_list>
// 初始化列表允许使用列表初始化vector类

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

template <typename ElemType>
class vector
{
	using iterator = ElemType*;
private:
	iterator _begin; // 作为数组的头部，实际上也可以通过_begin直接访问数据
	iterator _end;
	iterator _capacity;

	// vector类只是存储了3个指针，也就是vector类的地址下，有三个指针，存放在栈区；
	// 而其指向的数据，有可能在堆区也可能在栈区，取决于实现
	// 因此vector类和其指针存放的位置是不同的
public:

	size_t size() const
	{
		return _end - _begin;
	}

	ElemType& operator[](const size_t delta) const
	{
		// 这个函数不检查超界；通过_begin直接访问
		return _begin[delta];
	}

	vector() :_begin(nullptr), _end(nullptr), _capacity(nullptr) {};

	vector(std::initializer_list<ElemType> init_list)
	{
		size_t recapacity = init_list.size();
		_begin = new ElemType[recapacity];
		_end = _capacity = _begin + recapacity;

		for (size_t i = 0; i < recapacity; i++)
			_begin[i] = *(init_list.begin() + i);
	}

	explicit vector(size_t nums = 0,const ElemType& _El=ElemType()) 
	// 最好附带explicit标记，因为特征标里面的动态参数是nums，有可能执行隐式转换
	{
		if(nums > 0)
		{
			_begin = new ElmeType[nums];
			_end = _capacity = _begin + nums;
			for (size_t i = 0; i < nums; i++)
				_begin[i] = _El;
			// 如果是简单类型，赋值号将直接复制，但是如果是更大的类型，赋值号需要重载，以此提高效率
		}
		else
			_begin = _end = _capacity = nullptr;
			// 对于小于0的数据长度，自动返回空指针
	}
	
	vector(const vector& Vctr)
		:_begin((Vctr.size()>0) ? new ElemType* [Vctr.size()] : nullptr), _end(_begin + Vctr.size()), _capacity(_end)
		// 新复制构造，深拷贝。防止进行浅拷贝，也就是只拷贝了地址，这将会导致在执行析构函数时，两次删除同一个地址，造成危险
		// 同时这个构造只用在初始化时，假设需要使用一个原有对象初始化一个新的对象，就会调用这个函数
	{
		for (size_t i = 0; i < Vctr.size(); i++)
			_begin[i] = Vctr[i];
	}

	vector& operator=(const vector& Vctr) 
	// 赋值运算符重载，只能在把一个新对象赋给一个旧对象时使用，也就是两个对象必须原本就存在
	// 仅对于这里的vector类实现，因此并不需要保证相同长度的vector
	{
		if (this != &Vctr) // 以防在先执行delete操作时就把数据清除了
		{
			delete[] _begin; 
			// 赋值前，需要把原来的数据清退，否则指向这块内存的指针离开，这块内存就被浪费了
			// 也就是复制赋值实际上是重新开辟一个地方用来存新的数据
			// 但是指针_begin不会被清退，由编译器结束函数后清理栈

			size_t recapacity = Vctr.size();
			_begin =(recapacity>0) ? new ElemType[recapacity]: nullptr;
			_end = _capacity = _begin + recapacity;
	
			for (size_t i = 0;i<recapacity;i++)
				_begin[i] = Vctr[i];
		}
		return *this; // 返回一个引用，以此支持连续=号赋值
	}

	vector& operator=(vector&& R_Vctr) noexcept // 移动赋值，将存在的临时对象修改成变量，新的类直接接管这个临时变量
	{
		if (this != &R_Vctr) // 防止右值赋值自己
		{
			delete[] _begin;

			_begin = R_Vctr._begin;
			_capacity = R_Vctr._capacity;
			_end = R_Vctr._end;
			// 直接移动指针即可，这样临时对象将会被左值变量接管

			R_Vctr._begin = nullptr;
			R_Vctr._capacity = nullptr;
			R_Vctr._end = nullptr;
			// 右值所有指针置空，防止this和R_Vctr都指向相同的类，在R_Vctr退出后会触发析构函数，而this退出后也会触发
		}
		return *this;
	}

	vector(vector&& R_Vctr) noexcept 
	// 移动构造, noexcept表明此操作绝对不会返回错误，编译器可以放心使用。否则编译器可能采取保守地复制构造
		:_begin(R_Vctr._begin),_end(R_Vctr._end),_capacity(R_Vctr._capacity)
	{
		R_Vctr._begin = nullptr;
		R_Vctr._capacity = nullptr;
		R_Vctr._end = nullptr;
	}


	friend void swap(vector& first, vector& second) noexcept
	{
		std::swap(first._begin, second._begin);
		std::swap(first._end, second._end);
		std::swap(first._capacity, second._capacity);
	}

	friend ostream& operator<<(ostream& output,const vector& Vctr)
	{
		for (size_t i=0;i<Vctr.size();i++)
		{
			cout << Vctr[i] << " ";
		}
		return output;
	}

	~vector() 
	{
		delete[] _begin;
	}
};
