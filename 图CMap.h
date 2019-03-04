#include "Node.h"
#include "Edge.h"
#include <vector>
class CMap
{
 public:
 	CMap(int capacity);
 	~CMap();
 	bool addNode(Node *pNode);//��ͼ�м�����
	void resetNode(); 
	        //���ö���
	bool setValueToMatrixForDitectionGraph(int row,int col,int val = 1);//Ϊ����ͼ�����ڽӾ��� 
	bool setValueToMatrixForUnditectionGraph(int row,int col,int val = 1);//Ϊ����ͼ�����ڽӾ��� 		 		
	void printMatrix();//��ӡ�ڽӾ���
	
	void depthFirstTraverse(int nodeIndex); //������ȱ���		
	void breadthFirstTraverse(int nodeIndex);//������ȱ���
	
	void primTree(int nodeIndex);
	
	private: 
		bool getValueFromMatrix(int row,int col,int &val);    //�Ӿ����л�ȡֵ
		void breadthFirstTraverseImpl(vector<int> preVec);//�����ȱ���ʵ�� 
	 	int getMinEdge(vector<Edge> edgeVec);
	 	
	private:
		int m_iCapacity;   //ͼ����ඥ����
		int m_iNodeCount;  // �Ѿ���ӵĶ�����
		Node *m_pNodeArray;//������Ŷ�������
		int *m_pMatrix;    //��������ڽӾ��� 
		
		Edge *m_pEdge;
	 
}; 

