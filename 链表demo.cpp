#include "Tree.h"
 /* 0 1 3 4 2 5 6     Ç°Ðò 
 	3 1 4 0 5 2 6		ÖÐÐò 
	3 4 1 5 6 2 0  	ºóÐò 
             £¨0£©
             
	  5£¨1£©		  8£¨2£©
		
2£¨3£©  6£¨4£©    9£¨5£©   7£¨6£©  
*/

int main(){
	Node *node1 = new Node();
	node1 -> index = 1;
	node1 -> date = 5;
	 
	Node *node2 = new Node();
	node2 -> index = 2;
	node2 -> date = 8;
	
	Node *node3 = new Node();
	node3 -> index = 3;
	node3 -> date = 2;
	
	Node *node4 = new Node();
	node4 -> index = 4;
	node4 -> date = 6;
	
	Node *node5 = new Node();
	node5 -> index = 5;
	node5 -> date = 9;
	
	Node *node6 = new Node();
	node6 -> index = 6;
	node6 -> date = 7;
	
	Tree *tree = new Tree();
	tree -> AddNode(0,0,node1);
	tree -> AddNode(0,1,node2);
	tree -> AddNode(1,0,node3);
	tree -> AddNode(1,1,node4);
	tree -> AddNode(2,0,node5);
	tree -> AddNode(2,1,node6);
	
	tree -> PreorderTraversal();
	cout << endl;
	
	tree -> DeleteNode(1,NULL);
	
	tree -> PreorderTraversal();
	cout << endl;
	
//	tree -> InorderTraversal();
//	cout << endl;
//	
//	tree -> PostorderTraversal();
//	cout << endl;
	
	
	
	
	
	
	
	
	
	
}
