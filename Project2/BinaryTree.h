#pragma once
#include<iostream>
#include<string>
#include"Queue.h"

using namespace std;
using namespace QUEUE;

namespace BINARYTREE
{
	template<typename ElemType>
	struct BiTNode
	{
		BiTNode* left;
		BiTNode* right;
		ElemType data;

		BiTNode(BiTNode* LEFT = nullptr, BiTNode* RIGHT = nullptr, ElemType DATA = ElemType{}) :
			left(LEFT), right(RIGHT), data(DATA){}

		~BiTNode()
		{
			if constexpr (is_pointer_v<ElemType>)//检测ElemType型是否为指针，是就删除
			// constexpr是一种编译时就确定是否执行的语句，如果编译时，ElemType就已经不是指针了，那么在运行开始后析构函数都不会运作
			{
				delete data;
				data = nullptr;
			}
		}
	};

	template<typename ElemType>
	class BiT
	{
	public:

		void CreatTree(BiTNode<ElemType>*& root); // 使用#符号标识插入结束

		void RemoveTree(BiTNode<ElemType>*& node); //node==root就把整棵树删了

		void InsertTreeNode(BiTNode<ElemType>*& node,ElemType data);//默认左插

		BiTNode<ElemType>* MergeTree(BiTNode<ElemType>* right, BiTNode<ElemType>* left, ElemType data);

		bool IsTreeEmpty(BiTNode<ElemType>* node);
		bool IsTreeLeaf(BiTNode<ElemType>* node);

		void Preorder(BiTNode<ElemType>* root);
		void Inorder(BiTNode<ElemType>* root);
		void Postorder(BiTNode<ElemType>* root);
		void Floororder(BiTNode<ElemType>* root, Queue<BiTNode<ElemType>*>*& queue);//要使用队列完成
	};

	template<typename ElemType>
	void BiT<ElemType>::CreatTree(BiTNode<ElemType>*& root)
	{
		ElemType Elem{};
		cin >> Elem;
		if (Elem != '#')
		{
			BiTNode<ElemType>* node = new BiTNode<ElemType>;
			node->data = Elem;

			root = node;
			CreatTree(root->left);
			CreatTree(root->right);
			//这里采用前序遍历的方法来创建树，因此输入就按照前序遍历的方法来输入
		}
		else
			return;
	}

	template<typename ElemType>
	void BiT<ElemType>::RemoveTree(BiTNode<ElemType>*& node)
	{
		if (node == nullptr)
		{
			throw runtime_error("空树");
			return;
		}

		if (!node->left && !node->right)
		{
			delete node;//把运行到的结点申请的内存回收
			node = nullptr;//结点置为空指针，防止悬空指针
		}

		RemoveTree(node->left);
		RemoveTree(node->right);
		delete node;
		node = nullptr;
	}

	template<typename ElemType>
	void BiT<ElemType>::InsertTreeNode(BiTNode<ElemType>*& node, ElemType data)
	{
		BiTNode<ElemType>* newNode = new BiTNode<ElemType>;
		newNode->data = data;

		if (!node->right)
			node->right = newNode;
		else if (!node->left)
			node->left = newNode;
		else
		{
			delete newNode;
			return;
		}
	}

	template<typename ElemType>
	BiTNode<ElemType>* BiT<ElemType>::MergeTree(BiTNode<ElemType>* left, BiTNode<ElemType>* right, ElemType data)
	{
		BiTNode<ElemType>* merge = new BiTNode<ElemType>;
		if (merge == nullptr)
			return nullptr;
		else
		{
			merge->data = data;
			//把根节点的地址复制，从而左子树的根节点地址在两棵树内都存在，但是物理空间内只有一颗子树
			merge->left = left;
			merge->right = right;
		}
		//这里不能采用remove函数，因为是拼接树而不是复制树，传入的左右子树只是归属有了改变，本身未作任何修改
		return merge;
	}

	template<typename ElemType>
	bool BiT<ElemType>::IsTreeEmpty(BiTNode<ElemType>* root)
	{
		return root == nullptr;
	}

	template<typename ElemType>
	bool BiT<ElemType>::IsTreeLeaf(BiTNode<ElemType>* node)
	{
		return !node->left && !node->right;
	}

	template<typename ElemType>
	void BiT<ElemType>::Preorder(BiTNode<ElemType>* node)//Node,Left,Right:NLR
	{
		if (node != nullptr)
		{
			cout << node->data << endl;
			Preorder(node->left);
			Preorder(node->right);
		}
		return;
	}

	template<typename ElemType>
	void BiT<ElemType>::Inorder(BiTNode<ElemType>* node)
	{
		if (node != nullptr)
		{
			Inorder(node->left);
			cout << node->data << endl;
			Inorder(node->right);
		}
		return;
	}

	template<typename ElemType>
	void BiT<ElemType>::Postorder(BiTNode<ElemType>* node)
	{
		if (node != nullptr)
		{
			Postorder(node->left);
			Postorder(node->right);
			cout << node->data << endl;
		}
		return;
	}
	template<typename ElemType>
	void BiT<ElemType>::Floororder(BiTNode<ElemType>* root, Queue<BiTNode<ElemType>*>*& queue)
	{
		if (!root)
			return;

		queue->EnQueue(root);//先把根节点入进来

		while(!queue->isEmpty())
		{
			BiTNode<ElemType>* Guns = queue->GetHeadElem();
			cout << Guns->data << endl;

			if (Guns->left)//如果有左孩子，加进去
				queue->EnQueue(Guns->left);
			if (Guns->right)//同上
				queue->EnQueue(Guns->right);
			queue->OutQueue();//访问完成的结点就出队
		}
	}
}


