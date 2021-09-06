#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

//匹配User表的ORM类
class User{
public:
    User(int _id = -1, string _name = "", string _pwd = "", string _state = "offline")
        : id(_id), name(_name), password(_pwd), state(_state) {}

    void setId(int _id){this->id = _id;}
    void setName(string _name){this->name = _name;}
    void setPwd(string _pwd){this->password = _pwd;}
    void setState(string _state){this->state = _state;}

    int getId(){return this->id;}
    string getName(){return this->name;}
    string getPwd(){return this->password;}
    string getState(){return this->state;}

private:
    int id;
    string name;
    string password;
    string state;
};

#endif