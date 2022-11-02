//
// Created by zavier on 2021/10/11.
//

#include "dsrpc/log.h"
#include "dsrpc/util.h"
#include <iostream>
#include <memory>
using namespace std;
int main(){
    //source::Logger::ptr logger(std::make_shared<source::Logger>());
    auto logger = dsrpc::LogMgr::GetInstance()->getLogger("system");
    ACID_LOG_ERROR(logger)<<"system";
  //cout<<"hello";
}
