#include <iostream>
using namespace std;
float add(float a,float b);
float sub(float a,float b);
float mul(float a,float b);
float div(float a,float b);
int main(){
	cout << " 该小应用为实现两个数的四则运算小应用程序" << endl << endl;
	loop:
	char ch;
	float a;
	float b;
	float result;
	cout << "please input a and 运算方法 and b： ";
	cin >> a;
	cin >> ch;
	cin >> b;	
	switch(ch){
		case '+':  result = add(a,b); break;
		case '-':  result = sub(a,b); break;
		case '*':  result = mul(a,b); break;
		case '/':  result = div(a,b); break;
		default: cout << "Wrong inputing";
	}
	cout << "result is: " << result << endl << endl;
	goto loop;
	return 0;
}
float add(float a,float b){
	return a + b;
} 
float sub(float a,float b){
	return a - b;
} 
float mul(float a,float b){
	return a * b;
} 
float div(float a,float b){
	return a / b;
} 
