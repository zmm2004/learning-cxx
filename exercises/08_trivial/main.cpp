#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 如果缓存未初始化，进行初始化
    if (cache.cached == 0) {
        cache.cache[0] = 0;
        cache.cache[1] = 1;
        cache.cached = 2;
        for (int j = 2; j < 16; ++j) {
            cache.cache[j] = cache.cache[j - 1] + cache.cache[j - 2];
            cache.cached = j + 1;
        }
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // 初始化缓存结构体，使计算正确
    FibonacciCache fib = { {0}, 0 };
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
