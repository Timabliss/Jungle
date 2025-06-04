
#include<iostream>


//int main()
//{
//	using std::cout;
//	using std::endl;
//	cout << "C   C  CCCCC  C      C      CCCCC" << endl;
//	cout << "C   C  C      C      C      C   C" << endl;
//	cout << "C   C  C      C      C      C   C" << endl;
//	cout << "CCCCC  CCC    C      C      C   C" << endl;
//	cout << "C   C  C      C      C      C   C" << endl;
//	cout << "C   C  C      C      C      C   C" << endl;
//	cout << "C   C  CCCCC  CCCCC  CCCCC  CCCCC" << endl;
//	cout << endl;
//	cout << "C   C  CCCCC  CCCCC  C      CCCC " << endl;
//	cout << "C   C  C   C  C   C  C      C   C" << endl;
//	cout << "C C C  C   C  CCCCC  C      C   C" << endl;
//	cout << "CC CC  C   C  CC     C      C   C" << endl;
//	cout << "C   C  C   C  C C    C      C   C" << endl;
//	cout << "C   C  C   C  C  C   C      C   C" << endl;
//	cout << "C   C  CCCCC  C   C  CCCCC  CCCC " << endl;
//	return 0;
//}

/*
从m个数中选择n个最大数(m>>n)
这个方案不会去重
*/
/*
void BubbleSort(int num[], int m);
int main()
{
	int nums, ches;
	cout << "请输入一共有多少个数字和需要选择的数字" << endl;
	cin >> nums >> ches;
	int* num = new int[nums];
	cout << "请依次输入数据" << endl;
	for (int i = 0; i < nums; i++)
	{
		cin >> num[i];
	}//原始数据输入
	int* selected = new int[ches];
	for (int i = 0; i < ches; i++)
	{
		selected[i] = num[i];
	}//选择前五个数填入新数组

	int flag = ches;//标记，用于指示每次循环第一个被比较的数的位置
	int sign;//标记，用于指示if语句是否执行
	while (1)
	{
		sign = 0;
		BubbleSort(selected, ches);
		int least = selected[0];//冒泡排序后，用least变量储存最小值，进行后续的比较
		for (int i = flag; i < nums; i++)
		{
			if (least < num[i])
			{
				selected[0] = num[i];
				flag = i + 1;//比较一次，下一次循环时第一个被比较的数的位置后移1
				sign = 1;
				break;
			}
		}
		if (sign == 0)
		{
			break;
		}//sign==0表明if循环不执行，说明selected数组内最小值已经大于剩余的所有的值
	}
	for (int i = 0; i < ches; i++)
	{
		cout << selected[i] << endl;
	}
	delete[] num;
	delete[] selected;
	return 0;
}
void BubbleSort(int num[], int m)
{
	int temp;
	bool flag;
	for (int i = 0; i < m - 1; i++)
	{
		flag = false;
		for (int j = 0; j < m - i - 1; j++)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j + 1];
				num[j + 1] = num[j];
				num[j] = temp;
			}
			flag = true;
		}
		if (!flag)
			break;
	}
}
*/

/*
//用分解质因数方法求最小公倍数
int main()
{
	int primetable[] = { 2,3,5,7,11,13,17,19,23,29 };
	int num[10] = { 0 };
	int times[10] = { 0 };
	int a, b;
	cout << "请输入两个数据" << endl;
	cin >> a >> b;
	for (int i = 0; i < 10; i++)
	{
		int timesA = 0;
		int timesB = 0;
		while (a % primetable[i] == 0)// 筛出这个质数在a数据中存在的次数
		{
			timesA++;
			a /= primetable[i];
		}
		while (b % primetable[i] == 0)// 筛出这个质数在b数据中存在的次数
		{
			timesB++;
			b /= primetable[i];
		}
		//挑选最大的，如果都为零说明不包含这个质数。只要有一个不为0就选它
		if (timesA > 0 || timesB > 0)
		{
			num[i] = primetable[i];
			times[i] = timesA > timesB ? timesA : timesB;
		}
		//直到都除到了1，表明没有更多的公共质因数了，就跳
		if (a == 1 && b == 1)
			break;
	}
	int sum = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < times[i]; j++)
		{
			sum *= num[i];//乘方可以转化为循环次数为乘方数的循环相乘
		}
	}
	cout << sum << endl;
	return 0;
}*/

/* 下面是简单数据结构的验证区域 */

/* 
//线性表的验证区
#include"LineList.h"
using namespace LINELIST;
int main()
{
	LineList<int> list(10);
	for (int i = 0; i < 10; i++)
		list.Insert(i, i + 1);
	list.PrintList();
 	cout << "***" << list.PosGet(3) << "***" << endl;
	for (int i = 0; i < 10; i += 2)
		list.Delete(i);
	list.PrintList();
	return 0;
}
*/
/*
//链表的验证区域
#include"LinkList.h"
using namespace LINKLIST;
int main()
{
	LinkList<char> L;
	Node<char>* head = new Node<char>;
	head->data = '#';
	if (head != nullptr)
	{
		char data;
		cout << "请依次输入10个结点的数据" << endl;
		for (int i = 0; i < 10; i++)
		{
			cin >> data;
			L.TailInsertNode(head, data);
		}
		L.PrintNodeList(head);
		cout << endl;
		L.ReverseBy2Ptr(head);
		L.PrintNodeList(head);
		cout << endl;
		L.ReverseBy3Ptr(head);
		L.PrintNodeList(head);
	}
	L.DestoryNode(head);
	return 0;
}
*/

/*
//表达式求值+栈的验证区域
#include "Stack.h"
using namespace STACK;

int Checkprior(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else
		return 3;
}

void ExpreChange(Stack<char>& operators, const string& expression, string& out_expression)
{
	int n = expression.size();
	for (int i = 0; i < n; i++)
	{
		if(expression[i] != ' ')
		{
			// 区分操作数
			if (expression[i] >= '0' && expression[i] <= '9')
			{
				while (i < n && expression[i] != ' ')
				{
					out_expression += expression[i++];
				}
				out_expression += ' ';
				i--;
			}
			// 区分负数
			else if (expression[i] == '-' && i + 1 < n && expression[i + 1] != ' ')
			{
				out_expression += '-';
				i++;
				while (i < n && expression[i] != ' ')
				{
					out_expression += expression[i++];
				}
				out_expression += ' ';
				i--;
			}
			//区分括号
			else if (expression[i] == '(')
			{
				operators.PushStack(expression[i]);
			}
			else if (expression[i] == ')')
			{
				char op;
				operators.GetTopStack(op);
				while (op != '(')
				{
					out_expression += op;
					out_expression += ' ';
					operators.PopStack();
					operators.GetTopStack(op);
				}
				operators.PopStack();
			}
			//操作符装填
			else
			{
				if (operators.isEmpty())
				{
					operators.PushStack(expression[i]);
				}
				else
				{
					char op;
					operators.GetTopStack(op);
					while (!operators.isEmpty() && Checkprior(expression[i]) <= Checkprior(op) && Checkprior(op) <= 2)
					{
						out_expression += op;
						out_expression += ' ';
						operators.PopStack();
						if (!operators.isEmpty())
							operators.GetTopStack(op);
					}
					operators.PushStack(expression[i]);
				}
			}
		}
	}

	while (!operators.isEmpty())
	{
		char op;
		operators.GetTopStack(op);
		out_expression += op;
		out_expression += ' ';
		operators.PopStack();
	}
	out_expression.pop_back();
}

void OutNum(Stack<int>& operands, Stack<char>& operators)
{
	while (operators.LengthStack() > 0)
	{
		char op;
		operators.GetTopStack(op);
		operators.PopStack();
		int x; int y; int out;
		operands.GetTopStack(x);
		operands.PopStack();
		operands.GetTopStack(y);
		operands.PopStack();

		char oper[]{ '+','-','*','/' };
		int sec = 0;
		for (int i = 0; i < 4; i++)
		{
			if (op == oper[i])
			{
				sec = i;
				break;
			}
		}
		switch (sec)
		{
		case(0):
			out = y + x;
			break;
		case(1):
			out = y - x;
			break;
		case(2):
			out = y * x;
			break;
		case(3):
			out = y / x;
			break;
		default:
			break;
		}
		operands.PushStack(out);
	}
}

void Scanstack(Stack<int>& operands, Stack<char>& operators, const string& expression)
{
	int n = expression.size();

	for (int i = 0; i < n; i++) // 入栈
	{
		if(expression[i] != ' ')
		{
			if (expression[i] >= '0' && expression[i] <= '9')//空格可以区分位数
			{
				string num = "";
				while (i < n && expression[i] != ' ')
				{
					num += expression[i++];
				}
				operands.PushStack(stoi(num));
				i--;  // 更新i的位置
			}
			else if (expression[i] == '-')//区分是负数还是减号
			{
				if (i + 1 < n && (expression[i + 1] == ' ') || i + 1 == n)
				{
					operators.PushStack(expression[i]);
					OutNum(operands, operators);
				}
				else
				{
					string num = "";
					i++;
					while (i < n && expression[i] != ' ')
					{
						num += expression[i++];
					}
					operands.PushStack(0 - stoi(num));
					i--;
				}
			}
			else
			{
				operators.PushStack(expression[i]);
				OutNum(operands, operators);
			}
		}
	}
}

const int MAXSIZE = 100;
int main()
{

	Stack<int> operands(MAXSIZE);
	Stack<char> operators(MAXSIZE);


	//这个问题实际上被简化的非常严重，最完美的是不需要依靠空格，按照人话输入就能实现运算
	//逆波兰表达式，取消了括号的优先级，但是为了仿照人话输入，这里还是采取了中缀表达式作为输入，再转为后缀表达式

	string expression;
	cout << "请输入中缀计算表达式:操作数与操作符之间请以空格间隔" << endl;
	getline(cin, expression);
	string out_expression;

	ExpreChange(operators, expression, out_expression);
	Scanstack(operands, operators, out_expression);
	OutNum(operands, operators);

	int finals;
	operands.GetTopStack(finals);
	cout << "最终结果为" << finals << endl;
	return 0;
}
*/

/*
//队列排序+优先队列+队列的验证区域
#include"Queue.h"
using namespace QUEUE;
int main()
{
	Queue<int>* queues[2]{};//生成一个Queue<int>类型的数组
	for (int i = 0; i < 2; i++)
	{
		queues[i] = new Queue<int> (20);//为数组的每个部分开辟空间
	}

	int t[10]{ 0 };
	cout << "请依次输入要排序的10个数" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> t[i];
	}

	queues[0]->EnQueue(t[0]);//先入队列1
	int count = 1;
	int k = 0;
	int j = 1;
	//选择器,进入时1对应空队列，出来是0对应空队列
	//先把比要排序的数字小的推到另外一个空队列里面去，然后这个队列再补入这个要比较的数字，然后把剩下的继续推进去
	while (count < 10)
	{
		while (queues[k]->GetHeadElem() <= t[count] && !queues[k]->isEmpty())
		{
			queues[j]->EnQueue(queues[k]->GetHeadElem());
			queues[k]->OutQueue();
		}
		queues[j]->EnQueue(t[count++]);
		while (!queues[k]->isEmpty())
		{
			queues[j]->EnQueue(queues[k]->GetHeadElem());
			queues[k]->OutQueue();
		}
		//交换队列下标
		int temp;
		temp = j;
		j = k;
		k = temp;
	}

	while (!queues[1]->isEmpty())
	{
		cout << queues[1]->GetHeadElem() <<" ";
		queues[1]->OutQueue();
	}
	return 0;
}*/
/*
#include"BinaryTree.h"
#include"Queue.h"
using namespace QUEUE;
using namespace BINARYTREE;


//简单二叉树的验证区域 1：创建二叉树，然后进行前后中序遍历，然后使用层序遍历
int main()
{
	BiTNode<char>* root;//不急初始化，建树函数内部会初始化
	BiT<char> T;//类的实例化
	cout << "请输入树的数据序列，以空格间隔，以#号作为叶子标识" << endl;
	T.CreatTree(root);
	T.Preorder(root);
	cout << endl;
	T.Inorder(root);
	cout << endl;
	T.Postorder(root);
	cout << endl;
	Queue<BiTNode<char>*>* queue = new Queue<BiTNode<char>*>(20);
	T.Floororder(root, queue);

	T.RemoveTree(root);
	return 0;
}*/
/*
* 算绩点的
int main()
{
	int sums;
	cin >> sums;
	int* scors = new int[sums];
	double* oses = new double[sums];
	double count1 = 0;
	double count2 = 0;
	for (int i = 0; i < sums; i++)
	{
		cin >> scors[i] >> oses[i];
		count1 += oses[i];
		count2 += oses[i] * scors[i];
	}
	cout << count2 / count1 << endl;
	return 0;
}*/
/*
inline double squerE(double x)
{
	return x * x;
}
using Fun_c= const double* (*)(const double*, int);
const double* myfun(const double*, int);
int main()
{
	int ret = 3;
	int& rum = ret;
	double a = 1.0; double b = 2.4; double c = 8.4;
	double pf[3] = { a,b,c };
	double (*pd)[3] = &pf;
	Fun_c strs = myfun;
	std::cout << sizeof(pf) << std::endl;
	std::cout << sizeof(&pf[0]) << std::endl;
	std::cout << strs(pf, 3) << std::endl;
	double d = 2;
	double r = squerE(d++);
	cout << r <<" "<< d << endl;
	double& reu = d;
	cout << reu << endl;
	cout << &reu << endl;
	double j = 15.0;
	double&& str = j * 25 + 10.0;
	cout << str << endl;
	return 0;
}
const double* myfun(const double* arr, int n)
{
	return ( & arr[1] + n);
}
*/
/*
template <typename T1,typename T2>
auto str(T1& a, T2& b) ->decltype(a+b)
{
	decltype(a + b) xpr;
	xpr = a + b;
	return xpr;
}

int main()
{
	int a = 5;
	double s = 6.7;
	double r=str<int, double>(a, s);
	cout << r << endl;
	return 0;
}*/
/*
#include<new>
const int N = 5;
thread_local const int MAX = 10;

char buffer[N];
void strcount(const char*);
int main()
{
	char input[MAX];
	char next;

	std::cout << "输入" << std::endl;
	cin.get(input, MAX);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);

		strcount(input);
		std::cout << "输入下一行" << endl;
		cin.get(input, MAX);
	}
	std::cout << "ssss" << endl;

	//控制输入技术；cin.get（input,MAX)首先读取一整行的前MAX-1个数据，将后面的所有数据留在缓冲区
	//如果该方法成功输入非换行符，那么将会返回一个有效的cin对象，while循环自动将cin转为bool值的True，否则为false
	//接下来，首先读取剩余的数据，如果是换行符就执行strcount函数，确定输入字符串的字符个数以及总输入个数
	//完成后继续输入下一行。

	double* pd = new (buffer + N * sizeof(double)) double[N];
	delete[] pd;
	return 0;
}

void strcount(const char* str)
{
	static int total = 0;
	int count = 0;

	std::cout << "输入为：" << str << endl;
	while ((*str))
	{
		count++;
		str++;
	}
	//针对于字符串，这个while循环可以有效进行，直到且总能遇到行末的'\0'终止
	total += count;
	std::cout << "字符数为：" << count << endl;
	std::cout << "已输入总数为：" << total << endl;
}
*/
/*
int able(const int&, const int&, const int&);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int out = able(a, b, c);
	cout << out << endl;
}

int able(const int& a, const int& b, const int& c)
{
	return a > b ? (c > a ? c : a) : (c > b ? c : b);
}*/

/*
template <typename ...AR>
auto product(AR... nums)
{
	return (1*...*nums);
}

int main()
{
	auto out = product(1.1, 2.1, 3.4);
	cout << out << endl;
	return 0;
}
*/

//#include<string>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::ostream;
//using std::istream;
//using std::string;
//using std::getline;
//
//
//static char* strcopy(char* dest, const char* src)
//{
//	char* redest = dest;
//	while ((*dest++ = *src++) != '\0')
//	{
//	}
//	return redest;
//}
//
//class Student
//{
//private:
//	string name;
//	char* ID;
//	int age;
//	double score;
//	static constexpr int ID_LIMIT = 11;
//public:
//	Student() :name("###"), ID(new char[ID_LIMIT]), age(0), score(0) {}
//
//	Student(const string& n, const char* I, int a, double s) :name(n), age(a), score(s)
//	{
//		ID = new char[ID_LIMIT];
//		strcopy(ID, I);
//		cout << "Student: " << name << " has been in the database" <<" by func1"<< endl;
//	}
//	Student(const Student& s) :name(s.name), age(s.age), score(s.score)
//	{
//		ID = new char[ID_LIMIT];
//		strcopy(ID, s.ID);
//		cout << "Student: " << name << " has been in the database" << " by func2" << endl;
//	}
//	~Student()
//	{
//		delete[] ID;
//		cout << "Student: " << name << " has been out of the database" << endl;
//	}
//
//	const string& check_name() const { return name; };
//	string& get_name() { return name; };
//
//	const char* check_ID() const { return ID; };
//	char* get_ID() { return ID; };
//
//	int get_age() { return age; };
//	double get_score() { return score; };
//
//	Student& operator=(const Student&);
//	friend istream& operator>>(istream&, Student&);
//	friend ostream& operator<<(ostream&, const Student&);
//};
//
//Student& Student::operator=(const Student& _base)
//{
//	if (this == &_base)
//		return *this;
//	delete[] ID;
//	name = _base.name;
//	age = _base.age;
//	score = _base.score;
//	ID = new char[ID_LIMIT];
//	strcopy(ID, _base.check_ID());
//	return *this;
//}
//
//istream& operator>>(istream& input, Student& _base)
//{
//	getline(input, _base.get_name());
//	input.getline(_base.get_ID(), Student::ID_LIMIT).clear();
//	while (input && input.get() != '\n')
//		continue;
//	input >> _base.age >> _base.score;
//	input.ignore();
//	return input;
//}
//
//ostream& operator<<(ostream& output, const Student& _base)
//{
//	output << "Student: " << _base.name
//		<< " owns ID:" << _base.ID
//		<< " and owns age: " << _base.age
//		<< " and owns score: " << _base.score << endl;
//	return output;
//}

#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
const double pi = 3.1415;

class Base_Model
{	
	const string name;
	friend ostream& operator<<(ostream&, const Base_Model&);
protected:
	Base_Model(const string& NAME="No shape") :name(NAME){};
	Base_Model(const Base_Model& base) = default;
public:
	virtual int get_nums() const = 0;
	virtual double get_area()const = 0;
	Base_Model& operator=(const Base_Model&) = delete;
	virtual ~Base_Model()= default;
	virtual ostream& print(ostream& output)const=0;
	
};
ostream& operator<<(ostream&output, const Base_Model& base)
{
	return base.print(output);
}

class Circle :public Base_Model
{
	double radius;
	inline static int nums = 0;
public:
	Circle(double rad = 0.0) :Base_Model("Circle"), radius(rad) { nums++; };
	Circle(const Circle& base) :Base_Model(base), radius(base.radius) { nums++; };
	Circle& operator=(const Circle& base)
	{
		if (this == &base)
			return *this;
		radius = base.radius;
		return *this;
	}
	explicit operator double() const { return radius; };
	int get_nums()const override { return nums; };
	double get_area()const override{ return pi * radius * radius; }
	ostream& print(ostream& output)const override{ output << radius << endl; return output; }
	~Circle() override { nums--; };
};


class Rectangle :public Base_Model
{
	double length;
	double width;
	inline static int nums = 0;
public:
	Rectangle(double len = 0.0,double wid=0.0) :Base_Model("Rectangle"), length(len),width(wid) { nums++; };
	Rectangle(const Rectangle& base) :Base_Model(base), length(base.length),width(base.width) { nums++; };
	Rectangle& operator=(const Rectangle& base)
	{
		if (this == &base)
			return *this;
		length = base.length;
		width = base.width;
		return *this;
	}
	int get_nums()const override { return nums; };
	double get_area()const override { return length * width; };
	ostream& print(ostream& output)const override { output << length << endl<<width<<endl; return output; }
	~Rectangle() override { nums--; };
};

int main()

{
	Base_Model** arr = new Base_Model * [2];
	arr[0] = new Circle(5.6);
	arr[1] = new Rectangle(1.5, 4.5);
	cout << arr[0]->get_area() << endl;
	cout << arr[0]->get_nums() << endl;
	cout << *arr[0];
	cout << arr[1]->get_nums() << endl;
	cout << arr[1]->get_area() << endl;
	cout << *arr[1];
	for (int i = 0; i < 2; i++)
		delete arr[i];
	int a = 1;
	cout << (a == 1 && a == 2 && a == 3) << endl;
}
