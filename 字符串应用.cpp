/*
字符串应用
strcpy(s1,s2)  s2复制到s1 
strcat(s1,s2)  s2连接到s1
strlen(s)      获取s的长度
strcmp(s1,s2)  比较s1和s2是否相等，相等则返回false
gets(s)        输入字符串 
*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char s1[80];
	char s2[80];
	gets(s1);            
	gets(s2);
	cout << "s1的长度：" << strlen(s1) << endl;	
	if (!strcmp(s1,s2)){
		cout << "s1和s2相等。" << endl;
	}
	strcat(s1,s2);
	cout << "s2链接到s1后：" << s1 << endl; 
	strcpy(s2,s1);
	cout << "s1复制到s2后：" << s2; 
}
