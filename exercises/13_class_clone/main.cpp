#include "../exercise.h"
#include <stdexcept> // 用于抛出异常

class DynFibonacci {
    size_t *cache;
    int capacity; // 添加一个容量成员变量
    int cached;

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int capacity)
        : cache(new size_t[capacity]()), capacity(capacity), cached(0) {
        if (capacity > 0) {
            cache[0] = 0;
        }
        if (capacity > 1) {
            cache[1] = 1;
            cached = 1;
        }
    }

    // 实现复制构造器，这里我们将其删除，使得类不可复制
    DynFibonacci(DynFibonacci const &other) = delete;

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i <= cached) {
            return cache[i];
        }
        if (i >= capacity) {
            throw std::out_of_range("Index out of range");
        }
        for (int j = cached + 1; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];
            cached = j;
        }
        return cache[i];
    }

    // 实现常量版本的get方法
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        throw std::out_of_range("i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    // 由于复制构造器已被删除，因此以下代码行被注释掉
    // DynFibonacci const fib_ = fib;
    // ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
