#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAX_GRAPH_NUM 20
#define INIT_GRAPH_SIZE 100
#define INCREMENT_GRAPH_SIZE 100
using namespace std;

typedef bool status;
typedef bool InfoType;
typedef string LinkType;
typedef struct data {
	int eventID;//事件ID
	int level;//事件级别
	string time;//日期时间
	string source;//来源
	int category;//类别
	string user;//用户
	string subject;//事件主体
	string object;//事件客体
	string keywords;//关键字
}ElemType;

struct ArcInfo {
	LinkType link;//边的关系
	InfoType type;//有向/无向
};
struct ArcNode {
	ArcInfo info;
	int adjvex;//该弧所指向的顶点
	struct ArcNode *nextarc;//下一邻接事件
};
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
status load_graph(MultiGraph *M, char *filename);
status write_graph(MultiGraph *M, char *filename);

status arc_update(MultiGraph &M, int v, int w, InfoType info);//事件间关系更新
status arc_search(MultiGraph &M,string condition);//查找事件间关系


