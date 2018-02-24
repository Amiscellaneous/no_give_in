#ifndef LOG_NODE_H
#define LOG_NODE_H
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>



using namespace std;
int str2mon(string str);
time_t string2time(char* str);
class log_node
{
public:
    //构造和析构函数
    log_node(const log_node&record);
    log_node();
   ~log_node();

public:
    //data
        string level;//事件级别
        time_t time;//时间(以秒数存储)
        string subject;//事件主体
        int PID;//事件主体（进程）ID
        string object;//事件客体
        string user;//用户
        string description;//描述
};


status load_graph(MultiGraph *M, char *filename);
status write_graph(MultiGraph *M, char *filename);

status arc_update(MultiGraph &M, int v, int w, InfoType info);//事件间关系更新
status arc_search(MultiGraph &M,string condition);//查找事件间关系



#endif // LOG_NODE_H
