#include "log_node.h"
#include "log_node.h"

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

log_node::log_node(){
    this->level="";
    this->time=0;
    this->PID=-1;
    this->object="";
    this->subject="";
    this->user="";
    this->description="";
}

log_node::log_node(string level,string time,string user,
                    string subject,int PID,string object,string description){
    this->level=level;
    this->time=string2time(time);
    this->subject=subject;
    this->PID=PID;
    this->object=object;
    this->user=user;
    this->description=description;
}

log_node::~log_node(){
    delete this->level;
    delete this->subject;
    delete this->object;
    delete this->description;
    delete this->user;
    this->PID=0;
    this->time=0;
}


int str2mon(string str){
    if(str=="Jan")  return 1;
    else if(str=="Feb") return 2;
    else if(str=="Mar") return 3;
    else if(str=="Apr") return 4;
    else if(str=="May") return 5;
    else if(str=="Jun") return 6;
    else if(str=="Jul") return 7;
    else if(str=="Aug") return 8;
    else if(str=="Sep") return 9;
    else if(str=="Oct") return 10;
    else if (str=="Nov")    return 11;
    else return 12;
}
time_t string2time(char* str){

    tm tm1;
    time_t t1;
    int mday,hour,min,sec;
    char mon[5]={0};

    if(-1==sscanf(str,"%3s %d %d:%d:%d",mon,&mday,&hour,&min,&sec))
        return -1;

    tm1.tm_year=2018-1900;
    tm1.tm_mon=str2mon(mon);
    tm1.tm_mday=mday;
    tm1.tm_min=min;
    tm1.tm_sec=sec;
    t1=mktime(&tm1);
    if(t1==-1)
    {
        fputs("convert error!\n",stderr);
        exit(1);
    }
    char buf[20]={0};
    strftime(buf,sizeof(buf),"%b %d %X",localtime(&t1));
    return t1;
}
