#include "MyStack.h"

MyStack::MyStack(int size){
	m_iSize = size;
	m_pBuffer = new string[size];
	m_iTop = 0;
		
}
MyStack::~ MyStack(){
	delete []m_pBuffer ;
} 
bool MyStack::stackEmpty(){
	if (0 == m_iTop){
		return true;
	}
	return false;
} 
bool MyStack::stackFull(){
	if ( m_iSize == m_iTop){
		return true;
	}
	return false;
}
void MyStack:: clearStack(){
	m_iTop = 0;
}
int MyStack::stackLength(){
	return m_iTop;
}
bool MyStack::push(string elem){
	if(stackFull()) {
		cout << " 栈为满 不能插值"; 
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}
bool MyStack::pop(string &elem){
	if(stackEmpty()) {
		cout << " 栈为空 不能取值";
	return false;
	}
	m_iTop--; 
	elem = m_pBuffer[m_iTop];
	return true;
}
void MyStack::stackTraverse(bool isFromBottom){
	if (isFromBottom == true){
		for(int i = 0;i < m_iTop; i++){
			cout << m_pBuffer[i] << " ";
			
		}
		cout << endl;
	}
	if (isFromBottom == false){
		for(int i = m_iTop - 1;i >= 0; i--){
			cout << m_pBuffer[i] << " ";
		}
		cout << endl;
	}
}




