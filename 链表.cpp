#include <iostream>
using namespace std;
typedef struct NODE{
	int date;              //һ������ 
	struct	NODE * next; 			//һ��ָ����һ������ָ�� ���е�struct���п��� 
}List; 								//List Ϊ�ṹ��NODE�ı��� 
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

