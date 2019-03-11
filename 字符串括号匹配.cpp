#include <iostream>
#include <cstring>
using namespace std;
#include "MyStack.h"
#include "Cordinate.h"
#define BINARY 2
#define OCTONARY 8
#define HXADECIMAL 16
int main()
{

	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);
		
	char ch[] = "[()[()]";
	char currentNeed = 0;
		
	for (int i = 0; i < strlen(ch);i++)
	{		 
		if (ch[i] != currentNeed)
		{
			pStack -> push(ch[i]);
									
			switch(ch[i])
			{			
				case '[': 
					if(currentNeed != 0) 
					{
						pNeedStack -> push(currentNeed);	
					}
					currentNeed = ']';				
					break;
				case'(': 
					if(currentNeed != 0) 
						{
							pNeedStack -> push(currentNeed);							
						}
					currentNeed = ')';
					break;
				default:
					cout << " ×Ö·û´®À¨ºÅ²»Æ¥Åä";
					return 0; 
			}
		}
		else
		{			
			char elem;
			pStack -> pop(elem);
			if(!pNeedStack -> pop(currentNeed))
			{
				currentNeed = 0;
			}
		}	
	}
	
	if (pStack -> stackEmpty())
	{
		cout << " ×Ö·û´®À¨ºÅ Æ¥Åä"; 
	}
	else 
	{
		cout << " ×Ö·û´®À¨ºÅ²»Æ¥Åä"; 
	}
	
	delete pStack;
	pStack = NULL;
	delete pNeedStack;
	pNeedStack = NULL;
}
