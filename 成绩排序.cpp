#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int minci[20];
	int score[20];
	string name[20]; 
	int scoretemp;          //������֤char  
	string  nametemp; 
	for (int i = 0;i < 5;i++){
		minci[i] = i + 1;
	}
	cout << " �����������Ͷ�Ӧ�ĳɼ���" << endl;
	for (int i = 0;i < 5;i++){
		cin >>  name[i] >> score[i];
	}
	cout << " ����ǰ��" << endl;
	cout << setw(9) << " ����" << setw(9) << " ����" << setw(9) << " ����" << endl;
	for (int i = 0;i < 5;i++){
		cout << setw(8) <<  minci[i] << setw(9) <<   name[i]  << setw(9) <<  score[i] <<endl;
	}
	for (int i = 0;i < 5;i++){                //ʵ���Է������� 
		for (int j = i + 1;j < 5;j++){
			if (score[i] > score[j]){         //���������ֶ����� 
				scoretemp = score[i];
				score[i] = score[j];
				score[j] = scoretemp;				
				 nametemp =  name[i];
				 name[i]  =  name[j];
				 name[j]  =  nametemp;			
			}			
		}
	}
	cout << " �����" << endl;
	cout << setw(9) << " ����" << setw(9) << " ����" << setw(9) << " ����" << endl;
	for (int i = 0;i < 5;i++){
		cout << setw(8) <<  minci[i] << setw(9) <<   name[i]  << setw(9) <<  score[i] <<endl;
	}
} 
