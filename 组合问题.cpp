/*
组合问题  void comb(int m,int k)为找出1，2，3...m中任取k个数字组合
当确定了第一个数字，就变成了从m-1个数字中选取k-1个数字组合，形成递归， 
*
#include <iostream>
using namespace std;
int a[100] = {0};
void comb(int m,int k){
	for (int i = m; i >= k; i--){
			a[k] = i;
			if (k > 1){
				comb(i-1,k-1);
			}
			else{
				for (int j = a[0];j >= 1;j--){
					cout << a[j] << " ";
				}
				cout << endl;
			}
	}	
}
int main(){
	loop:
	int m,k;
	cout << "please input m and k:";
	cin >> m >> k;
	a[0] = k;
	comb (m,k);
	cout << endl;
	goto loop;
	return 0;
}
