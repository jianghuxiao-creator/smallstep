#include "MyQueue.h"

int main()
{
	MyQueue *myQueue = new MyQueue(4);
	if(myQueue -> QueueEmpty())
	{
		cout << " 为空" << endl; 
	}
	
	myQueue -> EnQueue(2);
	myQueue -> EnQueue(5);
	myQueue -> EnQueue(9);
	myQueue -> EnQueue(7);
	
	if(myQueue -> QueueFull())
	{
		cout << " 为满" << endl; 
	} 
	
	myQueue -> QueueTraverse();
	
	cout << endl;
	cout << " 队列长度：" << myQueue ->  QueueLength() << endl;
	
	int elem = -1;
	myQueue -> DeQueue(elem);
	cout << " 删除的值为：" << elem << endl;
	
	cout << " 队列长度：" << myQueue ->  QueueLength() << endl;
	myQueue -> QueueTraverse();
	cout << endl;
	
	delete myQueue;
	myQueue = NULL;
	
}
