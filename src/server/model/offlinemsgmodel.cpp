#include "offlinemsgmodel.hpp"
#include "db.h"
//#include <muduo/base/Logging.h>

//存储用户的离线消息
void offlineMsgModel::insert(int userid, string msg){
    //1.组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "insert into offlinemessage values(%d, '%s')", userid, msg.c_str());

    //2.连接数据库并插入
    MySQL mysql;
    if(mysql.connect()){
        mysql.update(sql);
    }
}

//删除用户的离线消息
void offlineMsgModel::remove(int userid){
    //1.组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "delete from offlinemessage where userid = %d", userid);

    //2.连接数据库并插入
    MySQL mysql;
    if(mysql.connect()){
        mysql.update(sql);
    }
}

//查询用户的离线消息
vector<string> offlineMsgModel::query(int userid){
    //1.组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "select message from offlinemessage where userid = %d", userid);

    //2.连接数据库并插入
    vector<string> vec;
    MySQL mysql;
    if(mysql.connect()){
        MYSQL_RES *res = mysql.query(sql);
        if(res != nullptr){
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr){
                //LOG_INFO << "msg: " << *row;
                vec.push_back(row[0]);
            }
            mysql_free_result(res);
            return vec;
        }     
    }
    return vec;
}