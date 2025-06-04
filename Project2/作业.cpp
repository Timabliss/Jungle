#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
/* 1.1
template<typename T>
T max(T a, T b, T c)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	return a;
}
int main()
{
	int jug;
	cin >> jug;
	if (jug == 1)
	{
		int i1, i2, i3, i_max;
		cin >> i1 >> i2 >> i3;
		i_max = max(i1, i2, i3);
		cout << i_max;
	}
	else if (jug == 2)
	{
		float f1, f2, f3, f_max;
		cin >> f1 >> f2 >> f3;
		f_max = max(f1, f2, f3);
		cout << f_max;
	}
	else
	{
		double d1, d2, d3, d_max;
		cin >> d1 >> d2 >> d3;
		d_max = max(d1, d2, d3);
		cout << d_max;
	}
	return 0;
}*/ 

/* 1.2
#define MAX 20
int main()
{
	string s[MAX];
	int i = 0;
	do
	{
		cin >> s[i];
		i++;

	} while (getchar()!= '\n');
	cout << s[i-1];
	for (int j = i - 2; j >= 0; j--)
	{
		cout << ' ' << s[j];
	}
	return 0;
}*/

/* 1.3
int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;
	int i1 = stoi(s1);
	int i2 = stoi(s2);
	cout << i1 + i2 << endl;
	return 0;
}*/

/* 1.4
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);//ע��C++�����˿ո�ʹ��getline���пո�
	int len1 = s1.length();
	int len2 = s2.length();
	int i=0,flag=0;
	for (; i < len1-len2+1; i++)
	{
		string temp = s1.substr(i, len2);
		if (temp == s2)
		{
			cout << i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << -1;
	}
	return 0;
}*/

/* 1.5
int main()
{
	string num;
	cin >> num;
	int len = num.length();
	int sum = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		sum *= 10;
		sum += (num[i] - 48);
	}
	string temp = to_string(sum);
	if (temp == num)
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}*/

/* 1.6
int max(int arr[],int n)
{
	int temp=arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}
int main()
{
	int k;
	cin >> k;
	int arr[100] = { 0 };
	int count = 0;
	int sum[100] = { 0 };
	int num = 0;
	int sry[100] = { 0 };
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0)
			count++;
	}
	if (count == k)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i;j++)
		{
			num += arr[i + j];
			sum[j] = num;
		}
		sry[i] = max(sum, k - i);
		sum[k - 1 - i] = 0;
		num = 0;
	}
	cout << max(sry, k);
	return 0;
}*/

/* //����ʽ����������
int main()
{
	int anums, bnums;
	cout << "���������ʽA�Ͷ���ʽB�Ĵ���" << endl;
	cin >> anums >> bnums;
	double* astir = new double[anums+1];
	double* bstir = new double[bnums+1];
	cout << "�������������ʽA�����ϵ��" << endl;
	for (int i = 0; i <= anums; i++)
		cin >> astir[i];
	cout << "�������������ʽB�����ϵ��" << endl;
	for (int i = 0; i <= bnums; i++)
		cin >> bstir[i];
	cout << "�����������ʽ��1��ʾ����ʽ�˷���2��ʾ����(����Ĭ��ΪA/B)" << endl;
	int type;
	cin >> type;
	double* out_type1 = new double[anums + bnums + 1];
	double* out_type2 = new double[anums - bnums + 1];
	for (int i = 0; i <= anums + bnums; i++)
		out_type1[i] = 0;
	for (int i = 0; i <= anums - bnums; i++)
		out_type2[i] = 0;
	switch (type)
	{
	case(1):
	{
		for (int i = 0; i <= anums; i++)
		{
			for (int j = 0; j <= bnums; j++)
			{
				out_type1[i+j] += astir[i] * bstir[j];
			}
		}
		cout << "�������ʽ��ϵ��Ϊ" << endl;
		for (int i = 0; i <= anums + bnums; i++)
			cout << out_type1[i] <<" " << endl;
	}
	case(2):
	{
		for (int i = anums;i>=bnums; i--)
		{
			out_type2[i-bnums] = astir[i] / bstir[bnums];
			for (int j = bnums,k=anums; j >=0; j--,k--)
			{
				astir[k] -= (out_type2[i - bnums] * bstir[j]);
			}
		}
		cout << "�������ʽ��ϵ��Ϊ" << endl;
		for (int i = 0; i <= anums - bnums; i++)
			cout << out_type2[i] << " " << endl;
	}
	default:
		break;
	}
	return 0;
}
*/

/*
//������Ȩͼ ������Ⱥ͹�����ȱ���
typedef char VertexType;
typedef int EdgeType;

struct EdgeNode //������һ���ߣ�������������ţ��յ��ַ,���Ը���Ȩֵ
{
	int adjvex;//����ʼ������
	EdgeNode* next;//Ŀ�ĵ�ַ
};
struct VertexNode
{
	VertexType vertex;//��������
	EdgeNode* firstedge;//�ý���ͷ��
};

struct ALGraph
{
	VertexNode* ALList;//һ���ڽӱ�
	int n, e;
	//������ͱ���
};

struct queue_BDS //ʹ���˶���
{
	int* queue;
	int front;
	int rear;
};

void CreatGraphAL(ALGraph* G);
void DFS(ALGraph* G, int i, bool* visited,int& count);
void BDS(ALGraph* G, int i, bool* visited, queue_BDS& Q);
void PrintfGraphAL(ALGraph* G); 
void DeleteGraphAL(ALGraph* G); 

int main()
{
	ALGraph G;
	G.ALList = nullptr;
	G.n = 0;
	G.e = 0;
	CreatGraphAL(&G);
	bool* visited = new bool[G.n];
	for (int i = 0; i < G.n; i++)
		visited[i] = false;
	cout << "��ѡ��ʼ����ĵ�" << endl;
	int posi = 0;
	cin >> posi;

	cout << "������ȱ�����" << endl;
	int count = 0;
	cout << "������������ȱ���" << endl;
	DFS(&G,posi,visited,count);

	cout << "�����ǹ�����ȱ���" << endl;
	queue_BDS Q{};
	Q.queue = new int[50];
	Q.front = Q.rear = 0;
	for (int i = 0; i < G.n; i++)
		visited[i] = false;
	BDS(&G, posi, visited, Q);

	cout<<"�����ڽӱ�<<endl;
	PrintfGraphAL(&G);

	DeleteGraphAL(&G);
	delete[] visited;
	delete[] Q.queue;
	return 0;
}

void CreatGraphAL(ALGraph* G)//�����ڽӱ�
{
	cout << "������ ����" << endl;
	cin >> G->n >> G->e;
	G->ALList = new VertexNode[G->n];

	cout << "�������ȷ������" << endl;
	for (int i = 0; i < G->n; i++)
	{
		cin >> G->ALList[i].vertex;
		G->ALList[i].firstedge = nullptr;
	}
	cout << "����� �����" << endl;
	for (int i = 0; i < G->e; i++)
	{
		int k, j;
		cin >> k >> j;
		//������ͷ�巨ʵ������
		//����ͼ���������������Ҫ����������ı�

		//��ȥ��
		EdgeNode* edge1 = new EdgeNode;
		edge1->adjvex = j;
		edge1->next = G->ALList[k].firstedge;
		G->ALList[k].firstedge = edge1;

		//��ȥ��
		EdgeNode* edge2 = new EdgeNode;
		edge2->adjvex = k;
		edge2->next = G->ALList[j].firstedge;
		G->ALList[j].firstedge = edge2;
	}
}

void DFS(ALGraph* G, int i, bool* visited,int& count)
{
	visited[i] = true;
	count++;
	cout << G->ALList[i].vertex << endl;
	if (count == G->n)
		return;

	EdgeNode* ptr = G->ALList[i].firstedge;
	while (ptr != NULL)
	{
		if (!visited[ptr->adjvex])
		{
			DFS(G, ptr->adjvex, visited,count);
		}
		ptr = ptr->next;
	}
}

void BDS(ALGraph* G, int i, bool* visited,queue_BDS& Q)
{
	Q.rear = (Q.rear + 1) % 50;
	Q.queue[Q.rear] = i;//��ʼ�����
	visited[i] = true;

	while (Q.front != Q.rear)
	{
		int m = Q.queue[(Q.front + 1) % 50];
		Q.front = (Q.front + 1) % 50;

		EdgeNode* ptr = G->ALList[m].firstedge;
		cout << G->ALList[m].vertex << endl;

		while (ptr)
		{
			if (!visited[ptr->adjvex])
			{
				Q.rear = (Q.rear + 1) % 50;
				Q.queue[Q.rear] = ptr->adjvex;
				visited[ptr->adjvex] = true;
			}
			ptr = ptr->next;
		}
	}
}



void PrintfGraphAL(const ALGraph* G)//���ڽӱ�
{
	EdgeNode* ptr;
	for (int i = 0; i < G->n; i++)
	{
		ptr = G->ALList[i].firstedge;
		if (!ptr)
		{
			cout << "�ö����ޱ�" << endl;
			continue;
		}
		cout << G->ALList[i].vertex;
		while (ptr != NULL)
		{
			cout << "->" << G->ALList[ptr->adjvex].vertex;
			ptr = ptr->next;
		}
		cout << endl;
	}
}

void DeleteGraphAL(ALGraph* G)
{
	for (int i = 0; i < G->n; i++)
	{
		EdgeNode* ptr = G->ALList[i].firstedge;
		if(ptr->next)
		{
			EdgeNode* qtr = ptr->next;
			while (qtr)
			{
				delete ptr;
				ptr = qtr;
				qtr = qtr->next;
			}
		}
		delete ptr;
	}
	G->e = G->n = 0;
	delete[] G->ALList;
	G->ALList = nullptr;
}
*/
//������������Ȩͼ������㷨

/*
const int N = 20;//������
const int MAX = 1000;//������

typedef char ElemType;

struct ArcNode//�����
{
	int adjvex;//�ڽӽ������
	ArcNode* next;
	int weight;
};

struct VertexNode//�ڽӱ�ͷ���
{
	ElemType data;
	ArcNode* firstarc;
};

struct AVGraph//�ڽӱ�
{
	VertexNode avgraph[N];
	int arcs;
	int vertexs;
};

void CreatDAG(AVGraph* G,int arcs,int vertexs);
void PrintGraph(AVGraph* G);
void Dijkstra(AVGraph* G);
void DeleteGraphAL(AVGraph* G);
int main()
{
	int arcs, vertexs;
	cout << "������ͼ�Ļ����붥����" << endl;
	cin >> arcs >> vertexs;
	AVGraph G;
	CreatDAG(&G, arcs, vertexs);
	PrintGraph(&G);
	Dijkstra(&G);
	return 0;
}

void CreatDAG(AVGraph* G, int arcs, int vertexs)
{
	G->arcs = arcs;
	G->vertexs = vertexs;
	cout << "ÿ����������" << endl;
	for (int i = 0; i < G->vertexs; i++)
	{
		cin >> G->avgraph[i].data;
		G->avgraph[i].firstarc = nullptr;
	}
	cout << "��� �յ� Ȩֵ" << endl;
	for (int i = 0; i < G->arcs; i++)
	{
		int j, k, weight;
		cin >> j >> k >> weight;
		//����ͼ�����������ͼ��ɾȥ�յ�ȥ���ı�

		ArcNode* arc = new ArcNode;
		arc->weight = weight;
		arc->adjvex = k;
		arc->next = G->avgraph[j].firstarc;
		G->avgraph[j].firstarc = arc;//ͷ�巨

		ArcNode* brc = new ArcNode;
		brc->weight = weight;
		brc->adjvex = j;
		brc->next = G->avgraph[k].firstarc;
		G->avgraph[k].firstarc = brc;
	}
}

void PrintGraph(AVGraph* G)
{
	ArcNode* ptr;
	for (int i = 0; i < G->vertexs; i++)
	{
		ptr = G->avgraph[i].firstarc;
		cout << G->avgraph[i].data;
		while (ptr != NULL)
		{
			cout << "->" << G->avgraph[ptr->adjvex].data;
			ptr = ptr->next;
		}
		cout << endl;
	}
}

void Dijkstra(AVGraph* G)//����㷨ֻ����һ���㵽����������̾��롣����ȡ���Ϊ0�ĵ���Դ��
{
	// ������㷨���ԣ�����ָ��ָ��ĳ�������ڽӱ��ͷʱ����Ϊ�Ըý��ķ��ʣ���ָ�����ڽӱ��ݲ���ȡ���ݲ����з���

	// ����Դ����������֤����
	// ����Ϊ����Ŀ�Ľ�㣬·��ÿ�ζ�����ѡ��̷�֧����������Ŀ�ĵػ���һ��ֵ
	// �����ⲻһ����С���п�����һ��·����ֱ�ӵ���Ŀ�ĵأ���Ȼֻ����һ�η�֧���·��Ҫ���������ܵ���˵�����
	// ������Ҫ��ÿ��ѡ·��ʱ����¾��롣
	// ��һ��ѡ·���ȸ�����Χ���е���һ������Ľ��ľ��롣
	// ��ѡ�������̵�·����Ӧ�ĵ�A��ʹ�����S����һ���Ѿ�ȷ������̾���ļ���
	// ֮������ΪA�����̾����Ѿ�ȷ��������Ϊ����û��ȷ������ô��Ҫ������·�������A,�������ľ���һ��������Ϊ������Ծ�Լ�����ĺ�����
	// ������������A�����ȷ�ϣ����ַ��ʱ���A��ľ��뽫�̶������ٸ���
	// ���ҵ���Χδ�����ʹ����ھӡ���Щ�ھӣ��п���Դ�㲻��һ������п����ܹ�һ�����
	// �����ܹ��ģ���������룬�ٸ�ԭ���ľ���Ƚϣ������Ƿ���¡����ܹ��ľ�ֱ�Ӹ��¡�
	// �������õ������о��룬���ǻ���Դ��ģ�ֻ����·����ͬ��
	// ���ڣ�dist�����ֵ�����˸��£�ͬʱvisited������Դ���A����true�����治�ٷ���Ҳ�����޸ġ������Զ��׼���
	// ������������ѡA��һ����ȥѡdist�������������С��Ӧ�ĵ�B������Ҳ�ѵ�B��������S������ΪB����̾����Ѿ��ҵ�
	// ԭ����Խ��͵ĸ��������ȡ��֤�������϶���B��distֵ�Ǵ�A���������С����ֵ���ٶ��������ϸ�£�
	// ��Դ�������������·���Ե���B�㡣������Ҫ������Щ·�ܲ����ṩ���̵�·��ֵ��
	// ��һ�֣�Դ��ֱ��ȥB��������ʵ���迼�ǣ���ΪѡB��֮ǰ�Ѿ�ͨ������ıȽϽ��й������ˡ�
	// �ڶ��֣�;��A�㵫�ǲ�ֱ��ȥB����ΪB��dist�Ѿ���С����A�����һ������������ľ���һ������ȥB����������·�����ṩ��С�ľ���
	// �����֣���;��A�㣬��Դ����Χ��ĳ��δ�����ʵĵ������
	// ���Դ�㵽�����ľ����B���distֵ�����Ѿ�û�����ˡ������ȥB�Ķ̣���ô�ڶ���ѡ��Ͳ���ѡB�㣬B�����̾��뻹�����
	// �������������B���ֵ�Ѿ������ֵ�ˡ��Ӵ�B���Ϊ���ʡ�������������У�ֱ�������ܷ��ʵĵ�ȫ�������ʡ�
	// ���ֻҪ������ȷ�Ͳ�����������������ĳ�����ȷ��Ϊ����ʱ�����ľ��벻����С


	int dist[N]{};
	bool visited[N]{};
	for (int i = 0; i < N; i++)
	{
		dist[i] = MAX;
		visited[i] = false;
	}
	// ��ʼ��������ͷ����飬��������ȫ����MAX,��������ȫ����false
	
	dist[0] = 0;//��ʼ���������㣬��Ϊ�ο���
	
		for (int i = 0; i < G->vertexs; i++)
	{
		int u = -1;
		for (int j = 0; j < G->vertexs; j++)
		{
			if (visited[j]==false && (u == -1 || dist[j] < dist[u]))
			{
				u = j;
			}
		}
		// ������ѡ������
		// ���ȣ�if��һ��ִ�е������Ƿ�����ĵ�һ��δ�����ʵĵ㣬���۾��룬��ָ�������
		// �����ϣ������Ҫ����u=-1����ô�������е㶼�����ʡ�
		// ��ȫ��ͨͼ�����е㶼�����ʺ������ѭ��ͬʱ���������u��=-1
		// �й�������߷ǹ�������Դ���޷�����ĵ㣨����������ͼ�и�������ʱ��
		// u�ᱻ��Ϊ��һ��û�б����ʵĵ㣬����ܷ��ʵĵ�ȫ���������ˣ���ôdist[u]==MAX���ڶ���if��佫����ѭ��
		// ����ֻҪ���У�u�϶���Ϊ-1��if�����ִ�е������ǣ�
		// �����ĳ�����û�����ʣ�������������������ĳ������ڽӱ��ڣ�������dist���޸��ˡ�
		// ͬʱ���޸ĺ��distҪ�ȵ�һ��ִ��if�����ȷ����dist[u]С
		// �ҵ���u��Ϊ��������ţ�ѭ�����е��������ҵ�����0��λ�����δ�����ʵ���̾���㡣
		// �����ȱ�����ÿ������С�㶼Ҫ�������������飬Ч�ʲ��ߣ�ʱ�临�Ӷ���O(n^2)

		if (dist[u] == MAX)
			break;
		// ����ѡ���������ѡ�����������
		// �Է��������н��ΪĿ�꣬����Ѿ����������ܷ��ʵ����е㣬����ǰ��
		// ���if������������������δ�����ʣ�����������ܱ��޸ģ�˵����������Դ���ǿ���ͨ��
		// ���if��������������ѡ����������һ����û������Ҳû�޸ľ���Ľ��λ��
		// �������������о����С�Ľ�㣬�����ʹ��ˣ���û�б����ʣ�����������Դ����ԣ�һ���ǲ�����ͨ�ġ������ǰ��

		visited[u] = true;
		// ���������õ�ķ��������Ϊtrue�����λ���޹ؽ�Ҫ������Ȩֵ�������trueҲ��
		// ֻ�е���ָ��ָ����������ڽӱ��ͷʱ���ų�Ϊ�Ըý��ķ��ʡ�������������Ƿ���
		// ͬʱһ���÷���Ϊtrue���������޸����ֵ

		ArcNode* ptr = G->avgraph[u].firstarc;
		while (ptr != NULL)
		{
			int v = ptr->adjvex;
			if (visited[v]==false && dist[u] + ptr->weight < dist[v])
				dist[v] = dist[u] + ptr->weight;
			ptr = ptr->next;
		}//�������㼰���ڽӽ����������£����봢���������У���һ��ȫ�ֱ任
	} //�����ǹ����㷨���൱�ڶ�һ�����������ѡ����С�ģ�δ�����ʵĵ㣬ʩ�ӷ��ʡ�

	cout << "���·��" << endl;
	for (int i = 0; i < G->vertexs; i++)
	{
		if (dist[i]!=MAX)
			cout << "V0��V" << i << "����̾���Ϊ" << dist[i]<<endl;
		else
			cout << "V0��V" << i << "����̾���" << endl;
	}
}


void DeleteGraphAL(AVGraph* G)
{
	ArcNode* ptr;
	for (int i = 0; i < G->vertexs; i++)
	{
		ptr = G->avgraph[i].firstarc;
		while (ptr != NULL)
		{
			ArcNode* qtr = ptr;
			ptr = ptr->next;
			delete qtr;
		}
	}
}
*/

/*
// Kruskal�㷨��ѡ����������С������
struct Edge
{
	int begin;
	int end;
	int weight;

	Edge(int BEGIN=0,int END=0,int WEIGHT=0):
		begin(BEGIN),end(END),weight(WEIGHT){}

	bool operator> (const Edge& e) const
	{
		return this->weight>e.weight;
	}
};

void EdgeBubbleSort(Edge e[], int n)//�������Բ��ö�����
{
	Edge em;
	for(int i=0;i<n-1;i++)
		{for (int j = 0; j < n - 1 - i; j++)
		{
			if (e[j] > e[j + 1])
			{
				em = e[j + 1];
				e[j + 1] = e[j];
				e[j] = em;
			}
		}
}

int RootFinder(int table[], int ver)
{
	int xer = ver;
	while (table[xer] > -1)
		xer = table[xer];
	return xer;
}

// Kruskal�㷨�����ܳ��ܶ���selected���飬Ҳ���ǲ�ͬ�ڵ�ĸ���һ��������ȫȡ����������ʱͷβ������ô����ģ�
// ��Ϊ����ͼ���ߵ�ͷβ����Ӱ��������������ͼ�ͱ���ע��������
int main()
{
	int nums,sums;
	cout << "��������������Ͷ�����" << endl;
	cin >> nums>>sums;

	Edge* edges=new Edge[nums];
	cout << "����������ߵ���ʼ�㣬��ֹ�㣬Ȩ��" << endl;
	for (int i = 0; i < nums; i++)
		cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
	EdgeBubbleSort(edges, nums);

	int* selected = new int[sums];//������ʶĳ����ĸ��ڵ㣬���ڵ�ʼ��Ϊ-1
	for (int i = 0; i < sums; i++)
		selected[i] = -1;

	int count = 0;
	int weights = 0;
	int start, end;
	for (int i = 0; i < nums; i++)
	{
		start = RootFinder(selected, edges[i].begin);
		end = RootFinder(selected, edges[i].end);
		if (start != end)
		{
			cout << "�Ѿ�ѡ��ıߵ���ʼ��ֱ�Ϊ"<<edges[i].begin << " " << edges[i].end << endl;
			selected[end] = start;
			count++;
			weights += edges[i].weight;
		}
		if (count == sums - 1)
			break;
	}
	cout << "��СȨ����" << weights << endl;
	for (int i = 0; i < sums; i++)
	{
		cout << i << " " << selected[i] << endl;
	}
	delete[] edges;
	delete[] selected;
	return 0;
}*/


/*
// Prim�㷨 ��Dijkstra�㷨��࣬���Ե�����һ��ͼ������ͼ���� ˫�� �ڽӱ������档
// Prim�㷨����ֻ���ǵ㣬����Ҫ�Ա�������˵�ͼ�Ƚϳ���ʱЧ���ܺá�

struct Edge //�ڽӱ�
{
	int adjvex;//�յ�
	Edge* next;//��һ����
	int weight;//Ȩ
	Edge(int ADJVEX=0,Edge* NEXT=nullptr,int WEIGHT=0):
		adjvex(ADJVEX),next(NEXT),weight(WEIGHT){}
};

struct HeadNode //�ڽӱ��ͷ�ڵ�
{
	char data;
	Edge* firstedge;
	HeadNode(char DATA = 0,Edge*FIRSTEDGE=nullptr):
		data(DATA),firstedge(FIRSTEDGE){}
};

int Prim(HeadNode* G, int edges, int vertexs)
// ��Dijkstra�㷨���ʲ�࣬��ѡ��֪����С��dist�㣬Ȼ�����������Χ��ľ��롣
// Ȼ��Prim�㷨Ҫ��һ��������Ȩֵ�����Է�����intֵ
{
	int* dist = new int[vertexs];
	bool* visited = new bool[vertexs];
	for (int i = 0; i < vertexs; i++)
	{
		dist[i] = 1000;
		visited[i] = false;
	}

	dist[0] = 0;//ѡһ����ϲ����λ�ã������λ�õ��ɳ�ʼ�㣬������0

	for (int i = 0; i < vertexs; i++)
	{
		int u = -1;
		for (int j = 0; j < vertexs; j++)
		{
			if (!visited[j] && (u == -1 || dist[j] < dist[u]))
				u = j;
		}

		if (dist[u] == 1000)
			break;

		visited[u] = true;

		Edge* arc = G[u].firstedge;
		while (arc!=NULL)
		{
			int vex = arc->adjvex;
			if (!visited[vex] && arc->weight < dist[vex])
				dist[vex] = arc->weight;
			arc = arc->next;
		}
	}

	int weights = 0;
	for (int i = 0; i < vertexs; i++)
		if (visited[i]==true)
		{
			cout << dist[i] << endl;
			weights += dist[i];
		}

	delete[] dist;
	delete[] visited;

	return weights;
}
int main()
{
	int edges, vertexs;
	cout << "��������������Ͷ�����" << endl;
	cin >> edges >> vertexs;
	HeadNode* avgraph = new HeadNode[vertexs];
	cout << "������ÿ�����������" << endl;
	for (int i = 0; i < vertexs; i++)
		cin >> avgraph[i].data;
	cout << "������ÿ���ߵ���㣬�յ㣬Ȩֵ" << endl;
	for (int i = 0; i < edges; i++)
	{
		int j, k, w;
		cin >> j >> k >> w;
		Edge* edge1 = new Edge;
		edge1->weight = w;

		edge1->adjvex = k;
		edge1->next = avgraph[j].firstedge;
		avgraph[j].firstedge = edge1;

		Edge* edge2 = new Edge;
		edge2->weight = w;

		edge2->adjvex = j;
		edge2->next = avgraph[k].firstedge;
		avgraph[k].firstedge = edge2;
		//ͷ�巨
	}
	int W=Prim(avgraph, edges, vertexs);
	cout << W << endl;

	for (int i = 0; i < vertexs; i++)
	{
		Edge* edge = avgraph[i].firstedge;
		while (edge != nullptr)
		{
			Edge* temp = edge;
			edge = edge->next;
			delete temp; // �ͷ�ÿ���ߵ��ڴ�
		}
	}

	delete[] avgraph;
	return 0;
}
*/

/*
//̰���㷨�������
struct Time
{
	int start_time;
	int end_time;
	Time(int START = 0,int END = 0):
		start_time(START),end_time(END){}

	bool operator> (const Time& t1) const
	{
		if (this->end_time > t1.end_time)
			return true;
		else
			return false;
	}
};

void TimeBubbleSort(Time t[], int n)
{
	Time temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (t[j] > t[j + 1])
			{
				temp = t[j+1];
				t[j + 1] = t[j];
				t[j] = temp;
			}
		}
	}
}

void OrderFinder(Time t[], int n,int position,int* count)
{
	int pt = t[position].end_time;
	int p=-1;
	for (int i = position+1; i < n; i++)
	{
		if (pt + 1 <= t[i].start_time)
		{
			p = i;
			(*count)++;
			break;
		}
	}
	if (p == -1)
		return;
	OrderFinder(t, n, p, count);
	return;
}

int main()
{
	int nums;
	cin >> nums;
	Time* table = new Time[nums];
	for (int i = 0; i < nums; i++)
	{
		cin >> table[i].start_time >> table[i].end_time;
	}
	TimeBubbleSort(table, nums);

	int count = 1;
	OrderFinder(table, nums, 0,&count);
	cout << count << endl;
	delete []table;
	return 0;
}
*/

/*
// ��̤�����㷨
const int rows = 12;
const int cols = 12;
const int xMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int yMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

struct Road
{
	int xNext;  // �յ��x����
	int yNext;  // �յ��y����
	int rnums;  // �õ���ͨ������һ��������

	Road(int X = 0, int Y = 0,int RNUMS = -1) : xNext(X), yNext(Y), rnums(RNUMS) {}

	bool operator> (const Road& r) const
	{
		return this->rnums > r.rnums;  // ·���ٵ�����
	}
};
// ð���������ڸ��ݿ��з�������rnums������
void Bubblesort(Road roads[])
{
	Road temp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7 - i; j++)
		{
			// ���򣺿��з������ٵ�����
			if (roads[j]> roads[j + 1])
			{
				temp = roads[j + 1];
				roads[j + 1] = roads[j];
				roads[j] = temp;
			}
		}
	}
}
// ����ӵ�ǰλ�ÿ����ߵ���һ�������浽 roads ��
void nextXY(int Chess[][cols], int x, int y, Road roads[])
{
	for (int i = 0; i < 8; i++)
	{
		int x_x = x + xMove[i];
		int y_y = y + yMove[i];
		if ((x_x >= 0 && x_x < rows) && (y_y >= 0 && y_y < cols) && Chess[x_x][y_y] == 0)
		{
			roads[i].xNext = x_x;
			roads[i].yNext = y_y;
			roads[i].rnums = 0;
			// �����λ�ÿ����ߵķ�����
			for (int j = 0; j < 8; j++)
			{
				int sx = x_x + xMove[j];
				int sy = y_y + yMove[j];
				if ((sx >= 0 && sx < rows) && (sy >= 0 && sy < cols) && Chess[sx][sy] == 0)
					roads[i].rnums++;
			}
		}
	}
	// ʹ��ð�����򣬰� rnums ��С��������
	Bubblesort(roads);
}

// �����������
bool DFS(int Chess[][cols], int x, int y, int count)
{
	Chess[x][y] = count;  // ��ǵ�ǰ��Ϊ�� count ��

	if (count == rows * cols)  // �������и���
		return true;

	Road roads[8];//ÿ�ζ���Ҫ�������ɣ������ⲿ���úã�ÿ�ζ�����������������Խ�Լ�ռ�
	nextXY(Chess, x, y, roads);  // ����ӵ�ǰ������ߵ���һ��

	// �������п��еķ�������ѡ�������ٿ��з����·��
	for (int i = 0; i < 8; i++)
	{
		if (roads[i].rnums >= 0)  // ���·�����в���˵rnums��Ҫ����0������0Ҳ���ԣ���Ȼ�������յ㣬��������޽�����ȥ
		{
			bool result = DFS(Chess, roads[i].xNext, roads[i].yNext, count + 1);
			//���·�����У���ȥ����һ��·�ɲ����У�������̻�ͨ���ݹ�һֱ������ȥ
			//ֱ�������յ������Χ8������·����
			//��������յ㣬�ͻ�����һ�εݹ鿪ʼ����trueֵ��ֱ����һ�εݹ飬64��ȫ��Ϊtrue
			//���������·���ߵĵ㣬����Ϊ��ǰ��·���ˣ�Ȼ������������Ϊ0����Ϊû���߹���Ȼ�󷵻�false
			//��һ���ݹ����������·��̽·��תȥ��һ��·��ֱ�������յ㡣
			if (result)
				return true;
		}
	}
	Chess[x][y] = 0;  // ����
	return false;
}

void PrintMatrix(int Chess[][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Chess[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int Chess[rows][cols] = { 0 };
	cout << "��������ʼ���x,y����" << endl;
	int x0, y0;
	cin >> x0 >> y0;
	x0--,y0--;
	if (DFS(Chess, x0, y0, 1))
	{
		cout << "���ҵ�·��" << endl;
		PrintMatrix(Chess); 
	}
	else
		cout << "ʧ��" << endl;
	return 0;
}*/


/* 12.1 ��̬�滮
#include<vector>

struct Goldinf
{
	int values;
	int nums;
	char tag;

	Goldinf(int VALUES=0,int NUMS=0,char TAG='#') :
		values(VALUES),nums(NUMS),tag(TAG){}

};

int MAX(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}

int maxGOLD(Goldinf g[], int gold, int people,vector<vector<int>>&DP)//�����������������������,��̬�滮
{
	if (gold == 0) 
		return 0;

	if (DP[gold][people] != -1) 
	{
		return DP[gold][people];
	}
	if (people >= g[gold - 1].nums)// �������������� 
	{
		// ����ѡ�񣺲��ڻ����������
		int pos1 = maxGOLD(g, gold - 1, people, DP);  // ����
		int pos2 = maxGOLD(g, gold - 1, people - g[gold - 1].nums, DP) + g[gold - 1].values;  // �������

		DP[gold][people] = MAX(pos1, pos2);
	}
	else 
	{
		DP[gold][people] = maxGOLD(g, gold - 1, people, DP);  // ����
	}

	return DP[gold][people];
}

int main()
{
	int goldnums, peoplenums;
	cout << "�����������Ŀ�Լ��ܹ��ṩ������" << endl;
	cin >> goldnums >> peoplenums;
	Goldinf* group = new Goldinf[goldnums];
	cout << "������ÿ�����ı�ǩ������������Ҫ���ɵ�����" << endl;
	for (int i = 0; i < goldnums; i++)
		cin >> group[i].tag >> group[i].values >> group[i].nums;

	vector<vector<int>> DP(goldnums + 1, vector<int>(peoplenums + 1, -1));

	cout << "��̬�滮����������Ϊ" << endl;
	int result = maxGOLD(group, goldnums, peoplenums,DP);
	cout << result << endl;
	cout << "�����ǿ��ɷ���" << endl;
	int i = goldnums, j = peoplenums;
	while (i > 0 && j > 0) 
	{
		if (DP[i][j] != DP[i - 1][j]) 
		{
			// ˵���� i ����󱻿���
			cout << group[i - 1].tag << endl;  // ��ӡ�����ɵĽ���ǩ
			j -= group[i - 1].nums;  // ʣ�����������
		}
		i--;
	}

	return 0;
}
*/
/*
// �������
const int rows = 20;
const int cols = 20;

int MAX(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}
void LCSfinder(const string& s1, const string& s2, int LF[][cols])
{
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])
				LF[i][j] = LF[i-1][j-1]+1;
			else
			{
				LF[i][j] = MAX(LF[i][j - 1], LF[i - 1][j]);
			}
		}
	}
}

string LCSmaker(int LF[][cols],int n1,int n2,const string& s1)
{
	string end;
	int i = n1; int j = n2;
	while (i > 0 && j > 0)
	{
		if (LF[i][j] == LF[i][j-1])
			j--;
		else if (LF[i][j] == LF[i-1][j])
			i--;
		else
		{
			end.push_back(s1[i - 1]);//�����±��==�ַ����ܳ�-1
			i--; j--;
		}	
	}
	reverse(end.begin(), end.end());
	return end;
}
int main()
{
	string s1, s2;
	cout << "��������������" << endl;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	int LF[rows][cols] = { 0 };
	LCSfinder(s1, s2, LF);
	cout << "������еĳ���Ϊ " << LF[l1][l2] << endl;
	cout << "������Ϊ " << LCSmaker(LF,l1,l2,s1) << endl;
	return 0;
}
*/

/*
 // 0-1��������
const int max_nums = 20;
const int max_weight = 50;

struct staff
{
	char tag;
	int weight;
	int value;

	staff(char TAG = '#', int WEIGHT = 0, int VALUE=0):
		tag(TAG),weight(WEIGHT),value(VALUE){}

};

int MAX(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}

int Zero_One(staff table[], int nums, int weight,int s[][max_weight])
{
	if (nums == 0)
		return 0;

	if (s[nums][weight] != -1)
		return s[nums][weight];

	if (weight >= table[nums-1].weight)
	{
		int pos1 = Zero_One(table, nums - 1, weight - table[nums-1].weight, s) + table[nums-1].value;
		int pos2 = Zero_One(table, nums - 1, weight,s);
		s[nums][weight] = MAX(pos1, pos2);
	}
	else
		s[nums][weight]= Zero_One(table, nums - 1, weight, s);

	return s[nums][weight];
}

void PutStrategy(int s[][max_weight], staff table[],int nums,int weight)
{	
	int i = nums; int j = weight;
	while (i > 0 && j >0)
	{
		if (s[i][j] == s[i-1][j])
			i--;
		else
		{
			cout << table[i-1].tag << endl;
			j -= table[i-1].weight;
			i--;
		}
	}
}
int main()
{
	int staffnums, total_weight;
	cout << "��������Ʒ�����Լ���������" << endl;
	cin >> staffnums >> total_weight;
	staff* table = new staff[staffnums];
	cout << "������ÿ����Ʒ�ı�ǩ�������ͼ�ֵ" << endl;
	for (int i = 0; i < staffnums; i++)
		cin >> table[i].tag >> table[i].weight >> table[i].value;

	int strategy[max_nums][max_weight]{};
	for(int i=0;i<max_nums;i++)
		for (int j = 0; j < max_weight; j++)
		{
			strategy[i][j] = -1;
		}

	int out = Zero_One(table, staffnums, total_weight, strategy);
	cout << "��ѷ����¿�Я����ֵΪ" << out << "����Ʒ" << endl;
	cout << "��������" << endl;
	PutStrategy(strategy, table, staffnums, total_weight);
	return 0;
}
*/

//#include<queue>
//#include<vector>
//int main()
//{
//	std::priority_queue<int, vector<int>, std::greater<int>> Heap;
//	Heap.push(2);
//	Heap.push(9);
//	Heap.push(6);
//	Heap.push(3);
//	Heap.push(10);
//
//	while (!Heap.empty())
//	{
//		cout << Heap.top() << endl;
//		Heap.pop();
//	}
//
//
//}



