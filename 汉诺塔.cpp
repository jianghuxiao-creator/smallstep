/*
 ͨ���ݹ�����ŵ������ ��A B C �������ӣ�������A�ϵ����Ӿ�B�ƶ���C,ÿ��ֻ���ƶ�һ�����ӡ� 
 ��һ����������ǽ� n-1 ������ͨ��C�ƶ���B���ڽ���n�������ƶ���C���ڽ�B��n-1�������ƶ���C��
 �����ͽ�N����������n-1�����⣬�ظ�������̣�ÿ��N��1�����N=1ʱ��ֱ���ƶ����ɡ� 
 move (n ,A,B,C):AԴ����B��������CĿ����
 �ɷֽ�Ϊ��
 move (n-1,A,C,B);
 A -> C; 
 move (n-1,B,A,C);
*/
#include <iostream>
using namespace std;
int sum = 0; //���貽�� 
void move(int n, char a,char b,char c){
	if (1 == n){
		cout << a << " -> " << c <<endl;
		sum++;
	}
	else{
		move ( n-1,a,c,b);
		cout << a << " -> " << c << endl; 
		sum++;
		move (n-1,b,a,c);
	}
}
int main(){
	loop: 
	int total;
	cout << " please input ���Ӹ��� n:";
	cin >> total;
	move (total,'A','B','C');
	cout << " ����" << sum << " ��" << endl;
	sum = 0;
	cout << endl;
	goto loop;	
	return 0;	
}
