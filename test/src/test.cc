


#pragma region include
#pragma region include::standard

#include <chrono>
#include <thread>
#pragma endregion include::standard
#pragma region include::project
#include "core/ThreadPool.hh"
#pragma endregion include::project
#pragma endregion include

int sum1(int a, int b);
int sum2(int a, int b, int c);
// void io_thread(int listenfd);
// void worker_thread(int clientfd);

/*
如何能让线程池提交任务更加方便
1. threadPool.submitTask(sum1, 10, 20);
   threadPool.submitTask(sum2, 1 ,2, 3);
   submitTask:可变参模板编程

2. 我们自己造了一个Result以及相关的类型，代码挺多
    C++11 线程库   thread   packaged_task(function函数对象)  async
   使用future来代替Result节省线程池代码
*/

int sum1(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    // 比较耗时
    return a + b;
}

int sum2(int a, int b, int c) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b + c;
}

// io线程
// void io_thread(int listenfd) {}

// // worker线程
// void worker_thread(int clientfd) {}

int main() {
    easyThread::ThreadPool threadPool;
    // threadPool.setMode(easyThread::PoolMode::MODE_CACHED);
    threadPool.start(); // 自动使用 CPU 核心数

    std::future<int> r1 = threadPool.submitTask(sum1, 1, 2);
    std::future<int> r2 = threadPool.submitTask(sum2, 1, 2, 3);
    std::future<int> r3 = threadPool.submitTask(
        [](int b, int e) -> int {
            int sum = 0;
            for (int i = b; i <= e; i++) {
                sum += i;
            }
            return sum;
        },
        1, 100);
    std::future<int> r4 = threadPool.submitTask(
        [](int b, int e) -> int {
            int sum = 0;
            for (int i = b; i <= e; i++) {
                sum += i;
            }
            return sum;
        },
        1, 100);
    std::future<int> r5 = threadPool.submitTask(
        [](int b, int e) -> int {
            int sum = 0;
            for (int i = b; i <= e; i++) {
                sum += i;
            }
            return sum;
        },
        1, 100);
    // std::future<int> r4 = threadPool.submitTask(sum1, 1, 2);

    std::cout << r1.get() << std::endl;
    std::cout << r2.get() << std::endl;
    std::cout << r3.get() << std::endl;
    std::cout << r4.get() << std::endl;
    std::cout << r5.get() << std::endl;

    // packaged_task<int(int, int)> task(sum1);
    //// future <=> Result
    // future<int> res = task.get_future();
    //// task(10, 20);
    // thread t(std::move(task), 10, 20);
    // t.detach();

    // cout << res.get() << endl;

    /*thread t1(sum1, 10, 20);
    thread t2(sum2, 1, 2, 3);

    t1.join();
    t2.join();*/
}
