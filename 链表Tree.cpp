/*
Tree();                                                //创建树 
~Tree();                                               //销毁树
Node *SearchNode(int nodeIndex);                       //搜索结点
bool AddNode(int nodeIndex,int direction,Node *pNode); //添加结点
bool DeleteNode(int nodeIndex,Node *pNode);            //删除结点
void PreorderTraversal();                              //前序遍历 
void InorderTraversal();                               //中序遍历 
void PostorderTraversal();                             //后序遍历 

结点要素：索引   数据 左孩子指针 右孩子指针 父结点指针

             （0）
             
	  5（1）		  8（2）
		
2（3）  6（4）    9（5）   7（6）  
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










