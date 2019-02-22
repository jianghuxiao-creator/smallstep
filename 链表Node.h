
/*结点要素：索引   数据 左孩子指针 右孩子指针 父结点指针*/
#include <iostream>
using namespace std;
class Node{
public:
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();                               //中序遍历 
	void PostorderTraversal();
	int index;
	int date;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};
