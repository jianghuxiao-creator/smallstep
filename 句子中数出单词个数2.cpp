/*
输入一个英文句子，单词间由若干空格隔开，数出有多少个单词，不区分大小写（大小写相同的为同一个单词） 
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	char ch[100];
	cout << " 请输入一个英文句子：" << endl; 
	gets(ch);
	char temp[20][15] = {0};          //存放单词 
	int count;
	if(ch[0] == ' '){
		count = 0;
	}else{
		count = 1;
	} 
	int i = 0;
	int m = 0, n = 0;
//	bool bl = true;
	int s = -1;        //计数 
	while (ch[i] != '\0'){               //取单词 
		if(ch[i] == ' ' && ch[i + 1] != ' ' &&  ch[i + 1] != '\0'){ 
			count ++;
			m++;
			n = 0;
		} else{
			if(ch[i] != ' '){
				temp [m][n++] = ch[i];
			}
			
		}
		i++;
	} 
	n = 14;
	for (int i = 0;i <= m;i++){             //输出每个单词 
		for (int j = 0; j <= n;j++){
			cout << temp[i][j];
		}
		cout << endl;
	} 
	
	 cout << "m:" << m << "n:" << n << endl;
	 cout << " 单词数：" << count << endl << endl; 
	 
	for (int i = 0;i < m;i++){                    //寻找相同元素 
		for(int j = i + 1; j <= m;j++){ 
			for (int k = 0;k <= n;k++){
				cout << "if前：" << "temp[" << i << "][" << k << "]："<<temp[i][k] 
				<< "   and   " << "temp[" << j << "][" << k << "]：" << temp[j][k] << endl;
					
				if (temp[i][k] == temp[j][k] || abs(temp[i][k] - temp[j][k] ) == 32){
						s++;
						cout << " 计数变量s=" << s << endl;				
					cout << temp[i][k] << "   and   " << temp[j][k] << endl;
					//cout << " 第一次bl:"   << bl << endl; 
					//break; 
				}
								
			}
			if (s == n){
				cout << " 执行s == n" << endl;
				count --;
				for (int f = j; f < m;f++){     //删除一个相同元素 
					for ( int g = 0;g < n;g++){
					temp[f][g] = temp[f + 1][g];	
					}				
				}
				
				m--;
				j--;
				cout << " m的中间值：" << m << endl;
				cout << " j的中间值：" << j << endl;
				cout << " 中间单词列表：" << endl;
				for (int i = 0;i <= m;i++){             //输出每个单词 
						for (int j = 0; j <= n;j++){
							cout << temp[i][j];
						}
						cout << endl;
				} 					
				}
				s = -1;
			//bl = true;
			cout << " 第" << i << " 次：单词数：" << count << endl; 
		}			
	}
	cout << " 共有" << count << " 个单词" << endl; 
	cout << "m的最终值： "  << m << endl; 
}

