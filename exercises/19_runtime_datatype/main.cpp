﻿#include "../exercise.h"
#include <cmath>
#include <type_traits>

enum class DataType {
    Float,
    Double,
};

/// @brief Tagged union 即标签化联合体，是联合体的一种常见应用。
///        Rust enum 在实现上就是标签化联合体。
struct TaggedUnion {
    DataType type;
    // NOTICE: struct/union 可以相互任意嵌套。
    union {
        float f;
        double d;
    };
};

// 模板函数用于计算 sigmoid
template <typename T>
T sigmoid(T x) {
    return 1 / (1 + std::exp(-x));
}

// 根据 DataType 动态选择类型
TaggedUnion sigmoid_dyn(TaggedUnion x) {
    TaggedUnion ans{x.type};

    // 使用条件编译，根据 type 调用正确的 sigmoid 实现
    if (x.type == DataType::Float) {
        ans.f = sigmoid(x.f);
    } else if (x.type == DataType::Double) {
        ans.d = sigmoid(x.d);
    }

    return ans;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    TaggedUnion xf{DataType::Float};
    xf.f = 5.f;
    auto yf = sigmoid_dyn(xf);
    ASSERT(yf.type == DataType::Float, "type mismatch");
    ASSERT(yf.f == 1 / (1 + std::exp(-5.f)), "sigmoid float");

    TaggedUnion xd{DataType::Double};
    xd.d = 5.0;
    auto yd = sigmoid_dyn(xd);
    ASSERT(yd.type == DataType::Double, "type mismatch");
    ASSERT(yd.d == 1 / (1 + std::exp(-5.0)), "sigmoid double");
    return 0;
}
