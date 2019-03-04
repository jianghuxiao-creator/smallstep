class Edge
{
	public:
		Edge(int nodeIndexA = 0,int nodeIndexB = 0,int weightValue = 0); //要给一个初值0才行 我也是醉了 这个是个编译器的问题吧 
		int m_iNodeIndexA;
		int m_iNodeIndexB;
		int m_iWeightValue;
		bool m_bSelected;
};


