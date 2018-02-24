#include "stdafx.h"
#include "Log.h"
/*�������ƣ�vex_insert
*��������� ͼG,����λ����Ϣv,��������value
*����ֵ�� �ɹ��򷵻�OK��ʧ�ܷ���ERROR
*�������ܣ�����ָ��λ�ý��
*/
status Graph::vex_insert(Graph &G, int v, ElemType value)
{
	if (!G.vertices)
		return ERROR;
	if (v < 1 || v>G.vexnum + 1)
		return	ERROR;
	if (G.vexnum > INIT_GRAPH_SIZE)//���¼���Ŀ���࣬����
		G.vertices = (VList)realloc(G.vertices,G.vexnum+INIT_GRAPH_SIZE);
	for (int i = G.vexnum - 1; i > v; --i)//�ƶ�����������Ԫ��
		G.vertices[i + 1] = G.vertices[i];
	//��ֵ
	G.vertices[v - 1].data = value;
	G.vertices[v - 1].firstarc = NULL;
	++G.vexnum;
	return OK;
}
status Graph::vex_delete(Graph &G, int v)
{
	if (!G.vertices)//ͼ��δ����
		return ERROR;
	if (v<0 || v>G.vexnum)//���벻����
		return ERROR;
	//ɾ������
	free(G.vertices[v].firstarc);
	G.vertices[v].firstarc = NULL;
	for (int i = v; i < G.vexnum - 1; i++)//�ƶ����¼������洢�¼�
		G.vertices[i] = G.vertices[i + 1];

	//�ڹ�ϵ��ɾ�����¼�
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode *p = NULL, *prior = NULL;
		p = G.vertices[i].firstarc;
		while (p&&p->adjvex != v)
		{
			if (p->adjvex > v)//���¹������λ��
				p->adjvex--;
			prior = p;
			p = p->nextarc;
		}
		if (prior&&p)//���ҵ����ı�ָ��
			prior->nextarc = p->nextarc;
		else if (p)
			G.vertices[i].firstarc = p->nextarc;
		free(p);
		
		//�ı�ʣ�໡ָ��
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
/*�������ƣ�arc_updata
*��������� ͼG,����λ����Ϣv,��������value
*����ֵ�� �ɹ��򷵻�OK��ʧ�ܷ���ERROR
*�������ܣ����½����
*/
status arc_update(MultiGraph & M, int v, int w, InfoType info)
{
	return status();
}
/**
*�������ƣ�arc_insert
*��������� ͼG,���1��λ����Ϣv,���2��λ����Ϣw,Ȩֵ����info
*����ֵ�� �ɹ��򷵻�OK��ʧ�ܷ���ERROR
*�������ܣ���ָ�����֮����뻡
*/
status arc_insert(MultiGraph & M, int v, int w, InfoType info)
{
	return status();
}
