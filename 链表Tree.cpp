/*
Tree();                                                //������ 
~Tree();                                               //������
Node *SearchNode(int nodeIndex);                       //�������
bool AddNode(int nodeIndex,int direction,Node *pNode); //��ӽ��
bool DeleteNode(int nodeIndex,Node *pNode);            //ɾ�����
void PreorderTraversal();                              //ǰ����� 
void InorderTraversal();                               //������� 
void PostorderTraversal();                             //������� 

���Ҫ�أ�����   ���� ����ָ�� �Һ���ָ�� �����ָ��

             ��0��
             
	  5��1��		  8��2��
		
2��3��  6��4��    9��5��   7��6��  
*/
#include "Tree.h"
Tree::Tree(){
	m_pRoot = new Node();  
}

Tree::~Tree(){
	//DeleteNode(0,NULL);
	m_pRoot -> DeleteNode();
}
 
Node *Tree::SearchNode(int nodeIndex){
	 return m_pRoot -> SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex,int direction,Node *pNode){
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL){
		return false;
	} 
	
	Node * node = new Node();
	if (node == NULL){
		return false;
	}
	node -> index = pNode -> index;
	node -> date = pNode -> date;
	node -> pParent = temp;
	if (direction == 0){
		temp -> pLChild = node;
	}
	
	if (direction == 1){
		temp -> pRChild = node;
	}
	
	return true;
}

bool Tree::DeleteNode(int nodeIndex,Node *pNode){
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL){
		return false;
	} 
	
	if(pNode != NULL){
		pNode -> date = temp -> date;
	}
	
	temp -> DeleteNode();
	
	return true;
}

void Tree::PreorderTraversal(){
	m_pRoot -> PreorderTraversal();
}

void Tree::InorderTraversal(){
	m_pRoot -> InorderTraversal();
}

void Tree::PostorderTraversal(){
	m_pRoot -> PostorderTraversal();
}










