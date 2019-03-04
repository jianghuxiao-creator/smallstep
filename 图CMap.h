#include "Node.h"
#include "Edge.h"
#include <vector>
class CMap
{
 public:
 	CMap(int capacity);
 	~CMap();
 	bool addNode(Node *pNode);//向图中加入结点
	void resetNode(); 
	        //重置顶点
	bool setValueToMatrixForDitectionGraph(int row,int col,int val = 1);//为有向图设置邻接矩阵 
	bool setValueToMatrixForUnditectionGraph(int row,int col,int val = 1);//为无向图设置邻接矩阵 		 		
	void printMatrix();//打印邻接矩阵
	
	void depthFirstTraverse(int nodeIndex); //深度优先遍历		
	void breadthFirstTraverse(int nodeIndex);//广度优先遍历
	
	void primTree(int nodeIndex);
	
	private: 
		bool getValueFromMatrix(int row,int col,int &val);    //从矩阵中获取值
		void breadthFirstTraverseImpl(vector<int> preVec);//度优先遍历实现 
	 	int getMinEdge(vector<Edge> edgeVec);
	 	
	private:
		int m_iCapacity;   //图中最多顶点数
		int m_iNodeCount;  // 已经添加的顶点数
		Node *m_pNodeArray;//用来存放顶点数组
		int *m_pMatrix;    //用来存放邻接矩阵 
		
		Edge *m_pEdge;
	 
}; 

