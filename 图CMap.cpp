#include "CMap.h"
//#include "Edge.h"
//#include "Node.h"
#include <vector>

CMap::CMap(int capacity)
{
	m_pEdge = new Edge[m_iCapacity];
	
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	//memset(m_pMatrix,0,m_iCapacity * m_iCapacity *sizeof(int));
	for (int i = 0;i < m_iCapacity * m_iCapacity;i++)
	{
		m_pMatrix[i] = 0;
	}
	
	
}

CMap::~CMap()
{
	delete [] m_pNodeArray;
	delete [] m_pMatrix;
}

bool CMap::addNode(Node *pNode)
{
	if (pNode == NULL)
	{
		return false;
	}
	 m_pNodeArray[m_iNodeCount].m_cDate = pNode -> m_cDate;
	 m_iNodeCount++;
	 return true;
}

void CMap::resetNode()
{
	for(int i = 0;i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDitectionGraph(int row,int col,int val) 
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUnditectionGraph(int row,int col,int val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
		m_pMatrix[row * m_iCapacity + col] = val;
		m_pMatrix[col * m_iCapacity + row] = val;
		return true;
}

bool CMap::getValueFromMatrix(int row,int col,int &val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::printMatrix()
{
	for(int i = 0;i < m_iCapacity;i++)
	{
		for (int j = 0;j < m_iCapacity;j++)
		{
			cout << m_pMatrix[i * m_iCapacity + j] << "   ";	
		}
		cout << endl;
	}	 
}

void CMap::depthFirstTraverse(int nodeIndex)
{
	int value;
	cout << m_pNodeArray[nodeIndex].m_cDate << "   ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	for(int i = 0;i < m_iCapacity;i++)
	{
		getValueFromMatrix(nodeIndex,i,value);
		if (value == 1)
		{
			if(m_pNodeArray[i].m_bIsVisited == true)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);	
			}
		}
		else
		{
			continue;	
		}
	}	
} 

void CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cDate << "   ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	vector<int> curVec;
	curVec.push_back(nodeIndex);
	breadthFirstTraverseImpl(curVec);
	
} 

void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	int value = 0;
	vector<int> curVec;
	for (int j = 0;j < (int)preVec.size();j++)
	{
		for (int i = 0;i < m_iCapacity;i++)
		{
			getValueFromMatrix(preVec[j],i,value);
			if(value != 0)
			{
				if(m_pNodeArray[i] . m_bIsVisited == true)
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[i] . m_cDate << "   ";
					m_pNodeArray[i] . m_bIsVisited = true;
					curVec.push_back(i);
				}
					
			}
			else
			{
				continue;
			}
		}
	}
	if(curVec.size() == 0)
	{
		return;
	}
	else
	{
		breadthFirstTraverseImpl(curVec);
	}
}


void CMap::primTree(int nodeIndex)
{
	int value = 0;
	int edgeCount = 0;
	vector<int> nodeVec;
	vector<Edge> edgeVec;
	
	cout << m_pNodeArray[nodeIndex].m_cDate << endl;
	
	nodeVec.push_back(nodeIndex);
	
	cout << "nodeVec集合：" ; 
	for (int i = 0;i < nodeVec.size();i++)
	{
		cout << nodeVec[i] << "   " ;
	}
	cout << endl << endl;
	
	
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	while(edgeCount < m_iCapacity - 1)
	{
		
	
		int temp = nodeVec.back();
		
		for(int i = 0;i < m_iCapacity;i++)
		{
			getValueFromMatrix(temp,i,value);
			if (value == 0)
			{
				continue;
			}
			if(!m_pNodeArray[i].m_bIsVisited)
			{
				cout << "value:  " << value << endl;
			}
			
			if(value != 0)
			{
				if(m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}  
				else
				{
					Edge edge(temp,i,value);
					edgeVec.push_back(edge);       //下一次while循环把下一个结点的新边添加进来，这次
					                              //循环没有做清空处理 
				}	
			}
		} 
		
		//从可选边集合中找最小边
		int edgeIndex = getMinEdge(edgeVec); 
		edgeVec[edgeIndex].m_bSelected = true;
		
		cout << edgeVec[edgeIndex].m_iNodeIndexA << "---->" << edgeVec[edgeIndex].m_iNodeIndexB << "  ";
		cout << " 权值" << edgeVec[edgeIndex].m_iWeightValue << endl; 
		
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		
		if(!m_pNodeArray[nextNodeIndex].m_bIsVisited)
		{
		    m_pEdge[edgeCount] = edgeVec[edgeIndex];
		    edgeCount++;			
		}
		
		cout << "m_pEdge: ";
		for (int i = 0;i < edgeCount; i++)
		{
			cout << m_pEdge[i].m_iNodeIndexA << "--->" << m_pEdge[i].m_iNodeIndexB << "       ";
		}
		cout << endl;	
		
		if (!m_pNodeArray[nextNodeIndex].m_bIsVisited)
		{
			nodeVec.push_back(nextNodeIndex);
		}
		
		
		cout << "nodeVec集合：" ;
		for (int i = 0;i < nodeVec.size();i++)
		{
			cout << nodeVec[i] << "   " ;
		}
		cout << endl << endl;
	
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << m_pNodeArray[nextNodeIndex].m_cDate << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec)
{	
	int minWeight = 0;
	int edgeIndex = 0;
	int i = 0;
	
	for(;i < edgeVec.size();i++)
	{
		if(!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}
	
	if (minWeight == 0)
	{
		return -1;
	}
	
	for(;i < edgeVec.size();i++)
	{
		if(edgeVec[i].m_bSelected == true)
		{
			continue;
		}
		if(minWeight > edgeVec[i].m_iWeightValue)
		{
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
		}	
	}
	
	return 	edgeIndex;
}
























