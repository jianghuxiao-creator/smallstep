//克鲁斯卡尔算法 
void CMap::kruskalTree()
{
	int value = 0;
	int edgeCount = 0;
	 
	//定义存放节点集合的数组
	vector<vector <int> > nodeSets;
	//第一步：取出所有的边
	vector<Edge> edgeVec;
	for(int i = 0;i < m_iCapacity;i++)
	{
		for (int k = 0; k < m_iCapacity;k++)
		{
			getValueFromMatrix(i,k,value);
			if(value != 0)
			{
				Edge edge(i,k,value);
				edgeVec.push_back(edge);
			}
			
		}
	}
	
	//第二步：从所有边中取出组成最小生成树的边
	//1.找到算法结束条件
	while(edgeCount < m_iCapacity - 1)
	{
		
	
	//2.从边集合中找到最小的边
	int minEdgeIndex = getMinEdge(edgeVec);
	edgeVec[minEdgeIndex].m_bSelected = true;
	
	//3.找到最小边连接的点
	int NodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
	int NodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;
	
	
	bool nodeAIsIndex = false;
	bool nodeBIsIndex = false;
	
	int nodeAInSetLabel = -1;
	int nodeBInSetLabel = -1;
	//4.找出点所在的点集合
	for(int i = 0;i < nodeSets.size();i++)
	{
		nodeAIsIndex = inSet(nodeSets[i],NodeAIndex);
		if(nodeAIsIndex)
		{
			nodeAInSetLabel = i;	
		}
	}
	
	for(int i = 0;i < nodeSets.size();i++)
	{
		nodeBIsIndex = inSet(nodeSets[i],NodeBIndex);
		if(nodeBIsIndex)
		{
			nodeBInSetLabel = i;	
		}
	}
	//5.根据点所在的集合的不同做出不同处理 
	if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
	{
		vector <int> vec;
		vec.push_back(NodeAIndex);
		vec.push_back(NodeBIndex);
		nodeSets.push_back(vec);
	}
	else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
	{
		 nodeSets[nodeBInSetLabel].push_back(NodeAIndex);
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
	{
		 nodeSets[nodeAInSetLabel].push_back(NodeBIndex);
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)
	{
		mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
		for(int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1;k++)
		{
			nodeSets[k] = nodeSets[k + 1]; 
		}
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel) 
	{
		continue;
	}
	
	m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
	edgeCount ++;
	
	cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "---->" << edgeVec[minEdgeIndex].m_iNodeIndexB <<"   ";
	cout << edgeVec[minEdgeIndex].m_iWeightValue << endl; 
	}
	
	nodeSets.clear(); 
}

bool CMap::inSet(vector <int> nodeSet, int target)
{
	for (int i = 0; i < nodeSet.size();i++)
	{
		if (nodeSet[i] == target)
		{
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA,vector<int> nodeSetB)
{
	for (int i = 0;i < nodeSetB.size() ;i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}	
}



