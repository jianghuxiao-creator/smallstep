#include <iostream>
#include <string>
using namespace std;
class MyStack{
public :
	MyStack(int size);     //分配内存初始化栈空间，设定栈容量 
	~ MyStack();           //回收栈空间内存 
	bool stackEmpty();     //判断栈是否已空，为满返回true  
	bool stackFull();      //判断栈是否已满，为满返回true 
	void clearStack();     //清空栈 
	int stackLength();     //已有元素的个数 
	bool push(string elem);  //元素入栈，栈顶上升 
	bool pop(string &elem);  //元素出栈，栈顶下降 
	void stackTraverse(bool isFromBottom);  //遍历栈中所有元素 	
private:
	string *m_pBuffer; //栈空间指针 
	int m_iSize;	//栈容量 
	int m_iTop;      //栈顶	
}; 
