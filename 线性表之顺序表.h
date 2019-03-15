#include <iostream>
using namespace std;
template <typename T>
class List
{
	public:
		List(int size);         //�������Ա� 
		~List();               //�������Ա� 
		void ClearList();      //��� 
		bool ListEmpty();      //�п�
		bool ListFull();       //����
		int ListLength();      //��ȡ����
		bool GetElem(int i,T *e);//����ָ��λ�õ�ֵ
		int LocateElem(T *e);//����ֵ��ֵ��λ��
		bool PriorElem(T *currentElem,T *preElem);//����ָ��ֵ��ǰ��
		bool NextElem(T *currentElem,T *nextElem);//����ָ��ֵ�ĺ��
		void ListTraverse();   //�������Ա�
		bool ListInsert(int i,T *e);//��λ��i����e
		bool ListDelete(int i,T *e);// ��λ��iɾ��e ��ȡ��e
		 		 				
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
	if (temp == -1 || temp == 0)       //û�ҵ�����Ϊ��Ԫ�� 
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
	if (temp == -1 || temp == m_iLength - 1)       //û�ҵ�����Ϊ��Ԫ�� 
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


