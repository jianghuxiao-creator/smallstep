#include <iostream>
#include "Node.h"
using namespace std;
class List
{
	public:
		List();         //构造线性表 
		~List();               //销毁线性表 
		void ClearList();      //清空 
		bool ListEmpty();      //判空
		int ListLength();      //获取长度
		bool GetElem(int i,Node *pNode);//返回指定位置的值
		int LocateElem(Node *pNode);//返回值定值的位置
		bool PriorElem(Node *pCurrentNode,Node *pPreNode);//返回指定值的前驱
		bool NextElem(Node *pCurrentNode,Node *pNextNode);//返回指定值的后继
		void ListTraverse();   //遍历线性表
		bool ListInsert(int i,Node *pNode);//在位置i插入pNode
		bool ListDelete(int i,Node *pNode);// 在位置i删除pNode 并取出pNode
		bool ListInsertHead(Node *pNode);
		bool ListInsertTail(Node *pNode);
		 		 				
	private:
	Node *m_pList;	
	int m_iLength;	
	
};
