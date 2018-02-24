#ifndef GRAPH_H
#define GRAPH_H
#include"log_list.h"
struct ArcInfo {
    LinkType link;//边的关系
    InfoType type;//有向/无向
};
struct ArcNode {
    ArcInfo info;
    int adjvex;//该弧所指向的顶点
    struct ArcNode *nextarc;//下一邻接事件
};
class graph
{
public:
    log_list record_list;


public:
    graph();

};

#endif // GRAPH_H


typedef struct VNode
{
    int loc;//事件序号
    ElemType data;//事件信息
    ArcNode *firstarc;//首个邻接事件
}*VList;
class Graph
{
public:
    Graph();
    ~Graph();
    status vex_insert(Graph &G, int v, ElemType value);//插入事件
    status vex_delete(Graph &G, int v); //删除事件
    status vex_search(Graph G, string condition);//查找事件
private:
    VList vertices;
    int vexnum, arcnum;
};

Graph::Graph()
{
    this->vertices = new VNode[INIT_GRAPH_SIZE];
}

Graph::~Graph()
{
    delete this->vertices;
    this->vexnum = 0;
}
class MultiGraph
{
public:
    MultiGraph();
    ~MultiGraph();
    status insert_graph(MultiGraph &M,Graph G);

private:
    int length;//存储图数目
    Graph *base;//首个图指针
    LinkType type;//记录当前图所存关系类型
};

MultiGraph::MultiGraph()
{
    this->base = new Graph[MAX_GRAPH_NUM];
    this->length = 0;
    this->type = "";
}

MultiGraph::~MultiGraph()
{
    delete this->base;
    this->type = "";
    this->length = 0;
}
