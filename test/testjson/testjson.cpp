#include "json.hpp"

using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing";

    string sendBuf = js.dump();
    cout << sendBuf.c_str() << endl;
 }

void func2(){
    json js;
    js["id"] = {1,2,3,4,5};
    js["name"] = "zhang san";
    
}

int main(){
    func1();
    return 0;
}