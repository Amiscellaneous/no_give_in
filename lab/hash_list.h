#ifndef HASH_LIST_H
#define HASH_LIST_H
#include<vector>
#include"log_node.h"
#include"hash_node.h"
#include"log_list.h"
#define INIT_HASH_SIZE 256
#define INCREMENT_HASH_SIZE 256

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
int max_prime(int size);
class hash_list
{
public:
    hash_list();
    ~hash_list();
    inline void resize();
    void hash_construct();
    void log_into_hash();
    bool search_sub(string sub_condition,vector<log_node>&result);
    bool search_sub(int pid,vector<log_node>&result);
    bool search_obj(string obj_condition,vector<log_node>&result);
    bool search_time(time_t time_begin, time_t time_end,vector<log_node> &result);
private:
    int length;
    int p;
    int size;
    hash_node *record_hash;//首地址
    log_list *record_list;//数据域
};
inline void hash_list::resize(){
    size+=INCREMENT_HASH_SIZE;
    record_hash=realloc(record_hash,size*sizeof(hash_node));
}
#endif // HASH_LIST_H
