#include <iostream>
using namespace std;
class Tree{
	public:
		Tree(int size,int *pRoot);                                        //创建树 
		~Tree();                                               //销毁树 
		int *SearchNode(int nodeIndex);                        //根据索引寻找结点 
		bool AddNode(int nodeIndex,int direction,int *pNode);  //添加结点 
		bool DeletNode(int nodeIndex,int *pNode);              //删除结点 
		void TreeTraverse();                                   //遍历二叉树 
		
	private:
		int *m_pTree;
		int m_iSize;	
};
