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
	int eventID;//�¼�ID
	int level;//�¼�����
	string time;//����ʱ��
	string source;//��Դ
	int category;//���
	string user;//�û�
	string subject;//�¼�����
	string object;//�¼�����
	string keywords;//�ؼ���
}ElemType;

struct ArcInfo {
	LinkType link;//�ߵĹ�ϵ
	InfoType type;//����/����
};
struct ArcNode {
	ArcInfo info;
	int adjvex;//�û���ָ��Ķ���
	struct ArcNode *nextarc;//��һ�ڽ��¼�
};
typedef struct VNode
{
	int loc;//�¼����
	ElemType data;//�¼���Ϣ
	ArcNode *firstarc;//�׸��ڽ��¼�
}*VList;
class Graph
{
public:
	Graph();
	~Graph();
	status vex_insert(Graph &G, int v, ElemType value);//�����¼�
	status vex_delete(Graph &G, int v); //ɾ���¼�
	status vex_search(Graph G, string condition);//�����¼�
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
	int length;//�洢ͼ��Ŀ
	Graph *base;//�׸�ͼָ��
	LinkType type;//��¼��ǰͼ�����ϵ����
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

status arc_update(MultiGraph &M, int v, int w, InfoType info);//�¼����ϵ����
status arc_search(MultiGraph &M,string condition);//�����¼����ϵ


