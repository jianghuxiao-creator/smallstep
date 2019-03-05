#include "MyQueue.h"

int main()
{
	MyQueue *myQueue = new MyQueue(4);
	if(myQueue -> QueueEmpty())
	{
		cout << " Ϊ��" << endl; 
	}
	
	myQueue -> EnQueue(2);
	myQueue -> EnQueue(5);
	myQueue -> EnQueue(9);
	myQueue -> EnQueue(7);
	
	if(myQueue -> QueueFull())
	{
		cout << " Ϊ��" << endl; 
	} 
	
	myQueue -> QueueTraverse();
	
	cout << endl;
	cout << " ���г��ȣ�" << myQueue ->  QueueLength() << endl;
	
	int elem = -1;
	myQueue -> DeQueue(elem);
	cout << " ɾ����ֵΪ��" << elem << endl;
	
	cout << " ���г��ȣ�" << myQueue ->  QueueLength() << endl;
	myQueue -> QueueTraverse();
	cout << endl;
	
	delete myQueue;
	myQueue = NULL;
	
}
