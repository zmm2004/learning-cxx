﻿#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iterator> // For std::back_inserter

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};

    // 定义 ans 向量用于存储结果
    std::vector<std::string> ans;

    // 使用 std::transform 将 val 中的每个元素乘以 2，并转换为字符串，存入 ans
    std::transform(val.begin(), val.end(), std::back_inserter(ans),
                   [](int v) { return std::to_string(v * 2); });

    // 验证结果
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");

    return 0;
}
