//
// Created by wjb on 2022/11/2.
//
#include <execinfo.h>
#include "dsrpc/fiber.h"
#include "dsrpc/log.h"
#include "dsrpc/util.h"
namespace dsrpc{
static Logger::ptr g_logger = ACID_LOG_NAME("system");

pid_t GetThreadId(){
    return syscall(SYS_gettid);
}

int64_t GetFiberId(){
    return Fiber::GetFiberId();
}

void Backtrace(std::vector<std::string>& bt, int size, int skip) {
    void** array = (void**)malloc((sizeof(void*) * size));
    size_t s = backtrace(array, size);

    char** strings = backtrace_symbols(array, s);
    if(strings == NULL) {
        ACID_LOG_ERROR(g_logger) << "backtrace_synbols error";
        free(array);
        return;
    }

    for(size_t i = skip; i < s; ++i) {
        bt.push_back(strings[i]);
    }

    free(strings);
    free(array);
}

std::string BacktraceToString(int size, int skip, const std::string& prefix) {
    std::vector<std::string> bt;
    Backtrace(bt, size, skip);
    std::stringstream ss;
    for(size_t i = 0; i < bt.size(); ++i) {
        ss << prefix << bt[i] << std::endl;
    }
    return ss.str();
}

uint64_t GetCurrentMS(){
    struct timeval tm;
    gettimeofday(&tm,0);
    return tm.tv_sec * 1000ul + tm.tv_usec / 1000;
}

uint64_t GetCurrentUS(){
    struct timeval tm;
    gettimeofday(&tm,0);
    return tm.tv_sec * 1000ul * 1000ul + tm.tv_usec;
}

}