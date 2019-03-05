#include <iostream>
using namespace std;

class MyQueue
{
	public:
		MyQueue(int queueCapacity);    //创建队列 
		~MyQueue();					//销毁i队列 
		void Clear();				//清空队列 
		bool QueueEmpty(); 			//判空
		bool QueueFull(); 			//判满 
		int QueueLength();          //队列长度
		bool EnQueue(int element);  //插入新元素 
		bool DeQueue(int &element); //首元素出队 
		void QueueTraverse();       //遍历队列 
		
	private:
		int *m_pQueue;          //队列数组指针
		int m_iQueueLen;        //队列袁术个数
		int m_iQueueCapacity;   //队列数组容量 
		int m_iHead;            //队头
		int m_iTail;            //队尾 
};
