#include <iostream>
#include <string>
using namespace std;
class MyStack{
public :
	MyStack(int size);     //�����ڴ��ʼ��ջ�ռ䣬�趨ջ���� 
	~ MyStack();           //����ջ�ռ��ڴ� 
	bool stackEmpty();     //�ж�ջ�Ƿ��ѿգ�Ϊ������true  
	bool stackFull();      //�ж�ջ�Ƿ�������Ϊ������true 
	void clearStack();     //���ջ 
	int stackLength();     //����Ԫ�صĸ��� 
	bool push(string elem);  //Ԫ����ջ��ջ������ 
	bool pop(string &elem);  //Ԫ�س�ջ��ջ���½� 
	void stackTraverse(bool isFromBottom);  //����ջ������Ԫ�� 	
private:
	string *m_pBuffer; //ջ�ռ�ָ�� 
	int m_iSize;	//ջ���� 
	int m_iTop;      //ջ��	
}; 
