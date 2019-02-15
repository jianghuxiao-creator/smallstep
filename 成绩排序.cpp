#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int minci[20];
	int score[20];
	string name[20]; 
	int scoretemp;          //等下验证char  
	string  nametemp; 
	for (int i = 0;i < 5;i++){
		minci[i] = i + 1;
	}
	cout << " 请输入姓名和对应的成绩：" << endl;
	for (int i = 0;i < 5;i++){
		cin >>  name[i] >> score[i];
	}
	cout << " 排序前：" << endl;
	cout << setw(9) << " 名次" << setw(9) << " 姓名" << setw(9) << " 分数" << endl;
	for (int i = 0;i < 5;i++){
		cout << setw(8) <<  minci[i] << setw(9) <<   name[i]  << setw(9) <<  score[i] <<endl;
	}
	for (int i = 0;i < 5;i++){                //实现以分数排序 
		for (int j = i + 1;j < 5;j++){
			if (score[i] > score[j]){         //分数和名字都交换 
				scoretemp = score[i];
				score[i] = score[j];
				score[j] = scoretemp;				
				 nametemp =  name[i];
				 name[i]  =  name[j];
				 name[j]  =  nametemp;			
			}			
		}
	}
	cout << " 排序后：" << endl;
	cout << setw(9) << " 名次" << setw(9) << " 姓名" << setw(9) << " 分数" << endl;
	for (int i = 0;i < 5;i++){
		cout << setw(8) <<  minci[i] << setw(9) <<   name[i]  << setw(9) <<  score[i] <<endl;
	}
} 
