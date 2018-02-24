#include "hash_list.h"

//得到size内最大素数
int max_prime(int size){
    bool tag=false;
    int max=0;
    for(int i=1;i<size;i++){
        for(int j=2;j<=sqrt(i);j++)
        {
            if(!(i%j))
            {
                tag=true;
                break;
            }
        }
        if(tag==false) max=i;
        else
             tag=false;
    }
}
/**
    *函数名称：hash_construct
    *输入参数：
    *返回值：
    *函数功能：
**/
void hash_list::hash_construct(){
    log_node *record=record_list->record;
    p=max_prime(size);
    int pos=0;
    for(int i=0;i<record_list->length();i++){
        pos=record[i].PID%p;
        while(record_hash[pos].id!=-1)
           pos=(++pos)%size;
        record_hash[pos].pid=record->PID;//存储进程pid
        record_hash[pos].id=i;//存储数据域表位置
    }
}
/**
    *函数名称：hash_list
    *输入参数：
    *返回值：
    *函数功能：初始化构造
**/
hash_list::hash_list(){
    length=0;
    size=INIT_HASH_SIZE;
    record_hash=new hash_node[INIT_HASH_SIZE];
}
hash_list::~hash_list(){
    delete[](record_hash);
    length=0;
    size=0;
}
/**
    *函数名称：
    *输入参数：
    *返回值：
    *函数功能：通过对pid除留余数构造散列表,线性探测再散列解决冲突
**/
hash_list::log_into_hash(){
    if(record_list->length()>this->size)//若哈希表数目<日志数目，扩容
    {
        resize();
    }
    hash_construct();//建立哈希表
}
/**
    *函数名称：search_sub
    *输入参数：
    *返回值：
    *函数功能：通过哈希表查找主体相同事件，线性探测
**/
hash_list::search_sub(int pid,vector<log_node>&result){
    if(pid<0)//数据输入不合理
        return false;
    int pos=pid%p;

    if(record_hash[pos].pid!=pid)//查找失败
        return false;


    for(int i=pos;record_hash[i].pid==pid;i++){
        int id=record_hash[i].id;//对应数据域中位置
        result.push_back(record_list->record[id]);
    }

    return true;
}
/**
    *函数名称：search_sub
    *输入参数：
    *返回值：
    *函数功能：通过子串查找得到搜索结果
**/
hash_list::search_sub(string sub_condition, vector<log_node> &result)
{
    log_node *record=record_list->record;
    if(!record)
        return false;
    int i;
    for(i=0;i<record_list->length();i++){
        string str=record[i].subject;
        if(str.find(sub_condition)!=string::npos){
            int pid=record[i].PID;
            int pos=pid%p;

            //在哈希表中查找，将对应pid全部送入搜索结果
            while(record_hash[pos].pid==pid){
                int id=record_hash[pos].id;
                result.push_back(record[id]);
                pos=(++pos)%size;
            }
        }

    }
    if(i>=record_list->length())
        return false;
    else
        return true;
}

/**
    *函数名称：search_obj
    *输入参数：
    *返回值：true/false
    *函数功能：
**/
hash_list::search_obj(string obj_condition, vector<log_node> &result){
    log_node *record=record_list->record;
    if(!record)
        return false;
    int i;
    for(i=0;i<record_list->length();i++){
        string str=record[i].object;
        if(str.find(obj_condition)!=string::npos)
            result.push_back(record[i]);
    }
    if(i>=record_list->length())
        return false;
    else
        return true;
}
/**
    *函数名称：search_time
    *输入参数：
    *返回值：
    *函数功能：在时间事件表中查找,采用二分查找法查找起点
**/
bool hash_list::search_time(time_t time_begin, time_t time_end,vector<log_node> &result){

    if(time_begin>time_end)
        return   false;

    int high=record_list->length()-1;
    int low=0;
    int mid;
    int pos=-1;
    while(high>=low){
        mid=(high+low)/2;
        if(record[mid].time==time_begin)
        {
            pos=mid;
            break;
        }
        else if(record[mid].time>time_begin)
        {
            high=mid-1;
            pos=low;
        }
        else
        {
            low=mid+1;
            pos=high;
        }
    }
    if(pos==-1&&pos==record_list->length())
        return false;

    for(int i=pos;record[i].time<=time_end;i++){
        result.push_back(record[i]);
    }
    return true;
}
