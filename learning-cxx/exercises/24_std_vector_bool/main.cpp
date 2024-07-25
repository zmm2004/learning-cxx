#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); // Initialize vector with 100 elements, all set to true.
    ASSERT(vec[0], "Make this assertion pass."); // First element should be true.
    ASSERT(vec[99], "Make this assertion pass."); // Last element should be true.
    ASSERT(vec.size() == 100, "Make this assertion pass."); // Size of the vector should be 100.
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value."); // Size of the vector object itself.

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // Element at index 20 should be false.
    }

    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value."); // Size after adding one element should be 101.
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // New element at index 100 should be false.
    }

    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`"); // Element at index 30 should be true initially.
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // After assignment, `ref` should be false.
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // Element at index 30 should also be false.
    }

    return 0;
}
