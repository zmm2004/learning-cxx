#include "../exercise.h"

// C++ 中，`class` 和 `struct` 之间的**唯一区别**是
// `class` 默认访问控制符是 `private`，
// `struct` 默认访问控制符是 `public`。
// READ: 访问说明符 <https://zh.cppreference.com/w/cpp/language/access>

// 这个 class 中的字段被 private 修饰，只能在 class 内部访问。
// 因此必须提供构造器来初始化字段。
// READ: 构造器 <https://zh.cppreference.com/w/cpp/language/constructor>
#include "../exercise.h"

// `class` 中的字段默认为 `private`，
// 需要构造器来初始化字段。
class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 构造器初始化缓存数组和已缓存的数量
    Fibonacci() : cache{0}, cached(2) {
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < 16; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // 实现缓存优化斐波那契计算
    size_t get(int i) {
        if (i >= cached) {
            // 需要计算额外的值并更新缓存
            for (int j = cached; j <= i; ++j) {
                cache[j] = cache[j - 1] + cache[j - 2];
            }
            cached = i + 1;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

