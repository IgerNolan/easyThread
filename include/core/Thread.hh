#ifndef INCLUDE_CORE_THREAD_HH
#define INCLUDE_CORE_THREAD_HH

#pragma region include::standard
#include <functional>
#pragma endregion include::standard

namespace easyThread {

// 线程类型
class Thread {
    public:
        // 线程函数对象类型
        using ThreadFunc = std::function<void(int)>;

        // 线程构造
        Thread(ThreadFunc func);

        // 线程析构
        ~Thread() = default;

        // 启动线程
        void start();

        // 获取线程id
        int getId() const;

    private:
        ThreadFunc func_;
        static int generateId_;
        int threadId_; // 保存线程id
};

} // namespace easyThread

#endif // INCLUDE_CORE_THREAD_HH
