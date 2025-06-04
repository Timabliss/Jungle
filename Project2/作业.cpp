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
	getline(cin, s2);//注意C++屏蔽了空格，使用getline保有空格
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

/* //多项式的四则运算
int main()
{
	int anums, bnums;
	cout << "请输入多项式A和多项式B的次数" << endl;
	cin >> anums >> bnums;
	double* astir = new double[anums+1];
	double* bstir = new double[bnums+1];
	cout << "请依次输入多项式A各项的系数" << endl;
	for (int i = 0; i <= anums; i++)
		cin >> astir[i];
	cout << "请依次输入多项式B各项的系数" << endl;
	for (int i = 0; i <= bnums; i++)
		cin >> bstir[i];
	cout << "请输入输出格式，1表示多项式乘法，2表示除法(除法默认为A/B)" << endl;
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
		cout << "结果多项式的系数为" << endl;
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
		cout << "结果多项式的系数为" << endl;
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
//无向无权图 深度优先和广度优先遍历
typedef char VertexType;
typedef int EdgeType;

struct EdgeNode //定义了一条边，包括边起点的序号，终点地址,可以附带权值
{
	int adjvex;//边起始点的序号
	EdgeNode* next;//目的地址
};
struct VertexNode
{
	VertexType vertex;//结点的数据
	EdgeNode* firstedge;//该结点的头边
};

struct ALGraph
{
	VertexNode* ALList;//一套邻接表
	int n, e;
	//结点数和边数
};

struct queue_BDS //使用了队列
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
	cout << "请选择开始历遍的点" << endl;
	int posi = 0;
	cin >> posi;

	cout << "深度优先遍历：" << endl;
	int count = 0;
	cout << "这里是深度优先遍历" << endl;
	DFS(&G,posi,visited,count);

	cout << "这里是广度优先遍历" << endl;
	queue_BDS Q{};
	Q.queue = new int[50];
	Q.front = Q.rear = 0;
	for (int i = 0; i < G.n; i++)
		visited[i] = false;
	BDS(&G, posi, visited, Q);

	cout<<"这是邻接表<<endl;
	PrintfGraphAL(&G);

	DeleteGraphAL(&G);
	delete[] visited;
	delete[] Q.queue;
	return 0;
}

void CreatGraphAL(ALGraph* G)//创建邻接表
{
	cout << "顶点数 边数" << endl;
	cin >> G->n >> G->e;
	G->ALList = new VertexNode[G->n];

	cout << "按顶点号确定数据" << endl;
	for (int i = 0; i < G->n; i++)
	{
		cin >> G->ALList[i].vertex;
		G->ALList[i].firstedge = nullptr;
	}
	cout << "父序号 子序号" << endl;
	for (int i = 0; i < G->e; i++)
	{
		int k, j;
		cin >> k >> j;
		//类似于头插法实现链表
		//无向图特征决定了两点间要有两条反向的边

		//父去子
		EdgeNode* edge1 = new EdgeNode;
		edge1->adjvex = j;
		edge1->next = G->ALList[k].firstedge;
		G->ALList[k].firstedge = edge1;

		//子去父
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
	Q.queue[Q.rear] = i;//初始点入队
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



void PrintfGraphAL(const ALGraph* G)//打邻接表
{
	EdgeNode* ptr;
	for (int i = 0; i < G->n; i++)
	{
		ptr = G->ALList[i].firstedge;
		if (!ptr)
		{
			cout << "该顶点无边" << endl;
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
//下面是无向有权图的相关算法

/*
const int N = 20;//顶点数
const int MAX = 1000;//最大距离

typedef char ElemType;

struct ArcNode//弧结点
{
	int adjvex;//邻接结点的序号
	ArcNode* next;
	int weight;
};

struct VertexNode//邻接表头结点
{
	ElemType data;
	ArcNode* firstarc;
};

struct AVGraph//邻接表
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
	cout << "请输入图的弧数与顶点数" << endl;
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
	cout << "每个结点的数据" << endl;
	for (int i = 0; i < G->vertexs; i++)
	{
		cin >> G->avgraph[i].data;
		G->avgraph[i].firstarc = nullptr;
	}
	cout << "起点 终点 权值" << endl;
	for (int i = 0; i < G->arcs; i++)
	{
		int j, k, weight;
		cin >> j >> k >> weight;
		//无向图，如果是有向图就删去终点去起点的边

		ArcNode* arc = new ArcNode;
		arc->weight = weight;
		arc->adjvex = k;
		arc->next = G->avgraph[j].firstarc;
		G->avgraph[j].firstarc = arc;//头插法

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

void Dijkstra(AVGraph* G)//这个算法只计算一个点到其余各点的最短距离。这里取序号为0的点作源点
{
	// 对这个算法而言，当边指针指向某个结点的邻接表表头时，称为对该结点的访问，边指针沿邻接表传递并读取数据并不叫访问

	// 下面对代码给出文字证明：
	// 首先为到达目的结点，路径每次都可以选最短分支，这样到达目的地会有一个值
	// 但是这不一定最小，有可能有一条路径能直接到达目的地，虽然只看第一次分支这个路径要长，但是总的来说是最短
	// 所以需要在每次选路的时候更新距离。
	// 第一次选路，先更新周围所有的能一步到达的结点的距离。
	// 再选择距离最短的路径对应的点A，使其进入S集，一个已经确认了最短距离的集合
	// 之所以认为A点的最短距离已经确定，是因为假设没有确定，那么就要从其余路径到达点A,所经历的距离一定更大，因为不能跳跃以及距离的恒正性
	// 接下来，予以A点访问确认，这种访问表明A点的距离将固定，不再更改
	// 再找到周围未被访问过的邻居。这些邻居，有可能源点不能一步到达，有可能能够一步到达。
	// 对于能够的，就重算距离，再跟原来的距离比较，决定是否更新。不能够的就直接更新。
	// 这个步骤得到的所有距离，都是基于源点的，只不过路径不同。
	// 现在，dist数组的值发生了更新，同时visited数组中源点和A点置true，后面不再访问也不再修改。这是显而易见的
	// 接下来，就像选A点一样，去选dist数组里面距离最小对应的点B，并且也把点B包含进入S集。认为B的最短距离已经找到
	// 原理可以解释的更清楚。采取反证法，先认定点B的dist值是从A点出发的最小距离值，再对情况考虑细致：
	// 从源点出发，有三种路可以到达B点。现在主要考虑这些路能不能提供更短的路径值：
	// 第一种，源点直接去B。这种其实无需考虑，因为选B点之前已经通过距离的比较进行过更新了。
	// 第二种，途径A点但是不直接去B。因为B的dist已经最小，从A点出发一步到达其他点的距离一定大于去B，所以这种路不会提供更小的距离
	// 第三种，不途径A点，从源点周围的某个未被访问的点出发。
	// 如果源点到这个点的距离比B点的dist值长，已经没意义了。如果比去B的短，那么第二轮选点就不会选B点，B点的最短距离还会更新
	// 因此综上所述，B点的值已经是最短值了。从此B点记为访问。这个过程向后进行，直到所有能访问的点全部被访问。
	// 因此只要代码正确就不会出现这种情况：当某个结点确定为访问时，它的距离不是最小


	int dist[N]{};
	bool visited[N]{};
	for (int i = 0; i < N; i++)
	{
		dist[i] = MAX;
		visited[i] = false;
	}
	// 初始化距离组和访问组，距离组先全部置MAX,访问组先全部置false
	
	dist[0] = 0;//起始点自身置零，作为参考点
	
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
		// 结点访问选择器。
		// 首先，if第一次执行的条件是访问组的第一个未被访问的点，无论距离，先指向这个点
		// 理论上，如果想要出现u=-1，那么必须所有点都被访问。
		// 完全连通图在所有点都被访问后，最外层循环同时结束，因此u！=-1
		// 有孤立点或者非孤立但是源点无法到达的点（后者在有向图中更常见）时，
		// u会被置为第一个没有被访问的点，如果能访问的点全部被访问了，那么dist[u]==MAX，第二个if语句将跳出循环
		// 所以只要运行，u肯定不为-1。if语句再执行的条件是：
		// 后面的某个结点没被访问，但是由于这个点存在于某个点的邻接表内，所以其dist被修改了。
		// 同时被修改后的dist要比第一次执行if语句所确定的dist[u]小
		// 找到后u置为这个点的序号，循环运行到跳出，找到除了0号位以外的未被访问的最短距离点。
		// 这个的缺点就是每次找最小点都要历遍完两套数组，效率不高，时间复杂度是O(n^2)

		if (dist[u] == MAX)
			break;
		// 距离选择器，这个选择器不可替代
		// 以访问完所有结点为目标，如果已经访问完了能访问的所有点，就提前跳
		// 如果if不成立，表明这个结点未被访问，但是其距离能被修改，说明这个结点与源点是可连通的
		// 如果if成立，表明访问选择器传来了一个既没被访问也没修改距离的结点位置
		// 这表明后面的所有距离更小的结点，都访问过了，它没有被访问，所以这个点对源点而言，一定是不可连通的。因此提前跳

		visited[u] = true;
		// 接下来将该点的访问情况置为true，语句位置无关紧要，结束权值运算后再true也行
		// 只有当边指针指向这个结点的邻接表表头时，才称为对该结点的访问。其余情况均不是访问
		// 同时一旦置访问为true，将不能修改这个值

		ArcNode* ptr = G->avgraph[u].firstarc;
		while (ptr != NULL)
		{
			int v = ptr->adjvex;
			if (visited[v]==false && dist[u] + ptr->weight < dist[v])
				dist[v] = dist[u] + ptr->weight;
			ptr = ptr->next;
		}//对这个结点及其邻接结点作距离更新，距离储存在数组中，是一种全局变换
	} //上面是古早算法，相当于对一个数组操作，选择最小的，未被访问的点，施加访问。

	cout << "最短路径" << endl;
	for (int i = 0; i < G->vertexs; i++)
	{
		if (dist[i]!=MAX)
			cout << "V0到V" << i << "的最短距离为" << dist[i]<<endl;
		else
			cout << "V0到V" << i << "无最短距离" << endl;
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
// Kruskal算法，选边来制造最小生成树
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

void EdgeBubbleSort(Edge e[], int n)//后续可以采用堆排序
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

// Kruskal算法可以跑出很多种selected数组，也就是不同节点的根不一样，这完全取决于你输入时头尾顶点怎么定义的，
// 作为无向图，颠倒头尾并不影响结果，但是有向图就必须注意输入了
int main()
{
	int nums,sums;
	cout << "请依次输入边数和顶点数" << endl;
	cin >> nums>>sums;

	Edge* edges=new Edge[nums];
	cout << "请依次输入边的起始点，终止点，权重" << endl;
	for (int i = 0; i < nums; i++)
		cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
	EdgeBubbleSort(edges, nums);

	int* selected = new int[sums];//用来标识某个点的根节点，根节点始终为-1
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
			cout << "已经选择的边的起始点分别为"<<edges[i].begin << " " << edges[i].end << endl;
			selected[end] = start;
			count++;
			weights += edges[i].weight;
		}
		if (count == sums - 1)
			break;
	}
	cout << "最小权重是" << weights << endl;
	for (int i = 0; i < sums; i++)
	{
		cout << i << " " << selected[i] << endl;
	}
	delete[] edges;
	delete[] selected;
	return 0;
}*/


/*
// Prim算法 跟Dijkstra算法差不多，所以得先造一个图。无向图就用 双向 邻接表来储存。
// Prim算法由于只考虑点，不需要对边排序，因此当图比较稠密时效果很好。

struct Edge //邻接表
{
	int adjvex;//终点
	Edge* next;//下一条弧
	int weight;//权
	Edge(int ADJVEX=0,Edge* NEXT=nullptr,int WEIGHT=0):
		adjvex(ADJVEX),next(NEXT),weight(WEIGHT){}
};

struct HeadNode //邻接表的头节点
{
	char data;
	Edge* firstedge;
	HeadNode(char DATA = 0,Edge*FIRSTEDGE=nullptr):
		data(DATA),firstedge(FIRSTEDGE){}
};

int Prim(HeadNode* G, int edges, int vertexs)
// 跟Dijkstra算法本质差不多，先选已知的最小的dist点，然后更新它到周围点的距离。
// 然后Prim算法要多一步来计算权值，所以返回了int值
{
	int* dist = new int[vertexs];
	bool* visited = new bool[vertexs];
	for (int i = 0; i < vertexs; i++)
	{
		dist[i] = 1000;
		visited[i] = false;
	}

	dist[0] = 0;//选一个你喜欢的位置，把这个位置当成初始点，距离是0

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
	cout << "请依次输入边数和顶点数" << endl;
	cin >> edges >> vertexs;
	HeadNode* avgraph = new HeadNode[vertexs];
	cout << "请输入每个顶点的数据" << endl;
	for (int i = 0; i < vertexs; i++)
		cin >> avgraph[i].data;
	cout << "请输入每条边的起点，终点，权值" << endl;
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
		//头插法
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
			delete temp; // 释放每个边的内存
		}
	}

	delete[] avgraph;
	return 0;
}
*/

/*
//贪心算法求解活动安排
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
// 马踏棋盘算法
const int rows = 12;
const int cols = 12;
const int xMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int yMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

struct Road
{
	int xNext;  // 终点的x坐标
	int yNext;  // 终点的y坐标
	int rnums;  // 该点能通往的下一步方向数

	Road(int X = 0, int Y = 0,int RNUMS = -1) : xNext(X), yNext(Y), rnums(RNUMS) {}

	bool operator> (const Road& r) const
	{
		return this->rnums > r.rnums;  // 路数少的优先
	}
};
// 冒泡排序，用于根据可行方向数（rnums）排序
void Bubblesort(Road roads[])
{
	Road temp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7 - i; j++)
		{
			// 排序：可行方向数少的优先
			if (roads[j]> roads[j + 1])
			{
				temp = roads[j + 1];
				roads[j + 1] = roads[j];
				roads[j] = temp;
			}
		}
	}
}
// 计算从当前位置可以走的下一步，保存到 roads 中
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
			// 计算该位置可以走的方向数
			for (int j = 0; j < 8; j++)
			{
				int sx = x_x + xMove[j];
				int sy = y_y + yMove[j];
				if ((sx >= 0 && sx < rows) && (sy >= 0 && sy < cols) && Chess[sx][sy] == 0)
					roads[i].rnums++;
			}
		}
	}
	// 使用冒泡排序，按 rnums 从小到大排序
	Bubblesort(roads);
}

// 深度优先搜索
bool DFS(int Chess[][cols], int x, int y, int count)
{
	Chess[x][y] = count;  // 标记当前点为第 count 步

	if (count == rows * cols)  // 走完所有格子
		return true;

	Road roads[8];//每次都需要重新生成，或者外部设置好，每次都传递这个参数，可以节约空间
	nextXY(Chess, x, y, roads);  // 计算从当前点可以走的下一步

	// 遍历所有可行的方向，优先选择有最少可行方向的路径
	for (int i = 0; i < 8; i++)
	{
		if (roads[i].rnums >= 0)  // 这个路径可行不是说rnums非要大于0，等于0也可以，不然到不了终点，程序会无限进行下去
		{
			bool result = DFS(Chess, roads[i].xNext, roads[i].yNext, count + 1);
			//如果路径可行，就去看下一条路可不可行，这个过程会通过递归一直进行下去
			//直到遇到终点或者周围8个点无路可走
			//如果遇到终点，就会从最后一次递归开始返回true值，直到第一次递归，64次全部为true
			//如果遇到无路可走的点，就认为当前的路死了，然后把这个点重置为0，认为没有走过，然后返回false
			//上一级递归结束对这条路的探路，转去下一条路，直到到达终点。
			if (result)
				return true;
		}
	}
	Chess[x][y] = 0;  // 回溯
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
	cout << "请输入起始点的x,y坐标" << endl;
	int x0, y0;
	cin >> x0 >> y0;
	x0--,y0--;
	if (DFS(Chess, x0, y0, 1))
	{
		cout << "已找到路线" << endl;
		PrintMatrix(Chess); 
	}
	else
		cout << "失败" << endl;
	return 0;
}*/


/* 12.1 动态规划
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

int maxGOLD(Goldinf g[], int gold, int people,vector<vector<int>>&DP)//传金矿的特征，金矿数，人数,动态规划
{
	if (gold == 0) 
		return 0;

	if (DP[gold][people] != -1) 
	{
		return DP[gold][people];
	}
	if (people >= g[gold - 1].nums)// 表明这个矿可以挖 
	{
		// 两种选择：不挖或者挖这个矿
		int pos1 = maxGOLD(g, gold - 1, people, DP);  // 不挖
		int pos2 = maxGOLD(g, gold - 1, people - g[gold - 1].nums, DP) + g[gold - 1].values;  // 挖这个矿

		DP[gold][people] = MAX(pos1, pos2);
	}
	else 
	{
		DP[gold][people] = maxGOLD(g, gold - 1, people, DP);  // 不挖
	}

	return DP[gold][people];
}

int main()
{
	int goldnums, peoplenums;
	cout << "请输入金矿的数目以及能够提供的人数" << endl;
	cin >> goldnums >> peoplenums;
	Goldinf* group = new Goldinf[goldnums];
	cout << "请输入每座金矿的标签，金子数，需要开采的人数" << endl;
	for (int i = 0; i < goldnums; i++)
		cin >> group[i].tag >> group[i].values >> group[i].nums;

	vector<vector<int>> DP(goldnums + 1, vector<int>(peoplenums + 1, -1));

	cout << "动态规划后最多金子数为" << endl;
	int result = maxGOLD(group, goldnums, peoplenums,DP);
	cout << result << endl;
	cout << "下面是开采方案" << endl;
	int i = goldnums, j = peoplenums;
	while (i > 0 && j > 0) 
	{
		if (DP[i][j] != DP[i - 1][j]) 
		{
			// 说明第 i 个金矿被开采
			cout << group[i - 1].tag << endl;  // 打印被开采的金矿标签
			j -= group[i - 1].nums;  // 剩余的人数减少
		}
		i--;
	}

	return 0;
}
*/
/*
// 最长子序列
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
			end.push_back(s1[i - 1]);//数组下标最长==字符串总长-1
			i--; j--;
		}	
	}
	reverse(end.begin(), end.end());
	return end;
}
int main()
{
	string s1, s2;
	cout << "请输入两个序列" << endl;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	int LF[rows][cols] = { 0 };
	LCSfinder(s1, s2, LF);
	cout << "最长子序列的长度为 " << LF[l1][l2] << endl;
	cout << "该序列为 " << LCSmaker(LF,l1,l2,s1) << endl;
	return 0;
}
*/

/*
 // 0-1背包问题
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
	cout << "请输入物品总数以及背包总重" << endl;
	cin >> staffnums >> total_weight;
	staff* table = new staff[staffnums];
	cout << "请输入每个物品的标签，质量和价值" << endl;
	for (int i = 0; i < staffnums; i++)
		cin >> table[i].tag >> table[i].weight >> table[i].value;

	int strategy[max_nums][max_weight]{};
	for(int i=0;i<max_nums;i++)
		for (int j = 0; j < max_weight; j++)
		{
			strategy[i][j] = -1;
		}

	int out = Zero_One(table, staffnums, total_weight, strategy);
	cout << "最佳方案下可携带价值为" << out << "的物品" << endl;
	cout << "方案如下" << endl;
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



