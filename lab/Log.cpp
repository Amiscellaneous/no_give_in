#include "stdafx.h"
#include "Log.h"
/*函数名称：vex_insert
*输入参数： 图G,结点的位置信息v,结点的数据value
*返回值： 成功则返回OK，失败返回ERROR
*函数功能：插入指定位置结点
*/
status Graph::vex_insert(Graph &G, int v, ElemType value)
{
	if (!G.vertices)
		return ERROR;
	if (v < 1 || v>G.vexnum + 1)
		return	ERROR;
	if (G.vexnum > INIT_GRAPH_SIZE)//若事件数目过多，扩容
		G.vertices = (VList)realloc(G.vertices,G.vexnum+INIT_GRAPH_SIZE);
	for (int i = G.vexnum - 1; i > v; --i)//移动顶点数组后的元素
		G.vertices[i + 1] = G.vertices[i];
	//赋值
	G.vertices[v - 1].data = value;
	G.vertices[v - 1].firstarc = NULL;
	++G.vexnum;
	return OK;
}
status Graph::vex_delete(Graph &G, int v)
{
	if (!G.vertices)//图尚未建立
		return ERROR;
	if (v<0 || v>G.vexnum)//输入不合理
		return ERROR;
	//删除操作
	free(G.vertices[v].firstarc);
	G.vertices[v].firstarc = NULL;
	for (int i = v; i < G.vexnum - 1; i++)//移动此事件后续存储事件
		G.vertices[i] = G.vertices[i + 1];

	//在关系中删除此事件
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode *p = NULL, *prior = NULL;
		p = G.vertices[i].firstarc;
		while (p&&p->adjvex != v)
		{
			if (p->adjvex > v)//更新关联结点位置
				p->adjvex--;
			prior = p;
			p = p->nextarc;
		}
		if (prior&&p)//查找到，改变指向
			prior->nextarc = p->nextarc;
		else if (p)
			G.vertices[i].firstarc = p->nextarc;
		free(p);
		
		//改变剩余弧指向
		p = prior->nextarc;
		while (p)
		{
			if (p->adjvex > v)
				p->adjvex--;
			p = p->nextarc;
		}
	}
	G.arcnum--;
	return OK;
}
status Graph::vex_search(Graph G, string condition)
{
	return OK;
}
/*函数名称：arc_updata
*输入参数： 图G,结点的位置信息v,结点的数据value
*返回值： 成功则返回OK，失败返回ERROR
*函数功能：更新结点间边
*/
status arc_update(MultiGraph & M, int v, int w, InfoType info)
{
	return status();
}
/**
*函数名称：arc_insert
*输入参数： 图G,结点1的位置信息v,结点2的位置信息w,权值数据info
*返回值： 成功则返回OK，失败返回ERROR
*函数功能：在指定结点之间插入弧
*/
status arc_insert(MultiGraph & M, int v, int w, InfoType info)
{
	return status();
}
