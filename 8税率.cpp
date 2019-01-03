#include <iostream>
using namespace std;
int main(){
	loop:
	int award;
	cout << "please input award: ";
	cin >> award;
	int rat;
	rat = award / 1000;
	if (rat > 10){
		rat = 10;
	}
	float award2;
	float rate ;
	switch (rat){
		case 0: rate = 0.0; award2 = award; break;
		case 1: rate = 0.03; award2 = award - (award - 1000) * rate; break;
		case 2: rate = 0.05; award2 = award - (award - 2000) * rate - 1000 * 0.03; break;
		case 3: rate = 0.07; award2 = award - (award - 3000) * rate - 1000 * (0.05 + 0.03);break;
		case 4: rate = 0.09; award2 = award - (award - 4000) * rate - 1000 * (0.07 + 0.05 + 0.03);break;
		case 5: rate = 0.12; award2 = award - (award - 5000) * rate - 1000 * (0.09 + 0.07 + 0.05 + 0.03);break;
		case 6: rate = 0.16; award2 = award - (award - 6000) * rate - 1000 * (0.12 + 0.09 + 0.07 + 0.05 + 0.03);break;
		case 7: rate = 0.18; award2 = award - (award - 7000) * rate - 1000 * (0.16 + 0.12 + 0.09 + 0.07 + 0.05 + 0.03);break;
		case 8: rate = 0.20; award2 = award - (award - 8000) * rate - 1000 * (0.18 + 0.16+0.12 + 0.09 + 0.07 + 0.05 + 0.03);break;
		case 9: rate = 0.22; award2 = award - (award - 9000) * rate - 1000 * (0.20 + 0.18 + 0.16+0.12 + 0.09 + 0.07 + 0.05 + 0.03);break;
		case 10: rate = 0.25; award2 = award - (award - 10000) * rate - 1000 * (0.22 + 0.20 + 0.18 + 0.16+0.12 + 0.09 + 0.07 + 0.05 + 0.03);break;
		
	} 
	cout << " 最高税率达：" << rate << endl;
	
	cout << " 税后金额：" << award2 << endl;
	goto loop;
	return 0;
}
