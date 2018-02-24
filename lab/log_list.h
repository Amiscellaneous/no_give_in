#ifndef NODE_MANAGE_H
#define NODE_MANAGE_H
#include"log_node.h"
#include<vector>
#include<time.h>
#include<math.h>
#define INIT_LOG_SIZE 256
#define INCREMENT_LOG_SIZE 256

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0


int bina_search(int low,int high,int *array);
class log_list
{
public:
    log_list();
    ~log_list();
    inline int size();
    inline int length();
    bool log_check(const log_node record);
    void log_insert_time(const log_node record);
    void log_delete(int pos);
    void log_load(string filename);
    void log_write(string filename);
    void combine_search(bool *flags);
public:
    log_node *record;
private:
    int length;
    int size;
};


#endif // NODE_MANAGE_H
