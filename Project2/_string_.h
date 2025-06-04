#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ostream;
using std::istream;

static char* strcopy(char* dest, const char* src)
{
	char* redest = dest;
	while ((*dest++ = *src++) != '\0')
		;
	return redest;
}

class String
{
private:
	char* begin;
	size_t length;
	inline static int nums = 0;
	static constexpr int LENMAX = 1000;
public:
	// ���캯��(Ĭ��+C����ַ���+���ƹ���+��ֵ���ã�����һ�����е���ȥ��ʼ��һ��û�е���
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept;
	// ��ֵ�����,��Ҫ�ǰ����е���ʵ�������ַ���������һ�����е���
	String& operator=(const char*);
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	// �ⲿ�ӿ���
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	int LenOfStr() const { return int(length); };
	char& operator[](int i); // һ���������ȵ��ǲ�����ȫ���������������Ѿ�ȷ�����˷�Χ������,ֻ���ھ���
	//char& at(int i);// ��ȫ����������ȷ�������Ƿ�ȫ�����򱨴�
	const char& operator[](int i) const; // ���޷���
	~String();
};

String::String():begin(new char[1]),length(0)
{
	begin[0] = '\0';
	nums++;
}

String::String(const char* _base)
{
	if(_base)
	{
		length = std::strlen(_base);
		begin = new char[length + 1];
		strcopy(begin, _base);
	}
	else
	{
		begin = new char[1];
		length = 0;
		begin[0] = '\0';
	}
	nums++;
}

String::String(const String& _base)
{
	length = _base.length;
	begin = new char[length + 1];
	strcopy(begin, _base.begin);
	nums++;
}

String::String(String&& base__)noexcept: length(base__.length),begin(base__.begin) 
{
	base__.begin = nullptr;
	base__.length = 0;
}

String& String::operator=(const char* _base)
{
	String temp(_base);
	*this = temp;
	return *this;
}

String& String::operator=(const String& _base)
{
	if (this != &_base) //this���ַ��һ���࣬��û���ж��Ƿ�ȫ�ȵĽӿ�
	{
		delete[] begin;

		length = _base.length;
		begin = new char[length + 1];
		strcopy(begin, _base.begin);
	}
	return *this;
}

String& String::operator=(String&& _base) noexcept
{
	if (this != &_base)
	{
		delete[] begin;

		length = _base.length;
		begin = _base.begin;

		_base.begin = nullptr;
		_base.length = 0;
	}
	return *this;
}

ostream& operator<<(ostream& output, const String& _base)
{
	output << _base.begin;
	return output;
}

istream& operator>>(istream& input, String& _base)
{
	char temp[String::LENMAX];
	input.getline(temp, String::LENMAX);
	if(input)
		_base = temp;

	input.clear();
	while (!input.eof() && input.get() != '\n')
		continue;
	// ���������
	return input;
}

char& String::operator[](int i)
{
	if (i < 0 || i >= LenOfStr())
		cerr << "����λ�� "<< i <<" �Ѿ�����"<<endl;
	return begin[i];
}

//char& String::at(int i)
//{
//	if (i < 0 || i >= LenOfStr())
//		;
//}

const char& String::operator[](int i) const
{
	return begin[i];
}

String::~String()
{
	delete[] begin;
	nums--;
}

