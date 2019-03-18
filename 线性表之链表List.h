#include <iostream>
#include "Node.h"
using namespace std;
class List
{
	public:
		List();         //�������Ա� 
		~List();               //�������Ա� 
		void ClearList();      //��� 
		bool ListEmpty();      //�п�
		int ListLength();      //��ȡ����
		bool GetElem(int i,Node *pNode);//����ָ��λ�õ�ֵ
		int LocateElem(Node *pNode);//����ֵ��ֵ��λ��
		bool PriorElem(Node *pCurrentNode,Node *pPreNode);//����ָ��ֵ��ǰ��
		bool NextElem(Node *pCurrentNode,Node *pNextNode);//����ָ��ֵ�ĺ��
		void ListTraverse();   //�������Ա�
		bool ListInsert(int i,Node *pNode);//��λ��i����pNode
		bool ListDelete(int i,Node *pNode);// ��λ��iɾ��pNode ��ȡ��pNode
		bool ListInsertHead(Node *pNode);
		bool ListInsertTail(Node *pNode);
		 		 				
	private:
	Node *m_pList;	
	int m_iLength;	
	
};
