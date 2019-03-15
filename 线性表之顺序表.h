#include <iostream>
using namespace std;
template <typename T>
class List
{
	public:
		List(int size);         //构造线性表 
		~List();               //销毁线性表 
		void ClearList();      //清空 
		bool ListEmpty();      //判空
		bool ListFull();       //判满
		int ListLength();      //获取长度
		bool GetElem(int i,T *e);//返回指定位置的值
		int LocateElem(T *e);//返回值定值的位置
		bool PriorElem(T *currentElem,T *preElem);//返回指定值的前驱
		bool NextElem(T *currentElem,T *nextElem);//返回指定值的后继
		void ListTraverse();   //遍历线性表
		bool ListInsert(int i,T *e);//在位置i插入e
		bool ListDelete(int i,T *e);// 在位置i删除e 并取出e
		 		 				
	private:
	T *m_pList;
	int m_iSize;
	int m_iLength;	
	
};

template <typename T>
List<T>::List(int size) 
{
	m_iSize = size;
	m_pList = new T[30];
	m_iLength = 0;
}

template <typename T>
List<T>::~List()
{
	delete []m_pList;
}

template <typename T>
void List<T>::ClearList()
{
	m_iLength = 0;
}

template <typename T>
bool List<T>::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	return false;
}

template <typename T>
bool List<T>::ListFull()
{
	if (m_iLength == m_iSize)
	{
		return true;
	}
	return false;
}

template <typename T>
int List<T>::ListLength()
{
	return m_iLength;
}

template <typename T>
bool List<T>::GetElem(int i,T *e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	*e = m_pList[i];
	return true;
}

template <typename T>
int List<T>::LocateElem(T *e)
{
	for(int k = 0; k < m_iLength;k++)
	{
		if(m_pList[k] == *e)
		{
			return k;
		}
	}
	return -1;
}

template <typename T>
bool List<T>::PriorElem(T *currentElem,T *preElem)
{
	int temp = LocateElem(currentElem);
	if (temp == -1 || temp == 0)       //没找到或者为首元素 
	{
		return false;
	}
	else
	{
		*preElem = m_pList[temp - 1]; 
	}
	return true;
}

template <typename T>
bool List<T>::NextElem(T *currentElem,T *nextElem)
{
	int temp = LocateElem(currentElem);
	if (temp == -1 || temp == m_iLength - 1)       //没找到或者为首元素 
	{
		return false;
	}
	else
	{
		*nextElem = m_pList[temp + 1]; 
	}
	return true;
}

template <typename T>
void List<T>::ListTraverse()
{
	for(int i = 0;i < m_iLength;i++)
	{
		cout << m_pList[i] << "   " ;	
	}
	cout << endl;
}

template <typename T>
bool List<T>::ListInsert(int i,T *e)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}
	for(int k = m_iLength - 1;k >= i;k--)
	{
		m_pList[k + 1] = m_pList[k];
	}
	m_pList[i] = *e;
	m_iLength ++;
	return true;
}

template <typename T>
bool List<T>::ListDelete(int i,T *e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	*e = m_pList[i];
	for(int k = i;k < m_iLength - 1;k++)
	{
		m_pList[k] = m_pList[k + 1];
	}
	m_iLength--;
	return true;
}


