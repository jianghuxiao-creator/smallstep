/*
 通过递归解决汉诺塔问题 有A B C 三个柱子，将柱子A上的盘子经B移动到C,每次只能移动一个盘子。 
 对一般情况，我们将 n-1 个盘子通过C移动到B，在将第n个盘子移动到C，在将B上n-1个盘子移动到C；
 这样就将N的问题变成了n-1的问题，重复这个过程，每次N减1。最后当N=1时，直接移动即可。 
 move (n ,A,B,C):A源柱，B工作柱，C目标柱
 可分解为：
 move (n-1,A,C,B);
 A -> C; 
 move (n-1,B,A,C);
*/
#include <iostream>
using namespace std;
int sum = 0; //共需步数 
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
	cout << " please input 盘子个数 n:";
	cin >> total;
	move (total,'A','B','C');
	cout << " 共需" << sum << " 步" << endl;
	sum = 0;
	cout << endl;
	goto loop;	
	return 0;	
}
