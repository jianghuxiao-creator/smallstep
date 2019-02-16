#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std; 
int main(){
	struct Leader {
		int no;
		char name[15];
		int piaoshu;
	};
	Leader  leader1 = {1 ,"li",0};		 
	Leader  leader2 = {2 ,"zhang",0};
	Leader  leader3 = {3 ,"wu",0};
	Leader  leader4 = {4 ,"ji",0};
	Leader  leader5 = {5 ,"zhou",0};
	Leader  leader6 = {6 ,"ruo",0};
	srand(time(0));//给一个随机种子
	Leader a[6] = {leader1,leader2,leader3,leader4,leader5,leader6};
	int s;
	Leader temp;
	for (int i = 0;i < 1000; i++){
		s = rand() % 6;
		a[s].piaoshu++;
	}
	cout << " 排序前：" << endl;
	cout << setw(10) << " 名次" <<setw(10) << " 编号" << setw(15) << " 名字" << setw(10) << " 票数" << endl; 
	for (int i = 0;i < 6;i++){
		cout << setw(10) << i+1 << setw(10) << a[i].no << setw(15) << a[i].name << setw(10) << a[i].piaoshu << endl;
	} 
	for (int i = 0;i < 5;i++ ){    //实现由大到小排序 
		for (int j = i + 1;j < 6;j++){
			if (a[i].piaoshu < a[j].piaoshu){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << " 排序后：" << endl << endl << endl;
	cout << setw(10) << " 名次" << setw(10) << " 编号" << setw(15) << " 名字" << setw(10) << " 票数" << endl; 
	for (int i = 0;i < 6;i++){
		cout << setw(10) << i+1  << setw(10) << a[i].no << setw(15) << a[i].name << setw(10) << a[i].piaoshu << endl;
	} 
	cout << endl;
	cout << " 票数最高为："  << endl; 
	cout << setw(10) << a[0].no << setw(15) << a[0].name << setw(10) << a[0].piaoshu << endl;
}
