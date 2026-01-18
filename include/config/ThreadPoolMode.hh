#ifndef INCLUDE_CONFIG_THREAD_POOL_MODE_HH
#define INCLUDE_CONFIG_THREAD_POOL_MODE_HH


namespace easyThread {

// 线程池支持的模式
enum class PoolMode {
    MODE_FIXED, // 固定数量的线程
    MODE_CACHED // 线程数量可动态增长
};

} // namespace easyThread

#endif // INCLUDE_CONFIG_THREAD_POOL_MODE_HH
