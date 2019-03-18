#include "List.h"

List::List()
{
	m_pList = new Node;
	m_pList -> date.setXY(0,0);
	m_pList -> next = NULL;
	m_iLength = 0;
}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListEmpty()
{
	if(m_iLength == 0)
	{
		return true;
	}
	return false; 
} 

int List::ListLength()
{
	return m_iLength;
}

void List::ClearList()
{
	Node *currentNode = m_pList -> next;
	while (currentNode != NULL)
	{
		Node *temp = currentNode -> next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList -> next = NULL;
	m_iLength = 0;
}

bool List::ListInsertHead(Node *pNode)        //和视频有差异 
{
	Node *newNode = new Node  ; 
	if(newNode == NULL)
	{
		return false;
	}
	newNode -> date = pNode -> date;
	
	newNode -> next = m_pList ->next;
	m_pList -> next = newNode;
	m_iLength ++;
	return true;
}

bool List::ListInsertTail(Node *pNode)
{
		
	Node *currentNode = m_pList;
	
	while(currentNode -> next != NULL)     //找到最后一个结点 
	{
		currentNode = currentNode -> next;	
	}
	
	//需要从堆中申请内存，从栈中申请的内存函数调用后就被回收了；也就不能使用在链表中了
	Node *newNode = new Node  ;                                
	if(newNode == NULL)
	{
		return false;
	}
	newNode -> date = pNode -> date;	
	newNode -> next = NULL;
	
	currentNode -> next = newNode;
	m_iLength ++;
	return true;
}
	
bool List::ListInsert(int i,Node *pNode)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}
	
	Node *currentNode = m_pList;
	for(int k = 0;k < i;k++)
	{
		currentNode = currentNode -> next;
	}
	
	Node *newNode = new Node ;
	if(newNode == NULL)
	{
		return false;
	}
	newNode -> date = pNode -> date;
	
	Node *temp = NULL;
	temp = currentNode -> next;
	currentNode -> next = newNode;
	newNode -> next = temp;
		
	m_iLength++;
	return true;	
}

bool List::ListDelete(int i,Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	
	for(int k = 0; k <= i;k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode -> next; 	
	} 
	
	currentNodeBefore -> next = currentNode -> next;
	
	pNode -> date = currentNode -> date;
	
	delete currentNode;
	currentNode = NULL;
	m_iLength --;
	return true;
}

bool List::GetElem(int i,Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	for(int k = 0; k <= i;k++)
	{
		currentNode = currentNode -> next; 	
	} 
	
	pNode -> date = currentNode -> date;
	return true;
}

int List::LocateElem(Node *pNode)
{
	 Node *currentNode = m_pList;
	int count = 0;
	
	while(currentNode -> next != NULL)
	{
		currentNode = currentNode -> next;
		if(currentNode -> date == pNode -> date)
		{
			return count;
		}
		count++;
	}
	
	return -1;
}

bool List::PriorElem( Node *pCurrentNode, Node *pPreNode)
{
	 Node *currentNode = m_pList;
	 Node *currentNodeBefore = NULL;
	
	while(currentNode -> next != NULL)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode -> next;
		if(currentNode -> date == pCurrentNode -> date)
		{
			if(currentNodeBefore == m_pList)
			{
				return false;
			}
			pPreNode -> date = currentNodeBefore -> date;
			return true;
		}		
	}
	return false;
}

bool List::NextElem( Node *pCurrentNode, Node *pNextNode)
{
	 Node   *currentNode = m_pList;
	while(currentNode -> next != NULL)
	{		
		currentNode = currentNode -> next;
		if(currentNode -> date == pCurrentNode -> date)
		{
			if(currentNode -> next == NULL)
			{
				return false;
			}
			pNextNode -> date = currentNode -> next -> date;
			return true;
		}		
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while(currentNode != NULL)
	{
		currentNode = currentNode -> next; 
		currentNode -> printNode();
	} 
}









 
