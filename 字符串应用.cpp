/*
�ַ���Ӧ��
strcpy(s1,s2)  s2���Ƶ�s1 
strcat(s1,s2)  s2���ӵ�s1
strlen(s)      ��ȡs�ĳ���
strcmp(s1,s2)  �Ƚ�s1��s2�Ƿ���ȣ�����򷵻�false
gets(s)        �����ַ��� 
*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char s1[80];
	char s2[80];
	gets(s1);            
	gets(s2);
	cout << "s1�ĳ��ȣ�" << strlen(s1) << endl;	
	if (!strcmp(s1,s2)){
		cout << "s1��s2��ȡ�" << endl;
	}
	strcat(s1,s2);
	cout << "s2���ӵ�s1��" << s1 << endl; 
	strcpy(s2,s1);
	cout << "s1���Ƶ�s2��" << s2; 
}
