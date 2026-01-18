

#pragma region include
#pragma region include::header
#include "core/Thread.hh"
#pragma endregion include::header
#pragma region include::standard
#include <thread>
#pragma endregion include::standard
#pragma endregion include

namespace easyThread {

int Thread::generateId_ = 0;

// 线程构造
Thread::Thread(ThreadFunc func)
    : func_(func)
    , threadId_(generateId_++) {}

// 启动线程
void Thread::start() {
    // 创建一个线程来执行一个线程函数 pthread_create
    std::thread t(func_,
                  threadId_); // C++11来说 线程对象t  和线程函数func_
    t.detach(); // 设置分离线程   pthread_detach pthread_t设置成分离线程
}

// 获取线程id
int Thread::getId() const {
    return threadId_;
}

} // namespace easyThread

