/*
����һ��Ӣ�ľ��ӣ����ʼ������ɿո�����������ж��ٸ����ʣ����ִ�Сд 
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	char ch[100];
	cout << " ������һ��Ӣ�ľ��ӣ�" << endl; 
	gets(ch);
	char temp[20][15] = {0};          //��ŵ��� 
	int count;
	if(ch[0] == ' '){
		count = 0;
	}else{
		count = 1;
	} 
	int i = 0;
	int m = 0, n = 0;
	bool bl = true;
	while (ch[i] != '\0'){               //ȡ���� 
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
	for (int i = 0;i <= m;i++){             //���ÿ������ 
		for (int j = 0; j <= n;j++){
			cout << temp[i][j];
		}
		cout << endl;
	} 
	
	 cout << "m:" << m << "n:" << n << endl;
	 cout << " ��������" << count << endl << endl; 
	 
	for (int i = 0;i < m;i++){                    //Ѱ����ͬԪ�� 
		for(int j = i + 1; j <= m;j++){ 
			for (int k = 0;k <= n;k++){
				cout << "ifǰ��" << "temp[" << i << "][" << k << "]��"<<temp[i][k] 
				<< "   and   " << "temp[" << j << "][" << k << "]��" << temp[j][k] << endl;
					
				if (temp[i][k] != temp[j][k] ){
					bl = false;					
					cout << temp[i][k] << "   and   " << temp[j][k] << endl;
					cout << " ��һ��bl:"   << bl << endl; 
					break; 
				}
								
			}
			if (bl == true){
				cout << " ִ��bl == true" << endl;
				count --;
				for (int f = j; f < m;f++){     //ɾ��һ����ͬԪ�� 
					for ( int g = 0;g < n;g++){
					temp[f][g] = temp[f + 1][g];	
					}				
				}
				m--;
				j--;
				cout << " m���м�ֵ��" << m << endl;
				cout << " �м䵥���б�" << endl;
				for (int i = 0;i <= m;i++){             //���ÿ������ 
						for (int j = 0; j <= n;j++){
							cout << temp[i][j];
						}
						cout << endl;
				} 					
				}
			bl = true;
			cout << " ��" << i << " �Σ���������" << count << endl; 
		}			
	}
	cout << " ����" << count << " ������" << endl; 
	cout << "m������ֵ�� "  << m << endl; 
}

