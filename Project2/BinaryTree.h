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
			if constexpr (is_pointer_v<ElemType>)//���ElemType���Ƿ�Ϊָ�룬�Ǿ�ɾ��
			// constexpr��һ�ֱ���ʱ��ȷ���Ƿ�ִ�е���䣬�������ʱ��ElemType���Ѿ�����ָ���ˣ���ô�����п�ʼ��������������������
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

		void CreatTree(BiTNode<ElemType>*& root); // ʹ��#���ű�ʶ�������

		void RemoveTree(BiTNode<ElemType>*& node); //node==root�Ͱ�������ɾ��

		void InsertTreeNode(BiTNode<ElemType>*& node,ElemType data);//Ĭ�����

		BiTNode<ElemType>* MergeTree(BiTNode<ElemType>* right, BiTNode<ElemType>* left, ElemType data);

		bool IsTreeEmpty(BiTNode<ElemType>* node);
		bool IsTreeLeaf(BiTNode<ElemType>* node);

		void Preorder(BiTNode<ElemType>* root);
		void Inorder(BiTNode<ElemType>* root);
		void Postorder(BiTNode<ElemType>* root);
		void Floororder(BiTNode<ElemType>* root, Queue<BiTNode<ElemType>*>*& queue);//Ҫʹ�ö������
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
			//�������ǰ������ķ��������������������Ͱ���ǰ������ķ���������
		}
		else
			return;
	}

	template<typename ElemType>
	void BiT<ElemType>::RemoveTree(BiTNode<ElemType>*& node)
	{
		if (node == nullptr)
		{
			throw runtime_error("����");
			return;
		}

		if (!node->left && !node->right)
		{
			delete node;//�����е��Ľ��������ڴ����
			node = nullptr;//�����Ϊ��ָ�룬��ֹ����ָ��
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
			//�Ѹ��ڵ�ĵ�ַ���ƣ��Ӷ��������ĸ��ڵ��ַ���������ڶ����ڣ���������ռ���ֻ��һ������
			merge->left = left;
			merge->right = right;
		}
		//���ﲻ�ܲ���remove��������Ϊ��ƴ���������Ǹ��������������������ֻ�ǹ������˸ı䣬����δ���κ��޸�
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

		queue->EnQueue(root);//�ȰѸ��ڵ������

		while(!queue->isEmpty())
		{
			BiTNode<ElemType>* Guns = queue->GetHeadElem();
			cout << Guns->data << endl;

			if (Guns->left)//��������ӣ��ӽ�ȥ
				queue->EnQueue(Guns->left);
			if (Guns->right)//ͬ��
				queue->EnQueue(Guns->right);
			queue->OutQueue();//������ɵĽ��ͳ���
		}
	}
}


