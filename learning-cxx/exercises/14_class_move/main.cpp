#include "../exercise.h"
#include <stdexcept>  // For std::out_of_range

class DynFibonacci {
    size_t *cache;
    int cached;
    int capacity;

public:
    // 动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(2), capacity(capacity) {
        if (capacity > 0) cache[0] = 0;
        if (capacity > 1) cache[1] = 1;
        for (int i = 2; i < capacity; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // 移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept : cache(other.cache), cached(other.cached), capacity(other.capacity) {
        other.cache = nullptr;
        other.cached = 0;
        other.capacity = 0;
    }

    // 移动赋值
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {
        if (this != &other) {  // 处理自赋值
            delete[] cache;    // 释放现有资源

            cache = other.cache;
            cached = other.cached;
            capacity = other.capacity;

            other.cache = nullptr;
            other.cached = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 非 const 版本用于修改缓存
    void update_cache(int i) {
        for (int j = cached; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];
        }
        cached = i + 1;
    }

    // const 版本用于访问数据
    size_t operator[](int i) const {
        if (i >= capacity) {
            throw std::out_of_range("Index exceeds cache capacity");
        }
        return const_cast<DynFibonacci*>(this)->cache[i];
    }

    // NOTICE: 不要修改这个方法
    bool is_alive() const {
        return cache != nullptr;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);
    fib0 = std::move(fib0); // This is essentially a no-op but should be handled correctly
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}
