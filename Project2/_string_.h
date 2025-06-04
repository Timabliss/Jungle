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
	// 构造函数(默认+C风格字符串+复制构造+右值引用），用一个已有的类去初始化一个没有的类
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept;
	// 赋值运算符,主要是把已有的类实例或者字符串赋给另一个已有的类
	String& operator=(const char*);
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	// 外部接口组
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	int LenOfStr() const { return int(length); };
	char& operator[](int i); // 一种性能优先但是不够安全的做法，信任于已经确定好了范围的输入,只存在警告
	//char& at(int i);// 安全的做法，会确认输入是否安全，否则报错
	const char& operator[](int i) const; // 仅限访问
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
	if (this != &_base) //this解地址是一个类，类没有判断是否全等的接口
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
	// 清空输入流
	return input;
}

char& String::operator[](int i)
{
	if (i < 0 || i >= LenOfStr())
		cerr << "输入位置 "<< i <<" 已经超界"<<endl;
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

