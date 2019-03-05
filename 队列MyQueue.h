#include <iostream>
using namespace std;

class MyQueue
{
	public:
		MyQueue(int queueCapacity);    //�������� 
		~MyQueue();					//����i���� 
		void Clear();				//��ն��� 
		bool QueueEmpty(); 			//�п�
		bool QueueFull(); 			//���� 
		int QueueLength();          //���г���
		bool EnQueue(int element);  //������Ԫ�� 
		bool DeQueue(int &element); //��Ԫ�س��� 
		void QueueTraverse();       //�������� 
		
	private:
		int *m_pQueue;          //��������ָ��
		int m_iQueueLen;        //����Ԭ������
		int m_iQueueCapacity;   //������������ 
		int m_iHead;            //��ͷ
		int m_iTail;            //��β 
};
