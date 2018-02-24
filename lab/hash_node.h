#ifndef HASH_NODE_H
#define HASH_NODE_H

struct arcinfo
{
    int adjex;
    arcinfo *next;
};
class hash_node
{
    int pid;//关键字pid
    int id;//原表中位置
    int *flags;//遍历标记+删除标记
    arcinfo *first_sub;//主体首邻接边
    arcinfo *first_obj;//客体首邻接边
    arcinfo *first_cpn;//伴随首邻接边
    arcinfo *first_res;//因果首邻接边
public:
    hash_node();
    ~hash_node();
};
hash_node::hash_node(){
    id=-1;
    pid=-1;
    flags=new int[4];
    for(int i=0;i<4;i++)    flags[i]=0;
    first_cpn=NULL;
    first_obj=NULL;
    first_res=NULL;
    first_sub=NULL;
}
hash_node::~hash_node(){
    id=-1;
    pid=-1;
    delete [](flags);
    delete first_cpn;
    delete first_obj;
    delete first_res;
    delete first_sub;
}

#endif // HASH_NODE_H
