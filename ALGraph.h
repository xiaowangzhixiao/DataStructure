//邻接表（Adjacency List）存储图
#define   maxvtxnum     100
#define   edgetype		int
#define	  vextype		int

typedef struct  ArcNode  {
      int    adjvex;
      edgetype   info;
      struct   ArcNode  * nextarc;
} ArcNode;//弧节点

typedef struct  VexNode{
      vextype   vexdata;
      struct  ArcNode   * firstarc;
}VexNode;//头结点

typedef VexNode AdjList[maxvtxnum]; 

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;//当前顶点数，弧数
	int kind;	//图的种类标志
}ALGraph;	
