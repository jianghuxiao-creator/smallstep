/*
����һ��Ӣ�ľ��ӣ����ʼ������ɿո�����������ж��ٸ����ʣ������ִ�Сд����Сд��ͬ��Ϊͬһ�����ʣ� 
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
//	bool bl = true;
	int s = -1;        //���� 
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
					
				if (temp[i][k] == temp[j][k] || abs(temp[i][k] - temp[j][k] ) == 32){
						s++;
						cout << " ��������s=" << s << endl;				
					cout << temp[i][k] << "   and   " << temp[j][k] << endl;
					//cout << " ��һ��bl:"   << bl << endl; 
					//break; 
				}
								
			}
			if (s == n){
				cout << " ִ��s == n" << endl;
				count --;
				for (int f = j; f < m;f++){     //ɾ��һ����ͬԪ�� 
					for ( int g = 0;g < n;g++){
					temp[f][g] = temp[f + 1][g];	
					}				
				}
				
				m--;
				j--;
				cout << " m���м�ֵ��" << m << endl;
				cout << " j���м�ֵ��" << j << endl;
				cout << " �м䵥���б�" << endl;
				for (int i = 0;i <= m;i++){             //���ÿ������ 
						for (int j = 0; j <= n;j++){
							cout << temp[i][j];
						}
						cout << endl;
				} 					
				}
				s = -1;
			//bl = true;
			cout << " ��" << i << " �Σ���������" << count << endl; 
		}			
	}
	cout << " ����" << count << " ������" << endl; 
	cout << "m������ֵ�� "  << m << endl; 
}

