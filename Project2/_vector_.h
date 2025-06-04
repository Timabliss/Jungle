#pragma once
#include<iostream>
#include<initializer_list>
// ��ʼ���б�����ʹ���б��ʼ��vector��

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
	iterator _begin; // ��Ϊ�����ͷ����ʵ����Ҳ����ͨ��_beginֱ�ӷ�������
	iterator _end;
	iterator _capacity;

	// vector��ֻ�Ǵ洢��3��ָ�룬Ҳ����vector��ĵ�ַ�£�������ָ�룬�����ջ����
	// ����ָ������ݣ��п����ڶ���Ҳ������ջ����ȡ����ʵ��
	// ���vector�����ָ���ŵ�λ���ǲ�ͬ��
public:

	size_t size() const
	{
		return _end - _begin;
	}

	ElemType& operator[](const size_t delta) const
	{
		// �����������鳬�磻ͨ��_beginֱ�ӷ���
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
	// ��ø���explicit��ǣ���Ϊ����������Ķ�̬������nums���п���ִ����ʽת��
	{
		if(nums > 0)
		{
			_begin = new ElmeType[nums];
			_end = _capacity = _begin + nums;
			for (size_t i = 0; i < nums; i++)
				_begin[i] = _El;
			// ����Ǽ����ͣ���ֵ�Ž�ֱ�Ӹ��ƣ���������Ǹ�������ͣ���ֵ����Ҫ���أ��Դ����Ч��
		}
		else
			_begin = _end = _capacity = nullptr;
			// ����С��0�����ݳ��ȣ��Զ����ؿ�ָ��
	}
	
	vector(const vector& Vctr)
		:_begin((Vctr.size()>0) ? new ElemType* [Vctr.size()] : nullptr), _end(_begin + Vctr.size()), _capacity(_end)
		// �¸��ƹ��죬�������ֹ����ǳ������Ҳ����ֻ�����˵�ַ���⽫�ᵼ����ִ����������ʱ������ɾ��ͬһ����ַ�����Σ��
		// ͬʱ�������ֻ���ڳ�ʼ��ʱ��������Ҫʹ��һ��ԭ�ж����ʼ��һ���µĶ��󣬾ͻ�����������
	{
		for (size_t i = 0; i < Vctr.size(); i++)
			_begin[i] = Vctr[i];
	}

	vector& operator=(const vector& Vctr) 
	// ��ֵ��������أ�ֻ���ڰ�һ���¶��󸳸�һ���ɶ���ʱʹ�ã�Ҳ���������������ԭ���ʹ���
	// �����������vector��ʵ�֣���˲�����Ҫ��֤��ͬ���ȵ�vector
	{
		if (this != &Vctr) // �Է�����ִ��delete����ʱ�Ͱ����������
		{
			delete[] _begin; 
			// ��ֵǰ����Ҫ��ԭ�����������ˣ�����ָ������ڴ��ָ���뿪������ڴ�ͱ��˷���
			// Ҳ���Ǹ��Ƹ�ֵʵ���������¿���һ���ط��������µ�����
			// ����ָ��_begin���ᱻ���ˣ��ɱ�������������������ջ

			size_t recapacity = Vctr.size();
			_begin =(recapacity>0) ? new ElemType[recapacity]: nullptr;
			_end = _capacity = _begin + recapacity;
	
			for (size_t i = 0;i<recapacity;i++)
				_begin[i] = Vctr[i];
		}
		return *this; // ����һ�����ã��Դ�֧������=�Ÿ�ֵ
	}

	vector& operator=(vector&& R_Vctr) noexcept // �ƶ���ֵ�������ڵ���ʱ�����޸ĳɱ������µ���ֱ�ӽӹ������ʱ����
	{
		if (this != &R_Vctr) // ��ֹ��ֵ��ֵ�Լ�
		{
			delete[] _begin;

			_begin = R_Vctr._begin;
			_capacity = R_Vctr._capacity;
			_end = R_Vctr._end;
			// ֱ���ƶ�ָ�뼴�ɣ�������ʱ���󽫻ᱻ��ֵ�����ӹ�

			R_Vctr._begin = nullptr;
			R_Vctr._capacity = nullptr;
			R_Vctr._end = nullptr;
			// ��ֵ����ָ���ÿգ���ֹthis��R_Vctr��ָ����ͬ���࣬��R_Vctr�˳���ᴥ��������������this�˳���Ҳ�ᴥ��
		}
		return *this;
	}

	vector(vector&& R_Vctr) noexcept 
	// �ƶ�����, noexcept�����˲������Բ��᷵�ش��󣬱��������Է���ʹ�á�������������ܲ�ȡ���صظ��ƹ���
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
