#include <iostream>
using namespace std;
class Tree{
	public:
		Tree(int size,int *pRoot);                                        //������ 
		~Tree();                                               //������ 
		int *SearchNode(int nodeIndex);                        //��������Ѱ�ҽ�� 
		bool AddNode(int nodeIndex,int direction,int *pNode);  //��ӽ�� 
		bool DeletNode(int nodeIndex,int *pNode);              //ɾ����� 
		void TreeTraverse();                                   //���������� 
		
	private:
		int *m_pTree;
		int m_iSize;	
};
