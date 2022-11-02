# DSRPC
基于c++20实现分布式服务架构

# 技术背景
C++17/20新特性 、c++20 coroutine的无栈协程状态机解析 URI 和 HTTP 协议等、实现rpc
后期展望：完善rpc，向grpc、brpc靠拢
# 环境搭建
虚拟机ubuntu20.04 安装c++11 相关特性
```
sudo apt install software-properties-common
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt install gcc-11 g++-11
```
2.配置模块采用了yaml-cpp，按照以下方法安装yaml-cpp
```
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp
mkdir build
cd build
cmake -DYAML_BUILD_SHARED_LIBS=on ..
sudo make install
cd ../..
```
3.构建项目 / Build
```
git clone https://github.com/wjbbupt/DSRPC
cd acid
mkdir build
cd build
cmake ..
make
cd ../..
```


