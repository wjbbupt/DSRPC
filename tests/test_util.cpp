//
// Created by wjb on 2022/11/2.
//
#include "dsrpc/dsrpc.h"
#include <vector>
#include <iostream>
void test( int n){
    //constexpr int c=0;
    ACID_ASSERT2(0,"Not zero");
    //ACID_STATIC_ASSERT(c);
    //dsrpc::Assert(0,"Void test(int)");
}
void test_defer() {
    Defer_ {
        LOG_DEBUG << "no log";
    };
    Defer {
          LOG_DEBUG << "defer c";
          LOG_DEBUG << "defer d";
    };
    defer []{
        LOG_DEBUG << "defer a";
    };
    defer []{
        LOG_DEBUG << "defer b";
    };
}
int main(){
    test_defer();
}