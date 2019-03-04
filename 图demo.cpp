#include <iostream>

/*
                A
              /    \
            B		D
          /   \    /  \
        C	  F   G    H
         \   /
           E
*/
/*
	A  B  C  D  E  F  G  H
A	   1     1
B	1     1        1
C	   1	    1
D	1                 1
E         1        1
F      1        1
G            1           1
H                     1

*/
#include "CMap.h"
int main()
{
	CMap *pMap = new CMap(6);
	
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
//	Node *pNodeG = new Node('G');
//	Node *pNodeH = new Node('H');
	
	pMap -> addNode(pNodeA);
	pMap -> addNode(pNodeB);
	pMap -> addNode(pNodeC);
	pMap -> addNode(pNodeD);
	pMap -> addNode(pNodeE);
	pMap -> addNode(pNodeF);
 
	
	
	pMap -> setValueToMatrixForUnditectionGraph(0,1,2);
	pMap -> setValueToMatrixForUnditectionGraph(0,4,8);
	pMap -> setValueToMatrixForUnditectionGraph(0,5,1);
	pMap -> setValueToMatrixForUnditectionGraph(1,2,6);
	pMap -> setValueToMatrixForUnditectionGraph(1,5,5);	
	pMap -> setValueToMatrixForUnditectionGraph(2,5,11);
	pMap -> setValueToMatrixForUnditectionGraph(2,3,10);
	pMap -> setValueToMatrixForUnditectionGraph(3,5,7);
	pMap -> setValueToMatrixForUnditectionGraph(3,4,5);
	pMap -> setValueToMatrixForUnditectionGraph(4,5,12);
	
	pMap -> printMatrix();	
	cout << endl;
//	
//	pMap -> depthFirstTraverse(0);	
//	cout << endl;
//	
//	pMap ->  resetNode();
//	
//	pMap -> breadthFirstTraverse(0);
//	
	
//	Edge edge(1,2,3);
//	edge.print();
	
	pMap -> primTree(0);
	return 0;
}

