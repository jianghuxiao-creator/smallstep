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
	srand(time(0));//��һ���������
	Leader a[6] = {leader1,leader2,leader3,leader4,leader5,leader6};
	int s;
	Leader temp;
	for (int i = 0;i < 1000; i++){
		s = rand() % 6;
		a[s].piaoshu++;
	}
	cout << " ����ǰ��" << endl;
	cout << setw(10) << " ����" <<setw(10) << " ���" << setw(15) << " ����" << setw(10) << " Ʊ��" << endl; 
	for (int i = 0;i < 6;i++){
		cout << setw(10) << i+1 << setw(10) << a[i].no << setw(15) << a[i].name << setw(10) << a[i].piaoshu << endl;
	} 
	for (int i = 0;i < 5;i++ ){    //ʵ���ɴ�С���� 
		for (int j = i + 1;j < 6;j++){
			if (a[i].piaoshu < a[j].piaoshu){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << " �����" << endl << endl << endl;
	cout << setw(10) << " ����" << setw(10) << " ���" << setw(15) << " ����" << setw(10) << " Ʊ��" << endl; 
	for (int i = 0;i < 6;i++){
		cout << setw(10) << i+1  << setw(10) << a[i].no << setw(15) << a[i].name << setw(10) << a[i].piaoshu << endl;
	} 
	cout << endl;
	cout << " Ʊ�����Ϊ��"  << endl; 
	cout << setw(10) << a[0].no << setw(15) << a[0].name << setw(10) << a[0].piaoshu << endl;
}
