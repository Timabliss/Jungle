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

	//&�����ݵ�ַ�����Խ�ͨ����ֱַ�ӶԵ�ַ��ָ������ݽ��в�����const����ǰ�������еĲ���������ı����ݱ���
	HuffmanNode* Creat(const unordered_map<char, int>& freqmap);

	void GenerateCodes(HuffmanNode* root, const string& codes, unordered_map<char, string>& HuffmanCodes);
	//��һ������д��0����һ������д��1

	void PrintCodes(const unordered_map<char, string>& HuffmanCodes);

	void DeleteHuffmanTree(HuffmanNode* root);
};


HuffmanNode* HuffmanNode::Creat(const unordered_map<char, int>& freqmap)
{

	std::priority_queue<HuffmanNode, vector<HuffmanNode>,std::greater<HuffmanNode>> minHeap;
	// �������ȶ��У�������е����ȼ��ǵ�ֵ����
	// ��һ������ΪԪ�����ͣ��ڶ�������Ϊ�洢Ԫ�ص�����������������Ϊ�Ƚ�����Ĭ��Ϊ���ѣ�less<Ԫ������>��
	// �Ƚ�������ԭ���Ȱ�����ѹ������������ĩβ��Ȼ����ñȽ��������ڶ���Ԫ�أ����һ��Ԫ��
	// ������less�Ƚ����������ʵ���ϴ���>����less��������false���ڲ���swap��������ִ�У�
	// �����ʵ���ϴ���<����ôless��������true���ڲ�swapִ�У���˽����ϸ���Ҳ���ǰѴ�ĸ���ȥ���γ�����

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