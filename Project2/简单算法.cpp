
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
��m������ѡ��n�������(m>>n)
�����������ȥ��
*/
/*
void BubbleSort(int num[], int m);
int main()
{
	int nums, ches;
	cout << "������һ���ж��ٸ����ֺ���Ҫѡ�������" << endl;
	cin >> nums >> ches;
	int* num = new int[nums];
	cout << "��������������" << endl;
	for (int i = 0; i < nums; i++)
	{
		cin >> num[i];
	}//ԭʼ��������
	int* selected = new int[ches];
	for (int i = 0; i < ches; i++)
	{
		selected[i] = num[i];
	}//ѡ��ǰ���������������

	int flag = ches;//��ǣ�����ָʾÿ��ѭ����һ�����Ƚϵ�����λ��
	int sign;//��ǣ�����ָʾif����Ƿ�ִ��
	while (1)
	{
		sign = 0;
		BubbleSort(selected, ches);
		int least = selected[0];//ð���������least����������Сֵ�����к����ıȽ�
		for (int i = flag; i < nums; i++)
		{
			if (least < num[i])
			{
				selected[0] = num[i];
				flag = i + 1;//�Ƚ�һ�Σ���һ��ѭ��ʱ��һ�����Ƚϵ�����λ�ú���1
				sign = 1;
				break;
			}
		}
		if (sign == 0)
		{
			break;
		}//sign==0����ifѭ����ִ�У�˵��selected��������Сֵ�Ѿ�����ʣ������е�ֵ
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
//�÷ֽ���������������С������
int main()
{
	int primetable[] = { 2,3,5,7,11,13,17,19,23,29 };
	int num[10] = { 0 };
	int times[10] = { 0 };
	int a, b;
	cout << "��������������" << endl;
	cin >> a >> b;
	for (int i = 0; i < 10; i++)
	{
		int timesA = 0;
		int timesB = 0;
		while (a % primetable[i] == 0)// ɸ�����������a�����д��ڵĴ���
		{
			timesA++;
			a /= primetable[i];
		}
		while (b % primetable[i] == 0)// ɸ�����������b�����д��ڵĴ���
		{
			timesB++;
			b /= primetable[i];
		}
		//��ѡ���ģ������Ϊ��˵�����������������ֻҪ��һ����Ϊ0��ѡ��
		if (timesA > 0 || timesB > 0)
		{
			num[i] = primetable[i];
			times[i] = timesA > timesB ? timesA : timesB;
		}
		//ֱ����������1������û�и���Ĺ����������ˣ�����
		if (a == 1 && b == 1)
			break;
	}
	int sum = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < times[i]; j++)
		{
			sum *= num[i];//�˷�����ת��Ϊѭ������Ϊ�˷�����ѭ�����
		}
	}
	cout << sum << endl;
	return 0;
}*/

/* �����Ǽ����ݽṹ����֤���� */

/* 
//���Ա����֤��
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
//�������֤����
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
		cout << "����������10����������" << endl;
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
//���ʽ��ֵ+ջ����֤����
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
			// ���ֲ�����
			if (expression[i] >= '0' && expression[i] <= '9')
			{
				while (i < n && expression[i] != ' ')
				{
					out_expression += expression[i++];
				}
				out_expression += ' ';
				i--;
			}
			// ���ָ���
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
			//��������
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
			//������װ��
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

	for (int i = 0; i < n; i++) // ��ջ
	{
		if(expression[i] != ' ')
		{
			if (expression[i] >= '0' && expression[i] <= '9')//�ո��������λ��
			{
				string num = "";
				while (i < n && expression[i] != ' ')
				{
					num += expression[i++];
				}
				operands.PushStack(stoi(num));
				i--;  // ����i��λ��
			}
			else if (expression[i] == '-')//�����Ǹ������Ǽ���
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


	//�������ʵ���ϱ��򻯵ķǳ����أ����������ǲ���Ҫ�����ո񣬰����˻��������ʵ������
	//�沨�����ʽ��ȡ�������ŵ����ȼ�������Ϊ�˷����˻����룬���ﻹ�ǲ�ȡ����׺���ʽ��Ϊ���룬��תΪ��׺���ʽ

	string expression;
	cout << "��������׺������ʽ:�������������֮�����Կո���" << endl;
	getline(cin, expression);
	string out_expression;

	ExpreChange(operators, expression, out_expression);
	Scanstack(operands, operators, out_expression);
	OutNum(operands, operators);

	int finals;
	operands.GetTopStack(finals);
	cout << "���ս��Ϊ" << finals << endl;
	return 0;
}
*/

/*
//��������+���ȶ���+���е���֤����
#include"Queue.h"
using namespace QUEUE;
int main()
{
	Queue<int>* queues[2]{};//����һ��Queue<int>���͵�����
	for (int i = 0; i < 2; i++)
	{
		queues[i] = new Queue<int> (20);//Ϊ�����ÿ�����ֿ��ٿռ�
	}

	int t[10]{ 0 };
	cout << "����������Ҫ�����10����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> t[i];
	}

	queues[0]->EnQueue(t[0]);//�������1
	int count = 1;
	int k = 0;
	int j = 1;
	//ѡ����,����ʱ1��Ӧ�ն��У�������0��Ӧ�ն���
	//�Ȱѱ�Ҫ���������С���Ƶ�����һ���ն�������ȥ��Ȼ����������ٲ������Ҫ�Ƚϵ����֣�Ȼ���ʣ�µļ����ƽ�ȥ
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
		//���������±�
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


//�򵥶���������֤���� 1��������������Ȼ�����ǰ�����������Ȼ��ʹ�ò������
int main()
{
	BiTNode<char>* root;//������ʼ�������������ڲ����ʼ��
	BiT<char> T;//���ʵ����
	cout << "�����������������У��Կո�������#����ΪҶ�ӱ�ʶ" << endl;
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
* �㼨���
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

	std::cout << "����" << std::endl;
	cin.get(input, MAX);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);

		strcount(input);
		std::cout << "������һ��" << endl;
		cin.get(input, MAX);
	}
	std::cout << "ssss" << endl;

	//�������뼼����cin.get��input,MAX)���ȶ�ȡһ���е�ǰMAX-1�����ݣ�������������������ڻ�����
	//����÷����ɹ�����ǻ��з�����ô���᷵��һ����Ч��cin����whileѭ���Զ���cinתΪboolֵ��True������Ϊfalse
	//�����������ȶ�ȡʣ������ݣ�����ǻ��з���ִ��strcount������ȷ�������ַ������ַ������Լ����������
	//��ɺ����������һ�С�

	double* pd = new (buffer + N * sizeof(double)) double[N];
	delete[] pd;
	return 0;
}

void strcount(const char* str)
{
	static int total = 0;
	int count = 0;

	std::cout << "����Ϊ��" << str << endl;
	while ((*str))
	{
		count++;
		str++;
	}
	//������ַ��������whileѭ��������Ч���У�ֱ��������������ĩ��'\0'��ֹ
	total += count;
	std::cout << "�ַ���Ϊ��" << count << endl;
	std::cout << "����������Ϊ��" << total << endl;
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
