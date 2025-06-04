#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::string;
using std::vector;

class HuffmanNode
{
	char data;
	int freq;
	HuffmanNode* left;
	HuffmanNode* right;

public:
	HuffmanNode(char, int, HuffmanNode*, HuffmanNode*) :
		data(char()), freq(0), left(nullptr), right(nullptr) {}

	bool operator> (const HuffmanNode& other) const
	{
		return this->freq > other.freq;
	}

	//&符传递地址，所以将通过地址直接对地址所指向的内容进行操作，const符提前声明进行的操作将不会改变内容本身
	HuffmanNode* Creat(const unordered_map<char, int>& freqmap);

	void GenerateCodes(HuffmanNode* root, const string& codes, unordered_map<char, string>& HuffmanCodes);
	//走一次左树写入0，走一次右树写入1

	void PrintCodes(const unordered_map<char, string>& HuffmanCodes);

	void DeleteHuffmanTree(HuffmanNode* root);
};


HuffmanNode* HuffmanNode::Creat(const unordered_map<char, int>& freqmap)
{

	std::priority_queue<HuffmanNode, vector<HuffmanNode>,std::greater<HuffmanNode>> minHeap;
	// 创建优先队列，这个队列的优先级是低值优先
	// 第一个参数为元素类型，第二个参数为存储元素的容器，第三个参数为比较器，默认为最大堆：less<元素类型>。
	// 比较器作用原理：先把数据压入容器并放在末尾，然后调用比较器，倒第二个元素？最后一个元素
	// 鉴于是less比较器，如果？实际上代表>，则less函数返回false，内部的swap函数不会执行，
	// 如果？实际上代表<，那么less函数返回true，内部swap执行，因此进行上浮，也就是把大的浮上去，形成最大堆

	for (const auto& pair : freqmap)
	{
		minHeap.push(HuffmanNode{ pair.first, pair.second ,nullptr,nullptr });
	}

	while (minHeap.size() > 1)
	{
		HuffmanNode* left = new HuffmanNode{ minHeap.top() };
		minHeap.pop();

		HuffmanNode* right = new HuffmanNode{ minHeap.top() };
		minHeap.pop();

		HuffmanNode* parent = new HuffmanNode{ '\0',left->freq + right->freq,left,right };
		minHeap.push(*parent);
	}
	HuffmanNode* root = new HuffmanNode{ '\0',minHeap.top().freq,minHeap.top().left,minHeap.top().right };

	return root;
}

void HuffmanNode::GenerateCodes(HuffmanNode* root, const string& codes, unordered_map<char, string>& HuffmanCodes)
{
	if (!root)
		return;

	if (!root->left && !root->right)
	{
		HuffmanCodes[root->data] = codes;
		return;
	}

	GenerateCodes(root->left, codes + '0', HuffmanCodes);
	GenerateCodes(root->right, codes + '1', HuffmanCodes);

}

void HuffmanNode::PrintCodes(const unordered_map<char, string>& HuffmanCodes)
{
	for (const auto& pair : HuffmanCodes)
		cout << pair.first << ':' << pair.second << endl;
}

void HuffmanNode::DeleteHuffmanTree(HuffmanNode* root)
{
	if (!root->left && !root->right)
	{
		delete root;
		return;
	}
	DeleteHuffmanTree(root->left);
	DeleteHuffmanTree(root->right);

	delete root;
	return;
}