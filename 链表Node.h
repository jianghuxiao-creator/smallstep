
/*���Ҫ�أ�����   ���� ����ָ�� �Һ���ָ�� �����ָ��*/
#include <iostream>
using namespace std;
class Node{
public:
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();                               //������� 
	void PostorderTraversal();
	int index;
	int date;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};
