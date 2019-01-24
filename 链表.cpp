#include <iostream>
using namespace std;
typedef struct NODE{
	int date;              //一个数据 
	struct	NODE * next; 			//一个指向下一个结点的指针 这行的struct可有可无 
}List; 								//List 为结构体NODE的别名 
List * head;
List * Create(){
	List * p = NULL;
	List * q = NULL;
	head = NULL;
	int x;
	cin>>x;
	while (x != 0){
		p = new List;
		p -> date = x;
		if(head == NULL){
			head = p;
		}
		else {
		q -> next = p;	
		}		
		q = p;
		cin >> x;
	} //end while
	if (head != NULL){
		q -> next = NULL;
	}
	return (head);
} //end Create()

void displayList (List *head){
	while (head != NULL){
		cout << head -> date <<" ";
		
		cout << head -> next <<" "; 
		head = head -> next;
	}
}

int main(){
	displayList(Create());
	cout << endl;
	return 0;
}

