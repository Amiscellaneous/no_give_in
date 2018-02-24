#include "log_list.h"

//构造与析构
log_list::log_list(){
    length=0;
    size=INIT_LOG_SIZE;
    record=new log_node[INIT_LOG_SIZE];
}
log_list::~log_list(){
    delete[](record);
    length=0;
    size=0;
}
inline int log_list::size(){
    return size;
}
inline int log_list::length(){
    return length;
}
/**
    *函数名称：log_check
    *输入参数：输入日志数据record
    *返回值：TRUE#pass,FALSE#fail
    *函数功能：检查输入数据是否符合要求
**/
bool log_list::log_check(const log_node record){
    if(record.PID==-1)
        return false;
    if(record.subject=="")
        return false;
    if(record.user=="")
        return false;
    if(record.level=="")
        return false;
    if(record.time==0)
        return false;
    return true;
}
/**
 * 函数名称：log_insert_time
*输入参数： 待插入事件record
*输出参数：静态查找表log_list
*函数功能：按时间顺序插入事件
*/
void log_list::log_insert_time(const log_node insert_record){
    //若内存空间不足，扩容
        if(length>=size)
        {
            record=(log_node *)realloc(record,size+INCREMENT_LOG_SIZE);
            size+=INCREMENT_LOG_SIZE;
        }
    //按时间先后顺序插入,由于时间大小为线性关系，采用二分查找插入
        int high=length-1;
        int low=0;
        int mid;
        int pos=-1;
        while(high>=low){
            mid=(high+low)/2;
            if(record[mid].time==insert_record.time)
            {
                pos=mid;
                break;
            }
            else if(record[mid].time<insert_record.time)
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

        //移动顶点数组后的元素
        for (int i = length-1; i >=pos; --i)
            record[i + 1] = record[i];
        //赋值
        record[pos]=insert_record;
        ++length;
}

/**
    *函数名称：log_insert_sub
    *输入参数：日志节点
    *返回值：null
    *函数功能：按进程pid哈希后插入哈希表,此处用线性再散列法处理冲突,同id则插入邻接表
**/

void log_list::log_insert_sub(const log_node record){
    //若内存空间不足，扩容
      if(length>=size)
        {
            record=(log_node *)realloc(record,size+INCREMENT_LOG_SIZE);
            size+=INCREMENT_LOG_SIZE;
        }


}


/**
 * 函数名称：log_delete
*输入参数：
*输出参数：事件集log_list
*函数功能：
*/
void log_list::log_delete(int pos)
{
    if (pos>=log_list.length)//位置不合理
        return ERROR;
    //删除边操作
    free(G.vertices[v].firstarc);
    G.vertices[v].firstarc = NULL;

    //移动此事件后续存储事件
    for (int i = pos; i <length- 1; i++)
        record[i] =record[i + 1];

    length--;

    return OK;
}

/**
    *函数名称：search_sub
    *输入参数：sub_condition
    *返回值：true/false
    *函数功能：根据主体查找
**/
bool log_list::search_sub(string sub_condition){

}
